#! /usr/bin/perl -w
#
# ops2cgc.pl
#
# Generate a C header and source file from the operation definitions in
# an .ops file.
#

use strict;
use lib 'lib';
use Parrot::OpsFile;



sub Usage {
    print STDERR <<_EOF_;
usage: $0 trans input.ops [input2.ops ...]
_EOF_
    exit 1;
}

#
# Process command-line argument:
#

Usage() unless @ARGV >= 2;

my $trans_class = "Parrot::OpTrans::" . shift @ARGV;

eval "require $trans_class";

my $trans = $trans_class->new;

my $prefix  = $trans->prefix;
my $suffix  = $trans->suffix;
my $defines = $trans->defines;
my $opsarraytype = $trans->opsarraytype;

my $file = shift @ARGV;

my $base = $file;
$base =~ s/\.ops$//;

my $incdir  = "include/parrot/oplib";
my $include = "parrot/oplib/${base}_ops_cg${suffix}.h";
my $header  = "include/$include";
my $source  = "${base}_ops_cg${suffix}.c";

#
# Read the input file:
#

my %opsfiles;
my @opsfiles;

foreach my $opsfile ($file, @ARGV) {
  if ($opsfiles{$opsfile}) {
    print STDERR "$0: Ops file '$opsfile' mentioned more than once!\n";
    next;
  }

  $opsfiles{$opsfile} = 1;
  push @opsfiles, $opsfile;

  die "$0: Could not read ops file '$opsfile'!\n" unless -r $opsfile;
}

my $ops = new Parrot::OpsFile @opsfiles;

my $version       = $ops->version;
my $major_version = $ops->major_version;
my $minor_version = $ops->minor_version;
my $patch_version = $ops->patch_version;

my $cur_code = 0;
for(@{$ops->{OPS}}) {
   $_->{CODE}=$cur_code++;
}

my $num_ops     = scalar $ops->ops;
my $num_entries = $num_ops + 1; # For trailing NULL


#
# Open the output files:
#

if (! -d $incdir) {
    mkdir($incdir, 0755) or die "ops2cgc.pl: Could not mkdir $incdir $!!\n";
}

open HEADER, ">$header"
  or die "ops2cgc.pl: Could not open header file '$header' for writing: $!!\n";

open SOURCE, ">$source"
  or die "ops2cgc.pl: Could not open source file '$source' for writing: $!!\n";


#
# Print the preamble for the HEADER and SOURCE files:
#

my $preamble = <<END_C;
/*
** !!!!!!!   DO NOT EDIT THIS FILE   !!!!!!!
**
** This file is generated automatically from '$file'.
** Any changes made here will be lost!
*/

END_C

print HEADER $preamble;
print HEADER <<END_C;
#include "parrot/parrot.h"

opcode_t *cg_core(opcode_t *, struct Parrot_Interp *);
END_C

print SOURCE $preamble;
print SOURCE <<END_C;
#include "$include"

${defines}
END_C

print SOURCE $ops->preamble($trans);

print SOURCE <<END_C;

opcode_t *
cg_core(opcode_t *cur_opcode, struct Parrot_Interp *interpreter)
{
    static void *ops_addr[] = {
END_C

#
# Iterate over the ops, appending SOURCE fragments:
#

my @op_source;
my $index = 0;

foreach my $op ($ops->ops) {
    my $definition = "PC_$index:";
    my $source     = $op->source($trans);
#    my $source     = $op->source(\&map_cg_abs, \&map_cg_rel, \&map_arg, \&map_res_abs, \&map_res_rel);

    print SOURCE "        &&PC_" . $index++ . ",\n";

    push @op_source, "$definition /* " . $op->func_name . " */\n{\n$source}\n\n";
}

#
# Finish the array and stat the execution:
#

print SOURCE <<END_C;
  NULL
};
/* #ifdef HAVE_NESTED_FUNC */
#ifdef __GNUC__
    static void _check(void);
    static void _check(void) {
	int lo_var_ptr;
	if (!interpreter->lo_var_ptr)
	    interpreter->lo_var_ptr = (void*)&lo_var_ptr;
    }
    _check();
#endif
/* #endif */

goto *ops_addr[*cur_opcode];

END_C

#
# Dump the source:
#

print SOURCE @op_source;

print SOURCE <<END_C;
};

END_C

#
# map_arg()
#

sub map_arg
{
  my ($self, $type, $num, $op) = @_;

  my %arg_maps = (
    'op' => "cur_opcode[%ld]",

    'i'  => "interpreter->ctx.int_reg->registers[cur_opcode[%ld]]",
    'n'  => "interpreter->ctx.num_reg->registers[cur_opcode[%ld]]",
    'p'  => "interpreter->ctx.pmc_reg->registers[cur_opcode[%ld]]",
    's'  => "interpreter->ctx.string_reg->registers[cur_opcode[%ld]]",

    'ic' => "cur_opcode[%ld]",
    'nc' => "interpreter->code->const_table->constants[cur_opcode[%ld]]->number",
    'pc' => "%ld /* ERROR: Don't know how to handle PMC constants yet! */",
    'sc' => "interpreter->code->const_table->constants[cur_opcode[%ld]]->string",
  );

  die "Unrecognized type '$type' for num '$num'" unless exists $arg_maps{$type};
  return sprintf($arg_maps{$type}, $num);
}


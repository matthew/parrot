#! perl -w
#
# process_opfunc.pl
#
# Take a file of opcode functions and emit real C code for them
#
# opcode functions are in the format:
#
#  AUTO_OP opname {
#
#   ... body of function ...
#
#  }
#
# Where the closing brace is on its own line. Alternately, for opcode
# functions that manage their own return values:
#
# MANUAL_OP opname {
#
#    ... body of function ...
#
#    RETVAL = x;
#
# }
#
# There may be more than one RETVAL
#
# The functions have the magic variables Pnnn for parameters 1 through
# X. (Parameter 0 is the opcode number) Types for each, and the size
# of the return offset, are taken from the opcode_table file

use strict;

my %opcode;

open GUTS, "interp_guts.h";
my $opcode;
while (<GUTS>) {
    next unless /\tx\[(\d+)\] = ([a-z_]+);/;
    $opcode{$2}{OPNUM} = $1;
}


my %psize = (i => 1,
	     n => 2,
	     I => 1,
	     N => 1,
	     D => 1,
	     S => 1,
	     s => 1,
	     );


open OPCODE, "opcode_table" or die "Can't open opcode_table, $!/$^E";
while (<OPCODE>) {
    s/#.*//;
    s/^\s+//;
    chomp;
    next unless $_;
    my ($name, $params, @params) = split /\s+/;
    $opcode{$name}{PARAM_COUNT} = $params;
    $opcode{$name}{PARAM_ARRAY} = \@params;

    my $psize=0;
    foreach (@params) {
       $psize+=$psize{$_};
    }


    $opcode{$name}{RETURN_OFFSET} = 1 + $psize;
    my $count = 1;
    $opcode{$name}{PARAMETER_SUB} = ["", 
				     map {if ($_ eq "n") { 
					 my $temp = '*(NV *)&cur_opcode[' . $count . ']';
					 $count += 2;
					 $temp;
				     } else {
					 "cur_opcode[" . $count++ . "]"
					 }
				      } @params];
}

my $file = $ARGV[0];
open INPUT, $file or die "Can't open $file, $!/$^E";
if (! ($file =~ s/\.ops$/.c/)) {
    $file .= ".c";
}
open OUTPUT, ">$file" or die "Can't open $file, $!/$^E";

my($name, $footer);
while (<INPUT>) {

    if (/^AUTO_OP/) {
	($name, $footer) = emit_auto_header($_);
	next;
    }

    if (/^MANUAL_OP/) {
	($name, $footer) = emit_manual_header($_);
	next;
    }

    s/RETVAL/return_offset/;

    s/RETURN\(0\);/return 0;/;

    s/RETURN\((.*)\)/return cur_opcode + $1/;

    s/\bP(\d+)\b/$opcode{$name}{PARAMETER_SUB}[$1]/g;

    if (/^}/) {
        print OUTPUT $footer, "\n";
	next;
    }

    print OUTPUT $_;
}

sub emit_auto_header {
    my $line = shift;
    my ($name) = $line =~ /AUTO_OP\s+(\w+)/;
    
    print OUTPUT "IV *$name(IV cur_opcode[], struct Perl_Interp *interpreter) {\n";
    return($name, "  return cur_opcode + "
    . $opcode{$name}{RETURN_OFFSET}. ";\n}\n");
}

sub emit_manual_header {
    my $line = shift;
    my ($name) = $line =~ /MANUAL_OP\s+(\w+)/;
    
    print OUTPUT "IV *$name(IV cur_opcode[], struct Perl_Interp *interpreter) {\n";
    print OUTPUT "  IV return_offset = 1;\n";
    return($name, "  return cur_opcode + return_offset;\n}\n");
}


#! perl

# Copyright (C) 2003-2006, The Perl Foundation.

use strict;
use warnings;
use lib qw(lib);

my $static_dir  = 'runtime/builtin';
my $dynamic_dir = 'src/builtin';

print <<EOH;
# This file automatically generated by $0.

EOH

# commands that are in Tcl's :: namespace directly
my @static_cmds = pir_cmds_in_dir($static_dir);

# subroutines that generate the PIR for Tcl commands
my @dynamic_cmds = pir_cmds_in_dir($dynamic_dir);

print " .HLL 'tcl', 'tcl_group'\n";

print "  .include 'languages/tcl/$dynamic_dir/$_.pir'\n" for @dynamic_cmds;

#print <<'END_PIR';
#
#.HLL 'tcl', 'tcl_group'
#.namespace
#
#END_PIR

print "  .include 'languages/tcl/$static_dir/$_.pir'\n" for @static_cmds;

# For every builtin with an inline'd version and no interpreted version,
# create a shim for the interpreted version that automatically calls
# the inline'd version, compiles the result and invokes it.

sub pir_cmds_in_dir {
    my ($dir) = @_;

    opendir( DIR, $dir );

    # only return pir files (and strip the extension)
    my @files = grep { s/\.pir$// } readdir(DIR);
    closedir(DIR);

    return @files;
}

# Local Variables:
#   mode: cperl
#   cperl-indent-level: 4
#   fill-column: 100
# End:
# vim: expandtab shiftwidth=4:

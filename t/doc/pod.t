#! perl
# Copyright (C) 2001-2005, The Perl Foundation.
# $Id$

=head1 NAME

t/doc/pod.t - Pod document syntax tests

=head1 SYNOPSIS

    % prove t/doc/pod.t

=head1 DESCRIPTION

Tests the Pod syntax for all files listed in F<MANIFEST> and
F<MANIFEST.generated> that appear to contain Pod markup. If any files
contain invalid pod markup, they are reported in the test output.
Use C<podchecker> to ferret out individual issues.

=cut

use strict;
use warnings;

use lib qw( . lib ../lib ../../lib );

use Test::More tests => 1;
use Parrot::Config;
use ExtUtils::Manifest qw(maniread);

use vars qw(@failed);

BEGIN {
    eval "use Pod::Find";
    if ($@) {
        print "1..1\nok 1 # skip Pod::Find not installed\n";
        exit;
    }
    eval "use Test::Pod";
    if ($@) {
        print "1..1\nok 1 # skip Test::Pod not installed\n";
        exit;
    }
}

# XXX this should really be using src_dir insetad of build_dir but it
# doesn't exist (yet)
my $build_dir = $PConfig{build_dir};
my $manifest     = maniread("$build_dir/MANIFEST");
my $manifest_gen = maniread("$build_dir/MANIFEST.generated");

diag "finding files with pod, this may take a minute.";

foreach my $file (keys(%$manifest), keys(%$manifest_gen)) {
    $file = "$build_dir/$file";
    # skip binary files (including .pbc files)
    next if -B $file;
    # skip missing MANIFEST.generated files
    next unless -e $file;
    # skip files without POD
    next unless Pod::Find::contains_pod( $file, 0 );
    # skip files with valid POD
    next if file_pod_ok ( $file );
    push @failed, $file;
}

my $bad_files = join ("\n", @failed);
is ( $bad_files, q{} ); # only ok if everything passed

# Pulled from Test::Pod
sub file_pod_ok {
    my $file = shift;
    my $checker = Pod::Simple->new;

    $checker->output_string( \my $trash ); # Ignore any output
    $checker->parse_file( $file );

    return !$checker->any_errata_seen;
}

# Local Variables:
#   mode: cperl
#   cperl-indent-level: 4
#   fill-column: 100
# End:
# vim: expandtab shiftwidth=4:

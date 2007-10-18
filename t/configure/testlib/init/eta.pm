# Copyright (C) 2001-2003, The Perl Foundation.
# $Id$

=head1 NAME

t/configure/testlib/init/eta.pm - Module used in configuration tests

=cut

package init::eta;
use strict;
use warnings;

use base qw(Parrot::Configure::Step::Base);

use Parrot::Configure::Step;

sub _init {
    my $self = shift;
    my %data;
    $data{description} = q{Determining if your computer does eta};
    $data{args}        = [ qw( ) ];
    $data{result}      = q{};
    return \%data;
}

my $result = q|Goodbye, cruel world|;

sub runstep {
    my ( $self, $conf ) = @_;
    $self->set_result($result);
    return;
}

1;

# Local Variables:
#   mode: cperl
#   cperl-indent-level: 4
#   fill-column: 100
# End:
# vim: expandtab shiftwidth=4:


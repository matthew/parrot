# Copyright (C) 2001-2003, The Perl Foundation.
# $Id$

=head1 NAME

config/auto/funcptr.pm - Function Pointer Casts

=head1 DESCRIPTION

Verifies that the compiler supports function pointer casts.

=cut

package auto::funcptr;

use strict;
use warnings;
use vars qw($description @args);

use base qw(Parrot::Configure::Step::Base);

use Parrot::Configure::Step ':auto';

$description = 'Verifying that the compiler supports function pointer casts';

@args = qw(verbose);

sub runstep {
    my ( $self, $conf ) = @_;

    my $jitcapable = $conf->data->get('jitcapable');

    if ($jitcapable) {
        cc_gen('config/auto/funcptr/test_c.in');
        eval { cc_build(); };

        if ( $@ || cc_run() !~ /OK/ ) {
            print <<"END";
Although it is not required by the ANSI C standard,
Parrot requires the ability to cast from void pointers to function
pointers for its JIT support.

Your compiler does not appear to support this behavior with the
flags you have specified.  You must adjust your settings in order
to use the JIT code.

If you wish to continue without JIT support, please re-run this script
With the '--jitcapable=0' argument.
END
            exit(-1);
        }
        cc_clean();
        print " (yes) " if $conf->options->get('verbose');
        $self->set_result('yes');
    }

    return 1;
}

1;

# Local Variables:
#   mode: cperl
#   cperl-indent-level: 4
#   fill-column: 100
# End:
# vim: expandtab shiftwidth=4:

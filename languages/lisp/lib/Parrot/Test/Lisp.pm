# $Id$

package Parrot::Test::Lisp;

use strict;
use warnings;

use File::Basename;

=head1 NAME

Parrot::Test::Lisp -- testing routines for languages/lisp

This is largely a copy of Parrot::Test::Punie.

=cut

# Generate output_is(), output_isnt() and output_like() in current package.
Parrot::Test::generate_languages_functions(); 

sub new {
    return bless {};
}


sub get_lang_fn {
    my $self = shift;
    my ( $count, $options ) = @_;

    return File::Spec->rel2abs(Parrot::Test::per_test( '.l',  $count ));
}

sub get_out_fn {
    my $self = shift;
    my ( $count, $options ) = @_;

    return File::Spec->rel2abs(Parrot::Test::per_test( '.out', $count ));
}

sub get_cd {
    my $self = shift;
    my ( $options ) = @_;

    return "$self->{relpath}/languages/lisp";
}

# never skip
sub skip_why {
    my $self = shift;
    my ($options) = @_;

    return;
}

sub get_test_prog {
    my $self = shift;
    my ( $count, $options ) = @_;

    my $lang_fn = Parrot::Test::per_test( '.l', $count );
    ( undef, undef, my $current_dir ) = File::Spec->splitpath( Cwd::getcwd() );
    if ( $current_dir eq 'languages' ) {
        $lang_fn = File::Spec->catdir( '..', $lang_fn );
    }

    my $test_prog_args = $ENV{TEST_PROG_ARGS} || q{};

    return 
        join( ' ',
              "../../$self->{parrot}",
              'lisp.pbc',
              $test_prog_args,
              $lang_fn );
}

sub output_is_aaaaaaaaaa {
    my ( $self, $code, $output, $desc, %extra ) = @_;

    my $count = $self->{builder}->current_test() + 1;

    # set a TODO for Test::Builder to find
    my $call_pkg = $self->{builder}->exported_to() || '';

    no strict 'refs';
    local *{ $call_pkg . '::TODO' } = \$extra{todo}
        if defined $extra{todo};

    my $lang_fn = File::Spec->rel2abs(Parrot::Test::per_test( '.l',  $count ));
    my $out_fn  = File::Spec->rel2abs(Parrot::Test::per_test( '.out', $count ));
    Parrot::Test::write_code_to_file( $code, $lang_fn );

    my $args     = $ENV{TEST_PROG_ARGS} || '';
    my $cmd      = "../../$self->{parrot} $args lisp.pbc $lang_fn";
    my $lang_dir = File::Spec->catdir( $self->{relpath}, qw( languages lisp ) );

    my $exit_code = Parrot::Test::run_command(
        $cmd,
        CD     => $lang_dir,
        STDOUT => $out_fn,
        STDERR => $out_fn
    );
    my $pass = $self->{builder}->is_eq( Parrot::Test::slurp_file($out_fn), $output, $desc );
    $self->{builder}->diag("'$cmd' failed with exit code $exit_code")
        if $exit_code and not $pass;

    return $pass;
}

1;

# Local Variables:
#   mode: cperl
#   cperl-indent-level: 4
#   fill-column: 100
# End:
# vim: expandtab shiftwidth=4:

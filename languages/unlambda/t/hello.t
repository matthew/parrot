# Copyright (C) 2005-2008, The Perl Foundation.
# $Id$

=head1 NAME

unlambda/t/hello.t - testing hello.unl

=head1 SYNOPSIS

	% cd languages && perl unlambda/t/hello.t

	% cd languages/unlambda && perl t/hello.t

=head1 DESCRIPTION

Test hello.unl.

=head1 AUTHOR

Bernhard Schmalhofer - C<Bernhard.Schmalhofer@gmx.de>

=cut

use strict;
use FindBin;
use lib "$FindBin::Bin/../../../lib";

use Test::More tests => 1;
use Parrot::Config;
use File::Spec();

my $parrot    = File::Spec->catfile( $FindBin::Bin,
                                     File::Spec->updir(),
                                     File::Spec->updir(),
                                     File::Spec->updir(),
                                     $PConfig{test_prog} );
my $unlamba   = $parrot . q{ } . File::Spec->catfile( $FindBin::Bin,
                                                      File::Spec->updir(), 
                                                      'unl.pir' );

my $hello_unl = File::Spec->catfile( $FindBin::Bin,
                                     File::Spec->updir(),
                                     'examples',
                                     'hello.unl' ); 
is( `$unlamba $hello_unl`, "Hello world\n", 'hello.unl' );

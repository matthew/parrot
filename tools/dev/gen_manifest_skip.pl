#! perl -w
# Copyright: 2005 The Perl Foundation.  All Rights Reserved.
# $Id$

=head1 NAME

tools/dev/gen_manifest_skip.pl - generated the file MANIFEST.SKIP

=head1 SYNOPSIS

    % perl tools/dev/gen_manifest_skip.pl

=head1 DESCRIPTION

Goes through the Parrot directories and ask about the svn:ignore property.
Generate a MANIFEST.SKIP file from that.

=cut

use strict;
use FindBin;
use lib "$FindBin::Bin/../../lib";

use Data::Dumper;
use Parrot::Distribution;

my $dist = Parrot::Distribution->new();

my $skip = $dist->gen_manifest_skip();


my $header = << 'END_HEADER';
# $Id$
# generated by gen_manifest_skip.pl NOW
#
# Please update t/src/manifest.t when adding patterns here
\B\.svn\b
END_HEADER
my $now = localtime();
$header =~ s/NOW/$now/;

print join( "\n", $header, @{$skip}, '' );

=head1 AUTHOR

Bernhard Schmalhofer - <Bernhard.Schmalhofer@gmx.de>

=cut

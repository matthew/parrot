#!perl

# Copyright (C) 2006-2007, The Perl Foundation.
# $Id$

use strict;
use warnings;
use lib qw( lib ../lib ../../lib dotnet dotnet/t );

use DotNetTesting;

use Test::More tests => 2;

## Testing class for this file.t';
#
die unless compile_cs( "t.dll", <<'CSHARP');
namespace Testing
{
    public class Test
    {
        public long set_long()
        {
            long x = 0xFF000000F0;
            return x;
        }
    }
}
CSHARP

## Attempt to translate.
ok( translate( "t.dll", "t.pbc" ), 'translate' );

## Tests.
is( run_pir(<<'PIR'), <<'OUTPUT', 'set_long' );
.sub main
	.local pmc obj
	load_bytecode "t.pbc"
	obj = new [ "Testing" ; "Test" ]
	$P0 = obj.set_long()
    $I0 = $P0.get_high_bits()
	print $I0
	print "\n"
    $I0 = $P0.get_low_bits()
	print $I0
	print "\n"
.end
PIR
255
240
OUTPUT

## Clean up.
unlink qw(t.dll t.pbc);

# Local Variables:
#   mode: cperl
#   cperl-indent-level: 4
#   fill-column: 100
# End:
# vim: expandtab shiftwidth=4:

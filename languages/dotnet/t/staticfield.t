#!perl

# Copyright (C) 2006-2007, The Perl Foundation.
# $Id$

use strict;
use warnings;
use lib qw( lib ../lib ../../lib dotnet dotnet/t );

use DotNetTesting;

use Test::More tests => 4;

## Testing class for this file.t';
#
die unless compile_cs( "t.dll", <<'CSHARP');
namespace Testing
{
    public class Test
    {
        public static int x;
	    public static int y;

	    public void set_x(int x)
    	{
	    	Test.x = x;
    	}

	    public void set_y(int y)
    	{
	    	Test.y = y;
    	}

	    public int add()
    	{
	    	return x + y;
	    }
    }
}
CSHARP

## Attempt to translate.
ok( translate( "t.dll", "t.pbc" ), 'translate' );

## Tests.
is( run_pir(<<'PIR'), <<'OUTPUT', 'set_x' );
.HLL 'dotnet'
.sub main
	.local pmc obj
	load_bytecode "t.pbc"
	obj = new [ "Testing" ; "Test" ]
	obj.set_x(26)
    $P0 = new 'Integer'
    $P0 = get_hll_global [ "Testing" ; "Test" ], "x"
	print $P0
	print "\n"
.end
PIR
26
OUTPUT

is( run_pir(<<'PIR'), <<'OUTPUT', 'set_y' );
.HLL 'dotnet'
.sub main
	.local pmc obj
	load_bytecode "t.pbc"
	obj = new [ "Testing" ; "Test" ]
	obj.set_y(16)
    $P0 = new 'Integer'
    $P0 = get_hll_global [ "Testing" ; "Test" ], "y"
	print $P0
	print "\n"
.end
PIR
16
OUTPUT

is( run_pir(<<'PIR'), <<'OUTPUT', 'add' );
.sub main
	.local pmc obj
	load_bytecode "t.pbc"
	obj = new [ "Testing" ; "Test" ]
	obj.set_x(26)
	obj.set_y(16)
    $I0 = obj.add()
	print $I0
	print "\n"
.end
PIR
42
OUTPUT

## Clean up.
unlink qw(t.dll t.pbc);

# Local Variables:
#   mode: cperl
#   cperl-indent-level: 4
#   fill-column: 100
# End:
# vim: expandtab shiftwidth=4:

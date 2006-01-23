#! perl -w
# Copyright: 2005-2006 The Perl Foundation.  All Rights Reserved.
# $Id$

=head1 NAME

t/pmc/nil.t - LuaNil

=head1 SYNOPSIS

    % perl -I../../lib t/pmc/nil.t

=head1 DESCRIPTION

Tests C<LuaNil> PMC
(implemented in F<languages/lua/pmc/luanil.pmc>).

=cut

use Parrot::Test tests => 12;
use Test::More;

pir_output_is(<< 'CODE', << 'OUTPUT', "check inheritance");
.sub _main
    loadlib P1, "lua_group"
    find_type $I0, "LuaNil"
    .local pmc pmc1
    pmc1 = new $I0
    .local int bool1
    bool1 = isa pmc1, "LuaNil"
    print bool1
    print "\n"
    end
.end
CODE
1
OUTPUT

pir_output_is(<< 'CODE', << 'OUTPUT', "check interface");
.sub _main
    loadlib P1, "lua_group"
    find_type $I0, "LuaNil"
    .local pmc pmc1
    pmc1 = new $I0
    .local int bool1
    bool1 = does pmc1, "scalar"
    print bool1
    print "\n"
    bool1 = does pmc1, "no_interface"
    print bool1
    print "\n"
    end
.end
CODE
1
0
OUTPUT

pir_output_is(<< 'CODE', << 'OUTPUT', "check name");
.sub _main
    loadlib P1, "lua_group"
    find_type $I0, "LuaNil"
    .local pmc pmc1
    pmc1 = new $I0
    .local string str1
    str1 = classname pmc1
    print str1
    print "\n"
    str1 = typeof pmc1
    print str1
    print "\n"
    end
.end
CODE
nil
nil
OUTPUT

pir_output_is(<< 'CODE', << 'OUTPUT', "check get_string");
.sub _main
    loadlib P1, "lua_group"
    find_type $I0, "LuaNil"
    .local pmc pmc1
    pmc1 = new $I0
    print pmc1
    print "\n"
    end
.end
CODE
nil
OUTPUT

pir_output_is(<< 'CODE', << 'OUTPUT', "check get_repr");
.sub _main
    loadlib P1, "lua_group"
    find_type $I0, "LuaNil"
    .local pmc pmc1
    pmc1 = new $I0
    .local string str1
    str1 = get_repr pmc1
    print str1
    print "\n"
    end
.end
CODE
nil
OUTPUT

pir_output_is(<< 'CODE', << 'OUTPUT', "check get_bool");
.sub _main
    loadlib P1, "lua_group"
    find_type $I0, "LuaNil"
    .local pmc pmc1
    pmc1 = new $I0
    .local int bool1
    bool1 = isfalse pmc1
    print bool1
    print "\n"
    end
.end
CODE
1
OUTPUT

pir_output_is(<< 'CODE', << 'OUTPUT', "check logical_not");
.sub _main
    loadlib P1, "lua_group"
    find_type $I0, "LuaNil"
    .local pmc pmc1
    pmc1 = new $I0
    find_type $I0, "LuaBoolean"
    .local pmc pmc2
    pmc2 = new $I0
    pmc2 = not pmc1
    print pmc2
    print "\n"
    .local string str1
    str1 = typeof pmc2
    print str1
    print "\n"
    end
.end
CODE
true
boolean
OUTPUT

pir_output_is(<< 'CODE', << 'OUTPUT', "check HLL");
.HLL "Lua", "lua_group"
.sub _main
    .local pmc pmc1
    pmc1 = new .LuaNil
    print pmc1
    print "\n"
    .local int bool1
    bool1 = isa pmc1, "LuaNil"
    print bool1
    print "\n"
    end
.end
CODE
nil
1
OUTPUT

pir_output_is(<< 'CODE', << 'OUTPUT', "check HLL & .const");
.HLL "Lua", "lua_group"
.sub _main
    .const .LuaNil cst1 = "dummy"
    print cst1
    print "\n"
    .local int bool1
    bool1 = isa cst1, "LuaNil"
    print bool1
    print "\n"
.end
CODE
nil
1
OUTPUT

pir_output_is(<< 'CODE', << 'OUTPUT', "morph to string");
.HLL "Lua", "lua_group"
.sub _main
    .local pmc pmc1
    pmc1 = new .LuaNil
    print pmc1
    print "\n"
    pmc1 = "text"
    .local string str1
    str1 = typeof pmc1
    print str1
    print "\n"
    print pmc1
    print "\n"
    end
.end
CODE
nil
string
text
OUTPUT

pir_output_is(<< 'CODE', << 'OUTPUT', "morph to boolean");
.HLL "Lua", "lua_group"
.sub _main
    .local pmc pmc1
    pmc1 = new .LuaNil
    print pmc1
    print "\n"
    pmc1 = 1
    .local string str1
    str1 = typeof pmc1
    print str1
    print "\n"
    print pmc1
    print "\n"
    end
.end
CODE
nil
boolean
true
OUTPUT

pir_output_is(<< 'CODE', << 'OUTPUT', "morph to number");
.HLL "Lua", "lua_group"
.sub _main
    .local pmc pmc1
    pmc1 = new .LuaNil
    print pmc1
    print "\n"
    pmc1 = 3.14
    .local string str1
    str1 = typeof pmc1
    print str1
    print "\n"
    print pmc1                                    
    print "\n"
    .local pmc pmc2
    pmc2 = new .LuaNil
    $N2 = 2			# prevent morph to boolean
    pmc2 = $N2
    .local string str2
    str2 = typeof pmc2
    print str2
    print "\n"
    print pmc2
    print "\n"
    end
.end
CODE
nil
number
3.14
number
2
OUTPUT


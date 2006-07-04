#!/usr/bin/perl

use strict;
use lib qw(tcl/lib ./lib ../lib ../../lib ../../../lib);
use Parrot::Test tests => 23;
use Test::More;
use vars qw($TODO);

language_output_is("tcl",<<'TCL',<<OUT,"namespace: no args");
   namespace
TCL
wrong # args: should be "namespace subcommand ?arg ...?"
OUT

language_output_is("tcl",<<'TCL',<<OUT,"namespace: bad subcommand");
   namespace asdf
TCL
bad option "asdf": must be children, code, current, delete, eval, exists, export, forget, import, inscope, origin, parent, qualifiers, tail, or which
OUT

language_output_is("tcl",<<'TCL',<<OUT,"namespace qualifiers: no args");
   namespace qualifiers
TCL
wrong # args: should be "namespace qualifiers string"
OUT

language_output_is("tcl",<<'TCL',<<OUT,"namespace qualifiers: too many args");
   namespace qualifiers string string
TCL
wrong # args: should be "namespace qualifiers string"
OUT

language_output_is("tcl",<<'TCL',<<OUT,"namespace qualifiers: simple");
   puts [namespace qualifiers ::a::b::c]
TCL
::a::b
OUT

language_output_is("tcl",<<'TCL',<<OUT,"namespace qualifiers: extra colons");
   puts [namespace qualifiers :::a:::b::c]
TCL
:::a:::b
OUT

language_output_is("tcl",<<'TCL',<<OUT,"namespace tail: no args");
   namespace tail
TCL
wrong # args: should be "namespace tail string"
OUT

language_output_is("tcl",<<'TCL',<<OUT,"namespace qualifiers: too many args");
   namespace tail string string
TCL
wrong # args: should be "namespace tail string"
OUT

language_output_is("tcl",<<'TCL',<<OUT,"namespace tail: simple");
   puts [namespace tail ::a::b::c]
TCL
c
OUT

language_output_is("tcl",<<'TCL',<<OUT,"namespace tail: extra colons");
   puts [namespace tail :::a:::b::c]
TCL
c
OUT

language_output_is("tcl",<<'TCL',<<OUT,"namespace exists: no args");
   namespace exists
TCL
wrong # args: should be "namespace exists name"
OUT

language_output_is("tcl",<<'TCL',<<OUT,"namespace exists: too many args");
   namespace exists a a
TCL
wrong # args: should be "namespace exists name"
OUT

language_output_is("tcl",<<'TCL',<<OUT,"namespace exists: failure");
   puts [namespace exists a]
TCL
0
OUT

language_output_is("tcl",<<'TCL',<<OUT,"namespace exists: global implicit");
   puts [namespace exists {}]
TCL
1
OUT

language_output_is("tcl",<<'TCL',<<OUT,"namespace exists: global explicit");
   puts [namespace exists ::]
TCL
1
OUT

language_output_is("tcl", <<'TCL', <<'OUT', "namespace eval - bad args");
  namespace eval foo
TCL
wrong # args: should be "namespace eval name arg ?arg...?"
OUT

language_output_is("tcl", <<'TCL', <<'OUT', "namespace eval foo {}");
  namespace eval foo {}
  puts [namespace exists foo]
TCL
1
OUT

language_output_is("tcl", <<'TCL', <<'OUT', "namespace eval foo {}");
  namespace eval foo { proc bar {} {puts ok} }
  foo::bar
TCL
ok
OUT

language_output_is("tcl", <<'TCL', <<'OUT', "namespace eval foo { namespace eval bar {} }");
  namespace eval foo {
    namespace eval bar {
      proc baz {} {puts ok}
    }
  }
  foo::bar::baz
TCL
ok
OUT

language_output_is("tcl", <<'TCL', <<'OUT', "namespace delete foo bar");
  namespace eval foo {}
  namespace eval bar {}
  puts [namespace exists foo]
  puts [namespace exists bar]
  namespace delete foo bar
  puts [namespace exists foo]
  puts [namespace exists bar]
TCL
1
1
0
0
OUT

language_output_is("tcl", <<'TCL', <<'OUT', "namespace current - too many args");
namespace current foo
TCL
wrong # args: should be "namespace current"
OUT

language_output_is("tcl", <<'TCL', <<'OUT', "namespace current - global");
  puts [namespace current]
TCL
::
OUT

language_output_is("tcl", <<'TCL', <<'OUT', "namespace current - ::foo");
  namespace eval foo { proc test {} {puts [namespace current]} }
  foo::test
TCL
::foo
OUT

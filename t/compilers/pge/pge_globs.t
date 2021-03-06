#! perl
# Copyright (C) 2001-2005, Parrot Foundation.
# $Id$

use strict;
use warnings;
use lib qw( t . lib ../lib ../../lib );
use Test::More;
use Parrot::Test tests => 28;
use Parrot::Test::PGE;

=head1 NAME

t/library/pge_globs.t

=head1 SYNOPSIS

        % prove -Ilib t/library/pge_globs.t

=head1 DESCRIPTION

Parrot Grammar Engine tests of globs

=cut

## literal match
pgeglob_is( '', '', 'literal: empty string, empty pattern' );
pgeglob_isnt( '0', '',  'literal: empty pattern' );
pgeglob_isnt( '',  '0', 'literal: empty string' );
pgeglob_is( 'abc', 'abc', 'literal' );
pgeglob_isnt( 'abc', 'abd', 'literal' );

## wildcards
pgeglob_is( 'bznza', 'b?n*a', "glob wildcards" );
pgeglob_is( 'bana',  'b?n*a', "glob wildcards" );
pgeglob_isnt( 'bnana', 'b?n*a', "glob wildcards" );
pgeglob_is( 'bnan', '?n?*', "glob wildcards" );
pgeglob_is( 'ana',  '?n?*', "glob wildcards" );
pgeglob_isnt( 'an', '?n?*', "glob wildcards" );

## enumerated chars
pgeglob_is( 'orange', '[go]range', 'glob enumerated characters' );
pgeglob_is( 'grange', '[go]range', 'glob enumerated characters' );
pgeglob_isnt( 'ggrange', '[go]range', 'glob enumerated characters' );
pgeglob_isnt( 'borange', '[go]range', 'glob enumerated characters' );
pgeglob_isnt( 'arange',  '[go]range', 'glob enumerated characters' );
pgeglob_is( 'a', '[^0-9]', 'glob enumerated characters' );
pgeglob_isnt( '4',  '[^0-9]', 'glob enumerated characters' );
pgeglob_isnt( '0',  '[^0-9]', 'glob enumerated characters' );
pgeglob_isnt( '9',  '[^0-9]', 'glob enumerated characters' );
pgeglob_isnt( '4a', '[^0-9]', 'glob enumerated characters' );
pgeglob_isnt( 'aa', '[^0-9]', 'glob enumerated characters' );
pgeglob_is( '_', '[A-z]', '_ is between A and z' );

## empty string
pgeglob_is( '', '*', 'glob empty string' );
pgeglob_isnt( '', '?',    'glob empty string' );
pgeglob_isnt( '', '[0]',  'glob empty string' );
pgeglob_isnt( '', '[^0]', 'glob empty string' );

## alternate
pir_output_is( <<'CODE', <<'OUT', "Glob, alternate" );

.sub _main
  load_bytecode "PGE.pbc"
  load_bytecode "PGE/Glob.pbc"

  .local pmc rule, globc
  globc = compreg "PGE::Glob"
  rule = globc.'compile'("{app,bet,cod}a")

  $P1 = rule("appa")
  if $P1 goto ok1
  print "not "
ok1:
  print "ok1\n"

  $P1 = rule("coda")
  if $P1 goto ok2
  print "not "
ok2:
  print "ok2\n"

  $P1 = rule("beta")
  if $P1 goto ok3
  print "not "
ok3:
  print "ok3\n"

  $P1 = rule("bet")
  unless $P1 goto ok4
  print "not "
ok4:
  print "ok4\n"

  $P1 = rule("alfa")
  unless $P1 goto ok5
  print "not "
ok5:
  print "ok5\n"

  rule = globc.'compile'("*{1,two,three}")

  $P1 = rule("1")
  if $P1 goto ok6
  print "not "
ok6:
  print "ok6\n"

  $P1 = rule("ptwo")
  if $P1 goto ok7
  print "not "
ok7:
  print "ok7\n"

  $P1 = rule("al")
  unless $P1 goto ok8
  print "not "
ok8:
  print "ok8\n"

  $P1 = rule("three")
  if $P1 goto ok9
  print "not "
ok9:
  print "ok9\n"

  $P1 = rule("twop")
  unless $P1 goto ok10
  print "not "
ok10:
  print "ok10\n"

  $P1 = rule("1atwo")
  if $P1 goto ok11
  print "not "
ok11:
  print "ok11\n"

.end
CODE
ok1
ok2
ok3
ok4
ok5
ok6
ok7
ok8
ok9
ok10
ok11
OUT

# Local Variables:
#   mode: cperl
#   cperl-indent-level: 4
#   fill-column: 100
# End:
# vim: expandtab shiftwidth=4:

#
# Loop.pm
#
# Copyright (C) 2002-2003 Gregor N. Purdy. All rights reserved.
# This program is free software. It is subject to the same license
# as the Parrot interpreter.
#
# $Id$
#

use strict;
use warnings;

package Jako::Construct::Block::Loop;

use Carp;

use base qw(Jako::Construct::Block);

=no

my %comp_ops = (
  'eq' => sub { $_[0] == $_[1] },
  'ne' => sub { $_[0] != $_[1] },
  'le' => sub { $_[0] <= $_[1] },
  'lt' => sub { $_[0] <  $_[1] },
  'ge' => sub { $_[0] >= $_[1] },
  'gt' => sub { $_[0] >  $_[1] },

  '==' => '',
  '!=' => 'ne',
  '<=' => 'le',
  '<'  => 'lt',
  '>=' => 'ge',
  '>'  => 'gt',

  '!eq' => 'ne',
  '!ne' => 'eq',
  '!le' => 'gt',
  '!lt' => 'ge',
  '!ge' => 'lt',
  '!gt' => 'le',
);

=cut

sub left      { return shift->{LEFT};      }
sub op        { return shift->{OP};        }
sub right     { return shift->{RIGHT};     }
sub kind      { return shift->{KIND};      }
sub namespace { return shift->{NAMESPACE}; }
sub prefix    { return shift->{PREFIX};    }

sub compile
{
  my $self = shift;
  my ($compiler) = @_;

  my $namespace = $self->namespace;
  my $prefix    = $self->prefix;
  my $kind      = $self->kind;

  my $left;
  my $op;
  my $right;

  if ($kind eq 'while' or $kind eq 'until') {
    $left  = $self->left->value;
    $op    = $self->op;
    $right = $self->right->value;
  }

  if ($kind eq 'while') {
    $op = Jako::Compiler::invert_relop($op); # Invert the sense for 'while' loops.
  }

  if ($kind eq 'while' or $kind eq 'until') {
    $compiler->emit("${prefix}_NEXT:");
    $compiler->emit("  if $left $op $right goto ${prefix}_LAST");
    $compiler->emit("${prefix}_REDO:");

    if ($self->content) {
      $compiler->emit(".namespace ${namespace}");
      $compiler->indent;
      $self->SUPER::compile($compiler);
      $compiler->outdent;
      $compiler->emit(".endnamespace ${namespace}");
    }
  }
  elsif ($kind eq 'continue') {
    $compiler->emit("${prefix}_CONT:");

    if ($self->content) {
      $compiler->emit(".namespace ${namespace}_CONT");
      $compiler->indent;
      $self->SUPER::compile($compiler);
      $compiler->outdent;
      $compiler->emit(".endnamespace ${namespace}_CONT");
    }

    $compiler->emit("  goto ${prefix}_NEXT");
    $compiler->emit("${prefix}_LAST:");
  }
  else {
    $self->INTERNAL_ERROR("Unrecognized kind of block '%s'", $kind);
  }

  return 1;
}


1;


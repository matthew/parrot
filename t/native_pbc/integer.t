#! perl -w
# Copyright: 2001-2005 The Perl Foundation.  All Rights Reserved.
# $Id$

=head1 NAME

t/native_pbc/integer.t - Integers

=head1 SYNOPSIS

	% perl t/native_pbc/integer.t

=head1 DESCRIPTION

Tests word-size/float-type/endian-ness for different architectures.

=cut

=begin comment

s. t/native_pbc/number.t for additional comments

Test files on different architectures are generated by:

$ parrot -o i.pbc -a - <<EOF
> print 0x10203040
> end
> EOF
$ mv i.pbc t/native_pbc/integer_${N}.pbc

The output of

$ pdump -h i.pbc

should be included for reference.

=cut

use Parrot::Test tests => 1;

# execute the file t/native_pbc/integer_1.pbc
#
# HEADER => [
#         wordsize  = 4   (interpreter's wordsize    = 4)
#         int_size  = 4   (interpreter's INTVAL size = 4)
#         byteorder = 0   (interpreter's byteorder   = 0)
#         floattype = 0   (interpreter's NUMVAL_SIZE = 8)
#         no endianize, no opcode, no numval transform
#         dirformat = 1
# ]
pbc_output_is(undef, '270544960', "i386 32 bit opcode_t, 32 bit intval");

# Formerly following tests had been set up:
# output_is(undef, '270544960', "PPC BE 32 bit opcode_t, 32 bit intval");
# output_is(undef, '270544960', "little-endian 64-bit tru64");
# output_is(undef, '270544960', "big-endian 64-bit irix");

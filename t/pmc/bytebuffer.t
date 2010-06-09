#!./parrot
# Copyright (C) 2010, Parrot Foundation.
# $Id$

=head1 NAME

t/pmc/bytebuffer.t - ByteBuffer PMC

=head1 SYNOPSIS

    % prove t/pmc/bytebuffer.t

=head1 DESCRIPTION

Tests C<ByteBuffer> PMC..

=cut

.sub 'main' :main
    .include 'test_more.pir'
    plan(17)

    test_init()
    test_set_string()
    test_set_byte()
    test_get_string()
.end

.sub test_init
    .local pmc bb
    .local int n
    bb = new ['ByteBuffer']
    n = elements bb
    is(n, 0, "size of a new buffer is 0")

    bb = new ['ByteBuffer'], 42
    n = elements bb
    is(n, 42, "size of a new buffer with initial size is correct")

.end

.sub test_set_string
    .local pmc bb
    .local string s
    .local int n, c
    bb = new ['ByteBuffer']
    s = 'Hi'
    bb = s

    # Exercise mark vtable
    sweep 1

    n = elements bb
    is(n, 2, "size is the same as the source string bytelength")
    n = bb[0]
    c = ord 'H'
    is(n, c, "first byte is the same as the source string")
    n = bb[1]
    c = ord 'i'
    is(n, c, "second byte is the same as the source string")
    n = bb[2]
    is(n, 0, "byte out of size is 0")
    n = bb[-1]
    is(n, 0, "byte at negative index is 0")
.end

.sub test_set_byte
    .local pmc bb
    .local int n
    bb = new ['ByteBuffer']
    bb[255] = 42
    n = elements bb
    is(n, 256, "setting a byte resize empty buffer")

    .local string s
    s = 'Hi'
    bb = s
    bb[2] = 42
    n = elements bb
    is(n, 3, "setting a byte resize buffer initialized from string")

    bb = new ['ByteBuffer'], 42
    bb[41] = 9
    n = elements bb
    is(n, 42, "setting a byte within range does not resize")
    bb[42] = 7
    n = elements bb
    is(n, 43, "setting a byte resize buffer with initial size")
    n = bb[41]
    is(n, 9, "resized buffer preserve old value")

    push_eh catch
    bb[-1] = 0
    ok(0, "setting a byte with negative index should throw")
    goto end
catch:
    pop_eh
    ok(1, "setting a byte with negative index throws")
end:
.end

.sub test_get_string
    .local pmc bb
    bb = new ['ByteBuffer']
    # Upper case n tilde: codepoint 0xD1, utf8 encoding 0xC3, 0x91
    bb = utf16:unicode:"\x{D1}"
    .local string s
    s = bb.'get_string'('unicode', 'utf16')
    .local int n
    n = length s
    is(n, 1, "getting utf16 from buffer gives correct length")
    n = ord s
    is(n, 0xD1, "getting utf16 from buffer gives correct codepoint")

    bb = new ['ByteBuffer']
    bb[0] = 0xC3
    bb[1] = 0x91
    s = bb.'get_string_as'(utf8:unicode:"")
    n = length s
    is(n, 1, "getting utf8 from buffer gives correct length")
    n = ord s
    is(n, 0xD1, "getting utf8 from buffer gives correct codepoint")
.end

# Local Variables:
#   mode: pir
#   fill-column: 100
# End:
# vim: expandtab shiftwidth=4 ft=pir:
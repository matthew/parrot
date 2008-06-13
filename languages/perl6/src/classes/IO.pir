## $Id$

=head1 TITLE

IO - Perl 6 IO class

=head1 DESCRIPTION

This file implements the IO file handle class.

=head1 Methods

=over 4

=cut

.namespace ['IO']

.sub 'onload' :anon :init :load
    .local pmc p6meta
    p6meta = get_hll_global ['Perl6Object'], '$!P6META'
    p6meta.'new_class'('IO', 'parent'=>'Any', 'attr'=>'$!PIO')
    p6meta.'new_class'('IOIterator', 'parent'=>'Perl6Object', 'attr'=>'$!IO')
.end

=item print

Writes the given list of items to the file.

=cut

.sub 'print' :method
    .param pmc args            :slurpy
    .local pmc iter
    .local pmc PIO
    PIO = getattribute self, "$!PIO"
    args = 'list'(args)
    iter = new 'Iterator', args
  iter_loop:
    unless iter goto iter_end
    $S0 = shift iter
    print PIO, $S0
    goto iter_loop
  iter_end:
    .return (1)
.end


=item say

Writes the given list of items to the file, then a newline character.

=cut

.sub 'say' :method
    .param pmc list            :slurpy
    .local pmc PIO
    PIO = getattribute self, "$!PIO"
    self.'print'(list)
    print PIO, "\n"
    .return (1)
.end


=item readline

Reads a line from the file handle.

=cut

.sub 'readline' :method
    .local pmc PIO
    PIO = getattribute self, "$!PIO"
    $P0 = PIO.readline('')
    .return ($P0)
.end


=item slurp

Slurp a file into a string.

=cut

.sub 'slurp' :method
    .local pmc PIO
    PIO = getattribute self, "$!PIO"
    $S0 = PIO.slurp('')
    .return($S0)
.end


=item close

Closes the file.

=cut

.sub 'close' :method
    .local pmc PIO
    PIO = getattribute self, "$!PIO"
    close PIO
    .return(1)
.end


.namespace []

=back

=head1 EXPORTED MULTI SUBS

=over

=item prefix:=(IO $io)

Gets the iterator for the IO object.

=cut

.sub 'prefix:=' :multi('IO')
    .param pmc io
    $P0 = get_hll_global 'IOIterator'
    $P0 = $P0.'new'('IO' => io)
    .return($P0)
.end


.namespace [ 'IOIterator' ]

=back

=head1 IOIterator

The IOIterator class implements the I/O iterator.

=cut

.sub get_bool :method :vtable
    .local pmc PIO
    $P0 = getattribute self, "$!IO"
    PIO = getattribute $P0, "$!PIO"
    if PIO goto more
    .return(0)
more:
    .return(1)
.end

.sub shift_pmc :method :vtable
    .local pmc pio
    $P0 = getattribute self, "$!IO"
    pio = getattribute $P0, "$!PIO"
    $P0 = pio.readline("")
    .return($P0)
.end

.sub get_iter :method :vtable
    .return(self)
.end

# Local Variables:
#   mode: pir
#   fill-column: 100
# End:
# vim: expandtab shiftwidth=4 ft=pir:

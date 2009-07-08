# $Id$
# Copyright (C) 2009, Parrot Foundation.

=head1 Builtins

Variour helper builtins.

=cut
.namespace []

.sub 'uc'
    .param string arg
    $S0 = upcase arg
    .return ($S0)
.end

.sub 'join'
    .param string joiner
    .param pmc args

    unless args goto done
    $S0 = join joiner, args
  done:
    .return ($S0)
.end

.sub 'defined'
    .param pmc thing
    $I0 = defined thing
    .return ($I0)
.end

.sub 'exists'
    .param pmc where
    .param pmc what
    $I0 = exists where[what]
    .return ($I0)
.end

.sub 'clone'
    .param pmc what
    $P0 = clone what
    .return ($P0)
.end

.sub 'elements'
    .param pmc p
    $I0 = elements p
    .return ($I0)
.end


.sub 'substr'
    .param string orig
    .param int    from
    .param int    len
    $S0 = substr orig, from, len
    .return ($S0)
.end

.sub 'match'
    .param string pattern
    .param string subject

    .local pmc recomp, resub, match, recache

    load_bytecode 'PGE.pbc'
    
    #hash cache mapping patterns to subs, avoiding unneeded recompilation
    recache = get_hll_global ['Ops';'Op'], '%recache'
    $I0 = isnull recache
    if $I0 goto no_cache
    $I0 = exists recache[pattern]
    if $I0 goto found_re
    goto no_re

  no_cache:
    recache = new ['Hash']

  no_re:
    recomp = compreg 'PGE::Perl6Regex'
    resub = recomp(pattern)
    recache[pattern] = resub

  found_re:
    resub = recache[pattern]
    set_hll_global ['Ops';'Op'], '%recache', recache

    match = resub(subject)
    if match goto found_match
    .return (0)
  found_match:
    .return (1)
.end



# Local Variables:
#   mode: pir
#   fill-column: 100
# End:
# vim: expandtab shiftwidth=4 ft=pir:

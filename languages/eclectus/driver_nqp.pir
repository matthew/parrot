# $Id$

# The dynamics PMCs used by Eclectus are loaded
.loadlib 'eclectus_group'

# for devel
.include 'library/dumper.pir'
.include 'gen_past.pir'

.namespace

.sub '__onload' :init
    load_bytecode 'PGE.pbc'
    load_bytecode 'PGE/Text.pbc'
    load_bytecode 'PGE/Util.pbc'
    load_bytecode 'PGE/Dumper.pbc'
    load_bytecode 'PCT.pbc'
.end


.sub drive :main

    .local pmc stmts
    ( stmts ) = scheme_entry()
    # _dumper( stmts, 'stmts' )

    # compile and evaluate
    .local pmc past_compiler
    past_compiler = new [ 'PCT::HLLCompiler' ]
    $P0 = split ' ', 'post pir'
    past_compiler.'stages'( $P0 )
    $P1 = past_compiler.'eval'(stmts)
    #_dumper ($P1)
    $P0 = split ' ', 'evalpmc'
    past_compiler.'stages'( $P0 )
    past_compiler.'eval'( $P1 )
.end


.sub '__initconst' :init
    $P0 = new 'EclectusBoolean'
    $P0 = 1
    set_root_global ['_eclectus'], '#t', $P0
    $P0 = new 'EclectusBoolean'
    set_root_global ['_eclectus'], '#f', $P0
    $P0 = new 'EclectusEmptyList'
    set_root_global ['_eclectus'], '()', $P0
.end

.sub 'say'
    .param pmc args :slurpy
    if null args goto end
    .local pmc iter
    iter = new 'Iterator', args
loop:
    unless iter goto end
    $P0 = shift iter
    print $P0
    goto loop
end:
    say ''
    .return ()
.end

.sub 'infix:<'
    .param num a
    .param num b
    $I0 = islt a, b

    .return ($I0)
.end

.sub 'infix:<='
    .param num a
    .param num b
    $I0 = isle a, b

    .return ($I0)
.end

.sub 'infix:=='
    .param pmc a
    .param pmc b
    $I0 = cmp_num a, b
    $I0 = iseq $I0, 0

    .return ($I0)
.end

.sub 'infix:>='
    .param num a
    .param num b
    $I0 = isge a, b

    .return ($I0)
.end

.sub 'infix:>'
    .param num a
    .param num b
    $I0 = isgt a, b

    .return ($I0)
.end

.sub 'eq?'
    .param pmc a
    .param pmc b
    $I0 = issame a, b

    .return ($I0)
.end

.sub 'eqv?'
    .param pmc a
    .param pmc b
    $I0 = iseq a, b

    .return ($I0)
.end

.sub 'equal?'
    .param pmc a
    .param pmc b
    $I0 = iseq a, b

    .return ($I0)
.end

# Local Variables:
#   mode: pir
#   fill-column: 100
# End:
# vim: expandtab shiftwidth=4 ft=pir:

# Copyright (C) 2008, The Perl Foundation.
# $Id$

=head1 NAME

Markdown::HTML::Compiler - MAST Compiler

=head1 DESCRIPTION

Markdown::HTML::Compiler implements a compiler for MAST nodes.

=head1 METHODS

=over

=cut

.namespace [ 'Markdown::HTML::Compiler' ]

.sub '__onload' :anon :load :init
    $P0 = newclass 'Markdown::HTML::Compiler'
.end

.sub 'to_html' :method
    .param pmc past
    .param pmc adverbs         :slurpy :named

    .return self.'html'(past)
.end

=item html_children(node)

Return generated HTML for all of its children.

=cut

.sub 'html_children' :method
    .param pmc node
    .local pmc code, iter
    code = new 'CodeString'
    iter = node.'iterator'()
  iter_loop:
    unless iter goto iter_end
    .local pmc cpast
    cpast = shift iter
    $P0 = self.'html'(cpast)
    code .= $P0
    goto iter_loop
  iter_end:
    .return (code)
.end


=item html(Any node)

=cut

.sub 'html' :method :multi(_,_)
    .param pmc node
    .return self.'html_children'(node)
.end


=item html(Markdown::Document node)

=cut

.sub 'html' :method :multi(_,['Markdown::Document'])
    .param pmc node
    .return self.'html_children'(node)
.end


=item html(Markdown::HorizontalRule node)

=cut

.sub 'html' :method :multi(_,['Markdown::HorizontalRule'])
    .param pmc node
    .local pmc code
    new code, 'CodeString'
    set code, "<hr />\n\n"
    .return (code)
.end


=item html(Markdown::Title node)

=cut

.sub 'html' :method :multi(_,['Markdown::Title'])
    .param pmc node
    $S1 = self.'html_children'(node)
    $S2 = node.'level'()
    .local pmc code
    new code, 'CodeString'
    $S0 = "<h"
    $S0 .= $S2
    $S0 .= ">"
    $S0 .= $S1
    $S0 .= "</h"
    $S0 .= $S2
    $S0 .= ">\n\n"
    set code, $S0
    .return (code)
.end


=item html(Markdown::Para node)

=cut

.sub 'html' :method :multi(_,['Markdown::Para'])
    .param pmc node
    $S1 = self.'html_children'(node)
    .local pmc code
    new code, 'CodeString'
    $S0 = "<p>"
    $S0 .= $S1
    $S0 .= "</p>\n\n"
    set code, $S0
    .return (code)
.end

=item html(Markdown::BlockQuote node)

=cut

.sub 'html' :method :multi(_,['Markdown::BlockQuote'])
    .param pmc node
    $S1 = self.'html_children'(node)
    .local pmc code
    new code, 'CodeString'
    $S0 = "<blockquote>\n"
    $S0 .= $S1
    $S0 .= "</blockquote>\n\n"
    set code, $S0
    .return (code)
.end

=item html(Markdown::Line node)

=cut

.sub 'html' :method :multi(_,['Markdown::Line'])
    .param pmc node
    $S1 = node.'text'()
    .local pmc code
    new code, 'CodeString'
    $S0 = "  <p>"
    $S0 .= $S1
    $S0 .= "</p>\n"
    set code, $S0
    .return (code)
.end

=item html(Markdown::Word node)

=cut

.sub 'html' :method :multi(_,['Markdown::Word'])
    .param pmc node
    $S1 = node.'text'()
    .local pmc code
    new code, 'CodeString'
    set code, $S1
    .return (code)
.end

=item html(Markdown::Space node)

=cut

.sub 'html' :method :multi(_,['Markdown::Space'])
    .param pmc node
    .local pmc code
    new code, 'CodeString'
    set code, ' '
    .return (code)
.end

=back

=head1 AUTHORS

Francois Perrad

=cut

# Local Variables:
#   mode: pir
#   fill-column: 100
# End:
# vim: expandtab shiftwidth=4 ft=pir:


#!./parrot-nqp
# Copyright (C) 2010, Parrot Foundation.
# $Id$

INIT {
    pir::load_bytecode('PCT.pbc');
}

class PAST::Pattern::Node is PAST::Pattern {
    method attr ($name, $value, $has_value) {
        my $result;
        if ($has_value) {
            self{$name} := PAST::Pattern::patternize($value);
        } else {
            $result := self{$name};
        }
        $result;
    }

    method name ($val?) {
        self.attr("name", $val, !pir::isnull__iP($val));
    }

    method source ($val?) {
        self.attr("source", $val, !pir::isnull__iP($val));
    }

    method pos ($val?) {
        self.attr("pos", $val, !pir::isnull__iP($val));
    }

    method returns ($val?) {
        self.attr("returns", $val, !pir::isnull__iP($val));
    }

    method arity ($val?) {
        self.attr("arity", $val, !pir::isnull__iP($val));
    }

    method named ($val?) {
        self.attr("named", $val, !pir::isnull__iP($val));
    }

    method flat ($val?) {
        self.attr("flat", $val, !pir::isnull__iP($val));
    }

    method lvalue ($val?) {
        self.attr("lvalue", $val, !pir::isnull__iP($val));
    }    

    method new (*@children, *%attrs) {
        my $result := Q:PIR {
            $P0 = self.'HOW'()
            $P0 = getattribute $P0, 'parrotclass'
            %r = new $P0
        };

        for %attrs {
            $result.attr($_, %attrs{$_}, 1);
        }
        for @children {
            pir::push($result, PAST::Pattern::patternize($_));
        }
        $result;
    }

    sub check_attribute ($pattern, $node, $attribute, $/) {
        my $pAttr := $pattern.attr($attribute, null, 0);
        unless pir::defined__IP($pAttr) {
            return 1;
        }
        unless pir::defined__IP($pAttr) {
            $/.success(0);
            return 0;
        }
        my $nAttr := $node.attr($attribute, null, 0);
        my $result := $nAttr ~~ $pAttr;
        if ($result) {
            $/{$attribute} := $result;
        }
        else {
            $/.success(0);
        }
        $result;
    }

    sub check_children ($pattern, $node, $/) {
        my $pLen := pir::elements($pattern);
        my $nLen := pir::elements($node);
        my $result;
        my $index;
        if $pLen == 0 {
            $result := 1;
        }
        elsif ($pLen == $nLen) {
            $index := 0;
            while ($index < $pLen) {
                if ($result := $node[$index] ~~ $pattern[$index]) {
                    $/[$index] := $result;
                }
                else {
                    $/.success(0);
                    return 0;
                }
                $index++;
            }
            $result := 1;
        }
        else {
            $/.success(0);
            $result := 0;
        }
        $result;
    }

    sub check_node_attributes ($pattern, $node, $/) {
        (check_attribute($pattern, $node, "name", $/)
         && check_attribute($pattern, $node, "source", $/)
         && check_attribute($pattern, $node, "pos", $/)
         && check_attribute($pattern, $node, "returns", $/)
         && check_attribute($pattern, $node, "arity", $/)
         && check_attribute($pattern, $node, "named", $/)
         && check_attribute($pattern, $node, "flat", $/)
         && check_attribute($pattern, $node, "lvalue", $/));
    }

    method ACCEPTS ($node, *%opts) {
        my $global := ?%opts<g>;
        my $/;
        my $first := self.ACCEPTSEXACTLY($node);
        if ($global && $node ~~ PAST::Node) {
            my $matches := ?$first;
            my $index := 0;
            my $max := pir::elements__IP($node);
            my $submatch;
            $/ := PAST::Pattern::Match.new(?$first);
            $/[0] := $first if $first;
            until ($index == $max) {
                $submatch := self.ACCEPTS($node[$index], :g);
                if ($submatch) {
                    $/.success(1) unless $matches;
                    if pir::defined__iP($submatch.from()) {
                        $/[$matches++] := $submatch;
                    }
                    else { # The submatch is a list of multiple matches.
                        my $subIndex := 0;
                        my $subMax := pir::elements__IP($submatch);
                        until ($subIndex == $subMax) {
                            $/[$matches++] := $submatch[$subIndex];
                            $subIndex++;
                        }
                    }
                }
                $index++;
            }
            $/ := $/[0] if $matches == 1;
        }
        elsif ($first) {
            $/ := $first;
        } else {
            if ($node ~~ PAST::Node) {
                my $index := 0;
                my $max := pir::elements__IP($node);
                until ($index == $max) {
                    $/ := $node[$index] ~~ self;
                    return $/ if $/;
                    $index++;
                }
                $/ := PAST::Pattern::Match.new(0);
            } else {
                $/ := PAST::Pattern::Match.new(0);
            }
        }
        $/;
    }
}

class PAST::Pattern::Block is PAST::Pattern::Node {
    method blocktype ($val?) {
        self.attr("blocktype", $val, !pir::isnull__iP($val));
    }

    method closure ($val?) {
        self.attr("closure", $val, !pir::isnull__iP($val));
    }

    method control ($val?) {
        self.attr("control", $val, !pir::isnull__iP($val));
    }

    method loadinit ($val?) {
        self.attr("loadinit", $val, !pir::isnull__iP($val));
    }

    method namespace ($val?) {
        self.attr("namespace", $val, !pir::isnull__iP($val));
    }

    method multi ($val?) {
        self.attr("multi", $val, !pir::isnull__iP($val));
    }

    method hll ($val?) {
        self.attr("hll", $val, !pir::isnull__iP($val));
    }

    method nsentry ($val?) {
        self.attr("nsentry", $val, !pir::isnull__iP($val));
    }

    method symtable ($val?) {
        self.attr("symtable", $val, !pir::isnull__iP($val));
    }

    method lexical ($val?) {
        self.attr("lexical", $val, !pir::isnull__iP($val));
    }

    method compiler ($val?) {
        self.attr("compiler", $val, !pir::isnull__iP($val));
    }

    method compiler_args ($val?) {
        self.attr("compiler_args", $val, !pir::isnull__iP($val));
    }

    method subid ($val?) {
        self.attr("subid", $val, !pir::isnull__iP($val));
    }

    method pirflags ($val?) {
        self.attr("pirflags", $val, !pir::isnull__iP($val));
    }
    
    method ACCEPTSEXACTLY ($node) {
        return PAST::Pattern::Match.new(0) unless $node ~~ PAST::Block;
        my $/ := PAST::Pattern::Match.new(1);
        (PAST::Pattern::Node::check_attribute(self, $node,
                                              "blocktype", $/)
         && PAST::Pattern::Node::check_attribute(self, $node,
                                                 "closure", $/)
         && PAST::Pattern::Node::check_attribute(self, $node,
                                                 "control", $/)
         && PAST::Pattern::Node::check_attribute(self, $node,
                                                 "loadinit", $/)
         && PAST::Pattern::Node::check_attribute(self, $node,
                                                 "namespace", $/)
         && PAST::Pattern::Node::check_attribute(self, $node,
                                                 "multi", $/)
         && PAST::Pattern::Node::check_attribute(self, $node,
                                                 "hll", $/)
         && PAST::Pattern::Node::check_attribute(self, $node,
                                                 "nsentry", $/)
         && PAST::Pattern::Node::check_attribute(self, $node,
                                                 "symtable", $/)
         && PAST::Pattern::Node::check_attribute(self, $node,
                                                 "lexical", $/)
         && PAST::Pattern::Node::check_attribute(self, $node,
                                                 "compiler", $/)
         && PAST::Pattern::Node::check_attribute(self, $node, 
                                                 "compiler_args", $/)
         && PAST::Pattern::Node::check_attribute(self, $node,
                                                 "subid", $/)
         && PAST::Pattern::Node::check_attribute(self, $node,
                                                 "pirflags", $/)
         && PAST::Pattern::Node::check_children(self, $node, $/)
         && PAST::Pattern::Node::check_node_attributes(self, $node, $/));
        $/.from($node) if $/;
        $/;
    }
}


class PAST::Pattern::Op is PAST::Pattern::Node {
    method pasttype ($val?) {
        self.attr("pasttype", $val, !pir::isnull__iP($val));
    }

    method pirop ($val?) {
        self.attr("pirop", $val, !pir::isnull__iP($val));
    }

    method inline ($val?) {
        self.attr("inline", $val, !pir::isnull__iP($val));
    }


    method ACCEPTSEXACTLY ($node) {
        return PAST::Pattern::Match.new(0) unless $node ~~ PAST::Op;
        my $/ := PAST::Pattern::Match.new(1);
        (PAST::Pattern::Node::check_attribute(self, $node,
                                              "pasttype", $/)
         && PAST::Pattern::Node::check_attribute(self, $node,
                                                 "pirop", $/)
         && PAST::Pattern::Node::check_attribute(self, $node,
                                                 "inline", $/)
         && PAST::Pattern::Node::check_children(self, $node, $/)
         && PAST::Pattern::Node::check_node_attributes(self, $node, $/));
        $/.from($node) if $/;
        $/;
    }
}

class PAST::Pattern::Stmts is PAST::Pattern::Node {
    method ACCEPTSEXACTLY ($node) {
        return PAST::Pattern::Match.new(0) unless $node ~~ PAST::Stmts;
        my $/ := PAST::Pattern::Match.new(1);
        (PAST::Pattern::Node::check_children(self, $node, $/)
         && PAST::Pattern::Node::check_node_attributes(self, $node, $/));
        $/.from($node) if $/;
        $/;
    }
}

class PAST::Pattern::Val is PAST::Pattern::Node {
    method value ($val?) {
        self.attr("value", $val, !pir::isnull__iP($val));
    }

    method ACCEPTSEXACTLY ($node) {
        return PAST::Pattern::Match.new(0) unless $node ~~ PAST::Val;
        my $/ := PAST::Pattern::Match.new(1);
        (PAST::Pattern::Node::check_children(self, $node, $/)
         && PAST::Pattern::Node::check_node_attributes(self, $node, $/)
         && PAST::Pattern::Node::check_attribute(self, $node, 
                                                 "value", $/));
        $/.from($node) if $/;
        $/;
    }
}

class PAST::Pattern::Var is PAST::Pattern::Node {
    method scope ($val?) {
        self.attr("scope", $val, !pir::isnull__iP($val));
    }

    method isdecl ($val?) {
        self.attr("isdecl", $val, !pir::isnull__iP($val));
    }

    method namespace ($val?) {
        self.attr("namespace", $val, !pir::isnull__iP($val));
    }

    method slurpy ($val?) {
        self.attr("slurpy", $val, !pir::isnull__iP($val));
    }

    method call_sig ($val?) {
        self.attr("call_sig", $val, !pir::isnull__iP($val));
    }

    method viviself ($val?) {
        self.attr("viviself", $val, !pir::isnull__iP($val));
    }

    method vivibase ($val?) {
        self.attr("vivibase", $val, !pir::isnull__iP($val));
    }

    method multitype ($val?) {
        self.attr("multitype", $val, !pir::isnull__iP($val));
    }

    method ACCEPTSEXACTLY ($node) {
        return PAST::Pattern::Match.new(0) unless $node ~~ PAST::Var;
        my $/ := PAST::Pattern::Match.new(1);
        (PAST::Pattern::Node::check_attribute(self, $node,
                                              "scope", $/)
         && PAST::Pattern::Node::check_attribute(self, $node,
                                                 "isdecl", $/)
         && PAST::Pattern::Node::check_attribute(self, $node,
                                                 "namespace", $/)
         && PAST::Pattern::Node::check_attribute(self, $node,
                                                 "slurpy", $/)
         && PAST::Pattern::Node::check_attribute(self, $node,
                                                 "call_sig", $/)
         && PAST::Pattern::Node::check_attribute(self, $node,
                                                 "viviself", $/)
         && PAST::Pattern::Node::check_attribute(self, $node,
                                                 "vivibase", $/)
         && PAST::Pattern::Node::check_attribute(self, $node,
                                                 "multitype", $/)
         && PAST::Pattern::Node::check_children(self, $node, $/)
         && PAST::Pattern::Node::check_node_attributes(self, $node, $/));
        $/.from($node) if $/;
        $/;
    }
}

class PAST::Pattern::VarList is PAST::Pattern::Node {
    method ACCEPTSEXACTLY ($node) {
        return PAST::Pattern::Match.new(0) unless $node ~~ PAST::VarList;
        my $/ := PAST::Pattern::Match.new(1);
        (PAST::Pattern::Node::check_children(self, $node, $/)
         && PAST::Pattern::Node::check_node_attributes(self, $node, $/));
        $/.from($node) if $/;
        $/;
    }
}

# Local Variables:
#   mode: cperl
#   cperl-indent-level: 4
#   fill-column: 100
# End:
# vim: expandtab shiftwidth=4:

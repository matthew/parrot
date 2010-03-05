#! nqp

class Ops::Emitter is Hash;

=begin

Emitter.

=end

method new(:$ops_file!, :$trans!, :$script!, :$file, :%flags!) {
    self<ops_file>  := $ops_file;
    self<trans>     := $trans;
    self<script>    := $script;
    self<file>      := $file;
    self<flags>     := %flags;

    # Preparing various bits.
    my $suffix := $trans.suffix();

    my $base := %flags<core> ?? 'core' !! $file; #FIXME drop .ops
    my $base_ops_stub := $base ~ '_ops' ~ $suffix;
    my $base_ops_h    := $base_ops_stub ~ '.h';


    self<include> := "parrot/oplib/$base_ops_h";
    self<header>  := (~%flags<dir>) ~ "include/" ~ self<include>;

    self;
};

method ops_file()   { self<ops_file> };
method trans()      { self<trans> };
method script()     { self<script> };
method file()       { self<file> };
method flags()      { self<flags> };


method print_c_header_file() {
    my $fh := pir::open__PSs(self<header>, 'w') || die("Can't open filehandle");
    self.emit_c_header_file($fh);
    $fh.close();
    return self<header>;
}

method emit_c_header_file($fh) {

    self._emit_guard_prefix($fh);

    self._emit_preamble($fh);

    self._emit_guard_suffix($fh);

    self._emit_coda($fh);
}

# given a headerfile name like "include/parrot/oplib/core_ops.h", this
# returns a string like "PARROT_OPLIB_CORE_OPS_H_GUARD"
method _generate_guard_macro_name() {
    my $fn   := self<header>;
    $fn := subst($fn, /.h$/, '');
    #my @path = File::Spec->splitdir($fn);
    my @path := split('/', $fn);
    @path.shift if @path[0]~'/' eq self<flags><dir>;
    @path.shift if @path[0] eq 'include';
    @path.shift if @path[0] eq 'parrot';
    uc( join( '_', 'parrot', |@path, 'h', 'guard' ) );
}


method _emit_guard_prefix($fh) {
    my $guardname := self._generate_guard_macro_name();
    $fh.print(qq/
#ifndef $guardname
#define $guardname

/);
}

method _emit_guard_suffix($fh) {
    my $guardname := self._generate_guard_macro_name();
    $fh.print(qq|

#endif /* $guardname */
|);
}


method _emit_coda($fh) {
    $fh.print(q|

/*
 * Local variables:
 *   c-file-style: "parrot"
 *   buffer-read-only: t
 * End:
 * vim: expandtab shiftwidth=4:
 */
|);
}

method _emit_preamble($fh) {
    $fh.print(qq|
/* ex: set ro:
 * !!!!!!!   DO NOT EDIT THIS FILE   !!!!!!!
 *
 * This file is generated automatically from '{self<file>}' (and possibly other
 * .ops files). by {self<script>}.
 *
 * Any changes made here will be lost!
 *
 */
|);
}
# vim: expandtab shiftwidth=4 ft=perl6:

#! ./parrot-nqp

pir::load_bytecode("opsc.pbc");
pir::load_bytecode("Getopt/Obj.pbc");

my $core := 0;
my @files;
my $emit_lines := 1;

my $getopts := Q:PIR{ %r = new ['Getopt';'Obj'] };

$getopts.notOptStop();
my $arg := $getopts.add();
$arg.long('core');

$arg := $getopts.add();
$arg.long('dynamic');
$arg.type('String');

$arg := $getopts.add();
$arg.long('no-lines');

$arg := $getopts.add();
$arg.long('help');
$arg.short('h');

my $opts := $getopts.get_options(pir::getinterp__p()[2]);

if $opts<core> {
    @files := <
        src/ops/core.ops
        src/ops/bit.ops
        src/ops/cmp.ops
        src/ops/debug.ops
        src/ops/io.ops
        src/ops/math.ops
        src/ops/object.ops
        src/ops/pmc.ops
        src/ops/set.ops
        src/ops/string.ops
        src/ops/sys.ops
        src/ops/var.ops
        src/ops/experimental.ops
    >;
    $core := 1;
}
elsif $opts<dynamic> {
    $core := 0;
    @files.push( $opts<dynamic>);
}
elsif (+$opts == 0 || $opts<help>) {
    say("usage:
ops2c --core
ops2c --dynamic path/to/dynops.ops");
    pir::exit(0);
}

if ($opts<no-lines>) {
    #TODO: figure out how to generate line numbers
    # $emit_lines is currently ignored
    $emit_lines := 0;
}

my $trans := Ops::Trans::C.new();
my $start_time := pir::time__N();
my $f;

if $core {
    my $lib := Ops::OpLib.new(
        :num_file('src/ops/ops.num'),
        :skip_file('src/ops/ops.skip'),
    );
    $f := Ops::File.new(|@files, :oplib($lib), :core(1));
}
else {
    $f := Ops::File.new(|@files, :core(0));
}

my $end_time := pir::time__N();
say('# Ops parsed ' ~ ($end_time - $start_time));
my $emitter := Ops::Emitter.new(
    :ops_file($f), :trans($trans),
    :script('ops2c.nqp'), :file(@files[0]),
    :flags( hash( core => $core ) ),
);

if $core {
    # Emit oplib/ops.h
    # TODO Move it somewhere else and test it properly.
    my $ops_h := pir::open__Ps("include/parrot/oplib/ops.h", "w")
                      || die("Can't open ops.h");

    $ops_h.print(q|
/* ex: set ro:
 * !!!!!!!   DO NOT EDIT THIS FILE   !!!!!!!
 *
 * This file is generated automatically from 'src/ops/core.ops'
 * by ops2c.
 *
 * Any changes made here will be lost!
 */

#ifndef PARROT_OPS_H_GUARD
#define PARROT_OPS_H_GUARD

typedef enum {
|);

    my $sb := pir::new__Ps('StringBuilder');
    for $f.ops -> $op {
        $sb.append_format("    PARROT_OP_%0, %1 /* %2 */\n",
                $op.full_name,
                pir::repeat__SsI(' ', 30 - pir::length__Is($op.full_name)),
                $op.code);
    }

    $ops_h.print(~$sb);

    $ops_h.print(q|
} parrot_opcode_enums;

#endif /* PARROT_OPS_H_GUARD */

/*
 * Local variables:
 *   c-file-style: "parrot"
 * End:
 * vim: expandtab shiftwidth=4:
 */
    |);

    $ops_h.close;
}

$emitter.print_c_header_file();
$emitter.print_c_source_file();

# vim: expandtab shiftwidth=4 ft=perl6:

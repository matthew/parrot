#! perl
# # Copyright (C) 2006-2007, The Perl Foundation.
# $Id$
use strict;
use warnings;
use File::Find;
use Cwd;
use lib qw/ lib /;
use Parrot::Op;
use Parrot::OpLib::core;


=head1 The problem

10:23 <toor> # Tests - ~1/3 of opcodes are uncovered by tests <--
             were can I see which ones are not
             tested? (yes, maybe I want to write some tests :p)

10:25 <@leo> toor: run 'make testr', then create a script that runs
             disasseble $_.pbc for all @pbcs,
             extract the opcode, sort, uniq and compare with
             lib/Parrot/OpLib/core.pm
10:26 <@leo> disassemble even
10:26 <@leo> $ make disassemble
10:28 <toor> leo: and if I make a perl5 script that does that
             automagicly, is it usefull for the
             project?
10:28 <@leo> very useful
10:28 <toor> ok, looks that I've got something to start :)
10:28 <@leo> great, thanks

=head1 NOTES

not windows-friendly.

=cut


# First of all we need the disassemble program
system('make disassemble') == 0
    or die "Couldn't make disassemble: $!\n";


# Parse 'lib/Parrot/OpLib/core.pm' to find all defined opcodes
# Extract the full name from the opcode data
my %opcodes;
$opcodes{ $_->full_name }++
    for @$Parrot::OpLib::core::ops;

# Count the number of opcodes
my $opcount = %opcodes;

# So, and *assuming* 'make testr' was runned already,
#     find all .pbc on t/ to disassemble
my $name  = $File::Find::name;


# This struct will hold the uniq opcodes found
my $cwd = Cwd::cwd();
File::Find::find( { wanted => \&wanted }, 't/' );

# This is the callback called by File::Find. Here we get all opcodes from
# the result of the disassemble of the *.pbc files generated by 'make testr'
# The opcodes found are deleted from the hash of all opcodes.
sub wanted {
    return unless /\.pbc$/i;    # We only want *.pbc files

    open F, '<', "$cwd/disassemble $cwd/$name |"
        or warn "can't open $cwd/$name: $!" && return;
    while (<F>) {
        s/L\w+\:\s+//;          # Remove the Lxx marks
        s/^(\w+).*/$1/;         # Extract the opcode
        chomp;
        delete $opcodes{$_};
    }
    close F;
}


# Count how many opcodes from core are not tested
my $percent = 100 * keys( %opcodes ) / $opcount;

# And now send the results to the user
print "$_\n"
    for keys %opcodes;

print scalar( keys %opcodes ) . " of $opcount opcodes untested! ($percent%)\n";


# Local Variables:
#   mode: cperl
#   cperl-indent-level: 4
#   fill-column: 100
# End:
# vim: expandtab shiftwidth=4:

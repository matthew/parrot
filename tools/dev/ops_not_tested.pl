#! perl 

use strict;
use warnings;
use File::Find ();
use Cwd        ();

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

=cut 

# First of all we need the disassemble progrie
system('make disassemble') == 0
    or die "Couldn't make disassemble: $!\n";

# So, and *assuming* 'make testr' was runned already,
#     find all .pbc on t/ to disassemble
use vars qw/*name *dir *prune/;
*name  = *File::Find::name;
*dir   = *File::Find::dir;
*prune = *File::Find::prune;

# This struct will hold the uniq opcodes found
my %opcodes_t;
my $cwd = Cwd::cwd();
File::Find::find( { wanted => \&wanted }, 't/' );

# This is the callback called by File::Find..
#      Here we get all opcodes from the result of the disassemble
#           of the *.pbc files generated by 'make testr'
sub wanted {
    return unless /\.pbc$/i;    # We only want *.pbc files

    open F, '<', "$cwd/disassemble $cwd/$name |";
    while (<F>) {
        s/L\w+\:\s+//;          # Remove the Lxx marks
        s/^(\w+).*/$1/;         # Extract the opcode
        chomp;
        $opcodes_t{$_} = 0;
    }
    close F;
}

# Now parse the 'lib/Parrot/OpLib/core.pm' to find all defined
#     opcodes
use lib qw/lib/;
use Parrot::Op;
use Parrot::OpLib::core;

# Extract the register types from each opcode
my %opcodes_c;
for my $op (@$Parrot::OpLib::core::ops) { $opcodes_c{ $op->full_name } = 0; }

# Now, we need to compare the two hashes
for my $op ( keys %opcodes_t ) {
    $opcodes_c{$op}++ if exists $opcodes_c{$op};
}

# Count how many opcodes from core are not tested
my @opcodes_c_tested = grep { $opcodes_c{$_} == 0 } ( keys %opcodes_c );
my $percent = ( ( scalar @opcodes_c_tested ) * 100 ) / ( scalar keys %opcodes_c );

# And now send the results to the user
print "$_\n" for @opcodes_c_tested;
print ""
    . ( scalar @opcodes_c_tested )
    . " out of "
    . ( scalar keys %opcodes_c )
    . " are not tested! ("
    . int($percent) . "%)\n";

# Local Variables:
#   mode: cperl
#   cperl-indent-level: 4
#   fill-column: 100
# End:
# vim: expandtab shiftwidth=4:

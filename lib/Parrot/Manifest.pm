# $Id$
# Copyright (C) 2007-2010, Parrot Foundation.

=head1 NAME

Parrot::Manifest - Re-create MANIFEST and MANIFEST.SKIP

=head1 SYNOPSIS

    use Parrot::Manifest;

    $mani = Parrot::Manifest->new($0);

    $manifest_lines_ref = $mani->prepare_manifest();
    $need_for_files     = $mani->determine_need_for_manifest($manifest_lines_ref);
    $mani->print_manifest($manifest_lines_ref) if $need_for_files;

    $print_str     = $mani->prepare_manifest_skip();
    $need_for_skip = $mani->determine_need_for_manifest_skip($print_str);
    $mani->print_manifest_skip($print_str) if $need_for_skip;

    $print_str     = $mani->prepare_gitignore();
    $mani->print_gitignore($print_str) if $need_for_skip;

=head1 DESCRIPTION

This package exports no functions.  A Parrot::Manifest object is used in
F<tools/dev/mk_manifest_and_skip.pl>, which in turn is the basis of C<make
manifest_tests>.

=cut

package Parrot::Manifest;
use strict;
use warnings;
use Carp;

=head1 METHODS

=head2 new

    $mani = Parrot::Manifest->new({
        script => $0,
        file => $filename,
        skip => $skipfilename,
        gitignore => $gitignoresfilename,
    })

Creates a Parrot::Manifest object by asking C<svn status> for verbose output,
and parsing the results.

C<file> is the name of the file that the manifest will eventually be written
to, and defaults to F<MANIFEST>.  C<skip> is the name of the file that will
hold the list of files to be skipped, and defaults to F<MANIFEST.SKIP>.
C<gitignore> contains the same information as F<MANIFEST.SKIP> in a different
format.  It defaults to F<.gitignore>.  The C<script> parameter is the name of
the program invoking Parrot::Manifest, for use in messages.

=cut

# ...the results go into $self->{dirs} and $self->{versioned_files}
sub new {
    my $class   = shift;
    my $argsref = shift;

    my $self = bless( {}, $class );

    my %data = (
        id         => '$' . 'Id$',
        time       => scalar gmtime,
        cmd        => 'svn',
        script     => $argsref->{script},
        file       => $argsref->{file}      ? $argsref->{file}      : q{MANIFEST},
        skip       => $argsref->{skip}      ? $argsref->{skip}      : q{MANIFEST.SKIP},
        gitignore  => $argsref->{gitignore} ? $argsref->{gitignore} : q{.gitignore},
    );

    my $status_output_ref = [qx($data{cmd} status -v)];

    # grab the versioned resources:
    my @versioned_files;
    my @dirs;
    my @versioned_output = grep !/^[?D]/, @{$status_output_ref};
    for my $line (@versioned_output) {
        my @line_info = split( /\s+/, $line );

        # the file is the last item in the @line_info array
        my $filename = $line_info[-1];
        $filename =~ s/\\/\//g;

        # ignore .svn, blib directories;
        # ignore ports/ directories, as that information does not need to be
        # in tarball releases
        next if $filename =~ m[/\.svn|^blib|^ports];
        if ( -d $filename ) {
            push @dirs, $filename;
        }
        else {
            push @versioned_files, $filename;
        }
    }
    $data{dirs}            = \@dirs;
    $data{versioned_files} = \@versioned_files;

    # initialize the object from the prepared values (Damian, p. 98)
    %$self = %data;

    return $self;
}

=head2 prepare_manifest

    $manifest_lines_ref = $mani->prepare_manifest();

Prepares the manifest from the read in by the C<new()> method, and returns a
hash of the files.  The keys of the hash are the filenames, and the values are
strings representing the package and a list of the meta flags.

=cut

sub prepare_manifest {
    my $self = shift;

    my %manifest_lines;
    for my $file ( @{ $self->{versioned_files} } ) {
        $manifest_lines{$file} = _get_manifest_entry($file);
    }

    return \%manifest_lines;
}

=head2 determine_need_for_manifest

    $need_for_files =
        $mani->determine_need_for_manifest($manifest_lines_ref);

Determines the need for the manifest.  The checks are:

=over 4

=item *

If there's no manifest yet, we need one.

=item *

If there's a difference between what's already there and what's in the list,
we need a new one.

=back

If a new manifest is needed, the return value is C<1>; otherwise it is
undefined.  The value passed in is the hash as returned from I<e.g.>,
C<prepare_manifest()>.

=cut

sub determine_need_for_manifest {
    my $self               = shift;
    my $proposed_files_ref = shift;

    return 1 unless -f $self->{file};

    my $current_files_ref        = $self->_get_current_files();
    my $different_patterns_count = 0;
    foreach my $cur ( keys %{$current_files_ref} ) {
        $different_patterns_count++ unless $proposed_files_ref->{$cur};
    }
    foreach my $pro ( keys %{$proposed_files_ref} ) {
        $different_patterns_count++ unless $current_files_ref->{$pro};
    }

    $different_patterns_count ? return 1 : return;
}

=head2 print_manifest

    $mani->print_manifest($manifest_lines_ref) if $need_for_files;

Writes the manifest to a file.  The example above does so only if an update is
needed.

=cut

my $text_file_coda = <<'CODA';
# Local variables:
#   mode: text
#   buffer-read-only: t
# End:
CODA

sub print_manifest {
    my $self               = shift;
    my $manifest_lines_ref = shift;

    my $print_str          = <<"END_HEADER";
# ex: set ro:
# $self->{id}
#
# generated by $self->{script} $self->{time} UT
#
# See below for documentation on the format of this file.
#
# See docs/submissions.pod and the documentation in
# $self->{script} on how to recreate this file after SVN
# has been told about new or deleted files.
END_HEADER

    for my $k ( sort keys %{$manifest_lines_ref} ) {
        $print_str .= sprintf "%- 59s %s\n", ( $k, $manifest_lines_ref->{$k} );
    }
    $print_str .= $text_file_coda;
    open my $MANIFEST, '>', $self->{file}
        or croak "Unable to open $self->{file} for writing";
    print {$MANIFEST} $print_str;
    close $MANIFEST or croak "Unable to close $self->{file} after writing";

    return 1;
}

# Gets the package and the meta flags for the given file.  This function does
# it based on the directory the file is in.  If a particular file is needed,
# then _get_special (below) provides that functionality.
sub _get_manifest_entry {
    my $file    = shift;

    my $special = _get_special();
    my $loc     = '[]';
    for ($file) {
        $loc =
              exists( $special->{$_} ) ? $special->{$_}
            : !m[/]                           ? '[]'
            : m[^docs/book/draft/]            ? '[]'
            : m[^docs/]                       ? '[doc]'
            : m[^examples/]                   ? '[examples]'
            : m[README]                       ? '[]doc'
            : m[^include/]                    ? '[main]include'
            : m[^t/]                          ? '[test]'
            : m[/t/]                          ? '[test]'
            : ( m[^languages/(\w+)/] and $1 ne 'conversion' ) ? "[$1]"
            : ( m[^compilers/(\w+)/] and $1 ne 'conversion' ) ? "[$1]"
            : m[^lib/Parrot/]                 ? '[devel]lib'
            : m[^runtime/]                    ? '[library]'
            : m[^src/pmc/.*\.h]               ? '[devel]include'
            : m[^runtime/parrot/library/PCT]  ? '[pct]'
            : m[^runtime/parrot/library/PCT]  ? '[pge]'
            : m[^runtime/parrot/library/TGE]  ? '[tge]'
            : m[^runtime/parrot/library/JSON] ? '[json]'
            :                                   '[]'; # default
    }

    return $loc;
}

# See comments for _get_manifest_entry, above
sub _get_special {
    my %special = qw(
        CREDITS                                         [main]doc
        DEPRECATED.pod                                  [devel]doc
        DONORS.pod                                      [main]doc
        LICENSE                                         [main]doc
        NEWS                                            [main]doc
        PBC_COMPAT                                      [main]doc
        PLATFORMS                                       [devel]doc
        README                                          [devel]doc
        README_win32.pod                                [devel]doc
        README_cygwin.pod                               [devel]doc
        RESPONSIBLE_PARTIES                             [main]doc
        TODO                                            [devel]doc
        VERSION                                         [devel]
        languages/t/harness                             [test]
        lib/File/Which.pm                               [devel]lib
        parrot-config                                   [main]bin
        src/ops/ops.num                                 [devel]src
        src/vtable.tbl                                  [devel]src
        tools/build/ops2c.pl                            [devel]
        tools/build/pmc2c.pl                            [devel]
        tools/dev/mk_language_shell.pl                  [devel]
        tools/dev/create_language.pl                    [devel]
        tools/dev/pbc_to_exe.pir                        [devel]
        tools/dev/gen_makefile.pl                       [devel]
        tools/dev/reconfigure.pl                        [devel]
    );

    return \%special;
}

# Gets files currently listed in manifest, and returns a hash
sub _get_current_files {
    my $self          = shift;

    my %current_files;
    open my $FILE, "<", $self->{file}
        or die "Unable to open $self->{file} for reading";
    while ( my $line = <$FILE> ) {
        chomp $line;

        next if $line =~ /^\s*$/o;

        next if $line =~ /^#/o;

        my ($file) = split /\s+/, $line;
        $current_files{ $file }++;
    }
    close $FILE or die "Unable to close $self->{file} after reading";

    return \%current_files;
}

=head2 prepare_manifest_skip

    $print_str = $mani->prepare_manifest_skip();

Gets a list of the files that SVN ignores, and returns a string that can be
put into F<MANIFEST.SKIP>.

=cut

sub prepare_manifest_skip {
    my $self      = shift;

    my $ignores_ref = $self->_get_ignores();

    return $self->_compose_manifest_skip($ignores_ref);
}

=head2 prepare_gitignore

    $print_str = $mani->prepare_gitignore();

Gets a list of the files that SVN ignores, and then writes it to the
F<.gitignore> file.

=cut

sub prepare_gitignore {
    my $self      = shift;

    my $ignores_ref = $self->_get_ignores();

    return $self->_compose_gitignore($ignores_ref);
}

=head2 determine_need_for_manifest_skip

    $need_for_skip =
        $mani->determine_need_for_manifest_skip($print_str);

Determines whether F<MANIFEST.SKIP> is needed.  The tests used are:

=over 4

=item *

If the file doesn't exist, we need one.

=item *

If the proposed and existing contents differ, we need one.

=back

=cut

sub determine_need_for_manifest_skip {
    my $self      = shift;
    my $print_str = shift;

    if ( !-f $self->{skip} ) {
        return 1;
    }
    else {
        my $current_skips_ref        = $self->_get_current_skips();
        my $proposed_skips_ref       = _get_proposed_skips($print_str);
        my $different_patterns_count = 0;
        foreach my $cur ( keys %{$current_skips_ref} ) {
            $different_patterns_count++ unless $proposed_skips_ref->{$cur};
        }
        foreach my $pro ( keys %{$proposed_skips_ref} ) {
            $different_patterns_count++ unless $current_skips_ref->{$pro};
        }

        $different_patterns_count ? return 1 : return;
    }
}

=head2 print_manifest_skip

    $mani->print_manifest_skip($print_str) if $need_for_skip;

Writes F<MANIFEST.SKIP> to a file.  The example above does so only if needed.

=cut

sub print_manifest_skip {
    my $self      = shift;
    my $print_str = shift;

    open my $MANIFEST_SKIP, '>', $self->{skip}
        or die "Unable to open $self->{skip} for writing";
    $print_str .= $text_file_coda;
    print $MANIFEST_SKIP $print_str;
    close $MANIFEST_SKIP
        or die "Unable to close $self->{skip} after writing";

    return 1;
}

=head2 print_gitignore

    $mani->print_gitignore($print_str) if $need_for_skip;

Writes the F<.gitignore> file.  The example above does so only if needed.

=cut

sub print_gitignore {
    my $self      = shift;
    my $print_str = shift;

    open my $GITIGNORE, '>', $self->{gitignore}
        or die "Unable to open $self->{gitignore} for writing";
    $print_str .= $text_file_coda;
    print $GITIGNORE $print_str;
    close $GITIGNORE
        or die "Unable to close $self->{gitignore} after writing";

    return 1;
}

# Gets a list of files that SVN ignores
sub _get_ignores {
    my $self      = shift;

    my $svnignore = `$self->{cmd} propget svn:ignore @{ $self->{dirs} }`;

    # cope with trailing newlines in svn:ignore output
    $svnignore =~ s/\n{3,}/\n\n/g;
    my %ignores;
    my @ignore = split( /\n\n/, $svnignore );
    foreach (@ignore) {
        my @cnt = m/( - )/g;
        if ($#cnt) {
            my @a = split /\n(?=(?:.*?) - )/, $_;
            foreach (@a) {
                m/^\s*(.*?) - (.+)/sm;
                $ignores{$1} = $2 if $2;
            }
        }
        else {
            m/^(.*) - (.+)/sm;
            $ignores{$1} = $2 if $2;
        }
    }

    return \%ignores;
}

# Turns the list of ignored files into .gitignore format
sub _compose_gitignore {
    my $self        = shift;
    my $ignores_ref = shift;

    my $print_str  = <<"END_HEADER";
# ex: set ro:
# $self->{id}
# generated by $self->{script} $self->{time} UT
#
# This file should contain a transcript of the svn:ignore properties
# of the directories in the Parrot subversion repository.
# The .gitignore file is a convenience for developers  working with git-svn.
# See http://www.kernel.org/pub/software/scm/git/docs/gitignore.html for the
# format of this file.
#
END_HEADER

    foreach my $directory ( sort keys %{$ignores_ref} ) {
        my $dir = $directory;
        $dir =~ s!\\!/!g;
        $print_str .= "# generated from svn:ignore of '$dir/'\n";
        foreach ( sort split /\n/, $ignores_ref->{$directory} ) {
            $print_str .=
                ( $dir ne '.' )
                ? "/$dir/$_\n"
                : "/$_\n";
        }
    }

    return $print_str;
}

# Turns list of ignored files into F<MANIFEST.SKIP> format
sub _compose_manifest_skip {
    my $self       = shift;
    my $ignore_ref = shift;

    my %ignore     = %{$ignore_ref};
    my $print_str  = <<"END_HEADER";
# ex: set ro:
# $self->{id}
# generated by $self->{script} $self->{time} UT
#
# This file should contain a transcript of the svn:ignore properties
# of the directories in the Parrot subversion repository. (Needed for
# distributions or in general when svn is not available).
# See docs/submissions.pod on how to recreate this file after SVN
# has been told about new generated files.
#
# Ignore the SVN directories
\\B\\.svn\\b

# ports/ should not go into release tarballs
^ports\$
^ports/
END_HEADER

    foreach my $directory ( sort keys %ignore ) {
        my $dir = $directory;
        $dir =~ s!\\!/!g;
        $print_str .= "# generated from svn:ignore of '$dir/'\n";
        foreach ( sort split /\n/, $ignore{$directory} ) {
            s/\./\\./g;
            s/\*/.*/g;
            $print_str .=
                ( $dir ne '.' )
                ? "^$dir/$_\$\n^$dir/$_/\n"
                : "^$_\$\n^$_/\n";
        }
    }

    return $print_str;
}

# Gets a list of the currently skipped files from F<MANIFEST.SKIP>
sub _get_current_skips {
    my $self          = shift;

    my %current_skips;
    open my $SKIP, "<", $self->{skip}
        or die "Unable to open $self->{skip} for reading";
    while ( my $line = <$SKIP> ) {
        chomp $line;
        next if $line =~ /^\s*$/o;
        next if $line =~ /^#/o;
        $current_skips{$line}++;
    }
    close $SKIP or die "Unable to close $self->{skip} after reading";

    return \%current_skips;
}

# Gets list of files we're proposing to skip
sub _get_proposed_skips {
    my $print_str      = shift;

    my @proposed_lines = split /\n/, $print_str;
    my %proposed_skips = ();
    for my $line (@proposed_lines) {
        next if $line =~ /^\s*$/o;
        next if $line =~ /^#/o;
        $proposed_skips{$line}++;
    }

    return \%proposed_skips;
}

1;

=head1 MANIFEST FORMAT

The format of the F<MANIFEST> (currently F<MANIFEST> and F<MANIFEST.generated>
are used) is:

    source_path <whitespace> [package]meta1,meta2,...

or you may optionally specify a different destination path:

    source_path <whitespace> [package]meta1,meta2,... <whitespace> destination

Additionally, there may be a C<*> in front of the whole line to designate
a generated file:

    source_path <whitespace> *[package]meta1,meta2,... <whitespace> destination

The square brackets around C<package> are literal. C<package> gives
the name of the RPM that the given file will be installed for, and is
only used by this script to skip files that are not members of any
package.

The various meta flags recognized are:

=over 4

=item C<doc>

Tag this file with C<%doc> in the RPM, and omit the leading path (because
F<rpm> will put it into a directory of its choosing).

=item C<include>

Write this file to the location given by the C<--includedir> option.

=item C<lib>

Write this file to the location given by the C<--libdir> option.

=item C<bin>

Write this file to the location given by the C<--bindir> option.

=back

The optional C<destination> field provides a general way to change
where a file will be written to. It will be applied before any
metadata tags.

Example: if this line is in the F<MANIFEST.generated> file

  languages/snorkfest/snork-compile        [main]bin

and the C<--bindir=/usr/parroty/bin>, then the generated
F<parrot-E<lt>VERSIONE<gt>-1.E<lt>archE<gt>.rpm> file will contain the file
C</usr/parroty/bin/snork-compile>.

=head1 SEE ALSO

F<tools/dev/mk_manifest_and_skip.pl>.

=head1 AUTHOR

James E. Keenan (jkeenan@cpan.org) refactored code from earlier versions of
F<tools/dev/mk_manifest_and_skip.pl>.

=head1 LICENSE

This is free software which you may distribute under the same terms as Perl
itself.

=cut

# Local Variables:
#   mode: cperl
#   cperl-indent-level: 4
#   fill-column: 100
# End:
# vim: expandtab shiftwidth=4:

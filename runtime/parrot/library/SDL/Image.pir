
# $Id$

=head1 NAME

SDL::Image - Parrot class representing images in Parrot SDL

=head1 SYNOPSIS

	# load this library
	load_bytecode 'library/SDL/Image.pir'

	# set a filename in a PMC
	.local pmc filename
	new filename, .String
	set filename, 'examples/sdl/parrot_small.png'

	# create a new SDL::Image object
	.local pmc image
	.local int image_type

	find_type image_type, 'SDL::Image'
	image = new image_type, filename

	# blit and update this object as you like!

=head1 DESCRIPTION

SDL::Image objects represent images loaded from external files.  You'll need to
have the C<SDL_image> library installed to use this.

This class extends SDL::Surface, so any operations you can do on objects of
that class you can do on SDL::Image objects.

=head1 METHODS

An SDL::Image object has the following methods:

=over 4

=cut

.namespace [ 'SDL::Image' ]

.sub _initialize :load
	.local pmc surface_type
	.local pmc image_class
	
	$I0 = find_type 'SDL::Image'
	if $I0 > 1 goto END

	.local pmc init_image
	init_image = find_global 'SDL', '_init_image'
	init_image()

	getclass surface_type,        'SDL::Surface'
	subclass image_class, surface_type, 'SDL::Image'

	.local pmc initializer
	new initializer, .String
	set initializer, 'BUILD'
	setprop image_class, 'BUILD', initializer
END:

.end

=item BUILD( filename )

Given the string C<filename> containing the path to a file to load, loads the
image.

The name of this method may change, per discussion on p6i.

=cut

.sub BUILD method
	.param pmc filename_pmc

	# can only pass PMCs implicitly for now
	.local string filename
	set filename, filename_pmc

	.local pmc IMG_Load
	IMG_Load = find_global 'SDL::NCI', 'IMG_Load'

	.local pmc image

	image = IMG_Load( filename )

	self.'wrap_surface'( image )
.end

=back

=head1 AUTHOR

Written and maintained by chromatic, E<lt>chromatic at wgz dot orgE<gt>, with
suggestions from Jens Rieks.  Please send patches, feedback, and suggestions to
the Perl 6 Internals mailing list.

=head1 COPYRIGHT

Copyright (C) 2004-2006, The Perl Foundation.

=cut

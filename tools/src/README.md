The 4 C files here can be build using the gcc command line.
All they do is provide raw frequency counts for the nscores program.


The Nscores program combines all of the frequency files and performs some
relatively minor math to change them from frequencies to a log based score
or a rough equivalent. Look at the Nscores main.c for the deails.

Use the BldNscores_h.bat file to build the nscores.h file.

BldNscores_h corpus.txt

It will create 4 text files and then combine them into the nscores.h file.
Run time is anywhere from a few seconds to several minutes depending on
the size of your corpus. I suggest a corpus file of less than 5Gb to
save time and avoid any overflow conditions.

Alternately you can run the programs manually. The 4 frequency counter
programs need an in file and an outfile. The nscores program has
the file names embedded so be sure to use the same filenames in the
BldNscores_h.bat file.

The QuadgrmH program may not reliably run on some computers. It uses
at over 1827904 bytes of memory and sometimes likes to crash rather than run. I suspect
it is a memory allocaion problem in Windows. It doesn't matter how you
build them, large arrays tend to cause problems.

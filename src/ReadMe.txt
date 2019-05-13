
Building
========
The makefile is just a basic makefile. A few DOS/Windows specific
things have been removed. For linux, you may want to remove the
.EXE from the file name. You can probably just as easily build
it from the command line with GCC.

The program builds with Dev-C++ and Msys2/32/64 both using GCC.
Linux GCC wasn't tested, but it should work.

The header file nscores.h is over 6Mb by itself when unzipped.
The programs that generated that file are not included. As of
this writing, they are an ugly hack of file loaders that were
originally part of the program. The problem is C doesn't always
like to dynamically load a file that large.

Running
=======
The entire program is designed to be a test bed. There are plans for
additional ciphers as well as alternate scoring systems and other
search algorithms. Which means all of this is subject to change.
As an example, simulated annealing could be created by swaping
out the hillclimb files or added with a few conditionals and 
parameters. A similar trick can be used for new or added ciphers.

The command line for HillClmb can be a little complicated. There are
no sanity checks on the trial limit or loop limit. Use small numbers
less than 1000 for the trial limit and generally 10000 is more than
enough for the loop limit.

A quick command line looks like this:
hillclmb 4rs100 4000 cipher.txt hillout.txt

If you try to run the program without parameters you'll get the usage
message partially shown below. Missing or bad paramters or other problems
will result in an error message and exit. 

usage: HillClmb ntsnn looplmt infile outfile <keyfile>

n       = 1 mono, 2 digram, 3 trigram, 4 quadgram scoring
t       = r=random, s=selection, e=experiment
snn       = (optional) s=shotgun and nn= the number of keys to try.
looplmt = Search loop count limit (typ. 10000)
infile  = Ciphertext input file
outfile = Possible key and decrypt file
keyfile = Optional starting key file (26 letters in any order)

The first parameter is a number for the N-gram score. The quadgram
score usually works best, but the trigram and digram scoring sometimes
works faster or better than the quadgram scoring. The monogram score is
not of much use but it is included because it doesn't take much space and
it may be used to generate a starting key.

The secont parameter is the type of letter swap. The random swap uses
an additive fibonachi generator with a fairly long period. The selection
swap is based on the selection sort and attempts an organized swap.
The experimental swap is based on the selection sort but uses a random
alphabet key to swap letters. The selection swap doesn't work and the
experimental swap may eventually become a permanent swap type. This is
a test bed for ideas so there are many things that may change here.

The third parameter turns on the shotgun loop and is limited by the number
that follows it. This parameter is optional and if left off, it may still
find a working key if your text is large enough.

The looplmt parameter forces the hill climb loop to exit when no better
keys are found. You can speed up long searches by fine tuning this, but
you'll find tha even at 10000 the program will generate keys very quickly.

The infile is the path and file name of your ciphertext. The ciphertext
does need to be in ASCII format and it converts upper or lower case letters.
All other symbols and numbers are ignored.

The outfile is the path and file name of your results file. Since every
trial plaintext generated has alredy been scored as "English", you'll
need to manual search through the file or do trial word searches to find
any plaintext results that may be from a good key.

The optional keyfile is the path and file name of a file containing a 26
letter alphabetic key. Each letter may only be used once. In the future,
this may be cipher specific such as a 6x6 polybius square. You can use this
to continue a search, but since the random number generator state is not
saved, it would not be the same as a run without a break. Given the nature
of random nunber generation, this may or may not affect any outcome.


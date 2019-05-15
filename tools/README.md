The nscores.h build files.

These programs were made special to build the nscores.h file.
If you want more human readable counters use the CryptoProject
versions. If you are using the nscores.zip file you don't need
these files at all.

If you are building your own scores file then this is the place
to start. You can make changes if you want, but they are working
better than other score files I've found.


FreqH.c    - 1 letter frequency (26)
DigramH.c  - 2 letter frequencies (676)
TrigramH.c - 3 letter frequencies (17576)
QuadgrmH.c - 4 letter frequencies (456976)
Nscores   - Combines the frequecy files into C arrays. (nscores.h)


The corpus file will never be included. It is assumed that you can
get your own or that you are building an alternate language file.
Some changes will be needed for use with alternate languages.
The nscores.h file was origunally compiled from a 1Gb or larger corpus.
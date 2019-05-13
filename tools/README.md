The nscores.h build files.

These programs were made special to build the nscores.h file.
If you want more human readable counters use the CryptoProject
versions.


monogram.c - 1 letter frequency (26)
digram.c   - 2 letter frequencies (676)
trigram.c  - 3 letter frequencies (17576)
quadgram.c - 4 letter frequencies (456976)
scrbld.c   - Combines the frequecy files into C arrays. (nscores.h)


The corpus file will never be included. It is assumed that you can
get your own or that you are building an alternate language file.
Some changes will be needed for use with alternate languages.
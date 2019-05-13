CryptoHillClimber

This program is highly experimental.

While it has a lot of error detection, it may be possible to break it
at various times. It is also possible to abuse the program by setting
insane limits. Most numbers internally are 32 bit integers which allows
numbers large enough to fill your hard drive with junk. Even relatively
sane numbers can generate files over 10Mb.

The command line may change without notice. One of the problems with making
so many things optional and configurable is that the command line will
change with the addition of new features or changes. The command line is
then used to "program" how the hillclimber runs.

The primary reason for this program is to serve as a testbed for various
ideas that may fail or ultimately be useless. It may contain code that
does nothing except waste space. Some or all of this may be eliminated
with the various #defines that add or remove optional parts.

Eventually there will be several possible random number generators, search
methods and key generators. Because the basic algorithm is very similar,
I may allso add simulated annealing. I'm making this dynamically available
through the command line and internally pointers to functions to preserve
speed and keep the inner loops clean. I also hope to create DLL's so that
multiple cipher types can be used with with simple add-on's rather than
build them all into the program.

Read the ReadMe.txt file before attempting to build it or use it. This
file should be the most current file for command line or build changes.

The nscores.h file is about 6Mb unzipped and contains the scoring tables
based off of a 1Gb English corpus. Eventually I plan on publishing the
programs used to build the tables, but currently some of it is just a
quick hack. The size of the nscores.h file is one reason I want to make
the program modular so that alternate languages and alternate scoring
systems may be used.
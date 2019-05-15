If you are digging around here, I assume you know at least a little.


The fgetst.c/h is a function set roughly equivalent to a small C++ class.
All it does is read a line of text regardless of the native line
terminators. I wanted the universal C equivalent of BASIC's LINE INPUT
and wrote one.

Some of my test files do not have DOS/Win line terminators so this
is probably the next best thing to a C library function.
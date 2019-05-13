# Project: HillClmb

CPP      = g++
CC       = gcc
OBJ      = HillClimb.o MonoAlph.o RndGen.o Core.o Main.o
LINKOBJ  = HillClimb.o MonoAlph.o RndGen.o Core.o Main.o
LIBS     = 
INCS     = 
CXXINCS  = 
BIN      = HillClmb.exe
CXXFLAGS = $(CXXINCS) -Ofast -Wall -Wextra -pedantic
CFLAGS   = $(INCS) -Ofast -Wall -Wextra -pedantic
RM       = rm -f

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after

clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CC) $(LINKOBJ) -o $(BIN) $(LIBS)

HillClimb.o: HillClimb.c
	$(CC) -c HillClimb.c -o HillClimb.o $(CFLAGS)

MonoAlph.o: MonoAlph.c
	$(CC) -c MonoAlph.c -o MonoAlph.o $(CFLAGS)

RndGen.o: RndGen.c
	$(CC) -c RndGen.c -o RndGen.o $(CFLAGS)

Core.o: Core.c
	$(CC) -c Core.c -o Core.o $(CFLAGS)

Main.o: Main.c
	$(CC) -c Main.c -o Main.o $(CFLAGS)

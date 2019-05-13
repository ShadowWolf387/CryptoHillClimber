/****************************************************************************
* RndGen.h
*
* Header for RndGen.c
* See RndGen.c for details. Some things may be incomplete 
****************************************************************************/
#define FIBPRNG			/* Fibonacci style PRNG. No Multiplication or modulus */
//#define LCGPRNG		/* Linear Congruential Generator */

/* FIBPRNG sizes and limits constants. Change at your own risk. */
#define SEEDSIZE 26
#define INITLOOP 2600
#define ARRYSIZE 75
#define PNTRSIZE 3
#define RNDSIZE 26


/* RndGen variables */
int rndarray[ARRYSIZE],rndpoint[PNTRSIZE],rndsel;

void RndInit(void);
int RndGen(void);

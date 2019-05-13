/****************************************************************************
* MonoAlph.h
*
* Header for MonoAlph.c
* See MonoAlph.c for details 
****************************************************************************/
#include <stdio.h>

/**************************************************************************** 
* Keygen types available (Select one)
* ! Some Keygen functions may not be implemented or working yet.
****************************************************************************/
#define RANDOM		/* Random swaps. Similar to fractal filling */
#define SLCTSRCH	/* Selection style moving swaps (fails)*/
//#define BBLSRCH		/* ! Bubble sort style moving swaps */
//#define CKTLSRCH	/* ! Bi-directional bubble swaps */
#define EXPRMNT		/* ! Unknown. Use at your own risk. */

#define KEYSZ 26 

/* Function Definitions */
void InitKey(void);
void GenKeyR(void);
void GenKeyS(void);
void GenKeyB(void);
void GenKeyC(void);
void GenKeyE(void);
void Shotgun(void);
void Decrypt(void);
void SwapKey(void);
void ReadKey(void);
void WriteKey(void);


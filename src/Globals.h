/****************************************************************************
* Globals.h
*
* All the global varriables.
*
* This should be mostly universal for all ciphers.
****************************************************************************/
#include <stdio.h>

#define KEYSIZE 26
#define TXTSIZE 4000
#define SGNLMT 100;

int *Key;
int NewKey[KEYSIZE]; /* New Key array */
int BstKey[KEYSIZE]; /* Best Key array */
int bstskr,lstskr,newskr; /* New, Last and Best score storage */
int bkc; /* Best Key Count = The current best key win count */
int bstwin; /* Best win count */
int KeySwap1,KeySwap2;
int Ks1,Ks2;

int ctxtsz,ptxtsz;					/* Text actual size */
int ctext[TXTSIZE];	/* Ciphertext buffer */
int ptext[TXTSIZE];	/* Plaintext buffer */

long lpcnt;							/* Loop count */
int lplmt;							/* Loop limit */

FILE *fi,*fk,*fo; /* File pointers for input, key and output */
char *freqpath;		/* Pointer for the freq files path environ variable */

int GenType;
void (*GenStats)(void);		/* Pointer to allow dynamic switching */
void (*GenKey)(void);		/* Pointer to allow dynamic switching */

void HillClimb(void);	/* Definition for HillClimb(). Avoids a header file. */

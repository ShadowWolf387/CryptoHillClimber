/****************************************************************************
* HillClmb.c
* Hill climber basic algorithm.
*
* Look at the <algorithm>.c file for cipher handling.
* Cipher is treated like a C++ class.
****************************************************************************/
#include <stdio.h>
#include "Globals.h"
#include "MonoAlph.h"


/****************************************************************************
* Hill Climbing Algorithm
*
*This is the general hill climbing loop
****************************************************************************/
void HillClimb(void){
	int Tmp;
	/* Set Key Pointer */
	Key=NewKey;
	/* Initial Decrypt */
	Decrypt();
	/* Set initial stats */
	GenStats();
	bstskr=newskr;
	InitKey();
	bstwin=bkc=0;
	lpcnt=0;
	/* Main Loop */
	do{
		/* Modify key */
		GenKey();
		/* Trial decrypt */
		Decrypt();
		/* Gather stats */
		GenStats();
		/* New key better? */
		if(newskr>bstskr){
			/* Save new key swap */
			lstskr=bstskr;
			bstskr=newskr;
			Tmp=BstKey[KeySwap1];
			BstKey[KeySwap1]=BstKey[KeySwap2];
			BstKey[KeySwap2]=Tmp;
			/* Save highest win count */
			if(bkc>bstwin)bstwin=bkc;
			/* Reset old key count */
			bkc=0;
		}else{
			/* Inc old key count */
			bkc++;
			/* Put keyswap back */
			Tmp=NewKey[KeySwap1];
			NewKey[KeySwap1]=NewKey[KeySwap2];
			NewKey[KeySwap2]=Tmp;
		}
		lpcnt++;
		/* Exit when old key count reaches limit */
		/* Minimum should be about 700 or more (26*26 random swaps) */ 
	}while(bkc<lplmt); /* Test */
}


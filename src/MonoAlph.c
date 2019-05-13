/****************************************************************************
* MonoAlph.c
*
* This should serve as a template for future adaptations of other ciphers.
*
* A mono-alphabetic cipher adapted for hillclimbing.
* Expects a 26 letter alphabet key.
* All functions declared inline and void.
* Uses global variables.
*
* Expects a 26 letter mono-alphabetic key. May be upper or lower case.
****************************************************************************/
#include <stdio.h>
#include "Globals.h"
#include "MonoAlph.h"
#include "RndGen.h"

/* Random Table */
int RndTbl[26]={8,19,7,0,12,18,14,1,4,23,2,17,16,
					10,22,5,24,13,25,9,3,20,11,15,6,21};

/****************************************************************************
* Initialize some stuff
****************************************************************************/
void InitKey(void){
#ifdef SLCTSRCH
	if(GenType==2){
		KeySwap1=0;
		KeySwap2=1;
	}
#endif
#ifdef EXPRMNT
	if(GenType==5){
		Ks1=0;
		Ks2=1;
	}
#endif
}
/****************************************************************************
* Generate a new key from an old key. Uses global variables.
* Needs to retain varaibles to avoid repeating mistakes.
* Change the defines to allow various keygen funcions.
****************************************************************************/
#ifdef RANDOM 
void GenKeyR(void){
	int Tmp;
	KeySwap1=RndGen();
	KeySwap2=RndGen();
	while(KeySwap2==KeySwap1)KeySwap2=RndGen();
	Tmp=NewKey[KeySwap1];
	NewKey[KeySwap1]=NewKey[KeySwap2];
	NewKey[KeySwap2]=Tmp;
}
#endif
/****************************************************************************
* Performs a deterministic "selection sort" of letter pairs.
****************************************************************************/
#ifdef SLCTSRCH
void GenKeyS(void){
	int Tmp;
	Tmp=NewKey[KeySwap1];
	NewKey[KeySwap1]=NewKey[KeySwap2];
	NewKey[KeySwap2]=Tmp;
	KeySwap2++;
	if(KeySwap2==KEYSZ){
		KeySwap1++;
		if(KeySwap1==KEYSZ-1)KeySwap1=0;
		KeySwap2=KeySwap1+1;
	}
}
#endif
/****************************************************************************
* Experimental keygen May not work well or at all.
****************************************************************************/
/****************************************************************************
* Random Table "Selection Sort" search
****************************************************************************/
#ifdef EXPRMNT 
void GenKeyE(void){
	int Tmp;
	KeySwap1=RndTbl[Ks1];
	KeySwap2=RndTbl[Ks2];
	Tmp=NewKey[KeySwap1];
	NewKey[KeySwap1]=NewKey[KeySwap2];
	NewKey[KeySwap2]=Tmp;
	Ks2++;
	if(Ks2==KEYSZ){
		Ks1++;
		if(Ks1==KEYSZ-1)Ks1=0;
		Ks2=Ks1+1;
	}
}
#endif
void Shotgun(void){
	int r,Tmp,x;
	for(x=0;x<KEYSIZE;x++){
		r=RndGen();
		while(r==x)r=RndGen();
		Tmp=BstKey[x];
		BstKey[x]=BstKey[r];
		BstKey[r]=Tmp;		
	}
	for(x=0;x<KEYSIZE;x++)NewKey[x]=BstKey[x];
}
/****************************************************************************
* Basic decrypt function for trial decrypts.
****************************************************************************/
void Decrypt(void){
	int x;
	for(x=0;x<ctxtsz;x++){
		ptext[x]=Key[ctext[x]];
	}
	ptxtsz=x;
}
inline void SwapKey(void){
}
/****************************************************************************
* Expects a 26 letter mono-alphabetic key.
* Key may be upper or lower case.
****************************************************************************/
void ReadKey(void){
	int c,x;
	for(x=0;x<KEYSZ;x++){
		c=fgetc(fk);
		if(c>='a'&&c<='z')c-=32;
		if(c>='A'&&c<='Z'){
			BstKey[x]=NewKey[x]=c-65;
		}
	}
}
/****************************************************************************
* Writes/Appends a 26 letter mono-alphabetic possible solution key
* Assumes you can decrypt
****************************************************************************/
void WriteKey(void){
	int x,y=0,z=0;
	/* Write decrypt key */
	for(x=0;x<KEYSZ;x++){ 
		fprintf(fo,"%c",BstKey[x]+65);
		NewKey[BstKey[x]]=x;
	}
	fprintf(fo,"\n");
	/* Write alphabet */
	for(x=0;x<KEYSZ;x++){
		fprintf(fo,"%c",x+65);
	}
	fprintf(fo,"\n");
	/* Write encrypt key */
	for(x=0;x<KEYSZ;x++){
		fprintf(fo,"%c",NewKey[x]+65);
	}
	fprintf(fo,"\n");
	fprintf(fo,"\nText Size = %d/%d    Win Count = %d\n",ctxtsz,ptxtsz,bstwin);
	fprintf(fo,"Best = %d     Last = %d     New = %d\n",bstskr,lstskr,newskr);
	fprintf(fo,"Loop Count = %ld      Search Count = %ld\n",lpcnt,lpcnt-lplmt);
	fprintf(fo,"\n");
	Key=BstKey;
	Decrypt();
	/* Show decrypt */
	for(x=0;x<ptxtsz;x++){
		fprintf(fo,"%c",ptext[x]+65);
		y++;
		if(y==5){
			z++;
			if(z==10){
				fprintf(fo,"\n");
				z=0;
			}else{
				fprintf(fo," ");
			}
			y=0;
		}
	}
	fprintf(fo,"\n\n");
}


/****************************************************************************
* Core.c
* 
* Core functions that are not algorithm specific.
****************************************************************************/
#include <stdlib.h>
#include <math.h>
#include "Globals.h"
#include "Core.h"
#include "nscores.h"

/****************************************************************************
* Reads the ciphertext into a buffer
****************************************************************************/
void ReadCtext(void){
	int c,x=0;
	while((c=fgetc(fi))!=EOF){
		if(c>='a'&&c<='z')c-=32;
		if(c>='A'&&c<='Z'){
			ctext[x]=c-65;
			x++;
		}
	}
	ctxtsz=x;
}
/****************************************************************************
* Generate stats for quality rating.
****************************************************************************/
void GenStats1(void){
	int x;
	newskr=0;
	for(x=0;x<ptxtsz;x++)newskr+=mgs[ptext[x]];
}
void GenStats2(void){
	int x;
	newskr=0;
	for(x=1;x<ptxtsz;x++)newskr+=dgs[ptext[x-1]*26+ptext[x]];
}
void GenStats3(void){
	int x;
	newskr=0;
	for(x=2;x<ptxtsz;x++){
		newskr+=tgs[ptext[x-2]*676+ptext[x-1]*26+ptext[x]];
	}
}
void GenStats4(void){
	int x;
	newskr=0;
	for(x=3;x<ptxtsz;x++){
		newskr+=qgs[ptext[x-3]*17576+ptext[x-2]*676+ptext[x-1]*26+ptext[x]];
	}
}



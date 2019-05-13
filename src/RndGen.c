/****************************************************************************
* RndGen.c
*
* Generates Random numbers  
****************************************************************************/
#include "Globals.h"
#include "RndGen.h"

void RndInit(void){
	int x;
	rndsel=2;
	rndpoint[0]=0;
	rndpoint[1]=3;
	rndpoint[2]=SEEDSIZE;
	for(x=0;x<SEEDSIZE;x++)rndarray[x]=BstKey[x];
	for(x=0;x<INITLOOP;x++)RndGen();
}
int RndGen(void){
	int rtn;
	rtn=rndarray[rndpoint[0]]+rndarray[rndpoint[1]];
	while(rtn>RNDSIZE-1)rtn-=RNDSIZE;
	rndarray[rndpoint[2]]=rtn;
	rndpoint[0]++;
	rndpoint[1]++;
	rndpoint[2]++;
	if(rndpoint[rndsel]>ARRYSIZE-1){
		rndpoint[rndsel]=0;
		rndsel--;
		if(rndsel<0)rndsel=2;
	}
	return rtn;
} 


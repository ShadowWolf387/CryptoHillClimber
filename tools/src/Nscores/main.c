#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fgetst.h"

#define NOCOMMENTS

void Read1GrmTbl(void);
void Read2GrmTbl(void);
void Read3GrmTbl(void);
void Read4GrmTbl(void);

FILE *fo;

int main(int argc, char *argv[]){
	
	if((fo=fopen("nscores.h","wt"))==NULL){
		printf("Output file open failed.\n");
		return 1;
	}
	Read1GrmTbl();
	Read2GrmTbl();
	Read3GrmTbl();
	Read4GrmTbl();
	fclose(fo);
	return 0;
}
/****************************************************************************
* Reads from monogram sample file.
* File is expected to have entries for all monograms.
****************************************************************************/
void Read1GrmTbl(void){
	unsigned char *buf;
	char filepath[255];
	int c,cnt=0,i,l,n=0,x;
	long fc[26];
	FILEST *f;
	for(x=0;x<26;x++)fc[x]=0;
	f=fopenst(50,"mngm.txt");
	fprintf(fo,"int mgs[26]={\n");
	while(feofst(f)!=1&&n<26){
		if((l=fgetst(f))<=0){
			printf("ERROR: Monogram file read failed.\n\n");
			exit(2);
		}
		buf=getstr(f);
		cnt=i=0;
		while(buf[i]==32&&i<l)i++;
		/* get number */
		while(i<l&&buf[i]!=32){
			c=buf[i];
			if(c>='0'&&c<='9'){
				cnt=cnt*10+(c-48);
			}
			i++;
		}
		while(buf[i]==32&&i<l)i++;
		/* Get letters */
		fc[buf[i]-65]=cnt;
		n++;
	}
	n=fc[4]; /* E count */
	/* Find lowest letter count */
	for(x=0;x<26;x++)if(fc[x]<n)n=fc[x];
	if(n<=0)n=0;
	/* Write scores */
	for(x=0;x<26;x++){
		i=(int)((fc[x]*2)/n);
		if(x!=25)
#ifndef NOCOMMENTS
			fprintf(fo,"%d, /*%c*/\n",i,x+65);
		else
			fprintf(fo,"%d}; /*%c*/\n",i,x+65);
#else
			fprintf(fo,"%d,\n",i);
		else
			fprintf(fo,"%d};\n",i);
#endif
	}
	fclosest(f);
}
/****************************************************************************
* Reads from a digram sample file.
* File is expected to have entries for all digrams.
****************************************************************************/
void Read2GrmTbl(void){
	unsigned char *buf;
	char filepath[255];
	int c,cnt=0,i,l,n=0;
	double lg;
	FILEST *f;
	
	f=fopenst(50,"digm.txt");
	fprintf(fo,"int dgs[676]={\n");
	while(feofst(f)!=1&&n<676){
		if((l=fgetst(f))<=0){
			printf("ERROR: Digram file read failed.\n\n");
			exit(2);
		}
		buf=getstr(f);
		cnt=i=0;
		while(buf[i]==32&&i<l)i++;
		/* get number */
		while(i<l&&buf[i]!=32){
			c=buf[i];
			if(c>='0'&&c<='9'){
				cnt=cnt*10+(c-48);
			}
			i++;
		}
		while(buf[i]==32&&i<l)i++;
		/* Get letters */
		if(cnt<1)cnt=1;
		lg=log(cnt);
#ifndef NOCOMMENTS
		fprintf(fo,"%d /*%c%c*/",(int)(lg*lg),buf[i],buf[i+1]);
#else
		fprintf(fo,"%d",(int)(lg*lg));
#endif
		n++;
		if(n!=676)fprintf(fo,",\n");
	}
	fprintf(fo,"};\n");
	fclosest(f);
}
/****************************************************************************
* Reads from a trigram sample file.
* File is expected to have entries for all trigrams.
****************************************************************************/
void Read3GrmTbl(void){
	unsigned char *buf;
	char filepath[255];
	int c,cnt=0,i,l,n=0;
	double lg;
	FILEST *f;
	f=fopenst(50,"trgm.txt");
		fprintf(fo,"int tgs[17576]={\n");
	while(feofst(f)!=1&&n<17576){
		if((l=fgetst(f))<=0){
			printf("ERROR: Trigram file read failed.\n\n");
			exit(2);
		}
		buf=getstr(f);
		cnt=i=0;
		while(buf[i]==32&&i<l)i++;
		/* get number */
		while(i<l&&buf[i]!=32){
			c=buf[i];
			if(c>='0'&&c<='9'){
				cnt=cnt*10+(c-48);
			}
			i++;
		}
		while(buf[i]==32&&i<l)i++;
		/* Get letters */
		if(cnt<1)cnt=1;
		lg=log(cnt);
#ifndef NOCOMMENTS
		fprintf(fo,"%d /*%c%c%c*/",(int)(lg*lg),buf[i],buf[i+1],buf[i+2]);
#else
		fprintf(fo,"%d",(int)(lg*lg));
#endif
		n++;
		if(n!=17576)fprintf(fo,",\n");
	}
	fprintf(fo,"};\n");
	fclosest(f);
}
/****************************************************************************
* Reads from a quadgram sample file.
* File is expected to have entries for all quadgrams.
****************************************************************************/
void Read4GrmTbl(void){
	unsigned char *buf;
	char filepath[255];
	int c,cnt=0,i,l,n=0;
	double lg;
	FILEST *f;
	f=fopenst(50,"qdgm.txt");
		fprintf(fo,"int qgs[6456976]={\n");
	while(feofst(f)!=1&&n<456976){
		if((l=fgetst(f))<=0){
			printf("ERROR: Quadgram file read failed.\n\n");
			exit(2);
		}
		buf=getstr(f);
		cnt=i=0;
		while(buf[i]==32&&i<l)i++;
		/* get number */
		while(i<l&&buf[i]!=32){
			c=buf[i];
			if(c>='0'&&c<='9'){
				cnt=cnt*10+(c-48);
			}
			i++;
		}
		while(buf[i]==32&&i<l)i++;
		/* Get letters */
		if(cnt<1)cnt=1;
		lg=log(cnt*3);
#ifndef NOCOMMENTS
		fprintf(fo,"%d /*%c%c%c%c*/",(int)(lg*lg),buf[i],buf[i+1],buf[i+2],buf[i+3]);
#else
		fprintf(fo,"%d",(int)(lg*lg));
#endif
		n++;
		if(n!=456976)fprintf(fo,",\n");
	}
	fprintf(fo,"};\n");
	fclosest(f);
}

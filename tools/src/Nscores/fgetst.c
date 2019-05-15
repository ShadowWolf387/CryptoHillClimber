/**************************************************************************
* fgetst.c
* Read any text line regardless of how it is terminated.
* MSDOS/Win CR/LF, APPLE CR, Unix/Linux LF, Other LF/CR.
*
* This is in many ways a replacement for fgets() but it doesn't depend
* on native file terminations. 
*
* As this is a read only text fuction, files are opened as C "rt"
* Struct and string buffer dynamically allocated to allow multiple files.
* fclosest() automatically deallocates buffer and closes file.
*
* While you can directly access the FILEST structure members,
* it is suggested that you treat it as an object and use the
* accessor functions.
*
* All functions return NULL, 0 or EOF if FILEST pointer == NULL.
* if an error is detected, all functions should fail gracefully.
*
* FILEST *fopenst(int bufsize, char *filename) returns pointer or NULL
* int fgetst(FILEST *fst) Returns string size
* int feofst(FILEST *fst) Returns TRUE or FALSE (1 or 0)
* void rewindst(FILEST *fst) Reset file pointer to start.
* int fclosest(FILEST *fst) Closes the file
*
* int lenst(void) Returns string length in buffer
* unsigned char *getst(FILEST *buf) Returns pointer to string buffer
**************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "fgetst.h"

#define SILENT

/**************************************************************************
The typedef FILEST struct is included here only as a reference.
It is included in the fgetst.h file where it is needed.

typedef struct{
	FILE *File;
	int EOFflag;
	int BufferSize;
	unsigned char *String;
	int Length;
}FILEST;
**************************************************************************/

FILEST *fopenst(int buffsize, char *filename){
	/* If anything fails at any time, clean up and return NULL */
	FILEST *fst;
#ifndef SILENT 
		printf("fgetst opening '%s'...\n",filename);
#endif
	/* Allocate a buffer and it's string buffer */
	if((fst=malloc(sizeof(FILEST)))!=NULL){
		if((fst->String=malloc(buffsize+1))==NULL){
			/* String malloc() failed. */
#ifndef SILENT 
			printf("fgetst buffer malloc failed.\n");
#endif
			free(fst);
			return NULL;
		}
	}else{
		/* FILEST malloc() failed. */
#ifndef SILENT 
			printf("fgetst type malloc failed.\n");
#endif
		return NULL;
	}
#ifndef SILENT 
			printf("fgetst malloc success.\n");
#endif
	/* Open file in read only text mode */
	if((fst->File=fopen(filename,"rt"))==NULL){
		/* File open failed. */
#ifndef SILENT 
		printf("fgetst File open failed.\n");
#endif
		fclosest(fst);
		return NULL;
	}
#ifndef SILENT 
			printf("fgetst file open success.\n");
#endif
	/* Initialize remaining FILEST variables */
	fst->BufferSize=buffsize;
	fst->Length=0;
	fst->EOFflag=0;
#ifndef SILENT 
	printf("fgetst success.\n");
#endif
	return fst;
}
int fgetst(FILEST *fst){
	int b,c,d;
	if(fst==NULL)return 0;
#ifndef SILENT 
			printf("fgetst read line...\n");
#endif
	/* get a line no matter how it ends. */
	b=-1;
	do{
		b++;
		c=fgetc(fst->File);
		/* Make sure zero bytes become white space. */
		if(c==0)c=32;
		fst->String[b]=c;
		/* Limit line length to string size of 256 bytes */
	}while(c!=10&&c!=13&&c!=EOF&&b<fst->BufferSize);
	if(c!=EOF){
		/* Now we have a line except there can be another terminator char. */
		d=fgetc(fst->File);
		/*
			Checking for a single char termination.
			Put it back if not a terminator or a blank line.
		*/
		if((d!=10&&d!=13)||c==d)ungetc(d,fst->File);
	}
	/* Set EOF if the file is empty */
	if(c==EOF||d==EOF){
		fst->EOFflag=1;
	}else{
		fst->EOFflag=0;
	}
	/* Properly terminate the string. Overwrites end of line char */
	fst->String[b]=0;
	fst->Length=b;
#ifndef SILENT 
			printf("fgetst read line success.\n");
#endif
	return fst->Length;
}
int feofst(FILEST *fst){
	if(fst==NULL)return 1;
	return fst->EOFflag;
}
void rewindst(FILEST *fst){
	if(fst==NULL)return;
	rewind(fst->File);
	fst->EOFflag=0;
}
void fclosest(FILEST *fst){
	/* Close the file and free up buffers. */
	fclose(fst->File);
	free(fst->String);
	free(fst);
}
unsigned char *getstr(FILEST *fst){
	if(fst==NULL)return NULL;
	return fst->String;
}
int lenst(FILEST *fst){
	if(fst==NULL)return 0;
	return fst->Length;
}


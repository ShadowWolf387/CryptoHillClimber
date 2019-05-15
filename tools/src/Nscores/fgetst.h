/***************************************************************************
* fgetst.h
*
* See comments in fgetst.c
***************************************************************************/
#include <stdio.h>

typedef struct {
	FILE *File;
	int EOFflag;
	int BufferSize;
	unsigned char *String;
	int Length;
}FILEST;


FILEST *fopenst(int size,char *fname);
int fgetst(FILEST *buf);
int feofst(FILEST *buf);
void fclosest(FILEST *buf);
unsigned char *getstr(FILEST *buf);
int lenst(FILEST *buf);


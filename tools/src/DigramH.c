/********************************************************************
* DigramH.c
* A custom digram frequency counter for generating the
* hill climber score files.
********************************************************************/
#include <stdio.h>

int main(int argc, char *argv[]){
	FILE *fi,*fo;
  /* Misc. junk variables and loop counters */
  int c, x, y;
  /* letter work variables */
  int c1, c2;
  /* contact arrays */
  long t, cc[26][26];

  /* Splash message */
	printf("\nDigram Frequency Counter\n");
	printf("Copyright 2019 ShadowWolf387\n\n");
  /* Display usage if not correct number of arguments */
	if(argc<3||argc>3){
		printf("Usage: Digram infile outfile\n\n");
		printf("infile  = input path and file name\n");
		printf("outfile = output path and file name\n\n");
		printf("Makes a Digram frequency count file.\n");
		printf("Special output for Hill climber\n");
		return 1;
	}
  /* Open files. Exit gracefully on error */
	if((fi=fopen(argv[1],"rb"))==NULL){
		printf("Can't open input file '%s'\n",argv[1]);
		return 1;
	}
	if((fo=fopen(argv[2],"wt"))==NULL){
		printf("Can't open output file '%s'\n",argv[2]);
		fclose(fi);
		return 1;
  }
  /* Initialize arrays and variables as needed */
  for(x=0;x<26;x++){
  	for(y=0;y<26;y++)cc[x][y]=0;
  }
  /* Read in and do counts */
  c2=c1=0;
  t=0;
	while((c=getc(fi))!=EOF){
		/* Count only letters */
		if((c>64&&c<91)||(c>96&&c<123)){
    	/* Remove case and reference alphabet to zero origin */
    	c=(c&31)-1;
    	/* shift letters as used */
      c2=c1;
      c1=c;
      /* Keep a total count */
      t++;
      /* Skip contact counts if first 2 letters not read */
      if(t<2) continue;
      /* sum trigrams */
      cc[c2][c1]++;
    }
  }
  /* Save file. */
  for(x=0;x<26;x++)
		for(y=0;y<26;y++)
			fprintf(fo,"%9ld %c%c\n",cc[x][y],x+65,y+65);
	fclose(fo);
	fclose(fi);
	return(0);
}

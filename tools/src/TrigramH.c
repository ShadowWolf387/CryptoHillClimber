/********************************************************************
* TrigramH.c
* A contact frequency counter and analysis assistant.
* Generates contact frequency data and saves to a file.
********************************************************************/
#include <stdio.h>

int main(int argc, char *argv[]){
	FILE *fi,*fo;
  /* Misc. junk variables and loop counters */
  int c, x, y, z;
  /* letter work variables */
  int c1, c2, c3;
  /* contact arrays */
  long t, cc[26][26][26];

  /* Splash message */
	printf("\nTrigram Frequency Counter\n");
	printf("Copyright 2019 ShadowWolf387\n\n");
  /* Display usage if not correct number of arguments */
	if(argc<3||argc>3){
		printf("Usage: trigram infile outfile\n\n");
		printf("infile  = input path and file name\n");
		printf("outfile = output path and file name\n\n");
		printf("Makes a trigram frequency count file.\n");
		printf("Special output for Hill climber\n");
		return(0);
	}
  /* Open files. Exit gracefully on error */
	if((fi=fopen(argv[1],"rb"))==NULL){
		printf("Can't open input file '%s'\n",argv[1]);
		return(0);
	}
	if((fo=fopen(argv[2],"wt"))==NULL){
		printf("Can't open output file '%s'\n",argv[2]);
		fclose(fi);
		return(0);
  }
  /* Initialize arrays and variables as needed */
  for(x=0;x<26;x++){
  	for(y=0;y<26;y++){
    	for(z=0;z<26;z++)cc[x][y][z]=0;
    }
  }
  /* Read in and do counts */
  c3=c2=c1=0;
  t=0;
	while((c=getc(fi))!=EOF){
		/* Count only letters */
		if((c>64&&c<91)||(c>96&&c<123)){
    	/* Remove case and reference alphabet to zero origin */
    	c=(c&31)-1;
    	/* shift letters as used */
      c3=c2;
      c2=c1;
      c1=c;
      /* Keep a total count */
      t++;
      /* Skip contact counts if first 3 letters not read */
      if(t<3) continue;
      /* sum trigrams */
      cc[c3][c2][c1]++;
    }
  }
  /* Save file. */
  for(x=0;x<26;x++)for(y=0;y<26;y++)for(z=0;z<26;z++)
		fprintf(fo,"%9ld %c%c%c\n",cc[x][y][z],x+65,y+65,z+65);
	fclose(fo);
	fclose(fi);
	return(0);
}

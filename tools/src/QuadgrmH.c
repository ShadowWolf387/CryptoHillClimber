/********************************************************************
* QuadgramH.c
* A quadgram frequency counter and analysis assistant.
* Generates quadgram frequency data and saves to a file.
********************************************************************/
#include <stdio.h>

int main(int argc, char *argv[]){
	FILE *fi,*fo;
  /* Misc. junk variables and loop counters */
  int c, w, x, y, z;
  /* letter work variables */
  int c1, c2, c3, c4;
  /* contact arrays */
  long t, cc[26][26][26][26];

  /* Splash message */
	printf("\nQuadgram Frequency Counter\n");
	printf("Copyright 2019 ShadowWolf387\n\n");
  /* Display usage if not correct number of arguments */
	if(argc<3||argc>3){
		printf("Usage: quadgram infile outfile\n\n");
		printf("infile  = input path and file name\n");
		printf("outfile = output path and file name\n\n");
		printf("Makes a quadgram frequency count file.\n");
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
  for(w=0;w<26;w++)
		for(x=0;x<26;x++)
  		for(y=0;y<26;y++)
    		for(z=0;z<26;z++)cc[w][x][y][z]=0;
	/* Read in and do counts */
  c4=c3=c2=c1=0;
  t=0;
	while((c=getc(fi))!=EOF){
		/* Count only letters */
		if((c>64&&c<91)||(c>96&&c<123)){
    	/* Remove case and reference alphabet to zero origin */
    	c=(c&31)-1;
    	/* shift letters as used */
      c4=c3;
			c3=c2;
      c2=c1;
      c1=c;
      /* Keep a total count */
      t++;
      /* Skip contact counts if first 3 letters not read */
      if(t<3) continue;
      /* sum trigrams */
      cc[c4][c3][c2][c1]++;
    }
  }
  /* Save file. */
  for(w=0;w<26;w++)for(x=0;x<26;x++)for(y=0;y<26;y++)for(z=0;z<26;z++)
		fprintf(fo,"%9ld %c%c%c%c\n",cc[w][x][y][z],w+65,x+65,y+65,z+65);
	fclose(fo);
	fclose(fi);
	return(0);
}

#include <stdio.h>
#include <stdlib.h>


void print_prefs(unsigned int * suitor_pref, unsigned int * reviewer_pref, unsigned int S, unsigned int R, unsigned int SK, unsigned int RK){
  int i, j;
  printf("\nsuitors:");
  for(i = 0; i < S; ++i){
     printf("\n %i",i);
    for(j = 0; j < SK; ++j){
      if(j % 6 == 0) 
	printf("\n");
      printf("\t %u :-> %u", j, suitor_pref[i*SK+j] );
    }
  }
  
  printf("\n reviewers:");
  for(i = 0; i < R; ++i){
     printf("\n %i",i);
    for(j = 0; j < RK; ++j){
      if((j % 6) == 0) 
	printf("\n");
      printf("\t %u :-> %u", j, reviewer_pref[i*RK+j] );
    }
  }
  printf("\n");
}


void getInput(const char* fname, unsigned int * suitor_pref, unsigned int * reviewer_pref, unsigned int S, unsigned int R, unsigned int SK, unsigned int RK){
  FILE *fp = fopen(fname,"r");
  //  printf("get input \n");
  if(fp == NULL){
    //    printf("%s\n",fname);
    exit(0);
  }
  else {
    int i = 0;
    unsigned int * ary;
    unsigned int dat;
    char space[10];
    ary = suitor_pref;
    //    printf("suitor:\n");
    while( fscanf(fp,"%x",&dat) != EOF ){ //,space)
     if(dat == -1){
       //       printf("\nreviewer:\n");
      i = 0;
      ary = reviewer_pref;
     } else {
       //    printf("%u \t",dat);
       ary[i] = dat;
       ++i;
       }
    }
    //    printf("\n");
  }
  fclose(fp);

  //  print_prefs(suitor_pref, reviewer_pref, S,R,SK,RK);
} 

void output_binary_string(unsigned int n){
  int c, k;
 
  for (c = 0; c < 32; c++)
  {
    k = n >> c;
 
    if (k & 1)
      printf("[1]");
    else
      printf("[0]");
  
    if(c != 31 && ((c+1) % 15 !=0) )
      printf(" ");
  
    if( (c+1) % 15 == 0)
      printf("\n                   ");
  
  } 
}

void output(unsigned int * matches_, unsigned int S){
  unsigned int * matches = matches_;
  int i;
  //  printf("\n..............\n");
  for(i = 0; i < S; ++i){
    printf("Output for Alice: (");
    output_binary_string(matches[i]);
    printf(")\n");
    //    printf("%i => %u\t",i, matches[i]);

  }
  //  printf("\n");
}


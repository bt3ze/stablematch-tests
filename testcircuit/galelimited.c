// global variables needed for the stable matching
#define NUM_SUITORS 100 // number of suitors and reviewers
#define NUM_REVIEWERS 100
#define NIL NUM_REVIEWERS // MUST be chosen to be the greater of NUM_SUITORS and NUM_REVIEWERS

// number of potential matches we permit each player to rank of the opposite party before declaring they would rather remain unmatched
#define K_SUITORS 60
#define K_REVIEWERS 3

//#define __CPROG__
#define __PCFPROG__

#ifdef __CPROG__
#include "ext-input.c"
#endif
#ifdef __PCFPROG__
#include "pcfmethods.h"
//#include "pcf-input.c"
#endif
// #include "cmpswaprounds.c"
// #include "sort-iterative.c"


//table of matches. matches[suitor#] = reviewer#
unsigned int matches[NUM_SUITORS];
unsigned int matches_r[NUM_REVIEWERS]; // note: matches_r[x] = NIL if x is not matched

// the following two must be global variables because in PCF V1, all passed pointers must be global
unsigned int suitors[NUM_SUITORS];
unsigned int reviewers[NUM_REVIEWERS];

// each suitor keeps track of how many reviewers he has proposed to. No suitor may propose to more than K.
unsigned int suitor_round[NUM_SUITORS];

/*
if suitor_pref[i][k] = m,
m is the reviewer number of suitor i's k'th preferred reviewer (by canonical ordering)
same for reviewer_pref
 */
unsigned int suitor_pref[NUM_SUITORS*K_SUITORS];
unsigned int reviewer_pref[NUM_REVIEWERS*K_REVIEWERS];


#ifdef __PCFPROG__
/**
I/O Utilities
*/
void secure_input(unsigned int * suitor_pref_, unsigned int * reviewer_pref_){

  unsigned int * suitor_pref = suitor_pref_;
  unsigned int * reviewer_pref = reviewer_pref_;

  unsigned int i, j;

  /*
    update these for alice and bob inputs that expect to 0xfff
   */

  for(i = 0; i < NUM_REVIEWERS; i++){
    for(j = 0; j < K_SUITORS; j++){ // get inputs
      //   output_bob(j);
      suitor_pref[i*K_SUITORS+j] = alice((i*K_SUITORS+j)*12) & 0xfff; //0xf;
    }
  }

  for(i = 0; i < NUM_REVIEWERS; i++){
    for(j = 0; j < K_REVIEWERS; j++){ // get inputs
      reviewer_pref[i*K_REVIEWERS+j] = bob((i*K_REVIEWERS+j)*12) & 0xfff; //0xf;
     //      reviewer_pref[i*N+j] = bob((i*N+j)*16) &  (N-1); //0xf;
    }
  }

}


void output(unsigned int * matches_ ){
  unsigned int * matches = matches_;
  unsigned int i;
  for(i = 0; i < NUM_SUITORS; ++i){
    output_alice(matches[i]);
  }
}
#endif

/**
CIRCUIT
 */

/*
First, a note about the "limited" matching circuit.
In the current version, we limit the suitors and reviewers to declare their top K preferred reviewers or top K reviewers, respectively.
 */

void setup(unsigned int * match, unsigned int * match_r, unsigned int * suitor_round) { // unsigned int * reviewer_count,
  unsigned int i;
  for(i =0; i < NUM_SUITORS; i++){
    match[i] = NIL; // convention
    suitor_round[i]=0;
  } 
  for(i=0; i < NUM_REVIEWERS; i++){
    match_r[i]=NIL;
  }
}

void match( unsigned int * match, unsigned int * match_r, unsigned int * suitors, unsigned int * reviewers, unsigned int * suitorpref, unsigned int * reviewerpref,unsigned int * suitor_round) { 
//, unsigned int * reviewer_counts){


  // j, and k will be used as counters
  // j will be used to loop through all the indices in an array so as not to reveal with index we're looking up. this is a requirement for secure evaluation
  // k will track the total number of times the suitors have proposed to the reviewers
  unsigned int j,k,i; 
  unsigned int s,r,sr,rc; // suitor#, reviewer#, suitor round #, reviewer count

  // mr is the value of some index in the match_reverse lookup table.
  // match-reverse index
  unsigned int mr,mr_index;
  
  // suitor-preference-index
  // reviewer-preference index
  // both used to look up values in suitor/reviewer preference arrays
  unsigned int sp_index, rp_index;
  
  // rps is the reviewer preference of the currently proposing suitor
  // rp_mr is the reviewer preference of match-reverse suitor (the one who currently hold's r's hand)
  unsigned int rps, rp_mr;
  
  // start with arbitrarily designated suitor #0 (computation NOT affected by this choice)
  s = 0;

  /* proceed for a worse case on number of suitor proposal rounds
     N*K (#suitors * #reviewers allowed per each) is a rough upperboud because it would require all suitors to propose to all of their ranked reviewers
  */
  for(k = 0; k < NUM_SUITORS*K_SUITORS; k++){ 

    //  output_bob(0); // debug output lines


    // establish current suitor round
    // and find next reviewer

    // find the number of times that a suitor has proposed and store in suitor round
    for(j = 0; j < NUM_SUITORS; j++){
      if(j == s) {
	sr = suitor_round[j];
	// suitor_round[j]++; would like to uncomment this line and remove redundancy below for efficiency
      } 
    }

    //   output_bob(1);  
      
    // suitor_pref contains ids of reviewers sorted by suitor and then by suitor's preference
    // look up the sr'th preference of current suitor so that he may propose
    sp_index = s*K_SUITORS+sr; 
    for(j = 0; j < NUM_SUITORS*K_SUITORS; j++){
      if(j == sp_index)
	r = suitor_pref[j]; // r = suitor_pref[s*N+sr]
    } // r is now the id of the next suitor to whom s will propose

    //    output_bob(2);
    
    // increment the tally of times suitor s has proposed
    for(j = 0; j < NUM_SUITORS; j++){
      if(j == s)
	suitor_round[j]++;
    } //suitor_round[s]++
    
    //        output_bob(3);
    
    // mr (read: match-reverse) will hold the suitor ID of whoever is currently engaged to reviewer r
    mr = NIL;
    for(j=0;j < NUM_REVIEWERS; j++){
      if(j == r)
	mr = match_r[j];
    } // mr = match_r[r]
  // note mr (match reverse [lookup]) may still be NIL if r is not matched
    
    //   output_bob(5);

    // retrieve preferences for suitor candidates::

    // try to find "s" in r's listed preferences
    // if he exists, use his index as his preference rank
    rps = NIL;
    for(j = 0; j < NUM_REVIEWERS; j++){
      for(i = 0; i < K_REVIEWERS; i++) {
	rp_index = reviewer_pref[j*K_REVIEWERS+i];
	if( rp_index == s && j == r ){
	    rps = i;
	}
      }
    }
    // rps still = NIL if reviewer does not want him at all

    rp_mr = NIL;
    // go back and find suitor denoted by mr in r's preferences
    // his index is his preference rank
    for(j = 0; j<NUM_REVIEWERS;j++){
      for(i = 0; i < K_REVIEWERS; i++) {
	rp_index = reviewer_pref[j*K_REVIEWERS+i];
	if( rp_index == mr && j == r ){
	    rp_mr = i;
	}
      }
    }
    // rp_mr still = NIL only if reviewer is not matched AND does not want s

    //   output_bob(7);   

    // propose and accept/deny:: two for loops (one for suitor-length array, one for reviewer-lenght array
    //
    // in general:
    //   if mr == NIL, reviewer is unmatched and may be matched as long as 
    //      rps != NIL (indicating r would actually like to be matched with this guy)
    //   if mr != NIL, reviewer must prefer proposing suitor to her current one
    //      so check that rps < rp_mr (remember low numbers -> higher preference)
    //      this means we must also kick out the previously matched suitor 
    //
    //   note that this implementation is specific to the rule of only one suitor per reviewer, since the only one held by 'r' will be her least preferred (and we don't have to look him up)
         
    // assign reviewers to suitors
    for(j = 0; j < NUM_SUITORS; j++){ 
      
      // if reviewer wants this suitor and currently unmatched, assign her to him:
      if(rps != NIL && mr == NIL && j == s){
	match[j] = r; // match[s] = r
      }
      // if reviewer prefers this suitor and currentl matched, null the other guy's match and assign her to him
      if(rps != NIL && mr != NIL && rp_mr > rps && j == mr){
	match[j] = NIL; // match[match_r[r]] = NIL
      }
      if(rps != NIL && mr != NIL && rp_mr > rps && j == s){
	match[j] = r; // match[s] = r
      }
    }    

    // assign suitor to reviewer
    for(j = 0; j < NUM_REVIEWERS; j++) {
      // if reviewer wants this suitor and is currently unmatched, assign him to her
      if(rps != NIL && mr == NIL && j == r){
	match_r[j] = s; // match_r[r] = s
      }
      
      // if reviewer wants this suitor and prefers him to current, assign him to her
      if(rps != NIL && mr != NIL && rp_mr > rps && j == r) {
	match_r[j] = s; // march_r[r] = s
      }
    }


    //     output_bob(8);

    // go find the next suitor who does not have a match
    // note that if suitor_rounds[s] = K, s has exhausted all possibilities and now he's done.
    s = NIL;
    for(j = 0; j < NUM_SUITORS; j++){
      if(matches[j]== NIL &&  s == NIL && suitor_round[j] < K_SUITORS)
	s = j;
    }
    
    // output_bob(9);
    //    output_bob(s);
    //     output(match);

  }
  
}

#ifdef __PCFPROG__
void main(void){	
  secure_input(suitor_pref, reviewer_pref);    
  setup(matches, matches_r, suitor_round); // reviewer_counts
  match(matches, matches_r, suitors, reviewers, suitor_pref, reviewer_pref, suitor_round);//, reviewer_counts);
  output(matches);
}
#endif


#ifdef __CPROG__
  int main(int argc, char *argv[]){
  if(argc != 2){
  printf("no file specified");
  return 1;
}
  getInput(argv[1],suitor_pref, reviewer_pref, NUM_SUITORS, NUM_REVIEWERS, K_SUITORS, K_REVIEWERS);
  setup(matches, matches_r,suitor_round); // reviewer_counts, 
  match(matches, matches_r, suitors, reviewers, suitor_pref, reviewer_pref, suitor_round);//, reviewer_counts);
  output(matches, NUM_SUITORS);
}
#endif


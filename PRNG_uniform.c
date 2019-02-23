//
// Created by yrohanizadegan on 17/07/17.
//

#include <stdlib.h>
#include <stdio.h>
#include "UniPRNG.h"

/* This function uses the linear congruential generator and the Lagged-Fibonacci
 * generator (LFG) algorithms to produce an array of random numbers (U(0,1)) in the unit
 * interval [0,1] where the period of the prng is determined by values of
 * 's' and 'r' defined in the LFG algorithm. The reason to use LFG is for achieving
 * greater period of random number generation. The seed must be such that at least
 * one of the initialization values (indices 0 to r-1 in uni_rand array) is odd.*/

static long MULTIPR = 1103515245; //Multiplier in LCG
static long INC = 12345; //Increment in LCG
static long MODUL = 2147483648; //Modulus in LCG

double *PRNG_uniform(int num_of_pts, int s, int r, int seed) {
    double *random_num;
    int i;
    long *uni_rand, tmp;

    if (s > r) {
        fprintf(stderr, "s must be less than %d (0<s<r)\n", r);
        exit(1);
    } // Error raised if an 's' value greater than 'r' is passed to the function
    if (num_of_pts < r) {
        fprintf(stderr, "The size of the sample cannot be less than %d\n", r);
        exit(1);
    }// Error raised if value of 'r' is less than the sample size

    if ((random_num = (double *) malloc(num_of_pts*sizeof(double))) == NULL) {
        fprintf(stderr,"malloc failed\n");
        exit(1);
    } // Initialize the returning array as a double
    if ((uni_rand = (long *) malloc(num_of_pts*sizeof(long))) == NULL) {
        fprintf(stderr,"malloc failed\n");
        exit(1);
    } // Initialize uni_rand to generate integer (>0) random numbers

    tmp = seed;
    for (i=0; i<r; i++) {
        uni_rand[i] = tmp;
        tmp = (MULTIPR * uni_rand[i] + INC) % MODUL;// Use LCG to initialize the sequence
    }

    for (i=r; i<num_of_pts; i++) {
        uni_rand[i] = (uni_rand[i-r] + uni_rand[i-s]) % MODUL;
    } // Calculate the rest of the sequence using the LFG algorithm

    for (i=0; i<num_of_pts; i++) {
        random_num [i] = uni_rand[i] / (double)MODUL; //Convert the generated integer sequence to U(0,1)
    }
    free(uni_rand);
    return random_num;
}

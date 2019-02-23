/* This program uses the C pseudo random number generator (PRNG), rand(),
 * which is a linear congruential generator (LCG) and produces almost
 * uniformly distributed random numbers in [0,1]. The sample mean is
 * calculated for a number of batches of these random numbers to be
 * used for comparing the sample stats with the real uniform distribution.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "UniPRNG.h"

int main() {
    double *x, *inv, *hist_vec; // Declaration of the sample, intervals (histogram bins) and frequency arrays.
    const int BATCH_NUM=1000, NUM_RAND=1000000; // Initialize # of batches, random #s and histogram bins.
    const double INV_LEN=0.01, START_VAL=0.0, STOP_VAL=1.0; // Initialize the interval length, start and stop points for the histogram.
    int i, j;
    int num_invs; // The number of intervals (bins) that the histogram has. It is calculated from stat, stop and interval length
    FILE *f_out1, *f_out2, *f_out3;

    /* Initialize three files to store the histogram data of the last sample and
     * the means and variances of the batches.*/
    f_out1 = fopen("histogram_coords", "w+");
    f_out2 = fopen("sample_mean", "w+");
    f_out3 = fopen("sample_variance", "w+");
    // Allocate memory to the random sample in form of an array.
    if ((x = (double *) malloc(NUM_RAND*sizeof(double))) == NULL) {
        fprintf(stderr,"malloc failed\n");
        exit(1);
    }
    /* Loop through batches and in each batch find the mean and the variance of the random sample.*/
    for (i=0; i<BATCH_NUM; i++) {
        x = PRNG_uniform(NUM_RAND, 24, 55, i); //Call uniform-prng with lagged-fibonacci algorithm with s=24, r=55 and seed
        fprintf(f_out2, "batch# %d mean: %f\n", i+1, sample_mean(x, NUM_RAND)); // print the means to a file.
        fprintf(f_out3, "batch# %d variance: %f\n", i+1, sample_variance(x, NUM_RAND)); // print the variances to a file
    }

    /* Call the histogram_generator to produce the data for plotting a histogram
     * for the last batch.*/
    histogram_f(x, INV_LEN, START_VAL, STOP_VAL, &inv, &hist_vec, NUM_RAND);

    /* Print the contents of intervals (bins) and the associated frequencies to histogram_coords file.*/
    num_invs = (int) trunc((STOP_VAL-START_VAL)/INV_LEN); // Cast the truncated number of intervals into int
    for (j=0; j<num_invs; j++) {
        fprintf(f_out1, "%f %f\n", *(inv+j), *(hist_vec+j));
    }
    fclose(f_out1);
    fclose(f_out2);
    fclose(f_out3);
    free(x);
    free(inv);
    free(hist_vec);
    return 0;
}
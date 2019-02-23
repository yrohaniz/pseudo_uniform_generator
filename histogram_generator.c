//
// Created by yrohanizadegan on 25/07/17.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "UniPRNG.h"

/* This function takes as its input the generated sample, the size of the
 * sample and the number of histogram intervals (bins) and changes two arrays
 * that are passed to it by reference; the intervals array and the frequency
 * array which is called hist_vec. It uses qsort from 'stdlib.h' to sort the
 * input sample in an ascending order and then populates 'hist_vec' by counting
 * the number of data points that fall into each interval.*/
void histogram_f(double *rand_vec, double inv_len, double start, double stop, double **inv, double **hist_vec, int size) {
    int i=0,j, count=0, hist_bins; // Initialize i and count
    double sum;

    hist_bins = (int) trunc((stop - start)/inv_len); // Truncate the value for the number of intervals (bins) and cast it into int
    if (hist_bins > size) {
        fprintf(stderr, "The number of histogram bins should not be greater than the sample size");
        exit(1);
    }// Error raised if the number of bins is greater than the sample size

    if ((*hist_vec = (double *) calloc(hist_bins,sizeof(double))) == NULL) {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }// Allocate and initialize the array that records the frequencies in each bin
    if ((*inv = (double *) calloc(hist_bins,sizeof(double))) == NULL) {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }// Allocate and initialize the array that records the mid-point of each bin

    // Use built-in sorting function to sort the sample in an ascending order
    qsort(rand_vec, (unsigned int) size, sizeof(double), compare);

    sum = start; // Initialize sum using the starting point
    for (j=0; j<hist_bins; j++) {
        (*inv)[j] = sum + inv_len/2.0; // Record the mid-point of each interval
        /* Count the number of points in each interval (bin) by making sure
         * that the values do not exceed the interval's highest value and
         * the sample has not been exhausted. The counted number is represented
         * by count.*/
        while (rand_vec[i] <= ((*inv)[j]+inv_len/2.0) && i != size) {
            count++;
            i++;
        }
        (*hist_vec)[j] = (count/((double) size))/inv_len; // Divide 'count' by sample size and normalize by length
        count = 0;
        sum += inv_len; // Go to next interval (bin)
    }
}
//
// Created by yrohanizadegan on 26/07/17.
//

#include "UniPRNG.h"

/* This function computes the variance of a random sample which is input as an array.*/
double sample_variance(double *sample, int n) {
    double curr_mean, sum=0.0;
    int i;

    curr_mean = sample_mean(sample, n);
    for(i=0; i<n; i++) {
        sum += (sample[i]-curr_mean)*(sample[i]-curr_mean)/(n-1);
    }
    return sum;
}
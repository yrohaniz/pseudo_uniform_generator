//
// Created by yrohanizadegan on 17/07/17.
//

#include "UniPRNG.h"

/* This function computes the mean of a random sample which is input as an array.*/
double sample_mean(double *sample, int n) {
    double sum=0.0;
    int i;

    for(i=0; i<n; i++) {
        sum += sample[i]/n;
    }
    return sum;
}

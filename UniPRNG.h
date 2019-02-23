//
// Created by yrohanizadegan on 17/07/17.
//

#ifndef PSEUDO_UNIFORM_GENERATOR_UNIPRNG_H
#define PSEUDO_UNIFORM_GENERATOR_UNIPRNG_H

double sample_mean(double *sample, int n);
double sample_variance(double *sample, int n);
double *PRNG_uniform(int num_of_pts, int s, int r, int seed);
void histogram_f(double *rand_vec, double inv_len, double start, double stop, double **inv, double **hist_vec, int size);
int compare( const void *a, const void *b);

#endif //PSEUDO_UNIFORM_GENERATOR_UNIPRNG_H

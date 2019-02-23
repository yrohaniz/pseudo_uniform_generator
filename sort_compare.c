//
// Created by yrohanizadegan on 26/07/17.
//

#include "UniPRNG.h"

/* This function is used by qsort for comparing elements of an input array
 * and determining their relation and returning an integer as the final
 * result.*/
int compare( const void *a, const void *b) {
    if ( *((double*) a) == *((double*) b) ) return 0;
    else if ( *((double*) a) < *((double*) b) ) return -1;
    else return 1;
}
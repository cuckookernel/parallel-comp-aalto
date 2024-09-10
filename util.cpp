//
// Created by teo on 17/07/24.
//


#include <cstring>


void init(float *d, int n) {
    for( int i = 0; i < n * n; ++i) {
        d[i] = float(i % 23113) ;
    }
}

void init_0(float *d, int n) {
    memset(d, 0, n*n);
}

float sum_mat(float const *d, int n) {
    float sum = 0;
    for( int i = 0; i < n * n; ++i) {
        sum += d[i];
    }
    return sum;
}

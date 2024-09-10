//
// Created by teo on 16/07/24.
//
#include <iostream>
#include <limits>
#include <chrono>

#include "util.h"

#define VALUE_TO_STRING(x) #x
#define ALGO_VER_STR #ALGO_VER
#define PRINT_VAR_VALUE(var) #var "=`" VALUE_TO_STRING(var) "`"

using namespace std;
using namespace chrono;

#pragma message PRINT_VAR_VALUE(ALGO_VER)

void ALGO_VER(float* r, const float* d, int n);

int main() {
    int n = 4000;
    cout <<  "\ncompiler: " << compiler_name() << " version: " << compiler_version()
        << " - C++ " << __cplusplus << endl;
    cout << "running: " << ALGO_VER_STR << endl;
    auto *r = new float[n * n];
    auto *d = new float[n * n];

    init(d, n);
    init_0(r, n);
    auto tic = high_resolution_clock::now();
    ALGO_VER(r, d, n);
    auto toc = high_resolution_clock::now();
    DurMillis elapsed = toc - tic;
    cout << "Elapsed: " << elapsed.count() / 1000.0 << " secs.\n" << endl;

    sum_mat(r, n);

    delete[] r;
    delete[] d;
    return 0;
}


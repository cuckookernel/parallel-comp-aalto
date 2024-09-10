//
// Created by teo on 17/07/24.
//

#ifndef UTIL_H
#define UTIL_H

#if defined(__GNUC__)
#if defined(__clang__)
#define COMPILER_NAME "Clang"
#else
#define COMPILER_NAME "GNUC"
#endif
#define COMPILER_VERSION __VERSION__
#elif defined(_MSC_VER)
#define COMPILER_NAME "MSVC"
    #define COMPILER_VERSION _MSC_FULL_VER
#else
    #error Please add your compiler here.
#endif


void init(float *d, int n);
void init_0(float *d, int n);
float sum_mat(float const *d, int n);

typedef std::chrono::duration<float, std::milli> DurMillis;

typedef std::chrono::duration<float, std::nano> DurNanos;

const char* compiler_name() {
    return COMPILER_NAME;
}

const char* compiler_version() {
    return COMPILER_VERSION;
}

#endif //UTIL_H

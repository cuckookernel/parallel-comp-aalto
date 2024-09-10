//
// Created by teo on 17/07/24.
//
#include <limits>
#include <algorithm>

void step_v1(float* r, const float* d, int n) {
    #pragma omp parallel for
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            float v = std::numeric_limits<float>::infinity();
            for (int k = 0; k < n; ++k) {
                asm("# inner loop starts");
                float x = d[n*i + k];
                float y = d[n*k + j];
                float z = x + y;
                v = std::min(v, z);
                asm("# inner loop ends");
            }
            r[n*i + j] = v;
        }
    }
}

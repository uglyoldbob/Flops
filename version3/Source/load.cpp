#include <stddef.h>

#include "Benchmark.h"
#include "128/f64v1_MulAdd_SSE2_c6u4_c4u6.h"

extern "C" double sse_load(int a) {
    Flops::f64v1_MulAdd_SSE2_c6u4_c4u6 bm;
    return bm.run_kernel(a);
}

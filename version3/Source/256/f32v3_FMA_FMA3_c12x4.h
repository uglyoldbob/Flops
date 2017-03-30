/* f32v3_FMA_FMA3_c12x4.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 03/27/2017
 * Last Modified    : 03/27/2017
 * 
 */

#ifndef _flops_f32v3_FMA_FMA3_c12x4_H
#define _flops_f32v3_FMA_FMA3_c12x4_H
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//  Dependencies
#include <immintrin.h>
#include "../Benchmark.h"
namespace Flops{
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
class f32v3_FMA_FMA3_c12x4 : public Benchmark{
public:
    f32v3_FMA_FMA3_c12x4()
        : Benchmark(48 * 2 * 8)
    {}
    virtual double run_kernel(size_t iterations) const override{
        const __m256 mul0 = _mm256_set1_ps(1.4142135623730950488f);
        const __m256 mul1 = _mm256_set1_ps(1.7320508075688772935f);

        __m256 r0 = _mm256_set1_ps(1.0f);
        __m256 r1 = _mm256_set1_ps(1.1f);
        __m256 r2 = _mm256_set1_ps(1.2f);
        __m256 r3 = _mm256_set1_ps(1.3f);
        __m256 r4 = _mm256_set1_ps(1.4f);
        __m256 r5 = _mm256_set1_ps(1.5f);
        __m256 r6 = _mm256_set1_ps(1.6f);
        __m256 r7 = _mm256_set1_ps(1.7f);
        __m256 r8 = _mm256_set1_ps(1.8f);
        __m256 r9 = _mm256_set1_ps(1.9f);
        __m256 rA = _mm256_set1_ps(2.0f);
        __m256 rB = _mm256_set1_ps(2.1f);
        do{
            r0 = _mm256_fmadd_ps(mul0, mul1, r0);
            r1 = _mm256_fmadd_ps(mul0, mul1, r1);
            r2 = _mm256_fmadd_ps(mul0, mul1, r2);
            r3 = _mm256_fmadd_ps(mul0, mul1, r3);
            r4 = _mm256_fmadd_ps(mul0, mul1, r4);
            r5 = _mm256_fmadd_ps(mul0, mul1, r5);
            r6 = _mm256_fmadd_ps(mul0, mul1, r6);
            r7 = _mm256_fmadd_ps(mul0, mul1, r7);
            r8 = _mm256_fmadd_ps(mul0, mul1, r8);
            r9 = _mm256_fmadd_ps(mul0, mul1, r9);
            rA = _mm256_fmadd_ps(mul0, mul1, rA);
            rB = _mm256_fmadd_ps(mul0, mul1, rB);

            r0 = _mm256_fnmadd_ps(mul0, mul1, r0);
            r1 = _mm256_fnmadd_ps(mul0, mul1, r1);
            r2 = _mm256_fnmadd_ps(mul0, mul1, r2);
            r3 = _mm256_fnmadd_ps(mul0, mul1, r3);
            r4 = _mm256_fnmadd_ps(mul0, mul1, r4);
            r5 = _mm256_fnmadd_ps(mul0, mul1, r5);
            r6 = _mm256_fnmadd_ps(mul0, mul1, r6);
            r7 = _mm256_fnmadd_ps(mul0, mul1, r7);
            r8 = _mm256_fnmadd_ps(mul0, mul1, r8);
            r9 = _mm256_fnmadd_ps(mul0, mul1, r9);
            rA = _mm256_fnmadd_ps(mul0, mul1, rA);
            rB = _mm256_fnmadd_ps(mul0, mul1, rB);

            r0 = _mm256_fmadd_ps(mul0, mul1, r0);
            r1 = _mm256_fmadd_ps(mul0, mul1, r1);
            r2 = _mm256_fmadd_ps(mul0, mul1, r2);
            r3 = _mm256_fmadd_ps(mul0, mul1, r3);
            r4 = _mm256_fmadd_ps(mul0, mul1, r4);
            r5 = _mm256_fmadd_ps(mul0, mul1, r5);
            r6 = _mm256_fmadd_ps(mul0, mul1, r6);
            r7 = _mm256_fmadd_ps(mul0, mul1, r7);
            r8 = _mm256_fmadd_ps(mul0, mul1, r8);
            r9 = _mm256_fmadd_ps(mul0, mul1, r9);
            rA = _mm256_fmadd_ps(mul0, mul1, rA);
            rB = _mm256_fmadd_ps(mul0, mul1, rB);

            r0 = _mm256_fnmadd_ps(mul0, mul1, r0);
            r1 = _mm256_fnmadd_ps(mul0, mul1, r1);
            r2 = _mm256_fnmadd_ps(mul0, mul1, r2);
            r3 = _mm256_fnmadd_ps(mul0, mul1, r3);
            r4 = _mm256_fnmadd_ps(mul0, mul1, r4);
            r5 = _mm256_fnmadd_ps(mul0, mul1, r5);
            r6 = _mm256_fnmadd_ps(mul0, mul1, r6);
            r7 = _mm256_fnmadd_ps(mul0, mul1, r7);
            r8 = _mm256_fnmadd_ps(mul0, mul1, r8);
            r9 = _mm256_fnmadd_ps(mul0, mul1, r9);
            rA = _mm256_fnmadd_ps(mul0, mul1, rA);
            rB = _mm256_fnmadd_ps(mul0, mul1, rB);
        }while (--iterations);

        r0 = _mm256_add_ps(r0, r6);
        r1 = _mm256_add_ps(r1, r7);
        r2 = _mm256_add_ps(r2, r8);
        r3 = _mm256_add_ps(r3, r9);
        r4 = _mm256_add_ps(r4, rA);
        r5 = _mm256_add_ps(r5, rB);

        r0 = _mm256_add_ps(r0, r3);
        r1 = _mm256_add_ps(r1, r4);
        r2 = _mm256_add_ps(r2, r5);

        r0 = _mm256_add_ps(r0, r1);
        r0 = _mm256_add_ps(r0, r2);

        __m128 x = _mm_add_ps(_mm256_castps256_ps128(r0), _mm256_extractf128_ps(r0, 1));
        x = _mm_add_ps(x, _mm_unpackhi_ps(x, x));
        x = _mm_add_ps(x, _mm_shuffle_ps(x, x, 1));
        return _mm_cvtss_f32(x);
    }
};
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
}
#endif

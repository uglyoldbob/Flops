/* f32v4_FMA_AVX512_c12x4.h
 * 
 * Author           : Alexander J. Yee
 * Date Created     : 06/04/2017
 * Last Modified    : 06/04/2017
 * 
 */

#ifndef _flops_f32v4_FMA_AVX512_c12x4_H
#define _flops_f32v4_FMA_AVX512_c12x4_H
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
class f32v4_FMA_AVX512_c12x4 : public Benchmark{
public:
    f32v4_FMA_AVX512_c12x4()
        : Benchmark(48 * 2 * 16)
    {}
    virtual double run_kernel(size_t iterations) const override{
        const __m512 mul0 = _mm512_set1_ps(1.4142135623730950488f);
        const __m512 mul1 = _mm512_set1_ps(1.7320508075688772935f);

        __m512 r0 = _mm512_set1_ps(1.0f);
        __m512 r1 = _mm512_set1_ps(1.1f);
        __m512 r2 = _mm512_set1_ps(1.2f);
        __m512 r3 = _mm512_set1_ps(1.3f);
        __m512 r4 = _mm512_set1_ps(1.4f);
        __m512 r5 = _mm512_set1_ps(1.5f);
        __m512 r6 = _mm512_set1_ps(1.6f);
        __m512 r7 = _mm512_set1_ps(1.7f);
        __m512 r8 = _mm512_set1_ps(1.8f);
        __m512 r9 = _mm512_set1_ps(1.9f);
        __m512 rA = _mm512_set1_ps(2.0f);
        __m512 rB = _mm512_set1_ps(2.1f);
        do{
            r0 = _mm512_fmadd_ps(mul0, mul1, r0);
            r1 = _mm512_fmadd_ps(mul0, mul1, r1);
            r2 = _mm512_fmadd_ps(mul0, mul1, r2);
            r3 = _mm512_fmadd_ps(mul0, mul1, r3);
            r4 = _mm512_fmadd_ps(mul0, mul1, r4);
            r5 = _mm512_fmadd_ps(mul0, mul1, r5);
            r6 = _mm512_fmadd_ps(mul0, mul1, r6);
            r7 = _mm512_fmadd_ps(mul0, mul1, r7);
            r8 = _mm512_fmadd_ps(mul0, mul1, r8);
            r9 = _mm512_fmadd_ps(mul0, mul1, r9);
            rA = _mm512_fmadd_ps(mul0, mul1, rA);
            rB = _mm512_fmadd_ps(mul0, mul1, rB);

            r0 = _mm512_fnmadd_ps(mul0, mul1, r0);
            r1 = _mm512_fnmadd_ps(mul0, mul1, r1);
            r2 = _mm512_fnmadd_ps(mul0, mul1, r2);
            r3 = _mm512_fnmadd_ps(mul0, mul1, r3);
            r4 = _mm512_fnmadd_ps(mul0, mul1, r4);
            r5 = _mm512_fnmadd_ps(mul0, mul1, r5);
            r6 = _mm512_fnmadd_ps(mul0, mul1, r6);
            r7 = _mm512_fnmadd_ps(mul0, mul1, r7);
            r8 = _mm512_fnmadd_ps(mul0, mul1, r8);
            r9 = _mm512_fnmadd_ps(mul0, mul1, r9);
            rA = _mm512_fnmadd_ps(mul0, mul1, rA);
            rB = _mm512_fnmadd_ps(mul0, mul1, rB);

            r0 = _mm512_fmadd_ps(mul0, mul1, r0);
            r1 = _mm512_fmadd_ps(mul0, mul1, r1);
            r2 = _mm512_fmadd_ps(mul0, mul1, r2);
            r3 = _mm512_fmadd_ps(mul0, mul1, r3);
            r4 = _mm512_fmadd_ps(mul0, mul1, r4);
            r5 = _mm512_fmadd_ps(mul0, mul1, r5);
            r6 = _mm512_fmadd_ps(mul0, mul1, r6);
            r7 = _mm512_fmadd_ps(mul0, mul1, r7);
            r8 = _mm512_fmadd_ps(mul0, mul1, r8);
            r9 = _mm512_fmadd_ps(mul0, mul1, r9);
            rA = _mm512_fmadd_ps(mul0, mul1, rA);
            rB = _mm512_fmadd_ps(mul0, mul1, rB);

            r0 = _mm512_fnmadd_ps(mul0, mul1, r0);
            r1 = _mm512_fnmadd_ps(mul0, mul1, r1);
            r2 = _mm512_fnmadd_ps(mul0, mul1, r2);
            r3 = _mm512_fnmadd_ps(mul0, mul1, r3);
            r4 = _mm512_fnmadd_ps(mul0, mul1, r4);
            r5 = _mm512_fnmadd_ps(mul0, mul1, r5);
            r6 = _mm512_fnmadd_ps(mul0, mul1, r6);
            r7 = _mm512_fnmadd_ps(mul0, mul1, r7);
            r8 = _mm512_fnmadd_ps(mul0, mul1, r8);
            r9 = _mm512_fnmadd_ps(mul0, mul1, r9);
            rA = _mm512_fnmadd_ps(mul0, mul1, rA);
            rB = _mm512_fnmadd_ps(mul0, mul1, rB);
        }while (--iterations);

        r0 = _mm512_add_ps(r0, r6);
        r1 = _mm512_add_ps(r1, r7);
        r2 = _mm512_add_ps(r2, r8);
        r3 = _mm512_add_ps(r3, r9);
        r4 = _mm512_add_ps(r4, rA);
        r5 = _mm512_add_ps(r5, rB);

        r0 = _mm512_add_ps(r0, r3);
        r1 = _mm512_add_ps(r1, r4);
        r2 = _mm512_add_ps(r2, r5);

        r0 = _mm512_add_ps(r0, r1);
        r0 = _mm512_add_ps(r0, r2);

        __m256 y = _mm256_add_ps(
            _mm512_castps512_ps256(r0),
            _mm256_castsi256_ps(_mm512_extracti64x4_epi64(_mm512_castps_si512(r0), 1))
        );
        __m128 x = _mm_add_ps(_mm256_castps256_ps128(y), _mm256_extractf128_ps(y, 1));
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
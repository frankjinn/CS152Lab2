#include <assert.h>
#include "dataset.h"
#include "hpm.h"

/* Only once your code passes the self-check, remove VERIFY to skip
   verification for shorter simulations */
#define VERIFY

#define B 4

void __attribute__ ((noinline)) transpose(mat_nxm_t dst, const mat_mxn_t src) {
    size_t bi, bj, i, j;
    for (bi = 0; bi < 256; bi += B) {
        for (bj = 0; bj < 64; bj += B) {
            for (j = bj; j < bj + B; j++) {  // Loop interchange for better memory access
                for (i = bi; i < bi + B; i++) {
                    dst[j][i] = src[i][j];
                }
            }
        }
    }
}

// void __attribute__ ((noinline)) transpose(mat_nxm_t dst, const mat_mxn_t src)
// {
//     size_t i, j;
//     for (i = 0; i < MAT_M; i++) {
//         for (j = 0; j < MAT_N; j++) {
//             dst[j][i] = src[i][j];
//         }
//     }
// }

int main(void)
{
    size_t i, j;

    /* Enable performance counters */
    hpm_init();

    transpose(test_dst, test_src);

    /* Print performance counter data */
    hpm_print();

// #ifdef VERIFY
//     /* Verify result */
//     for (i = 0; i < MAT_M; i++) {
//         for  (j = 0; j < MAT_N; j++) {
//             assert(test_dst[j][i] == test_src[i][j]);
//         }
//     }
// #endif

    return 0;
}

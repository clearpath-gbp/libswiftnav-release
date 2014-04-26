/*****************************************************************************
  Copyright (c) 2010, Intel Corp.
  All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice,
      this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of Intel Corporation nor the names of its contributors
      may be used to endorse or promote products derived from this software
      without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
  THE POSSIBILITY OF SUCH DAMAGE.
******************************************************************************
* Contents: Native middle-level C interface to LAPACK function sgbrfs
* Author: Intel Corporation
* Generated October, 2010
*****************************************************************************/

#include "lapacke.h"
#include "lapacke_utils.h"

lapack_int LAPACKE_sgbrfs_work( int matrix_order, char trans, lapack_int n,
                                lapack_int kl, lapack_int ku, lapack_int nrhs,
                                const float* ab, lapack_int ldab,
                                const float* afb, lapack_int ldafb,
                                const lapack_int* ipiv, const float* b,
                                lapack_int ldb, float* x, lapack_int ldx,
                                float* ferr, float* berr, float* work,
                                lapack_int* iwork )
{
    lapack_int info = 0;
    if( matrix_order == LAPACK_COL_MAJOR ) {
        /* Call LAPACK function and adjust info */
        LAPACK_sgbrfs( &trans, &n, &kl, &ku, &nrhs, ab, &ldab, afb, &ldafb,
                       ipiv, b, &ldb, x, &ldx, ferr, berr, work, iwork, &info );
        if( info < 0 ) {
            info = info - 1;
        }
    } else if( matrix_order == LAPACK_ROW_MAJOR ) {
        lapack_int ldab_t = MAX(1,kl+ku+1);
        lapack_int ldafb_t = MAX(1,2*kl+ku+1);
        lapack_int ldb_t = MAX(1,n);
        lapack_int ldx_t = MAX(1,n);
        float* ab_t = NULL;
        float* afb_t = NULL;
        float* b_t = NULL;
        float* x_t = NULL;
        /* Check leading dimension(s) */
        if( ldab < n ) {
            info = -8;
            LAPACKE_xerbla( "LAPACKE_sgbrfs_work", info );
            return info;
        }
        if( ldafb < n ) {
            info = -10;
            LAPACKE_xerbla( "LAPACKE_sgbrfs_work", info );
            return info;
        }
        if( ldb < nrhs ) {
            info = -13;
            LAPACKE_xerbla( "LAPACKE_sgbrfs_work", info );
            return info;
        }
        if( ldx < nrhs ) {
            info = -15;
            LAPACKE_xerbla( "LAPACKE_sgbrfs_work", info );
            return info;
        }
        /* Allocate memory for temporary array(s) */
        ab_t = (float*)LAPACKE_malloc( sizeof(float) * ldab_t * MAX(1,n) );
        if( ab_t == NULL ) {
            info = LAPACK_TRANSPOSE_MEMORY_ERROR;
            goto exit_level_0;
        }
        afb_t = (float*)LAPACKE_malloc( sizeof(float) * ldafb_t * MAX(1,n) );
        if( afb_t == NULL ) {
            info = LAPACK_TRANSPOSE_MEMORY_ERROR;
            goto exit_level_1;
        }
        b_t = (float*)LAPACKE_malloc( sizeof(float) * ldb_t * MAX(1,nrhs) );
        if( b_t == NULL ) {
            info = LAPACK_TRANSPOSE_MEMORY_ERROR;
            goto exit_level_2;
        }
        x_t = (float*)LAPACKE_malloc( sizeof(float) * ldx_t * MAX(1,nrhs) );
        if( x_t == NULL ) {
            info = LAPACK_TRANSPOSE_MEMORY_ERROR;
            goto exit_level_3;
        }
        /* Transpose input matrices */
        LAPACKE_sgb_trans( matrix_order, n, n, kl, ku, ab, ldab, ab_t, ldab_t );
        LAPACKE_sgb_trans( matrix_order, n, n, kl, kl+ku, afb, ldafb, afb_t,
                           ldafb_t );
        LAPACKE_sge_trans( matrix_order, n, nrhs, b, ldb, b_t, ldb_t );
        LAPACKE_sge_trans( matrix_order, n, nrhs, x, ldx, x_t, ldx_t );
        /* Call LAPACK function and adjust info */
        LAPACK_sgbrfs( &trans, &n, &kl, &ku, &nrhs, ab_t, &ldab_t, afb_t,
                       &ldafb_t, ipiv, b_t, &ldb_t, x_t, &ldx_t, ferr, berr,
                       work, iwork, &info );
        if( info < 0 ) {
            info = info - 1;
        }
        /* Transpose output matrices */
        LAPACKE_sge_trans( LAPACK_COL_MAJOR, n, nrhs, x_t, ldx_t, x, ldx );
        /* Release memory and exit */
        LAPACKE_free( x_t );
exit_level_3:
        LAPACKE_free( b_t );
exit_level_2:
        LAPACKE_free( afb_t );
exit_level_1:
        LAPACKE_free( ab_t );
exit_level_0:
        if( info == LAPACK_TRANSPOSE_MEMORY_ERROR ) {
            LAPACKE_xerbla( "LAPACKE_sgbrfs_work", info );
        }
    } else {
        info = -1;
        LAPACKE_xerbla( "LAPACKE_sgbrfs_work", info );
    }
    return info;
}

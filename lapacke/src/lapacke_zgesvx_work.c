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
* Contents: Native middle-level C interface to LAPACK function zgesvx
* Author: Intel Corporation
* Generated October, 2010
*****************************************************************************/

#include "lapacke.h"
#include "lapacke_utils.h"

lapack_int LAPACKE_zgesvx_work( int matrix_order, char fact, char trans,
                                lapack_int n, lapack_int nrhs,
                                lapack_complex_double* a, lapack_int lda,
                                lapack_complex_double* af, lapack_int ldaf,
                                lapack_int* ipiv, char* equed, double* r,
                                double* c, lapack_complex_double* b,
                                lapack_int ldb, lapack_complex_double* x,
                                lapack_int ldx, double* rcond, double* ferr,
                                double* berr, lapack_complex_double* work,
                                double* rwork )
{
    lapack_int info = 0;
    if( matrix_order == LAPACK_COL_MAJOR ) {
        /* Call LAPACK function and adjust info */
        LAPACK_zgesvx( &fact, &trans, &n, &nrhs, a, &lda, af, &ldaf, ipiv,
                       equed, r, c, b, &ldb, x, &ldx, rcond, ferr, berr, work,
                       rwork, &info );
        if( info < 0 ) {
            info = info - 1;
        }
    } else if( matrix_order == LAPACK_ROW_MAJOR ) {
        lapack_int lda_t = MAX(1,n);
        lapack_int ldaf_t = MAX(1,n);
        lapack_int ldb_t = MAX(1,n);
        lapack_int ldx_t = MAX(1,n);
        lapack_complex_double* a_t = NULL;
        lapack_complex_double* af_t = NULL;
        lapack_complex_double* b_t = NULL;
        lapack_complex_double* x_t = NULL;
        /* Check leading dimension(s) */
        if( lda < n ) {
            info = -7;
            LAPACKE_xerbla( "LAPACKE_zgesvx_work", info );
            return info;
        }
        if( ldaf < n ) {
            info = -9;
            LAPACKE_xerbla( "LAPACKE_zgesvx_work", info );
            return info;
        }
        if( ldb < nrhs ) {
            info = -15;
            LAPACKE_xerbla( "LAPACKE_zgesvx_work", info );
            return info;
        }
        if( ldx < nrhs ) {
            info = -17;
            LAPACKE_xerbla( "LAPACKE_zgesvx_work", info );
            return info;
        }
        /* Allocate memory for temporary array(s) */
        a_t = (lapack_complex_double*)
            LAPACKE_malloc( sizeof(lapack_complex_double) * lda_t * MAX(1,n) );
        if( a_t == NULL ) {
            info = LAPACK_TRANSPOSE_MEMORY_ERROR;
            goto exit_level_0;
        }
        af_t = (lapack_complex_double*)
            LAPACKE_malloc( sizeof(lapack_complex_double) * ldaf_t * MAX(1,n) );
        if( af_t == NULL ) {
            info = LAPACK_TRANSPOSE_MEMORY_ERROR;
            goto exit_level_1;
        }
        b_t = (lapack_complex_double*)
            LAPACKE_malloc( sizeof(lapack_complex_double) *
                            ldb_t * MAX(1,nrhs) );
        if( b_t == NULL ) {
            info = LAPACK_TRANSPOSE_MEMORY_ERROR;
            goto exit_level_2;
        }
        x_t = (lapack_complex_double*)
            LAPACKE_malloc( sizeof(lapack_complex_double) *
                            ldx_t * MAX(1,nrhs) );
        if( x_t == NULL ) {
            info = LAPACK_TRANSPOSE_MEMORY_ERROR;
            goto exit_level_3;
        }
        /* Transpose input matrices */
        LAPACKE_zge_trans( matrix_order, n, n, a, lda, a_t, lda_t );
        if( LAPACKE_lsame( fact, 'f' ) ) {
            LAPACKE_zge_trans( matrix_order, n, n, af, ldaf, af_t, ldaf_t );
        }
        LAPACKE_zge_trans( matrix_order, n, nrhs, b, ldb, b_t, ldb_t );
        /* Call LAPACK function and adjust info */
        LAPACK_zgesvx( &fact, &trans, &n, &nrhs, a_t, &lda_t, af_t, &ldaf_t,
                       ipiv, equed, r, c, b_t, &ldb_t, x_t, &ldx_t, rcond, ferr,
                       berr, work, rwork, &info );
        if( info < 0 ) {
            info = info - 1;
        }
        /* Transpose output matrices */
        if( LAPACKE_lsame( fact, 'e' ) && ( LAPACKE_lsame( *equed, 'b' ) ||
            LAPACKE_lsame( *equed, 'c' ) || LAPACKE_lsame( *equed, 'r' ) ) ) {
            LAPACKE_zge_trans( LAPACK_COL_MAJOR, n, n, a_t, lda_t, a, lda );
        }
        if( LAPACKE_lsame( fact, 'e' ) || LAPACKE_lsame( fact, 'n' ) ) {
            LAPACKE_zge_trans( LAPACK_COL_MAJOR, n, n, af_t, ldaf_t, af, ldaf );
        }
        if( LAPACKE_lsame( fact, 'f' ) && ( LAPACKE_lsame( *equed, 'b' ) ||
            LAPACKE_lsame( *equed, 'c' ) || LAPACKE_lsame( *equed, 'r' ) ) ) {
            LAPACKE_zge_trans( LAPACK_COL_MAJOR, n, nrhs, b_t, ldb_t, b, ldb );
        }
        LAPACKE_zge_trans( LAPACK_COL_MAJOR, n, nrhs, x_t, ldx_t, x, ldx );
        /* Release memory and exit */
        LAPACKE_free( x_t );
exit_level_3:
        LAPACKE_free( b_t );
exit_level_2:
        LAPACKE_free( af_t );
exit_level_1:
        LAPACKE_free( a_t );
exit_level_0:
        if( info == LAPACK_TRANSPOSE_MEMORY_ERROR ) {
            LAPACKE_xerbla( "LAPACKE_zgesvx_work", info );
        }
    } else {
        info = -1;
        LAPACKE_xerbla( "LAPACKE_zgesvx_work", info );
    }
    return info;
}

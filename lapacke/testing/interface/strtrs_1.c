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
*****************************************************************************/
/*  Contents: test routine for C interface to LAPACK
*   Author: Intel Corporation
*   Created in March, 2010
*
* Purpose
*
* strtrs_1 is the test program for the C interface to LAPACK
* routine strtrs
* The program doesn't require an input, the input data is hardcoded in the
* test program.
* The program tests the C interface in the four combinations:
*   1) column-major layout, middle-level interface
*   2) column-major layout, high-level interface
*   3) row-major layout, middle-level interface
*   4) row-major layout, high-level interface
* The output of the C interface function is compared to those obtained from
* the corresponiding LAPACK routine with the same input data, and the
* comparison diagnostics is then printed on the standard output having PASSED
* keyword if the test is passed, and FAILED keyword if the test isn't passed.
*****************************************************************************/
#include <stdio.h>
#include "lapacke.h"
#include "lapacke_utils.h"
#include "test_utils.h"

static void init_scalars_strtrs( char *uplo, char *trans, char *diag,
                                 lapack_int *n, lapack_int *nrhs,
                                 lapack_int *lda, lapack_int *ldb );
static void init_a( lapack_int size, float *a );
static void init_b( lapack_int size, float *b );
static int compare_strtrs( float *b, float *b_i, lapack_int info,
                           lapack_int info_i, lapack_int ldb, lapack_int nrhs );

int main(void)
{
    /* Local scalars */
    char uplo, uplo_i;
    char trans, trans_i;
    char diag, diag_i;
    lapack_int n, n_i;
    lapack_int nrhs, nrhs_i;
    lapack_int lda, lda_i;
    lapack_int lda_r;
    lapack_int ldb, ldb_i;
    lapack_int ldb_r;
    lapack_int info, info_i;
    lapack_int i;
    int failed;

    /* Local arrays */
    float *a = NULL, *a_i = NULL;
    float *b = NULL, *b_i = NULL;
    float *b_save = NULL;
    float *a_r = NULL;
    float *b_r = NULL;

    /* Iniitialize the scalar parameters */
    init_scalars_strtrs( &uplo, &trans, &diag, &n, &nrhs, &lda, &ldb );
    lda_r = n+2;
    ldb_r = nrhs+2;
    uplo_i = uplo;
    trans_i = trans;
    diag_i = diag;
    n_i = n;
    nrhs_i = nrhs;
    lda_i = lda;
    ldb_i = ldb;

    /* Allocate memory for the LAPACK routine arrays */
    a = (float *)LAPACKE_malloc( lda*n * sizeof(float) );
    b = (float *)LAPACKE_malloc( ldb*nrhs * sizeof(float) );

    /* Allocate memory for the C interface function arrays */
    a_i = (float *)LAPACKE_malloc( lda*n * sizeof(float) );
    b_i = (float *)LAPACKE_malloc( ldb*nrhs * sizeof(float) );

    /* Allocate memory for the backup arrays */
    b_save = (float *)LAPACKE_malloc( ldb*nrhs * sizeof(float) );

    /* Allocate memory for the row-major arrays */
    a_r = (float *)LAPACKE_malloc( n*(n+2) * sizeof(float) );
    b_r = (float *)LAPACKE_malloc( n*(nrhs+2) * sizeof(float) );

    /* Initialize input arrays */
    init_a( lda*n, a );
    init_b( ldb*nrhs, b );

    /* Backup the ouptut arrays */
    for( i = 0; i < ldb*nrhs; i++ ) {
        b_save[i] = b[i];
    }

    /* Call the LAPACK routine */
    strtrs_( &uplo, &trans, &diag, &n, &nrhs, a, &lda, b, &ldb, &info );

    /* Initialize input data, call the column-major middle-level
     * interface to LAPACK routine and check the results */
    for( i = 0; i < lda*n; i++ ) {
        a_i[i] = a[i];
    }
    for( i = 0; i < ldb*nrhs; i++ ) {
        b_i[i] = b_save[i];
    }
    info_i = LAPACKE_strtrs_work( LAPACK_COL_MAJOR, uplo_i, trans_i, diag_i,
                                  n_i, nrhs_i, a_i, lda_i, b_i, ldb_i );

    failed = compare_strtrs( b, b_i, info, info_i, ldb, nrhs );
    if( failed == 0 ) {
        printf( "PASSED: column-major middle-level interface to strtrs\n" );
    } else {
        printf( "FAILED: column-major middle-level interface to strtrs\n" );
    }

    /* Initialize input data, call the column-major high-level
     * interface to LAPACK routine and check the results */
    for( i = 0; i < lda*n; i++ ) {
        a_i[i] = a[i];
    }
    for( i = 0; i < ldb*nrhs; i++ ) {
        b_i[i] = b_save[i];
    }
    info_i = LAPACKE_strtrs( LAPACK_COL_MAJOR, uplo_i, trans_i, diag_i, n_i,
                             nrhs_i, a_i, lda_i, b_i, ldb_i );

    failed = compare_strtrs( b, b_i, info, info_i, ldb, nrhs );
    if( failed == 0 ) {
        printf( "PASSED: column-major high-level interface to strtrs\n" );
    } else {
        printf( "FAILED: column-major high-level interface to strtrs\n" );
    }

    /* Initialize input data, call the row-major middle-level
     * interface to LAPACK routine and check the results */
    for( i = 0; i < lda*n; i++ ) {
        a_i[i] = a[i];
    }
    for( i = 0; i < ldb*nrhs; i++ ) {
        b_i[i] = b_save[i];
    }

    LAPACKE_sge_trans( LAPACK_COL_MAJOR, n, n, a_i, lda, a_r, n+2 );
    LAPACKE_sge_trans( LAPACK_COL_MAJOR, n, nrhs, b_i, ldb, b_r, nrhs+2 );
    info_i = LAPACKE_strtrs_work( LAPACK_ROW_MAJOR, uplo_i, trans_i, diag_i,
                                  n_i, nrhs_i, a_r, lda_r, b_r, ldb_r );

    LAPACKE_sge_trans( LAPACK_ROW_MAJOR, n, nrhs, b_r, nrhs+2, b_i, ldb );

    failed = compare_strtrs( b, b_i, info, info_i, ldb, nrhs );
    if( failed == 0 ) {
        printf( "PASSED: row-major middle-level interface to strtrs\n" );
    } else {
        printf( "FAILED: row-major middle-level interface to strtrs\n" );
    }

    /* Initialize input data, call the row-major high-level
     * interface to LAPACK routine and check the results */
    for( i = 0; i < lda*n; i++ ) {
        a_i[i] = a[i];
    }
    for( i = 0; i < ldb*nrhs; i++ ) {
        b_i[i] = b_save[i];
    }

    /* Init row_major arrays */
    LAPACKE_sge_trans( LAPACK_COL_MAJOR, n, n, a_i, lda, a_r, n+2 );
    LAPACKE_sge_trans( LAPACK_COL_MAJOR, n, nrhs, b_i, ldb, b_r, nrhs+2 );
    info_i = LAPACKE_strtrs( LAPACK_ROW_MAJOR, uplo_i, trans_i, diag_i, n_i,
                             nrhs_i, a_r, lda_r, b_r, ldb_r );

    LAPACKE_sge_trans( LAPACK_ROW_MAJOR, n, nrhs, b_r, nrhs+2, b_i, ldb );

    failed = compare_strtrs( b, b_i, info, info_i, ldb, nrhs );
    if( failed == 0 ) {
        printf( "PASSED: row-major high-level interface to strtrs\n" );
    } else {
        printf( "FAILED: row-major high-level interface to strtrs\n" );
    }

    /* Release memory */
    if( a != NULL ) {
        LAPACKE_free( a );
    }
    if( a_i != NULL ) {
        LAPACKE_free( a_i );
    }
    if( a_r != NULL ) {
        LAPACKE_free( a_r );
    }
    if( b != NULL ) {
        LAPACKE_free( b );
    }
    if( b_i != NULL ) {
        LAPACKE_free( b_i );
    }
    if( b_r != NULL ) {
        LAPACKE_free( b_r );
    }
    if( b_save != NULL ) {
        LAPACKE_free( b_save );
    }

    return 0;
}

/* Auxiliary function: strtrs scalar parameters initialization */
static void init_scalars_strtrs( char *uplo, char *trans, char *diag,
                                 lapack_int *n, lapack_int *nrhs,
                                 lapack_int *lda, lapack_int *ldb )
{
    *uplo = 'L';
    *trans = 'N';
    *diag = 'N';
    *n = 4;
    *nrhs = 2;
    *lda = 8;
    *ldb = 8;

    return;
}

/* Auxiliary functions: strtrs array parameters initialization */
static void init_a( lapack_int size, float *a ) {
    lapack_int i;
    for( i = 0; i < size; i++ ) {
        a[i] = 0;
    }
    a[0] = 4.300000191e+000;  /* a[0,0] */
    a[8] = 0.000000000e+000;  /* a[0,1] */
    a[16] = 0.000000000e+000;  /* a[0,2] */
    a[24] = 0.000000000e+000;  /* a[0,3] */
    a[1] = -3.960000038e+000;  /* a[1,0] */
    a[9] = -4.869999886e+000;  /* a[1,1] */
    a[17] = 0.000000000e+000;  /* a[1,2] */
    a[25] = 0.000000000e+000;  /* a[1,3] */
    a[2] = 4.000000060e-001;  /* a[2,0] */
    a[10] = 3.100000024e-001;  /* a[2,1] */
    a[18] = -8.020000458e+000;  /* a[2,2] */
    a[26] = 0.000000000e+000;  /* a[2,3] */
    a[3] = -2.700000107e-001;  /* a[3,0] */
    a[11] = 7.000000030e-002;  /* a[3,1] */
    a[19] = -5.949999809e+000;  /* a[3,2] */
    a[27] = 1.199999973e-001;  /* a[3,3] */
}
static void init_b( lapack_int size, float *b ) {
    lapack_int i;
    for( i = 0; i < size; i++ ) {
        b[i] = 0;
    }
    b[0] = -1.289999962e+001;  /* b[0,0] */
    b[8] = -2.150000000e+001;  /* b[0,1] */
    b[1] = 1.675000000e+001;  /* b[1,0] */
    b[9] = 1.493000031e+001;  /* b[1,1] */
    b[2] = -1.754999924e+001;  /* b[2,0] */
    b[10] = 6.329999924e+000;  /* b[2,1] */
    b[3] = -1.103999996e+001;  /* b[3,0] */
    b[11] = 8.090000153e+000;  /* b[3,1] */
}

/* Auxiliary function: C interface to strtrs results check */
/* Return value: 0 - test is passed, non-zero - test is failed */
static int compare_strtrs( float *b, float *b_i, lapack_int info,
                           lapack_int info_i, lapack_int ldb, lapack_int nrhs )
{
    lapack_int i;
    int failed = 0;
    for( i = 0; i < ldb*nrhs; i++ ) {
        failed += compare_floats(b[i],b_i[i]);
    }
    failed += (info == info_i) ? 0 : 1;
    if( info != 0 || info_i != 0 ) {
        printf( "info=%d, info_i=%d\n",(int)info,(int)info_i );
    }

    return failed;
}

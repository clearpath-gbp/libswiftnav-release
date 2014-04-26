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
* sgecon_1 is the test program for the C interface to LAPACK
* routine sgecon
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

static void init_scalars_sgecon( char *norm, lapack_int *n, lapack_int *lda,
                                 float *anorm );
static void init_a( lapack_int size, float *a );
static void init_work( lapack_int size, float *work );
static void init_iwork( lapack_int size, lapack_int *iwork );
static int compare_sgecon( float rcond, float rcond_i, lapack_int info,
                           lapack_int info_i );

int main(void)
{
    /* Local scalars */
    char norm, norm_i;
    lapack_int n, n_i;
    lapack_int lda, lda_i;
    lapack_int lda_r;
    float anorm, anorm_i;
    float rcond, rcond_i;
    lapack_int info, info_i;
    lapack_int i;
    int failed;

    /* Local arrays */
    float *a = NULL, *a_i = NULL;
    float *work = NULL, *work_i = NULL;
    lapack_int *iwork = NULL, *iwork_i = NULL;
    float *a_r = NULL;

    /* Iniitialize the scalar parameters */
    init_scalars_sgecon( &norm, &n, &lda, &anorm );
    lda_r = n+2;
    norm_i = norm;
    n_i = n;
    lda_i = lda;
    anorm_i = anorm;

    /* Allocate memory for the LAPACK routine arrays */
    a = (float *)LAPACKE_malloc( lda*n * sizeof(float) );
    work = (float *)LAPACKE_malloc( 4*n * sizeof(float) );
    iwork = (lapack_int *)LAPACKE_malloc( n * sizeof(lapack_int) );

    /* Allocate memory for the C interface function arrays */
    a_i = (float *)LAPACKE_malloc( lda*n * sizeof(float) );
    work_i = (float *)LAPACKE_malloc( 4*n * sizeof(float) );
    iwork_i = (lapack_int *)LAPACKE_malloc( n * sizeof(lapack_int) );

    /* Allocate memory for the row-major arrays */
    a_r = (float *)LAPACKE_malloc( n*(n+2) * sizeof(float) );

    /* Initialize input arrays */
    init_a( lda*n, a );
    init_work( 4*n, work );
    init_iwork( n, iwork );

    /* Call the LAPACK routine */
    sgecon_( &norm, &n, a, &lda, &anorm, &rcond, work, iwork, &info );

    /* Initialize input data, call the column-major middle-level
     * interface to LAPACK routine and check the results */
    for( i = 0; i < lda*n; i++ ) {
        a_i[i] = a[i];
    }
    for( i = 0; i < 4*n; i++ ) {
        work_i[i] = work[i];
    }
    for( i = 0; i < n; i++ ) {
        iwork_i[i] = iwork[i];
    }
    info_i = LAPACKE_sgecon_work( LAPACK_COL_MAJOR, norm_i, n_i, a_i, lda_i,
                                  anorm_i, &rcond_i, work_i, iwork_i );

    failed = compare_sgecon( rcond, rcond_i, info, info_i );
    if( failed == 0 ) {
        printf( "PASSED: column-major middle-level interface to sgecon\n" );
    } else {
        printf( "FAILED: column-major middle-level interface to sgecon\n" );
    }

    /* Initialize input data, call the column-major high-level
     * interface to LAPACK routine and check the results */
    for( i = 0; i < lda*n; i++ ) {
        a_i[i] = a[i];
    }
    for( i = 0; i < 4*n; i++ ) {
        work_i[i] = work[i];
    }
    for( i = 0; i < n; i++ ) {
        iwork_i[i] = iwork[i];
    }
    info_i = LAPACKE_sgecon( LAPACK_COL_MAJOR, norm_i, n_i, a_i, lda_i, anorm_i,
                             &rcond_i );

    failed = compare_sgecon( rcond, rcond_i, info, info_i );
    if( failed == 0 ) {
        printf( "PASSED: column-major high-level interface to sgecon\n" );
    } else {
        printf( "FAILED: column-major high-level interface to sgecon\n" );
    }

    /* Initialize input data, call the row-major middle-level
     * interface to LAPACK routine and check the results */
    for( i = 0; i < lda*n; i++ ) {
        a_i[i] = a[i];
    }
    for( i = 0; i < 4*n; i++ ) {
        work_i[i] = work[i];
    }
    for( i = 0; i < n; i++ ) {
        iwork_i[i] = iwork[i];
    }

    LAPACKE_sge_trans( LAPACK_COL_MAJOR, n, n, a_i, lda, a_r, n+2 );
    info_i = LAPACKE_sgecon_work( LAPACK_ROW_MAJOR, norm_i, n_i, a_r, lda_r,
                                  anorm_i, &rcond_i, work_i, iwork_i );

    failed = compare_sgecon( rcond, rcond_i, info, info_i );
    if( failed == 0 ) {
        printf( "PASSED: row-major middle-level interface to sgecon\n" );
    } else {
        printf( "FAILED: row-major middle-level interface to sgecon\n" );
    }

    /* Initialize input data, call the row-major high-level
     * interface to LAPACK routine and check the results */
    for( i = 0; i < lda*n; i++ ) {
        a_i[i] = a[i];
    }
    for( i = 0; i < 4*n; i++ ) {
        work_i[i] = work[i];
    }
    for( i = 0; i < n; i++ ) {
        iwork_i[i] = iwork[i];
    }

    /* Init row_major arrays */
    LAPACKE_sge_trans( LAPACK_COL_MAJOR, n, n, a_i, lda, a_r, n+2 );
    info_i = LAPACKE_sgecon( LAPACK_ROW_MAJOR, norm_i, n_i, a_r, lda_r, anorm_i,
                             &rcond_i );

    failed = compare_sgecon( rcond, rcond_i, info, info_i );
    if( failed == 0 ) {
        printf( "PASSED: row-major high-level interface to sgecon\n" );
    } else {
        printf( "FAILED: row-major high-level interface to sgecon\n" );
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
    if( work != NULL ) {
        LAPACKE_free( work );
    }
    if( work_i != NULL ) {
        LAPACKE_free( work_i );
    }
    if( iwork != NULL ) {
        LAPACKE_free( iwork );
    }
    if( iwork_i != NULL ) {
        LAPACKE_free( iwork_i );
    }

    return 0;
}

/* Auxiliary function: sgecon scalar parameters initialization */
static void init_scalars_sgecon( char *norm, lapack_int *n, lapack_int *lda,
                                 float *anorm )
{
    *norm = '1';
    *n = 4;
    *lda = 8;
    *anorm = 9.739999771e+000;

    return;
}

/* Auxiliary functions: sgecon array parameters initialization */
static void init_a( lapack_int size, float *a ) {
    lapack_int i;
    for( i = 0; i < size; i++ ) {
        a[i] = 0;
    }
    a[0] = 5.250000000e+000;  /* a[0,0] */
    a[8] = -2.950000048e+000;  /* a[0,1] */
    a[16] = -9.499999881e-001;  /* a[0,2] */
    a[24] = -3.799999952e+000;  /* a[0,3] */
    a[1] = 3.428571522e-001;  /* a[1,0] */
    a[9] = 3.891428709e+000;  /* a[1,1] */
    a[17] = 2.375714302e+000;  /* a[1,2] */
    a[25] = 4.128571749e-001;  /* a[1,3] */
    a[2] = 3.009524047e-001;  /* a[2,0] */
    a[10] = -4.631179273e-001;  /* a[2,1] */
    a[18] = -1.513859272e+000;  /* a[2,2] */
    a[26] = 2.948207855e-001;  /* a[2,3] */
    a[3] = -2.114285827e-001;  /* a[3,0] */
    a[11] = -3.298825026e-001;  /* a[3,1] */
    a[19] = 4.723378923e-003;  /* a[3,2] */
    a[27] = 1.313732415e-001;  /* a[3,3] */
}
static void init_work( lapack_int size, float *work ) {
    lapack_int i;
    for( i = 0; i < size; i++ ) {
        work[i] = 0;
    }
}
static void init_iwork( lapack_int size, lapack_int *iwork ) {
    lapack_int i;
    for( i = 0; i < size; i++ ) {
        iwork[i] = 0;
    }
}

/* Auxiliary function: C interface to sgecon results check */
/* Return value: 0 - test is passed, non-zero - test is failed */
static int compare_sgecon( float rcond, float rcond_i, lapack_int info,
                           lapack_int info_i )
{
    int failed = 0;
    failed += compare_floats(rcond,rcond_i);
    failed += (info == info_i) ? 0 : 1;
    if( info != 0 || info_i != 0 ) {
        printf( "info=%d, info_i=%d\n",(int)info,(int)info_i );
    }

    return failed;
}

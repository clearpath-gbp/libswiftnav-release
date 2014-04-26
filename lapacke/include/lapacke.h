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
* Contents: Native C interface to LAPACK
* Author: Intel Corporation
* Generated October, 2010
*****************************************************************************/

#ifndef _LAPACKE_H_
#define _LAPACKE_H_

/*
*  Turn on HAVE_LAPACK_CONFIG_H to redefine C-LAPACK datatypes
*  and default function name pattern.
*/
#ifdef HAVE_LAPACK_CONFIG_H
#include "lapacke_config.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include <stdlib.h>

#ifndef lapack_int
#define lapack_int     int
#endif

#ifndef lapack_logical
#define lapack_logical lapack_int
#endif

/* Complex types are structures equivalent to the
* Fortran complex types COMPLEX(4) and COMPLEX(8).
*
* One can also redefine the types with his own types
* for example by including in the code definitions like
*
* #define lapack_complex_float std::complex<float>
* #define lapack_complex_double std::complex<double>
*
* or define these types in the command line:
*
* -Dlapack_complex_float="std::complex<float>"
* -Dlapack_complex_double="std::complex<double>"
*/

#ifndef LAPACK_COMPLEX_CUSTOM

/* Complex type (single precision) */
#ifndef lapack_complex_float
#include <complex.h>
#define lapack_complex_float    float _Complex
#endif

#ifndef lapack_complex_float_real
#define lapack_complex_float_real(z)       (creal(z))
#endif

#ifndef lapack_complex_float_imag
#define lapack_complex_float_imag(z)       (imag(z))
#endif

lapack_complex_float lapack_make_complex_float( float re, float im );

/* Complex type (double precision) */
#ifndef lapack_complex_double
#include <complex.h>
#define lapack_complex_double   double _Complex
#endif

#ifndef lapack_complex_double_real
#define lapack_complex_double_real(z)      (creal(z))
#endif

#ifndef lapack_complex_double_imag
#define lapack_complex_double_imag(z)       (imag(z))
#endif

lapack_complex_double lapack_make_complex_double( double re, double im );

#endif

#ifndef ABS
#define ABS(x) (((x) < 0) ? -(x) : (x))
#endif
#ifndef MAX
#define MAX(x,y) (((x) > (y)) ? (x) : (y))
#endif
#ifndef MIN
#define MIN(x,y) (((x) < (y)) ? (x) : (y))
#endif
#ifndef MAX3
#define MAX3(x,y,z) (((x) > MAX(y,z)) ? (x) : MAX(y,z))
#endif
#ifndef MIN3
#define MIN3(x,y,z) (((x) < MIN(y,z)) ? (x) : MIN(y,z))
#endif

#define IS_S_NONZERO(x) ( (x) < 0 || (x) > 0 )
#define IS_D_NONZERO(x) ( (x) < 0 || (x) > 0 )
#define IS_C_NONZERO(x) ( IS_S_NONZERO(*((float*)&x)) ||  \
                          IS_S_NONZERO(*(((float*)&x)+1)) )
#define IS_Z_NONZERO(x) ( IS_D_NONZERO(*((double*)&x)) || \
                          IS_D_NONZERO(*(((double*)&x)+1)) )

#ifndef LAPACKE_malloc
#define LAPACKE_malloc( size ) malloc( size )
#endif
#ifndef LAPACKE_free
#define LAPACKE_free( p )      free( p )
#endif

#define LAPACK_C2INT( x ) (lapack_int)(*((float*)&x ))
#define LAPACK_Z2INT( x ) (lapack_int)(*((double*)&x ))

#define LAPACK_ROW_MAJOR               101
#define LAPACK_COL_MAJOR               102

#define LAPACK_WORK_MEMORY_ERROR       -1010
#define LAPACK_TRANSPOSE_MEMORY_ERROR  -1011

/* Callback logical functions of one, two, or three arguments are used
*  to select eigenvalues to sort to the top left of the Schur form.
*  The value is selected if function returns TRUE (non-zero). */

typedef lapack_logical (*LAPACK_S_SELECT2) ( const float*, const float* );
typedef lapack_logical (*LAPACK_S_SELECT3)
    ( const float*, const float*, const float* );
typedef lapack_logical (*LAPACK_D_SELECT2) ( const double*, const double* );
typedef lapack_logical (*LAPACK_D_SELECT3)
    ( const double*, const double*, const double* );

typedef lapack_logical (*LAPACK_C_SELECT1) ( const lapack_complex_float* );
typedef lapack_logical (*LAPACK_C_SELECT2)
    ( const lapack_complex_float*, const lapack_complex_float* );
typedef lapack_logical (*LAPACK_Z_SELECT1) ( const lapack_complex_double* );
typedef lapack_logical (*LAPACK_Z_SELECT2)
    ( const lapack_complex_double*, const lapack_complex_double* );

#ifndef LAPACK_NAME
#define LAPACK_NAME(lcname,UCNAME)  lcname##_
#endif

#define LAPACK_lsame LAPACK_NAME(lsame,LSAME)
lapack_logical LAPACK_lsame( char* ca,  char* cb,
                              lapack_int lca, lapack_int lcb );

/* C-LAPACK function prototypes */

lapack_int LAPACKE_sbdsdc( int matrix_order, char uplo, char compq,
                           lapack_int n, float* d, float* e, float* u,
                           lapack_int ldu, float* vt, lapack_int ldvt, float* q,
                           lapack_int* iq );
lapack_int LAPACKE_dbdsdc( int matrix_order, char uplo, char compq,
                           lapack_int n, double* d, double* e, double* u,
                           lapack_int ldu, double* vt, lapack_int ldvt,
                           double* q, lapack_int* iq );

lapack_int LAPACKE_sbdsqr( int matrix_order, char uplo, lapack_int n,
                           lapack_int ncvt, lapack_int nru, lapack_int ncc,
                           float* d, float* e, float* vt, lapack_int ldvt,
                           float* u, lapack_int ldu, float* c, lapack_int ldc );
lapack_int LAPACKE_dbdsqr( int matrix_order, char uplo, lapack_int n,
                           lapack_int ncvt, lapack_int nru, lapack_int ncc,
                           double* d, double* e, double* vt, lapack_int ldvt,
                           double* u, lapack_int ldu, double* c,
                           lapack_int ldc );
lapack_int LAPACKE_cbdsqr( int matrix_order, char uplo, lapack_int n,
                           lapack_int ncvt, lapack_int nru, lapack_int ncc,
                           float* d, float* e, lapack_complex_float* vt,
                           lapack_int ldvt, lapack_complex_float* u,
                           lapack_int ldu, lapack_complex_float* c,
                           lapack_int ldc );
lapack_int LAPACKE_zbdsqr( int matrix_order, char uplo, lapack_int n,
                           lapack_int ncvt, lapack_int nru, lapack_int ncc,
                           double* d, double* e, lapack_complex_double* vt,
                           lapack_int ldvt, lapack_complex_double* u,
                           lapack_int ldu, lapack_complex_double* c,
                           lapack_int ldc );

lapack_int LAPACKE_sdisna( char job, lapack_int m, lapack_int n, const float* d,
                           float* sep );
lapack_int LAPACKE_ddisna( char job, lapack_int m, lapack_int n,
                           const double* d, double* sep );

lapack_int LAPACKE_sgbbrd( int matrix_order, char vect, lapack_int m,
                           lapack_int n, lapack_int ncc, lapack_int kl,
                           lapack_int ku, float* ab, lapack_int ldab, float* d,
                           float* e, float* q, lapack_int ldq, float* pt,
                           lapack_int ldpt, float* c, lapack_int ldc );
lapack_int LAPACKE_dgbbrd( int matrix_order, char vect, lapack_int m,
                           lapack_int n, lapack_int ncc, lapack_int kl,
                           lapack_int ku, double* ab, lapack_int ldab,
                           double* d, double* e, double* q, lapack_int ldq,
                           double* pt, lapack_int ldpt, double* c,
                           lapack_int ldc );
lapack_int LAPACKE_cgbbrd( int matrix_order, char vect, lapack_int m,
                           lapack_int n, lapack_int ncc, lapack_int kl,
                           lapack_int ku, lapack_complex_float* ab,
                           lapack_int ldab, float* d, float* e,
                           lapack_complex_float* q, lapack_int ldq,
                           lapack_complex_float* pt, lapack_int ldpt,
                           lapack_complex_float* c, lapack_int ldc );
lapack_int LAPACKE_zgbbrd( int matrix_order, char vect, lapack_int m,
                           lapack_int n, lapack_int ncc, lapack_int kl,
                           lapack_int ku, lapack_complex_double* ab,
                           lapack_int ldab, double* d, double* e,
                           lapack_complex_double* q, lapack_int ldq,
                           lapack_complex_double* pt, lapack_int ldpt,
                           lapack_complex_double* c, lapack_int ldc );

lapack_int LAPACKE_sgbcon( int matrix_order, char norm, lapack_int n,
                           lapack_int kl, lapack_int ku, const float* ab,
                           lapack_int ldab, const lapack_int* ipiv, float anorm,
                           float* rcond );
lapack_int LAPACKE_dgbcon( int matrix_order, char norm, lapack_int n,
                           lapack_int kl, lapack_int ku, const double* ab,
                           lapack_int ldab, const lapack_int* ipiv,
                           double anorm, double* rcond );
lapack_int LAPACKE_cgbcon( int matrix_order, char norm, lapack_int n,
                           lapack_int kl, lapack_int ku,
                           const lapack_complex_float* ab, lapack_int ldab,
                           const lapack_int* ipiv, float anorm, float* rcond );
lapack_int LAPACKE_zgbcon( int matrix_order, char norm, lapack_int n,
                           lapack_int kl, lapack_int ku,
                           const lapack_complex_double* ab, lapack_int ldab,
                           const lapack_int* ipiv, double anorm,
                           double* rcond );

lapack_int LAPACKE_sgbequ( int matrix_order, lapack_int m, lapack_int n,
                           lapack_int kl, lapack_int ku, const float* ab,
                           lapack_int ldab, float* r, float* c, float* rowcnd,
                           float* colcnd, float* amax );
lapack_int LAPACKE_dgbequ( int matrix_order, lapack_int m, lapack_int n,
                           lapack_int kl, lapack_int ku, const double* ab,
                           lapack_int ldab, double* r, double* c,
                           double* rowcnd, double* colcnd, double* amax );
lapack_int LAPACKE_cgbequ( int matrix_order, lapack_int m, lapack_int n,
                           lapack_int kl, lapack_int ku,
                           const lapack_complex_float* ab, lapack_int ldab,
                           float* r, float* c, float* rowcnd, float* colcnd,
                           float* amax );
lapack_int LAPACKE_zgbequ( int matrix_order, lapack_int m, lapack_int n,
                           lapack_int kl, lapack_int ku,
                           const lapack_complex_double* ab, lapack_int ldab,
                           double* r, double* c, double* rowcnd, double* colcnd,
                           double* amax );

lapack_int LAPACKE_sgbequb( int matrix_order, lapack_int m, lapack_int n,
                            lapack_int kl, lapack_int ku, const float* ab,
                            lapack_int ldab, float* r, float* c, float* rowcnd,
                            float* colcnd, float* amax );
lapack_int LAPACKE_dgbequb( int matrix_order, lapack_int m, lapack_int n,
                            lapack_int kl, lapack_int ku, const double* ab,
                            lapack_int ldab, double* r, double* c,
                            double* rowcnd, double* colcnd, double* amax );
lapack_int LAPACKE_cgbequb( int matrix_order, lapack_int m, lapack_int n,
                            lapack_int kl, lapack_int ku,
                            const lapack_complex_float* ab, lapack_int ldab,
                            float* r, float* c, float* rowcnd, float* colcnd,
                            float* amax );
lapack_int LAPACKE_zgbequb( int matrix_order, lapack_int m, lapack_int n,
                            lapack_int kl, lapack_int ku,
                            const lapack_complex_double* ab, lapack_int ldab,
                            double* r, double* c, double* rowcnd,
                            double* colcnd, double* amax );

lapack_int LAPACKE_sgbrfs( int matrix_order, char trans, lapack_int n,
                           lapack_int kl, lapack_int ku, lapack_int nrhs,
                           const float* ab, lapack_int ldab, const float* afb,
                           lapack_int ldafb, const lapack_int* ipiv,
                           const float* b, lapack_int ldb, float* x,
                           lapack_int ldx, float* ferr, float* berr );
lapack_int LAPACKE_dgbrfs( int matrix_order, char trans, lapack_int n,
                           lapack_int kl, lapack_int ku, lapack_int nrhs,
                           const double* ab, lapack_int ldab, const double* afb,
                           lapack_int ldafb, const lapack_int* ipiv,
                           const double* b, lapack_int ldb, double* x,
                           lapack_int ldx, double* ferr, double* berr );
lapack_int LAPACKE_cgbrfs( int matrix_order, char trans, lapack_int n,
                           lapack_int kl, lapack_int ku, lapack_int nrhs,
                           const lapack_complex_float* ab, lapack_int ldab,
                           const lapack_complex_float* afb, lapack_int ldafb,
                           const lapack_int* ipiv,
                           const lapack_complex_float* b, lapack_int ldb,
                           lapack_complex_float* x, lapack_int ldx, float* ferr,
                           float* berr );
lapack_int LAPACKE_zgbrfs( int matrix_order, char trans, lapack_int n,
                           lapack_int kl, lapack_int ku, lapack_int nrhs,
                           const lapack_complex_double* ab, lapack_int ldab,
                           const lapack_complex_double* afb, lapack_int ldafb,
                           const lapack_int* ipiv,
                           const lapack_complex_double* b, lapack_int ldb,
                           lapack_complex_double* x, lapack_int ldx,
                           double* ferr, double* berr );

lapack_int LAPACKE_sgbrfsx( int matrix_order, char trans, char equed,
                            lapack_int n, lapack_int kl, lapack_int ku,
                            lapack_int nrhs, const float* ab, lapack_int ldab,
                            const float* afb, lapack_int ldafb,
                            const lapack_int* ipiv, const float* r,
                            const float* c, const float* b, lapack_int ldb,
                            float* x, lapack_int ldx, float* rcond, float* berr,
                            lapack_int n_err_bnds, float* err_bnds_norm,
                            float* err_bnds_comp, lapack_int nparams,
                            float* params );
lapack_int LAPACKE_dgbrfsx( int matrix_order, char trans, char equed,
                            lapack_int n, lapack_int kl, lapack_int ku,
                            lapack_int nrhs, const double* ab, lapack_int ldab,
                            const double* afb, lapack_int ldafb,
                            const lapack_int* ipiv, const double* r,
                            const double* c, const double* b, lapack_int ldb,
                            double* x, lapack_int ldx, double* rcond,
                            double* berr, lapack_int n_err_bnds,
                            double* err_bnds_norm, double* err_bnds_comp,
                            lapack_int nparams, double* params );
lapack_int LAPACKE_cgbrfsx( int matrix_order, char trans, char equed,
                            lapack_int n, lapack_int kl, lapack_int ku,
                            lapack_int nrhs, const lapack_complex_float* ab,
                            lapack_int ldab, const lapack_complex_float* afb,
                            lapack_int ldafb, const lapack_int* ipiv,
                            const float* r, const float* c,
                            const lapack_complex_float* b, lapack_int ldb,
                            lapack_complex_float* x, lapack_int ldx,
                            float* rcond, float* berr, lapack_int n_err_bnds,
                            float* err_bnds_norm, float* err_bnds_comp,
                            lapack_int nparams, float* params );
lapack_int LAPACKE_zgbrfsx( int matrix_order, char trans, char equed,
                            lapack_int n, lapack_int kl, lapack_int ku,
                            lapack_int nrhs, const lapack_complex_double* ab,
                            lapack_int ldab, const lapack_complex_double* afb,
                            lapack_int ldafb, const lapack_int* ipiv,
                            const double* r, const double* c,
                            const lapack_complex_double* b, lapack_int ldb,
                            lapack_complex_double* x, lapack_int ldx,
                            double* rcond, double* berr, lapack_int n_err_bnds,
                            double* err_bnds_norm, double* err_bnds_comp,
                            lapack_int nparams, double* params );

lapack_int LAPACKE_sgbsv( int matrix_order, lapack_int n, lapack_int kl,
                          lapack_int ku, lapack_int nrhs, float* ab,
                          lapack_int ldab, lapack_int* ipiv, float* b,
                          lapack_int ldb );
lapack_int LAPACKE_dgbsv( int matrix_order, lapack_int n, lapack_int kl,
                          lapack_int ku, lapack_int nrhs, double* ab,
                          lapack_int ldab, lapack_int* ipiv, double* b,
                          lapack_int ldb );
lapack_int LAPACKE_cgbsv( int matrix_order, lapack_int n, lapack_int kl,
                          lapack_int ku, lapack_int nrhs,
                          lapack_complex_float* ab, lapack_int ldab,
                          lapack_int* ipiv, lapack_complex_float* b,
                          lapack_int ldb );
lapack_int LAPACKE_zgbsv( int matrix_order, lapack_int n, lapack_int kl,
                          lapack_int ku, lapack_int nrhs,
                          lapack_complex_double* ab, lapack_int ldab,
                          lapack_int* ipiv, lapack_complex_double* b,
                          lapack_int ldb );

lapack_int LAPACKE_sgbsvx( int matrix_order, char fact, char trans,
                           lapack_int n, lapack_int kl, lapack_int ku,
                           lapack_int nrhs, float* ab, lapack_int ldab,
                           float* afb, lapack_int ldafb, lapack_int* ipiv,
                           char* equed, float* r, float* c, float* b,
                           lapack_int ldb, float* x, lapack_int ldx,
                           float* rcond, float* ferr, float* berr,
                           float* rpivot );
lapack_int LAPACKE_dgbsvx( int matrix_order, char fact, char trans,
                           lapack_int n, lapack_int kl, lapack_int ku,
                           lapack_int nrhs, double* ab, lapack_int ldab,
                           double* afb, lapack_int ldafb, lapack_int* ipiv,
                           char* equed, double* r, double* c, double* b,
                           lapack_int ldb, double* x, lapack_int ldx,
                           double* rcond, double* ferr, double* berr,
                           double* rpivot );
lapack_int LAPACKE_cgbsvx( int matrix_order, char fact, char trans,
                           lapack_int n, lapack_int kl, lapack_int ku,
                           lapack_int nrhs, lapack_complex_float* ab,
                           lapack_int ldab, lapack_complex_float* afb,
                           lapack_int ldafb, lapack_int* ipiv, char* equed,
                           float* r, float* c, lapack_complex_float* b,
                           lapack_int ldb, lapack_complex_float* x,
                           lapack_int ldx, float* rcond, float* ferr,
                           float* berr, float* rpivot );
lapack_int LAPACKE_zgbsvx( int matrix_order, char fact, char trans,
                           lapack_int n, lapack_int kl, lapack_int ku,
                           lapack_int nrhs, lapack_complex_double* ab,
                           lapack_int ldab, lapack_complex_double* afb,
                           lapack_int ldafb, lapack_int* ipiv, char* equed,
                           double* r, double* c, lapack_complex_double* b,
                           lapack_int ldb, lapack_complex_double* x,
                           lapack_int ldx, double* rcond, double* ferr,
                           double* berr, double* rpivot );

lapack_int LAPACKE_sgbsvxx( int matrix_order, char fact, char trans,
                            lapack_int n, lapack_int kl, lapack_int ku,
                            lapack_int nrhs, float* ab, lapack_int ldab,
                            float* afb, lapack_int ldafb, lapack_int* ipiv,
                            char* equed, float* r, float* c, float* b,
                            lapack_int ldb, float* x, lapack_int ldx,
                            float* rcond, float* rpvgrw, float* berr,
                            lapack_int n_err_bnds, float* err_bnds_norm,
                            float* err_bnds_comp, lapack_int nparams,
                            float* params );
lapack_int LAPACKE_dgbsvxx( int matrix_order, char fact, char trans,
                            lapack_int n, lapack_int kl, lapack_int ku,
                            lapack_int nrhs, double* ab, lapack_int ldab,
                            double* afb, lapack_int ldafb, lapack_int* ipiv,
                            char* equed, double* r, double* c, double* b,
                            lapack_int ldb, double* x, lapack_int ldx,
                            double* rcond, double* rpvgrw, double* berr,
                            lapack_int n_err_bnds, double* err_bnds_norm,
                            double* err_bnds_comp, lapack_int nparams,
                            double* params );
lapack_int LAPACKE_cgbsvxx( int matrix_order, char fact, char trans,
                            lapack_int n, lapack_int kl, lapack_int ku,
                            lapack_int nrhs, lapack_complex_float* ab,
                            lapack_int ldab, lapack_complex_float* afb,
                            lapack_int ldafb, lapack_int* ipiv, char* equed,
                            float* r, float* c, lapack_complex_float* b,
                            lapack_int ldb, lapack_complex_float* x,
                            lapack_int ldx, float* rcond, float* rpvgrw,
                            float* berr, lapack_int n_err_bnds,
                            float* err_bnds_norm, float* err_bnds_comp,
                            lapack_int nparams, float* params );
lapack_int LAPACKE_zgbsvxx( int matrix_order, char fact, char trans,
                            lapack_int n, lapack_int kl, lapack_int ku,
                            lapack_int nrhs, lapack_complex_double* ab,
                            lapack_int ldab, lapack_complex_double* afb,
                            lapack_int ldafb, lapack_int* ipiv, char* equed,
                            double* r, double* c, lapack_complex_double* b,
                            lapack_int ldb, lapack_complex_double* x,
                            lapack_int ldx, double* rcond, double* rpvgrw,
                            double* berr, lapack_int n_err_bnds,
                            double* err_bnds_norm, double* err_bnds_comp,
                            lapack_int nparams, double* params );

lapack_int LAPACKE_sgbtrf( int matrix_order, lapack_int m, lapack_int n,
                           lapack_int kl, lapack_int ku, float* ab,
                           lapack_int ldab, lapack_int* ipiv );
lapack_int LAPACKE_dgbtrf( int matrix_order, lapack_int m, lapack_int n,
                           lapack_int kl, lapack_int ku, double* ab,
                           lapack_int ldab, lapack_int* ipiv );
lapack_int LAPACKE_cgbtrf( int matrix_order, lapack_int m, lapack_int n,
                           lapack_int kl, lapack_int ku,
                           lapack_complex_float* ab, lapack_int ldab,
                           lapack_int* ipiv );
lapack_int LAPACKE_zgbtrf( int matrix_order, lapack_int m, lapack_int n,
                           lapack_int kl, lapack_int ku,
                           lapack_complex_double* ab, lapack_int ldab,
                           lapack_int* ipiv );

lapack_int LAPACKE_sgbtrs( int matrix_order, char trans, lapack_int n,
                           lapack_int kl, lapack_int ku, lapack_int nrhs,
                           const float* ab, lapack_int ldab,
                           const lapack_int* ipiv, float* b, lapack_int ldb );
lapack_int LAPACKE_dgbtrs( int matrix_order, char trans, lapack_int n,
                           lapack_int kl, lapack_int ku, lapack_int nrhs,
                           const double* ab, lapack_int ldab,
                           const lapack_int* ipiv, double* b, lapack_int ldb );
lapack_int LAPACKE_cgbtrs( int matrix_order, char trans, lapack_int n,
                           lapack_int kl, lapack_int ku, lapack_int nrhs,
                           const lapack_complex_float* ab, lapack_int ldab,
                           const lapack_int* ipiv, lapack_complex_float* b,
                           lapack_int ldb );
lapack_int LAPACKE_zgbtrs( int matrix_order, char trans, lapack_int n,
                           lapack_int kl, lapack_int ku, lapack_int nrhs,
                           const lapack_complex_double* ab, lapack_int ldab,
                           const lapack_int* ipiv, lapack_complex_double* b,
                           lapack_int ldb );

lapack_int LAPACKE_sgebak( int matrix_order, char job, char side, lapack_int n,
                           lapack_int ilo, lapack_int ihi, const float* scale,
                           lapack_int m, float* v, lapack_int ldv );
lapack_int LAPACKE_dgebak( int matrix_order, char job, char side, lapack_int n,
                           lapack_int ilo, lapack_int ihi, const double* scale,
                           lapack_int m, double* v, lapack_int ldv );
lapack_int LAPACKE_cgebak( int matrix_order, char job, char side, lapack_int n,
                           lapack_int ilo, lapack_int ihi, const float* scale,
                           lapack_int m, lapack_complex_float* v,
                           lapack_int ldv );
lapack_int LAPACKE_zgebak( int matrix_order, char job, char side, lapack_int n,
                           lapack_int ilo, lapack_int ihi, const double* scale,
                           lapack_int m, lapack_complex_double* v,
                           lapack_int ldv );

lapack_int LAPACKE_sgebal( int matrix_order, char job, lapack_int n, float* a,
                           lapack_int lda, lapack_int* ilo, lapack_int* ihi,
                           float* scale );
lapack_int LAPACKE_dgebal( int matrix_order, char job, lapack_int n, double* a,
                           lapack_int lda, lapack_int* ilo, lapack_int* ihi,
                           double* scale );
lapack_int LAPACKE_cgebal( int matrix_order, char job, lapack_int n,
                           lapack_complex_float* a, lapack_int lda,
                           lapack_int* ilo, lapack_int* ihi, float* scale );
lapack_int LAPACKE_zgebal( int matrix_order, char job, lapack_int n,
                           lapack_complex_double* a, lapack_int lda,
                           lapack_int* ilo, lapack_int* ihi, double* scale );

lapack_int LAPACKE_sgebrd( int matrix_order, lapack_int m, lapack_int n,
                           float* a, lapack_int lda, float* d, float* e,
                           float* tauq, float* taup );
lapack_int LAPACKE_dgebrd( int matrix_order, lapack_int m, lapack_int n,
                           double* a, lapack_int lda, double* d, double* e,
                           double* tauq, double* taup );
lapack_int LAPACKE_cgebrd( int matrix_order, lapack_int m, lapack_int n,
                           lapack_complex_float* a, lapack_int lda, float* d,
                           float* e, lapack_complex_float* tauq,
                           lapack_complex_float* taup );
lapack_int LAPACKE_zgebrd( int matrix_order, lapack_int m, lapack_int n,
                           lapack_complex_double* a, lapack_int lda, double* d,
                           double* e, lapack_complex_double* tauq,
                           lapack_complex_double* taup );

lapack_int LAPACKE_sgecon( int matrix_order, char norm, lapack_int n,
                           const float* a, lapack_int lda, float anorm,
                           float* rcond );
lapack_int LAPACKE_dgecon( int matrix_order, char norm, lapack_int n,
                           const double* a, lapack_int lda, double anorm,
                           double* rcond );
lapack_int LAPACKE_cgecon( int matrix_order, char norm, lapack_int n,
                           const lapack_complex_float* a, lapack_int lda,
                           float anorm, float* rcond );
lapack_int LAPACKE_zgecon( int matrix_order, char norm, lapack_int n,
                           const lapack_complex_double* a, lapack_int lda,
                           double anorm, double* rcond );

lapack_int LAPACKE_sgeequ( int matrix_order, lapack_int m, lapack_int n,
                           const float* a, lapack_int lda, float* r, float* c,
                           float* rowcnd, float* colcnd, float* amax );
lapack_int LAPACKE_dgeequ( int matrix_order, lapack_int m, lapack_int n,
                           const double* a, lapack_int lda, double* r,
                           double* c, double* rowcnd, double* colcnd,
                           double* amax );
lapack_int LAPACKE_cgeequ( int matrix_order, lapack_int m, lapack_int n,
                           const lapack_complex_float* a, lapack_int lda,
                           float* r, float* c, float* rowcnd, float* colcnd,
                           float* amax );
lapack_int LAPACKE_zgeequ( int matrix_order, lapack_int m, lapack_int n,
                           const lapack_complex_double* a, lapack_int lda,
                           double* r, double* c, double* rowcnd, double* colcnd,
                           double* amax );

lapack_int LAPACKE_sgeequb( int matrix_order, lapack_int m, lapack_int n,
                            const float* a, lapack_int lda, float* r, float* c,
                            float* rowcnd, float* colcnd, float* amax );
lapack_int LAPACKE_dgeequb( int matrix_order, lapack_int m, lapack_int n,
                            const double* a, lapack_int lda, double* r,
                            double* c, double* rowcnd, double* colcnd,
                            double* amax );
lapack_int LAPACKE_cgeequb( int matrix_order, lapack_int m, lapack_int n,
                            const lapack_complex_float* a, lapack_int lda,
                            float* r, float* c, float* rowcnd, float* colcnd,
                            float* amax );
lapack_int LAPACKE_zgeequb( int matrix_order, lapack_int m, lapack_int n,
                            const lapack_complex_double* a, lapack_int lda,
                            double* r, double* c, double* rowcnd,
                            double* colcnd, double* amax );

lapack_int LAPACKE_sgees( int matrix_order, char jobvs, char sort,
                          LAPACK_S_SELECT2 select, lapack_int n, float* a,
                          lapack_int lda, lapack_int* sdim, float* wr,
                          float* wi, float* vs, lapack_int ldvs );
lapack_int LAPACKE_dgees( int matrix_order, char jobvs, char sort,
                          LAPACK_D_SELECT2 select, lapack_int n, double* a,
                          lapack_int lda, lapack_int* sdim, double* wr,
                          double* wi, double* vs, lapack_int ldvs );
lapack_int LAPACKE_cgees( int matrix_order, char jobvs, char sort,
                          LAPACK_C_SELECT1 select, lapack_int n,
                          lapack_complex_float* a, lapack_int lda,
                          lapack_int* sdim, lapack_complex_float* w,
                          lapack_complex_float* vs, lapack_int ldvs );
lapack_int LAPACKE_zgees( int matrix_order, char jobvs, char sort,
                          LAPACK_Z_SELECT1 select, lapack_int n,
                          lapack_complex_double* a, lapack_int lda,
                          lapack_int* sdim, lapack_complex_double* w,
                          lapack_complex_double* vs, lapack_int ldvs );

lapack_int LAPACKE_sgeesx( int matrix_order, char jobvs, char sort,
                           LAPACK_S_SELECT2 select, char sense, lapack_int n,
                           float* a, lapack_int lda, lapack_int* sdim,
                           float* wr, float* wi, float* vs, lapack_int ldvs,
                           float* rconde, float* rcondv );
lapack_int LAPACKE_dgeesx( int matrix_order, char jobvs, char sort,
                           LAPACK_D_SELECT2 select, char sense, lapack_int n,
                           double* a, lapack_int lda, lapack_int* sdim,
                           double* wr, double* wi, double* vs, lapack_int ldvs,
                           double* rconde, double* rcondv );
lapack_int LAPACKE_cgeesx( int matrix_order, char jobvs, char sort,
                           LAPACK_C_SELECT1 select, char sense, lapack_int n,
                           lapack_complex_float* a, lapack_int lda,
                           lapack_int* sdim, lapack_complex_float* w,
                           lapack_complex_float* vs, lapack_int ldvs,
                           float* rconde, float* rcondv );
lapack_int LAPACKE_zgeesx( int matrix_order, char jobvs, char sort,
                           LAPACK_Z_SELECT1 select, char sense, lapack_int n,
                           lapack_complex_double* a, lapack_int lda,
                           lapack_int* sdim, lapack_complex_double* w,
                           lapack_complex_double* vs, lapack_int ldvs,
                           double* rconde, double* rcondv );

lapack_int LAPACKE_sgeev( int matrix_order, char jobvl, char jobvr,
                          lapack_int n, float* a, lapack_int lda, float* wr,
                          float* wi, float* vl, lapack_int ldvl, float* vr,
                          lapack_int ldvr );
lapack_int LAPACKE_dgeev( int matrix_order, char jobvl, char jobvr,
                          lapack_int n, double* a, lapack_int lda, double* wr,
                          double* wi, double* vl, lapack_int ldvl, double* vr,
                          lapack_int ldvr );
lapack_int LAPACKE_cgeev( int matrix_order, char jobvl, char jobvr,
                          lapack_int n, lapack_complex_float* a, lapack_int lda,
                          lapack_complex_float* w, lapack_complex_float* vl,
                          lapack_int ldvl, lapack_complex_float* vr,
                          lapack_int ldvr );
lapack_int LAPACKE_zgeev( int matrix_order, char jobvl, char jobvr,
                          lapack_int n, lapack_complex_double* a,
                          lapack_int lda, lapack_complex_double* w,
                          lapack_complex_double* vl, lapack_int ldvl,
                          lapack_complex_double* vr, lapack_int ldvr );

lapack_int LAPACKE_sgeevx( int matrix_order, char balanc, char jobvl,
                           char jobvr, char sense, lapack_int n, float* a,
                           lapack_int lda, float* wr, float* wi, float* vl,
                           lapack_int ldvl, float* vr, lapack_int ldvr,
                           lapack_int* ilo, lapack_int* ihi, float* scale,
                           float* abnrm, float* rconde, float* rcondv );
lapack_int LAPACKE_dgeevx( int matrix_order, char balanc, char jobvl,
                           char jobvr, char sense, lapack_int n, double* a,
                           lapack_int lda, double* wr, double* wi, double* vl,
                           lapack_int ldvl, double* vr, lapack_int ldvr,
                           lapack_int* ilo, lapack_int* ihi, double* scale,
                           double* abnrm, double* rconde, double* rcondv );
lapack_int LAPACKE_cgeevx( int matrix_order, char balanc, char jobvl,
                           char jobvr, char sense, lapack_int n,
                           lapack_complex_float* a, lapack_int lda,
                           lapack_complex_float* w, lapack_complex_float* vl,
                           lapack_int ldvl, lapack_complex_float* vr,
                           lapack_int ldvr, lapack_int* ilo, lapack_int* ihi,
                           float* scale, float* abnrm, float* rconde,
                           float* rcondv );
lapack_int LAPACKE_zgeevx( int matrix_order, char balanc, char jobvl,
                           char jobvr, char sense, lapack_int n,
                           lapack_complex_double* a, lapack_int lda,
                           lapack_complex_double* w, lapack_complex_double* vl,
                           lapack_int ldvl, lapack_complex_double* vr,
                           lapack_int ldvr, lapack_int* ilo, lapack_int* ihi,
                           double* scale, double* abnrm, double* rconde,
                           double* rcondv );

lapack_int LAPACKE_sgehrd( int matrix_order, lapack_int n, lapack_int ilo,
                           lapack_int ihi, float* a, lapack_int lda,
                           float* tau );
lapack_int LAPACKE_dgehrd( int matrix_order, lapack_int n, lapack_int ilo,
                           lapack_int ihi, double* a, lapack_int lda,
                           double* tau );
lapack_int LAPACKE_cgehrd( int matrix_order, lapack_int n, lapack_int ilo,
                           lapack_int ihi, lapack_complex_float* a,
                           lapack_int lda, lapack_complex_float* tau );
lapack_int LAPACKE_zgehrd( int matrix_order, lapack_int n, lapack_int ilo,
                           lapack_int ihi, lapack_complex_double* a,
                           lapack_int lda, lapack_complex_double* tau );

lapack_int LAPACKE_sgejsv( int matrix_order, char joba, char jobu, char jobv,
                           char jobr, char jobt, char jobp, lapack_int m,
                           lapack_int n, float* a, lapack_int lda, float* sva,
                           float* u, lapack_int ldu, float* v, lapack_int ldv,
                           float* stat, lapack_int* istat );
lapack_int LAPACKE_dgejsv( int matrix_order, char joba, char jobu, char jobv,
                           char jobr, char jobt, char jobp, lapack_int m,
                           lapack_int n, double* a, lapack_int lda, double* sva,
                           double* u, lapack_int ldu, double* v, lapack_int ldv,
                           double* stat, lapack_int* istat );

lapack_int LAPACKE_sgelqf( int matrix_order, lapack_int m, lapack_int n,
                           float* a, lapack_int lda, float* tau );
lapack_int LAPACKE_dgelqf( int matrix_order, lapack_int m, lapack_int n,
                           double* a, lapack_int lda, double* tau );
lapack_int LAPACKE_cgelqf( int matrix_order, lapack_int m, lapack_int n,
                           lapack_complex_float* a, lapack_int lda,
                           lapack_complex_float* tau );
lapack_int LAPACKE_zgelqf( int matrix_order, lapack_int m, lapack_int n,
                           lapack_complex_double* a, lapack_int lda,
                           lapack_complex_double* tau );

lapack_int LAPACKE_sgels( int matrix_order, char trans, lapack_int m,
                          lapack_int n, lapack_int nrhs, float* a,
                          lapack_int lda, float* b, lapack_int ldb );
lapack_int LAPACKE_dgels( int matrix_order, char trans, lapack_int m,
                          lapack_int n, lapack_int nrhs, double* a,
                          lapack_int lda, double* b, lapack_int ldb );
lapack_int LAPACKE_cgels( int matrix_order, char trans, lapack_int m,
                          lapack_int n, lapack_int nrhs,
                          lapack_complex_float* a, lapack_int lda,
                          lapack_complex_float* b, lapack_int ldb );
lapack_int LAPACKE_zgels( int matrix_order, char trans, lapack_int m,
                          lapack_int n, lapack_int nrhs,
                          lapack_complex_double* a, lapack_int lda,
                          lapack_complex_double* b, lapack_int ldb );

lapack_int LAPACKE_sgelsd( int matrix_order, lapack_int m, lapack_int n,
                           lapack_int nrhs, float* a, lapack_int lda, float* b,
                           lapack_int ldb, float* s, float rcond,
                           lapack_int* rank );
lapack_int LAPACKE_dgelsd( int matrix_order, lapack_int m, lapack_int n,
                           lapack_int nrhs, double* a, lapack_int lda,
                           double* b, lapack_int ldb, double* s, double rcond,
                           lapack_int* rank );
lapack_int LAPACKE_cgelsd( int matrix_order, lapack_int m, lapack_int n,
                           lapack_int nrhs, lapack_complex_float* a,
                           lapack_int lda, lapack_complex_float* b,
                           lapack_int ldb, float* s, float rcond,
                           lapack_int* rank );
lapack_int LAPACKE_zgelsd( int matrix_order, lapack_int m, lapack_int n,
                           lapack_int nrhs, lapack_complex_double* a,
                           lapack_int lda, lapack_complex_double* b,
                           lapack_int ldb, double* s, double rcond,
                           lapack_int* rank );

lapack_int LAPACKE_sgelss( int matrix_order, lapack_int m, lapack_int n,
                           lapack_int nrhs, float* a, lapack_int lda, float* b,
                           lapack_int ldb, float* s, float rcond,
                           lapack_int* rank );
lapack_int LAPACKE_dgelss( int matrix_order, lapack_int m, lapack_int n,
                           lapack_int nrhs, double* a, lapack_int lda,
                           double* b, lapack_int ldb, double* s, double rcond,
                           lapack_int* rank );
lapack_int LAPACKE_cgelss( int matrix_order, lapack_int m, lapack_int n,
                           lapack_int nrhs, lapack_complex_float* a,
                           lapack_int lda, lapack_complex_float* b,
                           lapack_int ldb, float* s, float rcond,
                           lapack_int* rank );
lapack_int LAPACKE_zgelss( int matrix_order, lapack_int m, lapack_int n,
                           lapack_int nrhs, lapack_complex_double* a,
                           lapack_int lda, lapack_complex_double* b,
                           lapack_int ldb, double* s, double rcond,
                           lapack_int* rank );

lapack_int LAPACKE_sgelsy( int matrix_order, lapack_int m, lapack_int n,
                           lapack_int nrhs, float* a, lapack_int lda, float* b,
                           lapack_int ldb, lapack_int* jpvt, float rcond,
                           lapack_int* rank );
lapack_int LAPACKE_dgelsy( int matrix_order, lapack_int m, lapack_int n,
                           lapack_int nrhs, double* a, lapack_int lda,
                           double* b, lapack_int ldb, lapack_int* jpvt,
                           double rcond, lapack_int* rank );
lapack_int LAPACKE_cgelsy( int matrix_order, lapack_int m, lapack_int n,
                           lapack_int nrhs, lapack_complex_float* a,
                           lapack_int lda, lapack_complex_float* b,
                           lapack_int ldb, lapack_int* jpvt, float rcond,
                           lapack_int* rank );
lapack_int LAPACKE_zgelsy( int matrix_order, lapack_int m, lapack_int n,
                           lapack_int nrhs, lapack_complex_double* a,
                           lapack_int lda, lapack_complex_double* b,
                           lapack_int ldb, lapack_int* jpvt, double rcond,
                           lapack_int* rank );

lapack_int LAPACKE_sgeqlf( int matrix_order, lapack_int m, lapack_int n,
                           float* a, lapack_int lda, float* tau );
lapack_int LAPACKE_dgeqlf( int matrix_order, lapack_int m, lapack_int n,
                           double* a, lapack_int lda, double* tau );
lapack_int LAPACKE_cgeqlf( int matrix_order, lapack_int m, lapack_int n,
                           lapack_complex_float* a, lapack_int lda,
                           lapack_complex_float* tau );
lapack_int LAPACKE_zgeqlf( int matrix_order, lapack_int m, lapack_int n,
                           lapack_complex_double* a, lapack_int lda,
                           lapack_complex_double* tau );

lapack_int LAPACKE_sgeqp3( int matrix_order, lapack_int m, lapack_int n,
                           float* a, lapack_int lda, lapack_int* jpvt,
                           float* tau );
lapack_int LAPACKE_dgeqp3( int matrix_order, lapack_int m, lapack_int n,
                           double* a, lapack_int lda, lapack_int* jpvt,
                           double* tau );
lapack_int LAPACKE_cgeqp3( int matrix_order, lapack_int m, lapack_int n,
                           lapack_complex_float* a, lapack_int lda,
                           lapack_int* jpvt, lapack_complex_float* tau );
lapack_int LAPACKE_zgeqp3( int matrix_order, lapack_int m, lapack_int n,
                           lapack_complex_double* a, lapack_int lda,
                           lapack_int* jpvt, lapack_complex_double* tau );

lapack_int LAPACKE_sgeqpf( int matrix_order, lapack_int m, lapack_int n,
                           float* a, lapack_int lda, lapack_int* jpvt,
                           float* tau );
lapack_int LAPACKE_dgeqpf( int matrix_order, lapack_int m, lapack_int n,
                           double* a, lapack_int lda, lapack_int* jpvt,
                           double* tau );
lapack_int LAPACKE_cgeqpf( int matrix_order, lapack_int m, lapack_int n,
                           lapack_complex_float* a, lapack_int lda,
                           lapack_int* jpvt, lapack_complex_float* tau );
lapack_int LAPACKE_zgeqpf( int matrix_order, lapack_int m, lapack_int n,
                           lapack_complex_double* a, lapack_int lda,
                           lapack_int* jpvt, lapack_complex_double* tau );

lapack_int LAPACKE_sgeqrf( int matrix_order, lapack_int m, lapack_int n,
                           float* a, lapack_int lda, float* tau );
lapack_int LAPACKE_dgeqrf( int matrix_order, lapack_int m, lapack_int n,
                           double* a, lapack_int lda, double* tau );
lapack_int LAPACKE_cgeqrf( int matrix_order, lapack_int m, lapack_int n,
                           lapack_complex_float* a, lapack_int lda,
                           lapack_complex_float* tau );
lapack_int LAPACKE_zgeqrf( int matrix_order, lapack_int m, lapack_int n,
                           lapack_complex_double* a, lapack_int lda,
                           lapack_complex_double* tau );

lapack_int LAPACKE_sgeqrfp( int matrix_order, lapack_int m, lapack_int n,
                            float* a, lapack_int lda, float* tau );
lapack_int LAPACKE_dgeqrfp( int matrix_order, lapack_int m, lapack_int n,
                            double* a, lapack_int lda, double* tau );
lapack_int LAPACKE_cgeqrfp( int matrix_order, lapack_int m, lapack_int n,
                            lapack_complex_float* a, lapack_int lda,
                            lapack_complex_float* tau );
lapack_int LAPACKE_zgeqrfp( int matrix_order, lapack_int m, lapack_int n,
                            lapack_complex_double* a, lapack_int lda,
                            lapack_complex_double* tau );

lapack_int LAPACKE_sgerfs( int matrix_order, char trans, lapack_int n,
                           lapack_int nrhs, const float* a, lapack_int lda,
                           const float* af, lapack_int ldaf,
                           const lapack_int* ipiv, const float* b,
                           lapack_int ldb, float* x, lapack_int ldx,
                           float* ferr, float* berr );
lapack_int LAPACKE_dgerfs( int matrix_order, char trans, lapack_int n,
                           lapack_int nrhs, const double* a, lapack_int lda,
                           const double* af, lapack_int ldaf,
                           const lapack_int* ipiv, const double* b,
                           lapack_int ldb, double* x, lapack_int ldx,
                           double* ferr, double* berr );
lapack_int LAPACKE_cgerfs( int matrix_order, char trans, lapack_int n,
                           lapack_int nrhs, const lapack_complex_float* a,
                           lapack_int lda, const lapack_complex_float* af,
                           lapack_int ldaf, const lapack_int* ipiv,
                           const lapack_complex_float* b, lapack_int ldb,
                           lapack_complex_float* x, lapack_int ldx, float* ferr,
                           float* berr );
lapack_int LAPACKE_zgerfs( int matrix_order, char trans, lapack_int n,
                           lapack_int nrhs, const lapack_complex_double* a,
                           lapack_int lda, const lapack_complex_double* af,
                           lapack_int ldaf, const lapack_int* ipiv,
                           const lapack_complex_double* b, lapack_int ldb,
                           lapack_complex_double* x, lapack_int ldx,
                           double* ferr, double* berr );

lapack_int LAPACKE_sgerfsx( int matrix_order, char trans, char equed,
                            lapack_int n, lapack_int nrhs, const float* a,
                            lapack_int lda, const float* af, lapack_int ldaf,
                            const lapack_int* ipiv, const float* r,
                            const float* c, const float* b, lapack_int ldb,
                            float* x, lapack_int ldx, float* rcond, float* berr,
                            lapack_int n_err_bnds, float* err_bnds_norm,
                            float* err_bnds_comp, lapack_int nparams,
                            float* params );
lapack_int LAPACKE_dgerfsx( int matrix_order, char trans, char equed,
                            lapack_int n, lapack_int nrhs, const double* a,
                            lapack_int lda, const double* af, lapack_int ldaf,
                            const lapack_int* ipiv, const double* r,
                            const double* c, const double* b, lapack_int ldb,
                            double* x, lapack_int ldx, double* rcond,
                            double* berr, lapack_int n_err_bnds,
                            double* err_bnds_norm, double* err_bnds_comp,
                            lapack_int nparams, double* params );
lapack_int LAPACKE_cgerfsx( int matrix_order, char trans, char equed,
                            lapack_int n, lapack_int nrhs,
                            const lapack_complex_float* a, lapack_int lda,
                            const lapack_complex_float* af, lapack_int ldaf,
                            const lapack_int* ipiv, const float* r,
                            const float* c, const lapack_complex_float* b,
                            lapack_int ldb, lapack_complex_float* x,
                            lapack_int ldx, float* rcond, float* berr,
                            lapack_int n_err_bnds, float* err_bnds_norm,
                            float* err_bnds_comp, lapack_int nparams,
                            float* params );
lapack_int LAPACKE_zgerfsx( int matrix_order, char trans, char equed,
                            lapack_int n, lapack_int nrhs,
                            const lapack_complex_double* a, lapack_int lda,
                            const lapack_complex_double* af, lapack_int ldaf,
                            const lapack_int* ipiv, const double* r,
                            const double* c, const lapack_complex_double* b,
                            lapack_int ldb, lapack_complex_double* x,
                            lapack_int ldx, double* rcond, double* berr,
                            lapack_int n_err_bnds, double* err_bnds_norm,
                            double* err_bnds_comp, lapack_int nparams,
                            double* params );

lapack_int LAPACKE_sgerqf( int matrix_order, lapack_int m, lapack_int n,
                           float* a, lapack_int lda, float* tau );
lapack_int LAPACKE_dgerqf( int matrix_order, lapack_int m, lapack_int n,
                           double* a, lapack_int lda, double* tau );
lapack_int LAPACKE_cgerqf( int matrix_order, lapack_int m, lapack_int n,
                           lapack_complex_float* a, lapack_int lda,
                           lapack_complex_float* tau );
lapack_int LAPACKE_zgerqf( int matrix_order, lapack_int m, lapack_int n,
                           lapack_complex_double* a, lapack_int lda,
                           lapack_complex_double* tau );

lapack_int LAPACKE_sgesdd( int matrix_order, char jobz, lapack_int m,
                           lapack_int n, float* a, lapack_int lda, float* s,
                           float* u, lapack_int ldu, float* vt,
                           lapack_int ldvt );
lapack_int LAPACKE_dgesdd( int matrix_order, char jobz, lapack_int m,
                           lapack_int n, double* a, lapack_int lda, double* s,
                           double* u, lapack_int ldu, double* vt,
                           lapack_int ldvt );
lapack_int LAPACKE_cgesdd( int matrix_order, char jobz, lapack_int m,
                           lapack_int n, lapack_complex_float* a,
                           lapack_int lda, float* s, lapack_complex_float* u,
                           lapack_int ldu, lapack_complex_float* vt,
                           lapack_int ldvt );
lapack_int LAPACKE_zgesdd( int matrix_order, char jobz, lapack_int m,
                           lapack_int n, lapack_complex_double* a,
                           lapack_int lda, double* s, lapack_complex_double* u,
                           lapack_int ldu, lapack_complex_double* vt,
                           lapack_int ldvt );

lapack_int LAPACKE_sgesv( int matrix_order, lapack_int n, lapack_int nrhs,
                          float* a, lapack_int lda, lapack_int* ipiv, float* b,
                          lapack_int ldb );
lapack_int LAPACKE_dgesv( int matrix_order, lapack_int n, lapack_int nrhs,
                          double* a, lapack_int lda, lapack_int* ipiv,
                          double* b, lapack_int ldb );
lapack_int LAPACKE_cgesv( int matrix_order, lapack_int n, lapack_int nrhs,
                          lapack_complex_float* a, lapack_int lda,
                          lapack_int* ipiv, lapack_complex_float* b,
                          lapack_int ldb );
lapack_int LAPACKE_zgesv( int matrix_order, lapack_int n, lapack_int nrhs,
                          lapack_complex_double* a, lapack_int lda,
                          lapack_int* ipiv, lapack_complex_double* b,
                          lapack_int ldb );
lapack_int LAPACKE_dsgesv( int matrix_order, lapack_int n, lapack_int nrhs,
                           double* a, lapack_int lda, lapack_int* ipiv,
                           double* b, lapack_int ldb, double* x, lapack_int ldx,
                           lapack_int* iter );
lapack_int LAPACKE_zcgesv( int matrix_order, lapack_int n, lapack_int nrhs,
                           lapack_complex_double* a, lapack_int lda,
                           lapack_int* ipiv, lapack_complex_double* b,
                           lapack_int ldb, lapack_complex_double* x,
                           lapack_int ldx, lapack_int* iter );

lapack_int LAPACKE_sgesvd( int matrix_order, char jobu, char jobvt,
                           lapack_int m, lapack_int n, float* a, lapack_int lda,
                           float* s, float* u, lapack_int ldu, float* vt,
                           lapack_int ldvt, float* superb );
lapack_int LAPACKE_dgesvd( int matrix_order, char jobu, char jobvt,
                           lapack_int m, lapack_int n, double* a,
                           lapack_int lda, double* s, double* u, lapack_int ldu,
                           double* vt, lapack_int ldvt, double* superb );
lapack_int LAPACKE_cgesvd( int matrix_order, char jobu, char jobvt,
                           lapack_int m, lapack_int n, lapack_complex_float* a,
                           lapack_int lda, float* s, lapack_complex_float* u,
                           lapack_int ldu, lapack_complex_float* vt,
                           lapack_int ldvt, float* superb );
lapack_int LAPACKE_zgesvd( int matrix_order, char jobu, char jobvt,
                           lapack_int m, lapack_int n, lapack_complex_double* a,
                           lapack_int lda, double* s, lapack_complex_double* u,
                           lapack_int ldu, lapack_complex_double* vt,
                           lapack_int ldvt, double* superb );

lapack_int LAPACKE_sgesvj( int matrix_order, char joba, char jobu, char jobv,
                           lapack_int m, lapack_int n, float* a, lapack_int lda,
                           float* sva, lapack_int mv, float* v, lapack_int ldv,
                           float* stat );
lapack_int LAPACKE_dgesvj( int matrix_order, char joba, char jobu, char jobv,
                           lapack_int m, lapack_int n, double* a,
                           lapack_int lda, double* sva, lapack_int mv,
                           double* v, lapack_int ldv, double* stat );

lapack_int LAPACKE_sgesvx( int matrix_order, char fact, char trans,
                           lapack_int n, lapack_int nrhs, float* a,
                           lapack_int lda, float* af, lapack_int ldaf,
                           lapack_int* ipiv, char* equed, float* r, float* c,
                           float* b, lapack_int ldb, float* x, lapack_int ldx,
                           float* rcond, float* ferr, float* berr,
                           float* rpivot );
lapack_int LAPACKE_dgesvx( int matrix_order, char fact, char trans,
                           lapack_int n, lapack_int nrhs, double* a,
                           lapack_int lda, double* af, lapack_int ldaf,
                           lapack_int* ipiv, char* equed, double* r, double* c,
                           double* b, lapack_int ldb, double* x, lapack_int ldx,
                           double* rcond, double* ferr, double* berr,
                           double* rpivot );
lapack_int LAPACKE_cgesvx( int matrix_order, char fact, char trans,
                           lapack_int n, lapack_int nrhs,
                           lapack_complex_float* a, lapack_int lda,
                           lapack_complex_float* af, lapack_int ldaf,
                           lapack_int* ipiv, char* equed, float* r, float* c,
                           lapack_complex_float* b, lapack_int ldb,
                           lapack_complex_float* x, lapack_int ldx,
                           float* rcond, float* ferr, float* berr,
                           float* rpivot );
lapack_int LAPACKE_zgesvx( int matrix_order, char fact, char trans,
                           lapack_int n, lapack_int nrhs,
                           lapack_complex_double* a, lapack_int lda,
                           lapack_complex_double* af, lapack_int ldaf,
                           lapack_int* ipiv, char* equed, double* r, double* c,
                           lapack_complex_double* b, lapack_int ldb,
                           lapack_complex_double* x, lapack_int ldx,
                           double* rcond, double* ferr, double* berr,
                           double* rpivot );

lapack_int LAPACKE_sgesvxx( int matrix_order, char fact, char trans,
                            lapack_int n, lapack_int nrhs, float* a,
                            lapack_int lda, float* af, lapack_int ldaf,
                            lapack_int* ipiv, char* equed, float* r, float* c,
                            float* b, lapack_int ldb, float* x, lapack_int ldx,
                            float* rcond, float* rpvgrw, float* berr,
                            lapack_int n_err_bnds, float* err_bnds_norm,
                            float* err_bnds_comp, lapack_int nparams,
                            float* params );
lapack_int LAPACKE_dgesvxx( int matrix_order, char fact, char trans,
                            lapack_int n, lapack_int nrhs, double* a,
                            lapack_int lda, double* af, lapack_int ldaf,
                            lapack_int* ipiv, char* equed, double* r, double* c,
                            double* b, lapack_int ldb, double* x,
                            lapack_int ldx, double* rcond, double* rpvgrw,
                            double* berr, lapack_int n_err_bnds,
                            double* err_bnds_norm, double* err_bnds_comp,
                            lapack_int nparams, double* params );
lapack_int LAPACKE_cgesvxx( int matrix_order, char fact, char trans,
                            lapack_int n, lapack_int nrhs,
                            lapack_complex_float* a, lapack_int lda,
                            lapack_complex_float* af, lapack_int ldaf,
                            lapack_int* ipiv, char* equed, float* r, float* c,
                            lapack_complex_float* b, lapack_int ldb,
                            lapack_complex_float* x, lapack_int ldx,
                            float* rcond, float* rpvgrw, float* berr,
                            lapack_int n_err_bnds, float* err_bnds_norm,
                            float* err_bnds_comp, lapack_int nparams,
                            float* params );
lapack_int LAPACKE_zgesvxx( int matrix_order, char fact, char trans,
                            lapack_int n, lapack_int nrhs,
                            lapack_complex_double* a, lapack_int lda,
                            lapack_complex_double* af, lapack_int ldaf,
                            lapack_int* ipiv, char* equed, double* r, double* c,
                            lapack_complex_double* b, lapack_int ldb,
                            lapack_complex_double* x, lapack_int ldx,
                            double* rcond, double* rpvgrw, double* berr,
                            lapack_int n_err_bnds, double* err_bnds_norm,
                            double* err_bnds_comp, lapack_int nparams,
                            double* params );

lapack_int LAPACKE_sgetrf( int matrix_order, lapack_int m, lapack_int n,
                           float* a, lapack_int lda, lapack_int* ipiv );
lapack_int LAPACKE_dgetrf( int matrix_order, lapack_int m, lapack_int n,
                           double* a, lapack_int lda, lapack_int* ipiv );
lapack_int LAPACKE_cgetrf( int matrix_order, lapack_int m, lapack_int n,
                           lapack_complex_float* a, lapack_int lda,
                           lapack_int* ipiv );
lapack_int LAPACKE_zgetrf( int matrix_order, lapack_int m, lapack_int n,
                           lapack_complex_double* a, lapack_int lda,
                           lapack_int* ipiv );

lapack_int LAPACKE_sgetri( int matrix_order, lapack_int n, float* a,
                           lapack_int lda, const lapack_int* ipiv );
lapack_int LAPACKE_dgetri( int matrix_order, lapack_int n, double* a,
                           lapack_int lda, const lapack_int* ipiv );
lapack_int LAPACKE_cgetri( int matrix_order, lapack_int n,
                           lapack_complex_float* a, lapack_int lda,
                           const lapack_int* ipiv );
lapack_int LAPACKE_zgetri( int matrix_order, lapack_int n,
                           lapack_complex_double* a, lapack_int lda,
                           const lapack_int* ipiv );

lapack_int LAPACKE_sgetrs( int matrix_order, char trans, lapack_int n,
                           lapack_int nrhs, const float* a, lapack_int lda,
                           const lapack_int* ipiv, float* b, lapack_int ldb );
lapack_int LAPACKE_dgetrs( int matrix_order, char trans, lapack_int n,
                           lapack_int nrhs, const double* a, lapack_int lda,
                           const lapack_int* ipiv, double* b, lapack_int ldb );
lapack_int LAPACKE_cgetrs( int matrix_order, char trans, lapack_int n,
                           lapack_int nrhs, const lapack_complex_float* a,
                           lapack_int lda, const lapack_int* ipiv,
                           lapack_complex_float* b, lapack_int ldb );
lapack_int LAPACKE_zgetrs( int matrix_order, char trans, lapack_int n,
                           lapack_int nrhs, const lapack_complex_double* a,
                           lapack_int lda, const lapack_int* ipiv,
                           lapack_complex_double* b, lapack_int ldb );

lapack_int LAPACKE_sggbak( int matrix_order, char job, char side, lapack_int n,
                           lapack_int ilo, lapack_int ihi, const float* lscale,
                           const float* rscale, lapack_int m, float* v,
                           lapack_int ldv );
lapack_int LAPACKE_dggbak( int matrix_order, char job, char side, lapack_int n,
                           lapack_int ilo, lapack_int ihi, const double* lscale,
                           const double* rscale, lapack_int m, double* v,
                           lapack_int ldv );
lapack_int LAPACKE_cggbak( int matrix_order, char job, char side, lapack_int n,
                           lapack_int ilo, lapack_int ihi, const float* lscale,
                           const float* rscale, lapack_int m,
                           lapack_complex_float* v, lapack_int ldv );
lapack_int LAPACKE_zggbak( int matrix_order, char job, char side, lapack_int n,
                           lapack_int ilo, lapack_int ihi, const double* lscale,
                           const double* rscale, lapack_int m,
                           lapack_complex_double* v, lapack_int ldv );

lapack_int LAPACKE_sggbal( int matrix_order, char job, lapack_int n, float* a,
                           lapack_int lda, float* b, lapack_int ldb,
                           lapack_int* ilo, lapack_int* ihi, float* lscale,
                           float* rscale );
lapack_int LAPACKE_dggbal( int matrix_order, char job, lapack_int n, double* a,
                           lapack_int lda, double* b, lapack_int ldb,
                           lapack_int* ilo, lapack_int* ihi, double* lscale,
                           double* rscale );
lapack_int LAPACKE_cggbal( int matrix_order, char job, lapack_int n,
                           lapack_complex_float* a, lapack_int lda,
                           lapack_complex_float* b, lapack_int ldb,
                           lapack_int* ilo, lapack_int* ihi, float* lscale,
                           float* rscale );
lapack_int LAPACKE_zggbal( int matrix_order, char job, lapack_int n,
                           lapack_complex_double* a, lapack_int lda,
                           lapack_complex_double* b, lapack_int ldb,
                           lapack_int* ilo, lapack_int* ihi, double* lscale,
                           double* rscale );

lapack_int LAPACKE_sgges( int matrix_order, char jobvsl, char jobvsr, char sort,
                          LAPACK_S_SELECT3 selctg, lapack_int n, float* a,
                          lapack_int lda, float* b, lapack_int ldb,
                          lapack_int* sdim, float* alphar, float* alphai,
                          float* beta, float* vsl, lapack_int ldvsl, float* vsr,
                          lapack_int ldvsr );
lapack_int LAPACKE_dgges( int matrix_order, char jobvsl, char jobvsr, char sort,
                          LAPACK_D_SELECT3 selctg, lapack_int n, double* a,
                          lapack_int lda, double* b, lapack_int ldb,
                          lapack_int* sdim, double* alphar, double* alphai,
                          double* beta, double* vsl, lapack_int ldvsl,
                          double* vsr, lapack_int ldvsr );
lapack_int LAPACKE_cgges( int matrix_order, char jobvsl, char jobvsr, char sort,
                          LAPACK_C_SELECT2 selctg, lapack_int n,
                          lapack_complex_float* a, lapack_int lda,
                          lapack_complex_float* b, lapack_int ldb,
                          lapack_int* sdim, lapack_complex_float* alpha,
                          lapack_complex_float* beta, lapack_complex_float* vsl,
                          lapack_int ldvsl, lapack_complex_float* vsr,
                          lapack_int ldvsr );
lapack_int LAPACKE_zgges( int matrix_order, char jobvsl, char jobvsr, char sort,
                          LAPACK_Z_SELECT2 selctg, lapack_int n,
                          lapack_complex_double* a, lapack_int lda,
                          lapack_complex_double* b, lapack_int ldb,
                          lapack_int* sdim, lapack_complex_double* alpha,
                          lapack_complex_double* beta,
                          lapack_complex_double* vsl, lapack_int ldvsl,
                          lapack_complex_double* vsr, lapack_int ldvsr );

lapack_int LAPACKE_sggesx( int matrix_order, char jobvsl, char jobvsr,
                           char sort, LAPACK_S_SELECT3 selctg, char sense,
                           lapack_int n, float* a, lapack_int lda, float* b,
                           lapack_int ldb, lapack_int* sdim, float* alphar,
                           float* alphai, float* beta, float* vsl,
                           lapack_int ldvsl, float* vsr, lapack_int ldvsr,
                           float* rconde, float* rcondv );
lapack_int LAPACKE_dggesx( int matrix_order, char jobvsl, char jobvsr,
                           char sort, LAPACK_D_SELECT3 selctg, char sense,
                           lapack_int n, double* a, lapack_int lda, double* b,
                           lapack_int ldb, lapack_int* sdim, double* alphar,
                           double* alphai, double* beta, double* vsl,
                           lapack_int ldvsl, double* vsr, lapack_int ldvsr,
                           double* rconde, double* rcondv );
lapack_int LAPACKE_cggesx( int matrix_order, char jobvsl, char jobvsr,
                           char sort, LAPACK_C_SELECT2 selctg, char sense,
                           lapack_int n, lapack_complex_float* a,
                           lapack_int lda, lapack_complex_float* b,
                           lapack_int ldb, lapack_int* sdim,
                           lapack_complex_float* alpha,
                           lapack_complex_float* beta,
                           lapack_complex_float* vsl, lapack_int ldvsl,
                           lapack_complex_float* vsr, lapack_int ldvsr,
                           float* rconde, float* rcondv );
lapack_int LAPACKE_zggesx( int matrix_order, char jobvsl, char jobvsr,
                           char sort, LAPACK_Z_SELECT2 selctg, char sense,
                           lapack_int n, lapack_complex_double* a,
                           lapack_int lda, lapack_complex_double* b,
                           lapack_int ldb, lapack_int* sdim,
                           lapack_complex_double* alpha,
                           lapack_complex_double* beta,
                           lapack_complex_double* vsl, lapack_int ldvsl,
                           lapack_complex_double* vsr, lapack_int ldvsr,
                           double* rconde, double* rcondv );

lapack_int LAPACKE_sggev( int matrix_order, char jobvl, char jobvr,
                          lapack_int n, float* a, lapack_int lda, float* b,
                          lapack_int ldb, float* alphar, float* alphai,
                          float* beta, float* vl, lapack_int ldvl, float* vr,
                          lapack_int ldvr );
lapack_int LAPACKE_dggev( int matrix_order, char jobvl, char jobvr,
                          lapack_int n, double* a, lapack_int lda, double* b,
                          lapack_int ldb, double* alphar, double* alphai,
                          double* beta, double* vl, lapack_int ldvl, double* vr,
                          lapack_int ldvr );
lapack_int LAPACKE_cggev( int matrix_order, char jobvl, char jobvr,
                          lapack_int n, lapack_complex_float* a, lapack_int lda,
                          lapack_complex_float* b, lapack_int ldb,
                          lapack_complex_float* alpha,
                          lapack_complex_float* beta, lapack_complex_float* vl,
                          lapack_int ldvl, lapack_complex_float* vr,
                          lapack_int ldvr );
lapack_int LAPACKE_zggev( int matrix_order, char jobvl, char jobvr,
                          lapack_int n, lapack_complex_double* a,
                          lapack_int lda, lapack_complex_double* b,
                          lapack_int ldb, lapack_complex_double* alpha,
                          lapack_complex_double* beta,
                          lapack_complex_double* vl, lapack_int ldvl,
                          lapack_complex_double* vr, lapack_int ldvr );

lapack_int LAPACKE_sggevx( int matrix_order, char balanc, char jobvl,
                           char jobvr, char sense, lapack_int n, float* a,
                           lapack_int lda, float* b, lapack_int ldb,
                           float* alphar, float* alphai, float* beta, float* vl,
                           lapack_int ldvl, float* vr, lapack_int ldvr,
                           lapack_int* ilo, lapack_int* ihi, float* lscale,
                           float* rscale, float* abnrm, float* bbnrm,
                           float* rconde, float* rcondv );
lapack_int LAPACKE_dggevx( int matrix_order, char balanc, char jobvl,
                           char jobvr, char sense, lapack_int n, double* a,
                           lapack_int lda, double* b, lapack_int ldb,
                           double* alphar, double* alphai, double* beta,
                           double* vl, lapack_int ldvl, double* vr,
                           lapack_int ldvr, lapack_int* ilo, lapack_int* ihi,
                           double* lscale, double* rscale, double* abnrm,
                           double* bbnrm, double* rconde, double* rcondv );
lapack_int LAPACKE_cggevx( int matrix_order, char balanc, char jobvl,
                           char jobvr, char sense, lapack_int n,
                           lapack_complex_float* a, lapack_int lda,
                           lapack_complex_float* b, lapack_int ldb,
                           lapack_complex_float* alpha,
                           lapack_complex_float* beta, lapack_complex_float* vl,
                           lapack_int ldvl, lapack_complex_float* vr,
                           lapack_int ldvr, lapack_int* ilo, lapack_int* ihi,
                           float* lscale, float* rscale, float* abnrm,
                           float* bbnrm, float* rconde, float* rcondv );
lapack_int LAPACKE_zggevx( int matrix_order, char balanc, char jobvl,
                           char jobvr, char sense, lapack_int n,
                           lapack_complex_double* a, lapack_int lda,
                           lapack_complex_double* b, lapack_int ldb,
                           lapack_complex_double* alpha,
                           lapack_complex_double* beta,
                           lapack_complex_double* vl, lapack_int ldvl,
                           lapack_complex_double* vr, lapack_int ldvr,
                           lapack_int* ilo, lapack_int* ihi, double* lscale,
                           double* rscale, double* abnrm, double* bbnrm,
                           double* rconde, double* rcondv );

lapack_int LAPACKE_sggglm( int matrix_order, lapack_int n, lapack_int m,
                           lapack_int p, float* a, lapack_int lda, float* b,
                           lapack_int ldb, float* d, float* x, float* y );
lapack_int LAPACKE_dggglm( int matrix_order, lapack_int n, lapack_int m,
                           lapack_int p, double* a, lapack_int lda, double* b,
                           lapack_int ldb, double* d, double* x, double* y );
lapack_int LAPACKE_cggglm( int matrix_order, lapack_int n, lapack_int m,
                           lapack_int p, lapack_complex_float* a,
                           lapack_int lda, lapack_complex_float* b,
                           lapack_int ldb, lapack_complex_float* d,
                           lapack_complex_float* x, lapack_complex_float* y );
lapack_int LAPACKE_zggglm( int matrix_order, lapack_int n, lapack_int m,
                           lapack_int p, lapack_complex_double* a,
                           lapack_int lda, lapack_complex_double* b,
                           lapack_int ldb, lapack_complex_double* d,
                           lapack_complex_double* x, lapack_complex_double* y );

lapack_int LAPACKE_sgghrd( int matrix_order, char compq, char compz,
                           lapack_int n, lapack_int ilo, lapack_int ihi,
                           float* a, lapack_int lda, float* b, lapack_int ldb,
                           float* q, lapack_int ldq, float* z, lapack_int ldz );
lapack_int LAPACKE_dgghrd( int matrix_order, char compq, char compz,
                           lapack_int n, lapack_int ilo, lapack_int ihi,
                           double* a, lapack_int lda, double* b, lapack_int ldb,
                           double* q, lapack_int ldq, double* z,
                           lapack_int ldz );
lapack_int LAPACKE_cgghrd( int matrix_order, char compq, char compz,
                           lapack_int n, lapack_int ilo, lapack_int ihi,
                           lapack_complex_float* a, lapack_int lda,
                           lapack_complex_float* b, lapack_int ldb,
                           lapack_complex_float* q, lapack_int ldq,
                           lapack_complex_float* z, lapack_int ldz );
lapack_int LAPACKE_zgghrd( int matrix_order, char compq, char compz,
                           lapack_int n, lapack_int ilo, lapack_int ihi,
                           lapack_complex_double* a, lapack_int lda,
                           lapack_complex_double* b, lapack_int ldb,
                           lapack_complex_double* q, lapack_int ldq,
                           lapack_complex_double* z, lapack_int ldz );

lapack_int LAPACKE_sgglse( int matrix_order, lapack_int m, lapack_int n,
                           lapack_int p, float* a, lapack_int lda, float* b,
                           lapack_int ldb, float* c, float* d, float* x );
lapack_int LAPACKE_dgglse( int matrix_order, lapack_int m, lapack_int n,
                           lapack_int p, double* a, lapack_int lda, double* b,
                           lapack_int ldb, double* c, double* d, double* x );
lapack_int LAPACKE_cgglse( int matrix_order, lapack_int m, lapack_int n,
                           lapack_int p, lapack_complex_float* a,
                           lapack_int lda, lapack_complex_float* b,
                           lapack_int ldb, lapack_complex_float* c,
                           lapack_complex_float* d, lapack_complex_float* x );
lapack_int LAPACKE_zgglse( int matrix_order, lapack_int m, lapack_int n,
                           lapack_int p, lapack_complex_double* a,
                           lapack_int lda, lapack_complex_double* b,
                           lapack_int ldb, lapack_complex_double* c,
                           lapack_complex_double* d, lapack_complex_double* x );

lapack_int LAPACKE_sggqrf( int matrix_order, lapack_int n, lapack_int m,
                           lapack_int p, float* a, lapack_int lda, float* taua,
                           float* b, lapack_int ldb, float* taub );
lapack_int LAPACKE_dggqrf( int matrix_order, lapack_int n, lapack_int m,
                           lapack_int p, double* a, lapack_int lda,
                           double* taua, double* b, lapack_int ldb,
                           double* taub );
lapack_int LAPACKE_cggqrf( int matrix_order, lapack_int n, lapack_int m,
                           lapack_int p, lapack_complex_float* a,
                           lapack_int lda, lapack_complex_float* taua,
                           lapack_complex_float* b, lapack_int ldb,
                           lapack_complex_float* taub );
lapack_int LAPACKE_zggqrf( int matrix_order, lapack_int n, lapack_int m,
                           lapack_int p, lapack_complex_double* a,
                           lapack_int lda, lapack_complex_double* taua,
                           lapack_complex_double* b, lapack_int ldb,
                           lapack_complex_double* taub );

lapack_int LAPACKE_sggrqf( int matrix_order, lapack_int m, lapack_int p,
                           lapack_int n, float* a, lapack_int lda, float* taua,
                           float* b, lapack_int ldb, float* taub );
lapack_int LAPACKE_dggrqf( int matrix_order, lapack_int m, lapack_int p,
                           lapack_int n, double* a, lapack_int lda,
                           double* taua, double* b, lapack_int ldb,
                           double* taub );
lapack_int LAPACKE_cggrqf( int matrix_order, lapack_int m, lapack_int p,
                           lapack_int n, lapack_complex_float* a,
                           lapack_int lda, lapack_complex_float* taua,
                           lapack_complex_float* b, lapack_int ldb,
                           lapack_complex_float* taub );
lapack_int LAPACKE_zggrqf( int matrix_order, lapack_int m, lapack_int p,
                           lapack_int n, lapack_complex_double* a,
                           lapack_int lda, lapack_complex_double* taua,
                           lapack_complex_double* b, lapack_int ldb,
                           lapack_complex_double* taub );

lapack_int LAPACKE_sggsvd( int matrix_order, char jobu, char jobv, char jobq,
                           lapack_int m, lapack_int n, lapack_int p,
                           lapack_int* k, lapack_int* l, float* a,
                           lapack_int lda, float* b, lapack_int ldb,
                           float* alpha, float* beta, float* u, lapack_int ldu,
                           float* v, lapack_int ldv, float* q, lapack_int ldq,
                           lapack_int* iwork );
lapack_int LAPACKE_dggsvd( int matrix_order, char jobu, char jobv, char jobq,
                           lapack_int m, lapack_int n, lapack_int p,
                           lapack_int* k, lapack_int* l, double* a,
                           lapack_int lda, double* b, lapack_int ldb,
                           double* alpha, double* beta, double* u,
                           lapack_int ldu, double* v, lapack_int ldv, double* q,
                           lapack_int ldq, lapack_int* iwork );
lapack_int LAPACKE_cggsvd( int matrix_order, char jobu, char jobv, char jobq,
                           lapack_int m, lapack_int n, lapack_int p,
                           lapack_int* k, lapack_int* l,
                           lapack_complex_float* a, lapack_int lda,
                           lapack_complex_float* b, lapack_int ldb,
                           float* alpha, float* beta, lapack_complex_float* u,
                           lapack_int ldu, lapack_complex_float* v,
                           lapack_int ldv, lapack_complex_float* q,
                           lapack_int ldq, lapack_int* iwork );
lapack_int LAPACKE_zggsvd( int matrix_order, char jobu, char jobv, char jobq,
                           lapack_int m, lapack_int n, lapack_int p,
                           lapack_int* k, lapack_int* l,
                           lapack_complex_double* a, lapack_int lda,
                           lapack_complex_double* b, lapack_int ldb,
                           double* alpha, double* beta,
                           lapack_complex_double* u, lapack_int ldu,
                           lapack_complex_double* v, lapack_int ldv,
                           lapack_complex_double* q, lapack_int ldq,
                           lapack_int* iwork );

lapack_int LAPACKE_sggsvp( int matrix_order, char jobu, char jobv, char jobq,
                           lapack_int m, lapack_int p, lapack_int n, float* a,
                           lapack_int lda, float* b, lapack_int ldb, float tola,
                           float tolb, lapack_int* k, lapack_int* l, float* u,
                           lapack_int ldu, float* v, lapack_int ldv, float* q,
                           lapack_int ldq );
lapack_int LAPACKE_dggsvp( int matrix_order, char jobu, char jobv, char jobq,
                           lapack_int m, lapack_int p, lapack_int n, double* a,
                           lapack_int lda, double* b, lapack_int ldb,
                           double tola, double tolb, lapack_int* k,
                           lapack_int* l, double* u, lapack_int ldu, double* v,
                           lapack_int ldv, double* q, lapack_int ldq );
lapack_int LAPACKE_cggsvp( int matrix_order, char jobu, char jobv, char jobq,
                           lapack_int m, lapack_int p, lapack_int n,
                           lapack_complex_float* a, lapack_int lda,
                           lapack_complex_float* b, lapack_int ldb, float tola,
                           float tolb, lapack_int* k, lapack_int* l,
                           lapack_complex_float* u, lapack_int ldu,
                           lapack_complex_float* v, lapack_int ldv,
                           lapack_complex_float* q, lapack_int ldq );
lapack_int LAPACKE_zggsvp( int matrix_order, char jobu, char jobv, char jobq,
                           lapack_int m, lapack_int p, lapack_int n,
                           lapack_complex_double* a, lapack_int lda,
                           lapack_complex_double* b, lapack_int ldb,
                           double tola, double tolb, lapack_int* k,
                           lapack_int* l, lapack_complex_double* u,
                           lapack_int ldu, lapack_complex_double* v,
                           lapack_int ldv, lapack_complex_double* q,
                           lapack_int ldq );

lapack_int LAPACKE_sgtcon( char norm, lapack_int n, const float* dl,
                           const float* d, const float* du, const float* du2,
                           const lapack_int* ipiv, float anorm, float* rcond );
lapack_int LAPACKE_dgtcon( char norm, lapack_int n, const double* dl,
                           const double* d, const double* du, const double* du2,
                           const lapack_int* ipiv, double anorm,
                           double* rcond );
lapack_int LAPACKE_cgtcon( char norm, lapack_int n,
                           const lapack_complex_float* dl,
                           const lapack_complex_float* d,
                           const lapack_complex_float* du,
                           const lapack_complex_float* du2,
                           const lapack_int* ipiv, float anorm, float* rcond );
lapack_int LAPACKE_zgtcon( char norm, lapack_int n,
                           const lapack_complex_double* dl,
                           const lapack_complex_double* d,
                           const lapack_complex_double* du,
                           const lapack_complex_double* du2,
                           const lapack_int* ipiv, double anorm,
                           double* rcond );

lapack_int LAPACKE_sgtrfs( int matrix_order, char trans, lapack_int n,
                           lapack_int nrhs, const float* dl, const float* d,
                           const float* du, const float* dlf, const float* df,
                           const float* duf, const float* du2,
                           const lapack_int* ipiv, const float* b,
                           lapack_int ldb, float* x, lapack_int ldx,
                           float* ferr, float* berr );
lapack_int LAPACKE_dgtrfs( int matrix_order, char trans, lapack_int n,
                           lapack_int nrhs, const double* dl, const double* d,
                           const double* du, const double* dlf,
                           const double* df, const double* duf,
                           const double* du2, const lapack_int* ipiv,
                           const double* b, lapack_int ldb, double* x,
                           lapack_int ldx, double* ferr, double* berr );
lapack_int LAPACKE_cgtrfs( int matrix_order, char trans, lapack_int n,
                           lapack_int nrhs, const lapack_complex_float* dl,
                           const lapack_complex_float* d,
                           const lapack_complex_float* du,
                           const lapack_complex_float* dlf,
                           const lapack_complex_float* df,
                           const lapack_complex_float* duf,
                           const lapack_complex_float* du2,
                           const lapack_int* ipiv,
                           const lapack_complex_float* b, lapack_int ldb,
                           lapack_complex_float* x, lapack_int ldx, float* ferr,
                           float* berr );
lapack_int LAPACKE_zgtrfs( int matrix_order, char trans, lapack_int n,
                           lapack_int nrhs, const lapack_complex_double* dl,
                           const lapack_complex_double* d,
                           const lapack_complex_double* du,
                           const lapack_complex_double* dlf,
                           const lapack_complex_double* df,
                           const lapack_complex_double* duf,
                           const lapack_complex_double* du2,
                           const lapack_int* ipiv,
                           const lapack_complex_double* b, lapack_int ldb,
                           lapack_complex_double* x, lapack_int ldx,
                           double* ferr, double* berr );

lapack_int LAPACKE_sgtsv( int matrix_order, lapack_int n, lapack_int nrhs,
                          float* dl, float* d, float* du, float* b,
                          lapack_int ldb );
lapack_int LAPACKE_dgtsv( int matrix_order, lapack_int n, lapack_int nrhs,
                          double* dl, double* d, double* du, double* b,
                          lapack_int ldb );
lapack_int LAPACKE_cgtsv( int matrix_order, lapack_int n, lapack_int nrhs,
                          lapack_complex_float* dl, lapack_complex_float* d,
                          lapack_complex_float* du, lapack_complex_float* b,
                          lapack_int ldb );
lapack_int LAPACKE_zgtsv( int matrix_order, lapack_int n, lapack_int nrhs,
                          lapack_complex_double* dl, lapack_complex_double* d,
                          lapack_complex_double* du, lapack_complex_double* b,
                          lapack_int ldb );

lapack_int LAPACKE_sgtsvx( int matrix_order, char fact, char trans,
                           lapack_int n, lapack_int nrhs, const float* dl,
                           const float* d, const float* du, float* dlf,
                           float* df, float* duf, float* du2, lapack_int* ipiv,
                           const float* b, lapack_int ldb, float* x,
                           lapack_int ldx, float* rcond, float* ferr,
                           float* berr );
lapack_int LAPACKE_dgtsvx( int matrix_order, char fact, char trans,
                           lapack_int n, lapack_int nrhs, const double* dl,
                           const double* d, const double* du, double* dlf,
                           double* df, double* duf, double* du2,
                           lapack_int* ipiv, const double* b, lapack_int ldb,
                           double* x, lapack_int ldx, double* rcond,
                           double* ferr, double* berr );
lapack_int LAPACKE_cgtsvx( int matrix_order, char fact, char trans,
                           lapack_int n, lapack_int nrhs,
                           const lapack_complex_float* dl,
                           const lapack_complex_float* d,
                           const lapack_complex_float* du,
                           lapack_complex_float* dlf, lapack_complex_float* df,
                           lapack_complex_float* duf, lapack_complex_float* du2,
                           lapack_int* ipiv, const lapack_complex_float* b,
                           lapack_int ldb, lapack_complex_float* x,
                           lapack_int ldx, float* rcond, float* ferr,
                           float* berr );
lapack_int LAPACKE_zgtsvx( int matrix_order, char fact, char trans,
                           lapack_int n, lapack_int nrhs,
                           const lapack_complex_double* dl,
                           const lapack_complex_double* d,
                           const lapack_complex_double* du,
                           lapack_complex_double* dlf,
                           lapack_complex_double* df,
                           lapack_complex_double* duf,
                           lapack_complex_double* du2, lapack_int* ipiv,
                           const lapack_complex_double* b, lapack_int ldb,
                           lapack_complex_double* x, lapack_int ldx,
                           double* rcond, double* ferr, double* berr );

lapack_int LAPACKE_sgttrf( lapack_int n, float* dl, float* d, float* du,
                           float* du2, lapack_int* ipiv );
lapack_int LAPACKE_dgttrf( lapack_int n, double* dl, double* d, double* du,
                           double* du2, lapack_int* ipiv );
lapack_int LAPACKE_cgttrf( lapack_int n, lapack_complex_float* dl,
                           lapack_complex_float* d, lapack_complex_float* du,
                           lapack_complex_float* du2, lapack_int* ipiv );
lapack_int LAPACKE_zgttrf( lapack_int n, lapack_complex_double* dl,
                           lapack_complex_double* d, lapack_complex_double* du,
                           lapack_complex_double* du2, lapack_int* ipiv );

lapack_int LAPACKE_sgttrs( int matrix_order, char trans, lapack_int n,
                           lapack_int nrhs, const float* dl, const float* d,
                           const float* du, const float* du2,
                           const lapack_int* ipiv, float* b, lapack_int ldb );
lapack_int LAPACKE_dgttrs( int matrix_order, char trans, lapack_int n,
                           lapack_int nrhs, const double* dl, const double* d,
                           const double* du, const double* du2,
                           const lapack_int* ipiv, double* b, lapack_int ldb );
lapack_int LAPACKE_cgttrs( int matrix_order, char trans, lapack_int n,
                           lapack_int nrhs, const lapack_complex_float* dl,
                           const lapack_complex_float* d,
                           const lapack_complex_float* du,
                           const lapack_complex_float* du2,
                           const lapack_int* ipiv, lapack_complex_float* b,
                           lapack_int ldb );
lapack_int LAPACKE_zgttrs( int matrix_order, char trans, lapack_int n,
                           lapack_int nrhs, const lapack_complex_double* dl,
                           const lapack_complex_double* d,
                           const lapack_complex_double* du,
                           const lapack_complex_double* du2,
                           const lapack_int* ipiv, lapack_complex_double* b,
                           lapack_int ldb );

lapack_int LAPACKE_chbev( int matrix_order, char jobz, char uplo, lapack_int n,
                          lapack_int kd, lapack_complex_float* ab,
                          lapack_int ldab, float* w, lapack_complex_float* z,
                          lapack_int ldz );
lapack_int LAPACKE_zhbev( int matrix_order, char jobz, char uplo, lapack_int n,
                          lapack_int kd, lapack_complex_double* ab,
                          lapack_int ldab, double* w, lapack_complex_double* z,
                          lapack_int ldz );

lapack_int LAPACKE_chbevd( int matrix_order, char jobz, char uplo, lapack_int n,
                           lapack_int kd, lapack_complex_float* ab,
                           lapack_int ldab, float* w, lapack_complex_float* z,
                           lapack_int ldz );
lapack_int LAPACKE_zhbevd( int matrix_order, char jobz, char uplo, lapack_int n,
                           lapack_int kd, lapack_complex_double* ab,
                           lapack_int ldab, double* w, lapack_complex_double* z,
                           lapack_int ldz );

lapack_int LAPACKE_chbevx( int matrix_order, char jobz, char range, char uplo,
                           lapack_int n, lapack_int kd,
                           lapack_complex_float* ab, lapack_int ldab,
                           lapack_complex_float* q, lapack_int ldq, float vl,
                           float vu, lapack_int il, lapack_int iu, float abstol,
                           lapack_int* m, float* w, lapack_complex_float* z,
                           lapack_int ldz, lapack_int* ifail );
lapack_int LAPACKE_zhbevx( int matrix_order, char jobz, char range, char uplo,
                           lapack_int n, lapack_int kd,
                           lapack_complex_double* ab, lapack_int ldab,
                           lapack_complex_double* q, lapack_int ldq, double vl,
                           double vu, lapack_int il, lapack_int iu,
                           double abstol, lapack_int* m, double* w,
                           lapack_complex_double* z, lapack_int ldz,
                           lapack_int* ifail );

lapack_int LAPACKE_chbgst( int matrix_order, char vect, char uplo, lapack_int n,
                           lapack_int ka, lapack_int kb,
                           lapack_complex_float* ab, lapack_int ldab,
                           const lapack_complex_float* bb, lapack_int ldbb,
                           lapack_complex_float* x, lapack_int ldx );
lapack_int LAPACKE_zhbgst( int matrix_order, char vect, char uplo, lapack_int n,
                           lapack_int ka, lapack_int kb,
                           lapack_complex_double* ab, lapack_int ldab,
                           const lapack_complex_double* bb, lapack_int ldbb,
                           lapack_complex_double* x, lapack_int ldx );

lapack_int LAPACKE_chbgv( int matrix_order, char jobz, char uplo, lapack_int n,
                          lapack_int ka, lapack_int kb,
                          lapack_complex_float* ab, lapack_int ldab,
                          lapack_complex_float* bb, lapack_int ldbb, float* w,
                          lapack_complex_float* z, lapack_int ldz );
lapack_int LAPACKE_zhbgv( int matrix_order, char jobz, char uplo, lapack_int n,
                          lapack_int ka, lapack_int kb,
                          lapack_complex_double* ab, lapack_int ldab,
                          lapack_complex_double* bb, lapack_int ldbb, double* w,
                          lapack_complex_double* z, lapack_int ldz );

lapack_int LAPACKE_chbgvd( int matrix_order, char jobz, char uplo, lapack_int n,
                           lapack_int ka, lapack_int kb,
                           lapack_complex_float* ab, lapack_int ldab,
                           lapack_complex_float* bb, lapack_int ldbb, float* w,
                           lapack_complex_float* z, lapack_int ldz );
lapack_int LAPACKE_zhbgvd( int matrix_order, char jobz, char uplo, lapack_int n,
                           lapack_int ka, lapack_int kb,
                           lapack_complex_double* ab, lapack_int ldab,
                           lapack_complex_double* bb, lapack_int ldbb,
                           double* w, lapack_complex_double* z,
                           lapack_int ldz );

lapack_int LAPACKE_chbgvx( int matrix_order, char jobz, char range, char uplo,
                           lapack_int n, lapack_int ka, lapack_int kb,
                           lapack_complex_float* ab, lapack_int ldab,
                           lapack_complex_float* bb, lapack_int ldbb,
                           lapack_complex_float* q, lapack_int ldq, float vl,
                           float vu, lapack_int il, lapack_int iu, float abstol,
                           lapack_int* m, float* w, lapack_complex_float* z,
                           lapack_int ldz, lapack_int* ifail );
lapack_int LAPACKE_zhbgvx( int matrix_order, char jobz, char range, char uplo,
                           lapack_int n, lapack_int ka, lapack_int kb,
                           lapack_complex_double* ab, lapack_int ldab,
                           lapack_complex_double* bb, lapack_int ldbb,
                           lapack_complex_double* q, lapack_int ldq, double vl,
                           double vu, lapack_int il, lapack_int iu,
                           double abstol, lapack_int* m, double* w,
                           lapack_complex_double* z, lapack_int ldz,
                           lapack_int* ifail );

lapack_int LAPACKE_chbtrd( int matrix_order, char vect, char uplo, lapack_int n,
                           lapack_int kd, lapack_complex_float* ab,
                           lapack_int ldab, float* d, float* e,
                           lapack_complex_float* q, lapack_int ldq );
lapack_int LAPACKE_zhbtrd( int matrix_order, char vect, char uplo, lapack_int n,
                           lapack_int kd, lapack_complex_double* ab,
                           lapack_int ldab, double* d, double* e,
                           lapack_complex_double* q, lapack_int ldq );

lapack_int LAPACKE_checon( int matrix_order, char uplo, lapack_int n,
                           const lapack_complex_float* a, lapack_int lda,
                           const lapack_int* ipiv, float anorm, float* rcond );
lapack_int LAPACKE_zhecon( int matrix_order, char uplo, lapack_int n,
                           const lapack_complex_double* a, lapack_int lda,
                           const lapack_int* ipiv, double anorm,
                           double* rcond );

lapack_int LAPACKE_cheequb( int matrix_order, char uplo, lapack_int n,
                            const lapack_complex_float* a, lapack_int lda,
                            float* s, float* scond, float* amax );
lapack_int LAPACKE_zheequb( int matrix_order, char uplo, lapack_int n,
                            const lapack_complex_double* a, lapack_int lda,
                            double* s, double* scond, double* amax );

lapack_int LAPACKE_cheev( int matrix_order, char jobz, char uplo, lapack_int n,
                          lapack_complex_float* a, lapack_int lda, float* w );
lapack_int LAPACKE_zheev( int matrix_order, char jobz, char uplo, lapack_int n,
                          lapack_complex_double* a, lapack_int lda, double* w );

lapack_int LAPACKE_cheevd( int matrix_order, char jobz, char uplo, lapack_int n,
                           lapack_complex_float* a, lapack_int lda, float* w );
lapack_int LAPACKE_zheevd( int matrix_order, char jobz, char uplo, lapack_int n,
                           lapack_complex_double* a, lapack_int lda,
                           double* w );

lapack_int LAPACKE_cheevr( int matrix_order, char jobz, char range, char uplo,
                           lapack_int n, lapack_complex_float* a,
                           lapack_int lda, float vl, float vu, lapack_int il,
                           lapack_int iu, float abstol, lapack_int* m, float* w,
                           lapack_complex_float* z, lapack_int ldz,
                           lapack_int* isuppz );
lapack_int LAPACKE_zheevr( int matrix_order, char jobz, char range, char uplo,
                           lapack_int n, lapack_complex_double* a,
                           lapack_int lda, double vl, double vu, lapack_int il,
                           lapack_int iu, double abstol, lapack_int* m,
                           double* w, lapack_complex_double* z, lapack_int ldz,
                           lapack_int* isuppz );

lapack_int LAPACKE_cheevx( int matrix_order, char jobz, char range, char uplo,
                           lapack_int n, lapack_complex_float* a,
                           lapack_int lda, float vl, float vu, lapack_int il,
                           lapack_int iu, float abstol, lapack_int* m, float* w,
                           lapack_complex_float* z, lapack_int ldz,
                           lapack_int* ifail );
lapack_int LAPACKE_zheevx( int matrix_order, char jobz, char range, char uplo,
                           lapack_int n, lapack_complex_double* a,
                           lapack_int lda, double vl, double vu, lapack_int il,
                           lapack_int iu, double abstol, lapack_int* m,
                           double* w, lapack_complex_double* z, lapack_int ldz,
                           lapack_int* ifail );

lapack_int LAPACKE_chegst( int matrix_order, lapack_int itype, char uplo,
                           lapack_int n, lapack_complex_float* a,
                           lapack_int lda, const lapack_complex_float* b,
                           lapack_int ldb );
lapack_int LAPACKE_zhegst( int matrix_order, lapack_int itype, char uplo,
                           lapack_int n, lapack_complex_double* a,
                           lapack_int lda, const lapack_complex_double* b,
                           lapack_int ldb );

lapack_int LAPACKE_chegv( int matrix_order, lapack_int itype, char jobz,
                          char uplo, lapack_int n, lapack_complex_float* a,
                          lapack_int lda, lapack_complex_float* b,
                          lapack_int ldb, float* w );
lapack_int LAPACKE_zhegv( int matrix_order, lapack_int itype, char jobz,
                          char uplo, lapack_int n, lapack_complex_double* a,
                          lapack_int lda, lapack_complex_double* b,
                          lapack_int ldb, double* w );

lapack_int LAPACKE_chegvd( int matrix_order, lapack_int itype, char jobz,
                           char uplo, lapack_int n, lapack_complex_float* a,
                           lapack_int lda, lapack_complex_float* b,
                           lapack_int ldb, float* w );
lapack_int LAPACKE_zhegvd( int matrix_order, lapack_int itype, char jobz,
                           char uplo, lapack_int n, lapack_complex_double* a,
                           lapack_int lda, lapack_complex_double* b,
                           lapack_int ldb, double* w );

lapack_int LAPACKE_chegvx( int matrix_order, lapack_int itype, char jobz,
                           char range, char uplo, lapack_int n,
                           lapack_complex_float* a, lapack_int lda,
                           lapack_complex_float* b, lapack_int ldb, float vl,
                           float vu, lapack_int il, lapack_int iu, float abstol,
                           lapack_int* m, float* w, lapack_complex_float* z,
                           lapack_int ldz, lapack_int* ifail );
lapack_int LAPACKE_zhegvx( int matrix_order, lapack_int itype, char jobz,
                           char range, char uplo, lapack_int n,
                           lapack_complex_double* a, lapack_int lda,
                           lapack_complex_double* b, lapack_int ldb, double vl,
                           double vu, lapack_int il, lapack_int iu,
                           double abstol, lapack_int* m, double* w,
                           lapack_complex_double* z, lapack_int ldz,
                           lapack_int* ifail );

lapack_int LAPACKE_cherfs( int matrix_order, char uplo, lapack_int n,
                           lapack_int nrhs, const lapack_complex_float* a,
                           lapack_int lda, const lapack_complex_float* af,
                           lapack_int ldaf, const lapack_int* ipiv,
                           const lapack_complex_float* b, lapack_int ldb,
                           lapack_complex_float* x, lapack_int ldx, float* ferr,
                           float* berr );
lapack_int LAPACKE_zherfs( int matrix_order, char uplo, lapack_int n,
                           lapack_int nrhs, const lapack_complex_double* a,
                           lapack_int lda, const lapack_complex_double* af,
                           lapack_int ldaf, const lapack_int* ipiv,
                           const lapack_complex_double* b, lapack_int ldb,
                           lapack_complex_double* x, lapack_int ldx,
                           double* ferr, double* berr );

lapack_int LAPACKE_cherfsx( int matrix_order, char uplo, char equed,
                            lapack_int n, lapack_int nrhs,
                            const lapack_complex_float* a, lapack_int lda,
                            const lapack_complex_float* af, lapack_int ldaf,
                            const lapack_int* ipiv, const float* s,
                            const lapack_complex_float* b, lapack_int ldb,
                            lapack_complex_float* x, lapack_int ldx,
                            float* rcond, float* berr, lapack_int n_err_bnds,
                            float* err_bnds_norm, float* err_bnds_comp,
                            lapack_int nparams, float* params );
lapack_int LAPACKE_zherfsx( int matrix_order, char uplo, char equed,
                            lapack_int n, lapack_int nrhs,
                            const lapack_complex_double* a, lapack_int lda,
                            const lapack_complex_double* af, lapack_int ldaf,
                            const lapack_int* ipiv, const double* s,
                            const lapack_complex_double* b, lapack_int ldb,
                            lapack_complex_double* x, lapack_int ldx,
                            double* rcond, double* berr, lapack_int n_err_bnds,
                            double* err_bnds_norm, double* err_bnds_comp,
                            lapack_int nparams, double* params );

lapack_int LAPACKE_chesv( int matrix_order, char uplo, lapack_int n,
                          lapack_int nrhs, lapack_complex_float* a,
                          lapack_int lda, lapack_int* ipiv,
                          lapack_complex_float* b, lapack_int ldb );
lapack_int LAPACKE_zhesv( int matrix_order, char uplo, lapack_int n,
                          lapack_int nrhs, lapack_complex_double* a,
                          lapack_int lda, lapack_int* ipiv,
                          lapack_complex_double* b, lapack_int ldb );

lapack_int LAPACKE_chesvx( int matrix_order, char fact, char uplo, lapack_int n,
                           lapack_int nrhs, const lapack_complex_float* a,
                           lapack_int lda, lapack_complex_float* af,
                           lapack_int ldaf, lapack_int* ipiv,
                           const lapack_complex_float* b, lapack_int ldb,
                           lapack_complex_float* x, lapack_int ldx,
                           float* rcond, float* ferr, float* berr );
lapack_int LAPACKE_zhesvx( int matrix_order, char fact, char uplo, lapack_int n,
                           lapack_int nrhs, const lapack_complex_double* a,
                           lapack_int lda, lapack_complex_double* af,
                           lapack_int ldaf, lapack_int* ipiv,
                           const lapack_complex_double* b, lapack_int ldb,
                           lapack_complex_double* x, lapack_int ldx,
                           double* rcond, double* ferr, double* berr );

lapack_int LAPACKE_chesvxx( int matrix_order, char fact, char uplo,
                            lapack_int n, lapack_int nrhs,
                            lapack_complex_float* a, lapack_int lda,
                            lapack_complex_float* af, lapack_int ldaf,
                            lapack_int* ipiv, char* equed, float* s,
                            lapack_complex_float* b, lapack_int ldb,
                            lapack_complex_float* x, lapack_int ldx,
                            float* rcond, float* rpvgrw, float* berr,
                            lapack_int n_err_bnds, float* err_bnds_norm,
                            float* err_bnds_comp, lapack_int nparams,
                            float* params );
lapack_int LAPACKE_zhesvxx( int matrix_order, char fact, char uplo,
                            lapack_int n, lapack_int nrhs,
                            lapack_complex_double* a, lapack_int lda,
                            lapack_complex_double* af, lapack_int ldaf,
                            lapack_int* ipiv, char* equed, double* s,
                            lapack_complex_double* b, lapack_int ldb,
                            lapack_complex_double* x, lapack_int ldx,
                            double* rcond, double* rpvgrw, double* berr,
                            lapack_int n_err_bnds, double* err_bnds_norm,
                            double* err_bnds_comp, lapack_int nparams,
                            double* params );

lapack_int LAPACKE_chetrd( int matrix_order, char uplo, lapack_int n,
                           lapack_complex_float* a, lapack_int lda, float* d,
                           float* e, lapack_complex_float* tau );
lapack_int LAPACKE_zhetrd( int matrix_order, char uplo, lapack_int n,
                           lapack_complex_double* a, lapack_int lda, double* d,
                           double* e, lapack_complex_double* tau );

lapack_int LAPACKE_chetrf( int matrix_order, char uplo, lapack_int n,
                           lapack_complex_float* a, lapack_int lda,
                           lapack_int* ipiv );
lapack_int LAPACKE_zhetrf( int matrix_order, char uplo, lapack_int n,
                           lapack_complex_double* a, lapack_int lda,
                           lapack_int* ipiv );

lapack_int LAPACKE_chetri( int matrix_order, char uplo, lapack_int n,
                           lapack_complex_float* a, lapack_int lda,
                           const lapack_int* ipiv );
lapack_int LAPACKE_zhetri( int matrix_order, char uplo, lapack_int n,
                           lapack_complex_double* a, lapack_int lda,
                           const lapack_int* ipiv );

lapack_int LAPACKE_chetrs( int matrix_order, char uplo, lapack_int n,
                           lapack_int nrhs, const lapack_complex_float* a,
                           lapack_int lda, const lapack_int* ipiv,
                           lapack_complex_float* b, lapack_int ldb );
lapack_int LAPACKE_zhetrs( int matrix_order, char uplo, lapack_int n,
                           lapack_int nrhs, const lapack_complex_double* a,
                           lapack_int lda, const lapack_int* ipiv,
                           lapack_complex_double* b, lapack_int ldb );

lapack_int LAPACKE_chfrk( int matrix_order, char transr, char uplo, char trans,
                          lapack_int n, lapack_int k, float alpha,
                          const lapack_complex_float* a, lapack_int lda,
                          float beta, lapack_complex_float* c );
lapack_int LAPACKE_zhfrk( int matrix_order, char transr, char uplo, char trans,
                          lapack_int n, lapack_int k, double alpha,
                          const lapack_complex_double* a, lapack_int lda,
                          double beta, lapack_complex_double* c );

lapack_int LAPACKE_shgeqz( int matrix_order, char job, char compq, char compz,
                           lapack_int n, lapack_int ilo, lapack_int ihi,
                           float* h, lapack_int ldh, float* t, lapack_int ldt,
                           float* alphar, float* alphai, float* beta, float* q,
                           lapack_int ldq, float* z, lapack_int ldz );
lapack_int LAPACKE_dhgeqz( int matrix_order, char job, char compq, char compz,
                           lapack_int n, lapack_int ilo, lapack_int ihi,
                           double* h, lapack_int ldh, double* t, lapack_int ldt,
                           double* alphar, double* alphai, double* beta,
                           double* q, lapack_int ldq, double* z,
                           lapack_int ldz );
lapack_int LAPACKE_chgeqz( int matrix_order, char job, char compq, char compz,
                           lapack_int n, lapack_int ilo, lapack_int ihi,
                           lapack_complex_float* h, lapack_int ldh,
                           lapack_complex_float* t, lapack_int ldt,
                           lapack_complex_float* alpha,
                           lapack_complex_float* beta, lapack_complex_float* q,
                           lapack_int ldq, lapack_complex_float* z,
                           lapack_int ldz );
lapack_int LAPACKE_zhgeqz( int matrix_order, char job, char compq, char compz,
                           lapack_int n, lapack_int ilo, lapack_int ihi,
                           lapack_complex_double* h, lapack_int ldh,
                           lapack_complex_double* t, lapack_int ldt,
                           lapack_complex_double* alpha,
                           lapack_complex_double* beta,
                           lapack_complex_double* q, lapack_int ldq,
                           lapack_complex_double* z, lapack_int ldz );

lapack_int LAPACKE_chpcon( int matrix_order, char uplo, lapack_int n,
                           const lapack_complex_float* ap,
                           const lapack_int* ipiv, float anorm, float* rcond );
lapack_int LAPACKE_zhpcon( int matrix_order, char uplo, lapack_int n,
                           const lapack_complex_double* ap,
                           const lapack_int* ipiv, double anorm,
                           double* rcond );

lapack_int LAPACKE_chpev( int matrix_order, char jobz, char uplo, lapack_int n,
                          lapack_complex_float* ap, float* w,
                          lapack_complex_float* z, lapack_int ldz );
lapack_int LAPACKE_zhpev( int matrix_order, char jobz, char uplo, lapack_int n,
                          lapack_complex_double* ap, double* w,
                          lapack_complex_double* z, lapack_int ldz );

lapack_int LAPACKE_chpevd( int matrix_order, char jobz, char uplo, lapack_int n,
                           lapack_complex_float* ap, float* w,
                           lapack_complex_float* z, lapack_int ldz );
lapack_int LAPACKE_zhpevd( int matrix_order, char jobz, char uplo, lapack_int n,
                           lapack_complex_double* ap, double* w,
                           lapack_complex_double* z, lapack_int ldz );

lapack_int LAPACKE_chpevx( int matrix_order, char jobz, char range, char uplo,
                           lapack_int n, lapack_complex_float* ap, float vl,
                           float vu, lapack_int il, lapack_int iu, float abstol,
                           lapack_int* m, float* w, lapack_complex_float* z,
                           lapack_int ldz, lapack_int* ifail );
lapack_int LAPACKE_zhpevx( int matrix_order, char jobz, char range, char uplo,
                           lapack_int n, lapack_complex_double* ap, double vl,
                           double vu, lapack_int il, lapack_int iu,
                           double abstol, lapack_int* m, double* w,
                           lapack_complex_double* z, lapack_int ldz,
                           lapack_int* ifail );

lapack_int LAPACKE_chpgst( int matrix_order, lapack_int itype, char uplo,
                           lapack_int n, lapack_complex_float* ap,
                           const lapack_complex_float* bp );
lapack_int LAPACKE_zhpgst( int matrix_order, lapack_int itype, char uplo,
                           lapack_int n, lapack_complex_double* ap,
                           const lapack_complex_double* bp );

lapack_int LAPACKE_chpgv( int matrix_order, lapack_int itype, char jobz,
                          char uplo, lapack_int n, lapack_complex_float* ap,
                          lapack_complex_float* bp, float* w,
                          lapack_complex_float* z, lapack_int ldz );
lapack_int LAPACKE_zhpgv( int matrix_order, lapack_int itype, char jobz,
                          char uplo, lapack_int n, lapack_complex_double* ap,
                          lapack_complex_double* bp, double* w,
                          lapack_complex_double* z, lapack_int ldz );

lapack_int LAPACKE_chpgvd( int matrix_order, lapack_int itype, char jobz,
                           char uplo, lapack_int n, lapack_complex_float* ap,
                           lapack_complex_float* bp, float* w,
                           lapack_complex_float* z, lapack_int ldz );
lapack_int LAPACKE_zhpgvd( int matrix_order, lapack_int itype, char jobz,
                           char uplo, lapack_int n, lapack_complex_double* ap,
                           lapack_complex_double* bp, double* w,
                           lapack_complex_double* z, lapack_int ldz );

lapack_int LAPACKE_chpgvx( int matrix_order, lapack_int itype, char jobz,
                           char range, char uplo, lapack_int n,
                           lapack_complex_float* ap, lapack_complex_float* bp,
                           float vl, float vu, lapack_int il, lapack_int iu,
                           float abstol, lapack_int* m, float* w,
                           lapack_complex_float* z, lapack_int ldz,
                           lapack_int* ifail );
lapack_int LAPACKE_zhpgvx( int matrix_order, lapack_int itype, char jobz,
                           char range, char uplo, lapack_int n,
                           lapack_complex_double* ap, lapack_complex_double* bp,
                           double vl, double vu, lapack_int il, lapack_int iu,
                           double abstol, lapack_int* m, double* w,
                           lapack_complex_double* z, lapack_int ldz,
                           lapack_int* ifail );

lapack_int LAPACKE_chprfs( int matrix_order, char uplo, lapack_int n,
                           lapack_int nrhs, const lapack_complex_float* ap,
                           const lapack_complex_float* afp,
                           const lapack_int* ipiv,
                           const lapack_complex_float* b, lapack_int ldb,
                           lapack_complex_float* x, lapack_int ldx, float* ferr,
                           float* berr );
lapack_int LAPACKE_zhprfs( int matrix_order, char uplo, lapack_int n,
                           lapack_int nrhs, const lapack_complex_double* ap,
                           const lapack_complex_double* afp,
                           const lapack_int* ipiv,
                           const lapack_complex_double* b, lapack_int ldb,
                           lapack_complex_double* x, lapack_int ldx,
                           double* ferr, double* berr );

lapack_int LAPACKE_chpsv( int matrix_order, char uplo, lapack_int n,
                          lapack_int nrhs, lapack_complex_float* ap,
                          lapack_int* ipiv, lapack_complex_float* b,
                          lapack_int ldb );
lapack_int LAPACKE_zhpsv( int matrix_order, char uplo, lapack_int n,
                          lapack_int nrhs, lapack_complex_double* ap,
                          lapack_int* ipiv, lapack_complex_double* b,
                          lapack_int ldb );

lapack_int LAPACKE_chpsvx( int matrix_order, char fact, char uplo, lapack_int n,
                           lapack_int nrhs, const lapack_complex_float* ap,
                           lapack_complex_float* afp, lapack_int* ipiv,
                           const lapack_complex_float* b, lapack_int ldb,
                           lapack_complex_float* x, lapack_int ldx,
                           float* rcond, float* ferr, float* berr );
lapack_int LAPACKE_zhpsvx( int matrix_order, char fact, char uplo, lapack_int n,
                           lapack_int nrhs, const lapack_complex_double* ap,
                           lapack_complex_double* afp, lapack_int* ipiv,
                           const lapack_complex_double* b, lapack_int ldb,
                           lapack_complex_double* x, lapack_int ldx,
                           double* rcond, double* ferr, double* berr );

lapack_int LAPACKE_chptrd( int matrix_order, char uplo, lapack_int n,
                           lapack_complex_float* ap, float* d, float* e,
                           lapack_complex_float* tau );
lapack_int LAPACKE_zhptrd( int matrix_order, char uplo, lapack_int n,
                           lapack_complex_double* ap, double* d, double* e,
                           lapack_complex_double* tau );

lapack_int LAPACKE_chptrf( int matrix_order, char uplo, lapack_int n,
                           lapack_complex_float* ap, lapack_int* ipiv );
lapack_int LAPACKE_zhptrf( int matrix_order, char uplo, lapack_int n,
                           lapack_complex_double* ap, lapack_int* ipiv );

lapack_int LAPACKE_chptri( int matrix_order, char uplo, lapack_int n,
                           lapack_complex_float* ap, const lapack_int* ipiv );
lapack_int LAPACKE_zhptri( int matrix_order, char uplo, lapack_int n,
                           lapack_complex_double* ap, const lapack_int* ipiv );

lapack_int LAPACKE_chptrs( int matrix_order, char uplo, lapack_int n,
                           lapack_int nrhs, const lapack_complex_float* ap,
                           const lapack_int* ipiv, lapack_complex_float* b,
                           lapack_int ldb );
lapack_int LAPACKE_zhptrs( int matrix_order, char uplo, lapack_int n,
                           lapack_int nrhs, const lapack_complex_double* ap,
                           const lapack_int* ipiv, lapack_complex_double* b,
                           lapack_int ldb );

lapack_int LAPACKE_shsein( int matrix_order, char job, char eigsrc, char initv,
                           lapack_logical* select, lapack_int n, const float* h,
                           lapack_int ldh, float* wr, const float* wi,
                           float* vl, lapack_int ldvl, float* vr,
                           lapack_int ldvr, lapack_int mm, lapack_int* m,
                           lapack_int* ifaill, lapack_int* ifailr );
lapack_int LAPACKE_dhsein( int matrix_order, char job, char eigsrc, char initv,
                           lapack_logical* select, lapack_int n,
                           const double* h, lapack_int ldh, double* wr,
                           const double* wi, double* vl, lapack_int ldvl,
                           double* vr, lapack_int ldvr, lapack_int mm,
                           lapack_int* m, lapack_int* ifaill,
                           lapack_int* ifailr );
lapack_int LAPACKE_chsein( int matrix_order, char job, char eigsrc, char initv,
                           const lapack_logical* select, lapack_int n,
                           const lapack_complex_float* h, lapack_int ldh,
                           lapack_complex_float* w, lapack_complex_float* vl,
                           lapack_int ldvl, lapack_complex_float* vr,
                           lapack_int ldvr, lapack_int mm, lapack_int* m,
                           lapack_int* ifaill, lapack_int* ifailr );
lapack_int LAPACKE_zhsein( int matrix_order, char job, char eigsrc, char initv,
                           const lapack_logical* select, lapack_int n,
                           const lapack_complex_double* h, lapack_int ldh,
                           lapack_complex_double* w, lapack_complex_double* vl,
                           lapack_int ldvl, lapack_complex_double* vr,
                           lapack_int ldvr, lapack_int mm, lapack_int* m,
                           lapack_int* ifaill, lapack_int* ifailr );

lapack_int LAPACKE_shseqr( int matrix_order, char job, char compz, lapack_int n,
                           lapack_int ilo, lapack_int ihi, float* h,
                           lapack_int ldh, float* wr, float* wi, float* z,
                           lapack_int ldz );
lapack_int LAPACKE_dhseqr( int matrix_order, char job, char compz, lapack_int n,
                           lapack_int ilo, lapack_int ihi, double* h,
                           lapack_int ldh, double* wr, double* wi, double* z,
                           lapack_int ldz );
lapack_int LAPACKE_chseqr( int matrix_order, char job, char compz, lapack_int n,
                           lapack_int ilo, lapack_int ihi,
                           lapack_complex_float* h, lapack_int ldh,
                           lapack_complex_float* w, lapack_complex_float* z,
                           lapack_int ldz );
lapack_int LAPACKE_zhseqr( int matrix_order, char job, char compz, lapack_int n,
                           lapack_int ilo, lapack_int ihi,
                           lapack_complex_double* h, lapack_int ldh,
                           lapack_complex_double* w, lapack_complex_double* z,
                           lapack_int ldz );

lapack_int LAPACKE_sopgtr( int matrix_order, char uplo, lapack_int n,
                           const float* ap, const float* tau, float* q,
                           lapack_int ldq );
lapack_int LAPACKE_dopgtr( int matrix_order, char uplo, lapack_int n,
                           const double* ap, const double* tau, double* q,
                           lapack_int ldq );

lapack_int LAPACKE_sopmtr( int matrix_order, char side, char uplo, char trans,
                           lapack_int m, lapack_int n, const float* ap,
                           const float* tau, float* c, lapack_int ldc );
lapack_int LAPACKE_dopmtr( int matrix_order, char side, char uplo, char trans,
                           lapack_int m, lapack_int n, const double* ap,
                           const double* tau, double* c, lapack_int ldc );

lapack_int LAPACKE_sorgbr( int matrix_order, char vect, lapack_int m,
                           lapack_int n, lapack_int k, float* a, lapack_int lda,
                           const float* tau );
lapack_int LAPACKE_dorgbr( int matrix_order, char vect, lapack_int m,
                           lapack_int n, lapack_int k, double* a,
                           lapack_int lda, const double* tau );

lapack_int LAPACKE_sorghr( int matrix_order, lapack_int n, lapack_int ilo,
                           lapack_int ihi, float* a, lapack_int lda,
                           const float* tau );
lapack_int LAPACKE_dorghr( int matrix_order, lapack_int n, lapack_int ilo,
                           lapack_int ihi, double* a, lapack_int lda,
                           const double* tau );

lapack_int LAPACKE_sorglq( int matrix_order, lapack_int m, lapack_int n,
                           lapack_int k, float* a, lapack_int lda,
                           const float* tau );
lapack_int LAPACKE_dorglq( int matrix_order, lapack_int m, lapack_int n,
                           lapack_int k, double* a, lapack_int lda,
                           const double* tau );

lapack_int LAPACKE_sorgql( int matrix_order, lapack_int m, lapack_int n,
                           lapack_int k, float* a, lapack_int lda,
                           const float* tau );
lapack_int LAPACKE_dorgql( int matrix_order, lapack_int m, lapack_int n,
                           lapack_int k, double* a, lapack_int lda,
                           const double* tau );

lapack_int LAPACKE_sorgqr( int matrix_order, lapack_int m, lapack_int n,
                           lapack_int k, float* a, lapack_int lda,
                           const float* tau );
lapack_int LAPACKE_dorgqr( int matrix_order, lapack_int m, lapack_int n,
                           lapack_int k, double* a, lapack_int lda,
                           const double* tau );

lapack_int LAPACKE_sorgrq( int matrix_order, lapack_int m, lapack_int n,
                           lapack_int k, float* a, lapack_int lda,
                           const float* tau );
lapack_int LAPACKE_dorgrq( int matrix_order, lapack_int m, lapack_int n,
                           lapack_int k, double* a, lapack_int lda,
                           const double* tau );

lapack_int LAPACKE_sorgtr( int matrix_order, char uplo, lapack_int n, float* a,
                           lapack_int lda, const float* tau );
lapack_int LAPACKE_dorgtr( int matrix_order, char uplo, lapack_int n, double* a,
                           lapack_int lda, const double* tau );

lapack_int LAPACKE_sormbr( int matrix_order, char vect, char side, char trans,
                           lapack_int m, lapack_int n, lapack_int k,
                           const float* a, lapack_int lda, const float* tau,
                           float* c, lapack_int ldc );
lapack_int LAPACKE_dormbr( int matrix_order, char vect, char side, char trans,
                           lapack_int m, lapack_int n, lapack_int k,
                           const double* a, lapack_int lda, const double* tau,
                           double* c, lapack_int ldc );

lapack_int LAPACKE_sormhr( int matrix_order, char side, char trans,
                           lapack_int m, lapack_int n, lapack_int ilo,
                           lapack_int ihi, const float* a, lapack_int lda,
                           const float* tau, float* c, lapack_int ldc );
lapack_int LAPACKE_dormhr( int matrix_order, char side, char trans,
                           lapack_int m, lapack_int n, lapack_int ilo,
                           lapack_int ihi, const double* a, lapack_int lda,
                           const double* tau, double* c, lapack_int ldc );

lapack_int LAPACKE_sormlq( int matrix_order, char side, char trans,
                           lapack_int m, lapack_int n, lapack_int k,
                           const float* a, lapack_int lda, const float* tau,
                           float* c, lapack_int ldc );
lapack_int LAPACKE_dormlq( int matrix_order, char side, char trans,
                           lapack_int m, lapack_int n, lapack_int k,
                           const double* a, lapack_int lda, const double* tau,
                           double* c, lapack_int ldc );

lapack_int LAPACKE_sormql( int matrix_order, char side, char trans,
                           lapack_int m, lapack_int n, lapack_int k,
                           const float* a, lapack_int lda, const float* tau,
                           float* c, lapack_int ldc );
lapack_int LAPACKE_dormql( int matrix_order, char side, char trans,
                           lapack_int m, lapack_int n, lapack_int k,
                           const double* a, lapack_int lda, const double* tau,
                           double* c, lapack_int ldc );

lapack_int LAPACKE_sormqr( int matrix_order, char side, char trans,
                           lapack_int m, lapack_int n, lapack_int k,
                           const float* a, lapack_int lda, const float* tau,
                           float* c, lapack_int ldc );
lapack_int LAPACKE_dormqr( int matrix_order, char side, char trans,
                           lapack_int m, lapack_int n, lapack_int k,
                           const double* a, lapack_int lda, const double* tau,
                           double* c, lapack_int ldc );

lapack_int LAPACKE_sormrq( int matrix_order, char side, char trans,
                           lapack_int m, lapack_int n, lapack_int k,
                           const float* a, lapack_int lda, const float* tau,
                           float* c, lapack_int ldc );
lapack_int LAPACKE_dormrq( int matrix_order, char side, char trans,
                           lapack_int m, lapack_int n, lapack_int k,
                           const double* a, lapack_int lda, const double* tau,
                           double* c, lapack_int ldc );

lapack_int LAPACKE_sormrz( int matrix_order, char side, char trans,
                           lapack_int m, lapack_int n, lapack_int k,
                           lapack_int l, const float* a, lapack_int lda,
                           const float* tau, float* c, lapack_int ldc );
lapack_int LAPACKE_dormrz( int matrix_order, char side, char trans,
                           lapack_int m, lapack_int n, lapack_int k,
                           lapack_int l, const double* a, lapack_int lda,
                           const double* tau, double* c, lapack_int ldc );

lapack_int LAPACKE_sormtr( int matrix_order, char side, char uplo, char trans,
                           lapack_int m, lapack_int n, const float* a,
                           lapack_int lda, const float* tau, float* c,
                           lapack_int ldc );
lapack_int LAPACKE_dormtr( int matrix_order, char side, char uplo, char trans,
                           lapack_int m, lapack_int n, const double* a,
                           lapack_int lda, const double* tau, double* c,
                           lapack_int ldc );

lapack_int LAPACKE_spbcon( int matrix_order, char uplo, lapack_int n,
                           lapack_int kd, const float* ab, lapack_int ldab,
                           float anorm, float* rcond );
lapack_int LAPACKE_dpbcon( int matrix_order, char uplo, lapack_int n,
                           lapack_int kd, const double* ab, lapack_int ldab,
                           double anorm, double* rcond );
lapack_int LAPACKE_cpbcon( int matrix_order, char uplo, lapack_int n,
                           lapack_int kd, const lapack_complex_float* ab,
                           lapack_int ldab, float anorm, float* rcond );
lapack_int LAPACKE_zpbcon( int matrix_order, char uplo, lapack_int n,
                           lapack_int kd, const lapack_complex_double* ab,
                           lapack_int ldab, double anorm, double* rcond );

lapack_int LAPACKE_spbequ( int matrix_order, char uplo, lapack_int n,
                           lapack_int kd, const float* ab, lapack_int ldab,
                           float* s, float* scond, float* amax );
lapack_int LAPACKE_dpbequ( int matrix_order, char uplo, lapack_int n,
                           lapack_int kd, const double* ab, lapack_int ldab,
                           double* s, double* scond, double* amax );
lapack_int LAPACKE_cpbequ( int matrix_order, char uplo, lapack_int n,
                           lapack_int kd, const lapack_complex_float* ab,
                           lapack_int ldab, float* s, float* scond,
                           float* amax );
lapack_int LAPACKE_zpbequ( int matrix_order, char uplo, lapack_int n,
                           lapack_int kd, const lapack_complex_double* ab,
                           lapack_int ldab, double* s, double* scond,
                           double* amax );

lapack_int LAPACKE_spbrfs( int matrix_order, char uplo, lapack_int n,
                           lapack_int kd, lapack_int nrhs, const float* ab,
                           lapack_int ldab, const float* afb, lapack_int ldafb,
                           const float* b, lapack_int ldb, float* x,
                           lapack_int ldx, float* ferr, float* berr );
lapack_int LAPACKE_dpbrfs( int matrix_order, char uplo, lapack_int n,
                           lapack_int kd, lapack_int nrhs, const double* ab,
                           lapack_int ldab, const double* afb, lapack_int ldafb,
                           const double* b, lapack_int ldb, double* x,
                           lapack_int ldx, double* ferr, double* berr );
lapack_int LAPACKE_cpbrfs( int matrix_order, char uplo, lapack_int n,
                           lapack_int kd, lapack_int nrhs,
                           const lapack_complex_float* ab, lapack_int ldab,
                           const lapack_complex_float* afb, lapack_int ldafb,
                           const lapack_complex_float* b, lapack_int ldb,
                           lapack_complex_float* x, lapack_int ldx, float* ferr,
                           float* berr );
lapack_int LAPACKE_zpbrfs( int matrix_order, char uplo, lapack_int n,
                           lapack_int kd, lapack_int nrhs,
                           const lapack_complex_double* ab, lapack_int ldab,
                           const lapack_complex_double* afb, lapack_int ldafb,
                           const lapack_complex_double* b, lapack_int ldb,
                           lapack_complex_double* x, lapack_int ldx,
                           double* ferr, double* berr );

lapack_int LAPACKE_spbstf( int matrix_order, char uplo, lapack_int n,
                           lapack_int kb, float* bb, lapack_int ldbb );
lapack_int LAPACKE_dpbstf( int matrix_order, char uplo, lapack_int n,
                           lapack_int kb, double* bb, lapack_int ldbb );
lapack_int LAPACKE_cpbstf( int matrix_order, char uplo, lapack_int n,
                           lapack_int kb, lapack_complex_float* bb,
                           lapack_int ldbb );
lapack_int LAPACKE_zpbstf( int matrix_order, char uplo, lapack_int n,
                           lapack_int kb, lapack_complex_double* bb,
                           lapack_int ldbb );

lapack_int LAPACKE_spbsv( int matrix_order, char uplo, lapack_int n,
                          lapack_int kd, lapack_int nrhs, float* ab,
                          lapack_int ldab, float* b, lapack_int ldb );
lapack_int LAPACKE_dpbsv( int matrix_order, char uplo, lapack_int n,
                          lapack_int kd, lapack_int nrhs, double* ab,
                          lapack_int ldab, double* b, lapack_int ldb );
lapack_int LAPACKE_cpbsv( int matrix_order, char uplo, lapack_int n,
                          lapack_int kd, lapack_int nrhs,
                          lapack_complex_float* ab, lapack_int ldab,
                          lapack_complex_float* b, lapack_int ldb );
lapack_int LAPACKE_zpbsv( int matrix_order, char uplo, lapack_int n,
                          lapack_int kd, lapack_int nrhs,
                          lapack_complex_double* ab, lapack_int ldab,
                          lapack_complex_double* b, lapack_int ldb );

lapack_int LAPACKE_spbsvx( int matrix_order, char fact, char uplo, lapack_int n,
                           lapack_int kd, lapack_int nrhs, float* ab,
                           lapack_int ldab, float* afb, lapack_int ldafb,
                           char* equed, float* s, float* b, lapack_int ldb,
                           float* x, lapack_int ldx, float* rcond, float* ferr,
                           float* berr );
lapack_int LAPACKE_dpbsvx( int matrix_order, char fact, char uplo, lapack_int n,
                           lapack_int kd, lapack_int nrhs, double* ab,
                           lapack_int ldab, double* afb, lapack_int ldafb,
                           char* equed, double* s, double* b, lapack_int ldb,
                           double* x, lapack_int ldx, double* rcond,
                           double* ferr, double* berr );
lapack_int LAPACKE_cpbsvx( int matrix_order, char fact, char uplo, lapack_int n,
                           lapack_int kd, lapack_int nrhs,
                           lapack_complex_float* ab, lapack_int ldab,
                           lapack_complex_float* afb, lapack_int ldafb,
                           char* equed, float* s, lapack_complex_float* b,
                           lapack_int ldb, lapack_complex_float* x,
                           lapack_int ldx, float* rcond, float* ferr,
                           float* berr );
lapack_int LAPACKE_zpbsvx( int matrix_order, char fact, char uplo, lapack_int n,
                           lapack_int kd, lapack_int nrhs,
                           lapack_complex_double* ab, lapack_int ldab,
                           lapack_complex_double* afb, lapack_int ldafb,
                           char* equed, double* s, lapack_complex_double* b,
                           lapack_int ldb, lapack_complex_double* x,
                           lapack_int ldx, double* rcond, double* ferr,
                           double* berr );

lapack_int LAPACKE_spbtrf( int matrix_order, char uplo, lapack_int n,
                           lapack_int kd, float* ab, lapack_int ldab );
lapack_int LAPACKE_dpbtrf( int matrix_order, char uplo, lapack_int n,
                           lapack_int kd, double* ab, lapack_int ldab );
lapack_int LAPACKE_cpbtrf( int matrix_order, char uplo, lapack_int n,
                           lapack_int kd, lapack_complex_float* ab,
                           lapack_int ldab );
lapack_int LAPACKE_zpbtrf( int matrix_order, char uplo, lapack_int n,
                           lapack_int kd, lapack_complex_double* ab,
                           lapack_int ldab );

lapack_int LAPACKE_spbtrs( int matrix_order, char uplo, lapack_int n,
                           lapack_int kd, lapack_int nrhs, const float* ab,
                           lapack_int ldab, float* b, lapack_int ldb );
lapack_int LAPACKE_dpbtrs( int matrix_order, char uplo, lapack_int n,
                           lapack_int kd, lapack_int nrhs, const double* ab,
                           lapack_int ldab, double* b, lapack_int ldb );
lapack_int LAPACKE_cpbtrs( int matrix_order, char uplo, lapack_int n,
                           lapack_int kd, lapack_int nrhs,
                           const lapack_complex_float* ab, lapack_int ldab,
                           lapack_complex_float* b, lapack_int ldb );
lapack_int LAPACKE_zpbtrs( int matrix_order, char uplo, lapack_int n,
                           lapack_int kd, lapack_int nrhs,
                           const lapack_complex_double* ab, lapack_int ldab,
                           lapack_complex_double* b, lapack_int ldb );

lapack_int LAPACKE_spftrf( int matrix_order, char transr, char uplo,
                           lapack_int n, float* a );
lapack_int LAPACKE_dpftrf( int matrix_order, char transr, char uplo,
                           lapack_int n, double* a );
lapack_int LAPACKE_cpftrf( int matrix_order, char transr, char uplo,
                           lapack_int n, lapack_complex_float* a );
lapack_int LAPACKE_zpftrf( int matrix_order, char transr, char uplo,
                           lapack_int n, lapack_complex_double* a );

lapack_int LAPACKE_spftri( int matrix_order, char transr, char uplo,
                           lapack_int n, float* a );
lapack_int LAPACKE_dpftri( int matrix_order, char transr, char uplo,
                           lapack_int n, double* a );
lapack_int LAPACKE_cpftri( int matrix_order, char transr, char uplo,
                           lapack_int n, lapack_complex_float* a );
lapack_int LAPACKE_zpftri( int matrix_order, char transr, char uplo,
                           lapack_int n, lapack_complex_double* a );

lapack_int LAPACKE_spftrs( int matrix_order, char transr, char uplo,
                           lapack_int n, lapack_int nrhs, const float* a,
                           float* b, lapack_int ldb );
lapack_int LAPACKE_dpftrs( int matrix_order, char transr, char uplo,
                           lapack_int n, lapack_int nrhs, const double* a,
                           double* b, lapack_int ldb );
lapack_int LAPACKE_cpftrs( int matrix_order, char transr, char uplo,
                           lapack_int n, lapack_int nrhs,
                           const lapack_complex_float* a,
                           lapack_complex_float* b, lapack_int ldb );
lapack_int LAPACKE_zpftrs( int matrix_order, char transr, char uplo,
                           lapack_int n, lapack_int nrhs,
                           const lapack_complex_double* a,
                           lapack_complex_double* b, lapack_int ldb );

lapack_int LAPACKE_spocon( int matrix_order, char uplo, lapack_int n,
                           const float* a, lapack_int lda, float anorm,
                           float* rcond );
lapack_int LAPACKE_dpocon( int matrix_order, char uplo, lapack_int n,
                           const double* a, lapack_int lda, double anorm,
                           double* rcond );
lapack_int LAPACKE_cpocon( int matrix_order, char uplo, lapack_int n,
                           const lapack_complex_float* a, lapack_int lda,
                           float anorm, float* rcond );
lapack_int LAPACKE_zpocon( int matrix_order, char uplo, lapack_int n,
                           const lapack_complex_double* a, lapack_int lda,
                           double anorm, double* rcond );

lapack_int LAPACKE_spoequ( int matrix_order, lapack_int n, const float* a,
                           lapack_int lda, float* s, float* scond,
                           float* amax );
lapack_int LAPACKE_dpoequ( int matrix_order, lapack_int n, const double* a,
                           lapack_int lda, double* s, double* scond,
                           double* amax );
lapack_int LAPACKE_cpoequ( int matrix_order, lapack_int n,
                           const lapack_complex_float* a, lapack_int lda,
                           float* s, float* scond, float* amax );
lapack_int LAPACKE_zpoequ( int matrix_order, lapack_int n,
                           const lapack_complex_double* a, lapack_int lda,
                           double* s, double* scond, double* amax );

lapack_int LAPACKE_spoequb( int matrix_order, lapack_int n, const float* a,
                            lapack_int lda, float* s, float* scond,
                            float* amax );
lapack_int LAPACKE_dpoequb( int matrix_order, lapack_int n, const double* a,
                            lapack_int lda, double* s, double* scond,
                            double* amax );
lapack_int LAPACKE_cpoequb( int matrix_order, lapack_int n,
                            const lapack_complex_float* a, lapack_int lda,
                            float* s, float* scond, float* amax );
lapack_int LAPACKE_zpoequb( int matrix_order, lapack_int n,
                            const lapack_complex_double* a, lapack_int lda,
                            double* s, double* scond, double* amax );

lapack_int LAPACKE_sporfs( int matrix_order, char uplo, lapack_int n,
                           lapack_int nrhs, const float* a, lapack_int lda,
                           const float* af, lapack_int ldaf, const float* b,
                           lapack_int ldb, float* x, lapack_int ldx,
                           float* ferr, float* berr );
lapack_int LAPACKE_dporfs( int matrix_order, char uplo, lapack_int n,
                           lapack_int nrhs, const double* a, lapack_int lda,
                           const double* af, lapack_int ldaf, const double* b,
                           lapack_int ldb, double* x, lapack_int ldx,
                           double* ferr, double* berr );
lapack_int LAPACKE_cporfs( int matrix_order, char uplo, lapack_int n,
                           lapack_int nrhs, const lapack_complex_float* a,
                           lapack_int lda, const lapack_complex_float* af,
                           lapack_int ldaf, const lapack_complex_float* b,
                           lapack_int ldb, lapack_complex_float* x,
                           lapack_int ldx, float* ferr, float* berr );
lapack_int LAPACKE_zporfs( int matrix_order, char uplo, lapack_int n,
                           lapack_int nrhs, const lapack_complex_double* a,
                           lapack_int lda, const lapack_complex_double* af,
                           lapack_int ldaf, const lapack_complex_double* b,
                           lapack_int ldb, lapack_complex_double* x,
                           lapack_int ldx, double* ferr, double* berr );

lapack_int LAPACKE_sporfsx( int matrix_order, char uplo, char equed,
                            lapack_int n, lapack_int nrhs, const float* a,
                            lapack_int lda, const float* af, lapack_int ldaf,
                            const float* s, const float* b, lapack_int ldb,
                            float* x, lapack_int ldx, float* rcond, float* berr,
                            lapack_int n_err_bnds, float* err_bnds_norm,
                            float* err_bnds_comp, lapack_int nparams,
                            float* params );
lapack_int LAPACKE_dporfsx( int matrix_order, char uplo, char equed,
                            lapack_int n, lapack_int nrhs, const double* a,
                            lapack_int lda, const double* af, lapack_int ldaf,
                            const double* s, const double* b, lapack_int ldb,
                            double* x, lapack_int ldx, double* rcond,
                            double* berr, lapack_int n_err_bnds,
                            double* err_bnds_norm, double* err_bnds_comp,
                            lapack_int nparams, double* params );
lapack_int LAPACKE_cporfsx( int matrix_order, char uplo, char equed,
                            lapack_int n, lapack_int nrhs,
                            const lapack_complex_float* a, lapack_int lda,
                            const lapack_complex_float* af, lapack_int ldaf,
                            const float* s, const lapack_complex_float* b,
                            lapack_int ldb, lapack_complex_float* x,
                            lapack_int ldx, float* rcond, float* berr,
                            lapack_int n_err_bnds, float* err_bnds_norm,
                            float* err_bnds_comp, lapack_int nparams,
                            float* params );
lapack_int LAPACKE_zporfsx( int matrix_order, char uplo, char equed,
                            lapack_int n, lapack_int nrhs,
                            const lapack_complex_double* a, lapack_int lda,
                            const lapack_complex_double* af, lapack_int ldaf,
                            const double* s, const lapack_complex_double* b,
                            lapack_int ldb, lapack_complex_double* x,
                            lapack_int ldx, double* rcond, double* berr,
                            lapack_int n_err_bnds, double* err_bnds_norm,
                            double* err_bnds_comp, lapack_int nparams,
                            double* params );

lapack_int LAPACKE_sposv( int matrix_order, char uplo, lapack_int n,
                          lapack_int nrhs, float* a, lapack_int lda, float* b,
                          lapack_int ldb );
lapack_int LAPACKE_dposv( int matrix_order, char uplo, lapack_int n,
                          lapack_int nrhs, double* a, lapack_int lda, double* b,
                          lapack_int ldb );
lapack_int LAPACKE_cposv( int matrix_order, char uplo, lapack_int n,
                          lapack_int nrhs, lapack_complex_float* a,
                          lapack_int lda, lapack_complex_float* b,
                          lapack_int ldb );
lapack_int LAPACKE_zposv( int matrix_order, char uplo, lapack_int n,
                          lapack_int nrhs, lapack_complex_double* a,
                          lapack_int lda, lapack_complex_double* b,
                          lapack_int ldb );
lapack_int LAPACKE_dsposv( int matrix_order, char uplo, lapack_int n,
                           lapack_int nrhs, double* a, lapack_int lda,
                           double* b, lapack_int ldb, double* x, lapack_int ldx,
                           lapack_int* iter );
lapack_int LAPACKE_zcposv( int matrix_order, char uplo, lapack_int n,
                           lapack_int nrhs, lapack_complex_double* a,
                           lapack_int lda, lapack_complex_double* b,
                           lapack_int ldb, lapack_complex_double* x,
                           lapack_int ldx, lapack_int* iter );

lapack_int LAPACKE_sposvx( int matrix_order, char fact, char uplo, lapack_int n,
                           lapack_int nrhs, float* a, lapack_int lda, float* af,
                           lapack_int ldaf, char* equed, float* s, float* b,
                           lapack_int ldb, float* x, lapack_int ldx,
                           float* rcond, float* ferr, float* berr );
lapack_int LAPACKE_dposvx( int matrix_order, char fact, char uplo, lapack_int n,
                           lapack_int nrhs, double* a, lapack_int lda,
                           double* af, lapack_int ldaf, char* equed, double* s,
                           double* b, lapack_int ldb, double* x, lapack_int ldx,
                           double* rcond, double* ferr, double* berr );
lapack_int LAPACKE_cposvx( int matrix_order, char fact, char uplo, lapack_int n,
                           lapack_int nrhs, lapack_complex_float* a,
                           lapack_int lda, lapack_complex_float* af,
                           lapack_int ldaf, char* equed, float* s,
                           lapack_complex_float* b, lapack_int ldb,
                           lapack_complex_float* x, lapack_int ldx,
                           float* rcond, float* ferr, float* berr );
lapack_int LAPACKE_zposvx( int matrix_order, char fact, char uplo, lapack_int n,
                           lapack_int nrhs, lapack_complex_double* a,
                           lapack_int lda, lapack_complex_double* af,
                           lapack_int ldaf, char* equed, double* s,
                           lapack_complex_double* b, lapack_int ldb,
                           lapack_complex_double* x, lapack_int ldx,
                           double* rcond, double* ferr, double* berr );

lapack_int LAPACKE_sposvxx( int matrix_order, char fact, char uplo,
                            lapack_int n, lapack_int nrhs, float* a,
                            lapack_int lda, float* af, lapack_int ldaf,
                            char* equed, float* s, float* b, lapack_int ldb,
                            float* x, lapack_int ldx, float* rcond,
                            float* rpvgrw, float* berr, lapack_int n_err_bnds,
                            float* err_bnds_norm, float* err_bnds_comp,
                            lapack_int nparams, float* params );
lapack_int LAPACKE_dposvxx( int matrix_order, char fact, char uplo,
                            lapack_int n, lapack_int nrhs, double* a,
                            lapack_int lda, double* af, lapack_int ldaf,
                            char* equed, double* s, double* b, lapack_int ldb,
                            double* x, lapack_int ldx, double* rcond,
                            double* rpvgrw, double* berr, lapack_int n_err_bnds,
                            double* err_bnds_norm, double* err_bnds_comp,
                            lapack_int nparams, double* params );
lapack_int LAPACKE_cposvxx( int matrix_order, char fact, char uplo,
                            lapack_int n, lapack_int nrhs,
                            lapack_complex_float* a, lapack_int lda,
                            lapack_complex_float* af, lapack_int ldaf,
                            char* equed, float* s, lapack_complex_float* b,
                            lapack_int ldb, lapack_complex_float* x,
                            lapack_int ldx, float* rcond, float* rpvgrw,
                            float* berr, lapack_int n_err_bnds,
                            float* err_bnds_norm, float* err_bnds_comp,
                            lapack_int nparams, float* params );
lapack_int LAPACKE_zposvxx( int matrix_order, char fact, char uplo,
                            lapack_int n, lapack_int nrhs,
                            lapack_complex_double* a, lapack_int lda,
                            lapack_complex_double* af, lapack_int ldaf,
                            char* equed, double* s, lapack_complex_double* b,
                            lapack_int ldb, lapack_complex_double* x,
                            lapack_int ldx, double* rcond, double* rpvgrw,
                            double* berr, lapack_int n_err_bnds,
                            double* err_bnds_norm, double* err_bnds_comp,
                            lapack_int nparams, double* params );

lapack_int LAPACKE_spotrf( int matrix_order, char uplo, lapack_int n, float* a,
                           lapack_int lda );
lapack_int LAPACKE_dpotrf( int matrix_order, char uplo, lapack_int n, double* a,
                           lapack_int lda );
lapack_int LAPACKE_cpotrf( int matrix_order, char uplo, lapack_int n,
                           lapack_complex_float* a, lapack_int lda );
lapack_int LAPACKE_zpotrf( int matrix_order, char uplo, lapack_int n,
                           lapack_complex_double* a, lapack_int lda );

lapack_int LAPACKE_spotri( int matrix_order, char uplo, lapack_int n, float* a,
                           lapack_int lda );
lapack_int LAPACKE_dpotri( int matrix_order, char uplo, lapack_int n, double* a,
                           lapack_int lda );
lapack_int LAPACKE_cpotri( int matrix_order, char uplo, lapack_int n,
                           lapack_complex_float* a, lapack_int lda );
lapack_int LAPACKE_zpotri( int matrix_order, char uplo, lapack_int n,
                           lapack_complex_double* a, lapack_int lda );

lapack_int LAPACKE_spotrs( int matrix_order, char uplo, lapack_int n,
                           lapack_int nrhs, const float* a, lapack_int lda,
                           float* b, lapack_int ldb );
lapack_int LAPACKE_dpotrs( int matrix_order, char uplo, lapack_int n,
                           lapack_int nrhs, const double* a, lapack_int lda,
                           double* b, lapack_int ldb );
lapack_int LAPACKE_cpotrs( int matrix_order, char uplo, lapack_int n,
                           lapack_int nrhs, const lapack_complex_float* a,
                           lapack_int lda, lapack_complex_float* b,
                           lapack_int ldb );
lapack_int LAPACKE_zpotrs( int matrix_order, char uplo, lapack_int n,
                           lapack_int nrhs, const lapack_complex_double* a,
                           lapack_int lda, lapack_complex_double* b,
                           lapack_int ldb );

lapack_int LAPACKE_sppcon( int matrix_order, char uplo, lapack_int n,
                           const float* ap, float anorm, float* rcond );
lapack_int LAPACKE_dppcon( int matrix_order, char uplo, lapack_int n,
                           const double* ap, double anorm, double* rcond );
lapack_int LAPACKE_cppcon( int matrix_order, char uplo, lapack_int n,
                           const lapack_complex_float* ap, float anorm,
                           float* rcond );
lapack_int LAPACKE_zppcon( int matrix_order, char uplo, lapack_int n,
                           const lapack_complex_double* ap, double anorm,
                           double* rcond );

lapack_int LAPACKE_sppequ( int matrix_order, char uplo, lapack_int n,
                           const float* ap, float* s, float* scond,
                           float* amax );
lapack_int LAPACKE_dppequ( int matrix_order, char uplo, lapack_int n,
                           const double* ap, double* s, double* scond,
                           double* amax );
lapack_int LAPACKE_cppequ( int matrix_order, char uplo, lapack_int n,
                           const lapack_complex_float* ap, float* s,
                           float* scond, float* amax );
lapack_int LAPACKE_zppequ( int matrix_order, char uplo, lapack_int n,
                           const lapack_complex_double* ap, double* s,
                           double* scond, double* amax );

lapack_int LAPACKE_spprfs( int matrix_order, char uplo, lapack_int n,
                           lapack_int nrhs, const float* ap, const float* afp,
                           const float* b, lapack_int ldb, float* x,
                           lapack_int ldx, float* ferr, float* berr );
lapack_int LAPACKE_dpprfs( int matrix_order, char uplo, lapack_int n,
                           lapack_int nrhs, const double* ap, const double* afp,
                           const double* b, lapack_int ldb, double* x,
                           lapack_int ldx, double* ferr, double* berr );
lapack_int LAPACKE_cpprfs( int matrix_order, char uplo, lapack_int n,
                           lapack_int nrhs, const lapack_complex_float* ap,
                           const lapack_complex_float* afp,
                           const lapack_complex_float* b, lapack_int ldb,
                           lapack_complex_float* x, lapack_int ldx, float* ferr,
                           float* berr );
lapack_int LAPACKE_zpprfs( int matrix_order, char uplo, lapack_int n,
                           lapack_int nrhs, const lapack_complex_double* ap,
                           const lapack_complex_double* afp,
                           const lapack_complex_double* b, lapack_int ldb,
                           lapack_complex_double* x, lapack_int ldx,
                           double* ferr, double* berr );

lapack_int LAPACKE_sppsv( int matrix_order, char uplo, lapack_int n,
                          lapack_int nrhs, float* ap, float* b,
                          lapack_int ldb );
lapack_int LAPACKE_dppsv( int matrix_order, char uplo, lapack_int n,
                          lapack_int nrhs, double* ap, double* b,
                          lapack_int ldb );
lapack_int LAPACKE_cppsv( int matrix_order, char uplo, lapack_int n,
                          lapack_int nrhs, lapack_complex_float* ap,
                          lapack_complex_float* b, lapack_int ldb );
lapack_int LAPACKE_zppsv( int matrix_order, char uplo, lapack_int n,
                          lapack_int nrhs, lapack_complex_double* ap,
                          lapack_complex_double* b, lapack_int ldb );

lapack_int LAPACKE_sppsvx( int matrix_order, char fact, char uplo, lapack_int n,
                           lapack_int nrhs, float* ap, float* afp, char* equed,
                           float* s, float* b, lapack_int ldb, float* x,
                           lapack_int ldx, float* rcond, float* ferr,
                           float* berr );
lapack_int LAPACKE_dppsvx( int matrix_order, char fact, char uplo, lapack_int n,
                           lapack_int nrhs, double* ap, double* afp,
                           char* equed, double* s, double* b, lapack_int ldb,
                           double* x, lapack_int ldx, double* rcond,
                           double* ferr, double* berr );
lapack_int LAPACKE_cppsvx( int matrix_order, char fact, char uplo, lapack_int n,
                           lapack_int nrhs, lapack_complex_float* ap,
                           lapack_complex_float* afp, char* equed, float* s,
                           lapack_complex_float* b, lapack_int ldb,
                           lapack_complex_float* x, lapack_int ldx,
                           float* rcond, float* ferr, float* berr );
lapack_int LAPACKE_zppsvx( int matrix_order, char fact, char uplo, lapack_int n,
                           lapack_int nrhs, lapack_complex_double* ap,
                           lapack_complex_double* afp, char* equed, double* s,
                           lapack_complex_double* b, lapack_int ldb,
                           lapack_complex_double* x, lapack_int ldx,
                           double* rcond, double* ferr, double* berr );

lapack_int LAPACKE_spptrf( int matrix_order, char uplo, lapack_int n,
                           float* ap );
lapack_int LAPACKE_dpptrf( int matrix_order, char uplo, lapack_int n,
                           double* ap );
lapack_int LAPACKE_cpptrf( int matrix_order, char uplo, lapack_int n,
                           lapack_complex_float* ap );
lapack_int LAPACKE_zpptrf( int matrix_order, char uplo, lapack_int n,
                           lapack_complex_double* ap );

lapack_int LAPACKE_spptri( int matrix_order, char uplo, lapack_int n,
                           float* ap );
lapack_int LAPACKE_dpptri( int matrix_order, char uplo, lapack_int n,
                           double* ap );
lapack_int LAPACKE_cpptri( int matrix_order, char uplo, lapack_int n,
                           lapack_complex_float* ap );
lapack_int LAPACKE_zpptri( int matrix_order, char uplo, lapack_int n,
                           lapack_complex_double* ap );

lapack_int LAPACKE_spptrs( int matrix_order, char uplo, lapack_int n,
                           lapack_int nrhs, const float* ap, float* b,
                           lapack_int ldb );
lapack_int LAPACKE_dpptrs( int matrix_order, char uplo, lapack_int n,
                           lapack_int nrhs, const double* ap, double* b,
                           lapack_int ldb );
lapack_int LAPACKE_cpptrs( int matrix_order, char uplo, lapack_int n,
                           lapack_int nrhs, const lapack_complex_float* ap,
                           lapack_complex_float* b, lapack_int ldb );
lapack_int LAPACKE_zpptrs( int matrix_order, char uplo, lapack_int n,
                           lapack_int nrhs, const lapack_complex_double* ap,
                           lapack_complex_double* b, lapack_int ldb );

lapack_int LAPACKE_spstrf( int matrix_order, char uplo, lapack_int n, float* a,
                           lapack_int lda, lapack_int* piv, lapack_int* rank,
                           float tol );
lapack_int LAPACKE_dpstrf( int matrix_order, char uplo, lapack_int n, double* a,
                           lapack_int lda, lapack_int* piv, lapack_int* rank,
                           double tol );
lapack_int LAPACKE_cpstrf( int matrix_order, char uplo, lapack_int n,
                           lapack_complex_float* a, lapack_int lda,
                           lapack_int* piv, lapack_int* rank, float tol );
lapack_int LAPACKE_zpstrf( int matrix_order, char uplo, lapack_int n,
                           lapack_complex_double* a, lapack_int lda,
                           lapack_int* piv, lapack_int* rank, double tol );

lapack_int LAPACKE_sptcon( lapack_int n, const float* d, const float* e,
                           float anorm, float* rcond );
lapack_int LAPACKE_dptcon( lapack_int n, const double* d, const double* e,
                           double anorm, double* rcond );
lapack_int LAPACKE_cptcon( lapack_int n, const float* d,
                           const lapack_complex_float* e, float anorm,
                           float* rcond );
lapack_int LAPACKE_zptcon( lapack_int n, const double* d,
                           const lapack_complex_double* e, double anorm,
                           double* rcond );

lapack_int LAPACKE_spteqr( int matrix_order, char compz, lapack_int n, float* d,
                           float* e, float* z, lapack_int ldz );
lapack_int LAPACKE_dpteqr( int matrix_order, char compz, lapack_int n,
                           double* d, double* e, double* z, lapack_int ldz );
lapack_int LAPACKE_cpteqr( int matrix_order, char compz, lapack_int n, float* d,
                           float* e, lapack_complex_float* z, lapack_int ldz );
lapack_int LAPACKE_zpteqr( int matrix_order, char compz, lapack_int n,
                           double* d, double* e, lapack_complex_double* z,
                           lapack_int ldz );

lapack_int LAPACKE_sptrfs( int matrix_order, lapack_int n, lapack_int nrhs,
                           const float* d, const float* e, const float* df,
                           const float* ef, const float* b, lapack_int ldb,
                           float* x, lapack_int ldx, float* ferr, float* berr );
lapack_int LAPACKE_dptrfs( int matrix_order, lapack_int n, lapack_int nrhs,
                           const double* d, const double* e, const double* df,
                           const double* ef, const double* b, lapack_int ldb,
                           double* x, lapack_int ldx, double* ferr,
                           double* berr );
lapack_int LAPACKE_cptrfs( int matrix_order, char uplo, lapack_int n,
                           lapack_int nrhs, const float* d,
                           const lapack_complex_float* e, const float* df,
                           const lapack_complex_float* ef,
                           const lapack_complex_float* b, lapack_int ldb,
                           lapack_complex_float* x, lapack_int ldx, float* ferr,
                           float* berr );
lapack_int LAPACKE_zptrfs( int matrix_order, char uplo, lapack_int n,
                           lapack_int nrhs, const double* d,
                           const lapack_complex_double* e, const double* df,
                           const lapack_complex_double* ef,
                           const lapack_complex_double* b, lapack_int ldb,
                           lapack_complex_double* x, lapack_int ldx,
                           double* ferr, double* berr );

lapack_int LAPACKE_sptsv( int matrix_order, lapack_int n, lapack_int nrhs,
                          float* d, float* e, float* b, lapack_int ldb );
lapack_int LAPACKE_dptsv( int matrix_order, lapack_int n, lapack_int nrhs,
                          double* d, double* e, double* b, lapack_int ldb );
lapack_int LAPACKE_cptsv( int matrix_order, lapack_int n, lapack_int nrhs,
                          float* d, lapack_complex_float* e,
                          lapack_complex_float* b, lapack_int ldb );
lapack_int LAPACKE_zptsv( int matrix_order, lapack_int n, lapack_int nrhs,
                          double* d, lapack_complex_double* e,
                          lapack_complex_double* b, lapack_int ldb );

lapack_int LAPACKE_sptsvx( int matrix_order, char fact, lapack_int n,
                           lapack_int nrhs, const float* d, const float* e,
                           float* df, float* ef, const float* b, lapack_int ldb,
                           float* x, lapack_int ldx, float* rcond, float* ferr,
                           float* berr );
lapack_int LAPACKE_dptsvx( int matrix_order, char fact, lapack_int n,
                           lapack_int nrhs, const double* d, const double* e,
                           double* df, double* ef, const double* b,
                           lapack_int ldb, double* x, lapack_int ldx,
                           double* rcond, double* ferr, double* berr );
lapack_int LAPACKE_cptsvx( int matrix_order, char fact, lapack_int n,
                           lapack_int nrhs, const float* d,
                           const lapack_complex_float* e, float* df,
                           lapack_complex_float* ef,
                           const lapack_complex_float* b, lapack_int ldb,
                           lapack_complex_float* x, lapack_int ldx,
                           float* rcond, float* ferr, float* berr );
lapack_int LAPACKE_zptsvx( int matrix_order, char fact, lapack_int n,
                           lapack_int nrhs, const double* d,
                           const lapack_complex_double* e, double* df,
                           lapack_complex_double* ef,
                           const lapack_complex_double* b, lapack_int ldb,
                           lapack_complex_double* x, lapack_int ldx,
                           double* rcond, double* ferr, double* berr );

lapack_int LAPACKE_spttrf( lapack_int n, float* d, float* e );
lapack_int LAPACKE_dpttrf( lapack_int n, double* d, double* e );
lapack_int LAPACKE_cpttrf( lapack_int n, float* d, lapack_complex_float* e );
lapack_int LAPACKE_zpttrf( lapack_int n, double* d, lapack_complex_double* e );

lapack_int LAPACKE_spttrs( int matrix_order, lapack_int n, lapack_int nrhs,
                           const float* d, const float* e, float* b,
                           lapack_int ldb );
lapack_int LAPACKE_dpttrs( int matrix_order, lapack_int n, lapack_int nrhs,
                           const double* d, const double* e, double* b,
                           lapack_int ldb );
lapack_int LAPACKE_cpttrs( int matrix_order, char uplo, lapack_int n,
                           lapack_int nrhs, const float* d,
                           const lapack_complex_float* e,
                           lapack_complex_float* b, lapack_int ldb );
lapack_int LAPACKE_zpttrs( int matrix_order, char uplo, lapack_int n,
                           lapack_int nrhs, const double* d,
                           const lapack_complex_double* e,
                           lapack_complex_double* b, lapack_int ldb );

lapack_int LAPACKE_ssbev( int matrix_order, char jobz, char uplo, lapack_int n,
                          lapack_int kd, float* ab, lapack_int ldab, float* w,
                          float* z, lapack_int ldz );
lapack_int LAPACKE_dsbev( int matrix_order, char jobz, char uplo, lapack_int n,
                          lapack_int kd, double* ab, lapack_int ldab, double* w,
                          double* z, lapack_int ldz );

lapack_int LAPACKE_ssbevd( int matrix_order, char jobz, char uplo, lapack_int n,
                           lapack_int kd, float* ab, lapack_int ldab, float* w,
                           float* z, lapack_int ldz );
lapack_int LAPACKE_dsbevd( int matrix_order, char jobz, char uplo, lapack_int n,
                           lapack_int kd, double* ab, lapack_int ldab,
                           double* w, double* z, lapack_int ldz );

lapack_int LAPACKE_ssbevx( int matrix_order, char jobz, char range, char uplo,
                           lapack_int n, lapack_int kd, float* ab,
                           lapack_int ldab, float* q, lapack_int ldq, float vl,
                           float vu, lapack_int il, lapack_int iu, float abstol,
                           lapack_int* m, float* w, float* z, lapack_int ldz,
                           lapack_int* ifail );
lapack_int LAPACKE_dsbevx( int matrix_order, char jobz, char range, char uplo,
                           lapack_int n, lapack_int kd, double* ab,
                           lapack_int ldab, double* q, lapack_int ldq,
                           double vl, double vu, lapack_int il, lapack_int iu,
                           double abstol, lapack_int* m, double* w, double* z,
                           lapack_int ldz, lapack_int* ifail );

lapack_int LAPACKE_ssbgst( int matrix_order, char vect, char uplo, lapack_int n,
                           lapack_int ka, lapack_int kb, float* ab,
                           lapack_int ldab, const float* bb, lapack_int ldbb,
                           float* x, lapack_int ldx );
lapack_int LAPACKE_dsbgst( int matrix_order, char vect, char uplo, lapack_int n,
                           lapack_int ka, lapack_int kb, double* ab,
                           lapack_int ldab, const double* bb, lapack_int ldbb,
                           double* x, lapack_int ldx );

lapack_int LAPACKE_ssbgv( int matrix_order, char jobz, char uplo, lapack_int n,
                          lapack_int ka, lapack_int kb, float* ab,
                          lapack_int ldab, float* bb, lapack_int ldbb, float* w,
                          float* z, lapack_int ldz );
lapack_int LAPACKE_dsbgv( int matrix_order, char jobz, char uplo, lapack_int n,
                          lapack_int ka, lapack_int kb, double* ab,
                          lapack_int ldab, double* bb, lapack_int ldbb,
                          double* w, double* z, lapack_int ldz );

lapack_int LAPACKE_ssbgvd( int matrix_order, char jobz, char uplo, lapack_int n,
                           lapack_int ka, lapack_int kb, float* ab,
                           lapack_int ldab, float* bb, lapack_int ldbb,
                           float* w, float* z, lapack_int ldz );
lapack_int LAPACKE_dsbgvd( int matrix_order, char jobz, char uplo, lapack_int n,
                           lapack_int ka, lapack_int kb, double* ab,
                           lapack_int ldab, double* bb, lapack_int ldbb,
                           double* w, double* z, lapack_int ldz );

lapack_int LAPACKE_ssbgvx( int matrix_order, char jobz, char range, char uplo,
                           lapack_int n, lapack_int ka, lapack_int kb,
                           float* ab, lapack_int ldab, float* bb,
                           lapack_int ldbb, float* q, lapack_int ldq, float vl,
                           float vu, lapack_int il, lapack_int iu, float abstol,
                           lapack_int* m, float* w, float* z, lapack_int ldz,
                           lapack_int* ifail );
lapack_int LAPACKE_dsbgvx( int matrix_order, char jobz, char range, char uplo,
                           lapack_int n, lapack_int ka, lapack_int kb,
                           double* ab, lapack_int ldab, double* bb,
                           lapack_int ldbb, double* q, lapack_int ldq,
                           double vl, double vu, lapack_int il, lapack_int iu,
                           double abstol, lapack_int* m, double* w, double* z,
                           lapack_int ldz, lapack_int* ifail );

lapack_int LAPACKE_ssbtrd( int matrix_order, char vect, char uplo, lapack_int n,
                           lapack_int kd, float* ab, lapack_int ldab, float* d,
                           float* e, float* q, lapack_int ldq );
lapack_int LAPACKE_dsbtrd( int matrix_order, char vect, char uplo, lapack_int n,
                           lapack_int kd, double* ab, lapack_int ldab,
                           double* d, double* e, double* q, lapack_int ldq );

lapack_int LAPACKE_ssfrk( int matrix_order, char transr, char uplo, char trans,
                          lapack_int n, lapack_int k, float alpha,
                          const float* a, lapack_int lda, float beta,
                          float* c );
lapack_int LAPACKE_dsfrk( int matrix_order, char transr, char uplo, char trans,
                          lapack_int n, lapack_int k, double alpha,
                          const double* a, lapack_int lda, double beta,
                          double* c );

lapack_int LAPACKE_sspcon( int matrix_order, char uplo, lapack_int n,
                           const float* ap, const lapack_int* ipiv, float anorm,
                           float* rcond );
lapack_int LAPACKE_dspcon( int matrix_order, char uplo, lapack_int n,
                           const double* ap, const lapack_int* ipiv,
                           double anorm, double* rcond );
lapack_int LAPACKE_cspcon( int matrix_order, char uplo, lapack_int n,
                           const lapack_complex_float* ap,
                           const lapack_int* ipiv, float anorm, float* rcond );
lapack_int LAPACKE_zspcon( int matrix_order, char uplo, lapack_int n,
                           const lapack_complex_double* ap,
                           const lapack_int* ipiv, double anorm,
                           double* rcond );

lapack_int LAPACKE_sspev( int matrix_order, char jobz, char uplo, lapack_int n,
                          float* ap, float* w, float* z, lapack_int ldz );
lapack_int LAPACKE_dspev( int matrix_order, char jobz, char uplo, lapack_int n,
                          double* ap, double* w, double* z, lapack_int ldz );

lapack_int LAPACKE_sspevd( int matrix_order, char jobz, char uplo, lapack_int n,
                           float* ap, float* w, float* z, lapack_int ldz );
lapack_int LAPACKE_dspevd( int matrix_order, char jobz, char uplo, lapack_int n,
                           double* ap, double* w, double* z, lapack_int ldz );

lapack_int LAPACKE_sspevx( int matrix_order, char jobz, char range, char uplo,
                           lapack_int n, float* ap, float vl, float vu,
                           lapack_int il, lapack_int iu, float abstol,
                           lapack_int* m, float* w, float* z, lapack_int ldz,
                           lapack_int* ifail );
lapack_int LAPACKE_dspevx( int matrix_order, char jobz, char range, char uplo,
                           lapack_int n, double* ap, double vl, double vu,
                           lapack_int il, lapack_int iu, double abstol,
                           lapack_int* m, double* w, double* z, lapack_int ldz,
                           lapack_int* ifail );

lapack_int LAPACKE_sspgst( int matrix_order, lapack_int itype, char uplo,
                           lapack_int n, float* ap, const float* bp );
lapack_int LAPACKE_dspgst( int matrix_order, lapack_int itype, char uplo,
                           lapack_int n, double* ap, const double* bp );

lapack_int LAPACKE_sspgv( int matrix_order, lapack_int itype, char jobz,
                          char uplo, lapack_int n, float* ap, float* bp,
                          float* w, float* z, lapack_int ldz );
lapack_int LAPACKE_dspgv( int matrix_order, lapack_int itype, char jobz,
                          char uplo, lapack_int n, double* ap, double* bp,
                          double* w, double* z, lapack_int ldz );

lapack_int LAPACKE_sspgvd( int matrix_order, lapack_int itype, char jobz,
                           char uplo, lapack_int n, float* ap, float* bp,
                           float* w, float* z, lapack_int ldz );
lapack_int LAPACKE_dspgvd( int matrix_order, lapack_int itype, char jobz,
                           char uplo, lapack_int n, double* ap, double* bp,
                           double* w, double* z, lapack_int ldz );

lapack_int LAPACKE_sspgvx( int matrix_order, lapack_int itype, char jobz,
                           char range, char uplo, lapack_int n, float* ap,
                           float* bp, float vl, float vu, lapack_int il,
                           lapack_int iu, float abstol, lapack_int* m, float* w,
                           float* z, lapack_int ldz, lapack_int* ifail );
lapack_int LAPACKE_dspgvx( int matrix_order, lapack_int itype, char jobz,
                           char range, char uplo, lapack_int n, double* ap,
                           double* bp, double vl, double vu, lapack_int il,
                           lapack_int iu, double abstol, lapack_int* m,
                           double* w, double* z, lapack_int ldz,
                           lapack_int* ifail );

lapack_int LAPACKE_ssprfs( int matrix_order, char uplo, lapack_int n,
                           lapack_int nrhs, const float* ap, const float* afp,
                           const lapack_int* ipiv, const float* b,
                           lapack_int ldb, float* x, lapack_int ldx,
                           float* ferr, float* berr );
lapack_int LAPACKE_dsprfs( int matrix_order, char uplo, lapack_int n,
                           lapack_int nrhs, const double* ap, const double* afp,
                           const lapack_int* ipiv, const double* b,
                           lapack_int ldb, double* x, lapack_int ldx,
                           double* ferr, double* berr );
lapack_int LAPACKE_csprfs( int matrix_order, char uplo, lapack_int n,
                           lapack_int nrhs, const lapack_complex_float* ap,
                           const lapack_complex_float* afp,
                           const lapack_int* ipiv,
                           const lapack_complex_float* b, lapack_int ldb,
                           lapack_complex_float* x, lapack_int ldx, float* ferr,
                           float* berr );
lapack_int LAPACKE_zsprfs( int matrix_order, char uplo, lapack_int n,
                           lapack_int nrhs, const lapack_complex_double* ap,
                           const lapack_complex_double* afp,
                           const lapack_int* ipiv,
                           const lapack_complex_double* b, lapack_int ldb,
                           lapack_complex_double* x, lapack_int ldx,
                           double* ferr, double* berr );

lapack_int LAPACKE_sspsv( int matrix_order, char uplo, lapack_int n,
                          lapack_int nrhs, float* ap, lapack_int* ipiv,
                          float* b, lapack_int ldb );
lapack_int LAPACKE_dspsv( int matrix_order, char uplo, lapack_int n,
                          lapack_int nrhs, double* ap, lapack_int* ipiv,
                          double* b, lapack_int ldb );
lapack_int LAPACKE_cspsv( int matrix_order, char uplo, lapack_int n,
                          lapack_int nrhs, lapack_complex_float* ap,
                          lapack_int* ipiv, lapack_complex_float* b,
                          lapack_int ldb );
lapack_int LAPACKE_zspsv( int matrix_order, char uplo, lapack_int n,
                          lapack_int nrhs, lapack_complex_double* ap,
                          lapack_int* ipiv, lapack_complex_double* b,
                          lapack_int ldb );

lapack_int LAPACKE_sspsvx( int matrix_order, char fact, char uplo, lapack_int n,
                           lapack_int nrhs, const float* ap, float* afp,
                           lapack_int* ipiv, const float* b, lapack_int ldb,
                           float* x, lapack_int ldx, float* rcond, float* ferr,
                           float* berr );
lapack_int LAPACKE_dspsvx( int matrix_order, char fact, char uplo, lapack_int n,
                           lapack_int nrhs, const double* ap, double* afp,
                           lapack_int* ipiv, const double* b, lapack_int ldb,
                           double* x, lapack_int ldx, double* rcond,
                           double* ferr, double* berr );
lapack_int LAPACKE_cspsvx( int matrix_order, char fact, char uplo, lapack_int n,
                           lapack_int nrhs, const lapack_complex_float* ap,
                           lapack_complex_float* afp, lapack_int* ipiv,
                           const lapack_complex_float* b, lapack_int ldb,
                           lapack_complex_float* x, lapack_int ldx,
                           float* rcond, float* ferr, float* berr );
lapack_int LAPACKE_zspsvx( int matrix_order, char fact, char uplo, lapack_int n,
                           lapack_int nrhs, const lapack_complex_double* ap,
                           lapack_complex_double* afp, lapack_int* ipiv,
                           const lapack_complex_double* b, lapack_int ldb,
                           lapack_complex_double* x, lapack_int ldx,
                           double* rcond, double* ferr, double* berr );

lapack_int LAPACKE_ssptrd( int matrix_order, char uplo, lapack_int n, float* ap,
                           float* d, float* e, float* tau );
lapack_int LAPACKE_dsptrd( int matrix_order, char uplo, lapack_int n,
                           double* ap, double* d, double* e, double* tau );

lapack_int LAPACKE_ssptrf( int matrix_order, char uplo, lapack_int n, float* ap,
                           lapack_int* ipiv );
lapack_int LAPACKE_dsptrf( int matrix_order, char uplo, lapack_int n,
                           double* ap, lapack_int* ipiv );
lapack_int LAPACKE_csptrf( int matrix_order, char uplo, lapack_int n,
                           lapack_complex_float* ap, lapack_int* ipiv );
lapack_int LAPACKE_zsptrf( int matrix_order, char uplo, lapack_int n,
                           lapack_complex_double* ap, lapack_int* ipiv );

lapack_int LAPACKE_ssptri( int matrix_order, char uplo, lapack_int n, float* ap,
                           const lapack_int* ipiv );
lapack_int LAPACKE_dsptri( int matrix_order, char uplo, lapack_int n,
                           double* ap, const lapack_int* ipiv );
lapack_int LAPACKE_csptri( int matrix_order, char uplo, lapack_int n,
                           lapack_complex_float* ap, const lapack_int* ipiv );
lapack_int LAPACKE_zsptri( int matrix_order, char uplo, lapack_int n,
                           lapack_complex_double* ap, const lapack_int* ipiv );

lapack_int LAPACKE_ssptrs( int matrix_order, char uplo, lapack_int n,
                           lapack_int nrhs, const float* ap,
                           const lapack_int* ipiv, float* b, lapack_int ldb );
lapack_int LAPACKE_dsptrs( int matrix_order, char uplo, lapack_int n,
                           lapack_int nrhs, const double* ap,
                           const lapack_int* ipiv, double* b, lapack_int ldb );
lapack_int LAPACKE_csptrs( int matrix_order, char uplo, lapack_int n,
                           lapack_int nrhs, const lapack_complex_float* ap,
                           const lapack_int* ipiv, lapack_complex_float* b,
                           lapack_int ldb );
lapack_int LAPACKE_zsptrs( int matrix_order, char uplo, lapack_int n,
                           lapack_int nrhs, const lapack_complex_double* ap,
                           const lapack_int* ipiv, lapack_complex_double* b,
                           lapack_int ldb );

lapack_int LAPACKE_sstebz( char range, char order, lapack_int n, float vl,
                           float vu, lapack_int il, lapack_int iu, float abstol,
                           const float* d, const float* e, lapack_int* m,
                           lapack_int* nsplit, float* w, lapack_int* iblock,
                           lapack_int* isplit );
lapack_int LAPACKE_dstebz( char range, char order, lapack_int n, double vl,
                           double vu, lapack_int il, lapack_int iu,
                           double abstol, const double* d, const double* e,
                           lapack_int* m, lapack_int* nsplit, double* w,
                           lapack_int* iblock, lapack_int* isplit );

lapack_int LAPACKE_sstedc( int matrix_order, char compz, lapack_int n, float* d,
                           float* e, float* z, lapack_int ldz );
lapack_int LAPACKE_dstedc( int matrix_order, char compz, lapack_int n,
                           double* d, double* e, double* z, lapack_int ldz );
lapack_int LAPACKE_cstedc( int matrix_order, char compz, lapack_int n, float* d,
                           float* e, lapack_complex_float* z, lapack_int ldz );
lapack_int LAPACKE_zstedc( int matrix_order, char compz, lapack_int n,
                           double* d, double* e, lapack_complex_double* z,
                           lapack_int ldz );

lapack_int LAPACKE_sstegr( int matrix_order, char jobz, char range,
                           lapack_int n, float* d, float* e, float vl, float vu,
                           lapack_int il, lapack_int iu, float abstol,
                           lapack_int* m, float* w, float* z, lapack_int ldz,
                           lapack_int* isuppz );
lapack_int LAPACKE_dstegr( int matrix_order, char jobz, char range,
                           lapack_int n, double* d, double* e, double vl,
                           double vu, lapack_int il, lapack_int iu,
                           double abstol, lapack_int* m, double* w, double* z,
                           lapack_int ldz, lapack_int* isuppz );
lapack_int LAPACKE_cstegr( int matrix_order, char jobz, char range,
                           lapack_int n, float* d, float* e, float vl, float vu,
                           lapack_int il, lapack_int iu, float abstol,
                           lapack_int* m, float* w, lapack_complex_float* z,
                           lapack_int ldz, lapack_int* isuppz );
lapack_int LAPACKE_zstegr( int matrix_order, char jobz, char range,
                           lapack_int n, double* d, double* e, double vl,
                           double vu, lapack_int il, lapack_int iu,
                           double abstol, lapack_int* m, double* w,
                           lapack_complex_double* z, lapack_int ldz,
                           lapack_int* isuppz );

lapack_int LAPACKE_sstein( int matrix_order, lapack_int n, const float* d,
                           const float* e, lapack_int m, const float* w,
                           const lapack_int* iblock, const lapack_int* isplit,
                           float* z, lapack_int ldz, lapack_int* ifailv );
lapack_int LAPACKE_dstein( int matrix_order, lapack_int n, const double* d,
                           const double* e, lapack_int m, const double* w,
                           const lapack_int* iblock, const lapack_int* isplit,
                           double* z, lapack_int ldz, lapack_int* ifailv );
lapack_int LAPACKE_cstein( int matrix_order, lapack_int n, const float* d,
                           const float* e, lapack_int m, const float* w,
                           const lapack_int* iblock, const lapack_int* isplit,
                           lapack_complex_float* z, lapack_int ldz,
                           lapack_int* ifailv );
lapack_int LAPACKE_zstein( int matrix_order, lapack_int n, const double* d,
                           const double* e, lapack_int m, const double* w,
                           const lapack_int* iblock, const lapack_int* isplit,
                           lapack_complex_double* z, lapack_int ldz,
                           lapack_int* ifailv );

lapack_int LAPACKE_sstemr( int matrix_order, char jobz, char range,
                           lapack_int n, float* d, float* e, float vl, float vu,
                           lapack_int il, lapack_int iu, lapack_int* m,
                           float* w, float* z, lapack_int ldz, lapack_int nzc,
                           lapack_int* isuppz, lapack_logical* tryrac );
lapack_int LAPACKE_dstemr( int matrix_order, char jobz, char range,
                           lapack_int n, double* d, double* e, double vl,
                           double vu, lapack_int il, lapack_int iu,
                           lapack_int* m, double* w, double* z, lapack_int ldz,
                           lapack_int nzc, lapack_int* isuppz,
                           lapack_logical* tryrac );
lapack_int LAPACKE_cstemr( int matrix_order, char jobz, char range,
                           lapack_int n, float* d, float* e, float vl, float vu,
                           lapack_int il, lapack_int iu, lapack_int* m,
                           float* w, lapack_complex_float* z, lapack_int ldz,
                           lapack_int nzc, lapack_int* isuppz,
                           lapack_logical* tryrac );
lapack_int LAPACKE_zstemr( int matrix_order, char jobz, char range,
                           lapack_int n, double* d, double* e, double vl,
                           double vu, lapack_int il, lapack_int iu,
                           lapack_int* m, double* w, lapack_complex_double* z,
                           lapack_int ldz, lapack_int nzc, lapack_int* isuppz,
                           lapack_logical* tryrac );

lapack_int LAPACKE_ssteqr( int matrix_order, char compz, lapack_int n, float* d,
                           float* e, float* z, lapack_int ldz );
lapack_int LAPACKE_dsteqr( int matrix_order, char compz, lapack_int n,
                           double* d, double* e, double* z, lapack_int ldz );
lapack_int LAPACKE_csteqr( int matrix_order, char compz, lapack_int n, float* d,
                           float* e, lapack_complex_float* z, lapack_int ldz );
lapack_int LAPACKE_zsteqr( int matrix_order, char compz, lapack_int n,
                           double* d, double* e, lapack_complex_double* z,
                           lapack_int ldz );

lapack_int LAPACKE_ssterf( lapack_int n, float* d, float* e );
lapack_int LAPACKE_dsterf( lapack_int n, double* d, double* e );

lapack_int LAPACKE_sstev( int matrix_order, char jobz, lapack_int n, float* d,
                          float* e, float* z, lapack_int ldz );
lapack_int LAPACKE_dstev( int matrix_order, char jobz, lapack_int n, double* d,
                          double* e, double* z, lapack_int ldz );

lapack_int LAPACKE_sstevd( int matrix_order, char jobz, lapack_int n, float* d,
                           float* e, float* z, lapack_int ldz );
lapack_int LAPACKE_dstevd( int matrix_order, char jobz, lapack_int n, double* d,
                           double* e, double* z, lapack_int ldz );

lapack_int LAPACKE_sstevr( int matrix_order, char jobz, char range,
                           lapack_int n, float* d, float* e, float vl, float vu,
                           lapack_int il, lapack_int iu, float abstol,
                           lapack_int* m, float* w, float* z, lapack_int ldz,
                           lapack_int* isuppz );
lapack_int LAPACKE_dstevr( int matrix_order, char jobz, char range,
                           lapack_int n, double* d, double* e, double vl,
                           double vu, lapack_int il, lapack_int iu,
                           double abstol, lapack_int* m, double* w, double* z,
                           lapack_int ldz, lapack_int* isuppz );

lapack_int LAPACKE_sstevx( int matrix_order, char jobz, char range,
                           lapack_int n, float* d, float* e, float vl, float vu,
                           lapack_int il, lapack_int iu, float abstol,
                           lapack_int* m, float* w, float* z, lapack_int ldz,
                           lapack_int* ifail );
lapack_int LAPACKE_dstevx( int matrix_order, char jobz, char range,
                           lapack_int n, double* d, double* e, double vl,
                           double vu, lapack_int il, lapack_int iu,
                           double abstol, lapack_int* m, double* w, double* z,
                           lapack_int ldz, lapack_int* ifail );

lapack_int LAPACKE_ssycon( int matrix_order, char uplo, lapack_int n,
                           const float* a, lapack_int lda,
                           const lapack_int* ipiv, float anorm, float* rcond );
lapack_int LAPACKE_dsycon( int matrix_order, char uplo, lapack_int n,
                           const double* a, lapack_int lda,
                           const lapack_int* ipiv, double anorm,
                           double* rcond );
lapack_int LAPACKE_csycon( int matrix_order, char uplo, lapack_int n,
                           const lapack_complex_float* a, lapack_int lda,
                           const lapack_int* ipiv, float anorm, float* rcond );
lapack_int LAPACKE_zsycon( int matrix_order, char uplo, lapack_int n,
                           const lapack_complex_double* a, lapack_int lda,
                           const lapack_int* ipiv, double anorm,
                           double* rcond );

lapack_int LAPACKE_ssyequb( int matrix_order, char uplo, lapack_int n,
                            const float* a, lapack_int lda, float* s,
                            float* scond, float* amax );
lapack_int LAPACKE_dsyequb( int matrix_order, char uplo, lapack_int n,
                            const double* a, lapack_int lda, double* s,
                            double* scond, double* amax );
lapack_int LAPACKE_csyequb( int matrix_order, char uplo, lapack_int n,
                            const lapack_complex_float* a, lapack_int lda,
                            float* s, float* scond, float* amax );
lapack_int LAPACKE_zsyequb( int matrix_order, char uplo, lapack_int n,
                            const lapack_complex_double* a, lapack_int lda,
                            double* s, double* scond, double* amax );

lapack_int LAPACKE_ssyev( int matrix_order, char jobz, char uplo, lapack_int n,
                          float* a, lapack_int lda, float* w );
lapack_int LAPACKE_dsyev( int matrix_order, char jobz, char uplo, lapack_int n,
                          double* a, lapack_int lda, double* w );

lapack_int LAPACKE_ssyevd( int matrix_order, char jobz, char uplo, lapack_int n,
                           float* a, lapack_int lda, float* w );
lapack_int LAPACKE_dsyevd( int matrix_order, char jobz, char uplo, lapack_int n,
                           double* a, lapack_int lda, double* w );

lapack_int LAPACKE_ssyevr( int matrix_order, char jobz, char range, char uplo,
                           lapack_int n, float* a, lapack_int lda, float vl,
                           float vu, lapack_int il, lapack_int iu, float abstol,
                           lapack_int* m, float* w, float* z, lapack_int ldz,
                           lapack_int* isuppz );
lapack_int LAPACKE_dsyevr( int matrix_order, char jobz, char range, char uplo,
                           lapack_int n, double* a, lapack_int lda, double vl,
                           double vu, lapack_int il, lapack_int iu,
                           double abstol, lapack_int* m, double* w, double* z,
                           lapack_int ldz, lapack_int* isuppz );

lapack_int LAPACKE_ssyevx( int matrix_order, char jobz, char range, char uplo,
                           lapack_int n, float* a, lapack_int lda, float vl,
                           float vu, lapack_int il, lapack_int iu, float abstol,
                           lapack_int* m, float* w, float* z, lapack_int ldz,
                           lapack_int* ifail );
lapack_int LAPACKE_dsyevx( int matrix_order, char jobz, char range, char uplo,
                           lapack_int n, double* a, lapack_int lda, double vl,
                           double vu, lapack_int il, lapack_int iu,
                           double abstol, lapack_int* m, double* w, double* z,
                           lapack_int ldz, lapack_int* ifail );

lapack_int LAPACKE_ssygst( int matrix_order, lapack_int itype, char uplo,
                           lapack_int n, float* a, lapack_int lda,
                           const float* b, lapack_int ldb );
lapack_int LAPACKE_dsygst( int matrix_order, lapack_int itype, char uplo,
                           lapack_int n, double* a, lapack_int lda,
                           const double* b, lapack_int ldb );

lapack_int LAPACKE_ssygv( int matrix_order, lapack_int itype, char jobz,
                          char uplo, lapack_int n, float* a, lapack_int lda,
                          float* b, lapack_int ldb, float* w );
lapack_int LAPACKE_dsygv( int matrix_order, lapack_int itype, char jobz,
                          char uplo, lapack_int n, double* a, lapack_int lda,
                          double* b, lapack_int ldb, double* w );

lapack_int LAPACKE_ssygvd( int matrix_order, lapack_int itype, char jobz,
                           char uplo, lapack_int n, float* a, lapack_int lda,
                           float* b, lapack_int ldb, float* w );
lapack_int LAPACKE_dsygvd( int matrix_order, lapack_int itype, char jobz,
                           char uplo, lapack_int n, double* a, lapack_int lda,
                           double* b, lapack_int ldb, double* w );

lapack_int LAPACKE_ssygvx( int matrix_order, lapack_int itype, char jobz,
                           char range, char uplo, lapack_int n, float* a,
                           lapack_int lda, float* b, lapack_int ldb, float vl,
                           float vu, lapack_int il, lapack_int iu, float abstol,
                           lapack_int* m, float* w, float* z, lapack_int ldz,
                           lapack_int* ifail );
lapack_int LAPACKE_dsygvx( int matrix_order, lapack_int itype, char jobz,
                           char range, char uplo, lapack_int n, double* a,
                           lapack_int lda, double* b, lapack_int ldb, double vl,
                           double vu, lapack_int il, lapack_int iu,
                           double abstol, lapack_int* m, double* w, double* z,
                           lapack_int ldz, lapack_int* ifail );

lapack_int LAPACKE_ssyrfs( int matrix_order, char uplo, lapack_int n,
                           lapack_int nrhs, const float* a, lapack_int lda,
                           const float* af, lapack_int ldaf,
                           const lapack_int* ipiv, const float* b,
                           lapack_int ldb, float* x, lapack_int ldx,
                           float* ferr, float* berr );
lapack_int LAPACKE_dsyrfs( int matrix_order, char uplo, lapack_int n,
                           lapack_int nrhs, const double* a, lapack_int lda,
                           const double* af, lapack_int ldaf,
                           const lapack_int* ipiv, const double* b,
                           lapack_int ldb, double* x, lapack_int ldx,
                           double* ferr, double* berr );
lapack_int LAPACKE_csyrfs( int matrix_order, char uplo, lapack_int n,
                           lapack_int nrhs, const lapack_complex_float* a,
                           lapack_int lda, const lapack_complex_float* af,
                           lapack_int ldaf, const lapack_int* ipiv,
                           const lapack_complex_float* b, lapack_int ldb,
                           lapack_complex_float* x, lapack_int ldx, float* ferr,
                           float* berr );
lapack_int LAPACKE_zsyrfs( int matrix_order, char uplo, lapack_int n,
                           lapack_int nrhs, const lapack_complex_double* a,
                           lapack_int lda, const lapack_complex_double* af,
                           lapack_int ldaf, const lapack_int* ipiv,
                           const lapack_complex_double* b, lapack_int ldb,
                           lapack_complex_double* x, lapack_int ldx,
                           double* ferr, double* berr );

lapack_int LAPACKE_ssyrfsx( int matrix_order, char uplo, char equed,
                            lapack_int n, lapack_int nrhs, const float* a,
                            lapack_int lda, const float* af, lapack_int ldaf,
                            const lapack_int* ipiv, const float* s,
                            const float* b, lapack_int ldb, float* x,
                            lapack_int ldx, float* rcond, float* berr,
                            lapack_int n_err_bnds, float* err_bnds_norm,
                            float* err_bnds_comp, lapack_int nparams,
                            float* params );
lapack_int LAPACKE_dsyrfsx( int matrix_order, char uplo, char equed,
                            lapack_int n, lapack_int nrhs, const double* a,
                            lapack_int lda, const double* af, lapack_int ldaf,
                            const lapack_int* ipiv, const double* s,
                            const double* b, lapack_int ldb, double* x,
                            lapack_int ldx, double* rcond, double* berr,
                            lapack_int n_err_bnds, double* err_bnds_norm,
                            double* err_bnds_comp, lapack_int nparams,
                            double* params );
lapack_int LAPACKE_csyrfsx( int matrix_order, char uplo, char equed,
                            lapack_int n, lapack_int nrhs,
                            const lapack_complex_float* a, lapack_int lda,
                            const lapack_complex_float* af, lapack_int ldaf,
                            const lapack_int* ipiv, const float* s,
                            const lapack_complex_float* b, lapack_int ldb,
                            lapack_complex_float* x, lapack_int ldx,
                            float* rcond, float* berr, lapack_int n_err_bnds,
                            float* err_bnds_norm, float* err_bnds_comp,
                            lapack_int nparams, float* params );
lapack_int LAPACKE_zsyrfsx( int matrix_order, char uplo, char equed,
                            lapack_int n, lapack_int nrhs,
                            const lapack_complex_double* a, lapack_int lda,
                            const lapack_complex_double* af, lapack_int ldaf,
                            const lapack_int* ipiv, const double* s,
                            const lapack_complex_double* b, lapack_int ldb,
                            lapack_complex_double* x, lapack_int ldx,
                            double* rcond, double* berr, lapack_int n_err_bnds,
                            double* err_bnds_norm, double* err_bnds_comp,
                            lapack_int nparams, double* params );

lapack_int LAPACKE_ssysv( int matrix_order, char uplo, lapack_int n,
                          lapack_int nrhs, float* a, lapack_int lda,
                          lapack_int* ipiv, float* b, lapack_int ldb );
lapack_int LAPACKE_dsysv( int matrix_order, char uplo, lapack_int n,
                          lapack_int nrhs, double* a, lapack_int lda,
                          lapack_int* ipiv, double* b, lapack_int ldb );
lapack_int LAPACKE_csysv( int matrix_order, char uplo, lapack_int n,
                          lapack_int nrhs, lapack_complex_float* a,
                          lapack_int lda, lapack_int* ipiv,
                          lapack_complex_float* b, lapack_int ldb );
lapack_int LAPACKE_zsysv( int matrix_order, char uplo, lapack_int n,
                          lapack_int nrhs, lapack_complex_double* a,
                          lapack_int lda, lapack_int* ipiv,
                          lapack_complex_double* b, lapack_int ldb );

lapack_int LAPACKE_ssysvx( int matrix_order, char fact, char uplo, lapack_int n,
                           lapack_int nrhs, const float* a, lapack_int lda,
                           float* af, lapack_int ldaf, lapack_int* ipiv,
                           const float* b, lapack_int ldb, float* x,
                           lapack_int ldx, float* rcond, float* ferr,
                           float* berr );
lapack_int LAPACKE_dsysvx( int matrix_order, char fact, char uplo, lapack_int n,
                           lapack_int nrhs, const double* a, lapack_int lda,
                           double* af, lapack_int ldaf, lapack_int* ipiv,
                           const double* b, lapack_int ldb, double* x,
                           lapack_int ldx, double* rcond, double* ferr,
                           double* berr );
lapack_int LAPACKE_csysvx( int matrix_order, char fact, char uplo, lapack_int n,
                           lapack_int nrhs, const lapack_complex_float* a,
                           lapack_int lda, lapack_complex_float* af,
                           lapack_int ldaf, lapack_int* ipiv,
                           const lapack_complex_float* b, lapack_int ldb,
                           lapack_complex_float* x, lapack_int ldx,
                           float* rcond, float* ferr, float* berr );
lapack_int LAPACKE_zsysvx( int matrix_order, char fact, char uplo, lapack_int n,
                           lapack_int nrhs, const lapack_complex_double* a,
                           lapack_int lda, lapack_complex_double* af,
                           lapack_int ldaf, lapack_int* ipiv,
                           const lapack_complex_double* b, lapack_int ldb,
                           lapack_complex_double* x, lapack_int ldx,
                           double* rcond, double* ferr, double* berr );

lapack_int LAPACKE_ssysvxx( int matrix_order, char fact, char uplo,
                            lapack_int n, lapack_int nrhs, float* a,
                            lapack_int lda, float* af, lapack_int ldaf,
                            lapack_int* ipiv, char* equed, float* s, float* b,
                            lapack_int ldb, float* x, lapack_int ldx,
                            float* rcond, float* rpvgrw, float* berr,
                            lapack_int n_err_bnds, float* err_bnds_norm,
                            float* err_bnds_comp, lapack_int nparams,
                            float* params );
lapack_int LAPACKE_dsysvxx( int matrix_order, char fact, char uplo,
                            lapack_int n, lapack_int nrhs, double* a,
                            lapack_int lda, double* af, lapack_int ldaf,
                            lapack_int* ipiv, char* equed, double* s, double* b,
                            lapack_int ldb, double* x, lapack_int ldx,
                            double* rcond, double* rpvgrw, double* berr,
                            lapack_int n_err_bnds, double* err_bnds_norm,
                            double* err_bnds_comp, lapack_int nparams,
                            double* params );
lapack_int LAPACKE_csysvxx( int matrix_order, char fact, char uplo,
                            lapack_int n, lapack_int nrhs,
                            lapack_complex_float* a, lapack_int lda,
                            lapack_complex_float* af, lapack_int ldaf,
                            lapack_int* ipiv, char* equed, float* s,
                            lapack_complex_float* b, lapack_int ldb,
                            lapack_complex_float* x, lapack_int ldx,
                            float* rcond, float* rpvgrw, float* berr,
                            lapack_int n_err_bnds, float* err_bnds_norm,
                            float* err_bnds_comp, lapack_int nparams,
                            float* params );
lapack_int LAPACKE_zsysvxx( int matrix_order, char fact, char uplo,
                            lapack_int n, lapack_int nrhs,
                            lapack_complex_double* a, lapack_int lda,
                            lapack_complex_double* af, lapack_int ldaf,
                            lapack_int* ipiv, char* equed, double* s,
                            lapack_complex_double* b, lapack_int ldb,
                            lapack_complex_double* x, lapack_int ldx,
                            double* rcond, double* rpvgrw, double* berr,
                            lapack_int n_err_bnds, double* err_bnds_norm,
                            double* err_bnds_comp, lapack_int nparams,
                            double* params );

lapack_int LAPACKE_ssytrd( int matrix_order, char uplo, lapack_int n, float* a,
                           lapack_int lda, float* d, float* e, float* tau );
lapack_int LAPACKE_dsytrd( int matrix_order, char uplo, lapack_int n, double* a,
                           lapack_int lda, double* d, double* e, double* tau );

lapack_int LAPACKE_ssytrf( int matrix_order, char uplo, lapack_int n, float* a,
                           lapack_int lda, lapack_int* ipiv );
lapack_int LAPACKE_dsytrf( int matrix_order, char uplo, lapack_int n, double* a,
                           lapack_int lda, lapack_int* ipiv );
lapack_int LAPACKE_csytrf( int matrix_order, char uplo, lapack_int n,
                           lapack_complex_float* a, lapack_int lda,
                           lapack_int* ipiv );
lapack_int LAPACKE_zsytrf( int matrix_order, char uplo, lapack_int n,
                           lapack_complex_double* a, lapack_int lda,
                           lapack_int* ipiv );

lapack_int LAPACKE_ssytri( int matrix_order, char uplo, lapack_int n, float* a,
                           lapack_int lda, const lapack_int* ipiv );
lapack_int LAPACKE_dsytri( int matrix_order, char uplo, lapack_int n, double* a,
                           lapack_int lda, const lapack_int* ipiv );
lapack_int LAPACKE_csytri( int matrix_order, char uplo, lapack_int n,
                           lapack_complex_float* a, lapack_int lda,
                           const lapack_int* ipiv );
lapack_int LAPACKE_zsytri( int matrix_order, char uplo, lapack_int n,
                           lapack_complex_double* a, lapack_int lda,
                           const lapack_int* ipiv );

lapack_int LAPACKE_ssytrs( int matrix_order, char uplo, lapack_int n,
                           lapack_int nrhs, const float* a, lapack_int lda,
                           const lapack_int* ipiv, float* b, lapack_int ldb );
lapack_int LAPACKE_dsytrs( int matrix_order, char uplo, lapack_int n,
                           lapack_int nrhs, const double* a, lapack_int lda,
                           const lapack_int* ipiv, double* b, lapack_int ldb );
lapack_int LAPACKE_csytrs( int matrix_order, char uplo, lapack_int n,
                           lapack_int nrhs, const lapack_complex_float* a,
                           lapack_int lda, const lapack_int* ipiv,
                           lapack_complex_float* b, lapack_int ldb );
lapack_int LAPACKE_zsytrs( int matrix_order, char uplo, lapack_int n,
                           lapack_int nrhs, const lapack_complex_double* a,
                           lapack_int lda, const lapack_int* ipiv,
                           lapack_complex_double* b, lapack_int ldb );

lapack_int LAPACKE_stbcon( int matrix_order, char norm, char uplo, char diag,
                           lapack_int n, lapack_int kd, const float* ab,
                           lapack_int ldab, float* rcond );
lapack_int LAPACKE_dtbcon( int matrix_order, char norm, char uplo, char diag,
                           lapack_int n, lapack_int kd, const double* ab,
                           lapack_int ldab, double* rcond );
lapack_int LAPACKE_ctbcon( int matrix_order, char norm, char uplo, char diag,
                           lapack_int n, lapack_int kd,
                           const lapack_complex_float* ab, lapack_int ldab,
                           float* rcond );
lapack_int LAPACKE_ztbcon( int matrix_order, char norm, char uplo, char diag,
                           lapack_int n, lapack_int kd,
                           const lapack_complex_double* ab, lapack_int ldab,
                           double* rcond );

lapack_int LAPACKE_stbrfs( int matrix_order, char uplo, char trans, char diag,
                           lapack_int n, lapack_int kd, lapack_int nrhs,
                           const float* ab, lapack_int ldab, const float* b,
                           lapack_int ldb, const float* x, lapack_int ldx,
                           float* ferr, float* berr );
lapack_int LAPACKE_dtbrfs( int matrix_order, char uplo, char trans, char diag,
                           lapack_int n, lapack_int kd, lapack_int nrhs,
                           const double* ab, lapack_int ldab, const double* b,
                           lapack_int ldb, const double* x, lapack_int ldx,
                           double* ferr, double* berr );
lapack_int LAPACKE_ctbrfs( int matrix_order, char uplo, char trans, char diag,
                           lapack_int n, lapack_int kd, lapack_int nrhs,
                           const lapack_complex_float* ab, lapack_int ldab,
                           const lapack_complex_float* b, lapack_int ldb,
                           const lapack_complex_float* x, lapack_int ldx,
                           float* ferr, float* berr );
lapack_int LAPACKE_ztbrfs( int matrix_order, char uplo, char trans, char diag,
                           lapack_int n, lapack_int kd, lapack_int nrhs,
                           const lapack_complex_double* ab, lapack_int ldab,
                           const lapack_complex_double* b, lapack_int ldb,
                           const lapack_complex_double* x, lapack_int ldx,
                           double* ferr, double* berr );

lapack_int LAPACKE_stbtrs( int matrix_order, char uplo, char trans, char diag,
                           lapack_int n, lapack_int kd, lapack_int nrhs,
                           const float* ab, lapack_int ldab, float* b,
                           lapack_int ldb );
lapack_int LAPACKE_dtbtrs( int matrix_order, char uplo, char trans, char diag,
                           lapack_int n, lapack_int kd, lapack_int nrhs,
                           const double* ab, lapack_int ldab, double* b,
                           lapack_int ldb );
lapack_int LAPACKE_ctbtrs( int matrix_order, char uplo, char trans, char diag,
                           lapack_int n, lapack_int kd, lapack_int nrhs,
                           const lapack_complex_float* ab, lapack_int ldab,
                           lapack_complex_float* b, lapack_int ldb );
lapack_int LAPACKE_ztbtrs( int matrix_order, char uplo, char trans, char diag,
                           lapack_int n, lapack_int kd, lapack_int nrhs,
                           const lapack_complex_double* ab, lapack_int ldab,
                           lapack_complex_double* b, lapack_int ldb );

lapack_int LAPACKE_stfsm( int matrix_order, char transr, char side, char uplo,
                          char trans, char diag, lapack_int m, lapack_int n,
                          float alpha, const float* a, float* b,
                          lapack_int ldb );
lapack_int LAPACKE_dtfsm( int matrix_order, char transr, char side, char uplo,
                          char trans, char diag, lapack_int m, lapack_int n,
                          double alpha, const double* a, double* b,
                          lapack_int ldb );
lapack_int LAPACKE_ctfsm( int matrix_order, char transr, char side, char uplo,
                          char trans, char diag, lapack_int m, lapack_int n,
                          lapack_complex_float alpha,
                          const lapack_complex_float* a,
                          lapack_complex_float* b, lapack_int ldb );
lapack_int LAPACKE_ztfsm( int matrix_order, char transr, char side, char uplo,
                          char trans, char diag, lapack_int m, lapack_int n,
                          lapack_complex_double alpha,
                          const lapack_complex_double* a,
                          lapack_complex_double* b, lapack_int ldb );

lapack_int LAPACKE_stftri( int matrix_order, char transr, char uplo, char diag,
                           lapack_int n, float* a );
lapack_int LAPACKE_dtftri( int matrix_order, char transr, char uplo, char diag,
                           lapack_int n, double* a );
lapack_int LAPACKE_ctftri( int matrix_order, char transr, char uplo, char diag,
                           lapack_int n, lapack_complex_float* a );
lapack_int LAPACKE_ztftri( int matrix_order, char transr, char uplo, char diag,
                           lapack_int n, lapack_complex_double* a );

lapack_int LAPACKE_stfttp( int matrix_order, char transr, char uplo,
                           lapack_int n, const float* arf, float* ap );
lapack_int LAPACKE_dtfttp( int matrix_order, char transr, char uplo,
                           lapack_int n, const double* arf, double* ap );
lapack_int LAPACKE_ctfttp( int matrix_order, char transr, char uplo,
                           lapack_int n, const lapack_complex_float* arf,
                           lapack_complex_float* ap );
lapack_int LAPACKE_ztfttp( int matrix_order, char transr, char uplo,
                           lapack_int n, const lapack_complex_double* arf,
                           lapack_complex_double* ap );

lapack_int LAPACKE_stfttr( int matrix_order, char transr, char uplo,
                           lapack_int n, const float* arf, float* a,
                           lapack_int lda );
lapack_int LAPACKE_dtfttr( int matrix_order, char transr, char uplo,
                           lapack_int n, const double* arf, double* a,
                           lapack_int lda );
lapack_int LAPACKE_ctfttr( int matrix_order, char transr, char uplo,
                           lapack_int n, const lapack_complex_float* arf,
                           lapack_complex_float* a, lapack_int lda );
lapack_int LAPACKE_ztfttr( int matrix_order, char transr, char uplo,
                           lapack_int n, const lapack_complex_double* arf,
                           lapack_complex_double* a, lapack_int lda );

lapack_int LAPACKE_stgevc( int matrix_order, char side, char howmny,
                           const lapack_logical* select, lapack_int n,
                           const float* s, lapack_int lds, const float* p,
                           lapack_int ldp, float* vl, lapack_int ldvl,
                           float* vr, lapack_int ldvr, lapack_int mm,
                           lapack_int* m );
lapack_int LAPACKE_dtgevc( int matrix_order, char side, char howmny,
                           const lapack_logical* select, lapack_int n,
                           const double* s, lapack_int lds, const double* p,
                           lapack_int ldp, double* vl, lapack_int ldvl,
                           double* vr, lapack_int ldvr, lapack_int mm,
                           lapack_int* m );
lapack_int LAPACKE_ctgevc( int matrix_order, char side, char howmny,
                           const lapack_logical* select, lapack_int n,
                           const lapack_complex_float* s, lapack_int lds,
                           const lapack_complex_float* p, lapack_int ldp,
                           lapack_complex_float* vl, lapack_int ldvl,
                           lapack_complex_float* vr, lapack_int ldvr,
                           lapack_int mm, lapack_int* m );
lapack_int LAPACKE_ztgevc( int matrix_order, char side, char howmny,
                           const lapack_logical* select, lapack_int n,
                           const lapack_complex_double* s, lapack_int lds,
                           const lapack_complex_double* p, lapack_int ldp,
                           lapack_complex_double* vl, lapack_int ldvl,
                           lapack_complex_double* vr, lapack_int ldvr,
                           lapack_int mm, lapack_int* m );

lapack_int LAPACKE_stgexc( int matrix_order, lapack_logical wantq,
                           lapack_logical wantz, lapack_int n, float* a,
                           lapack_int lda, float* b, lapack_int ldb, float* q,
                           lapack_int ldq, float* z, lapack_int ldz,
                           lapack_int* ifst, lapack_int* ilst );
lapack_int LAPACKE_dtgexc( int matrix_order, lapack_logical wantq,
                           lapack_logical wantz, lapack_int n, double* a,
                           lapack_int lda, double* b, lapack_int ldb, double* q,
                           lapack_int ldq, double* z, lapack_int ldz,
                           lapack_int* ifst, lapack_int* ilst );
lapack_int LAPACKE_ctgexc( int matrix_order, lapack_logical wantq,
                           lapack_logical wantz, lapack_int n,
                           lapack_complex_float* a, lapack_int lda,
                           lapack_complex_float* b, lapack_int ldb,
                           lapack_complex_float* q, lapack_int ldq,
                           lapack_complex_float* z, lapack_int ldz,
                           lapack_int ifst, lapack_int ilst );
lapack_int LAPACKE_ztgexc( int matrix_order, lapack_logical wantq,
                           lapack_logical wantz, lapack_int n,
                           lapack_complex_double* a, lapack_int lda,
                           lapack_complex_double* b, lapack_int ldb,
                           lapack_complex_double* q, lapack_int ldq,
                           lapack_complex_double* z, lapack_int ldz,
                           lapack_int ifst, lapack_int ilst );

lapack_int LAPACKE_stgsen( int matrix_order, lapack_int ijob,
                           lapack_logical wantq, lapack_logical wantz,
                           const lapack_logical* select, lapack_int n, float* a,
                           lapack_int lda, float* b, lapack_int ldb,
                           float* alphar, float* alphai, float* beta, float* q,
                           lapack_int ldq, float* z, lapack_int ldz,
                           lapack_int* m, float* pl, float* pr, float* dif );
lapack_int LAPACKE_dtgsen( int matrix_order, lapack_int ijob,
                           lapack_logical wantq, lapack_logical wantz,
                           const lapack_logical* select, lapack_int n,
                           double* a, lapack_int lda, double* b, lapack_int ldb,
                           double* alphar, double* alphai, double* beta,
                           double* q, lapack_int ldq, double* z, lapack_int ldz,
                           lapack_int* m, double* pl, double* pr, double* dif );
lapack_int LAPACKE_ctgsen( int matrix_order, lapack_int ijob,
                           lapack_logical wantq, lapack_logical wantz,
                           const lapack_logical* select, lapack_int n,
                           lapack_complex_float* a, lapack_int lda,
                           lapack_complex_float* b, lapack_int ldb,
                           lapack_complex_float* alpha,
                           lapack_complex_float* beta, lapack_complex_float* q,
                           lapack_int ldq, lapack_complex_float* z,
                           lapack_int ldz, lapack_int* m, float* pl, float* pr,
                           float* dif );
lapack_int LAPACKE_ztgsen( int matrix_order, lapack_int ijob,
                           lapack_logical wantq, lapack_logical wantz,
                           const lapack_logical* select, lapack_int n,
                           lapack_complex_double* a, lapack_int lda,
                           lapack_complex_double* b, lapack_int ldb,
                           lapack_complex_double* alpha,
                           lapack_complex_double* beta,
                           lapack_complex_double* q, lapack_int ldq,
                           lapack_complex_double* z, lapack_int ldz,
                           lapack_int* m, double* pl, double* pr, double* dif );

lapack_int LAPACKE_stgsja( int matrix_order, char jobu, char jobv, char jobq,
                           lapack_int m, lapack_int p, lapack_int n,
                           lapack_int k, lapack_int l, float* a, lapack_int lda,
                           float* b, lapack_int ldb, float tola, float tolb,
                           float* alpha, float* beta, float* u, lapack_int ldu,
                           float* v, lapack_int ldv, float* q, lapack_int ldq,
                           lapack_int* ncycle );
lapack_int LAPACKE_dtgsja( int matrix_order, char jobu, char jobv, char jobq,
                           lapack_int m, lapack_int p, lapack_int n,
                           lapack_int k, lapack_int l, double* a,
                           lapack_int lda, double* b, lapack_int ldb,
                           double tola, double tolb, double* alpha,
                           double* beta, double* u, lapack_int ldu, double* v,
                           lapack_int ldv, double* q, lapack_int ldq,
                           lapack_int* ncycle );
lapack_int LAPACKE_ctgsja( int matrix_order, char jobu, char jobv, char jobq,
                           lapack_int m, lapack_int p, lapack_int n,
                           lapack_int k, lapack_int l, lapack_complex_float* a,
                           lapack_int lda, lapack_complex_float* b,
                           lapack_int ldb, float tola, float tolb, float* alpha,
                           float* beta, lapack_complex_float* u, lapack_int ldu,
                           lapack_complex_float* v, lapack_int ldv,
                           lapack_complex_float* q, lapack_int ldq,
                           lapack_int* ncycle );
lapack_int LAPACKE_ztgsja( int matrix_order, char jobu, char jobv, char jobq,
                           lapack_int m, lapack_int p, lapack_int n,
                           lapack_int k, lapack_int l, lapack_complex_double* a,
                           lapack_int lda, lapack_complex_double* b,
                           lapack_int ldb, double tola, double tolb,
                           double* alpha, double* beta,
                           lapack_complex_double* u, lapack_int ldu,
                           lapack_complex_double* v, lapack_int ldv,
                           lapack_complex_double* q, lapack_int ldq,
                           lapack_int* ncycle );

lapack_int LAPACKE_stgsna( int matrix_order, char job, char howmny,
                           const lapack_logical* select, lapack_int n,
                           const float* a, lapack_int lda, const float* b,
                           lapack_int ldb, const float* vl, lapack_int ldvl,
                           const float* vr, lapack_int ldvr, float* s,
                           float* dif, lapack_int mm, lapack_int* m );
lapack_int LAPACKE_dtgsna( int matrix_order, char job, char howmny,
                           const lapack_logical* select, lapack_int n,
                           const double* a, lapack_int lda, const double* b,
                           lapack_int ldb, const double* vl, lapack_int ldvl,
                           const double* vr, lapack_int ldvr, double* s,
                           double* dif, lapack_int mm, lapack_int* m );
lapack_int LAPACKE_ctgsna( int matrix_order, char job, char howmny,
                           const lapack_logical* select, lapack_int n,
                           const lapack_complex_float* a, lapack_int lda,
                           const lapack_complex_float* b, lapack_int ldb,
                           const lapack_complex_float* vl, lapack_int ldvl,
                           const lapack_complex_float* vr, lapack_int ldvr,
                           float* s, float* dif, lapack_int mm, lapack_int* m );
lapack_int LAPACKE_ztgsna( int matrix_order, char job, char howmny,
                           const lapack_logical* select, lapack_int n,
                           const lapack_complex_double* a, lapack_int lda,
                           const lapack_complex_double* b, lapack_int ldb,
                           const lapack_complex_double* vl, lapack_int ldvl,
                           const lapack_complex_double* vr, lapack_int ldvr,
                           double* s, double* dif, lapack_int mm,
                           lapack_int* m );

lapack_int LAPACKE_stgsyl( int matrix_order, char trans, lapack_int ijob,
                           lapack_int m, lapack_int n, const float* a,
                           lapack_int lda, const float* b, lapack_int ldb,
                           float* c, lapack_int ldc, const float* d,
                           lapack_int ldd, const float* e, lapack_int lde,
                           float* f, lapack_int ldf, float* scale, float* dif );
lapack_int LAPACKE_dtgsyl( int matrix_order, char trans, lapack_int ijob,
                           lapack_int m, lapack_int n, const double* a,
                           lapack_int lda, const double* b, lapack_int ldb,
                           double* c, lapack_int ldc, const double* d,
                           lapack_int ldd, const double* e, lapack_int lde,
                           double* f, lapack_int ldf, double* scale,
                           double* dif );
lapack_int LAPACKE_ctgsyl( int matrix_order, char trans, lapack_int ijob,
                           lapack_int m, lapack_int n,
                           const lapack_complex_float* a, lapack_int lda,
                           const lapack_complex_float* b, lapack_int ldb,
                           lapack_complex_float* c, lapack_int ldc,
                           const lapack_complex_float* d, lapack_int ldd,
                           const lapack_complex_float* e, lapack_int lde,
                           lapack_complex_float* f, lapack_int ldf,
                           float* scale, float* dif );
lapack_int LAPACKE_ztgsyl( int matrix_order, char trans, lapack_int ijob,
                           lapack_int m, lapack_int n,
                           const lapack_complex_double* a, lapack_int lda,
                           const lapack_complex_double* b, lapack_int ldb,
                           lapack_complex_double* c, lapack_int ldc,
                           const lapack_complex_double* d, lapack_int ldd,
                           const lapack_complex_double* e, lapack_int lde,
                           lapack_complex_double* f, lapack_int ldf,
                           double* scale, double* dif );

lapack_int LAPACKE_stpcon( int matrix_order, char norm, char uplo, char diag,
                           lapack_int n, const float* ap, float* rcond );
lapack_int LAPACKE_dtpcon( int matrix_order, char norm, char uplo, char diag,
                           lapack_int n, const double* ap, double* rcond );
lapack_int LAPACKE_ctpcon( int matrix_order, char norm, char uplo, char diag,
                           lapack_int n, const lapack_complex_float* ap,
                           float* rcond );
lapack_int LAPACKE_ztpcon( int matrix_order, char norm, char uplo, char diag,
                           lapack_int n, const lapack_complex_double* ap,
                           double* rcond );

lapack_int LAPACKE_stprfs( int matrix_order, char uplo, char trans, char diag,
                           lapack_int n, lapack_int nrhs, const float* ap,
                           const float* b, lapack_int ldb, const float* x,
                           lapack_int ldx, float* ferr, float* berr );
lapack_int LAPACKE_dtprfs( int matrix_order, char uplo, char trans, char diag,
                           lapack_int n, lapack_int nrhs, const double* ap,
                           const double* b, lapack_int ldb, const double* x,
                           lapack_int ldx, double* ferr, double* berr );
lapack_int LAPACKE_ctprfs( int matrix_order, char uplo, char trans, char diag,
                           lapack_int n, lapack_int nrhs,
                           const lapack_complex_float* ap,
                           const lapack_complex_float* b, lapack_int ldb,
                           const lapack_complex_float* x, lapack_int ldx,
                           float* ferr, float* berr );
lapack_int LAPACKE_ztprfs( int matrix_order, char uplo, char trans, char diag,
                           lapack_int n, lapack_int nrhs,
                           const lapack_complex_double* ap,
                           const lapack_complex_double* b, lapack_int ldb,
                           const lapack_complex_double* x, lapack_int ldx,
                           double* ferr, double* berr );

lapack_int LAPACKE_stptri( int matrix_order, char uplo, char diag, lapack_int n,
                           float* ap );
lapack_int LAPACKE_dtptri( int matrix_order, char uplo, char diag, lapack_int n,
                           double* ap );
lapack_int LAPACKE_ctptri( int matrix_order, char uplo, char diag, lapack_int n,
                           lapack_complex_float* ap );
lapack_int LAPACKE_ztptri( int matrix_order, char uplo, char diag, lapack_int n,
                           lapack_complex_double* ap );

lapack_int LAPACKE_stptrs( int matrix_order, char uplo, char trans, char diag,
                           lapack_int n, lapack_int nrhs, const float* ap,
                           float* b, lapack_int ldb );
lapack_int LAPACKE_dtptrs( int matrix_order, char uplo, char trans, char diag,
                           lapack_int n, lapack_int nrhs, const double* ap,
                           double* b, lapack_int ldb );
lapack_int LAPACKE_ctptrs( int matrix_order, char uplo, char trans, char diag,
                           lapack_int n, lapack_int nrhs,
                           const lapack_complex_float* ap,
                           lapack_complex_float* b, lapack_int ldb );
lapack_int LAPACKE_ztptrs( int matrix_order, char uplo, char trans, char diag,
                           lapack_int n, lapack_int nrhs,
                           const lapack_complex_double* ap,
                           lapack_complex_double* b, lapack_int ldb );

lapack_int LAPACKE_stpttf( int matrix_order, char transr, char uplo,
                           lapack_int n, const float* ap, float* arf );
lapack_int LAPACKE_dtpttf( int matrix_order, char transr, char uplo,
                           lapack_int n, const double* ap, double* arf );
lapack_int LAPACKE_ctpttf( int matrix_order, char transr, char uplo,
                           lapack_int n, const lapack_complex_float* ap,
                           lapack_complex_float* arf );
lapack_int LAPACKE_ztpttf( int matrix_order, char transr, char uplo,
                           lapack_int n, const lapack_complex_double* ap,
                           lapack_complex_double* arf );

lapack_int LAPACKE_stpttr( int matrix_order, char uplo, lapack_int n,
                           const float* ap, float* a, lapack_int lda );
lapack_int LAPACKE_dtpttr( int matrix_order, char uplo, lapack_int n,
                           const double* ap, double* a, lapack_int lda );
lapack_int LAPACKE_ctpttr( int matrix_order, char uplo, lapack_int n,
                           const lapack_complex_float* ap,
                           lapack_complex_float* a, lapack_int lda );
lapack_int LAPACKE_ztpttr( int matrix_order, char uplo, lapack_int n,
                           const lapack_complex_double* ap,
                           lapack_complex_double* a, lapack_int lda );

lapack_int LAPACKE_strcon( int matrix_order, char norm, char uplo, char diag,
                           lapack_int n, const float* a, lapack_int lda,
                           float* rcond );
lapack_int LAPACKE_dtrcon( int matrix_order, char norm, char uplo, char diag,
                           lapack_int n, const double* a, lapack_int lda,
                           double* rcond );
lapack_int LAPACKE_ctrcon( int matrix_order, char norm, char uplo, char diag,
                           lapack_int n, const lapack_complex_float* a,
                           lapack_int lda, float* rcond );
lapack_int LAPACKE_ztrcon( int matrix_order, char norm, char uplo, char diag,
                           lapack_int n, const lapack_complex_double* a,
                           lapack_int lda, double* rcond );

lapack_int LAPACKE_strevc( int matrix_order, char side, char howmny,
                           lapack_logical* select, lapack_int n, const float* t,
                           lapack_int ldt, float* vl, lapack_int ldvl,
                           float* vr, lapack_int ldvr, lapack_int mm,
                           lapack_int* m );
lapack_int LAPACKE_dtrevc( int matrix_order, char side, char howmny,
                           lapack_logical* select, lapack_int n,
                           const double* t, lapack_int ldt, double* vl,
                           lapack_int ldvl, double* vr, lapack_int ldvr,
                           lapack_int mm, lapack_int* m );
lapack_int LAPACKE_ctrevc( int matrix_order, char side, char howmny,
                           const lapack_logical* select, lapack_int n,
                           lapack_complex_float* t, lapack_int ldt,
                           lapack_complex_float* vl, lapack_int ldvl,
                           lapack_complex_float* vr, lapack_int ldvr,
                           lapack_int mm, lapack_int* m );
lapack_int LAPACKE_ztrevc( int matrix_order, char side, char howmny,
                           const lapack_logical* select, lapack_int n,
                           lapack_complex_double* t, lapack_int ldt,
                           lapack_complex_double* vl, lapack_int ldvl,
                           lapack_complex_double* vr, lapack_int ldvr,
                           lapack_int mm, lapack_int* m );

lapack_int LAPACKE_strexc( int matrix_order, char compq, lapack_int n, float* t,
                           lapack_int ldt, float* q, lapack_int ldq,
                           lapack_int* ifst, lapack_int* ilst );
lapack_int LAPACKE_dtrexc( int matrix_order, char compq, lapack_int n,
                           double* t, lapack_int ldt, double* q, lapack_int ldq,
                           lapack_int* ifst, lapack_int* ilst );
lapack_int LAPACKE_ctrexc( int matrix_order, char compq, lapack_int n,
                           lapack_complex_float* t, lapack_int ldt,
                           lapack_complex_float* q, lapack_int ldq,
                           lapack_int ifst, lapack_int ilst );
lapack_int LAPACKE_ztrexc( int matrix_order, char compq, lapack_int n,
                           lapack_complex_double* t, lapack_int ldt,
                           lapack_complex_double* q, lapack_int ldq,
                           lapack_int ifst, lapack_int ilst );

lapack_int LAPACKE_strrfs( int matrix_order, char uplo, char trans, char diag,
                           lapack_int n, lapack_int nrhs, const float* a,
                           lapack_int lda, const float* b, lapack_int ldb,
                           const float* x, lapack_int ldx, float* ferr,
                           float* berr );
lapack_int LAPACKE_dtrrfs( int matrix_order, char uplo, char trans, char diag,
                           lapack_int n, lapack_int nrhs, const double* a,
                           lapack_int lda, const double* b, lapack_int ldb,
                           const double* x, lapack_int ldx, double* ferr,
                           double* berr );
lapack_int LAPACKE_ctrrfs( int matrix_order, char uplo, char trans, char diag,
                           lapack_int n, lapack_int nrhs,
                           const lapack_complex_float* a, lapack_int lda,
                           const lapack_complex_float* b, lapack_int ldb,
                           const lapack_complex_float* x, lapack_int ldx,
                           float* ferr, float* berr );
lapack_int LAPACKE_ztrrfs( int matrix_order, char uplo, char trans, char diag,
                           lapack_int n, lapack_int nrhs,
                           const lapack_complex_double* a, lapack_int lda,
                           const lapack_complex_double* b, lapack_int ldb,
                           const lapack_complex_double* x, lapack_int ldx,
                           double* ferr, double* berr );

lapack_int LAPACKE_strsen( int matrix_order, char job, char compq,
                           const lapack_logical* select, lapack_int n, float* t,
                           lapack_int ldt, float* q, lapack_int ldq, float* wr,
                           float* wi, lapack_int* m, float* s, float* sep );
lapack_int LAPACKE_dtrsen( int matrix_order, char job, char compq,
                           const lapack_logical* select, lapack_int n,
                           double* t, lapack_int ldt, double* q, lapack_int ldq,
                           double* wr, double* wi, lapack_int* m, double* s,
                           double* sep );
lapack_int LAPACKE_ctrsen( int matrix_order, char job, char compq,
                           const lapack_logical* select, lapack_int n,
                           lapack_complex_float* t, lapack_int ldt,
                           lapack_complex_float* q, lapack_int ldq,
                           lapack_complex_float* w, lapack_int* m, float* s,
                           float* sep );
lapack_int LAPACKE_ztrsen( int matrix_order, char job, char compq,
                           const lapack_logical* select, lapack_int n,
                           lapack_complex_double* t, lapack_int ldt,
                           lapack_complex_double* q, lapack_int ldq,
                           lapack_complex_double* w, lapack_int* m, double* s,
                           double* sep );

lapack_int LAPACKE_strsna( int matrix_order, char job, char howmny,
                           const lapack_logical* select, lapack_int n,
                           const float* t, lapack_int ldt, const float* vl,
                           lapack_int ldvl, const float* vr, lapack_int ldvr,
                           float* s, float* sep, lapack_int mm, lapack_int* m );
lapack_int LAPACKE_dtrsna( int matrix_order, char job, char howmny,
                           const lapack_logical* select, lapack_int n,
                           const double* t, lapack_int ldt, const double* vl,
                           lapack_int ldvl, const double* vr, lapack_int ldvr,
                           double* s, double* sep, lapack_int mm,
                           lapack_int* m );
lapack_int LAPACKE_ctrsna( int matrix_order, char job, char howmny,
                           const lapack_logical* select, lapack_int n,
                           const lapack_complex_float* t, lapack_int ldt,
                           const lapack_complex_float* vl, lapack_int ldvl,
                           const lapack_complex_float* vr, lapack_int ldvr,
                           float* s, float* sep, lapack_int mm, lapack_int* m );
lapack_int LAPACKE_ztrsna( int matrix_order, char job, char howmny,
                           const lapack_logical* select, lapack_int n,
                           const lapack_complex_double* t, lapack_int ldt,
                           const lapack_complex_double* vl, lapack_int ldvl,
                           const lapack_complex_double* vr, lapack_int ldvr,
                           double* s, double* sep, lapack_int mm,
                           lapack_int* m );

lapack_int LAPACKE_strsyl( int matrix_order, char trana, char tranb,
                           lapack_int isgn, lapack_int m, lapack_int n,
                           const float* a, lapack_int lda, const float* b,
                           lapack_int ldb, float* c, lapack_int ldc,
                           float* scale );
lapack_int LAPACKE_dtrsyl( int matrix_order, char trana, char tranb,
                           lapack_int isgn, lapack_int m, lapack_int n,
                           const double* a, lapack_int lda, const double* b,
                           lapack_int ldb, double* c, lapack_int ldc,
                           double* scale );
lapack_int LAPACKE_ctrsyl( int matrix_order, char trana, char tranb,
                           lapack_int isgn, lapack_int m, lapack_int n,
                           const lapack_complex_float* a, lapack_int lda,
                           const lapack_complex_float* b, lapack_int ldb,
                           lapack_complex_float* c, lapack_int ldc,
                           float* scale );
lapack_int LAPACKE_ztrsyl( int matrix_order, char trana, char tranb,
                           lapack_int isgn, lapack_int m, lapack_int n,
                           const lapack_complex_double* a, lapack_int lda,
                           const lapack_complex_double* b, lapack_int ldb,
                           lapack_complex_double* c, lapack_int ldc,
                           double* scale );

lapack_int LAPACKE_strtri( int matrix_order, char uplo, char diag, lapack_int n,
                           float* a, lapack_int lda );
lapack_int LAPACKE_dtrtri( int matrix_order, char uplo, char diag, lapack_int n,
                           double* a, lapack_int lda );
lapack_int LAPACKE_ctrtri( int matrix_order, char uplo, char diag, lapack_int n,
                           lapack_complex_float* a, lapack_int lda );
lapack_int LAPACKE_ztrtri( int matrix_order, char uplo, char diag, lapack_int n,
                           lapack_complex_double* a, lapack_int lda );

lapack_int LAPACKE_strtrs( int matrix_order, char uplo, char trans, char diag,
                           lapack_int n, lapack_int nrhs, const float* a,
                           lapack_int lda, float* b, lapack_int ldb );
lapack_int LAPACKE_dtrtrs( int matrix_order, char uplo, char trans, char diag,
                           lapack_int n, lapack_int nrhs, const double* a,
                           lapack_int lda, double* b, lapack_int ldb );
lapack_int LAPACKE_ctrtrs( int matrix_order, char uplo, char trans, char diag,
                           lapack_int n, lapack_int nrhs,
                           const lapack_complex_float* a, lapack_int lda,
                           lapack_complex_float* b, lapack_int ldb );
lapack_int LAPACKE_ztrtrs( int matrix_order, char uplo, char trans, char diag,
                           lapack_int n, lapack_int nrhs,
                           const lapack_complex_double* a, lapack_int lda,
                           lapack_complex_double* b, lapack_int ldb );

lapack_int LAPACKE_strttf( int matrix_order, char transr, char uplo,
                           lapack_int n, const float* a, lapack_int lda,
                           float* arf );
lapack_int LAPACKE_dtrttf( int matrix_order, char transr, char uplo,
                           lapack_int n, const double* a, lapack_int lda,
                           double* arf );
lapack_int LAPACKE_ctrttf( int matrix_order, char transr, char uplo,
                           lapack_int n, const lapack_complex_float* a,
                           lapack_int lda, lapack_complex_float* arf );
lapack_int LAPACKE_ztrttf( int matrix_order, char transr, char uplo,
                           lapack_int n, const lapack_complex_double* a,
                           lapack_int lda, lapack_complex_double* arf );

lapack_int LAPACKE_strttp( int matrix_order, char uplo, lapack_int n,
                           const float* a, lapack_int lda, float* ap );
lapack_int LAPACKE_dtrttp( int matrix_order, char uplo, lapack_int n,
                           const double* a, lapack_int lda, double* ap );
lapack_int LAPACKE_ctrttp( int matrix_order, char uplo, lapack_int n,
                           const lapack_complex_float* a, lapack_int lda,
                           lapack_complex_float* ap );
lapack_int LAPACKE_ztrttp( int matrix_order, char uplo, lapack_int n,
                           const lapack_complex_double* a, lapack_int lda,
                           lapack_complex_double* ap );

lapack_int LAPACKE_stzrzf( int matrix_order, lapack_int m, lapack_int n,
                           float* a, lapack_int lda, float* tau );
lapack_int LAPACKE_dtzrzf( int matrix_order, lapack_int m, lapack_int n,
                           double* a, lapack_int lda, double* tau );
lapack_int LAPACKE_ctzrzf( int matrix_order, lapack_int m, lapack_int n,
                           lapack_complex_float* a, lapack_int lda,
                           lapack_complex_float* tau );
lapack_int LAPACKE_ztzrzf( int matrix_order, lapack_int m, lapack_int n,
                           lapack_complex_double* a, lapack_int lda,
                           lapack_complex_double* tau );

lapack_int LAPACKE_cungbr( int matrix_order, char vect, lapack_int m,
                           lapack_int n, lapack_int k, lapack_complex_float* a,
                           lapack_int lda, const lapack_complex_float* tau );
lapack_int LAPACKE_zungbr( int matrix_order, char vect, lapack_int m,
                           lapack_int n, lapack_int k, lapack_complex_double* a,
                           lapack_int lda, const lapack_complex_double* tau );

lapack_int LAPACKE_cunghr( int matrix_order, lapack_int n, lapack_int ilo,
                           lapack_int ihi, lapack_complex_float* a,
                           lapack_int lda, const lapack_complex_float* tau );
lapack_int LAPACKE_zunghr( int matrix_order, lapack_int n, lapack_int ilo,
                           lapack_int ihi, lapack_complex_double* a,
                           lapack_int lda, const lapack_complex_double* tau );

lapack_int LAPACKE_cunglq( int matrix_order, lapack_int m, lapack_int n,
                           lapack_int k, lapack_complex_float* a,
                           lapack_int lda, const lapack_complex_float* tau );
lapack_int LAPACKE_zunglq( int matrix_order, lapack_int m, lapack_int n,
                           lapack_int k, lapack_complex_double* a,
                           lapack_int lda, const lapack_complex_double* tau );

lapack_int LAPACKE_cungql( int matrix_order, lapack_int m, lapack_int n,
                           lapack_int k, lapack_complex_float* a,
                           lapack_int lda, const lapack_complex_float* tau );
lapack_int LAPACKE_zungql( int matrix_order, lapack_int m, lapack_int n,
                           lapack_int k, lapack_complex_double* a,
                           lapack_int lda, const lapack_complex_double* tau );

lapack_int LAPACKE_cungqr( int matrix_order, lapack_int m, lapack_int n,
                           lapack_int k, lapack_complex_float* a,
                           lapack_int lda, const lapack_complex_float* tau );
lapack_int LAPACKE_zungqr( int matrix_order, lapack_int m, lapack_int n,
                           lapack_int k, lapack_complex_double* a,
                           lapack_int lda, const lapack_complex_double* tau );

lapack_int LAPACKE_cungrq( int matrix_order, lapack_int m, lapack_int n,
                           lapack_int k, lapack_complex_float* a,
                           lapack_int lda, const lapack_complex_float* tau );
lapack_int LAPACKE_zungrq( int matrix_order, lapack_int m, lapack_int n,
                           lapack_int k, lapack_complex_double* a,
                           lapack_int lda, const lapack_complex_double* tau );

lapack_int LAPACKE_cungtr( int matrix_order, char uplo, lapack_int n,
                           lapack_complex_float* a, lapack_int lda,
                           const lapack_complex_float* tau );
lapack_int LAPACKE_zungtr( int matrix_order, char uplo, lapack_int n,
                           lapack_complex_double* a, lapack_int lda,
                           const lapack_complex_double* tau );

lapack_int LAPACKE_cunmbr( int matrix_order, char vect, char side, char trans,
                           lapack_int m, lapack_int n, lapack_int k,
                           const lapack_complex_float* a, lapack_int lda,
                           const lapack_complex_float* tau,
                           lapack_complex_float* c, lapack_int ldc );
lapack_int LAPACKE_zunmbr( int matrix_order, char vect, char side, char trans,
                           lapack_int m, lapack_int n, lapack_int k,
                           const lapack_complex_double* a, lapack_int lda,
                           const lapack_complex_double* tau,
                           lapack_complex_double* c, lapack_int ldc );

lapack_int LAPACKE_cunmhr( int matrix_order, char side, char trans,
                           lapack_int m, lapack_int n, lapack_int ilo,
                           lapack_int ihi, const lapack_complex_float* a,
                           lapack_int lda, const lapack_complex_float* tau,
                           lapack_complex_float* c, lapack_int ldc );
lapack_int LAPACKE_zunmhr( int matrix_order, char side, char trans,
                           lapack_int m, lapack_int n, lapack_int ilo,
                           lapack_int ihi, const lapack_complex_double* a,
                           lapack_int lda, const lapack_complex_double* tau,
                           lapack_complex_double* c, lapack_int ldc );

lapack_int LAPACKE_cunmlq( int matrix_order, char side, char trans,
                           lapack_int m, lapack_int n, lapack_int k,
                           const lapack_complex_float* a, lapack_int lda,
                           const lapack_complex_float* tau,
                           lapack_complex_float* c, lapack_int ldc );
lapack_int LAPACKE_zunmlq( int matrix_order, char side, char trans,
                           lapack_int m, lapack_int n, lapack_int k,
                           const lapack_complex_double* a, lapack_int lda,
                           const lapack_complex_double* tau,
                           lapack_complex_double* c, lapack_int ldc );

lapack_int LAPACKE_cunmql( int matrix_order, char side, char trans,
                           lapack_int m, lapack_int n, lapack_int k,
                           const lapack_complex_float* a, lapack_int lda,
                           const lapack_complex_float* tau,
                           lapack_complex_float* c, lapack_int ldc );
lapack_int LAPACKE_zunmql( int matrix_order, char side, char trans,
                           lapack_int m, lapack_int n, lapack_int k,
                           const lapack_complex_double* a, lapack_int lda,
                           const lapack_complex_double* tau,
                           lapack_complex_double* c, lapack_int ldc );

lapack_int LAPACKE_cunmqr( int matrix_order, char side, char trans,
                           lapack_int m, lapack_int n, lapack_int k,
                           const lapack_complex_float* a, lapack_int lda,
                           const lapack_complex_float* tau,
                           lapack_complex_float* c, lapack_int ldc );
lapack_int LAPACKE_zunmqr( int matrix_order, char side, char trans,
                           lapack_int m, lapack_int n, lapack_int k,
                           const lapack_complex_double* a, lapack_int lda,
                           const lapack_complex_double* tau,
                           lapack_complex_double* c, lapack_int ldc );

lapack_int LAPACKE_cunmrq( int matrix_order, char side, char trans,
                           lapack_int m, lapack_int n, lapack_int k,
                           const lapack_complex_float* a, lapack_int lda,
                           const lapack_complex_float* tau,
                           lapack_complex_float* c, lapack_int ldc );
lapack_int LAPACKE_zunmrq( int matrix_order, char side, char trans,
                           lapack_int m, lapack_int n, lapack_int k,
                           const lapack_complex_double* a, lapack_int lda,
                           const lapack_complex_double* tau,
                           lapack_complex_double* c, lapack_int ldc );

lapack_int LAPACKE_cunmrz( int matrix_order, char side, char trans,
                           lapack_int m, lapack_int n, lapack_int k,
                           lapack_int l, const lapack_complex_float* a,
                           lapack_int lda, const lapack_complex_float* tau,
                           lapack_complex_float* c, lapack_int ldc );
lapack_int LAPACKE_zunmrz( int matrix_order, char side, char trans,
                           lapack_int m, lapack_int n, lapack_int k,
                           lapack_int l, const lapack_complex_double* a,
                           lapack_int lda, const lapack_complex_double* tau,
                           lapack_complex_double* c, lapack_int ldc );

lapack_int LAPACKE_cunmtr( int matrix_order, char side, char uplo, char trans,
                           lapack_int m, lapack_int n,
                           const lapack_complex_float* a, lapack_int lda,
                           const lapack_complex_float* tau,
                           lapack_complex_float* c, lapack_int ldc );
lapack_int LAPACKE_zunmtr( int matrix_order, char side, char uplo, char trans,
                           lapack_int m, lapack_int n,
                           const lapack_complex_double* a, lapack_int lda,
                           const lapack_complex_double* tau,
                           lapack_complex_double* c, lapack_int ldc );

lapack_int LAPACKE_cupgtr( int matrix_order, char uplo, lapack_int n,
                           const lapack_complex_float* ap,
                           const lapack_complex_float* tau,
                           lapack_complex_float* q, lapack_int ldq );
lapack_int LAPACKE_zupgtr( int matrix_order, char uplo, lapack_int n,
                           const lapack_complex_double* ap,
                           const lapack_complex_double* tau,
                           lapack_complex_double* q, lapack_int ldq );

lapack_int LAPACKE_cupmtr( int matrix_order, char side, char uplo, char trans,
                           lapack_int m, lapack_int n,
                           const lapack_complex_float* ap,
                           const lapack_complex_float* tau,
                           lapack_complex_float* c, lapack_int ldc );
lapack_int LAPACKE_zupmtr( int matrix_order, char side, char uplo, char trans,
                           lapack_int m, lapack_int n,
                           const lapack_complex_double* ap,
                           const lapack_complex_double* tau,
                           lapack_complex_double* c, lapack_int ldc );

lapack_int LAPACKE_sbdsdc_work( int matrix_order, char uplo, char compq,
                                lapack_int n, float* d, float* e, float* u,
                                lapack_int ldu, float* vt, lapack_int ldvt,
                                float* q, lapack_int* iq, float* work,
                                lapack_int* iwork );
lapack_int LAPACKE_dbdsdc_work( int matrix_order, char uplo, char compq,
                                lapack_int n, double* d, double* e, double* u,
                                lapack_int ldu, double* vt, lapack_int ldvt,
                                double* q, lapack_int* iq, double* work,
                                lapack_int* iwork );

lapack_int LAPACKE_sbdsqr_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int ncvt, lapack_int nru, lapack_int ncc,
                                float* d, float* e, float* vt, lapack_int ldvt,
                                float* u, lapack_int ldu, float* c,
                                lapack_int ldc, float* work );
lapack_int LAPACKE_dbdsqr_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int ncvt, lapack_int nru, lapack_int ncc,
                                double* d, double* e, double* vt,
                                lapack_int ldvt, double* u, lapack_int ldu,
                                double* c, lapack_int ldc, double* work );
lapack_int LAPACKE_cbdsqr_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int ncvt, lapack_int nru, lapack_int ncc,
                                float* d, float* e, lapack_complex_float* vt,
                                lapack_int ldvt, lapack_complex_float* u,
                                lapack_int ldu, lapack_complex_float* c,
                                lapack_int ldc, float* work );
lapack_int LAPACKE_zbdsqr_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int ncvt, lapack_int nru, lapack_int ncc,
                                double* d, double* e, lapack_complex_double* vt,
                                lapack_int ldvt, lapack_complex_double* u,
                                lapack_int ldu, lapack_complex_double* c,
                                lapack_int ldc, double* work );

lapack_int LAPACKE_sdisna_work( char job, lapack_int m, lapack_int n,
                                const float* d, float* sep );
lapack_int LAPACKE_ddisna_work( char job, lapack_int m, lapack_int n,
                                const double* d, double* sep );

lapack_int LAPACKE_sgbbrd_work( int matrix_order, char vect, lapack_int m,
                                lapack_int n, lapack_int ncc, lapack_int kl,
                                lapack_int ku, float* ab, lapack_int ldab,
                                float* d, float* e, float* q, lapack_int ldq,
                                float* pt, lapack_int ldpt, float* c,
                                lapack_int ldc, float* work );
lapack_int LAPACKE_dgbbrd_work( int matrix_order, char vect, lapack_int m,
                                lapack_int n, lapack_int ncc, lapack_int kl,
                                lapack_int ku, double* ab, lapack_int ldab,
                                double* d, double* e, double* q, lapack_int ldq,
                                double* pt, lapack_int ldpt, double* c,
                                lapack_int ldc, double* work );
lapack_int LAPACKE_cgbbrd_work( int matrix_order, char vect, lapack_int m,
                                lapack_int n, lapack_int ncc, lapack_int kl,
                                lapack_int ku, lapack_complex_float* ab,
                                lapack_int ldab, float* d, float* e,
                                lapack_complex_float* q, lapack_int ldq,
                                lapack_complex_float* pt, lapack_int ldpt,
                                lapack_complex_float* c, lapack_int ldc,
                                lapack_complex_float* work, float* rwork );
lapack_int LAPACKE_zgbbrd_work( int matrix_order, char vect, lapack_int m,
                                lapack_int n, lapack_int ncc, lapack_int kl,
                                lapack_int ku, lapack_complex_double* ab,
                                lapack_int ldab, double* d, double* e,
                                lapack_complex_double* q, lapack_int ldq,
                                lapack_complex_double* pt, lapack_int ldpt,
                                lapack_complex_double* c, lapack_int ldc,
                                lapack_complex_double* work, double* rwork );

lapack_int LAPACKE_sgbcon_work( int matrix_order, char norm, lapack_int n,
                                lapack_int kl, lapack_int ku, const float* ab,
                                lapack_int ldab, const lapack_int* ipiv,
                                float anorm, float* rcond, float* work,
                                lapack_int* iwork );
lapack_int LAPACKE_dgbcon_work( int matrix_order, char norm, lapack_int n,
                                lapack_int kl, lapack_int ku, const double* ab,
                                lapack_int ldab, const lapack_int* ipiv,
                                double anorm, double* rcond, double* work,
                                lapack_int* iwork );
lapack_int LAPACKE_cgbcon_work( int matrix_order, char norm, lapack_int n,
                                lapack_int kl, lapack_int ku,
                                const lapack_complex_float* ab, lapack_int ldab,
                                const lapack_int* ipiv, float anorm,
                                float* rcond, lapack_complex_float* work,
                                float* rwork );
lapack_int LAPACKE_zgbcon_work( int matrix_order, char norm, lapack_int n,
                                lapack_int kl, lapack_int ku,
                                const lapack_complex_double* ab,
                                lapack_int ldab, const lapack_int* ipiv,
                                double anorm, double* rcond,
                                lapack_complex_double* work, double* rwork );

lapack_int LAPACKE_sgbequ_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_int kl, lapack_int ku, const float* ab,
                                lapack_int ldab, float* r, float* c,
                                float* rowcnd, float* colcnd, float* amax );
lapack_int LAPACKE_dgbequ_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_int kl, lapack_int ku, const double* ab,
                                lapack_int ldab, double* r, double* c,
                                double* rowcnd, double* colcnd, double* amax );
lapack_int LAPACKE_cgbequ_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_int kl, lapack_int ku,
                                const lapack_complex_float* ab, lapack_int ldab,
                                float* r, float* c, float* rowcnd,
                                float* colcnd, float* amax );
lapack_int LAPACKE_zgbequ_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_int kl, lapack_int ku,
                                const lapack_complex_double* ab,
                                lapack_int ldab, double* r, double* c,
                                double* rowcnd, double* colcnd, double* amax );

lapack_int LAPACKE_sgbequb_work( int matrix_order, lapack_int m, lapack_int n,
                                 lapack_int kl, lapack_int ku, const float* ab,
                                 lapack_int ldab, float* r, float* c,
                                 float* rowcnd, float* colcnd, float* amax );
lapack_int LAPACKE_dgbequb_work( int matrix_order, lapack_int m, lapack_int n,
                                 lapack_int kl, lapack_int ku, const double* ab,
                                 lapack_int ldab, double* r, double* c,
                                 double* rowcnd, double* colcnd, double* amax );
lapack_int LAPACKE_cgbequb_work( int matrix_order, lapack_int m, lapack_int n,
                                 lapack_int kl, lapack_int ku,
                                 const lapack_complex_float* ab,
                                 lapack_int ldab, float* r, float* c,
                                 float* rowcnd, float* colcnd, float* amax );
lapack_int LAPACKE_zgbequb_work( int matrix_order, lapack_int m, lapack_int n,
                                 lapack_int kl, lapack_int ku,
                                 const lapack_complex_double* ab,
                                 lapack_int ldab, double* r, double* c,
                                 double* rowcnd, double* colcnd, double* amax );

lapack_int LAPACKE_sgbrfs_work( int matrix_order, char trans, lapack_int n,
                                lapack_int kl, lapack_int ku, lapack_int nrhs,
                                const float* ab, lapack_int ldab,
                                const float* afb, lapack_int ldafb,
                                const lapack_int* ipiv, const float* b,
                                lapack_int ldb, float* x, lapack_int ldx,
                                float* ferr, float* berr, float* work,
                                lapack_int* iwork );
lapack_int LAPACKE_dgbrfs_work( int matrix_order, char trans, lapack_int n,
                                lapack_int kl, lapack_int ku, lapack_int nrhs,
                                const double* ab, lapack_int ldab,
                                const double* afb, lapack_int ldafb,
                                const lapack_int* ipiv, const double* b,
                                lapack_int ldb, double* x, lapack_int ldx,
                                double* ferr, double* berr, double* work,
                                lapack_int* iwork );
lapack_int LAPACKE_cgbrfs_work( int matrix_order, char trans, lapack_int n,
                                lapack_int kl, lapack_int ku, lapack_int nrhs,
                                const lapack_complex_float* ab, lapack_int ldab,
                                const lapack_complex_float* afb,
                                lapack_int ldafb, const lapack_int* ipiv,
                                const lapack_complex_float* b, lapack_int ldb,
                                lapack_complex_float* x, lapack_int ldx,
                                float* ferr, float* berr,
                                lapack_complex_float* work, float* rwork );
lapack_int LAPACKE_zgbrfs_work( int matrix_order, char trans, lapack_int n,
                                lapack_int kl, lapack_int ku, lapack_int nrhs,
                                const lapack_complex_double* ab,
                                lapack_int ldab,
                                const lapack_complex_double* afb,
                                lapack_int ldafb, const lapack_int* ipiv,
                                const lapack_complex_double* b, lapack_int ldb,
                                lapack_complex_double* x, lapack_int ldx,
                                double* ferr, double* berr,
                                lapack_complex_double* work, double* rwork );

lapack_int LAPACKE_sgbrfsx_work( int matrix_order, char trans, char equed,
                                 lapack_int n, lapack_int kl, lapack_int ku,
                                 lapack_int nrhs, const float* ab,
                                 lapack_int ldab, const float* afb,
                                 lapack_int ldafb, const lapack_int* ipiv,
                                 const float* r, const float* c, const float* b,
                                 lapack_int ldb, float* x, lapack_int ldx,
                                 float* rcond, float* berr,
                                 lapack_int n_err_bnds, float* err_bnds_norm,
                                 float* err_bnds_comp, lapack_int nparams,
                                 float* params, float* work,
                                 lapack_int* iwork );
lapack_int LAPACKE_dgbrfsx_work( int matrix_order, char trans, char equed,
                                 lapack_int n, lapack_int kl, lapack_int ku,
                                 lapack_int nrhs, const double* ab,
                                 lapack_int ldab, const double* afb,
                                 lapack_int ldafb, const lapack_int* ipiv,
                                 const double* r, const double* c,
                                 const double* b, lapack_int ldb, double* x,
                                 lapack_int ldx, double* rcond, double* berr,
                                 lapack_int n_err_bnds, double* err_bnds_norm,
                                 double* err_bnds_comp, lapack_int nparams,
                                 double* params, double* work,
                                 lapack_int* iwork );
lapack_int LAPACKE_cgbrfsx_work( int matrix_order, char trans, char equed,
                                 lapack_int n, lapack_int kl, lapack_int ku,
                                 lapack_int nrhs,
                                 const lapack_complex_float* ab,
                                 lapack_int ldab,
                                 const lapack_complex_float* afb,
                                 lapack_int ldafb, const lapack_int* ipiv,
                                 const float* r, const float* c,
                                 const lapack_complex_float* b, lapack_int ldb,
                                 lapack_complex_float* x, lapack_int ldx,
                                 float* rcond, float* berr,
                                 lapack_int n_err_bnds, float* err_bnds_norm,
                                 float* err_bnds_comp, lapack_int nparams,
                                 float* params, lapack_complex_float* work,
                                 float* rwork );
lapack_int LAPACKE_zgbrfsx_work( int matrix_order, char trans, char equed,
                                 lapack_int n, lapack_int kl, lapack_int ku,
                                 lapack_int nrhs,
                                 const lapack_complex_double* ab,
                                 lapack_int ldab,
                                 const lapack_complex_double* afb,
                                 lapack_int ldafb, const lapack_int* ipiv,
                                 const double* r, const double* c,
                                 const lapack_complex_double* b, lapack_int ldb,
                                 lapack_complex_double* x, lapack_int ldx,
                                 double* rcond, double* berr,
                                 lapack_int n_err_bnds, double* err_bnds_norm,
                                 double* err_bnds_comp, lapack_int nparams,
                                 double* params, lapack_complex_double* work,
                                 double* rwork );

lapack_int LAPACKE_sgbsv_work( int matrix_order, lapack_int n, lapack_int kl,
                               lapack_int ku, lapack_int nrhs, float* ab,
                               lapack_int ldab, lapack_int* ipiv, float* b,
                               lapack_int ldb );
lapack_int LAPACKE_dgbsv_work( int matrix_order, lapack_int n, lapack_int kl,
                               lapack_int ku, lapack_int nrhs, double* ab,
                               lapack_int ldab, lapack_int* ipiv, double* b,
                               lapack_int ldb );
lapack_int LAPACKE_cgbsv_work( int matrix_order, lapack_int n, lapack_int kl,
                               lapack_int ku, lapack_int nrhs,
                               lapack_complex_float* ab, lapack_int ldab,
                               lapack_int* ipiv, lapack_complex_float* b,
                               lapack_int ldb );
lapack_int LAPACKE_zgbsv_work( int matrix_order, lapack_int n, lapack_int kl,
                               lapack_int ku, lapack_int nrhs,
                               lapack_complex_double* ab, lapack_int ldab,
                               lapack_int* ipiv, lapack_complex_double* b,
                               lapack_int ldb );

lapack_int LAPACKE_sgbsvx_work( int matrix_order, char fact, char trans,
                                lapack_int n, lapack_int kl, lapack_int ku,
                                lapack_int nrhs, float* ab, lapack_int ldab,
                                float* afb, lapack_int ldafb, lapack_int* ipiv,
                                char* equed, float* r, float* c, float* b,
                                lapack_int ldb, float* x, lapack_int ldx,
                                float* rcond, float* ferr, float* berr,
                                float* work, lapack_int* iwork );
lapack_int LAPACKE_dgbsvx_work( int matrix_order, char fact, char trans,
                                lapack_int n, lapack_int kl, lapack_int ku,
                                lapack_int nrhs, double* ab, lapack_int ldab,
                                double* afb, lapack_int ldafb, lapack_int* ipiv,
                                char* equed, double* r, double* c, double* b,
                                lapack_int ldb, double* x, lapack_int ldx,
                                double* rcond, double* ferr, double* berr,
                                double* work, lapack_int* iwork );
lapack_int LAPACKE_cgbsvx_work( int matrix_order, char fact, char trans,
                                lapack_int n, lapack_int kl, lapack_int ku,
                                lapack_int nrhs, lapack_complex_float* ab,
                                lapack_int ldab, lapack_complex_float* afb,
                                lapack_int ldafb, lapack_int* ipiv, char* equed,
                                float* r, float* c, lapack_complex_float* b,
                                lapack_int ldb, lapack_complex_float* x,
                                lapack_int ldx, float* rcond, float* ferr,
                                float* berr, lapack_complex_float* work,
                                float* rwork );
lapack_int LAPACKE_zgbsvx_work( int matrix_order, char fact, char trans,
                                lapack_int n, lapack_int kl, lapack_int ku,
                                lapack_int nrhs, lapack_complex_double* ab,
                                lapack_int ldab, lapack_complex_double* afb,
                                lapack_int ldafb, lapack_int* ipiv, char* equed,
                                double* r, double* c, lapack_complex_double* b,
                                lapack_int ldb, lapack_complex_double* x,
                                lapack_int ldx, double* rcond, double* ferr,
                                double* berr, lapack_complex_double* work,
                                double* rwork );

lapack_int LAPACKE_sgbsvxx_work( int matrix_order, char fact, char trans,
                                 lapack_int n, lapack_int kl, lapack_int ku,
                                 lapack_int nrhs, float* ab, lapack_int ldab,
                                 float* afb, lapack_int ldafb, lapack_int* ipiv,
                                 char* equed, float* r, float* c, float* b,
                                 lapack_int ldb, float* x, lapack_int ldx,
                                 float* rcond, float* rpvgrw, float* berr,
                                 lapack_int n_err_bnds, float* err_bnds_norm,
                                 float* err_bnds_comp, lapack_int nparams,
                                 float* params, float* work,
                                 lapack_int* iwork );
lapack_int LAPACKE_dgbsvxx_work( int matrix_order, char fact, char trans,
                                 lapack_int n, lapack_int kl, lapack_int ku,
                                 lapack_int nrhs, double* ab, lapack_int ldab,
                                 double* afb, lapack_int ldafb,
                                 lapack_int* ipiv, char* equed, double* r,
                                 double* c, double* b, lapack_int ldb,
                                 double* x, lapack_int ldx, double* rcond,
                                 double* rpvgrw, double* berr,
                                 lapack_int n_err_bnds, double* err_bnds_norm,
                                 double* err_bnds_comp, lapack_int nparams,
                                 double* params, double* work,
                                 lapack_int* iwork );
lapack_int LAPACKE_cgbsvxx_work( int matrix_order, char fact, char trans,
                                 lapack_int n, lapack_int kl, lapack_int ku,
                                 lapack_int nrhs, lapack_complex_float* ab,
                                 lapack_int ldab, lapack_complex_float* afb,
                                 lapack_int ldafb, lapack_int* ipiv,
                                 char* equed, float* r, float* c,
                                 lapack_complex_float* b, lapack_int ldb,
                                 lapack_complex_float* x, lapack_int ldx,
                                 float* rcond, float* rpvgrw, float* berr,
                                 lapack_int n_err_bnds, float* err_bnds_norm,
                                 float* err_bnds_comp, lapack_int nparams,
                                 float* params, lapack_complex_float* work,
                                 float* rwork );
lapack_int LAPACKE_zgbsvxx_work( int matrix_order, char fact, char trans,
                                 lapack_int n, lapack_int kl, lapack_int ku,
                                 lapack_int nrhs, lapack_complex_double* ab,
                                 lapack_int ldab, lapack_complex_double* afb,
                                 lapack_int ldafb, lapack_int* ipiv,
                                 char* equed, double* r, double* c,
                                 lapack_complex_double* b, lapack_int ldb,
                                 lapack_complex_double* x, lapack_int ldx,
                                 double* rcond, double* rpvgrw, double* berr,
                                 lapack_int n_err_bnds, double* err_bnds_norm,
                                 double* err_bnds_comp, lapack_int nparams,
                                 double* params, lapack_complex_double* work,
                                 double* rwork );

lapack_int LAPACKE_sgbtrf_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_int kl, lapack_int ku, float* ab,
                                lapack_int ldab, lapack_int* ipiv );
lapack_int LAPACKE_dgbtrf_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_int kl, lapack_int ku, double* ab,
                                lapack_int ldab, lapack_int* ipiv );
lapack_int LAPACKE_cgbtrf_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_int kl, lapack_int ku,
                                lapack_complex_float* ab, lapack_int ldab,
                                lapack_int* ipiv );
lapack_int LAPACKE_zgbtrf_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_int kl, lapack_int ku,
                                lapack_complex_double* ab, lapack_int ldab,
                                lapack_int* ipiv );

lapack_int LAPACKE_sgbtrs_work( int matrix_order, char trans, lapack_int n,
                                lapack_int kl, lapack_int ku, lapack_int nrhs,
                                const float* ab, lapack_int ldab,
                                const lapack_int* ipiv, float* b,
                                lapack_int ldb );
lapack_int LAPACKE_dgbtrs_work( int matrix_order, char trans, lapack_int n,
                                lapack_int kl, lapack_int ku, lapack_int nrhs,
                                const double* ab, lapack_int ldab,
                                const lapack_int* ipiv, double* b,
                                lapack_int ldb );
lapack_int LAPACKE_cgbtrs_work( int matrix_order, char trans, lapack_int n,
                                lapack_int kl, lapack_int ku, lapack_int nrhs,
                                const lapack_complex_float* ab, lapack_int ldab,
                                const lapack_int* ipiv, lapack_complex_float* b,
                                lapack_int ldb );
lapack_int LAPACKE_zgbtrs_work( int matrix_order, char trans, lapack_int n,
                                lapack_int kl, lapack_int ku, lapack_int nrhs,
                                const lapack_complex_double* ab,
                                lapack_int ldab, const lapack_int* ipiv,
                                lapack_complex_double* b, lapack_int ldb );

lapack_int LAPACKE_sgebak_work( int matrix_order, char job, char side,
                                lapack_int n, lapack_int ilo, lapack_int ihi,
                                const float* scale, lapack_int m, float* v,
                                lapack_int ldv );
lapack_int LAPACKE_dgebak_work( int matrix_order, char job, char side,
                                lapack_int n, lapack_int ilo, lapack_int ihi,
                                const double* scale, lapack_int m, double* v,
                                lapack_int ldv );
lapack_int LAPACKE_cgebak_work( int matrix_order, char job, char side,
                                lapack_int n, lapack_int ilo, lapack_int ihi,
                                const float* scale, lapack_int m,
                                lapack_complex_float* v, lapack_int ldv );
lapack_int LAPACKE_zgebak_work( int matrix_order, char job, char side,
                                lapack_int n, lapack_int ilo, lapack_int ihi,
                                const double* scale, lapack_int m,
                                lapack_complex_double* v, lapack_int ldv );

lapack_int LAPACKE_sgebal_work( int matrix_order, char job, lapack_int n,
                                float* a, lapack_int lda, lapack_int* ilo,
                                lapack_int* ihi, float* scale );
lapack_int LAPACKE_dgebal_work( int matrix_order, char job, lapack_int n,
                                double* a, lapack_int lda, lapack_int* ilo,
                                lapack_int* ihi, double* scale );
lapack_int LAPACKE_cgebal_work( int matrix_order, char job, lapack_int n,
                                lapack_complex_float* a, lapack_int lda,
                                lapack_int* ilo, lapack_int* ihi,
                                float* scale );
lapack_int LAPACKE_zgebal_work( int matrix_order, char job, lapack_int n,
                                lapack_complex_double* a, lapack_int lda,
                                lapack_int* ilo, lapack_int* ihi,
                                double* scale );

lapack_int LAPACKE_sgebrd_work( int matrix_order, lapack_int m, lapack_int n,
                                float* a, lapack_int lda, float* d, float* e,
                                float* tauq, float* taup, float* work,
                                lapack_int lwork );
lapack_int LAPACKE_dgebrd_work( int matrix_order, lapack_int m, lapack_int n,
                                double* a, lapack_int lda, double* d, double* e,
                                double* tauq, double* taup, double* work,
                                lapack_int lwork );
lapack_int LAPACKE_cgebrd_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_complex_float* a, lapack_int lda,
                                float* d, float* e, lapack_complex_float* tauq,
                                lapack_complex_float* taup,
                                lapack_complex_float* work, lapack_int lwork );
lapack_int LAPACKE_zgebrd_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_complex_double* a, lapack_int lda,
                                double* d, double* e,
                                lapack_complex_double* tauq,
                                lapack_complex_double* taup,
                                lapack_complex_double* work, lapack_int lwork );

lapack_int LAPACKE_sgecon_work( int matrix_order, char norm, lapack_int n,
                                const float* a, lapack_int lda, float anorm,
                                float* rcond, float* work, lapack_int* iwork );
lapack_int LAPACKE_dgecon_work( int matrix_order, char norm, lapack_int n,
                                const double* a, lapack_int lda, double anorm,
                                double* rcond, double* work,
                                lapack_int* iwork );
lapack_int LAPACKE_cgecon_work( int matrix_order, char norm, lapack_int n,
                                const lapack_complex_float* a, lapack_int lda,
                                float anorm, float* rcond,
                                lapack_complex_float* work, float* rwork );
lapack_int LAPACKE_zgecon_work( int matrix_order, char norm, lapack_int n,
                                const lapack_complex_double* a, lapack_int lda,
                                double anorm, double* rcond,
                                lapack_complex_double* work, double* rwork );

lapack_int LAPACKE_sgeequ_work( int matrix_order, lapack_int m, lapack_int n,
                                const float* a, lapack_int lda, float* r,
                                float* c, float* rowcnd, float* colcnd,
                                float* amax );
lapack_int LAPACKE_dgeequ_work( int matrix_order, lapack_int m, lapack_int n,
                                const double* a, lapack_int lda, double* r,
                                double* c, double* rowcnd, double* colcnd,
                                double* amax );
lapack_int LAPACKE_cgeequ_work( int matrix_order, lapack_int m, lapack_int n,
                                const lapack_complex_float* a, lapack_int lda,
                                float* r, float* c, float* rowcnd,
                                float* colcnd, float* amax );
lapack_int LAPACKE_zgeequ_work( int matrix_order, lapack_int m, lapack_int n,
                                const lapack_complex_double* a, lapack_int lda,
                                double* r, double* c, double* rowcnd,
                                double* colcnd, double* amax );

lapack_int LAPACKE_sgeequb_work( int matrix_order, lapack_int m, lapack_int n,
                                 const float* a, lapack_int lda, float* r,
                                 float* c, float* rowcnd, float* colcnd,
                                 float* amax );
lapack_int LAPACKE_dgeequb_work( int matrix_order, lapack_int m, lapack_int n,
                                 const double* a, lapack_int lda, double* r,
                                 double* c, double* rowcnd, double* colcnd,
                                 double* amax );
lapack_int LAPACKE_cgeequb_work( int matrix_order, lapack_int m, lapack_int n,
                                 const lapack_complex_float* a, lapack_int lda,
                                 float* r, float* c, float* rowcnd,
                                 float* colcnd, float* amax );
lapack_int LAPACKE_zgeequb_work( int matrix_order, lapack_int m, lapack_int n,
                                 const lapack_complex_double* a, lapack_int lda,
                                 double* r, double* c, double* rowcnd,
                                 double* colcnd, double* amax );

lapack_int LAPACKE_sgees_work( int matrix_order, char jobvs, char sort,
                               LAPACK_S_SELECT2 select, lapack_int n, float* a,
                               lapack_int lda, lapack_int* sdim, float* wr,
                               float* wi, float* vs, lapack_int ldvs,
                               float* work, lapack_int lwork,
                               lapack_logical* bwork );
lapack_int LAPACKE_dgees_work( int matrix_order, char jobvs, char sort,
                               LAPACK_D_SELECT2 select, lapack_int n, double* a,
                               lapack_int lda, lapack_int* sdim, double* wr,
                               double* wi, double* vs, lapack_int ldvs,
                               double* work, lapack_int lwork,
                               lapack_logical* bwork );
lapack_int LAPACKE_cgees_work( int matrix_order, char jobvs, char sort,
                               LAPACK_C_SELECT1 select, lapack_int n,
                               lapack_complex_float* a, lapack_int lda,
                               lapack_int* sdim, lapack_complex_float* w,
                               lapack_complex_float* vs, lapack_int ldvs,
                               lapack_complex_float* work, lapack_int lwork,
                               float* rwork, lapack_logical* bwork );
lapack_int LAPACKE_zgees_work( int matrix_order, char jobvs, char sort,
                               LAPACK_Z_SELECT1 select, lapack_int n,
                               lapack_complex_double* a, lapack_int lda,
                               lapack_int* sdim, lapack_complex_double* w,
                               lapack_complex_double* vs, lapack_int ldvs,
                               lapack_complex_double* work, lapack_int lwork,
                               double* rwork, lapack_logical* bwork );

lapack_int LAPACKE_sgeesx_work( int matrix_order, char jobvs, char sort,
                                LAPACK_S_SELECT2 select, char sense,
                                lapack_int n, float* a, lapack_int lda,
                                lapack_int* sdim, float* wr, float* wi,
                                float* vs, lapack_int ldvs, float* rconde,
                                float* rcondv, float* work, lapack_int lwork,
                                lapack_int* iwork, lapack_int liwork,
                                lapack_logical* bwork );
lapack_int LAPACKE_dgeesx_work( int matrix_order, char jobvs, char sort,
                                LAPACK_D_SELECT2 select, char sense,
                                lapack_int n, double* a, lapack_int lda,
                                lapack_int* sdim, double* wr, double* wi,
                                double* vs, lapack_int ldvs, double* rconde,
                                double* rcondv, double* work, lapack_int lwork,
                                lapack_int* iwork, lapack_int liwork,
                                lapack_logical* bwork );
lapack_int LAPACKE_cgeesx_work( int matrix_order, char jobvs, char sort,
                                LAPACK_C_SELECT1 select, char sense,
                                lapack_int n, lapack_complex_float* a,
                                lapack_int lda, lapack_int* sdim,
                                lapack_complex_float* w,
                                lapack_complex_float* vs, lapack_int ldvs,
                                float* rconde, float* rcondv,
                                lapack_complex_float* work, lapack_int lwork,
                                float* rwork, lapack_logical* bwork );
lapack_int LAPACKE_zgeesx_work( int matrix_order, char jobvs, char sort,
                                LAPACK_Z_SELECT1 select, char sense,
                                lapack_int n, lapack_complex_double* a,
                                lapack_int lda, lapack_int* sdim,
                                lapack_complex_double* w,
                                lapack_complex_double* vs, lapack_int ldvs,
                                double* rconde, double* rcondv,
                                lapack_complex_double* work, lapack_int lwork,
                                double* rwork, lapack_logical* bwork );

lapack_int LAPACKE_sgeev_work( int matrix_order, char jobvl, char jobvr,
                               lapack_int n, float* a, lapack_int lda,
                               float* wr, float* wi, float* vl, lapack_int ldvl,
                               float* vr, lapack_int ldvr, float* work,
                               lapack_int lwork );
lapack_int LAPACKE_dgeev_work( int matrix_order, char jobvl, char jobvr,
                               lapack_int n, double* a, lapack_int lda,
                               double* wr, double* wi, double* vl,
                               lapack_int ldvl, double* vr, lapack_int ldvr,
                               double* work, lapack_int lwork );
lapack_int LAPACKE_cgeev_work( int matrix_order, char jobvl, char jobvr,
                               lapack_int n, lapack_complex_float* a,
                               lapack_int lda, lapack_complex_float* w,
                               lapack_complex_float* vl, lapack_int ldvl,
                               lapack_complex_float* vr, lapack_int ldvr,
                               lapack_complex_float* work, lapack_int lwork,
                               float* rwork );
lapack_int LAPACKE_zgeev_work( int matrix_order, char jobvl, char jobvr,
                               lapack_int n, lapack_complex_double* a,
                               lapack_int lda, lapack_complex_double* w,
                               lapack_complex_double* vl, lapack_int ldvl,
                               lapack_complex_double* vr, lapack_int ldvr,
                               lapack_complex_double* work, lapack_int lwork,
                               double* rwork );

lapack_int LAPACKE_sgeevx_work( int matrix_order, char balanc, char jobvl,
                                char jobvr, char sense, lapack_int n, float* a,
                                lapack_int lda, float* wr, float* wi, float* vl,
                                lapack_int ldvl, float* vr, lapack_int ldvr,
                                lapack_int* ilo, lapack_int* ihi, float* scale,
                                float* abnrm, float* rconde, float* rcondv,
                                float* work, lapack_int lwork,
                                lapack_int* iwork );
lapack_int LAPACKE_dgeevx_work( int matrix_order, char balanc, char jobvl,
                                char jobvr, char sense, lapack_int n, double* a,
                                lapack_int lda, double* wr, double* wi,
                                double* vl, lapack_int ldvl, double* vr,
                                lapack_int ldvr, lapack_int* ilo,
                                lapack_int* ihi, double* scale, double* abnrm,
                                double* rconde, double* rcondv, double* work,
                                lapack_int lwork, lapack_int* iwork );
lapack_int LAPACKE_cgeevx_work( int matrix_order, char balanc, char jobvl,
                                char jobvr, char sense, lapack_int n,
                                lapack_complex_float* a, lapack_int lda,
                                lapack_complex_float* w,
                                lapack_complex_float* vl, lapack_int ldvl,
                                lapack_complex_float* vr, lapack_int ldvr,
                                lapack_int* ilo, lapack_int* ihi, float* scale,
                                float* abnrm, float* rconde, float* rcondv,
                                lapack_complex_float* work, lapack_int lwork,
                                float* rwork );
lapack_int LAPACKE_zgeevx_work( int matrix_order, char balanc, char jobvl,
                                char jobvr, char sense, lapack_int n,
                                lapack_complex_double* a, lapack_int lda,
                                lapack_complex_double* w,
                                lapack_complex_double* vl, lapack_int ldvl,
                                lapack_complex_double* vr, lapack_int ldvr,
                                lapack_int* ilo, lapack_int* ihi, double* scale,
                                double* abnrm, double* rconde, double* rcondv,
                                lapack_complex_double* work, lapack_int lwork,
                                double* rwork );

lapack_int LAPACKE_sgehrd_work( int matrix_order, lapack_int n, lapack_int ilo,
                                lapack_int ihi, float* a, lapack_int lda,
                                float* tau, float* work, lapack_int lwork );
lapack_int LAPACKE_dgehrd_work( int matrix_order, lapack_int n, lapack_int ilo,
                                lapack_int ihi, double* a, lapack_int lda,
                                double* tau, double* work, lapack_int lwork );
lapack_int LAPACKE_cgehrd_work( int matrix_order, lapack_int n, lapack_int ilo,
                                lapack_int ihi, lapack_complex_float* a,
                                lapack_int lda, lapack_complex_float* tau,
                                lapack_complex_float* work, lapack_int lwork );
lapack_int LAPACKE_zgehrd_work( int matrix_order, lapack_int n, lapack_int ilo,
                                lapack_int ihi, lapack_complex_double* a,
                                lapack_int lda, lapack_complex_double* tau,
                                lapack_complex_double* work, lapack_int lwork );

lapack_int LAPACKE_sgejsv_work( int matrix_order, char joba, char jobu,
                                char jobv, char jobr, char jobt, char jobp,
                                lapack_int m, lapack_int n, float* a,
                                lapack_int lda, float* sva, float* u,
                                lapack_int ldu, float* v, lapack_int ldv,
                                float* work, lapack_int lwork,
                                lapack_int* iwork );
lapack_int LAPACKE_dgejsv_work( int matrix_order, char joba, char jobu,
                                char jobv, char jobr, char jobt, char jobp,
                                lapack_int m, lapack_int n, double* a,
                                lapack_int lda, double* sva, double* u,
                                lapack_int ldu, double* v, lapack_int ldv,
                                double* work, lapack_int lwork,
                                lapack_int* iwork );

lapack_int LAPACKE_sgelqf_work( int matrix_order, lapack_int m, lapack_int n,
                                float* a, lapack_int lda, float* tau,
                                float* work, lapack_int lwork );
lapack_int LAPACKE_dgelqf_work( int matrix_order, lapack_int m, lapack_int n,
                                double* a, lapack_int lda, double* tau,
                                double* work, lapack_int lwork );
lapack_int LAPACKE_cgelqf_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_complex_float* a, lapack_int lda,
                                lapack_complex_float* tau,
                                lapack_complex_float* work, lapack_int lwork );
lapack_int LAPACKE_zgelqf_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_complex_double* a, lapack_int lda,
                                lapack_complex_double* tau,
                                lapack_complex_double* work, lapack_int lwork );

lapack_int LAPACKE_sgels_work( int matrix_order, char trans, lapack_int m,
                               lapack_int n, lapack_int nrhs, float* a,
                               lapack_int lda, float* b, lapack_int ldb,
                               float* work, lapack_int lwork );
lapack_int LAPACKE_dgels_work( int matrix_order, char trans, lapack_int m,
                               lapack_int n, lapack_int nrhs, double* a,
                               lapack_int lda, double* b, lapack_int ldb,
                               double* work, lapack_int lwork );
lapack_int LAPACKE_cgels_work( int matrix_order, char trans, lapack_int m,
                               lapack_int n, lapack_int nrhs,
                               lapack_complex_float* a, lapack_int lda,
                               lapack_complex_float* b, lapack_int ldb,
                               lapack_complex_float* work, lapack_int lwork );
lapack_int LAPACKE_zgels_work( int matrix_order, char trans, lapack_int m,
                               lapack_int n, lapack_int nrhs,
                               lapack_complex_double* a, lapack_int lda,
                               lapack_complex_double* b, lapack_int ldb,
                               lapack_complex_double* work, lapack_int lwork );

lapack_int LAPACKE_sgelsd_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_int nrhs, float* a, lapack_int lda,
                                float* b, lapack_int ldb, float* s, float rcond,
                                lapack_int* rank, float* work, lapack_int lwork,
                                lapack_int* iwork );
lapack_int LAPACKE_dgelsd_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_int nrhs, double* a, lapack_int lda,
                                double* b, lapack_int ldb, double* s,
                                double rcond, lapack_int* rank, double* work,
                                lapack_int lwork, lapack_int* iwork );
lapack_int LAPACKE_cgelsd_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_int nrhs, lapack_complex_float* a,
                                lapack_int lda, lapack_complex_float* b,
                                lapack_int ldb, float* s, float rcond,
                                lapack_int* rank, lapack_complex_float* work,
                                lapack_int lwork, float* rwork,
                                lapack_int* iwork );
lapack_int LAPACKE_zgelsd_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_int nrhs, lapack_complex_double* a,
                                lapack_int lda, lapack_complex_double* b,
                                lapack_int ldb, double* s, double rcond,
                                lapack_int* rank, lapack_complex_double* work,
                                lapack_int lwork, double* rwork,
                                lapack_int* iwork );

lapack_int LAPACKE_sgelss_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_int nrhs, float* a, lapack_int lda,
                                float* b, lapack_int ldb, float* s, float rcond,
                                lapack_int* rank, float* work,
                                lapack_int lwork );
lapack_int LAPACKE_dgelss_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_int nrhs, double* a, lapack_int lda,
                                double* b, lapack_int ldb, double* s,
                                double rcond, lapack_int* rank, double* work,
                                lapack_int lwork );
lapack_int LAPACKE_cgelss_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_int nrhs, lapack_complex_float* a,
                                lapack_int lda, lapack_complex_float* b,
                                lapack_int ldb, float* s, float rcond,
                                lapack_int* rank, lapack_complex_float* work,
                                lapack_int lwork, float* rwork );
lapack_int LAPACKE_zgelss_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_int nrhs, lapack_complex_double* a,
                                lapack_int lda, lapack_complex_double* b,
                                lapack_int ldb, double* s, double rcond,
                                lapack_int* rank, lapack_complex_double* work,
                                lapack_int lwork, double* rwork );

lapack_int LAPACKE_sgelsy_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_int nrhs, float* a, lapack_int lda,
                                float* b, lapack_int ldb, lapack_int* jpvt,
                                float rcond, lapack_int* rank, float* work,
                                lapack_int lwork );
lapack_int LAPACKE_dgelsy_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_int nrhs, double* a, lapack_int lda,
                                double* b, lapack_int ldb, lapack_int* jpvt,
                                double rcond, lapack_int* rank, double* work,
                                lapack_int lwork );
lapack_int LAPACKE_cgelsy_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_int nrhs, lapack_complex_float* a,
                                lapack_int lda, lapack_complex_float* b,
                                lapack_int ldb, lapack_int* jpvt, float rcond,
                                lapack_int* rank, lapack_complex_float* work,
                                lapack_int lwork, float* rwork );
lapack_int LAPACKE_zgelsy_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_int nrhs, lapack_complex_double* a,
                                lapack_int lda, lapack_complex_double* b,
                                lapack_int ldb, lapack_int* jpvt, double rcond,
                                lapack_int* rank, lapack_complex_double* work,
                                lapack_int lwork, double* rwork );

lapack_int LAPACKE_sgeqlf_work( int matrix_order, lapack_int m, lapack_int n,
                                float* a, lapack_int lda, float* tau,
                                float* work, lapack_int lwork );
lapack_int LAPACKE_dgeqlf_work( int matrix_order, lapack_int m, lapack_int n,
                                double* a, lapack_int lda, double* tau,
                                double* work, lapack_int lwork );
lapack_int LAPACKE_cgeqlf_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_complex_float* a, lapack_int lda,
                                lapack_complex_float* tau,
                                lapack_complex_float* work, lapack_int lwork );
lapack_int LAPACKE_zgeqlf_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_complex_double* a, lapack_int lda,
                                lapack_complex_double* tau,
                                lapack_complex_double* work, lapack_int lwork );

lapack_int LAPACKE_sgeqp3_work( int matrix_order, lapack_int m, lapack_int n,
                                float* a, lapack_int lda, lapack_int* jpvt,
                                float* tau, float* work, lapack_int lwork );
lapack_int LAPACKE_dgeqp3_work( int matrix_order, lapack_int m, lapack_int n,
                                double* a, lapack_int lda, lapack_int* jpvt,
                                double* tau, double* work, lapack_int lwork );
lapack_int LAPACKE_cgeqp3_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_complex_float* a, lapack_int lda,
                                lapack_int* jpvt, lapack_complex_float* tau,
                                lapack_complex_float* work, lapack_int lwork,
                                float* rwork );
lapack_int LAPACKE_zgeqp3_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_complex_double* a, lapack_int lda,
                                lapack_int* jpvt, lapack_complex_double* tau,
                                lapack_complex_double* work, lapack_int lwork,
                                double* rwork );

lapack_int LAPACKE_sgeqpf_work( int matrix_order, lapack_int m, lapack_int n,
                                float* a, lapack_int lda, lapack_int* jpvt,
                                float* tau, float* work );
lapack_int LAPACKE_dgeqpf_work( int matrix_order, lapack_int m, lapack_int n,
                                double* a, lapack_int lda, lapack_int* jpvt,
                                double* tau, double* work );
lapack_int LAPACKE_cgeqpf_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_complex_float* a, lapack_int lda,
                                lapack_int* jpvt, lapack_complex_float* tau,
                                lapack_complex_float* work, float* rwork );
lapack_int LAPACKE_zgeqpf_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_complex_double* a, lapack_int lda,
                                lapack_int* jpvt, lapack_complex_double* tau,
                                lapack_complex_double* work, double* rwork );

lapack_int LAPACKE_sgeqrf_work( int matrix_order, lapack_int m, lapack_int n,
                                float* a, lapack_int lda, float* tau,
                                float* work, lapack_int lwork );
lapack_int LAPACKE_dgeqrf_work( int matrix_order, lapack_int m, lapack_int n,
                                double* a, lapack_int lda, double* tau,
                                double* work, lapack_int lwork );
lapack_int LAPACKE_cgeqrf_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_complex_float* a, lapack_int lda,
                                lapack_complex_float* tau,
                                lapack_complex_float* work, lapack_int lwork );
lapack_int LAPACKE_zgeqrf_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_complex_double* a, lapack_int lda,
                                lapack_complex_double* tau,
                                lapack_complex_double* work, lapack_int lwork );

lapack_int LAPACKE_sgeqrfp_work( int matrix_order, lapack_int m, lapack_int n,
                                 float* a, lapack_int lda, float* tau,
                                 float* work, lapack_int lwork );
lapack_int LAPACKE_dgeqrfp_work( int matrix_order, lapack_int m, lapack_int n,
                                 double* a, lapack_int lda, double* tau,
                                 double* work, lapack_int lwork );
lapack_int LAPACKE_cgeqrfp_work( int matrix_order, lapack_int m, lapack_int n,
                                 lapack_complex_float* a, lapack_int lda,
                                 lapack_complex_float* tau,
                                 lapack_complex_float* work, lapack_int lwork );
lapack_int LAPACKE_zgeqrfp_work( int matrix_order, lapack_int m, lapack_int n,
                                 lapack_complex_double* a, lapack_int lda,
                                 lapack_complex_double* tau,
                                 lapack_complex_double* work,
                                 lapack_int lwork );

lapack_int LAPACKE_sgerfs_work( int matrix_order, char trans, lapack_int n,
                                lapack_int nrhs, const float* a, lapack_int lda,
                                const float* af, lapack_int ldaf,
                                const lapack_int* ipiv, const float* b,
                                lapack_int ldb, float* x, lapack_int ldx,
                                float* ferr, float* berr, float* work,
                                lapack_int* iwork );
lapack_int LAPACKE_dgerfs_work( int matrix_order, char trans, lapack_int n,
                                lapack_int nrhs, const double* a,
                                lapack_int lda, const double* af,
                                lapack_int ldaf, const lapack_int* ipiv,
                                const double* b, lapack_int ldb, double* x,
                                lapack_int ldx, double* ferr, double* berr,
                                double* work, lapack_int* iwork );
lapack_int LAPACKE_cgerfs_work( int matrix_order, char trans, lapack_int n,
                                lapack_int nrhs, const lapack_complex_float* a,
                                lapack_int lda, const lapack_complex_float* af,
                                lapack_int ldaf, const lapack_int* ipiv,
                                const lapack_complex_float* b, lapack_int ldb,
                                lapack_complex_float* x, lapack_int ldx,
                                float* ferr, float* berr,
                                lapack_complex_float* work, float* rwork );
lapack_int LAPACKE_zgerfs_work( int matrix_order, char trans, lapack_int n,
                                lapack_int nrhs, const lapack_complex_double* a,
                                lapack_int lda, const lapack_complex_double* af,
                                lapack_int ldaf, const lapack_int* ipiv,
                                const lapack_complex_double* b, lapack_int ldb,
                                lapack_complex_double* x, lapack_int ldx,
                                double* ferr, double* berr,
                                lapack_complex_double* work, double* rwork );

lapack_int LAPACKE_sgerfsx_work( int matrix_order, char trans, char equed,
                                 lapack_int n, lapack_int nrhs, const float* a,
                                 lapack_int lda, const float* af,
                                 lapack_int ldaf, const lapack_int* ipiv,
                                 const float* r, const float* c, const float* b,
                                 lapack_int ldb, float* x, lapack_int ldx,
                                 float* rcond, float* berr,
                                 lapack_int n_err_bnds, float* err_bnds_norm,
                                 float* err_bnds_comp, lapack_int nparams,
                                 float* params, float* work,
                                 lapack_int* iwork );
lapack_int LAPACKE_dgerfsx_work( int matrix_order, char trans, char equed,
                                 lapack_int n, lapack_int nrhs, const double* a,
                                 lapack_int lda, const double* af,
                                 lapack_int ldaf, const lapack_int* ipiv,
                                 const double* r, const double* c,
                                 const double* b, lapack_int ldb, double* x,
                                 lapack_int ldx, double* rcond, double* berr,
                                 lapack_int n_err_bnds, double* err_bnds_norm,
                                 double* err_bnds_comp, lapack_int nparams,
                                 double* params, double* work,
                                 lapack_int* iwork );
lapack_int LAPACKE_cgerfsx_work( int matrix_order, char trans, char equed,
                                 lapack_int n, lapack_int nrhs,
                                 const lapack_complex_float* a, lapack_int lda,
                                 const lapack_complex_float* af,
                                 lapack_int ldaf, const lapack_int* ipiv,
                                 const float* r, const float* c,
                                 const lapack_complex_float* b, lapack_int ldb,
                                 lapack_complex_float* x, lapack_int ldx,
                                 float* rcond, float* berr,
                                 lapack_int n_err_bnds, float* err_bnds_norm,
                                 float* err_bnds_comp, lapack_int nparams,
                                 float* params, lapack_complex_float* work,
                                 float* rwork );
lapack_int LAPACKE_zgerfsx_work( int matrix_order, char trans, char equed,
                                 lapack_int n, lapack_int nrhs,
                                 const lapack_complex_double* a, lapack_int lda,
                                 const lapack_complex_double* af,
                                 lapack_int ldaf, const lapack_int* ipiv,
                                 const double* r, const double* c,
                                 const lapack_complex_double* b, lapack_int ldb,
                                 lapack_complex_double* x, lapack_int ldx,
                                 double* rcond, double* berr,
                                 lapack_int n_err_bnds, double* err_bnds_norm,
                                 double* err_bnds_comp, lapack_int nparams,
                                 double* params, lapack_complex_double* work,
                                 double* rwork );

lapack_int LAPACKE_sgerqf_work( int matrix_order, lapack_int m, lapack_int n,
                                float* a, lapack_int lda, float* tau,
                                float* work, lapack_int lwork );
lapack_int LAPACKE_dgerqf_work( int matrix_order, lapack_int m, lapack_int n,
                                double* a, lapack_int lda, double* tau,
                                double* work, lapack_int lwork );
lapack_int LAPACKE_cgerqf_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_complex_float* a, lapack_int lda,
                                lapack_complex_float* tau,
                                lapack_complex_float* work, lapack_int lwork );
lapack_int LAPACKE_zgerqf_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_complex_double* a, lapack_int lda,
                                lapack_complex_double* tau,
                                lapack_complex_double* work, lapack_int lwork );

lapack_int LAPACKE_sgesdd_work( int matrix_order, char jobz, lapack_int m,
                                lapack_int n, float* a, lapack_int lda,
                                float* s, float* u, lapack_int ldu, float* vt,
                                lapack_int ldvt, float* work, lapack_int lwork,
                                lapack_int* iwork );
lapack_int LAPACKE_dgesdd_work( int matrix_order, char jobz, lapack_int m,
                                lapack_int n, double* a, lapack_int lda,
                                double* s, double* u, lapack_int ldu,
                                double* vt, lapack_int ldvt, double* work,
                                lapack_int lwork, lapack_int* iwork );
lapack_int LAPACKE_cgesdd_work( int matrix_order, char jobz, lapack_int m,
                                lapack_int n, lapack_complex_float* a,
                                lapack_int lda, float* s,
                                lapack_complex_float* u, lapack_int ldu,
                                lapack_complex_float* vt, lapack_int ldvt,
                                lapack_complex_float* work, lapack_int lwork,
                                float* rwork, lapack_int* iwork );
lapack_int LAPACKE_zgesdd_work( int matrix_order, char jobz, lapack_int m,
                                lapack_int n, lapack_complex_double* a,
                                lapack_int lda, double* s,
                                lapack_complex_double* u, lapack_int ldu,
                                lapack_complex_double* vt, lapack_int ldvt,
                                lapack_complex_double* work, lapack_int lwork,
                                double* rwork, lapack_int* iwork );

lapack_int LAPACKE_sgesv_work( int matrix_order, lapack_int n, lapack_int nrhs,
                               float* a, lapack_int lda, lapack_int* ipiv,
                               float* b, lapack_int ldb );
lapack_int LAPACKE_dgesv_work( int matrix_order, lapack_int n, lapack_int nrhs,
                               double* a, lapack_int lda, lapack_int* ipiv,
                               double* b, lapack_int ldb );
lapack_int LAPACKE_cgesv_work( int matrix_order, lapack_int n, lapack_int nrhs,
                               lapack_complex_float* a, lapack_int lda,
                               lapack_int* ipiv, lapack_complex_float* b,
                               lapack_int ldb );
lapack_int LAPACKE_zgesv_work( int matrix_order, lapack_int n, lapack_int nrhs,
                               lapack_complex_double* a, lapack_int lda,
                               lapack_int* ipiv, lapack_complex_double* b,
                               lapack_int ldb );
lapack_int LAPACKE_dsgesv_work( int matrix_order, lapack_int n, lapack_int nrhs,
                                double* a, lapack_int lda, lapack_int* ipiv,
                                double* b, lapack_int ldb, double* x,
                                lapack_int ldx, double* work, float* swork,
                                lapack_int* iter );
lapack_int LAPACKE_zcgesv_work( int matrix_order, lapack_int n, lapack_int nrhs,
                                lapack_complex_double* a, lapack_int lda,
                                lapack_int* ipiv, lapack_complex_double* b,
                                lapack_int ldb, lapack_complex_double* x,
                                lapack_int ldx, lapack_complex_double* work,
                                lapack_complex_float* swork, double* rwork,
                                lapack_int* iter );

lapack_int LAPACKE_sgesvd_work( int matrix_order, char jobu, char jobvt,
                                lapack_int m, lapack_int n, float* a,
                                lapack_int lda, float* s, float* u,
                                lapack_int ldu, float* vt, lapack_int ldvt,
                                float* work, lapack_int lwork );
lapack_int LAPACKE_dgesvd_work( int matrix_order, char jobu, char jobvt,
                                lapack_int m, lapack_int n, double* a,
                                lapack_int lda, double* s, double* u,
                                lapack_int ldu, double* vt, lapack_int ldvt,
                                double* work, lapack_int lwork );
lapack_int LAPACKE_cgesvd_work( int matrix_order, char jobu, char jobvt,
                                lapack_int m, lapack_int n,
                                lapack_complex_float* a, lapack_int lda,
                                float* s, lapack_complex_float* u,
                                lapack_int ldu, lapack_complex_float* vt,
                                lapack_int ldvt, lapack_complex_float* work,
                                lapack_int lwork, float* rwork );
lapack_int LAPACKE_zgesvd_work( int matrix_order, char jobu, char jobvt,
                                lapack_int m, lapack_int n,
                                lapack_complex_double* a, lapack_int lda,
                                double* s, lapack_complex_double* u,
                                lapack_int ldu, lapack_complex_double* vt,
                                lapack_int ldvt, lapack_complex_double* work,
                                lapack_int lwork, double* rwork );

lapack_int LAPACKE_sgesvj_work( int matrix_order, char joba, char jobu,
                                char jobv, lapack_int m, lapack_int n, float* a,
                                lapack_int lda, float* sva, lapack_int mv,
                                float* v, lapack_int ldv, float* work,
                                lapack_int lwork );
lapack_int LAPACKE_dgesvj_work( int matrix_order, char joba, char jobu,
                                char jobv, lapack_int m, lapack_int n,
                                double* a, lapack_int lda, double* sva,
                                lapack_int mv, double* v, lapack_int ldv,
                                double* work, lapack_int lwork );

lapack_int LAPACKE_sgesvx_work( int matrix_order, char fact, char trans,
                                lapack_int n, lapack_int nrhs, float* a,
                                lapack_int lda, float* af, lapack_int ldaf,
                                lapack_int* ipiv, char* equed, float* r,
                                float* c, float* b, lapack_int ldb, float* x,
                                lapack_int ldx, float* rcond, float* ferr,
                                float* berr, float* work, lapack_int* iwork );
lapack_int LAPACKE_dgesvx_work( int matrix_order, char fact, char trans,
                                lapack_int n, lapack_int nrhs, double* a,
                                lapack_int lda, double* af, lapack_int ldaf,
                                lapack_int* ipiv, char* equed, double* r,
                                double* c, double* b, lapack_int ldb, double* x,
                                lapack_int ldx, double* rcond, double* ferr,
                                double* berr, double* work, lapack_int* iwork );
lapack_int LAPACKE_cgesvx_work( int matrix_order, char fact, char trans,
                                lapack_int n, lapack_int nrhs,
                                lapack_complex_float* a, lapack_int lda,
                                lapack_complex_float* af, lapack_int ldaf,
                                lapack_int* ipiv, char* equed, float* r,
                                float* c, lapack_complex_float* b,
                                lapack_int ldb, lapack_complex_float* x,
                                lapack_int ldx, float* rcond, float* ferr,
                                float* berr, lapack_complex_float* work,
                                float* rwork );
lapack_int LAPACKE_zgesvx_work( int matrix_order, char fact, char trans,
                                lapack_int n, lapack_int nrhs,
                                lapack_complex_double* a, lapack_int lda,
                                lapack_complex_double* af, lapack_int ldaf,
                                lapack_int* ipiv, char* equed, double* r,
                                double* c, lapack_complex_double* b,
                                lapack_int ldb, lapack_complex_double* x,
                                lapack_int ldx, double* rcond, double* ferr,
                                double* berr, lapack_complex_double* work,
                                double* rwork );

lapack_int LAPACKE_sgesvxx_work( int matrix_order, char fact, char trans,
                                 lapack_int n, lapack_int nrhs, float* a,
                                 lapack_int lda, float* af, lapack_int ldaf,
                                 lapack_int* ipiv, char* equed, float* r,
                                 float* c, float* b, lapack_int ldb, float* x,
                                 lapack_int ldx, float* rcond, float* rpvgrw,
                                 float* berr, lapack_int n_err_bnds,
                                 float* err_bnds_norm, float* err_bnds_comp,
                                 lapack_int nparams, float* params, float* work,
                                 lapack_int* iwork );
lapack_int LAPACKE_dgesvxx_work( int matrix_order, char fact, char trans,
                                 lapack_int n, lapack_int nrhs, double* a,
                                 lapack_int lda, double* af, lapack_int ldaf,
                                 lapack_int* ipiv, char* equed, double* r,
                                 double* c, double* b, lapack_int ldb,
                                 double* x, lapack_int ldx, double* rcond,
                                 double* rpvgrw, double* berr,
                                 lapack_int n_err_bnds, double* err_bnds_norm,
                                 double* err_bnds_comp, lapack_int nparams,
                                 double* params, double* work,
                                 lapack_int* iwork );
lapack_int LAPACKE_cgesvxx_work( int matrix_order, char fact, char trans,
                                 lapack_int n, lapack_int nrhs,
                                 lapack_complex_float* a, lapack_int lda,
                                 lapack_complex_float* af, lapack_int ldaf,
                                 lapack_int* ipiv, char* equed, float* r,
                                 float* c, lapack_complex_float* b,
                                 lapack_int ldb, lapack_complex_float* x,
                                 lapack_int ldx, float* rcond, float* rpvgrw,
                                 float* berr, lapack_int n_err_bnds,
                                 float* err_bnds_norm, float* err_bnds_comp,
                                 lapack_int nparams, float* params,
                                 lapack_complex_float* work, float* rwork );
lapack_int LAPACKE_zgesvxx_work( int matrix_order, char fact, char trans,
                                 lapack_int n, lapack_int nrhs,
                                 lapack_complex_double* a, lapack_int lda,
                                 lapack_complex_double* af, lapack_int ldaf,
                                 lapack_int* ipiv, char* equed, double* r,
                                 double* c, lapack_complex_double* b,
                                 lapack_int ldb, lapack_complex_double* x,
                                 lapack_int ldx, double* rcond, double* rpvgrw,
                                 double* berr, lapack_int n_err_bnds,
                                 double* err_bnds_norm, double* err_bnds_comp,
                                 lapack_int nparams, double* params,
                                 lapack_complex_double* work, double* rwork );

lapack_int LAPACKE_sgetrf_work( int matrix_order, lapack_int m, lapack_int n,
                                float* a, lapack_int lda, lapack_int* ipiv );
lapack_int LAPACKE_dgetrf_work( int matrix_order, lapack_int m, lapack_int n,
                                double* a, lapack_int lda, lapack_int* ipiv );
lapack_int LAPACKE_cgetrf_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_complex_float* a, lapack_int lda,
                                lapack_int* ipiv );
lapack_int LAPACKE_zgetrf_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_complex_double* a, lapack_int lda,
                                lapack_int* ipiv );

lapack_int LAPACKE_sgetri_work( int matrix_order, lapack_int n, float* a,
                                lapack_int lda, const lapack_int* ipiv,
                                float* work, lapack_int lwork );
lapack_int LAPACKE_dgetri_work( int matrix_order, lapack_int n, double* a,
                                lapack_int lda, const lapack_int* ipiv,
                                double* work, lapack_int lwork );
lapack_int LAPACKE_cgetri_work( int matrix_order, lapack_int n,
                                lapack_complex_float* a, lapack_int lda,
                                const lapack_int* ipiv,
                                lapack_complex_float* work, lapack_int lwork );
lapack_int LAPACKE_zgetri_work( int matrix_order, lapack_int n,
                                lapack_complex_double* a, lapack_int lda,
                                const lapack_int* ipiv,
                                lapack_complex_double* work, lapack_int lwork );

lapack_int LAPACKE_sgetrs_work( int matrix_order, char trans, lapack_int n,
                                lapack_int nrhs, const float* a, lapack_int lda,
                                const lapack_int* ipiv, float* b,
                                lapack_int ldb );
lapack_int LAPACKE_dgetrs_work( int matrix_order, char trans, lapack_int n,
                                lapack_int nrhs, const double* a,
                                lapack_int lda, const lapack_int* ipiv,
                                double* b, lapack_int ldb );
lapack_int LAPACKE_cgetrs_work( int matrix_order, char trans, lapack_int n,
                                lapack_int nrhs, const lapack_complex_float* a,
                                lapack_int lda, const lapack_int* ipiv,
                                lapack_complex_float* b, lapack_int ldb );
lapack_int LAPACKE_zgetrs_work( int matrix_order, char trans, lapack_int n,
                                lapack_int nrhs, const lapack_complex_double* a,
                                lapack_int lda, const lapack_int* ipiv,
                                lapack_complex_double* b, lapack_int ldb );

lapack_int LAPACKE_sggbak_work( int matrix_order, char job, char side,
                                lapack_int n, lapack_int ilo, lapack_int ihi,
                                const float* lscale, const float* rscale,
                                lapack_int m, float* v, lapack_int ldv );
lapack_int LAPACKE_dggbak_work( int matrix_order, char job, char side,
                                lapack_int n, lapack_int ilo, lapack_int ihi,
                                const double* lscale, const double* rscale,
                                lapack_int m, double* v, lapack_int ldv );
lapack_int LAPACKE_cggbak_work( int matrix_order, char job, char side,
                                lapack_int n, lapack_int ilo, lapack_int ihi,
                                const float* lscale, const float* rscale,
                                lapack_int m, lapack_complex_float* v,
                                lapack_int ldv );
lapack_int LAPACKE_zggbak_work( int matrix_order, char job, char side,
                                lapack_int n, lapack_int ilo, lapack_int ihi,
                                const double* lscale, const double* rscale,
                                lapack_int m, lapack_complex_double* v,
                                lapack_int ldv );

lapack_int LAPACKE_sggbal_work( int matrix_order, char job, lapack_int n,
                                float* a, lapack_int lda, float* b,
                                lapack_int ldb, lapack_int* ilo,
                                lapack_int* ihi, float* lscale, float* rscale,
                                float* work );
lapack_int LAPACKE_dggbal_work( int matrix_order, char job, lapack_int n,
                                double* a, lapack_int lda, double* b,
                                lapack_int ldb, lapack_int* ilo,
                                lapack_int* ihi, double* lscale, double* rscale,
                                double* work );
lapack_int LAPACKE_cggbal_work( int matrix_order, char job, lapack_int n,
                                lapack_complex_float* a, lapack_int lda,
                                lapack_complex_float* b, lapack_int ldb,
                                lapack_int* ilo, lapack_int* ihi, float* lscale,
                                float* rscale, float* work );
lapack_int LAPACKE_zggbal_work( int matrix_order, char job, lapack_int n,
                                lapack_complex_double* a, lapack_int lda,
                                lapack_complex_double* b, lapack_int ldb,
                                lapack_int* ilo, lapack_int* ihi,
                                double* lscale, double* rscale, double* work );

lapack_int LAPACKE_sgges_work( int matrix_order, char jobvsl, char jobvsr,
                               char sort, LAPACK_S_SELECT3 selctg, lapack_int n,
                               float* a, lapack_int lda, float* b,
                               lapack_int ldb, lapack_int* sdim, float* alphar,
                               float* alphai, float* beta, float* vsl,
                               lapack_int ldvsl, float* vsr, lapack_int ldvsr,
                               float* work, lapack_int lwork,
                               lapack_logical* bwork );
lapack_int LAPACKE_dgges_work( int matrix_order, char jobvsl, char jobvsr,
                               char sort, LAPACK_D_SELECT3 selctg, lapack_int n,
                               double* a, lapack_int lda, double* b,
                               lapack_int ldb, lapack_int* sdim, double* alphar,
                               double* alphai, double* beta, double* vsl,
                               lapack_int ldvsl, double* vsr, lapack_int ldvsr,
                               double* work, lapack_int lwork,
                               lapack_logical* bwork );
lapack_int LAPACKE_cgges_work( int matrix_order, char jobvsl, char jobvsr,
                               char sort, LAPACK_C_SELECT2 selctg, lapack_int n,
                               lapack_complex_float* a, lapack_int lda,
                               lapack_complex_float* b, lapack_int ldb,
                               lapack_int* sdim, lapack_complex_float* alpha,
                               lapack_complex_float* beta,
                               lapack_complex_float* vsl, lapack_int ldvsl,
                               lapack_complex_float* vsr, lapack_int ldvsr,
                               lapack_complex_float* work, lapack_int lwork,
                               float* rwork, lapack_logical* bwork );
lapack_int LAPACKE_zgges_work( int matrix_order, char jobvsl, char jobvsr,
                               char sort, LAPACK_Z_SELECT2 selctg, lapack_int n,
                               lapack_complex_double* a, lapack_int lda,
                               lapack_complex_double* b, lapack_int ldb,
                               lapack_int* sdim, lapack_complex_double* alpha,
                               lapack_complex_double* beta,
                               lapack_complex_double* vsl, lapack_int ldvsl,
                               lapack_complex_double* vsr, lapack_int ldvsr,
                               lapack_complex_double* work, lapack_int lwork,
                               double* rwork, lapack_logical* bwork );

lapack_int LAPACKE_sggesx_work( int matrix_order, char jobvsl, char jobvsr,
                                char sort, LAPACK_S_SELECT3 selctg, char sense,
                                lapack_int n, float* a, lapack_int lda,
                                float* b, lapack_int ldb, lapack_int* sdim,
                                float* alphar, float* alphai, float* beta,
                                float* vsl, lapack_int ldvsl, float* vsr,
                                lapack_int ldvsr, float* rconde, float* rcondv,
                                float* work, lapack_int lwork,
                                lapack_int* iwork, lapack_int liwork,
                                lapack_logical* bwork );
lapack_int LAPACKE_dggesx_work( int matrix_order, char jobvsl, char jobvsr,
                                char sort, LAPACK_D_SELECT3 selctg, char sense,
                                lapack_int n, double* a, lapack_int lda,
                                double* b, lapack_int ldb, lapack_int* sdim,
                                double* alphar, double* alphai, double* beta,
                                double* vsl, lapack_int ldvsl, double* vsr,
                                lapack_int ldvsr, double* rconde,
                                double* rcondv, double* work, lapack_int lwork,
                                lapack_int* iwork, lapack_int liwork,
                                lapack_logical* bwork );
lapack_int LAPACKE_cggesx_work( int matrix_order, char jobvsl, char jobvsr,
                                char sort, LAPACK_C_SELECT2 selctg, char sense,
                                lapack_int n, lapack_complex_float* a,
                                lapack_int lda, lapack_complex_float* b,
                                lapack_int ldb, lapack_int* sdim,
                                lapack_complex_float* alpha,
                                lapack_complex_float* beta,
                                lapack_complex_float* vsl, lapack_int ldvsl,
                                lapack_complex_float* vsr, lapack_int ldvsr,
                                float* rconde, float* rcondv,
                                lapack_complex_float* work, lapack_int lwork,
                                float* rwork, lapack_int* iwork,
                                lapack_int liwork, lapack_logical* bwork );
lapack_int LAPACKE_zggesx_work( int matrix_order, char jobvsl, char jobvsr,
                                char sort, LAPACK_Z_SELECT2 selctg, char sense,
                                lapack_int n, lapack_complex_double* a,
                                lapack_int lda, lapack_complex_double* b,
                                lapack_int ldb, lapack_int* sdim,
                                lapack_complex_double* alpha,
                                lapack_complex_double* beta,
                                lapack_complex_double* vsl, lapack_int ldvsl,
                                lapack_complex_double* vsr, lapack_int ldvsr,
                                double* rconde, double* rcondv,
                                lapack_complex_double* work, lapack_int lwork,
                                double* rwork, lapack_int* iwork,
                                lapack_int liwork, lapack_logical* bwork );

lapack_int LAPACKE_sggev_work( int matrix_order, char jobvl, char jobvr,
                               lapack_int n, float* a, lapack_int lda, float* b,
                               lapack_int ldb, float* alphar, float* alphai,
                               float* beta, float* vl, lapack_int ldvl,
                               float* vr, lapack_int ldvr, float* work,
                               lapack_int lwork );
lapack_int LAPACKE_dggev_work( int matrix_order, char jobvl, char jobvr,
                               lapack_int n, double* a, lapack_int lda,
                               double* b, lapack_int ldb, double* alphar,
                               double* alphai, double* beta, double* vl,
                               lapack_int ldvl, double* vr, lapack_int ldvr,
                               double* work, lapack_int lwork );
lapack_int LAPACKE_cggev_work( int matrix_order, char jobvl, char jobvr,
                               lapack_int n, lapack_complex_float* a,
                               lapack_int lda, lapack_complex_float* b,
                               lapack_int ldb, lapack_complex_float* alpha,
                               lapack_complex_float* beta,
                               lapack_complex_float* vl, lapack_int ldvl,
                               lapack_complex_float* vr, lapack_int ldvr,
                               lapack_complex_float* work, lapack_int lwork,
                               float* rwork );
lapack_int LAPACKE_zggev_work( int matrix_order, char jobvl, char jobvr,
                               lapack_int n, lapack_complex_double* a,
                               lapack_int lda, lapack_complex_double* b,
                               lapack_int ldb, lapack_complex_double* alpha,
                               lapack_complex_double* beta,
                               lapack_complex_double* vl, lapack_int ldvl,
                               lapack_complex_double* vr, lapack_int ldvr,
                               lapack_complex_double* work, lapack_int lwork,
                               double* rwork );

lapack_int LAPACKE_sggevx_work( int matrix_order, char balanc, char jobvl,
                                char jobvr, char sense, lapack_int n, float* a,
                                lapack_int lda, float* b, lapack_int ldb,
                                float* alphar, float* alphai, float* beta,
                                float* vl, lapack_int ldvl, float* vr,
                                lapack_int ldvr, lapack_int* ilo,
                                lapack_int* ihi, float* lscale, float* rscale,
                                float* abnrm, float* bbnrm, float* rconde,
                                float* rcondv, float* work, lapack_int lwork,
                                lapack_int* iwork, lapack_logical* bwork );
lapack_int LAPACKE_dggevx_work( int matrix_order, char balanc, char jobvl,
                                char jobvr, char sense, lapack_int n, double* a,
                                lapack_int lda, double* b, lapack_int ldb,
                                double* alphar, double* alphai, double* beta,
                                double* vl, lapack_int ldvl, double* vr,
                                lapack_int ldvr, lapack_int* ilo,
                                lapack_int* ihi, double* lscale, double* rscale,
                                double* abnrm, double* bbnrm, double* rconde,
                                double* rcondv, double* work, lapack_int lwork,
                                lapack_int* iwork, lapack_logical* bwork );
lapack_int LAPACKE_cggevx_work( int matrix_order, char balanc, char jobvl,
                                char jobvr, char sense, lapack_int n,
                                lapack_complex_float* a, lapack_int lda,
                                lapack_complex_float* b, lapack_int ldb,
                                lapack_complex_float* alpha,
                                lapack_complex_float* beta,
                                lapack_complex_float* vl, lapack_int ldvl,
                                lapack_complex_float* vr, lapack_int ldvr,
                                lapack_int* ilo, lapack_int* ihi, float* lscale,
                                float* rscale, float* abnrm, float* bbnrm,
                                float* rconde, float* rcondv,
                                lapack_complex_float* work, lapack_int lwork,
                                float* rwork, lapack_int* iwork,
                                lapack_logical* bwork );
lapack_int LAPACKE_zggevx_work( int matrix_order, char balanc, char jobvl,
                                char jobvr, char sense, lapack_int n,
                                lapack_complex_double* a, lapack_int lda,
                                lapack_complex_double* b, lapack_int ldb,
                                lapack_complex_double* alpha,
                                lapack_complex_double* beta,
                                lapack_complex_double* vl, lapack_int ldvl,
                                lapack_complex_double* vr, lapack_int ldvr,
                                lapack_int* ilo, lapack_int* ihi,
                                double* lscale, double* rscale, double* abnrm,
                                double* bbnrm, double* rconde, double* rcondv,
                                lapack_complex_double* work, lapack_int lwork,
                                double* rwork, lapack_int* iwork,
                                lapack_logical* bwork );

lapack_int LAPACKE_sggglm_work( int matrix_order, lapack_int n, lapack_int m,
                                lapack_int p, float* a, lapack_int lda,
                                float* b, lapack_int ldb, float* d, float* x,
                                float* y, float* work, lapack_int lwork );
lapack_int LAPACKE_dggglm_work( int matrix_order, lapack_int n, lapack_int m,
                                lapack_int p, double* a, lapack_int lda,
                                double* b, lapack_int ldb, double* d, double* x,
                                double* y, double* work, lapack_int lwork );
lapack_int LAPACKE_cggglm_work( int matrix_order, lapack_int n, lapack_int m,
                                lapack_int p, lapack_complex_float* a,
                                lapack_int lda, lapack_complex_float* b,
                                lapack_int ldb, lapack_complex_float* d,
                                lapack_complex_float* x,
                                lapack_complex_float* y,
                                lapack_complex_float* work, lapack_int lwork );
lapack_int LAPACKE_zggglm_work( int matrix_order, lapack_int n, lapack_int m,
                                lapack_int p, lapack_complex_double* a,
                                lapack_int lda, lapack_complex_double* b,
                                lapack_int ldb, lapack_complex_double* d,
                                lapack_complex_double* x,
                                lapack_complex_double* y,
                                lapack_complex_double* work, lapack_int lwork );

lapack_int LAPACKE_sgghrd_work( int matrix_order, char compq, char compz,
                                lapack_int n, lapack_int ilo, lapack_int ihi,
                                float* a, lapack_int lda, float* b,
                                lapack_int ldb, float* q, lapack_int ldq,
                                float* z, lapack_int ldz );
lapack_int LAPACKE_dgghrd_work( int matrix_order, char compq, char compz,
                                lapack_int n, lapack_int ilo, lapack_int ihi,
                                double* a, lapack_int lda, double* b,
                                lapack_int ldb, double* q, lapack_int ldq,
                                double* z, lapack_int ldz );
lapack_int LAPACKE_cgghrd_work( int matrix_order, char compq, char compz,
                                lapack_int n, lapack_int ilo, lapack_int ihi,
                                lapack_complex_float* a, lapack_int lda,
                                lapack_complex_float* b, lapack_int ldb,
                                lapack_complex_float* q, lapack_int ldq,
                                lapack_complex_float* z, lapack_int ldz );
lapack_int LAPACKE_zgghrd_work( int matrix_order, char compq, char compz,
                                lapack_int n, lapack_int ilo, lapack_int ihi,
                                lapack_complex_double* a, lapack_int lda,
                                lapack_complex_double* b, lapack_int ldb,
                                lapack_complex_double* q, lapack_int ldq,
                                lapack_complex_double* z, lapack_int ldz );

lapack_int LAPACKE_sgglse_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_int p, float* a, lapack_int lda,
                                float* b, lapack_int ldb, float* c, float* d,
                                float* x, float* work, lapack_int lwork );
lapack_int LAPACKE_dgglse_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_int p, double* a, lapack_int lda,
                                double* b, lapack_int ldb, double* c, double* d,
                                double* x, double* work, lapack_int lwork );
lapack_int LAPACKE_cgglse_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_int p, lapack_complex_float* a,
                                lapack_int lda, lapack_complex_float* b,
                                lapack_int ldb, lapack_complex_float* c,
                                lapack_complex_float* d,
                                lapack_complex_float* x,
                                lapack_complex_float* work, lapack_int lwork );
lapack_int LAPACKE_zgglse_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_int p, lapack_complex_double* a,
                                lapack_int lda, lapack_complex_double* b,
                                lapack_int ldb, lapack_complex_double* c,
                                lapack_complex_double* d,
                                lapack_complex_double* x,
                                lapack_complex_double* work, lapack_int lwork );

lapack_int LAPACKE_sggqrf_work( int matrix_order, lapack_int n, lapack_int m,
                                lapack_int p, float* a, lapack_int lda,
                                float* taua, float* b, lapack_int ldb,
                                float* taub, float* work, lapack_int lwork );
lapack_int LAPACKE_dggqrf_work( int matrix_order, lapack_int n, lapack_int m,
                                lapack_int p, double* a, lapack_int lda,
                                double* taua, double* b, lapack_int ldb,
                                double* taub, double* work, lapack_int lwork );
lapack_int LAPACKE_cggqrf_work( int matrix_order, lapack_int n, lapack_int m,
                                lapack_int p, lapack_complex_float* a,
                                lapack_int lda, lapack_complex_float* taua,
                                lapack_complex_float* b, lapack_int ldb,
                                lapack_complex_float* taub,
                                lapack_complex_float* work, lapack_int lwork );
lapack_int LAPACKE_zggqrf_work( int matrix_order, lapack_int n, lapack_int m,
                                lapack_int p, lapack_complex_double* a,
                                lapack_int lda, lapack_complex_double* taua,
                                lapack_complex_double* b, lapack_int ldb,
                                lapack_complex_double* taub,
                                lapack_complex_double* work, lapack_int lwork );

lapack_int LAPACKE_sggrqf_work( int matrix_order, lapack_int m, lapack_int p,
                                lapack_int n, float* a, lapack_int lda,
                                float* taua, float* b, lapack_int ldb,
                                float* taub, float* work, lapack_int lwork );
lapack_int LAPACKE_dggrqf_work( int matrix_order, lapack_int m, lapack_int p,
                                lapack_int n, double* a, lapack_int lda,
                                double* taua, double* b, lapack_int ldb,
                                double* taub, double* work, lapack_int lwork );
lapack_int LAPACKE_cggrqf_work( int matrix_order, lapack_int m, lapack_int p,
                                lapack_int n, lapack_complex_float* a,
                                lapack_int lda, lapack_complex_float* taua,
                                lapack_complex_float* b, lapack_int ldb,
                                lapack_complex_float* taub,
                                lapack_complex_float* work, lapack_int lwork );
lapack_int LAPACKE_zggrqf_work( int matrix_order, lapack_int m, lapack_int p,
                                lapack_int n, lapack_complex_double* a,
                                lapack_int lda, lapack_complex_double* taua,
                                lapack_complex_double* b, lapack_int ldb,
                                lapack_complex_double* taub,
                                lapack_complex_double* work, lapack_int lwork );

lapack_int LAPACKE_sggsvd_work( int matrix_order, char jobu, char jobv,
                                char jobq, lapack_int m, lapack_int n,
                                lapack_int p, lapack_int* k, lapack_int* l,
                                float* a, lapack_int lda, float* b,
                                lapack_int ldb, float* alpha, float* beta,
                                float* u, lapack_int ldu, float* v,
                                lapack_int ldv, float* q, lapack_int ldq,
                                float* work, lapack_int* iwork );
lapack_int LAPACKE_dggsvd_work( int matrix_order, char jobu, char jobv,
                                char jobq, lapack_int m, lapack_int n,
                                lapack_int p, lapack_int* k, lapack_int* l,
                                double* a, lapack_int lda, double* b,
                                lapack_int ldb, double* alpha, double* beta,
                                double* u, lapack_int ldu, double* v,
                                lapack_int ldv, double* q, lapack_int ldq,
                                double* work, lapack_int* iwork );
lapack_int LAPACKE_cggsvd_work( int matrix_order, char jobu, char jobv,
                                char jobq, lapack_int m, lapack_int n,
                                lapack_int p, lapack_int* k, lapack_int* l,
                                lapack_complex_float* a, lapack_int lda,
                                lapack_complex_float* b, lapack_int ldb,
                                float* alpha, float* beta,
                                lapack_complex_float* u, lapack_int ldu,
                                lapack_complex_float* v, lapack_int ldv,
                                lapack_complex_float* q, lapack_int ldq,
                                lapack_complex_float* work, float* rwork,
                                lapack_int* iwork );
lapack_int LAPACKE_zggsvd_work( int matrix_order, char jobu, char jobv,
                                char jobq, lapack_int m, lapack_int n,
                                lapack_int p, lapack_int* k, lapack_int* l,
                                lapack_complex_double* a, lapack_int lda,
                                lapack_complex_double* b, lapack_int ldb,
                                double* alpha, double* beta,
                                lapack_complex_double* u, lapack_int ldu,
                                lapack_complex_double* v, lapack_int ldv,
                                lapack_complex_double* q, lapack_int ldq,
                                lapack_complex_double* work, double* rwork,
                                lapack_int* iwork );

lapack_int LAPACKE_sggsvp_work( int matrix_order, char jobu, char jobv,
                                char jobq, lapack_int m, lapack_int p,
                                lapack_int n, float* a, lapack_int lda,
                                float* b, lapack_int ldb, float tola,
                                float tolb, lapack_int* k, lapack_int* l,
                                float* u, lapack_int ldu, float* v,
                                lapack_int ldv, float* q, lapack_int ldq,
                                lapack_int* iwork, float* tau, float* work );
lapack_int LAPACKE_dggsvp_work( int matrix_order, char jobu, char jobv,
                                char jobq, lapack_int m, lapack_int p,
                                lapack_int n, double* a, lapack_int lda,
                                double* b, lapack_int ldb, double tola,
                                double tolb, lapack_int* k, lapack_int* l,
                                double* u, lapack_int ldu, double* v,
                                lapack_int ldv, double* q, lapack_int ldq,
                                lapack_int* iwork, double* tau, double* work );
lapack_int LAPACKE_cggsvp_work( int matrix_order, char jobu, char jobv,
                                char jobq, lapack_int m, lapack_int p,
                                lapack_int n, lapack_complex_float* a,
                                lapack_int lda, lapack_complex_float* b,
                                lapack_int ldb, float tola, float tolb,
                                lapack_int* k, lapack_int* l,
                                lapack_complex_float* u, lapack_int ldu,
                                lapack_complex_float* v, lapack_int ldv,
                                lapack_complex_float* q, lapack_int ldq,
                                lapack_int* iwork, float* rwork,
                                lapack_complex_float* tau,
                                lapack_complex_float* work );
lapack_int LAPACKE_zggsvp_work( int matrix_order, char jobu, char jobv,
                                char jobq, lapack_int m, lapack_int p,
                                lapack_int n, lapack_complex_double* a,
                                lapack_int lda, lapack_complex_double* b,
                                lapack_int ldb, double tola, double tolb,
                                lapack_int* k, lapack_int* l,
                                lapack_complex_double* u, lapack_int ldu,
                                lapack_complex_double* v, lapack_int ldv,
                                lapack_complex_double* q, lapack_int ldq,
                                lapack_int* iwork, double* rwork,
                                lapack_complex_double* tau,
                                lapack_complex_double* work );

lapack_int LAPACKE_sgtcon_work( char norm, lapack_int n, const float* dl,
                                const float* d, const float* du,
                                const float* du2, const lapack_int* ipiv,
                                float anorm, float* rcond, float* work,
                                lapack_int* iwork );
lapack_int LAPACKE_dgtcon_work( char norm, lapack_int n, const double* dl,
                                const double* d, const double* du,
                                const double* du2, const lapack_int* ipiv,
                                double anorm, double* rcond, double* work,
                                lapack_int* iwork );
lapack_int LAPACKE_cgtcon_work( char norm, lapack_int n,
                                const lapack_complex_float* dl,
                                const lapack_complex_float* d,
                                const lapack_complex_float* du,
                                const lapack_complex_float* du2,
                                const lapack_int* ipiv, float anorm,
                                float* rcond, lapack_complex_float* work );
lapack_int LAPACKE_zgtcon_work( char norm, lapack_int n,
                                const lapack_complex_double* dl,
                                const lapack_complex_double* d,
                                const lapack_complex_double* du,
                                const lapack_complex_double* du2,
                                const lapack_int* ipiv, double anorm,
                                double* rcond, lapack_complex_double* work );

lapack_int LAPACKE_sgtrfs_work( int matrix_order, char trans, lapack_int n,
                                lapack_int nrhs, const float* dl,
                                const float* d, const float* du,
                                const float* dlf, const float* df,
                                const float* duf, const float* du2,
                                const lapack_int* ipiv, const float* b,
                                lapack_int ldb, float* x, lapack_int ldx,
                                float* ferr, float* berr, float* work,
                                lapack_int* iwork );
lapack_int LAPACKE_dgtrfs_work( int matrix_order, char trans, lapack_int n,
                                lapack_int nrhs, const double* dl,
                                const double* d, const double* du,
                                const double* dlf, const double* df,
                                const double* duf, const double* du2,
                                const lapack_int* ipiv, const double* b,
                                lapack_int ldb, double* x, lapack_int ldx,
                                double* ferr, double* berr, double* work,
                                lapack_int* iwork );
lapack_int LAPACKE_cgtrfs_work( int matrix_order, char trans, lapack_int n,
                                lapack_int nrhs, const lapack_complex_float* dl,
                                const lapack_complex_float* d,
                                const lapack_complex_float* du,
                                const lapack_complex_float* dlf,
                                const lapack_complex_float* df,
                                const lapack_complex_float* duf,
                                const lapack_complex_float* du2,
                                const lapack_int* ipiv,
                                const lapack_complex_float* b, lapack_int ldb,
                                lapack_complex_float* x, lapack_int ldx,
                                float* ferr, float* berr,
                                lapack_complex_float* work, float* rwork );
lapack_int LAPACKE_zgtrfs_work( int matrix_order, char trans, lapack_int n,
                                lapack_int nrhs,
                                const lapack_complex_double* dl,
                                const lapack_complex_double* d,
                                const lapack_complex_double* du,
                                const lapack_complex_double* dlf,
                                const lapack_complex_double* df,
                                const lapack_complex_double* duf,
                                const lapack_complex_double* du2,
                                const lapack_int* ipiv,
                                const lapack_complex_double* b, lapack_int ldb,
                                lapack_complex_double* x, lapack_int ldx,
                                double* ferr, double* berr,
                                lapack_complex_double* work, double* rwork );

lapack_int LAPACKE_sgtsv_work( int matrix_order, lapack_int n, lapack_int nrhs,
                               float* dl, float* d, float* du, float* b,
                               lapack_int ldb );
lapack_int LAPACKE_dgtsv_work( int matrix_order, lapack_int n, lapack_int nrhs,
                               double* dl, double* d, double* du, double* b,
                               lapack_int ldb );
lapack_int LAPACKE_cgtsv_work( int matrix_order, lapack_int n, lapack_int nrhs,
                               lapack_complex_float* dl,
                               lapack_complex_float* d,
                               lapack_complex_float* du,
                               lapack_complex_float* b, lapack_int ldb );
lapack_int LAPACKE_zgtsv_work( int matrix_order, lapack_int n, lapack_int nrhs,
                               lapack_complex_double* dl,
                               lapack_complex_double* d,
                               lapack_complex_double* du,
                               lapack_complex_double* b, lapack_int ldb );

lapack_int LAPACKE_sgtsvx_work( int matrix_order, char fact, char trans,
                                lapack_int n, lapack_int nrhs, const float* dl,
                                const float* d, const float* du, float* dlf,
                                float* df, float* duf, float* du2,
                                lapack_int* ipiv, const float* b,
                                lapack_int ldb, float* x, lapack_int ldx,
                                float* rcond, float* ferr, float* berr,
                                float* work, lapack_int* iwork );
lapack_int LAPACKE_dgtsvx_work( int matrix_order, char fact, char trans,
                                lapack_int n, lapack_int nrhs, const double* dl,
                                const double* d, const double* du, double* dlf,
                                double* df, double* duf, double* du2,
                                lapack_int* ipiv, const double* b,
                                lapack_int ldb, double* x, lapack_int ldx,
                                double* rcond, double* ferr, double* berr,
                                double* work, lapack_int* iwork );
lapack_int LAPACKE_cgtsvx_work( int matrix_order, char fact, char trans,
                                lapack_int n, lapack_int nrhs,
                                const lapack_complex_float* dl,
                                const lapack_complex_float* d,
                                const lapack_complex_float* du,
                                lapack_complex_float* dlf,
                                lapack_complex_float* df,
                                lapack_complex_float* duf,
                                lapack_complex_float* du2, lapack_int* ipiv,
                                const lapack_complex_float* b, lapack_int ldb,
                                lapack_complex_float* x, lapack_int ldx,
                                float* rcond, float* ferr, float* berr,
                                lapack_complex_float* work, float* rwork );
lapack_int LAPACKE_zgtsvx_work( int matrix_order, char fact, char trans,
                                lapack_int n, lapack_int nrhs,
                                const lapack_complex_double* dl,
                                const lapack_complex_double* d,
                                const lapack_complex_double* du,
                                lapack_complex_double* dlf,
                                lapack_complex_double* df,
                                lapack_complex_double* duf,
                                lapack_complex_double* du2, lapack_int* ipiv,
                                const lapack_complex_double* b, lapack_int ldb,
                                lapack_complex_double* x, lapack_int ldx,
                                double* rcond, double* ferr, double* berr,
                                lapack_complex_double* work, double* rwork );

lapack_int LAPACKE_sgttrf_work( lapack_int n, float* dl, float* d, float* du,
                                float* du2, lapack_int* ipiv );
lapack_int LAPACKE_dgttrf_work( lapack_int n, double* dl, double* d, double* du,
                                double* du2, lapack_int* ipiv );
lapack_int LAPACKE_cgttrf_work( lapack_int n, lapack_complex_float* dl,
                                lapack_complex_float* d,
                                lapack_complex_float* du,
                                lapack_complex_float* du2, lapack_int* ipiv );
lapack_int LAPACKE_zgttrf_work( lapack_int n, lapack_complex_double* dl,
                                lapack_complex_double* d,
                                lapack_complex_double* du,
                                lapack_complex_double* du2, lapack_int* ipiv );

lapack_int LAPACKE_sgttrs_work( int matrix_order, char trans, lapack_int n,
                                lapack_int nrhs, const float* dl,
                                const float* d, const float* du,
                                const float* du2, const lapack_int* ipiv,
                                float* b, lapack_int ldb );
lapack_int LAPACKE_dgttrs_work( int matrix_order, char trans, lapack_int n,
                                lapack_int nrhs, const double* dl,
                                const double* d, const double* du,
                                const double* du2, const lapack_int* ipiv,
                                double* b, lapack_int ldb );
lapack_int LAPACKE_cgttrs_work( int matrix_order, char trans, lapack_int n,
                                lapack_int nrhs, const lapack_complex_float* dl,
                                const lapack_complex_float* d,
                                const lapack_complex_float* du,
                                const lapack_complex_float* du2,
                                const lapack_int* ipiv, lapack_complex_float* b,
                                lapack_int ldb );
lapack_int LAPACKE_zgttrs_work( int matrix_order, char trans, lapack_int n,
                                lapack_int nrhs,
                                const lapack_complex_double* dl,
                                const lapack_complex_double* d,
                                const lapack_complex_double* du,
                                const lapack_complex_double* du2,
                                const lapack_int* ipiv,
                                lapack_complex_double* b, lapack_int ldb );

lapack_int LAPACKE_chbev_work( int matrix_order, char jobz, char uplo,
                               lapack_int n, lapack_int kd,
                               lapack_complex_float* ab, lapack_int ldab,
                               float* w, lapack_complex_float* z,
                               lapack_int ldz, lapack_complex_float* work,
                               float* rwork );
lapack_int LAPACKE_zhbev_work( int matrix_order, char jobz, char uplo,
                               lapack_int n, lapack_int kd,
                               lapack_complex_double* ab, lapack_int ldab,
                               double* w, lapack_complex_double* z,
                               lapack_int ldz, lapack_complex_double* work,
                               double* rwork );

lapack_int LAPACKE_chbevd_work( int matrix_order, char jobz, char uplo,
                                lapack_int n, lapack_int kd,
                                lapack_complex_float* ab, lapack_int ldab,
                                float* w, lapack_complex_float* z,
                                lapack_int ldz, lapack_complex_float* work,
                                lapack_int lwork, float* rwork,
                                lapack_int lrwork, lapack_int* iwork,
                                lapack_int liwork );
lapack_int LAPACKE_zhbevd_work( int matrix_order, char jobz, char uplo,
                                lapack_int n, lapack_int kd,
                                lapack_complex_double* ab, lapack_int ldab,
                                double* w, lapack_complex_double* z,
                                lapack_int ldz, lapack_complex_double* work,
                                lapack_int lwork, double* rwork,
                                lapack_int lrwork, lapack_int* iwork,
                                lapack_int liwork );

lapack_int LAPACKE_chbevx_work( int matrix_order, char jobz, char range,
                                char uplo, lapack_int n, lapack_int kd,
                                lapack_complex_float* ab, lapack_int ldab,
                                lapack_complex_float* q, lapack_int ldq,
                                float vl, float vu, lapack_int il,
                                lapack_int iu, float abstol, lapack_int* m,
                                float* w, lapack_complex_float* z,
                                lapack_int ldz, lapack_complex_float* work,
                                float* rwork, lapack_int* iwork,
                                lapack_int* ifail );
lapack_int LAPACKE_zhbevx_work( int matrix_order, char jobz, char range,
                                char uplo, lapack_int n, lapack_int kd,
                                lapack_complex_double* ab, lapack_int ldab,
                                lapack_complex_double* q, lapack_int ldq,
                                double vl, double vu, lapack_int il,
                                lapack_int iu, double abstol, lapack_int* m,
                                double* w, lapack_complex_double* z,
                                lapack_int ldz, lapack_complex_double* work,
                                double* rwork, lapack_int* iwork,
                                lapack_int* ifail );

lapack_int LAPACKE_chbgst_work( int matrix_order, char vect, char uplo,
                                lapack_int n, lapack_int ka, lapack_int kb,
                                lapack_complex_float* ab, lapack_int ldab,
                                const lapack_complex_float* bb, lapack_int ldbb,
                                lapack_complex_float* x, lapack_int ldx,
                                lapack_complex_float* work, float* rwork );
lapack_int LAPACKE_zhbgst_work( int matrix_order, char vect, char uplo,
                                lapack_int n, lapack_int ka, lapack_int kb,
                                lapack_complex_double* ab, lapack_int ldab,
                                const lapack_complex_double* bb,
                                lapack_int ldbb, lapack_complex_double* x,
                                lapack_int ldx, lapack_complex_double* work,
                                double* rwork );

lapack_int LAPACKE_chbgv_work( int matrix_order, char jobz, char uplo,
                               lapack_int n, lapack_int ka, lapack_int kb,
                               lapack_complex_float* ab, lapack_int ldab,
                               lapack_complex_float* bb, lapack_int ldbb,
                               float* w, lapack_complex_float* z,
                               lapack_int ldz, lapack_complex_float* work,
                               float* rwork );
lapack_int LAPACKE_zhbgv_work( int matrix_order, char jobz, char uplo,
                               lapack_int n, lapack_int ka, lapack_int kb,
                               lapack_complex_double* ab, lapack_int ldab,
                               lapack_complex_double* bb, lapack_int ldbb,
                               double* w, lapack_complex_double* z,
                               lapack_int ldz, lapack_complex_double* work,
                               double* rwork );

lapack_int LAPACKE_chbgvd_work( int matrix_order, char jobz, char uplo,
                                lapack_int n, lapack_int ka, lapack_int kb,
                                lapack_complex_float* ab, lapack_int ldab,
                                lapack_complex_float* bb, lapack_int ldbb,
                                float* w, lapack_complex_float* z,
                                lapack_int ldz, lapack_complex_float* work,
                                lapack_int lwork, float* rwork,
                                lapack_int lrwork, lapack_int* iwork,
                                lapack_int liwork );
lapack_int LAPACKE_zhbgvd_work( int matrix_order, char jobz, char uplo,
                                lapack_int n, lapack_int ka, lapack_int kb,
                                lapack_complex_double* ab, lapack_int ldab,
                                lapack_complex_double* bb, lapack_int ldbb,
                                double* w, lapack_complex_double* z,
                                lapack_int ldz, lapack_complex_double* work,
                                lapack_int lwork, double* rwork,
                                lapack_int lrwork, lapack_int* iwork,
                                lapack_int liwork );

lapack_int LAPACKE_chbgvx_work( int matrix_order, char jobz, char range,
                                char uplo, lapack_int n, lapack_int ka,
                                lapack_int kb, lapack_complex_float* ab,
                                lapack_int ldab, lapack_complex_float* bb,
                                lapack_int ldbb, lapack_complex_float* q,
                                lapack_int ldq, float vl, float vu,
                                lapack_int il, lapack_int iu, float abstol,
                                lapack_int* m, float* w,
                                lapack_complex_float* z, lapack_int ldz,
                                lapack_complex_float* work, float* rwork,
                                lapack_int* iwork, lapack_int* ifail );
lapack_int LAPACKE_zhbgvx_work( int matrix_order, char jobz, char range,
                                char uplo, lapack_int n, lapack_int ka,
                                lapack_int kb, lapack_complex_double* ab,
                                lapack_int ldab, lapack_complex_double* bb,
                                lapack_int ldbb, lapack_complex_double* q,
                                lapack_int ldq, double vl, double vu,
                                lapack_int il, lapack_int iu, double abstol,
                                lapack_int* m, double* w,
                                lapack_complex_double* z, lapack_int ldz,
                                lapack_complex_double* work, double* rwork,
                                lapack_int* iwork, lapack_int* ifail );

lapack_int LAPACKE_chbtrd_work( int matrix_order, char vect, char uplo,
                                lapack_int n, lapack_int kd,
                                lapack_complex_float* ab, lapack_int ldab,
                                float* d, float* e, lapack_complex_float* q,
                                lapack_int ldq, lapack_complex_float* work );
lapack_int LAPACKE_zhbtrd_work( int matrix_order, char vect, char uplo,
                                lapack_int n, lapack_int kd,
                                lapack_complex_double* ab, lapack_int ldab,
                                double* d, double* e, lapack_complex_double* q,
                                lapack_int ldq, lapack_complex_double* work );

lapack_int LAPACKE_checon_work( int matrix_order, char uplo, lapack_int n,
                                const lapack_complex_float* a, lapack_int lda,
                                const lapack_int* ipiv, float anorm,
                                float* rcond, lapack_complex_float* work );
lapack_int LAPACKE_zhecon_work( int matrix_order, char uplo, lapack_int n,
                                const lapack_complex_double* a, lapack_int lda,
                                const lapack_int* ipiv, double anorm,
                                double* rcond, lapack_complex_double* work );

lapack_int LAPACKE_cheequb_work( int matrix_order, char uplo, lapack_int n,
                                 const lapack_complex_float* a, lapack_int lda,
                                 float* s, float* scond, float* amax,
                                 lapack_complex_float* work );
lapack_int LAPACKE_zheequb_work( int matrix_order, char uplo, lapack_int n,
                                 const lapack_complex_double* a, lapack_int lda,
                                 double* s, double* scond, double* amax,
                                 lapack_complex_double* work );

lapack_int LAPACKE_cheev_work( int matrix_order, char jobz, char uplo,
                               lapack_int n, lapack_complex_float* a,
                               lapack_int lda, float* w,
                               lapack_complex_float* work, lapack_int lwork,
                               float* rwork );
lapack_int LAPACKE_zheev_work( int matrix_order, char jobz, char uplo,
                               lapack_int n, lapack_complex_double* a,
                               lapack_int lda, double* w,
                               lapack_complex_double* work, lapack_int lwork,
                               double* rwork );

lapack_int LAPACKE_cheevd_work( int matrix_order, char jobz, char uplo,
                                lapack_int n, lapack_complex_float* a,
                                lapack_int lda, float* w,
                                lapack_complex_float* work, lapack_int lwork,
                                float* rwork, lapack_int lrwork,
                                lapack_int* iwork, lapack_int liwork );
lapack_int LAPACKE_zheevd_work( int matrix_order, char jobz, char uplo,
                                lapack_int n, lapack_complex_double* a,
                                lapack_int lda, double* w,
                                lapack_complex_double* work, lapack_int lwork,
                                double* rwork, lapack_int lrwork,
                                lapack_int* iwork, lapack_int liwork );

lapack_int LAPACKE_cheevr_work( int matrix_order, char jobz, char range,
                                char uplo, lapack_int n,
                                lapack_complex_float* a, lapack_int lda,
                                float vl, float vu, lapack_int il,
                                lapack_int iu, float abstol, lapack_int* m,
                                float* w, lapack_complex_float* z,
                                lapack_int ldz, lapack_int* isuppz,
                                lapack_complex_float* work, lapack_int lwork,
                                float* rwork, lapack_int lrwork,
                                lapack_int* iwork, lapack_int liwork );
lapack_int LAPACKE_zheevr_work( int matrix_order, char jobz, char range,
                                char uplo, lapack_int n,
                                lapack_complex_double* a, lapack_int lda,
                                double vl, double vu, lapack_int il,
                                lapack_int iu, double abstol, lapack_int* m,
                                double* w, lapack_complex_double* z,
                                lapack_int ldz, lapack_int* isuppz,
                                lapack_complex_double* work, lapack_int lwork,
                                double* rwork, lapack_int lrwork,
                                lapack_int* iwork, lapack_int liwork );

lapack_int LAPACKE_cheevx_work( int matrix_order, char jobz, char range,
                                char uplo, lapack_int n,
                                lapack_complex_float* a, lapack_int lda,
                                float vl, float vu, lapack_int il,
                                lapack_int iu, float abstol, lapack_int* m,
                                float* w, lapack_complex_float* z,
                                lapack_int ldz, lapack_complex_float* work,
                                lapack_int lwork, float* rwork,
                                lapack_int* iwork, lapack_int* ifail );
lapack_int LAPACKE_zheevx_work( int matrix_order, char jobz, char range,
                                char uplo, lapack_int n,
                                lapack_complex_double* a, lapack_int lda,
                                double vl, double vu, lapack_int il,
                                lapack_int iu, double abstol, lapack_int* m,
                                double* w, lapack_complex_double* z,
                                lapack_int ldz, lapack_complex_double* work,
                                lapack_int lwork, double* rwork,
                                lapack_int* iwork, lapack_int* ifail );

lapack_int LAPACKE_chegst_work( int matrix_order, lapack_int itype, char uplo,
                                lapack_int n, lapack_complex_float* a,
                                lapack_int lda, const lapack_complex_float* b,
                                lapack_int ldb );
lapack_int LAPACKE_zhegst_work( int matrix_order, lapack_int itype, char uplo,
                                lapack_int n, lapack_complex_double* a,
                                lapack_int lda, const lapack_complex_double* b,
                                lapack_int ldb );

lapack_int LAPACKE_chegv_work( int matrix_order, lapack_int itype, char jobz,
                               char uplo, lapack_int n, lapack_complex_float* a,
                               lapack_int lda, lapack_complex_float* b,
                               lapack_int ldb, float* w,
                               lapack_complex_float* work, lapack_int lwork,
                               float* rwork );
lapack_int LAPACKE_zhegv_work( int matrix_order, lapack_int itype, char jobz,
                               char uplo, lapack_int n,
                               lapack_complex_double* a, lapack_int lda,
                               lapack_complex_double* b, lapack_int ldb,
                               double* w, lapack_complex_double* work,
                               lapack_int lwork, double* rwork );

lapack_int LAPACKE_chegvd_work( int matrix_order, lapack_int itype, char jobz,
                                char uplo, lapack_int n,
                                lapack_complex_float* a, lapack_int lda,
                                lapack_complex_float* b, lapack_int ldb,
                                float* w, lapack_complex_float* work,
                                lapack_int lwork, float* rwork,
                                lapack_int lrwork, lapack_int* iwork,
                                lapack_int liwork );
lapack_int LAPACKE_zhegvd_work( int matrix_order, lapack_int itype, char jobz,
                                char uplo, lapack_int n,
                                lapack_complex_double* a, lapack_int lda,
                                lapack_complex_double* b, lapack_int ldb,
                                double* w, lapack_complex_double* work,
                                lapack_int lwork, double* rwork,
                                lapack_int lrwork, lapack_int* iwork,
                                lapack_int liwork );

lapack_int LAPACKE_chegvx_work( int matrix_order, lapack_int itype, char jobz,
                                char range, char uplo, lapack_int n,
                                lapack_complex_float* a, lapack_int lda,
                                lapack_complex_float* b, lapack_int ldb,
                                float vl, float vu, lapack_int il,
                                lapack_int iu, float abstol, lapack_int* m,
                                float* w, lapack_complex_float* z,
                                lapack_int ldz, lapack_complex_float* work,
                                lapack_int lwork, float* rwork,
                                lapack_int* iwork, lapack_int* ifail );
lapack_int LAPACKE_zhegvx_work( int matrix_order, lapack_int itype, char jobz,
                                char range, char uplo, lapack_int n,
                                lapack_complex_double* a, lapack_int lda,
                                lapack_complex_double* b, lapack_int ldb,
                                double vl, double vu, lapack_int il,
                                lapack_int iu, double abstol, lapack_int* m,
                                double* w, lapack_complex_double* z,
                                lapack_int ldz, lapack_complex_double* work,
                                lapack_int lwork, double* rwork,
                                lapack_int* iwork, lapack_int* ifail );

lapack_int LAPACKE_cherfs_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int nrhs, const lapack_complex_float* a,
                                lapack_int lda, const lapack_complex_float* af,
                                lapack_int ldaf, const lapack_int* ipiv,
                                const lapack_complex_float* b, lapack_int ldb,
                                lapack_complex_float* x, lapack_int ldx,
                                float* ferr, float* berr,
                                lapack_complex_float* work, float* rwork );
lapack_int LAPACKE_zherfs_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int nrhs, const lapack_complex_double* a,
                                lapack_int lda, const lapack_complex_double* af,
                                lapack_int ldaf, const lapack_int* ipiv,
                                const lapack_complex_double* b, lapack_int ldb,
                                lapack_complex_double* x, lapack_int ldx,
                                double* ferr, double* berr,
                                lapack_complex_double* work, double* rwork );

lapack_int LAPACKE_cherfsx_work( int matrix_order, char uplo, char equed,
                                 lapack_int n, lapack_int nrhs,
                                 const lapack_complex_float* a, lapack_int lda,
                                 const lapack_complex_float* af,
                                 lapack_int ldaf, const lapack_int* ipiv,
                                 const float* s, const lapack_complex_float* b,
                                 lapack_int ldb, lapack_complex_float* x,
                                 lapack_int ldx, float* rcond, float* berr,
                                 lapack_int n_err_bnds, float* err_bnds_norm,
                                 float* err_bnds_comp, lapack_int nparams,
                                 float* params, lapack_complex_float* work,
                                 float* rwork );
lapack_int LAPACKE_zherfsx_work( int matrix_order, char uplo, char equed,
                                 lapack_int n, lapack_int nrhs,
                                 const lapack_complex_double* a, lapack_int lda,
                                 const lapack_complex_double* af,
                                 lapack_int ldaf, const lapack_int* ipiv,
                                 const double* s,
                                 const lapack_complex_double* b, lapack_int ldb,
                                 lapack_complex_double* x, lapack_int ldx,
                                 double* rcond, double* berr,
                                 lapack_int n_err_bnds, double* err_bnds_norm,
                                 double* err_bnds_comp, lapack_int nparams,
                                 double* params, lapack_complex_double* work,
                                 double* rwork );

lapack_int LAPACKE_chesv_work( int matrix_order, char uplo, lapack_int n,
                               lapack_int nrhs, lapack_complex_float* a,
                               lapack_int lda, lapack_int* ipiv,
                               lapack_complex_float* b, lapack_int ldb,
                               lapack_complex_float* work, lapack_int lwork );
lapack_int LAPACKE_zhesv_work( int matrix_order, char uplo, lapack_int n,
                               lapack_int nrhs, lapack_complex_double* a,
                               lapack_int lda, lapack_int* ipiv,
                               lapack_complex_double* b, lapack_int ldb,
                               lapack_complex_double* work, lapack_int lwork );

lapack_int LAPACKE_chesvx_work( int matrix_order, char fact, char uplo,
                                lapack_int n, lapack_int nrhs,
                                const lapack_complex_float* a, lapack_int lda,
                                lapack_complex_float* af, lapack_int ldaf,
                                lapack_int* ipiv, const lapack_complex_float* b,
                                lapack_int ldb, lapack_complex_float* x,
                                lapack_int ldx, float* rcond, float* ferr,
                                float* berr, lapack_complex_float* work,
                                lapack_int lwork, float* rwork );
lapack_int LAPACKE_zhesvx_work( int matrix_order, char fact, char uplo,
                                lapack_int n, lapack_int nrhs,
                                const lapack_complex_double* a, lapack_int lda,
                                lapack_complex_double* af, lapack_int ldaf,
                                lapack_int* ipiv,
                                const lapack_complex_double* b, lapack_int ldb,
                                lapack_complex_double* x, lapack_int ldx,
                                double* rcond, double* ferr, double* berr,
                                lapack_complex_double* work, lapack_int lwork,
                                double* rwork );

lapack_int LAPACKE_chesvxx_work( int matrix_order, char fact, char uplo,
                                 lapack_int n, lapack_int nrhs,
                                 lapack_complex_float* a, lapack_int lda,
                                 lapack_complex_float* af, lapack_int ldaf,
                                 lapack_int* ipiv, char* equed, float* s,
                                 lapack_complex_float* b, lapack_int ldb,
                                 lapack_complex_float* x, lapack_int ldx,
                                 float* rcond, float* rpvgrw, float* berr,
                                 lapack_int n_err_bnds, float* err_bnds_norm,
                                 float* err_bnds_comp, lapack_int nparams,
                                 float* params, lapack_complex_float* work,
                                 float* rwork );
lapack_int LAPACKE_zhesvxx_work( int matrix_order, char fact, char uplo,
                                 lapack_int n, lapack_int nrhs,
                                 lapack_complex_double* a, lapack_int lda,
                                 lapack_complex_double* af, lapack_int ldaf,
                                 lapack_int* ipiv, char* equed, double* s,
                                 lapack_complex_double* b, lapack_int ldb,
                                 lapack_complex_double* x, lapack_int ldx,
                                 double* rcond, double* rpvgrw, double* berr,
                                 lapack_int n_err_bnds, double* err_bnds_norm,
                                 double* err_bnds_comp, lapack_int nparams,
                                 double* params, lapack_complex_double* work,
                                 double* rwork );

lapack_int LAPACKE_chetrd_work( int matrix_order, char uplo, lapack_int n,
                                lapack_complex_float* a, lapack_int lda,
                                float* d, float* e, lapack_complex_float* tau,
                                lapack_complex_float* work, lapack_int lwork );
lapack_int LAPACKE_zhetrd_work( int matrix_order, char uplo, lapack_int n,
                                lapack_complex_double* a, lapack_int lda,
                                double* d, double* e,
                                lapack_complex_double* tau,
                                lapack_complex_double* work, lapack_int lwork );

lapack_int LAPACKE_chetrf_work( int matrix_order, char uplo, lapack_int n,
                                lapack_complex_float* a, lapack_int lda,
                                lapack_int* ipiv, lapack_complex_float* work,
                                lapack_int lwork );
lapack_int LAPACKE_zhetrf_work( int matrix_order, char uplo, lapack_int n,
                                lapack_complex_double* a, lapack_int lda,
                                lapack_int* ipiv, lapack_complex_double* work,
                                lapack_int lwork );

lapack_int LAPACKE_chetri_work( int matrix_order, char uplo, lapack_int n,
                                lapack_complex_float* a, lapack_int lda,
                                const lapack_int* ipiv,
                                lapack_complex_float* work );
lapack_int LAPACKE_zhetri_work( int matrix_order, char uplo, lapack_int n,
                                lapack_complex_double* a, lapack_int lda,
                                const lapack_int* ipiv,
                                lapack_complex_double* work );

lapack_int LAPACKE_chetrs_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int nrhs, const lapack_complex_float* a,
                                lapack_int lda, const lapack_int* ipiv,
                                lapack_complex_float* b, lapack_int ldb );
lapack_int LAPACKE_zhetrs_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int nrhs, const lapack_complex_double* a,
                                lapack_int lda, const lapack_int* ipiv,
                                lapack_complex_double* b, lapack_int ldb );

lapack_int LAPACKE_chfrk_work( int matrix_order, char transr, char uplo,
                               char trans, lapack_int n, lapack_int k,
                               float alpha, const lapack_complex_float* a,
                               lapack_int lda, float beta,
                               lapack_complex_float* c );
lapack_int LAPACKE_zhfrk_work( int matrix_order, char transr, char uplo,
                               char trans, lapack_int n, lapack_int k,
                               double alpha, const lapack_complex_double* a,
                               lapack_int lda, double beta,
                               lapack_complex_double* c );

lapack_int LAPACKE_shgeqz_work( int matrix_order, char job, char compq,
                                char compz, lapack_int n, lapack_int ilo,
                                lapack_int ihi, float* h, lapack_int ldh,
                                float* t, lapack_int ldt, float* alphar,
                                float* alphai, float* beta, float* q,
                                lapack_int ldq, float* z, lapack_int ldz,
                                float* work, lapack_int lwork );
lapack_int LAPACKE_dhgeqz_work( int matrix_order, char job, char compq,
                                char compz, lapack_int n, lapack_int ilo,
                                lapack_int ihi, double* h, lapack_int ldh,
                                double* t, lapack_int ldt, double* alphar,
                                double* alphai, double* beta, double* q,
                                lapack_int ldq, double* z, lapack_int ldz,
                                double* work, lapack_int lwork );
lapack_int LAPACKE_chgeqz_work( int matrix_order, char job, char compq,
                                char compz, lapack_int n, lapack_int ilo,
                                lapack_int ihi, lapack_complex_float* h,
                                lapack_int ldh, lapack_complex_float* t,
                                lapack_int ldt, lapack_complex_float* alpha,
                                lapack_complex_float* beta,
                                lapack_complex_float* q, lapack_int ldq,
                                lapack_complex_float* z, lapack_int ldz,
                                lapack_complex_float* work, lapack_int lwork,
                                float* rwork );
lapack_int LAPACKE_zhgeqz_work( int matrix_order, char job, char compq,
                                char compz, lapack_int n, lapack_int ilo,
                                lapack_int ihi, lapack_complex_double* h,
                                lapack_int ldh, lapack_complex_double* t,
                                lapack_int ldt, lapack_complex_double* alpha,
                                lapack_complex_double* beta,
                                lapack_complex_double* q, lapack_int ldq,
                                lapack_complex_double* z, lapack_int ldz,
                                lapack_complex_double* work, lapack_int lwork,
                                double* rwork );

lapack_int LAPACKE_chpcon_work( int matrix_order, char uplo, lapack_int n,
                                const lapack_complex_float* ap,
                                const lapack_int* ipiv, float anorm,
                                float* rcond, lapack_complex_float* work );
lapack_int LAPACKE_zhpcon_work( int matrix_order, char uplo, lapack_int n,
                                const lapack_complex_double* ap,
                                const lapack_int* ipiv, double anorm,
                                double* rcond, lapack_complex_double* work );

lapack_int LAPACKE_chpev_work( int matrix_order, char jobz, char uplo,
                               lapack_int n, lapack_complex_float* ap, float* w,
                               lapack_complex_float* z, lapack_int ldz,
                               lapack_complex_float* work, float* rwork );
lapack_int LAPACKE_zhpev_work( int matrix_order, char jobz, char uplo,
                               lapack_int n, lapack_complex_double* ap,
                               double* w, lapack_complex_double* z,
                               lapack_int ldz, lapack_complex_double* work,
                               double* rwork );

lapack_int LAPACKE_chpevd_work( int matrix_order, char jobz, char uplo,
                                lapack_int n, lapack_complex_float* ap,
                                float* w, lapack_complex_float* z,
                                lapack_int ldz, lapack_complex_float* work,
                                lapack_int lwork, float* rwork,
                                lapack_int lrwork, lapack_int* iwork,
                                lapack_int liwork );
lapack_int LAPACKE_zhpevd_work( int matrix_order, char jobz, char uplo,
                                lapack_int n, lapack_complex_double* ap,
                                double* w, lapack_complex_double* z,
                                lapack_int ldz, lapack_complex_double* work,
                                lapack_int lwork, double* rwork,
                                lapack_int lrwork, lapack_int* iwork,
                                lapack_int liwork );

lapack_int LAPACKE_chpevx_work( int matrix_order, char jobz, char range,
                                char uplo, lapack_int n,
                                lapack_complex_float* ap, float vl, float vu,
                                lapack_int il, lapack_int iu, float abstol,
                                lapack_int* m, float* w,
                                lapack_complex_float* z, lapack_int ldz,
                                lapack_complex_float* work, float* rwork,
                                lapack_int* iwork, lapack_int* ifail );
lapack_int LAPACKE_zhpevx_work( int matrix_order, char jobz, char range,
                                char uplo, lapack_int n,
                                lapack_complex_double* ap, double vl, double vu,
                                lapack_int il, lapack_int iu, double abstol,
                                lapack_int* m, double* w,
                                lapack_complex_double* z, lapack_int ldz,
                                lapack_complex_double* work, double* rwork,
                                lapack_int* iwork, lapack_int* ifail );

lapack_int LAPACKE_chpgst_work( int matrix_order, lapack_int itype, char uplo,
                                lapack_int n, lapack_complex_float* ap,
                                const lapack_complex_float* bp );
lapack_int LAPACKE_zhpgst_work( int matrix_order, lapack_int itype, char uplo,
                                lapack_int n, lapack_complex_double* ap,
                                const lapack_complex_double* bp );

lapack_int LAPACKE_chpgv_work( int matrix_order, lapack_int itype, char jobz,
                               char uplo, lapack_int n,
                               lapack_complex_float* ap,
                               lapack_complex_float* bp, float* w,
                               lapack_complex_float* z, lapack_int ldz,
                               lapack_complex_float* work, float* rwork );
lapack_int LAPACKE_zhpgv_work( int matrix_order, lapack_int itype, char jobz,
                               char uplo, lapack_int n,
                               lapack_complex_double* ap,
                               lapack_complex_double* bp, double* w,
                               lapack_complex_double* z, lapack_int ldz,
                               lapack_complex_double* work, double* rwork );

lapack_int LAPACKE_chpgvd_work( int matrix_order, lapack_int itype, char jobz,
                                char uplo, lapack_int n,
                                lapack_complex_float* ap,
                                lapack_complex_float* bp, float* w,
                                lapack_complex_float* z, lapack_int ldz,
                                lapack_complex_float* work, lapack_int lwork,
                                float* rwork, lapack_int lrwork,
                                lapack_int* iwork, lapack_int liwork );
lapack_int LAPACKE_zhpgvd_work( int matrix_order, lapack_int itype, char jobz,
                                char uplo, lapack_int n,
                                lapack_complex_double* ap,
                                lapack_complex_double* bp, double* w,
                                lapack_complex_double* z, lapack_int ldz,
                                lapack_complex_double* work, lapack_int lwork,
                                double* rwork, lapack_int lrwork,
                                lapack_int* iwork, lapack_int liwork );

lapack_int LAPACKE_chpgvx_work( int matrix_order, lapack_int itype, char jobz,
                                char range, char uplo, lapack_int n,
                                lapack_complex_float* ap,
                                lapack_complex_float* bp, float vl, float vu,
                                lapack_int il, lapack_int iu, float abstol,
                                lapack_int* m, float* w,
                                lapack_complex_float* z, lapack_int ldz,
                                lapack_complex_float* work, float* rwork,
                                lapack_int* iwork, lapack_int* ifail );
lapack_int LAPACKE_zhpgvx_work( int matrix_order, lapack_int itype, char jobz,
                                char range, char uplo, lapack_int n,
                                lapack_complex_double* ap,
                                lapack_complex_double* bp, double vl, double vu,
                                lapack_int il, lapack_int iu, double abstol,
                                lapack_int* m, double* w,
                                lapack_complex_double* z, lapack_int ldz,
                                lapack_complex_double* work, double* rwork,
                                lapack_int* iwork, lapack_int* ifail );

lapack_int LAPACKE_chprfs_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int nrhs, const lapack_complex_float* ap,
                                const lapack_complex_float* afp,
                                const lapack_int* ipiv,
                                const lapack_complex_float* b, lapack_int ldb,
                                lapack_complex_float* x, lapack_int ldx,
                                float* ferr, float* berr,
                                lapack_complex_float* work, float* rwork );
lapack_int LAPACKE_zhprfs_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int nrhs,
                                const lapack_complex_double* ap,
                                const lapack_complex_double* afp,
                                const lapack_int* ipiv,
                                const lapack_complex_double* b, lapack_int ldb,
                                lapack_complex_double* x, lapack_int ldx,
                                double* ferr, double* berr,
                                lapack_complex_double* work, double* rwork );

lapack_int LAPACKE_chpsv_work( int matrix_order, char uplo, lapack_int n,
                               lapack_int nrhs, lapack_complex_float* ap,
                               lapack_int* ipiv, lapack_complex_float* b,
                               lapack_int ldb );
lapack_int LAPACKE_zhpsv_work( int matrix_order, char uplo, lapack_int n,
                               lapack_int nrhs, lapack_complex_double* ap,
                               lapack_int* ipiv, lapack_complex_double* b,
                               lapack_int ldb );

lapack_int LAPACKE_chpsvx_work( int matrix_order, char fact, char uplo,
                                lapack_int n, lapack_int nrhs,
                                const lapack_complex_float* ap,
                                lapack_complex_float* afp, lapack_int* ipiv,
                                const lapack_complex_float* b, lapack_int ldb,
                                lapack_complex_float* x, lapack_int ldx,
                                float* rcond, float* ferr, float* berr,
                                lapack_complex_float* work, float* rwork );
lapack_int LAPACKE_zhpsvx_work( int matrix_order, char fact, char uplo,
                                lapack_int n, lapack_int nrhs,
                                const lapack_complex_double* ap,
                                lapack_complex_double* afp, lapack_int* ipiv,
                                const lapack_complex_double* b, lapack_int ldb,
                                lapack_complex_double* x, lapack_int ldx,
                                double* rcond, double* ferr, double* berr,
                                lapack_complex_double* work, double* rwork );

lapack_int LAPACKE_chptrd_work( int matrix_order, char uplo, lapack_int n,
                                lapack_complex_float* ap, float* d, float* e,
                                lapack_complex_float* tau );
lapack_int LAPACKE_zhptrd_work( int matrix_order, char uplo, lapack_int n,
                                lapack_complex_double* ap, double* d, double* e,
                                lapack_complex_double* tau );

lapack_int LAPACKE_chptrf_work( int matrix_order, char uplo, lapack_int n,
                                lapack_complex_float* ap, lapack_int* ipiv );
lapack_int LAPACKE_zhptrf_work( int matrix_order, char uplo, lapack_int n,
                                lapack_complex_double* ap, lapack_int* ipiv );

lapack_int LAPACKE_chptri_work( int matrix_order, char uplo, lapack_int n,
                                lapack_complex_float* ap,
                                const lapack_int* ipiv,
                                lapack_complex_float* work );
lapack_int LAPACKE_zhptri_work( int matrix_order, char uplo, lapack_int n,
                                lapack_complex_double* ap,
                                const lapack_int* ipiv,
                                lapack_complex_double* work );

lapack_int LAPACKE_chptrs_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int nrhs, const lapack_complex_float* ap,
                                const lapack_int* ipiv, lapack_complex_float* b,
                                lapack_int ldb );
lapack_int LAPACKE_zhptrs_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int nrhs,
                                const lapack_complex_double* ap,
                                const lapack_int* ipiv,
                                lapack_complex_double* b, lapack_int ldb );

lapack_int LAPACKE_shsein_work( int matrix_order, char job, char eigsrc,
                                char initv, lapack_logical* select,
                                lapack_int n, const float* h, lapack_int ldh,
                                float* wr, const float* wi, float* vl,
                                lapack_int ldvl, float* vr, lapack_int ldvr,
                                lapack_int mm, lapack_int* m, float* work,
                                lapack_int* ifaill, lapack_int* ifailr );
lapack_int LAPACKE_dhsein_work( int matrix_order, char job, char eigsrc,
                                char initv, lapack_logical* select,
                                lapack_int n, const double* h, lapack_int ldh,
                                double* wr, const double* wi, double* vl,
                                lapack_int ldvl, double* vr, lapack_int ldvr,
                                lapack_int mm, lapack_int* m, double* work,
                                lapack_int* ifaill, lapack_int* ifailr );
lapack_int LAPACKE_chsein_work( int matrix_order, char job, char eigsrc,
                                char initv, const lapack_logical* select,
                                lapack_int n, const lapack_complex_float* h,
                                lapack_int ldh, lapack_complex_float* w,
                                lapack_complex_float* vl, lapack_int ldvl,
                                lapack_complex_float* vr, lapack_int ldvr,
                                lapack_int mm, lapack_int* m,
                                lapack_complex_float* work, float* rwork,
                                lapack_int* ifaill, lapack_int* ifailr );
lapack_int LAPACKE_zhsein_work( int matrix_order, char job, char eigsrc,
                                char initv, const lapack_logical* select,
                                lapack_int n, const lapack_complex_double* h,
                                lapack_int ldh, lapack_complex_double* w,
                                lapack_complex_double* vl, lapack_int ldvl,
                                lapack_complex_double* vr, lapack_int ldvr,
                                lapack_int mm, lapack_int* m,
                                lapack_complex_double* work, double* rwork,
                                lapack_int* ifaill, lapack_int* ifailr );

lapack_int LAPACKE_shseqr_work( int matrix_order, char job, char compz,
                                lapack_int n, lapack_int ilo, lapack_int ihi,
                                float* h, lapack_int ldh, float* wr, float* wi,
                                float* z, lapack_int ldz, float* work,
                                lapack_int lwork );
lapack_int LAPACKE_dhseqr_work( int matrix_order, char job, char compz,
                                lapack_int n, lapack_int ilo, lapack_int ihi,
                                double* h, lapack_int ldh, double* wr,
                                double* wi, double* z, lapack_int ldz,
                                double* work, lapack_int lwork );
lapack_int LAPACKE_chseqr_work( int matrix_order, char job, char compz,
                                lapack_int n, lapack_int ilo, lapack_int ihi,
                                lapack_complex_float* h, lapack_int ldh,
                                lapack_complex_float* w,
                                lapack_complex_float* z, lapack_int ldz,
                                lapack_complex_float* work, lapack_int lwork );
lapack_int LAPACKE_zhseqr_work( int matrix_order, char job, char compz,
                                lapack_int n, lapack_int ilo, lapack_int ihi,
                                lapack_complex_double* h, lapack_int ldh,
                                lapack_complex_double* w,
                                lapack_complex_double* z, lapack_int ldz,
                                lapack_complex_double* work, lapack_int lwork );

lapack_int LAPACKE_sopgtr_work( int matrix_order, char uplo, lapack_int n,
                                const float* ap, const float* tau, float* q,
                                lapack_int ldq, float* work );
lapack_int LAPACKE_dopgtr_work( int matrix_order, char uplo, lapack_int n,
                                const double* ap, const double* tau, double* q,
                                lapack_int ldq, double* work );

lapack_int LAPACKE_sopmtr_work( int matrix_order, char side, char uplo,
                                char trans, lapack_int m, lapack_int n,
                                const float* ap, const float* tau, float* c,
                                lapack_int ldc, float* work );
lapack_int LAPACKE_dopmtr_work( int matrix_order, char side, char uplo,
                                char trans, lapack_int m, lapack_int n,
                                const double* ap, const double* tau, double* c,
                                lapack_int ldc, double* work );

lapack_int LAPACKE_sorgbr_work( int matrix_order, char vect, lapack_int m,
                                lapack_int n, lapack_int k, float* a,
                                lapack_int lda, const float* tau, float* work,
                                lapack_int lwork );
lapack_int LAPACKE_dorgbr_work( int matrix_order, char vect, lapack_int m,
                                lapack_int n, lapack_int k, double* a,
                                lapack_int lda, const double* tau, double* work,
                                lapack_int lwork );

lapack_int LAPACKE_sorghr_work( int matrix_order, lapack_int n, lapack_int ilo,
                                lapack_int ihi, float* a, lapack_int lda,
                                const float* tau, float* work,
                                lapack_int lwork );
lapack_int LAPACKE_dorghr_work( int matrix_order, lapack_int n, lapack_int ilo,
                                lapack_int ihi, double* a, lapack_int lda,
                                const double* tau, double* work,
                                lapack_int lwork );

lapack_int LAPACKE_sorglq_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_int k, float* a, lapack_int lda,
                                const float* tau, float* work,
                                lapack_int lwork );
lapack_int LAPACKE_dorglq_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_int k, double* a, lapack_int lda,
                                const double* tau, double* work,
                                lapack_int lwork );

lapack_int LAPACKE_sorgql_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_int k, float* a, lapack_int lda,
                                const float* tau, float* work,
                                lapack_int lwork );
lapack_int LAPACKE_dorgql_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_int k, double* a, lapack_int lda,
                                const double* tau, double* work,
                                lapack_int lwork );

lapack_int LAPACKE_sorgqr_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_int k, float* a, lapack_int lda,
                                const float* tau, float* work,
                                lapack_int lwork );
lapack_int LAPACKE_dorgqr_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_int k, double* a, lapack_int lda,
                                const double* tau, double* work,
                                lapack_int lwork );

lapack_int LAPACKE_sorgrq_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_int k, float* a, lapack_int lda,
                                const float* tau, float* work,
                                lapack_int lwork );
lapack_int LAPACKE_dorgrq_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_int k, double* a, lapack_int lda,
                                const double* tau, double* work,
                                lapack_int lwork );

lapack_int LAPACKE_sorgtr_work( int matrix_order, char uplo, lapack_int n,
                                float* a, lapack_int lda, const float* tau,
                                float* work, lapack_int lwork );
lapack_int LAPACKE_dorgtr_work( int matrix_order, char uplo, lapack_int n,
                                double* a, lapack_int lda, const double* tau,
                                double* work, lapack_int lwork );

lapack_int LAPACKE_sormbr_work( int matrix_order, char vect, char side,
                                char trans, lapack_int m, lapack_int n,
                                lapack_int k, const float* a, lapack_int lda,
                                const float* tau, float* c, lapack_int ldc,
                                float* work, lapack_int lwork );
lapack_int LAPACKE_dormbr_work( int matrix_order, char vect, char side,
                                char trans, lapack_int m, lapack_int n,
                                lapack_int k, const double* a, lapack_int lda,
                                const double* tau, double* c, lapack_int ldc,
                                double* work, lapack_int lwork );

lapack_int LAPACKE_sormhr_work( int matrix_order, char side, char trans,
                                lapack_int m, lapack_int n, lapack_int ilo,
                                lapack_int ihi, const float* a, lapack_int lda,
                                const float* tau, float* c, lapack_int ldc,
                                float* work, lapack_int lwork );
lapack_int LAPACKE_dormhr_work( int matrix_order, char side, char trans,
                                lapack_int m, lapack_int n, lapack_int ilo,
                                lapack_int ihi, const double* a, lapack_int lda,
                                const double* tau, double* c, lapack_int ldc,
                                double* work, lapack_int lwork );

lapack_int LAPACKE_sormlq_work( int matrix_order, char side, char trans,
                                lapack_int m, lapack_int n, lapack_int k,
                                const float* a, lapack_int lda,
                                const float* tau, float* c, lapack_int ldc,
                                float* work, lapack_int lwork );
lapack_int LAPACKE_dormlq_work( int matrix_order, char side, char trans,
                                lapack_int m, lapack_int n, lapack_int k,
                                const double* a, lapack_int lda,
                                const double* tau, double* c, lapack_int ldc,
                                double* work, lapack_int lwork );

lapack_int LAPACKE_sormql_work( int matrix_order, char side, char trans,
                                lapack_int m, lapack_int n, lapack_int k,
                                const float* a, lapack_int lda,
                                const float* tau, float* c, lapack_int ldc,
                                float* work, lapack_int lwork );
lapack_int LAPACKE_dormql_work( int matrix_order, char side, char trans,
                                lapack_int m, lapack_int n, lapack_int k,
                                const double* a, lapack_int lda,
                                const double* tau, double* c, lapack_int ldc,
                                double* work, lapack_int lwork );

lapack_int LAPACKE_sormqr_work( int matrix_order, char side, char trans,
                                lapack_int m, lapack_int n, lapack_int k,
                                const float* a, lapack_int lda,
                                const float* tau, float* c, lapack_int ldc,
                                float* work, lapack_int lwork );
lapack_int LAPACKE_dormqr_work( int matrix_order, char side, char trans,
                                lapack_int m, lapack_int n, lapack_int k,
                                const double* a, lapack_int lda,
                                const double* tau, double* c, lapack_int ldc,
                                double* work, lapack_int lwork );

lapack_int LAPACKE_sormrq_work( int matrix_order, char side, char trans,
                                lapack_int m, lapack_int n, lapack_int k,
                                const float* a, lapack_int lda,
                                const float* tau, float* c, lapack_int ldc,
                                float* work, lapack_int lwork );
lapack_int LAPACKE_dormrq_work( int matrix_order, char side, char trans,
                                lapack_int m, lapack_int n, lapack_int k,
                                const double* a, lapack_int lda,
                                const double* tau, double* c, lapack_int ldc,
                                double* work, lapack_int lwork );

lapack_int LAPACKE_sormrz_work( int matrix_order, char side, char trans,
                                lapack_int m, lapack_int n, lapack_int k,
                                lapack_int l, const float* a, lapack_int lda,
                                const float* tau, float* c, lapack_int ldc,
                                float* work, lapack_int lwork );
lapack_int LAPACKE_dormrz_work( int matrix_order, char side, char trans,
                                lapack_int m, lapack_int n, lapack_int k,
                                lapack_int l, const double* a, lapack_int lda,
                                const double* tau, double* c, lapack_int ldc,
                                double* work, lapack_int lwork );

lapack_int LAPACKE_sormtr_work( int matrix_order, char side, char uplo,
                                char trans, lapack_int m, lapack_int n,
                                const float* a, lapack_int lda,
                                const float* tau, float* c, lapack_int ldc,
                                float* work, lapack_int lwork );
lapack_int LAPACKE_dormtr_work( int matrix_order, char side, char uplo,
                                char trans, lapack_int m, lapack_int n,
                                const double* a, lapack_int lda,
                                const double* tau, double* c, lapack_int ldc,
                                double* work, lapack_int lwork );

lapack_int LAPACKE_spbcon_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int kd, const float* ab, lapack_int ldab,
                                float anorm, float* rcond, float* work,
                                lapack_int* iwork );
lapack_int LAPACKE_dpbcon_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int kd, const double* ab,
                                lapack_int ldab, double anorm, double* rcond,
                                double* work, lapack_int* iwork );
lapack_int LAPACKE_cpbcon_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int kd, const lapack_complex_float* ab,
                                lapack_int ldab, float anorm, float* rcond,
                                lapack_complex_float* work, float* rwork );
lapack_int LAPACKE_zpbcon_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int kd, const lapack_complex_double* ab,
                                lapack_int ldab, double anorm, double* rcond,
                                lapack_complex_double* work, double* rwork );

lapack_int LAPACKE_spbequ_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int kd, const float* ab, lapack_int ldab,
                                float* s, float* scond, float* amax );
lapack_int LAPACKE_dpbequ_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int kd, const double* ab,
                                lapack_int ldab, double* s, double* scond,
                                double* amax );
lapack_int LAPACKE_cpbequ_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int kd, const lapack_complex_float* ab,
                                lapack_int ldab, float* s, float* scond,
                                float* amax );
lapack_int LAPACKE_zpbequ_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int kd, const lapack_complex_double* ab,
                                lapack_int ldab, double* s, double* scond,
                                double* amax );

lapack_int LAPACKE_spbrfs_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int kd, lapack_int nrhs, const float* ab,
                                lapack_int ldab, const float* afb,
                                lapack_int ldafb, const float* b,
                                lapack_int ldb, float* x, lapack_int ldx,
                                float* ferr, float* berr, float* work,
                                lapack_int* iwork );
lapack_int LAPACKE_dpbrfs_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int kd, lapack_int nrhs,
                                const double* ab, lapack_int ldab,
                                const double* afb, lapack_int ldafb,
                                const double* b, lapack_int ldb, double* x,
                                lapack_int ldx, double* ferr, double* berr,
                                double* work, lapack_int* iwork );
lapack_int LAPACKE_cpbrfs_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int kd, lapack_int nrhs,
                                const lapack_complex_float* ab, lapack_int ldab,
                                const lapack_complex_float* afb,
                                lapack_int ldafb, const lapack_complex_float* b,
                                lapack_int ldb, lapack_complex_float* x,
                                lapack_int ldx, float* ferr, float* berr,
                                lapack_complex_float* work, float* rwork );
lapack_int LAPACKE_zpbrfs_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int kd, lapack_int nrhs,
                                const lapack_complex_double* ab,
                                lapack_int ldab,
                                const lapack_complex_double* afb,
                                lapack_int ldafb,
                                const lapack_complex_double* b, lapack_int ldb,
                                lapack_complex_double* x, lapack_int ldx,
                                double* ferr, double* berr,
                                lapack_complex_double* work, double* rwork );

lapack_int LAPACKE_spbstf_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int kb, float* bb, lapack_int ldbb );
lapack_int LAPACKE_dpbstf_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int kb, double* bb, lapack_int ldbb );
lapack_int LAPACKE_cpbstf_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int kb, lapack_complex_float* bb,
                                lapack_int ldbb );
lapack_int LAPACKE_zpbstf_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int kb, lapack_complex_double* bb,
                                lapack_int ldbb );

lapack_int LAPACKE_spbsv_work( int matrix_order, char uplo, lapack_int n,
                               lapack_int kd, lapack_int nrhs, float* ab,
                               lapack_int ldab, float* b, lapack_int ldb );
lapack_int LAPACKE_dpbsv_work( int matrix_order, char uplo, lapack_int n,
                               lapack_int kd, lapack_int nrhs, double* ab,
                               lapack_int ldab, double* b, lapack_int ldb );
lapack_int LAPACKE_cpbsv_work( int matrix_order, char uplo, lapack_int n,
                               lapack_int kd, lapack_int nrhs,
                               lapack_complex_float* ab, lapack_int ldab,
                               lapack_complex_float* b, lapack_int ldb );
lapack_int LAPACKE_zpbsv_work( int matrix_order, char uplo, lapack_int n,
                               lapack_int kd, lapack_int nrhs,
                               lapack_complex_double* ab, lapack_int ldab,
                               lapack_complex_double* b, lapack_int ldb );

lapack_int LAPACKE_spbsvx_work( int matrix_order, char fact, char uplo,
                                lapack_int n, lapack_int kd, lapack_int nrhs,
                                float* ab, lapack_int ldab, float* afb,
                                lapack_int ldafb, char* equed, float* s,
                                float* b, lapack_int ldb, float* x,
                                lapack_int ldx, float* rcond, float* ferr,
                                float* berr, float* work, lapack_int* iwork );
lapack_int LAPACKE_dpbsvx_work( int matrix_order, char fact, char uplo,
                                lapack_int n, lapack_int kd, lapack_int nrhs,
                                double* ab, lapack_int ldab, double* afb,
                                lapack_int ldafb, char* equed, double* s,
                                double* b, lapack_int ldb, double* x,
                                lapack_int ldx, double* rcond, double* ferr,
                                double* berr, double* work, lapack_int* iwork );
lapack_int LAPACKE_cpbsvx_work( int matrix_order, char fact, char uplo,
                                lapack_int n, lapack_int kd, lapack_int nrhs,
                                lapack_complex_float* ab, lapack_int ldab,
                                lapack_complex_float* afb, lapack_int ldafb,
                                char* equed, float* s, lapack_complex_float* b,
                                lapack_int ldb, lapack_complex_float* x,
                                lapack_int ldx, float* rcond, float* ferr,
                                float* berr, lapack_complex_float* work,
                                float* rwork );
lapack_int LAPACKE_zpbsvx_work( int matrix_order, char fact, char uplo,
                                lapack_int n, lapack_int kd, lapack_int nrhs,
                                lapack_complex_double* ab, lapack_int ldab,
                                lapack_complex_double* afb, lapack_int ldafb,
                                char* equed, double* s,
                                lapack_complex_double* b, lapack_int ldb,
                                lapack_complex_double* x, lapack_int ldx,
                                double* rcond, double* ferr, double* berr,
                                lapack_complex_double* work, double* rwork );

lapack_int LAPACKE_spbtrf_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int kd, float* ab, lapack_int ldab );
lapack_int LAPACKE_dpbtrf_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int kd, double* ab, lapack_int ldab );
lapack_int LAPACKE_cpbtrf_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int kd, lapack_complex_float* ab,
                                lapack_int ldab );
lapack_int LAPACKE_zpbtrf_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int kd, lapack_complex_double* ab,
                                lapack_int ldab );

lapack_int LAPACKE_spbtrs_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int kd, lapack_int nrhs, const float* ab,
                                lapack_int ldab, float* b, lapack_int ldb );
lapack_int LAPACKE_dpbtrs_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int kd, lapack_int nrhs,
                                const double* ab, lapack_int ldab, double* b,
                                lapack_int ldb );
lapack_int LAPACKE_cpbtrs_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int kd, lapack_int nrhs,
                                const lapack_complex_float* ab, lapack_int ldab,
                                lapack_complex_float* b, lapack_int ldb );
lapack_int LAPACKE_zpbtrs_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int kd, lapack_int nrhs,
                                const lapack_complex_double* ab,
                                lapack_int ldab, lapack_complex_double* b,
                                lapack_int ldb );

lapack_int LAPACKE_spftrf_work( int matrix_order, char transr, char uplo,
                                lapack_int n, float* a );
lapack_int LAPACKE_dpftrf_work( int matrix_order, char transr, char uplo,
                                lapack_int n, double* a );
lapack_int LAPACKE_cpftrf_work( int matrix_order, char transr, char uplo,
                                lapack_int n, lapack_complex_float* a );
lapack_int LAPACKE_zpftrf_work( int matrix_order, char transr, char uplo,
                                lapack_int n, lapack_complex_double* a );

lapack_int LAPACKE_spftri_work( int matrix_order, char transr, char uplo,
                                lapack_int n, float* a );
lapack_int LAPACKE_dpftri_work( int matrix_order, char transr, char uplo,
                                lapack_int n, double* a );
lapack_int LAPACKE_cpftri_work( int matrix_order, char transr, char uplo,
                                lapack_int n, lapack_complex_float* a );
lapack_int LAPACKE_zpftri_work( int matrix_order, char transr, char uplo,
                                lapack_int n, lapack_complex_double* a );

lapack_int LAPACKE_spftrs_work( int matrix_order, char transr, char uplo,
                                lapack_int n, lapack_int nrhs, const float* a,
                                float* b, lapack_int ldb );
lapack_int LAPACKE_dpftrs_work( int matrix_order, char transr, char uplo,
                                lapack_int n, lapack_int nrhs, const double* a,
                                double* b, lapack_int ldb );
lapack_int LAPACKE_cpftrs_work( int matrix_order, char transr, char uplo,
                                lapack_int n, lapack_int nrhs,
                                const lapack_complex_float* a,
                                lapack_complex_float* b, lapack_int ldb );
lapack_int LAPACKE_zpftrs_work( int matrix_order, char transr, char uplo,
                                lapack_int n, lapack_int nrhs,
                                const lapack_complex_double* a,
                                lapack_complex_double* b, lapack_int ldb );

lapack_int LAPACKE_spocon_work( int matrix_order, char uplo, lapack_int n,
                                const float* a, lapack_int lda, float anorm,
                                float* rcond, float* work, lapack_int* iwork );
lapack_int LAPACKE_dpocon_work( int matrix_order, char uplo, lapack_int n,
                                const double* a, lapack_int lda, double anorm,
                                double* rcond, double* work,
                                lapack_int* iwork );
lapack_int LAPACKE_cpocon_work( int matrix_order, char uplo, lapack_int n,
                                const lapack_complex_float* a, lapack_int lda,
                                float anorm, float* rcond,
                                lapack_complex_float* work, float* rwork );
lapack_int LAPACKE_zpocon_work( int matrix_order, char uplo, lapack_int n,
                                const lapack_complex_double* a, lapack_int lda,
                                double anorm, double* rcond,
                                lapack_complex_double* work, double* rwork );

lapack_int LAPACKE_spoequ_work( int matrix_order, lapack_int n, const float* a,
                                lapack_int lda, float* s, float* scond,
                                float* amax );
lapack_int LAPACKE_dpoequ_work( int matrix_order, lapack_int n, const double* a,
                                lapack_int lda, double* s, double* scond,
                                double* amax );
lapack_int LAPACKE_cpoequ_work( int matrix_order, lapack_int n,
                                const lapack_complex_float* a, lapack_int lda,
                                float* s, float* scond, float* amax );
lapack_int LAPACKE_zpoequ_work( int matrix_order, lapack_int n,
                                const lapack_complex_double* a, lapack_int lda,
                                double* s, double* scond, double* amax );

lapack_int LAPACKE_spoequb_work( int matrix_order, lapack_int n, const float* a,
                                 lapack_int lda, float* s, float* scond,
                                 float* amax );
lapack_int LAPACKE_dpoequb_work( int matrix_order, lapack_int n,
                                 const double* a, lapack_int lda, double* s,
                                 double* scond, double* amax );
lapack_int LAPACKE_cpoequb_work( int matrix_order, lapack_int n,
                                 const lapack_complex_float* a, lapack_int lda,
                                 float* s, float* scond, float* amax );
lapack_int LAPACKE_zpoequb_work( int matrix_order, lapack_int n,
                                 const lapack_complex_double* a, lapack_int lda,
                                 double* s, double* scond, double* amax );

lapack_int LAPACKE_sporfs_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int nrhs, const float* a, lapack_int lda,
                                const float* af, lapack_int ldaf,
                                const float* b, lapack_int ldb, float* x,
                                lapack_int ldx, float* ferr, float* berr,
                                float* work, lapack_int* iwork );
lapack_int LAPACKE_dporfs_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int nrhs, const double* a,
                                lapack_int lda, const double* af,
                                lapack_int ldaf, const double* b,
                                lapack_int ldb, double* x, lapack_int ldx,
                                double* ferr, double* berr, double* work,
                                lapack_int* iwork );
lapack_int LAPACKE_cporfs_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int nrhs, const lapack_complex_float* a,
                                lapack_int lda, const lapack_complex_float* af,
                                lapack_int ldaf, const lapack_complex_float* b,
                                lapack_int ldb, lapack_complex_float* x,
                                lapack_int ldx, float* ferr, float* berr,
                                lapack_complex_float* work, float* rwork );
lapack_int LAPACKE_zporfs_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int nrhs, const lapack_complex_double* a,
                                lapack_int lda, const lapack_complex_double* af,
                                lapack_int ldaf, const lapack_complex_double* b,
                                lapack_int ldb, lapack_complex_double* x,
                                lapack_int ldx, double* ferr, double* berr,
                                lapack_complex_double* work, double* rwork );

lapack_int LAPACKE_sporfsx_work( int matrix_order, char uplo, char equed,
                                 lapack_int n, lapack_int nrhs, const float* a,
                                 lapack_int lda, const float* af,
                                 lapack_int ldaf, const float* s,
                                 const float* b, lapack_int ldb, float* x,
                                 lapack_int ldx, float* rcond, float* berr,
                                 lapack_int n_err_bnds, float* err_bnds_norm,
                                 float* err_bnds_comp, lapack_int nparams,
                                 float* params, float* work,
                                 lapack_int* iwork );
lapack_int LAPACKE_dporfsx_work( int matrix_order, char uplo, char equed,
                                 lapack_int n, lapack_int nrhs, const double* a,
                                 lapack_int lda, const double* af,
                                 lapack_int ldaf, const double* s,
                                 const double* b, lapack_int ldb, double* x,
                                 lapack_int ldx, double* rcond, double* berr,
                                 lapack_int n_err_bnds, double* err_bnds_norm,
                                 double* err_bnds_comp, lapack_int nparams,
                                 double* params, double* work,
                                 lapack_int* iwork );
lapack_int LAPACKE_cporfsx_work( int matrix_order, char uplo, char equed,
                                 lapack_int n, lapack_int nrhs,
                                 const lapack_complex_float* a, lapack_int lda,
                                 const lapack_complex_float* af,
                                 lapack_int ldaf, const float* s,
                                 const lapack_complex_float* b, lapack_int ldb,
                                 lapack_complex_float* x, lapack_int ldx,
                                 float* rcond, float* berr,
                                 lapack_int n_err_bnds, float* err_bnds_norm,
                                 float* err_bnds_comp, lapack_int nparams,
                                 float* params, lapack_complex_float* work,
                                 float* rwork );
lapack_int LAPACKE_zporfsx_work( int matrix_order, char uplo, char equed,
                                 lapack_int n, lapack_int nrhs,
                                 const lapack_complex_double* a, lapack_int lda,
                                 const lapack_complex_double* af,
                                 lapack_int ldaf, const double* s,
                                 const lapack_complex_double* b, lapack_int ldb,
                                 lapack_complex_double* x, lapack_int ldx,
                                 double* rcond, double* berr,
                                 lapack_int n_err_bnds, double* err_bnds_norm,
                                 double* err_bnds_comp, lapack_int nparams,
                                 double* params, lapack_complex_double* work,
                                 double* rwork );

lapack_int LAPACKE_sposv_work( int matrix_order, char uplo, lapack_int n,
                               lapack_int nrhs, float* a, lapack_int lda,
                               float* b, lapack_int ldb );
lapack_int LAPACKE_dposv_work( int matrix_order, char uplo, lapack_int n,
                               lapack_int nrhs, double* a, lapack_int lda,
                               double* b, lapack_int ldb );
lapack_int LAPACKE_cposv_work( int matrix_order, char uplo, lapack_int n,
                               lapack_int nrhs, lapack_complex_float* a,
                               lapack_int lda, lapack_complex_float* b,
                               lapack_int ldb );
lapack_int LAPACKE_zposv_work( int matrix_order, char uplo, lapack_int n,
                               lapack_int nrhs, lapack_complex_double* a,
                               lapack_int lda, lapack_complex_double* b,
                               lapack_int ldb );
lapack_int LAPACKE_dsposv_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int nrhs, double* a, lapack_int lda,
                                double* b, lapack_int ldb, double* x,
                                lapack_int ldx, double* work, float* swork,
                                lapack_int* iter );
lapack_int LAPACKE_zcposv_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int nrhs, lapack_complex_double* a,
                                lapack_int lda, lapack_complex_double* b,
                                lapack_int ldb, lapack_complex_double* x,
                                lapack_int ldx, lapack_complex_double* work,
                                lapack_complex_float* swork, double* rwork,
                                lapack_int* iter );

lapack_int LAPACKE_sposvx_work( int matrix_order, char fact, char uplo,
                                lapack_int n, lapack_int nrhs, float* a,
                                lapack_int lda, float* af, lapack_int ldaf,
                                char* equed, float* s, float* b, lapack_int ldb,
                                float* x, lapack_int ldx, float* rcond,
                                float* ferr, float* berr, float* work,
                                lapack_int* iwork );
lapack_int LAPACKE_dposvx_work( int matrix_order, char fact, char uplo,
                                lapack_int n, lapack_int nrhs, double* a,
                                lapack_int lda, double* af, lapack_int ldaf,
                                char* equed, double* s, double* b,
                                lapack_int ldb, double* x, lapack_int ldx,
                                double* rcond, double* ferr, double* berr,
                                double* work, lapack_int* iwork );
lapack_int LAPACKE_cposvx_work( int matrix_order, char fact, char uplo,
                                lapack_int n, lapack_int nrhs,
                                lapack_complex_float* a, lapack_int lda,
                                lapack_complex_float* af, lapack_int ldaf,
                                char* equed, float* s, lapack_complex_float* b,
                                lapack_int ldb, lapack_complex_float* x,
                                lapack_int ldx, float* rcond, float* ferr,
                                float* berr, lapack_complex_float* work,
                                float* rwork );
lapack_int LAPACKE_zposvx_work( int matrix_order, char fact, char uplo,
                                lapack_int n, lapack_int nrhs,
                                lapack_complex_double* a, lapack_int lda,
                                lapack_complex_double* af, lapack_int ldaf,
                                char* equed, double* s,
                                lapack_complex_double* b, lapack_int ldb,
                                lapack_complex_double* x, lapack_int ldx,
                                double* rcond, double* ferr, double* berr,
                                lapack_complex_double* work, double* rwork );

lapack_int LAPACKE_sposvxx_work( int matrix_order, char fact, char uplo,
                                 lapack_int n, lapack_int nrhs, float* a,
                                 lapack_int lda, float* af, lapack_int ldaf,
                                 char* equed, float* s, float* b,
                                 lapack_int ldb, float* x, lapack_int ldx,
                                 float* rcond, float* rpvgrw, float* berr,
                                 lapack_int n_err_bnds, float* err_bnds_norm,
                                 float* err_bnds_comp, lapack_int nparams,
                                 float* params, float* work,
                                 lapack_int* iwork );
lapack_int LAPACKE_dposvxx_work( int matrix_order, char fact, char uplo,
                                 lapack_int n, lapack_int nrhs, double* a,
                                 lapack_int lda, double* af, lapack_int ldaf,
                                 char* equed, double* s, double* b,
                                 lapack_int ldb, double* x, lapack_int ldx,
                                 double* rcond, double* rpvgrw, double* berr,
                                 lapack_int n_err_bnds, double* err_bnds_norm,
                                 double* err_bnds_comp, lapack_int nparams,
                                 double* params, double* work,
                                 lapack_int* iwork );
lapack_int LAPACKE_cposvxx_work( int matrix_order, char fact, char uplo,
                                 lapack_int n, lapack_int nrhs,
                                 lapack_complex_float* a, lapack_int lda,
                                 lapack_complex_float* af, lapack_int ldaf,
                                 char* equed, float* s, lapack_complex_float* b,
                                 lapack_int ldb, lapack_complex_float* x,
                                 lapack_int ldx, float* rcond, float* rpvgrw,
                                 float* berr, lapack_int n_err_bnds,
                                 float* err_bnds_norm, float* err_bnds_comp,
                                 lapack_int nparams, float* params,
                                 lapack_complex_float* work, float* rwork );
lapack_int LAPACKE_zposvxx_work( int matrix_order, char fact, char uplo,
                                 lapack_int n, lapack_int nrhs,
                                 lapack_complex_double* a, lapack_int lda,
                                 lapack_complex_double* af, lapack_int ldaf,
                                 char* equed, double* s,
                                 lapack_complex_double* b, lapack_int ldb,
                                 lapack_complex_double* x, lapack_int ldx,
                                 double* rcond, double* rpvgrw, double* berr,
                                 lapack_int n_err_bnds, double* err_bnds_norm,
                                 double* err_bnds_comp, lapack_int nparams,
                                 double* params, lapack_complex_double* work,
                                 double* rwork );

lapack_int LAPACKE_spotrf_work( int matrix_order, char uplo, lapack_int n,
                                float* a, lapack_int lda );
lapack_int LAPACKE_dpotrf_work( int matrix_order, char uplo, lapack_int n,
                                double* a, lapack_int lda );
lapack_int LAPACKE_cpotrf_work( int matrix_order, char uplo, lapack_int n,
                                lapack_complex_float* a, lapack_int lda );
lapack_int LAPACKE_zpotrf_work( int matrix_order, char uplo, lapack_int n,
                                lapack_complex_double* a, lapack_int lda );

lapack_int LAPACKE_spotri_work( int matrix_order, char uplo, lapack_int n,
                                float* a, lapack_int lda );
lapack_int LAPACKE_dpotri_work( int matrix_order, char uplo, lapack_int n,
                                double* a, lapack_int lda );
lapack_int LAPACKE_cpotri_work( int matrix_order, char uplo, lapack_int n,
                                lapack_complex_float* a, lapack_int lda );
lapack_int LAPACKE_zpotri_work( int matrix_order, char uplo, lapack_int n,
                                lapack_complex_double* a, lapack_int lda );

lapack_int LAPACKE_spotrs_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int nrhs, const float* a, lapack_int lda,
                                float* b, lapack_int ldb );
lapack_int LAPACKE_dpotrs_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int nrhs, const double* a,
                                lapack_int lda, double* b, lapack_int ldb );
lapack_int LAPACKE_cpotrs_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int nrhs, const lapack_complex_float* a,
                                lapack_int lda, lapack_complex_float* b,
                                lapack_int ldb );
lapack_int LAPACKE_zpotrs_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int nrhs, const lapack_complex_double* a,
                                lapack_int lda, lapack_complex_double* b,
                                lapack_int ldb );

lapack_int LAPACKE_sppcon_work( int matrix_order, char uplo, lapack_int n,
                                const float* ap, float anorm, float* rcond,
                                float* work, lapack_int* iwork );
lapack_int LAPACKE_dppcon_work( int matrix_order, char uplo, lapack_int n,
                                const double* ap, double anorm, double* rcond,
                                double* work, lapack_int* iwork );
lapack_int LAPACKE_cppcon_work( int matrix_order, char uplo, lapack_int n,
                                const lapack_complex_float* ap, float anorm,
                                float* rcond, lapack_complex_float* work,
                                float* rwork );
lapack_int LAPACKE_zppcon_work( int matrix_order, char uplo, lapack_int n,
                                const lapack_complex_double* ap, double anorm,
                                double* rcond, lapack_complex_double* work,
                                double* rwork );

lapack_int LAPACKE_sppequ_work( int matrix_order, char uplo, lapack_int n,
                                const float* ap, float* s, float* scond,
                                float* amax );
lapack_int LAPACKE_dppequ_work( int matrix_order, char uplo, lapack_int n,
                                const double* ap, double* s, double* scond,
                                double* amax );
lapack_int LAPACKE_cppequ_work( int matrix_order, char uplo, lapack_int n,
                                const lapack_complex_float* ap, float* s,
                                float* scond, float* amax );
lapack_int LAPACKE_zppequ_work( int matrix_order, char uplo, lapack_int n,
                                const lapack_complex_double* ap, double* s,
                                double* scond, double* amax );

lapack_int LAPACKE_spprfs_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int nrhs, const float* ap,
                                const float* afp, const float* b,
                                lapack_int ldb, float* x, lapack_int ldx,
                                float* ferr, float* berr, float* work,
                                lapack_int* iwork );
lapack_int LAPACKE_dpprfs_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int nrhs, const double* ap,
                                const double* afp, const double* b,
                                lapack_int ldb, double* x, lapack_int ldx,
                                double* ferr, double* berr, double* work,
                                lapack_int* iwork );
lapack_int LAPACKE_cpprfs_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int nrhs, const lapack_complex_float* ap,
                                const lapack_complex_float* afp,
                                const lapack_complex_float* b, lapack_int ldb,
                                lapack_complex_float* x, lapack_int ldx,
                                float* ferr, float* berr,
                                lapack_complex_float* work, float* rwork );
lapack_int LAPACKE_zpprfs_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int nrhs,
                                const lapack_complex_double* ap,
                                const lapack_complex_double* afp,
                                const lapack_complex_double* b, lapack_int ldb,
                                lapack_complex_double* x, lapack_int ldx,
                                double* ferr, double* berr,
                                lapack_complex_double* work, double* rwork );

lapack_int LAPACKE_sppsv_work( int matrix_order, char uplo, lapack_int n,
                               lapack_int nrhs, float* ap, float* b,
                               lapack_int ldb );
lapack_int LAPACKE_dppsv_work( int matrix_order, char uplo, lapack_int n,
                               lapack_int nrhs, double* ap, double* b,
                               lapack_int ldb );
lapack_int LAPACKE_cppsv_work( int matrix_order, char uplo, lapack_int n,
                               lapack_int nrhs, lapack_complex_float* ap,
                               lapack_complex_float* b, lapack_int ldb );
lapack_int LAPACKE_zppsv_work( int matrix_order, char uplo, lapack_int n,
                               lapack_int nrhs, lapack_complex_double* ap,
                               lapack_complex_double* b, lapack_int ldb );

lapack_int LAPACKE_sppsvx_work( int matrix_order, char fact, char uplo,
                                lapack_int n, lapack_int nrhs, float* ap,
                                float* afp, char* equed, float* s, float* b,
                                lapack_int ldb, float* x, lapack_int ldx,
                                float* rcond, float* ferr, float* berr,
                                float* work, lapack_int* iwork );
lapack_int LAPACKE_dppsvx_work( int matrix_order, char fact, char uplo,
                                lapack_int n, lapack_int nrhs, double* ap,
                                double* afp, char* equed, double* s, double* b,
                                lapack_int ldb, double* x, lapack_int ldx,
                                double* rcond, double* ferr, double* berr,
                                double* work, lapack_int* iwork );
lapack_int LAPACKE_cppsvx_work( int matrix_order, char fact, char uplo,
                                lapack_int n, lapack_int nrhs,
                                lapack_complex_float* ap,
                                lapack_complex_float* afp, char* equed,
                                float* s, lapack_complex_float* b,
                                lapack_int ldb, lapack_complex_float* x,
                                lapack_int ldx, float* rcond, float* ferr,
                                float* berr, lapack_complex_float* work,
                                float* rwork );
lapack_int LAPACKE_zppsvx_work( int matrix_order, char fact, char uplo,
                                lapack_int n, lapack_int nrhs,
                                lapack_complex_double* ap,
                                lapack_complex_double* afp, char* equed,
                                double* s, lapack_complex_double* b,
                                lapack_int ldb, lapack_complex_double* x,
                                lapack_int ldx, double* rcond, double* ferr,
                                double* berr, lapack_complex_double* work,
                                double* rwork );

lapack_int LAPACKE_spptrf_work( int matrix_order, char uplo, lapack_int n,
                                float* ap );
lapack_int LAPACKE_dpptrf_work( int matrix_order, char uplo, lapack_int n,
                                double* ap );
lapack_int LAPACKE_cpptrf_work( int matrix_order, char uplo, lapack_int n,
                                lapack_complex_float* ap );
lapack_int LAPACKE_zpptrf_work( int matrix_order, char uplo, lapack_int n,
                                lapack_complex_double* ap );

lapack_int LAPACKE_spptri_work( int matrix_order, char uplo, lapack_int n,
                                float* ap );
lapack_int LAPACKE_dpptri_work( int matrix_order, char uplo, lapack_int n,
                                double* ap );
lapack_int LAPACKE_cpptri_work( int matrix_order, char uplo, lapack_int n,
                                lapack_complex_float* ap );
lapack_int LAPACKE_zpptri_work( int matrix_order, char uplo, lapack_int n,
                                lapack_complex_double* ap );

lapack_int LAPACKE_spptrs_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int nrhs, const float* ap, float* b,
                                lapack_int ldb );
lapack_int LAPACKE_dpptrs_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int nrhs, const double* ap, double* b,
                                lapack_int ldb );
lapack_int LAPACKE_cpptrs_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int nrhs, const lapack_complex_float* ap,
                                lapack_complex_float* b, lapack_int ldb );
lapack_int LAPACKE_zpptrs_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int nrhs,
                                const lapack_complex_double* ap,
                                lapack_complex_double* b, lapack_int ldb );

lapack_int LAPACKE_spstrf_work( int matrix_order, char uplo, lapack_int n,
                                float* a, lapack_int lda, lapack_int* piv,
                                lapack_int* rank, float tol, float* work );
lapack_int LAPACKE_dpstrf_work( int matrix_order, char uplo, lapack_int n,
                                double* a, lapack_int lda, lapack_int* piv,
                                lapack_int* rank, double tol, double* work );
lapack_int LAPACKE_cpstrf_work( int matrix_order, char uplo, lapack_int n,
                                lapack_complex_float* a, lapack_int lda,
                                lapack_int* piv, lapack_int* rank, float tol,
                                float* work );
lapack_int LAPACKE_zpstrf_work( int matrix_order, char uplo, lapack_int n,
                                lapack_complex_double* a, lapack_int lda,
                                lapack_int* piv, lapack_int* rank, double tol,
                                double* work );

lapack_int LAPACKE_sptcon_work( lapack_int n, const float* d, const float* e,
                                float anorm, float* rcond, float* work );
lapack_int LAPACKE_dptcon_work( lapack_int n, const double* d, const double* e,
                                double anorm, double* rcond, double* work );
lapack_int LAPACKE_cptcon_work( lapack_int n, const float* d,
                                const lapack_complex_float* e, float anorm,
                                float* rcond, float* work );
lapack_int LAPACKE_zptcon_work( lapack_int n, const double* d,
                                const lapack_complex_double* e, double anorm,
                                double* rcond, double* work );

lapack_int LAPACKE_spteqr_work( int matrix_order, char compz, lapack_int n,
                                float* d, float* e, float* z, lapack_int ldz,
                                float* work );
lapack_int LAPACKE_dpteqr_work( int matrix_order, char compz, lapack_int n,
                                double* d, double* e, double* z, lapack_int ldz,
                                double* work );
lapack_int LAPACKE_cpteqr_work( int matrix_order, char compz, lapack_int n,
                                float* d, float* e, lapack_complex_float* z,
                                lapack_int ldz, float* work );
lapack_int LAPACKE_zpteqr_work( int matrix_order, char compz, lapack_int n,
                                double* d, double* e, lapack_complex_double* z,
                                lapack_int ldz, double* work );

lapack_int LAPACKE_sptrfs_work( int matrix_order, lapack_int n, lapack_int nrhs,
                                const float* d, const float* e, const float* df,
                                const float* ef, const float* b, lapack_int ldb,
                                float* x, lapack_int ldx, float* ferr,
                                float* berr, float* work );
lapack_int LAPACKE_dptrfs_work( int matrix_order, lapack_int n, lapack_int nrhs,
                                const double* d, const double* e,
                                const double* df, const double* ef,
                                const double* b, lapack_int ldb, double* x,
                                lapack_int ldx, double* ferr, double* berr,
                                double* work );
lapack_int LAPACKE_cptrfs_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int nrhs, const float* d,
                                const lapack_complex_float* e, const float* df,
                                const lapack_complex_float* ef,
                                const lapack_complex_float* b, lapack_int ldb,
                                lapack_complex_float* x, lapack_int ldx,
                                float* ferr, float* berr,
                                lapack_complex_float* work, float* rwork );
lapack_int LAPACKE_zptrfs_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int nrhs, const double* d,
                                const lapack_complex_double* e,
                                const double* df,
                                const lapack_complex_double* ef,
                                const lapack_complex_double* b, lapack_int ldb,
                                lapack_complex_double* x, lapack_int ldx,
                                double* ferr, double* berr,
                                lapack_complex_double* work, double* rwork );

lapack_int LAPACKE_sptsv_work( int matrix_order, lapack_int n, lapack_int nrhs,
                               float* d, float* e, float* b, lapack_int ldb );
lapack_int LAPACKE_dptsv_work( int matrix_order, lapack_int n, lapack_int nrhs,
                               double* d, double* e, double* b,
                               lapack_int ldb );
lapack_int LAPACKE_cptsv_work( int matrix_order, lapack_int n, lapack_int nrhs,
                               float* d, lapack_complex_float* e,
                               lapack_complex_float* b, lapack_int ldb );
lapack_int LAPACKE_zptsv_work( int matrix_order, lapack_int n, lapack_int nrhs,
                               double* d, lapack_complex_double* e,
                               lapack_complex_double* b, lapack_int ldb );

lapack_int LAPACKE_sptsvx_work( int matrix_order, char fact, lapack_int n,
                                lapack_int nrhs, const float* d, const float* e,
                                float* df, float* ef, const float* b,
                                lapack_int ldb, float* x, lapack_int ldx,
                                float* rcond, float* ferr, float* berr,
                                float* work );
lapack_int LAPACKE_dptsvx_work( int matrix_order, char fact, lapack_int n,
                                lapack_int nrhs, const double* d,
                                const double* e, double* df, double* ef,
                                const double* b, lapack_int ldb, double* x,
                                lapack_int ldx, double* rcond, double* ferr,
                                double* berr, double* work );
lapack_int LAPACKE_cptsvx_work( int matrix_order, char fact, lapack_int n,
                                lapack_int nrhs, const float* d,
                                const lapack_complex_float* e, float* df,
                                lapack_complex_float* ef,
                                const lapack_complex_float* b, lapack_int ldb,
                                lapack_complex_float* x, lapack_int ldx,
                                float* rcond, float* ferr, float* berr,
                                lapack_complex_float* work, float* rwork );
lapack_int LAPACKE_zptsvx_work( int matrix_order, char fact, lapack_int n,
                                lapack_int nrhs, const double* d,
                                const lapack_complex_double* e, double* df,
                                lapack_complex_double* ef,
                                const lapack_complex_double* b, lapack_int ldb,
                                lapack_complex_double* x, lapack_int ldx,
                                double* rcond, double* ferr, double* berr,
                                lapack_complex_double* work, double* rwork );

lapack_int LAPACKE_spttrf_work( lapack_int n, float* d, float* e );
lapack_int LAPACKE_dpttrf_work( lapack_int n, double* d, double* e );
lapack_int LAPACKE_cpttrf_work( lapack_int n, float* d,
                                lapack_complex_float* e );
lapack_int LAPACKE_zpttrf_work( lapack_int n, double* d,
                                lapack_complex_double* e );

lapack_int LAPACKE_spttrs_work( int matrix_order, lapack_int n, lapack_int nrhs,
                                const float* d, const float* e, float* b,
                                lapack_int ldb );
lapack_int LAPACKE_dpttrs_work( int matrix_order, lapack_int n, lapack_int nrhs,
                                const double* d, const double* e, double* b,
                                lapack_int ldb );
lapack_int LAPACKE_cpttrs_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int nrhs, const float* d,
                                const lapack_complex_float* e,
                                lapack_complex_float* b, lapack_int ldb );
lapack_int LAPACKE_zpttrs_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int nrhs, const double* d,
                                const lapack_complex_double* e,
                                lapack_complex_double* b, lapack_int ldb );

lapack_int LAPACKE_ssbev_work( int matrix_order, char jobz, char uplo,
                               lapack_int n, lapack_int kd, float* ab,
                               lapack_int ldab, float* w, float* z,
                               lapack_int ldz, float* work );
lapack_int LAPACKE_dsbev_work( int matrix_order, char jobz, char uplo,
                               lapack_int n, lapack_int kd, double* ab,
                               lapack_int ldab, double* w, double* z,
                               lapack_int ldz, double* work );

lapack_int LAPACKE_ssbevd_work( int matrix_order, char jobz, char uplo,
                                lapack_int n, lapack_int kd, float* ab,
                                lapack_int ldab, float* w, float* z,
                                lapack_int ldz, float* work, lapack_int lwork,
                                lapack_int* iwork, lapack_int liwork );
lapack_int LAPACKE_dsbevd_work( int matrix_order, char jobz, char uplo,
                                lapack_int n, lapack_int kd, double* ab,
                                lapack_int ldab, double* w, double* z,
                                lapack_int ldz, double* work, lapack_int lwork,
                                lapack_int* iwork, lapack_int liwork );

lapack_int LAPACKE_ssbevx_work( int matrix_order, char jobz, char range,
                                char uplo, lapack_int n, lapack_int kd,
                                float* ab, lapack_int ldab, float* q,
                                lapack_int ldq, float vl, float vu,
                                lapack_int il, lapack_int iu, float abstol,
                                lapack_int* m, float* w, float* z,
                                lapack_int ldz, float* work, lapack_int* iwork,
                                lapack_int* ifail );
lapack_int LAPACKE_dsbevx_work( int matrix_order, char jobz, char range,
                                char uplo, lapack_int n, lapack_int kd,
                                double* ab, lapack_int ldab, double* q,
                                lapack_int ldq, double vl, double vu,
                                lapack_int il, lapack_int iu, double abstol,
                                lapack_int* m, double* w, double* z,
                                lapack_int ldz, double* work, lapack_int* iwork,
                                lapack_int* ifail );

lapack_int LAPACKE_ssbgst_work( int matrix_order, char vect, char uplo,
                                lapack_int n, lapack_int ka, lapack_int kb,
                                float* ab, lapack_int ldab, const float* bb,
                                lapack_int ldbb, float* x, lapack_int ldx,
                                float* work );
lapack_int LAPACKE_dsbgst_work( int matrix_order, char vect, char uplo,
                                lapack_int n, lapack_int ka, lapack_int kb,
                                double* ab, lapack_int ldab, const double* bb,
                                lapack_int ldbb, double* x, lapack_int ldx,
                                double* work );

lapack_int LAPACKE_ssbgv_work( int matrix_order, char jobz, char uplo,
                               lapack_int n, lapack_int ka, lapack_int kb,
                               float* ab, lapack_int ldab, float* bb,
                               lapack_int ldbb, float* w, float* z,
                               lapack_int ldz, float* work );
lapack_int LAPACKE_dsbgv_work( int matrix_order, char jobz, char uplo,
                               lapack_int n, lapack_int ka, lapack_int kb,
                               double* ab, lapack_int ldab, double* bb,
                               lapack_int ldbb, double* w, double* z,
                               lapack_int ldz, double* work );

lapack_int LAPACKE_ssbgvd_work( int matrix_order, char jobz, char uplo,
                                lapack_int n, lapack_int ka, lapack_int kb,
                                float* ab, lapack_int ldab, float* bb,
                                lapack_int ldbb, float* w, float* z,
                                lapack_int ldz, float* work, lapack_int lwork,
                                lapack_int* iwork, lapack_int liwork );
lapack_int LAPACKE_dsbgvd_work( int matrix_order, char jobz, char uplo,
                                lapack_int n, lapack_int ka, lapack_int kb,
                                double* ab, lapack_int ldab, double* bb,
                                lapack_int ldbb, double* w, double* z,
                                lapack_int ldz, double* work, lapack_int lwork,
                                lapack_int* iwork, lapack_int liwork );

lapack_int LAPACKE_ssbgvx_work( int matrix_order, char jobz, char range,
                                char uplo, lapack_int n, lapack_int ka,
                                lapack_int kb, float* ab, lapack_int ldab,
                                float* bb, lapack_int ldbb, float* q,
                                lapack_int ldq, float vl, float vu,
                                lapack_int il, lapack_int iu, float abstol,
                                lapack_int* m, float* w, float* z,
                                lapack_int ldz, float* work, lapack_int* iwork,
                                lapack_int* ifail );
lapack_int LAPACKE_dsbgvx_work( int matrix_order, char jobz, char range,
                                char uplo, lapack_int n, lapack_int ka,
                                lapack_int kb, double* ab, lapack_int ldab,
                                double* bb, lapack_int ldbb, double* q,
                                lapack_int ldq, double vl, double vu,
                                lapack_int il, lapack_int iu, double abstol,
                                lapack_int* m, double* w, double* z,
                                lapack_int ldz, double* work, lapack_int* iwork,
                                lapack_int* ifail );

lapack_int LAPACKE_ssbtrd_work( int matrix_order, char vect, char uplo,
                                lapack_int n, lapack_int kd, float* ab,
                                lapack_int ldab, float* d, float* e, float* q,
                                lapack_int ldq, float* work );
lapack_int LAPACKE_dsbtrd_work( int matrix_order, char vect, char uplo,
                                lapack_int n, lapack_int kd, double* ab,
                                lapack_int ldab, double* d, double* e,
                                double* q, lapack_int ldq, double* work );

lapack_int LAPACKE_ssfrk_work( int matrix_order, char transr, char uplo,
                               char trans, lapack_int n, lapack_int k,
                               float alpha, const float* a, lapack_int lda,
                               float beta, float* c );
lapack_int LAPACKE_dsfrk_work( int matrix_order, char transr, char uplo,
                               char trans, lapack_int n, lapack_int k,
                               double alpha, const double* a, lapack_int lda,
                               double beta, double* c );

lapack_int LAPACKE_sspcon_work( int matrix_order, char uplo, lapack_int n,
                                const float* ap, const lapack_int* ipiv,
                                float anorm, float* rcond, float* work,
                                lapack_int* iwork );
lapack_int LAPACKE_dspcon_work( int matrix_order, char uplo, lapack_int n,
                                const double* ap, const lapack_int* ipiv,
                                double anorm, double* rcond, double* work,
                                lapack_int* iwork );
lapack_int LAPACKE_cspcon_work( int matrix_order, char uplo, lapack_int n,
                                const lapack_complex_float* ap,
                                const lapack_int* ipiv, float anorm,
                                float* rcond, lapack_complex_float* work );
lapack_int LAPACKE_zspcon_work( int matrix_order, char uplo, lapack_int n,
                                const lapack_complex_double* ap,
                                const lapack_int* ipiv, double anorm,
                                double* rcond, lapack_complex_double* work );

lapack_int LAPACKE_sspev_work( int matrix_order, char jobz, char uplo,
                               lapack_int n, float* ap, float* w, float* z,
                               lapack_int ldz, float* work );
lapack_int LAPACKE_dspev_work( int matrix_order, char jobz, char uplo,
                               lapack_int n, double* ap, double* w, double* z,
                               lapack_int ldz, double* work );

lapack_int LAPACKE_sspevd_work( int matrix_order, char jobz, char uplo,
                                lapack_int n, float* ap, float* w, float* z,
                                lapack_int ldz, float* work, lapack_int lwork,
                                lapack_int* iwork, lapack_int liwork );
lapack_int LAPACKE_dspevd_work( int matrix_order, char jobz, char uplo,
                                lapack_int n, double* ap, double* w, double* z,
                                lapack_int ldz, double* work, lapack_int lwork,
                                lapack_int* iwork, lapack_int liwork );

lapack_int LAPACKE_sspevx_work( int matrix_order, char jobz, char range,
                                char uplo, lapack_int n, float* ap, float vl,
                                float vu, lapack_int il, lapack_int iu,
                                float abstol, lapack_int* m, float* w, float* z,
                                lapack_int ldz, float* work, lapack_int* iwork,
                                lapack_int* ifail );
lapack_int LAPACKE_dspevx_work( int matrix_order, char jobz, char range,
                                char uplo, lapack_int n, double* ap, double vl,
                                double vu, lapack_int il, lapack_int iu,
                                double abstol, lapack_int* m, double* w,
                                double* z, lapack_int ldz, double* work,
                                lapack_int* iwork, lapack_int* ifail );

lapack_int LAPACKE_sspgst_work( int matrix_order, lapack_int itype, char uplo,
                                lapack_int n, float* ap, const float* bp );
lapack_int LAPACKE_dspgst_work( int matrix_order, lapack_int itype, char uplo,
                                lapack_int n, double* ap, const double* bp );

lapack_int LAPACKE_sspgv_work( int matrix_order, lapack_int itype, char jobz,
                               char uplo, lapack_int n, float* ap, float* bp,
                               float* w, float* z, lapack_int ldz,
                               float* work );
lapack_int LAPACKE_dspgv_work( int matrix_order, lapack_int itype, char jobz,
                               char uplo, lapack_int n, double* ap, double* bp,
                               double* w, double* z, lapack_int ldz,
                               double* work );

lapack_int LAPACKE_sspgvd_work( int matrix_order, lapack_int itype, char jobz,
                                char uplo, lapack_int n, float* ap, float* bp,
                                float* w, float* z, lapack_int ldz, float* work,
                                lapack_int lwork, lapack_int* iwork,
                                lapack_int liwork );
lapack_int LAPACKE_dspgvd_work( int matrix_order, lapack_int itype, char jobz,
                                char uplo, lapack_int n, double* ap, double* bp,
                                double* w, double* z, lapack_int ldz,
                                double* work, lapack_int lwork,
                                lapack_int* iwork, lapack_int liwork );

lapack_int LAPACKE_sspgvx_work( int matrix_order, lapack_int itype, char jobz,
                                char range, char uplo, lapack_int n, float* ap,
                                float* bp, float vl, float vu, lapack_int il,
                                lapack_int iu, float abstol, lapack_int* m,
                                float* w, float* z, lapack_int ldz, float* work,
                                lapack_int* iwork, lapack_int* ifail );
lapack_int LAPACKE_dspgvx_work( int matrix_order, lapack_int itype, char jobz,
                                char range, char uplo, lapack_int n, double* ap,
                                double* bp, double vl, double vu, lapack_int il,
                                lapack_int iu, double abstol, lapack_int* m,
                                double* w, double* z, lapack_int ldz,
                                double* work, lapack_int* iwork,
                                lapack_int* ifail );

lapack_int LAPACKE_ssprfs_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int nrhs, const float* ap,
                                const float* afp, const lapack_int* ipiv,
                                const float* b, lapack_int ldb, float* x,
                                lapack_int ldx, float* ferr, float* berr,
                                float* work, lapack_int* iwork );
lapack_int LAPACKE_dsprfs_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int nrhs, const double* ap,
                                const double* afp, const lapack_int* ipiv,
                                const double* b, lapack_int ldb, double* x,
                                lapack_int ldx, double* ferr, double* berr,
                                double* work, lapack_int* iwork );
lapack_int LAPACKE_csprfs_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int nrhs, const lapack_complex_float* ap,
                                const lapack_complex_float* afp,
                                const lapack_int* ipiv,
                                const lapack_complex_float* b, lapack_int ldb,
                                lapack_complex_float* x, lapack_int ldx,
                                float* ferr, float* berr,
                                lapack_complex_float* work, float* rwork );
lapack_int LAPACKE_zsprfs_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int nrhs,
                                const lapack_complex_double* ap,
                                const lapack_complex_double* afp,
                                const lapack_int* ipiv,
                                const lapack_complex_double* b, lapack_int ldb,
                                lapack_complex_double* x, lapack_int ldx,
                                double* ferr, double* berr,
                                lapack_complex_double* work, double* rwork );

lapack_int LAPACKE_sspsv_work( int matrix_order, char uplo, lapack_int n,
                               lapack_int nrhs, float* ap, lapack_int* ipiv,
                               float* b, lapack_int ldb );
lapack_int LAPACKE_dspsv_work( int matrix_order, char uplo, lapack_int n,
                               lapack_int nrhs, double* ap, lapack_int* ipiv,
                               double* b, lapack_int ldb );
lapack_int LAPACKE_cspsv_work( int matrix_order, char uplo, lapack_int n,
                               lapack_int nrhs, lapack_complex_float* ap,
                               lapack_int* ipiv, lapack_complex_float* b,
                               lapack_int ldb );
lapack_int LAPACKE_zspsv_work( int matrix_order, char uplo, lapack_int n,
                               lapack_int nrhs, lapack_complex_double* ap,
                               lapack_int* ipiv, lapack_complex_double* b,
                               lapack_int ldb );

lapack_int LAPACKE_sspsvx_work( int matrix_order, char fact, char uplo,
                                lapack_int n, lapack_int nrhs, const float* ap,
                                float* afp, lapack_int* ipiv, const float* b,
                                lapack_int ldb, float* x, lapack_int ldx,
                                float* rcond, float* ferr, float* berr,
                                float* work, lapack_int* iwork );
lapack_int LAPACKE_dspsvx_work( int matrix_order, char fact, char uplo,
                                lapack_int n, lapack_int nrhs, const double* ap,
                                double* afp, lapack_int* ipiv, const double* b,
                                lapack_int ldb, double* x, lapack_int ldx,
                                double* rcond, double* ferr, double* berr,
                                double* work, lapack_int* iwork );
lapack_int LAPACKE_cspsvx_work( int matrix_order, char fact, char uplo,
                                lapack_int n, lapack_int nrhs,
                                const lapack_complex_float* ap,
                                lapack_complex_float* afp, lapack_int* ipiv,
                                const lapack_complex_float* b, lapack_int ldb,
                                lapack_complex_float* x, lapack_int ldx,
                                float* rcond, float* ferr, float* berr,
                                lapack_complex_float* work, float* rwork );
lapack_int LAPACKE_zspsvx_work( int matrix_order, char fact, char uplo,
                                lapack_int n, lapack_int nrhs,
                                const lapack_complex_double* ap,
                                lapack_complex_double* afp, lapack_int* ipiv,
                                const lapack_complex_double* b, lapack_int ldb,
                                lapack_complex_double* x, lapack_int ldx,
                                double* rcond, double* ferr, double* berr,
                                lapack_complex_double* work, double* rwork );

lapack_int LAPACKE_ssptrd_work( int matrix_order, char uplo, lapack_int n,
                                float* ap, float* d, float* e, float* tau );
lapack_int LAPACKE_dsptrd_work( int matrix_order, char uplo, lapack_int n,
                                double* ap, double* d, double* e, double* tau );

lapack_int LAPACKE_ssptrf_work( int matrix_order, char uplo, lapack_int n,
                                float* ap, lapack_int* ipiv );
lapack_int LAPACKE_dsptrf_work( int matrix_order, char uplo, lapack_int n,
                                double* ap, lapack_int* ipiv );
lapack_int LAPACKE_csptrf_work( int matrix_order, char uplo, lapack_int n,
                                lapack_complex_float* ap, lapack_int* ipiv );
lapack_int LAPACKE_zsptrf_work( int matrix_order, char uplo, lapack_int n,
                                lapack_complex_double* ap, lapack_int* ipiv );

lapack_int LAPACKE_ssptri_work( int matrix_order, char uplo, lapack_int n,
                                float* ap, const lapack_int* ipiv,
                                float* work );
lapack_int LAPACKE_dsptri_work( int matrix_order, char uplo, lapack_int n,
                                double* ap, const lapack_int* ipiv,
                                double* work );
lapack_int LAPACKE_csptri_work( int matrix_order, char uplo, lapack_int n,
                                lapack_complex_float* ap,
                                const lapack_int* ipiv,
                                lapack_complex_float* work );
lapack_int LAPACKE_zsptri_work( int matrix_order, char uplo, lapack_int n,
                                lapack_complex_double* ap,
                                const lapack_int* ipiv,
                                lapack_complex_double* work );

lapack_int LAPACKE_ssptrs_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int nrhs, const float* ap,
                                const lapack_int* ipiv, float* b,
                                lapack_int ldb );
lapack_int LAPACKE_dsptrs_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int nrhs, const double* ap,
                                const lapack_int* ipiv, double* b,
                                lapack_int ldb );
lapack_int LAPACKE_csptrs_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int nrhs, const lapack_complex_float* ap,
                                const lapack_int* ipiv, lapack_complex_float* b,
                                lapack_int ldb );
lapack_int LAPACKE_zsptrs_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int nrhs,
                                const lapack_complex_double* ap,
                                const lapack_int* ipiv,
                                lapack_complex_double* b, lapack_int ldb );

lapack_int LAPACKE_sstebz_work( char range, char order, lapack_int n, float vl,
                                float vu, lapack_int il, lapack_int iu,
                                float abstol, const float* d, const float* e,
                                lapack_int* m, lapack_int* nsplit, float* w,
                                lapack_int* iblock, lapack_int* isplit,
                                float* work, lapack_int* iwork );
lapack_int LAPACKE_dstebz_work( char range, char order, lapack_int n, double vl,
                                double vu, lapack_int il, lapack_int iu,
                                double abstol, const double* d, const double* e,
                                lapack_int* m, lapack_int* nsplit, double* w,
                                lapack_int* iblock, lapack_int* isplit,
                                double* work, lapack_int* iwork );

lapack_int LAPACKE_sstedc_work( int matrix_order, char compz, lapack_int n,
                                float* d, float* e, float* z, lapack_int ldz,
                                float* work, lapack_int lwork,
                                lapack_int* iwork, lapack_int liwork );
lapack_int LAPACKE_dstedc_work( int matrix_order, char compz, lapack_int n,
                                double* d, double* e, double* z, lapack_int ldz,
                                double* work, lapack_int lwork,
                                lapack_int* iwork, lapack_int liwork );
lapack_int LAPACKE_cstedc_work( int matrix_order, char compz, lapack_int n,
                                float* d, float* e, lapack_complex_float* z,
                                lapack_int ldz, lapack_complex_float* work,
                                lapack_int lwork, float* rwork,
                                lapack_int lrwork, lapack_int* iwork,
                                lapack_int liwork );
lapack_int LAPACKE_zstedc_work( int matrix_order, char compz, lapack_int n,
                                double* d, double* e, lapack_complex_double* z,
                                lapack_int ldz, lapack_complex_double* work,
                                lapack_int lwork, double* rwork,
                                lapack_int lrwork, lapack_int* iwork,
                                lapack_int liwork );

lapack_int LAPACKE_sstegr_work( int matrix_order, char jobz, char range,
                                lapack_int n, float* d, float* e, float vl,
                                float vu, lapack_int il, lapack_int iu,
                                float abstol, lapack_int* m, float* w, float* z,
                                lapack_int ldz, lapack_int* isuppz, float* work,
                                lapack_int lwork, lapack_int* iwork,
                                lapack_int liwork );
lapack_int LAPACKE_dstegr_work( int matrix_order, char jobz, char range,
                                lapack_int n, double* d, double* e, double vl,
                                double vu, lapack_int il, lapack_int iu,
                                double abstol, lapack_int* m, double* w,
                                double* z, lapack_int ldz, lapack_int* isuppz,
                                double* work, lapack_int lwork,
                                lapack_int* iwork, lapack_int liwork );
lapack_int LAPACKE_cstegr_work( int matrix_order, char jobz, char range,
                                lapack_int n, float* d, float* e, float vl,
                                float vu, lapack_int il, lapack_int iu,
                                float abstol, lapack_int* m, float* w,
                                lapack_complex_float* z, lapack_int ldz,
                                lapack_int* isuppz, float* work,
                                lapack_int lwork, lapack_int* iwork,
                                lapack_int liwork );
lapack_int LAPACKE_zstegr_work( int matrix_order, char jobz, char range,
                                lapack_int n, double* d, double* e, double vl,
                                double vu, lapack_int il, lapack_int iu,
                                double abstol, lapack_int* m, double* w,
                                lapack_complex_double* z, lapack_int ldz,
                                lapack_int* isuppz, double* work,
                                lapack_int lwork, lapack_int* iwork,
                                lapack_int liwork );

lapack_int LAPACKE_sstein_work( int matrix_order, lapack_int n, const float* d,
                                const float* e, lapack_int m, const float* w,
                                const lapack_int* iblock,
                                const lapack_int* isplit, float* z,
                                lapack_int ldz, float* work, lapack_int* iwork,
                                lapack_int* ifailv );
lapack_int LAPACKE_dstein_work( int matrix_order, lapack_int n, const double* d,
                                const double* e, lapack_int m, const double* w,
                                const lapack_int* iblock,
                                const lapack_int* isplit, double* z,
                                lapack_int ldz, double* work, lapack_int* iwork,
                                lapack_int* ifailv );
lapack_int LAPACKE_cstein_work( int matrix_order, lapack_int n, const float* d,
                                const float* e, lapack_int m, const float* w,
                                const lapack_int* iblock,
                                const lapack_int* isplit,
                                lapack_complex_float* z, lapack_int ldz,
                                float* work, lapack_int* iwork,
                                lapack_int* ifailv );
lapack_int LAPACKE_zstein_work( int matrix_order, lapack_int n, const double* d,
                                const double* e, lapack_int m, const double* w,
                                const lapack_int* iblock,
                                const lapack_int* isplit,
                                lapack_complex_double* z, lapack_int ldz,
                                double* work, lapack_int* iwork,
                                lapack_int* ifailv );

lapack_int LAPACKE_sstemr_work( int matrix_order, char jobz, char range,
                                lapack_int n, float* d, float* e, float vl,
                                float vu, lapack_int il, lapack_int iu,
                                lapack_int* m, float* w, float* z,
                                lapack_int ldz, lapack_int nzc,
                                lapack_int* isuppz, lapack_logical* tryrac,
                                float* work, lapack_int lwork,
                                lapack_int* iwork, lapack_int liwork );
lapack_int LAPACKE_dstemr_work( int matrix_order, char jobz, char range,
                                lapack_int n, double* d, double* e, double vl,
                                double vu, lapack_int il, lapack_int iu,
                                lapack_int* m, double* w, double* z,
                                lapack_int ldz, lapack_int nzc,
                                lapack_int* isuppz, lapack_logical* tryrac,
                                double* work, lapack_int lwork,
                                lapack_int* iwork, lapack_int liwork );
lapack_int LAPACKE_cstemr_work( int matrix_order, char jobz, char range,
                                lapack_int n, float* d, float* e, float vl,
                                float vu, lapack_int il, lapack_int iu,
                                lapack_int* m, float* w,
                                lapack_complex_float* z, lapack_int ldz,
                                lapack_int nzc, lapack_int* isuppz,
                                lapack_logical* tryrac, float* work,
                                lapack_int lwork, lapack_int* iwork,
                                lapack_int liwork );
lapack_int LAPACKE_zstemr_work( int matrix_order, char jobz, char range,
                                lapack_int n, double* d, double* e, double vl,
                                double vu, lapack_int il, lapack_int iu,
                                lapack_int* m, double* w,
                                lapack_complex_double* z, lapack_int ldz,
                                lapack_int nzc, lapack_int* isuppz,
                                lapack_logical* tryrac, double* work,
                                lapack_int lwork, lapack_int* iwork,
                                lapack_int liwork );

lapack_int LAPACKE_ssteqr_work( int matrix_order, char compz, lapack_int n,
                                float* d, float* e, float* z, lapack_int ldz,
                                float* work );
lapack_int LAPACKE_dsteqr_work( int matrix_order, char compz, lapack_int n,
                                double* d, double* e, double* z, lapack_int ldz,
                                double* work );
lapack_int LAPACKE_csteqr_work( int matrix_order, char compz, lapack_int n,
                                float* d, float* e, lapack_complex_float* z,
                                lapack_int ldz, float* work );
lapack_int LAPACKE_zsteqr_work( int matrix_order, char compz, lapack_int n,
                                double* d, double* e, lapack_complex_double* z,
                                lapack_int ldz, double* work );

lapack_int LAPACKE_ssterf_work( lapack_int n, float* d, float* e );
lapack_int LAPACKE_dsterf_work( lapack_int n, double* d, double* e );

lapack_int LAPACKE_sstev_work( int matrix_order, char jobz, lapack_int n,
                               float* d, float* e, float* z, lapack_int ldz,
                               float* work );
lapack_int LAPACKE_dstev_work( int matrix_order, char jobz, lapack_int n,
                               double* d, double* e, double* z, lapack_int ldz,
                               double* work );

lapack_int LAPACKE_sstevd_work( int matrix_order, char jobz, lapack_int n,
                                float* d, float* e, float* z, lapack_int ldz,
                                float* work, lapack_int lwork,
                                lapack_int* iwork, lapack_int liwork );
lapack_int LAPACKE_dstevd_work( int matrix_order, char jobz, lapack_int n,
                                double* d, double* e, double* z, lapack_int ldz,
                                double* work, lapack_int lwork,
                                lapack_int* iwork, lapack_int liwork );

lapack_int LAPACKE_sstevr_work( int matrix_order, char jobz, char range,
                                lapack_int n, float* d, float* e, float vl,
                                float vu, lapack_int il, lapack_int iu,
                                float abstol, lapack_int* m, float* w, float* z,
                                lapack_int ldz, lapack_int* isuppz, float* work,
                                lapack_int lwork, lapack_int* iwork,
                                lapack_int liwork );
lapack_int LAPACKE_dstevr_work( int matrix_order, char jobz, char range,
                                lapack_int n, double* d, double* e, double vl,
                                double vu, lapack_int il, lapack_int iu,
                                double abstol, lapack_int* m, double* w,
                                double* z, lapack_int ldz, lapack_int* isuppz,
                                double* work, lapack_int lwork,
                                lapack_int* iwork, lapack_int liwork );

lapack_int LAPACKE_sstevx_work( int matrix_order, char jobz, char range,
                                lapack_int n, float* d, float* e, float vl,
                                float vu, lapack_int il, lapack_int iu,
                                float abstol, lapack_int* m, float* w, float* z,
                                lapack_int ldz, float* work, lapack_int* iwork,
                                lapack_int* ifail );
lapack_int LAPACKE_dstevx_work( int matrix_order, char jobz, char range,
                                lapack_int n, double* d, double* e, double vl,
                                double vu, lapack_int il, lapack_int iu,
                                double abstol, lapack_int* m, double* w,
                                double* z, lapack_int ldz, double* work,
                                lapack_int* iwork, lapack_int* ifail );

lapack_int LAPACKE_ssycon_work( int matrix_order, char uplo, lapack_int n,
                                const float* a, lapack_int lda,
                                const lapack_int* ipiv, float anorm,
                                float* rcond, float* work, lapack_int* iwork );
lapack_int LAPACKE_dsycon_work( int matrix_order, char uplo, lapack_int n,
                                const double* a, lapack_int lda,
                                const lapack_int* ipiv, double anorm,
                                double* rcond, double* work,
                                lapack_int* iwork );
lapack_int LAPACKE_csycon_work( int matrix_order, char uplo, lapack_int n,
                                const lapack_complex_float* a, lapack_int lda,
                                const lapack_int* ipiv, float anorm,
                                float* rcond, lapack_complex_float* work );
lapack_int LAPACKE_zsycon_work( int matrix_order, char uplo, lapack_int n,
                                const lapack_complex_double* a, lapack_int lda,
                                const lapack_int* ipiv, double anorm,
                                double* rcond, lapack_complex_double* work );

lapack_int LAPACKE_ssyequb_work( int matrix_order, char uplo, lapack_int n,
                                 const float* a, lapack_int lda, float* s,
                                 float* scond, float* amax, float* work );
lapack_int LAPACKE_dsyequb_work( int matrix_order, char uplo, lapack_int n,
                                 const double* a, lapack_int lda, double* s,
                                 double* scond, double* amax, double* work );
lapack_int LAPACKE_csyequb_work( int matrix_order, char uplo, lapack_int n,
                                 const lapack_complex_float* a, lapack_int lda,
                                 float* s, float* scond, float* amax,
                                 lapack_complex_float* work );
lapack_int LAPACKE_zsyequb_work( int matrix_order, char uplo, lapack_int n,
                                 const lapack_complex_double* a, lapack_int lda,
                                 double* s, double* scond, double* amax,
                                 lapack_complex_double* work );

lapack_int LAPACKE_ssyev_work( int matrix_order, char jobz, char uplo,
                               lapack_int n, float* a, lapack_int lda, float* w,
                               float* work, lapack_int lwork );
lapack_int LAPACKE_dsyev_work( int matrix_order, char jobz, char uplo,
                               lapack_int n, double* a, lapack_int lda,
                               double* w, double* work, lapack_int lwork );

lapack_int LAPACKE_ssyevd_work( int matrix_order, char jobz, char uplo,
                                lapack_int n, float* a, lapack_int lda,
                                float* w, float* work, lapack_int lwork,
                                lapack_int* iwork, lapack_int liwork );
lapack_int LAPACKE_dsyevd_work( int matrix_order, char jobz, char uplo,
                                lapack_int n, double* a, lapack_int lda,
                                double* w, double* work, lapack_int lwork,
                                lapack_int* iwork, lapack_int liwork );

lapack_int LAPACKE_ssyevr_work( int matrix_order, char jobz, char range,
                                char uplo, lapack_int n, float* a,
                                lapack_int lda, float vl, float vu,
                                lapack_int il, lapack_int iu, float abstol,
                                lapack_int* m, float* w, float* z,
                                lapack_int ldz, lapack_int* isuppz, float* work,
                                lapack_int lwork, lapack_int* iwork,
                                lapack_int liwork );
lapack_int LAPACKE_dsyevr_work( int matrix_order, char jobz, char range,
                                char uplo, lapack_int n, double* a,
                                lapack_int lda, double vl, double vu,
                                lapack_int il, lapack_int iu, double abstol,
                                lapack_int* m, double* w, double* z,
                                lapack_int ldz, lapack_int* isuppz,
                                double* work, lapack_int lwork,
                                lapack_int* iwork, lapack_int liwork );

lapack_int LAPACKE_ssyevx_work( int matrix_order, char jobz, char range,
                                char uplo, lapack_int n, float* a,
                                lapack_int lda, float vl, float vu,
                                lapack_int il, lapack_int iu, float abstol,
                                lapack_int* m, float* w, float* z,
                                lapack_int ldz, float* work, lapack_int lwork,
                                lapack_int* iwork, lapack_int* ifail );
lapack_int LAPACKE_dsyevx_work( int matrix_order, char jobz, char range,
                                char uplo, lapack_int n, double* a,
                                lapack_int lda, double vl, double vu,
                                lapack_int il, lapack_int iu, double abstol,
                                lapack_int* m, double* w, double* z,
                                lapack_int ldz, double* work, lapack_int lwork,
                                lapack_int* iwork, lapack_int* ifail );

lapack_int LAPACKE_ssygst_work( int matrix_order, lapack_int itype, char uplo,
                                lapack_int n, float* a, lapack_int lda,
                                const float* b, lapack_int ldb );
lapack_int LAPACKE_dsygst_work( int matrix_order, lapack_int itype, char uplo,
                                lapack_int n, double* a, lapack_int lda,
                                const double* b, lapack_int ldb );

lapack_int LAPACKE_ssygv_work( int matrix_order, lapack_int itype, char jobz,
                               char uplo, lapack_int n, float* a,
                               lapack_int lda, float* b, lapack_int ldb,
                               float* w, float* work, lapack_int lwork );
lapack_int LAPACKE_dsygv_work( int matrix_order, lapack_int itype, char jobz,
                               char uplo, lapack_int n, double* a,
                               lapack_int lda, double* b, lapack_int ldb,
                               double* w, double* work, lapack_int lwork );

lapack_int LAPACKE_ssygvd_work( int matrix_order, lapack_int itype, char jobz,
                                char uplo, lapack_int n, float* a,
                                lapack_int lda, float* b, lapack_int ldb,
                                float* w, float* work, lapack_int lwork,
                                lapack_int* iwork, lapack_int liwork );
lapack_int LAPACKE_dsygvd_work( int matrix_order, lapack_int itype, char jobz,
                                char uplo, lapack_int n, double* a,
                                lapack_int lda, double* b, lapack_int ldb,
                                double* w, double* work, lapack_int lwork,
                                lapack_int* iwork, lapack_int liwork );

lapack_int LAPACKE_ssygvx_work( int matrix_order, lapack_int itype, char jobz,
                                char range, char uplo, lapack_int n, float* a,
                                lapack_int lda, float* b, lapack_int ldb,
                                float vl, float vu, lapack_int il,
                                lapack_int iu, float abstol, lapack_int* m,
                                float* w, float* z, lapack_int ldz, float* work,
                                lapack_int lwork, lapack_int* iwork,
                                lapack_int* ifail );
lapack_int LAPACKE_dsygvx_work( int matrix_order, lapack_int itype, char jobz,
                                char range, char uplo, lapack_int n, double* a,
                                lapack_int lda, double* b, lapack_int ldb,
                                double vl, double vu, lapack_int il,
                                lapack_int iu, double abstol, lapack_int* m,
                                double* w, double* z, lapack_int ldz,
                                double* work, lapack_int lwork,
                                lapack_int* iwork, lapack_int* ifail );

lapack_int LAPACKE_ssyrfs_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int nrhs, const float* a, lapack_int lda,
                                const float* af, lapack_int ldaf,
                                const lapack_int* ipiv, const float* b,
                                lapack_int ldb, float* x, lapack_int ldx,
                                float* ferr, float* berr, float* work,
                                lapack_int* iwork );
lapack_int LAPACKE_dsyrfs_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int nrhs, const double* a,
                                lapack_int lda, const double* af,
                                lapack_int ldaf, const lapack_int* ipiv,
                                const double* b, lapack_int ldb, double* x,
                                lapack_int ldx, double* ferr, double* berr,
                                double* work, lapack_int* iwork );
lapack_int LAPACKE_csyrfs_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int nrhs, const lapack_complex_float* a,
                                lapack_int lda, const lapack_complex_float* af,
                                lapack_int ldaf, const lapack_int* ipiv,
                                const lapack_complex_float* b, lapack_int ldb,
                                lapack_complex_float* x, lapack_int ldx,
                                float* ferr, float* berr,
                                lapack_complex_float* work, float* rwork );
lapack_int LAPACKE_zsyrfs_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int nrhs, const lapack_complex_double* a,
                                lapack_int lda, const lapack_complex_double* af,
                                lapack_int ldaf, const lapack_int* ipiv,
                                const lapack_complex_double* b, lapack_int ldb,
                                lapack_complex_double* x, lapack_int ldx,
                                double* ferr, double* berr,
                                lapack_complex_double* work, double* rwork );

lapack_int LAPACKE_ssyrfsx_work( int matrix_order, char uplo, char equed,
                                 lapack_int n, lapack_int nrhs, const float* a,
                                 lapack_int lda, const float* af,
                                 lapack_int ldaf, const lapack_int* ipiv,
                                 const float* s, const float* b, lapack_int ldb,
                                 float* x, lapack_int ldx, float* rcond,
                                 float* berr, lapack_int n_err_bnds,
                                 float* err_bnds_norm, float* err_bnds_comp,
                                 lapack_int nparams, float* params, float* work,
                                 lapack_int* iwork );
lapack_int LAPACKE_dsyrfsx_work( int matrix_order, char uplo, char equed,
                                 lapack_int n, lapack_int nrhs, const double* a,
                                 lapack_int lda, const double* af,
                                 lapack_int ldaf, const lapack_int* ipiv,
                                 const double* s, const double* b,
                                 lapack_int ldb, double* x, lapack_int ldx,
                                 double* rcond, double* berr,
                                 lapack_int n_err_bnds, double* err_bnds_norm,
                                 double* err_bnds_comp, lapack_int nparams,
                                 double* params, double* work,
                                 lapack_int* iwork );
lapack_int LAPACKE_csyrfsx_work( int matrix_order, char uplo, char equed,
                                 lapack_int n, lapack_int nrhs,
                                 const lapack_complex_float* a, lapack_int lda,
                                 const lapack_complex_float* af,
                                 lapack_int ldaf, const lapack_int* ipiv,
                                 const float* s, const lapack_complex_float* b,
                                 lapack_int ldb, lapack_complex_float* x,
                                 lapack_int ldx, float* rcond, float* berr,
                                 lapack_int n_err_bnds, float* err_bnds_norm,
                                 float* err_bnds_comp, lapack_int nparams,
                                 float* params, lapack_complex_float* work,
                                 float* rwork );
lapack_int LAPACKE_zsyrfsx_work( int matrix_order, char uplo, char equed,
                                 lapack_int n, lapack_int nrhs,
                                 const lapack_complex_double* a, lapack_int lda,
                                 const lapack_complex_double* af,
                                 lapack_int ldaf, const lapack_int* ipiv,
                                 const double* s,
                                 const lapack_complex_double* b, lapack_int ldb,
                                 lapack_complex_double* x, lapack_int ldx,
                                 double* rcond, double* berr,
                                 lapack_int n_err_bnds, double* err_bnds_norm,
                                 double* err_bnds_comp, lapack_int nparams,
                                 double* params, lapack_complex_double* work,
                                 double* rwork );

lapack_int LAPACKE_ssysv_work( int matrix_order, char uplo, lapack_int n,
                               lapack_int nrhs, float* a, lapack_int lda,
                               lapack_int* ipiv, float* b, lapack_int ldb,
                               float* work, lapack_int lwork );
lapack_int LAPACKE_dsysv_work( int matrix_order, char uplo, lapack_int n,
                               lapack_int nrhs, double* a, lapack_int lda,
                               lapack_int* ipiv, double* b, lapack_int ldb,
                               double* work, lapack_int lwork );
lapack_int LAPACKE_csysv_work( int matrix_order, char uplo, lapack_int n,
                               lapack_int nrhs, lapack_complex_float* a,
                               lapack_int lda, lapack_int* ipiv,
                               lapack_complex_float* b, lapack_int ldb,
                               lapack_complex_float* work, lapack_int lwork );
lapack_int LAPACKE_zsysv_work( int matrix_order, char uplo, lapack_int n,
                               lapack_int nrhs, lapack_complex_double* a,
                               lapack_int lda, lapack_int* ipiv,
                               lapack_complex_double* b, lapack_int ldb,
                               lapack_complex_double* work, lapack_int lwork );

lapack_int LAPACKE_ssysvx_work( int matrix_order, char fact, char uplo,
                                lapack_int n, lapack_int nrhs, const float* a,
                                lapack_int lda, float* af, lapack_int ldaf,
                                lapack_int* ipiv, const float* b,
                                lapack_int ldb, float* x, lapack_int ldx,
                                float* rcond, float* ferr, float* berr,
                                float* work, lapack_int lwork,
                                lapack_int* iwork );
lapack_int LAPACKE_dsysvx_work( int matrix_order, char fact, char uplo,
                                lapack_int n, lapack_int nrhs, const double* a,
                                lapack_int lda, double* af, lapack_int ldaf,
                                lapack_int* ipiv, const double* b,
                                lapack_int ldb, double* x, lapack_int ldx,
                                double* rcond, double* ferr, double* berr,
                                double* work, lapack_int lwork,
                                lapack_int* iwork );
lapack_int LAPACKE_csysvx_work( int matrix_order, char fact, char uplo,
                                lapack_int n, lapack_int nrhs,
                                const lapack_complex_float* a, lapack_int lda,
                                lapack_complex_float* af, lapack_int ldaf,
                                lapack_int* ipiv, const lapack_complex_float* b,
                                lapack_int ldb, lapack_complex_float* x,
                                lapack_int ldx, float* rcond, float* ferr,
                                float* berr, lapack_complex_float* work,
                                lapack_int lwork, float* rwork );
lapack_int LAPACKE_zsysvx_work( int matrix_order, char fact, char uplo,
                                lapack_int n, lapack_int nrhs,
                                const lapack_complex_double* a, lapack_int lda,
                                lapack_complex_double* af, lapack_int ldaf,
                                lapack_int* ipiv,
                                const lapack_complex_double* b, lapack_int ldb,
                                lapack_complex_double* x, lapack_int ldx,
                                double* rcond, double* ferr, double* berr,
                                lapack_complex_double* work, lapack_int lwork,
                                double* rwork );

lapack_int LAPACKE_ssysvxx_work( int matrix_order, char fact, char uplo,
                                 lapack_int n, lapack_int nrhs, float* a,
                                 lapack_int lda, float* af, lapack_int ldaf,
                                 lapack_int* ipiv, char* equed, float* s,
                                 float* b, lapack_int ldb, float* x,
                                 lapack_int ldx, float* rcond, float* rpvgrw,
                                 float* berr, lapack_int n_err_bnds,
                                 float* err_bnds_norm, float* err_bnds_comp,
                                 lapack_int nparams, float* params, float* work,
                                 lapack_int* iwork );
lapack_int LAPACKE_dsysvxx_work( int matrix_order, char fact, char uplo,
                                 lapack_int n, lapack_int nrhs, double* a,
                                 lapack_int lda, double* af, lapack_int ldaf,
                                 lapack_int* ipiv, char* equed, double* s,
                                 double* b, lapack_int ldb, double* x,
                                 lapack_int ldx, double* rcond, double* rpvgrw,
                                 double* berr, lapack_int n_err_bnds,
                                 double* err_bnds_norm, double* err_bnds_comp,
                                 lapack_int nparams, double* params,
                                 double* work, lapack_int* iwork );
lapack_int LAPACKE_csysvxx_work( int matrix_order, char fact, char uplo,
                                 lapack_int n, lapack_int nrhs,
                                 lapack_complex_float* a, lapack_int lda,
                                 lapack_complex_float* af, lapack_int ldaf,
                                 lapack_int* ipiv, char* equed, float* s,
                                 lapack_complex_float* b, lapack_int ldb,
                                 lapack_complex_float* x, lapack_int ldx,
                                 float* rcond, float* rpvgrw, float* berr,
                                 lapack_int n_err_bnds, float* err_bnds_norm,
                                 float* err_bnds_comp, lapack_int nparams,
                                 float* params, lapack_complex_float* work,
                                 float* rwork );
lapack_int LAPACKE_zsysvxx_work( int matrix_order, char fact, char uplo,
                                 lapack_int n, lapack_int nrhs,
                                 lapack_complex_double* a, lapack_int lda,
                                 lapack_complex_double* af, lapack_int ldaf,
                                 lapack_int* ipiv, char* equed, double* s,
                                 lapack_complex_double* b, lapack_int ldb,
                                 lapack_complex_double* x, lapack_int ldx,
                                 double* rcond, double* rpvgrw, double* berr,
                                 lapack_int n_err_bnds, double* err_bnds_norm,
                                 double* err_bnds_comp, lapack_int nparams,
                                 double* params, lapack_complex_double* work,
                                 double* rwork );

lapack_int LAPACKE_ssytrd_work( int matrix_order, char uplo, lapack_int n,
                                float* a, lapack_int lda, float* d, float* e,
                                float* tau, float* work, lapack_int lwork );
lapack_int LAPACKE_dsytrd_work( int matrix_order, char uplo, lapack_int n,
                                double* a, lapack_int lda, double* d, double* e,
                                double* tau, double* work, lapack_int lwork );

lapack_int LAPACKE_ssytrf_work( int matrix_order, char uplo, lapack_int n,
                                float* a, lapack_int lda, lapack_int* ipiv,
                                float* work, lapack_int lwork );
lapack_int LAPACKE_dsytrf_work( int matrix_order, char uplo, lapack_int n,
                                double* a, lapack_int lda, lapack_int* ipiv,
                                double* work, lapack_int lwork );
lapack_int LAPACKE_csytrf_work( int matrix_order, char uplo, lapack_int n,
                                lapack_complex_float* a, lapack_int lda,
                                lapack_int* ipiv, lapack_complex_float* work,
                                lapack_int lwork );
lapack_int LAPACKE_zsytrf_work( int matrix_order, char uplo, lapack_int n,
                                lapack_complex_double* a, lapack_int lda,
                                lapack_int* ipiv, lapack_complex_double* work,
                                lapack_int lwork );

lapack_int LAPACKE_ssytri_work( int matrix_order, char uplo, lapack_int n,
                                float* a, lapack_int lda,
                                const lapack_int* ipiv, float* work );
lapack_int LAPACKE_dsytri_work( int matrix_order, char uplo, lapack_int n,
                                double* a, lapack_int lda,
                                const lapack_int* ipiv, double* work );
lapack_int LAPACKE_csytri_work( int matrix_order, char uplo, lapack_int n,
                                lapack_complex_float* a, lapack_int lda,
                                const lapack_int* ipiv,
                                lapack_complex_float* work );
lapack_int LAPACKE_zsytri_work( int matrix_order, char uplo, lapack_int n,
                                lapack_complex_double* a, lapack_int lda,
                                const lapack_int* ipiv,
                                lapack_complex_double* work );

lapack_int LAPACKE_ssytrs_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int nrhs, const float* a, lapack_int lda,
                                const lapack_int* ipiv, float* b,
                                lapack_int ldb );
lapack_int LAPACKE_dsytrs_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int nrhs, const double* a,
                                lapack_int lda, const lapack_int* ipiv,
                                double* b, lapack_int ldb );
lapack_int LAPACKE_csytrs_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int nrhs, const lapack_complex_float* a,
                                lapack_int lda, const lapack_int* ipiv,
                                lapack_complex_float* b, lapack_int ldb );
lapack_int LAPACKE_zsytrs_work( int matrix_order, char uplo, lapack_int n,
                                lapack_int nrhs, const lapack_complex_double* a,
                                lapack_int lda, const lapack_int* ipiv,
                                lapack_complex_double* b, lapack_int ldb );

lapack_int LAPACKE_stbcon_work( int matrix_order, char norm, char uplo,
                                char diag, lapack_int n, lapack_int kd,
                                const float* ab, lapack_int ldab, float* rcond,
                                float* work, lapack_int* iwork );
lapack_int LAPACKE_dtbcon_work( int matrix_order, char norm, char uplo,
                                char diag, lapack_int n, lapack_int kd,
                                const double* ab, lapack_int ldab,
                                double* rcond, double* work,
                                lapack_int* iwork );
lapack_int LAPACKE_ctbcon_work( int matrix_order, char norm, char uplo,
                                char diag, lapack_int n, lapack_int kd,
                                const lapack_complex_float* ab, lapack_int ldab,
                                float* rcond, lapack_complex_float* work,
                                float* rwork );
lapack_int LAPACKE_ztbcon_work( int matrix_order, char norm, char uplo,
                                char diag, lapack_int n, lapack_int kd,
                                const lapack_complex_double* ab,
                                lapack_int ldab, double* rcond,
                                lapack_complex_double* work, double* rwork );

lapack_int LAPACKE_stbrfs_work( int matrix_order, char uplo, char trans,
                                char diag, lapack_int n, lapack_int kd,
                                lapack_int nrhs, const float* ab,
                                lapack_int ldab, const float* b, lapack_int ldb,
                                const float* x, lapack_int ldx, float* ferr,
                                float* berr, float* work, lapack_int* iwork );
lapack_int LAPACKE_dtbrfs_work( int matrix_order, char uplo, char trans,
                                char diag, lapack_int n, lapack_int kd,
                                lapack_int nrhs, const double* ab,
                                lapack_int ldab, const double* b,
                                lapack_int ldb, const double* x, lapack_int ldx,
                                double* ferr, double* berr, double* work,
                                lapack_int* iwork );
lapack_int LAPACKE_ctbrfs_work( int matrix_order, char uplo, char trans,
                                char diag, lapack_int n, lapack_int kd,
                                lapack_int nrhs, const lapack_complex_float* ab,
                                lapack_int ldab, const lapack_complex_float* b,
                                lapack_int ldb, const lapack_complex_float* x,
                                lapack_int ldx, float* ferr, float* berr,
                                lapack_complex_float* work, float* rwork );
lapack_int LAPACKE_ztbrfs_work( int matrix_order, char uplo, char trans,
                                char diag, lapack_int n, lapack_int kd,
                                lapack_int nrhs,
                                const lapack_complex_double* ab,
                                lapack_int ldab, const lapack_complex_double* b,
                                lapack_int ldb, const lapack_complex_double* x,
                                lapack_int ldx, double* ferr, double* berr,
                                lapack_complex_double* work, double* rwork );

lapack_int LAPACKE_stbtrs_work( int matrix_order, char uplo, char trans,
                                char diag, lapack_int n, lapack_int kd,
                                lapack_int nrhs, const float* ab,
                                lapack_int ldab, float* b, lapack_int ldb );
lapack_int LAPACKE_dtbtrs_work( int matrix_order, char uplo, char trans,
                                char diag, lapack_int n, lapack_int kd,
                                lapack_int nrhs, const double* ab,
                                lapack_int ldab, double* b, lapack_int ldb );
lapack_int LAPACKE_ctbtrs_work( int matrix_order, char uplo, char trans,
                                char diag, lapack_int n, lapack_int kd,
                                lapack_int nrhs, const lapack_complex_float* ab,
                                lapack_int ldab, lapack_complex_float* b,
                                lapack_int ldb );
lapack_int LAPACKE_ztbtrs_work( int matrix_order, char uplo, char trans,
                                char diag, lapack_int n, lapack_int kd,
                                lapack_int nrhs,
                                const lapack_complex_double* ab,
                                lapack_int ldab, lapack_complex_double* b,
                                lapack_int ldb );

lapack_int LAPACKE_stfsm_work( int matrix_order, char transr, char side,
                               char uplo, char trans, char diag, lapack_int m,
                               lapack_int n, float alpha, const float* a,
                               float* b, lapack_int ldb );
lapack_int LAPACKE_dtfsm_work( int matrix_order, char transr, char side,
                               char uplo, char trans, char diag, lapack_int m,
                               lapack_int n, double alpha, const double* a,
                               double* b, lapack_int ldb );
lapack_int LAPACKE_ctfsm_work( int matrix_order, char transr, char side,
                               char uplo, char trans, char diag, lapack_int m,
                               lapack_int n, lapack_complex_float alpha,
                               const lapack_complex_float* a,
                               lapack_complex_float* b, lapack_int ldb );
lapack_int LAPACKE_ztfsm_work( int matrix_order, char transr, char side,
                               char uplo, char trans, char diag, lapack_int m,
                               lapack_int n, lapack_complex_double alpha,
                               const lapack_complex_double* a,
                               lapack_complex_double* b, lapack_int ldb );

lapack_int LAPACKE_stftri_work( int matrix_order, char transr, char uplo,
                                char diag, lapack_int n, float* a );
lapack_int LAPACKE_dtftri_work( int matrix_order, char transr, char uplo,
                                char diag, lapack_int n, double* a );
lapack_int LAPACKE_ctftri_work( int matrix_order, char transr, char uplo,
                                char diag, lapack_int n,
                                lapack_complex_float* a );
lapack_int LAPACKE_ztftri_work( int matrix_order, char transr, char uplo,
                                char diag, lapack_int n,
                                lapack_complex_double* a );

lapack_int LAPACKE_stfttp_work( int matrix_order, char transr, char uplo,
                                lapack_int n, const float* arf, float* ap );
lapack_int LAPACKE_dtfttp_work( int matrix_order, char transr, char uplo,
                                lapack_int n, const double* arf, double* ap );
lapack_int LAPACKE_ctfttp_work( int matrix_order, char transr, char uplo,
                                lapack_int n, const lapack_complex_float* arf,
                                lapack_complex_float* ap );
lapack_int LAPACKE_ztfttp_work( int matrix_order, char transr, char uplo,
                                lapack_int n, const lapack_complex_double* arf,
                                lapack_complex_double* ap );

lapack_int LAPACKE_stfttr_work( int matrix_order, char transr, char uplo,
                                lapack_int n, const float* arf, float* a,
                                lapack_int lda );
lapack_int LAPACKE_dtfttr_work( int matrix_order, char transr, char uplo,
                                lapack_int n, const double* arf, double* a,
                                lapack_int lda );
lapack_int LAPACKE_ctfttr_work( int matrix_order, char transr, char uplo,
                                lapack_int n, const lapack_complex_float* arf,
                                lapack_complex_float* a, lapack_int lda );
lapack_int LAPACKE_ztfttr_work( int matrix_order, char transr, char uplo,
                                lapack_int n, const lapack_complex_double* arf,
                                lapack_complex_double* a, lapack_int lda );

lapack_int LAPACKE_stgevc_work( int matrix_order, char side, char howmny,
                                const lapack_logical* select, lapack_int n,
                                const float* s, lapack_int lds, const float* p,
                                lapack_int ldp, float* vl, lapack_int ldvl,
                                float* vr, lapack_int ldvr, lapack_int mm,
                                lapack_int* m, float* work );
lapack_int LAPACKE_dtgevc_work( int matrix_order, char side, char howmny,
                                const lapack_logical* select, lapack_int n,
                                const double* s, lapack_int lds,
                                const double* p, lapack_int ldp, double* vl,
                                lapack_int ldvl, double* vr, lapack_int ldvr,
                                lapack_int mm, lapack_int* m, double* work );
lapack_int LAPACKE_ctgevc_work( int matrix_order, char side, char howmny,
                                const lapack_logical* select, lapack_int n,
                                const lapack_complex_float* s, lapack_int lds,
                                const lapack_complex_float* p, lapack_int ldp,
                                lapack_complex_float* vl, lapack_int ldvl,
                                lapack_complex_float* vr, lapack_int ldvr,
                                lapack_int mm, lapack_int* m,
                                lapack_complex_float* work, float* rwork );
lapack_int LAPACKE_ztgevc_work( int matrix_order, char side, char howmny,
                                const lapack_logical* select, lapack_int n,
                                const lapack_complex_double* s, lapack_int lds,
                                const lapack_complex_double* p, lapack_int ldp,
                                lapack_complex_double* vl, lapack_int ldvl,
                                lapack_complex_double* vr, lapack_int ldvr,
                                lapack_int mm, lapack_int* m,
                                lapack_complex_double* work, double* rwork );

lapack_int LAPACKE_stgexc_work( int matrix_order, lapack_logical wantq,
                                lapack_logical wantz, lapack_int n, float* a,
                                lapack_int lda, float* b, lapack_int ldb,
                                float* q, lapack_int ldq, float* z,
                                lapack_int ldz, lapack_int* ifst,
                                lapack_int* ilst, float* work,
                                lapack_int lwork );
lapack_int LAPACKE_dtgexc_work( int matrix_order, lapack_logical wantq,
                                lapack_logical wantz, lapack_int n, double* a,
                                lapack_int lda, double* b, lapack_int ldb,
                                double* q, lapack_int ldq, double* z,
                                lapack_int ldz, lapack_int* ifst,
                                lapack_int* ilst, double* work,
                                lapack_int lwork );
lapack_int LAPACKE_ctgexc_work( int matrix_order, lapack_logical wantq,
                                lapack_logical wantz, lapack_int n,
                                lapack_complex_float* a, lapack_int lda,
                                lapack_complex_float* b, lapack_int ldb,
                                lapack_complex_float* q, lapack_int ldq,
                                lapack_complex_float* z, lapack_int ldz,
                                lapack_int ifst, lapack_int ilst );
lapack_int LAPACKE_ztgexc_work( int matrix_order, lapack_logical wantq,
                                lapack_logical wantz, lapack_int n,
                                lapack_complex_double* a, lapack_int lda,
                                lapack_complex_double* b, lapack_int ldb,
                                lapack_complex_double* q, lapack_int ldq,
                                lapack_complex_double* z, lapack_int ldz,
                                lapack_int ifst, lapack_int ilst );

lapack_int LAPACKE_stgsen_work( int matrix_order, lapack_int ijob,
                                lapack_logical wantq, lapack_logical wantz,
                                const lapack_logical* select, lapack_int n,
                                float* a, lapack_int lda, float* b,
                                lapack_int ldb, float* alphar, float* alphai,
                                float* beta, float* q, lapack_int ldq, float* z,
                                lapack_int ldz, lapack_int* m, float* pl,
                                float* pr, float* dif, float* work,
                                lapack_int lwork, lapack_int* iwork,
                                lapack_int liwork );
lapack_int LAPACKE_dtgsen_work( int matrix_order, lapack_int ijob,
                                lapack_logical wantq, lapack_logical wantz,
                                const lapack_logical* select, lapack_int n,
                                double* a, lapack_int lda, double* b,
                                lapack_int ldb, double* alphar, double* alphai,
                                double* beta, double* q, lapack_int ldq,
                                double* z, lapack_int ldz, lapack_int* m,
                                double* pl, double* pr, double* dif,
                                double* work, lapack_int lwork,
                                lapack_int* iwork, lapack_int liwork );
lapack_int LAPACKE_ctgsen_work( int matrix_order, lapack_int ijob,
                                lapack_logical wantq, lapack_logical wantz,
                                const lapack_logical* select, lapack_int n,
                                lapack_complex_float* a, lapack_int lda,
                                lapack_complex_float* b, lapack_int ldb,
                                lapack_complex_float* alpha,
                                lapack_complex_float* beta,
                                lapack_complex_float* q, lapack_int ldq,
                                lapack_complex_float* z, lapack_int ldz,
                                lapack_int* m, float* pl, float* pr, float* dif,
                                lapack_complex_float* work, lapack_int lwork,
                                lapack_int* iwork, lapack_int liwork );
lapack_int LAPACKE_ztgsen_work( int matrix_order, lapack_int ijob,
                                lapack_logical wantq, lapack_logical wantz,
                                const lapack_logical* select, lapack_int n,
                                lapack_complex_double* a, lapack_int lda,
                                lapack_complex_double* b, lapack_int ldb,
                                lapack_complex_double* alpha,
                                lapack_complex_double* beta,
                                lapack_complex_double* q, lapack_int ldq,
                                lapack_complex_double* z, lapack_int ldz,
                                lapack_int* m, double* pl, double* pr,
                                double* dif, lapack_complex_double* work,
                                lapack_int lwork, lapack_int* iwork,
                                lapack_int liwork );

lapack_int LAPACKE_stgsja_work( int matrix_order, char jobu, char jobv,
                                char jobq, lapack_int m, lapack_int p,
                                lapack_int n, lapack_int k, lapack_int l,
                                float* a, lapack_int lda, float* b,
                                lapack_int ldb, float tola, float tolb,
                                float* alpha, float* beta, float* u,
                                lapack_int ldu, float* v, lapack_int ldv,
                                float* q, lapack_int ldq, float* work,
                                lapack_int* ncycle );
lapack_int LAPACKE_dtgsja_work( int matrix_order, char jobu, char jobv,
                                char jobq, lapack_int m, lapack_int p,
                                lapack_int n, lapack_int k, lapack_int l,
                                double* a, lapack_int lda, double* b,
                                lapack_int ldb, double tola, double tolb,
                                double* alpha, double* beta, double* u,
                                lapack_int ldu, double* v, lapack_int ldv,
                                double* q, lapack_int ldq, double* work,
                                lapack_int* ncycle );
lapack_int LAPACKE_ctgsja_work( int matrix_order, char jobu, char jobv,
                                char jobq, lapack_int m, lapack_int p,
                                lapack_int n, lapack_int k, lapack_int l,
                                lapack_complex_float* a, lapack_int lda,
                                lapack_complex_float* b, lapack_int ldb,
                                float tola, float tolb, float* alpha,
                                float* beta, lapack_complex_float* u,
                                lapack_int ldu, lapack_complex_float* v,
                                lapack_int ldv, lapack_complex_float* q,
                                lapack_int ldq, lapack_complex_float* work,
                                lapack_int* ncycle );
lapack_int LAPACKE_ztgsja_work( int matrix_order, char jobu, char jobv,
                                char jobq, lapack_int m, lapack_int p,
                                lapack_int n, lapack_int k, lapack_int l,
                                lapack_complex_double* a, lapack_int lda,
                                lapack_complex_double* b, lapack_int ldb,
                                double tola, double tolb, double* alpha,
                                double* beta, lapack_complex_double* u,
                                lapack_int ldu, lapack_complex_double* v,
                                lapack_int ldv, lapack_complex_double* q,
                                lapack_int ldq, lapack_complex_double* work,
                                lapack_int* ncycle );

lapack_int LAPACKE_stgsna_work( int matrix_order, char job, char howmny,
                                const lapack_logical* select, lapack_int n,
                                const float* a, lapack_int lda, const float* b,
                                lapack_int ldb, const float* vl,
                                lapack_int ldvl, const float* vr,
                                lapack_int ldvr, float* s, float* dif,
                                lapack_int mm, lapack_int* m, float* work,
                                lapack_int lwork, lapack_int* iwork );
lapack_int LAPACKE_dtgsna_work( int matrix_order, char job, char howmny,
                                const lapack_logical* select, lapack_int n,
                                const double* a, lapack_int lda,
                                const double* b, lapack_int ldb,
                                const double* vl, lapack_int ldvl,
                                const double* vr, lapack_int ldvr, double* s,
                                double* dif, lapack_int mm, lapack_int* m,
                                double* work, lapack_int lwork,
                                lapack_int* iwork );
lapack_int LAPACKE_ctgsna_work( int matrix_order, char job, char howmny,
                                const lapack_logical* select, lapack_int n,
                                const lapack_complex_float* a, lapack_int lda,
                                const lapack_complex_float* b, lapack_int ldb,
                                const lapack_complex_float* vl, lapack_int ldvl,
                                const lapack_complex_float* vr, lapack_int ldvr,
                                float* s, float* dif, lapack_int mm,
                                lapack_int* m, lapack_complex_float* work,
                                lapack_int lwork, lapack_int* iwork );
lapack_int LAPACKE_ztgsna_work( int matrix_order, char job, char howmny,
                                const lapack_logical* select, lapack_int n,
                                const lapack_complex_double* a, lapack_int lda,
                                const lapack_complex_double* b, lapack_int ldb,
                                const lapack_complex_double* vl,
                                lapack_int ldvl,
                                const lapack_complex_double* vr,
                                lapack_int ldvr, double* s, double* dif,
                                lapack_int mm, lapack_int* m,
                                lapack_complex_double* work, lapack_int lwork,
                                lapack_int* iwork );

lapack_int LAPACKE_stgsyl_work( int matrix_order, char trans, lapack_int ijob,
                                lapack_int m, lapack_int n, const float* a,
                                lapack_int lda, const float* b, lapack_int ldb,
                                float* c, lapack_int ldc, const float* d,
                                lapack_int ldd, const float* e, lapack_int lde,
                                float* f, lapack_int ldf, float* scale,
                                float* dif, float* work, lapack_int lwork,
                                lapack_int* iwork );
lapack_int LAPACKE_dtgsyl_work( int matrix_order, char trans, lapack_int ijob,
                                lapack_int m, lapack_int n, const double* a,
                                lapack_int lda, const double* b, lapack_int ldb,
                                double* c, lapack_int ldc, const double* d,
                                lapack_int ldd, const double* e, lapack_int lde,
                                double* f, lapack_int ldf, double* scale,
                                double* dif, double* work, lapack_int lwork,
                                lapack_int* iwork );
lapack_int LAPACKE_ctgsyl_work( int matrix_order, char trans, lapack_int ijob,
                                lapack_int m, lapack_int n,
                                const lapack_complex_float* a, lapack_int lda,
                                const lapack_complex_float* b, lapack_int ldb,
                                lapack_complex_float* c, lapack_int ldc,
                                const lapack_complex_float* d, lapack_int ldd,
                                const lapack_complex_float* e, lapack_int lde,
                                lapack_complex_float* f, lapack_int ldf,
                                float* scale, float* dif,
                                lapack_complex_float* work, lapack_int lwork,
                                lapack_int* iwork );
lapack_int LAPACKE_ztgsyl_work( int matrix_order, char trans, lapack_int ijob,
                                lapack_int m, lapack_int n,
                                const lapack_complex_double* a, lapack_int lda,
                                const lapack_complex_double* b, lapack_int ldb,
                                lapack_complex_double* c, lapack_int ldc,
                                const lapack_complex_double* d, lapack_int ldd,
                                const lapack_complex_double* e, lapack_int lde,
                                lapack_complex_double* f, lapack_int ldf,
                                double* scale, double* dif,
                                lapack_complex_double* work, lapack_int lwork,
                                lapack_int* iwork );

lapack_int LAPACKE_stpcon_work( int matrix_order, char norm, char uplo,
                                char diag, lapack_int n, const float* ap,
                                float* rcond, float* work, lapack_int* iwork );
lapack_int LAPACKE_dtpcon_work( int matrix_order, char norm, char uplo,
                                char diag, lapack_int n, const double* ap,
                                double* rcond, double* work,
                                lapack_int* iwork );
lapack_int LAPACKE_ctpcon_work( int matrix_order, char norm, char uplo,
                                char diag, lapack_int n,
                                const lapack_complex_float* ap, float* rcond,
                                lapack_complex_float* work, float* rwork );
lapack_int LAPACKE_ztpcon_work( int matrix_order, char norm, char uplo,
                                char diag, lapack_int n,
                                const lapack_complex_double* ap, double* rcond,
                                lapack_complex_double* work, double* rwork );

lapack_int LAPACKE_stprfs_work( int matrix_order, char uplo, char trans,
                                char diag, lapack_int n, lapack_int nrhs,
                                const float* ap, const float* b, lapack_int ldb,
                                const float* x, lapack_int ldx, float* ferr,
                                float* berr, float* work, lapack_int* iwork );
lapack_int LAPACKE_dtprfs_work( int matrix_order, char uplo, char trans,
                                char diag, lapack_int n, lapack_int nrhs,
                                const double* ap, const double* b,
                                lapack_int ldb, const double* x, lapack_int ldx,
                                double* ferr, double* berr, double* work,
                                lapack_int* iwork );
lapack_int LAPACKE_ctprfs_work( int matrix_order, char uplo, char trans,
                                char diag, lapack_int n, lapack_int nrhs,
                                const lapack_complex_float* ap,
                                const lapack_complex_float* b, lapack_int ldb,
                                const lapack_complex_float* x, lapack_int ldx,
                                float* ferr, float* berr,
                                lapack_complex_float* work, float* rwork );
lapack_int LAPACKE_ztprfs_work( int matrix_order, char uplo, char trans,
                                char diag, lapack_int n, lapack_int nrhs,
                                const lapack_complex_double* ap,
                                const lapack_complex_double* b, lapack_int ldb,
                                const lapack_complex_double* x, lapack_int ldx,
                                double* ferr, double* berr,
                                lapack_complex_double* work, double* rwork );

lapack_int LAPACKE_stptri_work( int matrix_order, char uplo, char diag,
                                lapack_int n, float* ap );
lapack_int LAPACKE_dtptri_work( int matrix_order, char uplo, char diag,
                                lapack_int n, double* ap );
lapack_int LAPACKE_ctptri_work( int matrix_order, char uplo, char diag,
                                lapack_int n, lapack_complex_float* ap );
lapack_int LAPACKE_ztptri_work( int matrix_order, char uplo, char diag,
                                lapack_int n, lapack_complex_double* ap );

lapack_int LAPACKE_stptrs_work( int matrix_order, char uplo, char trans,
                                char diag, lapack_int n, lapack_int nrhs,
                                const float* ap, float* b, lapack_int ldb );
lapack_int LAPACKE_dtptrs_work( int matrix_order, char uplo, char trans,
                                char diag, lapack_int n, lapack_int nrhs,
                                const double* ap, double* b, lapack_int ldb );
lapack_int LAPACKE_ctptrs_work( int matrix_order, char uplo, char trans,
                                char diag, lapack_int n, lapack_int nrhs,
                                const lapack_complex_float* ap,
                                lapack_complex_float* b, lapack_int ldb );
lapack_int LAPACKE_ztptrs_work( int matrix_order, char uplo, char trans,
                                char diag, lapack_int n, lapack_int nrhs,
                                const lapack_complex_double* ap,
                                lapack_complex_double* b, lapack_int ldb );

lapack_int LAPACKE_stpttf_work( int matrix_order, char transr, char uplo,
                                lapack_int n, const float* ap, float* arf );
lapack_int LAPACKE_dtpttf_work( int matrix_order, char transr, char uplo,
                                lapack_int n, const double* ap, double* arf );
lapack_int LAPACKE_ctpttf_work( int matrix_order, char transr, char uplo,
                                lapack_int n, const lapack_complex_float* ap,
                                lapack_complex_float* arf );
lapack_int LAPACKE_ztpttf_work( int matrix_order, char transr, char uplo,
                                lapack_int n, const lapack_complex_double* ap,
                                lapack_complex_double* arf );

lapack_int LAPACKE_stpttr_work( int matrix_order, char uplo, lapack_int n,
                                const float* ap, float* a, lapack_int lda );
lapack_int LAPACKE_dtpttr_work( int matrix_order, char uplo, lapack_int n,
                                const double* ap, double* a, lapack_int lda );
lapack_int LAPACKE_ctpttr_work( int matrix_order, char uplo, lapack_int n,
                                const lapack_complex_float* ap,
                                lapack_complex_float* a, lapack_int lda );
lapack_int LAPACKE_ztpttr_work( int matrix_order, char uplo, lapack_int n,
                                const lapack_complex_double* ap,
                                lapack_complex_double* a, lapack_int lda );

lapack_int LAPACKE_strcon_work( int matrix_order, char norm, char uplo,
                                char diag, lapack_int n, const float* a,
                                lapack_int lda, float* rcond, float* work,
                                lapack_int* iwork );
lapack_int LAPACKE_dtrcon_work( int matrix_order, char norm, char uplo,
                                char diag, lapack_int n, const double* a,
                                lapack_int lda, double* rcond, double* work,
                                lapack_int* iwork );
lapack_int LAPACKE_ctrcon_work( int matrix_order, char norm, char uplo,
                                char diag, lapack_int n,
                                const lapack_complex_float* a, lapack_int lda,
                                float* rcond, lapack_complex_float* work,
                                float* rwork );
lapack_int LAPACKE_ztrcon_work( int matrix_order, char norm, char uplo,
                                char diag, lapack_int n,
                                const lapack_complex_double* a, lapack_int lda,
                                double* rcond, lapack_complex_double* work,
                                double* rwork );

lapack_int LAPACKE_strevc_work( int matrix_order, char side, char howmny,
                                lapack_logical* select, lapack_int n,
                                const float* t, lapack_int ldt, float* vl,
                                lapack_int ldvl, float* vr, lapack_int ldvr,
                                lapack_int mm, lapack_int* m, float* work );
lapack_int LAPACKE_dtrevc_work( int matrix_order, char side, char howmny,
                                lapack_logical* select, lapack_int n,
                                const double* t, lapack_int ldt, double* vl,
                                lapack_int ldvl, double* vr, lapack_int ldvr,
                                lapack_int mm, lapack_int* m, double* work );
lapack_int LAPACKE_ctrevc_work( int matrix_order, char side, char howmny,
                                const lapack_logical* select, lapack_int n,
                                lapack_complex_float* t, lapack_int ldt,
                                lapack_complex_float* vl, lapack_int ldvl,
                                lapack_complex_float* vr, lapack_int ldvr,
                                lapack_int mm, lapack_int* m,
                                lapack_complex_float* work, float* rwork );
lapack_int LAPACKE_ztrevc_work( int matrix_order, char side, char howmny,
                                const lapack_logical* select, lapack_int n,
                                lapack_complex_double* t, lapack_int ldt,
                                lapack_complex_double* vl, lapack_int ldvl,
                                lapack_complex_double* vr, lapack_int ldvr,
                                lapack_int mm, lapack_int* m,
                                lapack_complex_double* work, double* rwork );

lapack_int LAPACKE_strexc_work( int matrix_order, char compq, lapack_int n,
                                float* t, lapack_int ldt, float* q,
                                lapack_int ldq, lapack_int* ifst,
                                lapack_int* ilst, float* work );
lapack_int LAPACKE_dtrexc_work( int matrix_order, char compq, lapack_int n,
                                double* t, lapack_int ldt, double* q,
                                lapack_int ldq, lapack_int* ifst,
                                lapack_int* ilst, double* work );
lapack_int LAPACKE_ctrexc_work( int matrix_order, char compq, lapack_int n,
                                lapack_complex_float* t, lapack_int ldt,
                                lapack_complex_float* q, lapack_int ldq,
                                lapack_int ifst, lapack_int ilst );
lapack_int LAPACKE_ztrexc_work( int matrix_order, char compq, lapack_int n,
                                lapack_complex_double* t, lapack_int ldt,
                                lapack_complex_double* q, lapack_int ldq,
                                lapack_int ifst, lapack_int ilst );

lapack_int LAPACKE_strrfs_work( int matrix_order, char uplo, char trans,
                                char diag, lapack_int n, lapack_int nrhs,
                                const float* a, lapack_int lda, const float* b,
                                lapack_int ldb, const float* x, lapack_int ldx,
                                float* ferr, float* berr, float* work,
                                lapack_int* iwork );
lapack_int LAPACKE_dtrrfs_work( int matrix_order, char uplo, char trans,
                                char diag, lapack_int n, lapack_int nrhs,
                                const double* a, lapack_int lda,
                                const double* b, lapack_int ldb,
                                const double* x, lapack_int ldx, double* ferr,
                                double* berr, double* work, lapack_int* iwork );
lapack_int LAPACKE_ctrrfs_work( int matrix_order, char uplo, char trans,
                                char diag, lapack_int n, lapack_int nrhs,
                                const lapack_complex_float* a, lapack_int lda,
                                const lapack_complex_float* b, lapack_int ldb,
                                const lapack_complex_float* x, lapack_int ldx,
                                float* ferr, float* berr,
                                lapack_complex_float* work, float* rwork );
lapack_int LAPACKE_ztrrfs_work( int matrix_order, char uplo, char trans,
                                char diag, lapack_int n, lapack_int nrhs,
                                const lapack_complex_double* a, lapack_int lda,
                                const lapack_complex_double* b, lapack_int ldb,
                                const lapack_complex_double* x, lapack_int ldx,
                                double* ferr, double* berr,
                                lapack_complex_double* work, double* rwork );

lapack_int LAPACKE_strsen_work( int matrix_order, char job, char compq,
                                const lapack_logical* select, lapack_int n,
                                float* t, lapack_int ldt, float* q,
                                lapack_int ldq, float* wr, float* wi,
                                lapack_int* m, float* s, float* sep,
                                float* work, lapack_int lwork,
                                lapack_int* iwork, lapack_int liwork );
lapack_int LAPACKE_dtrsen_work( int matrix_order, char job, char compq,
                                const lapack_logical* select, lapack_int n,
                                double* t, lapack_int ldt, double* q,
                                lapack_int ldq, double* wr, double* wi,
                                lapack_int* m, double* s, double* sep,
                                double* work, lapack_int lwork,
                                lapack_int* iwork, lapack_int liwork );
lapack_int LAPACKE_ctrsen_work( int matrix_order, char job, char compq,
                                const lapack_logical* select, lapack_int n,
                                lapack_complex_float* t, lapack_int ldt,
                                lapack_complex_float* q, lapack_int ldq,
                                lapack_complex_float* w, lapack_int* m,
                                float* s, float* sep,
                                lapack_complex_float* work, lapack_int lwork );
lapack_int LAPACKE_ztrsen_work( int matrix_order, char job, char compq,
                                const lapack_logical* select, lapack_int n,
                                lapack_complex_double* t, lapack_int ldt,
                                lapack_complex_double* q, lapack_int ldq,
                                lapack_complex_double* w, lapack_int* m,
                                double* s, double* sep,
                                lapack_complex_double* work, lapack_int lwork );

lapack_int LAPACKE_strsna_work( int matrix_order, char job, char howmny,
                                const lapack_logical* select, lapack_int n,
                                const float* t, lapack_int ldt, const float* vl,
                                lapack_int ldvl, const float* vr,
                                lapack_int ldvr, float* s, float* sep,
                                lapack_int mm, lapack_int* m, float* work,
                                lapack_int ldwork, lapack_int* iwork );
lapack_int LAPACKE_dtrsna_work( int matrix_order, char job, char howmny,
                                const lapack_logical* select, lapack_int n,
                                const double* t, lapack_int ldt,
                                const double* vl, lapack_int ldvl,
                                const double* vr, lapack_int ldvr, double* s,
                                double* sep, lapack_int mm, lapack_int* m,
                                double* work, lapack_int ldwork,
                                lapack_int* iwork );
lapack_int LAPACKE_ctrsna_work( int matrix_order, char job, char howmny,
                                const lapack_logical* select, lapack_int n,
                                const lapack_complex_float* t, lapack_int ldt,
                                const lapack_complex_float* vl, lapack_int ldvl,
                                const lapack_complex_float* vr, lapack_int ldvr,
                                float* s, float* sep, lapack_int mm,
                                lapack_int* m, lapack_complex_float* work,
                                lapack_int ldwork, float* rwork );
lapack_int LAPACKE_ztrsna_work( int matrix_order, char job, char howmny,
                                const lapack_logical* select, lapack_int n,
                                const lapack_complex_double* t, lapack_int ldt,
                                const lapack_complex_double* vl,
                                lapack_int ldvl,
                                const lapack_complex_double* vr,
                                lapack_int ldvr, double* s, double* sep,
                                lapack_int mm, lapack_int* m,
                                lapack_complex_double* work, lapack_int ldwork,
                                double* rwork );

lapack_int LAPACKE_strsyl_work( int matrix_order, char trana, char tranb,
                                lapack_int isgn, lapack_int m, lapack_int n,
                                const float* a, lapack_int lda, const float* b,
                                lapack_int ldb, float* c, lapack_int ldc,
                                float* scale );
lapack_int LAPACKE_dtrsyl_work( int matrix_order, char trana, char tranb,
                                lapack_int isgn, lapack_int m, lapack_int n,
                                const double* a, lapack_int lda,
                                const double* b, lapack_int ldb, double* c,
                                lapack_int ldc, double* scale );
lapack_int LAPACKE_ctrsyl_work( int matrix_order, char trana, char tranb,
                                lapack_int isgn, lapack_int m, lapack_int n,
                                const lapack_complex_float* a, lapack_int lda,
                                const lapack_complex_float* b, lapack_int ldb,
                                lapack_complex_float* c, lapack_int ldc,
                                float* scale );
lapack_int LAPACKE_ztrsyl_work( int matrix_order, char trana, char tranb,
                                lapack_int isgn, lapack_int m, lapack_int n,
                                const lapack_complex_double* a, lapack_int lda,
                                const lapack_complex_double* b, lapack_int ldb,
                                lapack_complex_double* c, lapack_int ldc,
                                double* scale );

lapack_int LAPACKE_strtri_work( int matrix_order, char uplo, char diag,
                                lapack_int n, float* a, lapack_int lda );
lapack_int LAPACKE_dtrtri_work( int matrix_order, char uplo, char diag,
                                lapack_int n, double* a, lapack_int lda );
lapack_int LAPACKE_ctrtri_work( int matrix_order, char uplo, char diag,
                                lapack_int n, lapack_complex_float* a,
                                lapack_int lda );
lapack_int LAPACKE_ztrtri_work( int matrix_order, char uplo, char diag,
                                lapack_int n, lapack_complex_double* a,
                                lapack_int lda );

lapack_int LAPACKE_strtrs_work( int matrix_order, char uplo, char trans,
                                char diag, lapack_int n, lapack_int nrhs,
                                const float* a, lapack_int lda, float* b,
                                lapack_int ldb );
lapack_int LAPACKE_dtrtrs_work( int matrix_order, char uplo, char trans,
                                char diag, lapack_int n, lapack_int nrhs,
                                const double* a, lapack_int lda, double* b,
                                lapack_int ldb );
lapack_int LAPACKE_ctrtrs_work( int matrix_order, char uplo, char trans,
                                char diag, lapack_int n, lapack_int nrhs,
                                const lapack_complex_float* a, lapack_int lda,
                                lapack_complex_float* b, lapack_int ldb );
lapack_int LAPACKE_ztrtrs_work( int matrix_order, char uplo, char trans,
                                char diag, lapack_int n, lapack_int nrhs,
                                const lapack_complex_double* a, lapack_int lda,
                                lapack_complex_double* b, lapack_int ldb );

lapack_int LAPACKE_strttf_work( int matrix_order, char transr, char uplo,
                                lapack_int n, const float* a, lapack_int lda,
                                float* arf );
lapack_int LAPACKE_dtrttf_work( int matrix_order, char transr, char uplo,
                                lapack_int n, const double* a, lapack_int lda,
                                double* arf );
lapack_int LAPACKE_ctrttf_work( int matrix_order, char transr, char uplo,
                                lapack_int n, const lapack_complex_float* a,
                                lapack_int lda, lapack_complex_float* arf );
lapack_int LAPACKE_ztrttf_work( int matrix_order, char transr, char uplo,
                                lapack_int n, const lapack_complex_double* a,
                                lapack_int lda, lapack_complex_double* arf );

lapack_int LAPACKE_strttp_work( int matrix_order, char uplo, lapack_int n,
                                const float* a, lapack_int lda, float* ap );
lapack_int LAPACKE_dtrttp_work( int matrix_order, char uplo, lapack_int n,
                                const double* a, lapack_int lda, double* ap );
lapack_int LAPACKE_ctrttp_work( int matrix_order, char uplo, lapack_int n,
                                const lapack_complex_float* a, lapack_int lda,
                                lapack_complex_float* ap );
lapack_int LAPACKE_ztrttp_work( int matrix_order, char uplo, lapack_int n,
                                const lapack_complex_double* a, lapack_int lda,
                                lapack_complex_double* ap );

lapack_int LAPACKE_stzrzf_work( int matrix_order, lapack_int m, lapack_int n,
                                float* a, lapack_int lda, float* tau,
                                float* work, lapack_int lwork );
lapack_int LAPACKE_dtzrzf_work( int matrix_order, lapack_int m, lapack_int n,
                                double* a, lapack_int lda, double* tau,
                                double* work, lapack_int lwork );
lapack_int LAPACKE_ctzrzf_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_complex_float* a, lapack_int lda,
                                lapack_complex_float* tau,
                                lapack_complex_float* work, lapack_int lwork );
lapack_int LAPACKE_ztzrzf_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_complex_double* a, lapack_int lda,
                                lapack_complex_double* tau,
                                lapack_complex_double* work, lapack_int lwork );

lapack_int LAPACKE_cungbr_work( int matrix_order, char vect, lapack_int m,
                                lapack_int n, lapack_int k,
                                lapack_complex_float* a, lapack_int lda,
                                const lapack_complex_float* tau,
                                lapack_complex_float* work, lapack_int lwork );
lapack_int LAPACKE_zungbr_work( int matrix_order, char vect, lapack_int m,
                                lapack_int n, lapack_int k,
                                lapack_complex_double* a, lapack_int lda,
                                const lapack_complex_double* tau,
                                lapack_complex_double* work, lapack_int lwork );

lapack_int LAPACKE_cunghr_work( int matrix_order, lapack_int n, lapack_int ilo,
                                lapack_int ihi, lapack_complex_float* a,
                                lapack_int lda, const lapack_complex_float* tau,
                                lapack_complex_float* work, lapack_int lwork );
lapack_int LAPACKE_zunghr_work( int matrix_order, lapack_int n, lapack_int ilo,
                                lapack_int ihi, lapack_complex_double* a,
                                lapack_int lda,
                                const lapack_complex_double* tau,
                                lapack_complex_double* work, lapack_int lwork );

lapack_int LAPACKE_cunglq_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_int k, lapack_complex_float* a,
                                lapack_int lda, const lapack_complex_float* tau,
                                lapack_complex_float* work, lapack_int lwork );
lapack_int LAPACKE_zunglq_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_int k, lapack_complex_double* a,
                                lapack_int lda,
                                const lapack_complex_double* tau,
                                lapack_complex_double* work, lapack_int lwork );

lapack_int LAPACKE_cungql_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_int k, lapack_complex_float* a,
                                lapack_int lda, const lapack_complex_float* tau,
                                lapack_complex_float* work, lapack_int lwork );
lapack_int LAPACKE_zungql_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_int k, lapack_complex_double* a,
                                lapack_int lda,
                                const lapack_complex_double* tau,
                                lapack_complex_double* work, lapack_int lwork );

lapack_int LAPACKE_cungqr_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_int k, lapack_complex_float* a,
                                lapack_int lda, const lapack_complex_float* tau,
                                lapack_complex_float* work, lapack_int lwork );
lapack_int LAPACKE_zungqr_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_int k, lapack_complex_double* a,
                                lapack_int lda,
                                const lapack_complex_double* tau,
                                lapack_complex_double* work, lapack_int lwork );

lapack_int LAPACKE_cungrq_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_int k, lapack_complex_float* a,
                                lapack_int lda, const lapack_complex_float* tau,
                                lapack_complex_float* work, lapack_int lwork );
lapack_int LAPACKE_zungrq_work( int matrix_order, lapack_int m, lapack_int n,
                                lapack_int k, lapack_complex_double* a,
                                lapack_int lda,
                                const lapack_complex_double* tau,
                                lapack_complex_double* work, lapack_int lwork );

lapack_int LAPACKE_cungtr_work( int matrix_order, char uplo, lapack_int n,
                                lapack_complex_float* a, lapack_int lda,
                                const lapack_complex_float* tau,
                                lapack_complex_float* work, lapack_int lwork );
lapack_int LAPACKE_zungtr_work( int matrix_order, char uplo, lapack_int n,
                                lapack_complex_double* a, lapack_int lda,
                                const lapack_complex_double* tau,
                                lapack_complex_double* work, lapack_int lwork );

lapack_int LAPACKE_cunmbr_work( int matrix_order, char vect, char side,
                                char trans, lapack_int m, lapack_int n,
                                lapack_int k, const lapack_complex_float* a,
                                lapack_int lda, const lapack_complex_float* tau,
                                lapack_complex_float* c, lapack_int ldc,
                                lapack_complex_float* work, lapack_int lwork );
lapack_int LAPACKE_zunmbr_work( int matrix_order, char vect, char side,
                                char trans, lapack_int m, lapack_int n,
                                lapack_int k, const lapack_complex_double* a,
                                lapack_int lda,
                                const lapack_complex_double* tau,
                                lapack_complex_double* c, lapack_int ldc,
                                lapack_complex_double* work, lapack_int lwork );

lapack_int LAPACKE_cunmhr_work( int matrix_order, char side, char trans,
                                lapack_int m, lapack_int n, lapack_int ilo,
                                lapack_int ihi, const lapack_complex_float* a,
                                lapack_int lda, const lapack_complex_float* tau,
                                lapack_complex_float* c, lapack_int ldc,
                                lapack_complex_float* work, lapack_int lwork );
lapack_int LAPACKE_zunmhr_work( int matrix_order, char side, char trans,
                                lapack_int m, lapack_int n, lapack_int ilo,
                                lapack_int ihi, const lapack_complex_double* a,
                                lapack_int lda,
                                const lapack_complex_double* tau,
                                lapack_complex_double* c, lapack_int ldc,
                                lapack_complex_double* work, lapack_int lwork );

lapack_int LAPACKE_cunmlq_work( int matrix_order, char side, char trans,
                                lapack_int m, lapack_int n, lapack_int k,
                                const lapack_complex_float* a, lapack_int lda,
                                const lapack_complex_float* tau,
                                lapack_complex_float* c, lapack_int ldc,
                                lapack_complex_float* work, lapack_int lwork );
lapack_int LAPACKE_zunmlq_work( int matrix_order, char side, char trans,
                                lapack_int m, lapack_int n, lapack_int k,
                                const lapack_complex_double* a, lapack_int lda,
                                const lapack_complex_double* tau,
                                lapack_complex_double* c, lapack_int ldc,
                                lapack_complex_double* work, lapack_int lwork );

lapack_int LAPACKE_cunmql_work( int matrix_order, char side, char trans,
                                lapack_int m, lapack_int n, lapack_int k,
                                const lapack_complex_float* a, lapack_int lda,
                                const lapack_complex_float* tau,
                                lapack_complex_float* c, lapack_int ldc,
                                lapack_complex_float* work, lapack_int lwork );
lapack_int LAPACKE_zunmql_work( int matrix_order, char side, char trans,
                                lapack_int m, lapack_int n, lapack_int k,
                                const lapack_complex_double* a, lapack_int lda,
                                const lapack_complex_double* tau,
                                lapack_complex_double* c, lapack_int ldc,
                                lapack_complex_double* work, lapack_int lwork );

lapack_int LAPACKE_cunmqr_work( int matrix_order, char side, char trans,
                                lapack_int m, lapack_int n, lapack_int k,
                                const lapack_complex_float* a, lapack_int lda,
                                const lapack_complex_float* tau,
                                lapack_complex_float* c, lapack_int ldc,
                                lapack_complex_float* work, lapack_int lwork );
lapack_int LAPACKE_zunmqr_work( int matrix_order, char side, char trans,
                                lapack_int m, lapack_int n, lapack_int k,
                                const lapack_complex_double* a, lapack_int lda,
                                const lapack_complex_double* tau,
                                lapack_complex_double* c, lapack_int ldc,
                                lapack_complex_double* work, lapack_int lwork );

lapack_int LAPACKE_cunmrq_work( int matrix_order, char side, char trans,
                                lapack_int m, lapack_int n, lapack_int k,
                                const lapack_complex_float* a, lapack_int lda,
                                const lapack_complex_float* tau,
                                lapack_complex_float* c, lapack_int ldc,
                                lapack_complex_float* work, lapack_int lwork );
lapack_int LAPACKE_zunmrq_work( int matrix_order, char side, char trans,
                                lapack_int m, lapack_int n, lapack_int k,
                                const lapack_complex_double* a, lapack_int lda,
                                const lapack_complex_double* tau,
                                lapack_complex_double* c, lapack_int ldc,
                                lapack_complex_double* work, lapack_int lwork );

lapack_int LAPACKE_cunmrz_work( int matrix_order, char side, char trans,
                                lapack_int m, lapack_int n, lapack_int k,
                                lapack_int l, const lapack_complex_float* a,
                                lapack_int lda, const lapack_complex_float* tau,
                                lapack_complex_float* c, lapack_int ldc,
                                lapack_complex_float* work, lapack_int lwork );
lapack_int LAPACKE_zunmrz_work( int matrix_order, char side, char trans,
                                lapack_int m, lapack_int n, lapack_int k,
                                lapack_int l, const lapack_complex_double* a,
                                lapack_int lda,
                                const lapack_complex_double* tau,
                                lapack_complex_double* c, lapack_int ldc,
                                lapack_complex_double* work, lapack_int lwork );

lapack_int LAPACKE_cunmtr_work( int matrix_order, char side, char uplo,
                                char trans, lapack_int m, lapack_int n,
                                const lapack_complex_float* a, lapack_int lda,
                                const lapack_complex_float* tau,
                                lapack_complex_float* c, lapack_int ldc,
                                lapack_complex_float* work, lapack_int lwork );
lapack_int LAPACKE_zunmtr_work( int matrix_order, char side, char uplo,
                                char trans, lapack_int m, lapack_int n,
                                const lapack_complex_double* a, lapack_int lda,
                                const lapack_complex_double* tau,
                                lapack_complex_double* c, lapack_int ldc,
                                lapack_complex_double* work, lapack_int lwork );

lapack_int LAPACKE_cupgtr_work( int matrix_order, char uplo, lapack_int n,
                                const lapack_complex_float* ap,
                                const lapack_complex_float* tau,
                                lapack_complex_float* q, lapack_int ldq,
                                lapack_complex_float* work );
lapack_int LAPACKE_zupgtr_work( int matrix_order, char uplo, lapack_int n,
                                const lapack_complex_double* ap,
                                const lapack_complex_double* tau,
                                lapack_complex_double* q, lapack_int ldq,
                                lapack_complex_double* work );

lapack_int LAPACKE_cupmtr_work( int matrix_order, char side, char uplo,
                                char trans, lapack_int m, lapack_int n,
                                const lapack_complex_float* ap,
                                const lapack_complex_float* tau,
                                lapack_complex_float* c, lapack_int ldc,
                                lapack_complex_float* work );
lapack_int LAPACKE_zupmtr_work( int matrix_order, char side, char uplo,
                                char trans, lapack_int m, lapack_int n,
                                const lapack_complex_double* ap,
                                const lapack_complex_double* tau,
                                lapack_complex_double* c, lapack_int ldc,
                                lapack_complex_double* work );

#define LAPACK_sgetrf LAPACK_NAME(sgetrf,SGETRF)
#define LAPACK_dgetrf LAPACK_NAME(dgetrf,DGETRF)
#define LAPACK_cgetrf LAPACK_NAME(cgetrf,CGETRF)
#define LAPACK_zgetrf LAPACK_NAME(zgetrf,ZGETRF)
#define LAPACK_sgbtrf LAPACK_NAME(sgbtrf,SGBTRF)
#define LAPACK_dgbtrf LAPACK_NAME(dgbtrf,DGBTRF)
#define LAPACK_cgbtrf LAPACK_NAME(cgbtrf,CGBTRF)
#define LAPACK_zgbtrf LAPACK_NAME(zgbtrf,ZGBTRF)
#define LAPACK_sgttrf LAPACK_NAME(sgttrf,SGTTRF)
#define LAPACK_dgttrf LAPACK_NAME(dgttrf,DGTTRF)
#define LAPACK_cgttrf LAPACK_NAME(cgttrf,CGTTRF)
#define LAPACK_zgttrf LAPACK_NAME(zgttrf,ZGTTRF)
#define LAPACK_spotrf LAPACK_NAME(spotrf,SPOTRF)
#define LAPACK_dpotrf LAPACK_NAME(dpotrf,DPOTRF)
#define LAPACK_cpotrf LAPACK_NAME(cpotrf,CPOTRF)
#define LAPACK_zpotrf LAPACK_NAME(zpotrf,ZPOTRF)
#define LAPACK_dpstrf LAPACK_NAME(dpstrf,DPSTRF)
#define LAPACK_spstrf LAPACK_NAME(spstrf,SPSTRF)
#define LAPACK_zpstrf LAPACK_NAME(zpstrf,ZPSTRF)
#define LAPACK_cpstrf LAPACK_NAME(cpstrf,CPSTRF)
#define LAPACK_dpftrf LAPACK_NAME(dpftrf,DPFTRF)
#define LAPACK_spftrf LAPACK_NAME(spftrf,SPFTRF)
#define LAPACK_zpftrf LAPACK_NAME(zpftrf,ZPFTRF)
#define LAPACK_cpftrf LAPACK_NAME(cpftrf,CPFTRF)
#define LAPACK_spptrf LAPACK_NAME(spptrf,SPPTRF)
#define LAPACK_dpptrf LAPACK_NAME(dpptrf,DPPTRF)
#define LAPACK_cpptrf LAPACK_NAME(cpptrf,CPPTRF)
#define LAPACK_zpptrf LAPACK_NAME(zpptrf,ZPPTRF)
#define LAPACK_spbtrf LAPACK_NAME(spbtrf,SPBTRF)
#define LAPACK_dpbtrf LAPACK_NAME(dpbtrf,DPBTRF)
#define LAPACK_cpbtrf LAPACK_NAME(cpbtrf,CPBTRF)
#define LAPACK_zpbtrf LAPACK_NAME(zpbtrf,ZPBTRF)
#define LAPACK_spttrf LAPACK_NAME(spttrf,SPTTRF)
#define LAPACK_dpttrf LAPACK_NAME(dpttrf,DPTTRF)
#define LAPACK_cpttrf LAPACK_NAME(cpttrf,CPTTRF)
#define LAPACK_zpttrf LAPACK_NAME(zpttrf,ZPTTRF)
#define LAPACK_ssytrf LAPACK_NAME(ssytrf,SSYTRF)
#define LAPACK_dsytrf LAPACK_NAME(dsytrf,DSYTRF)
#define LAPACK_csytrf LAPACK_NAME(csytrf,CSYTRF)
#define LAPACK_zsytrf LAPACK_NAME(zsytrf,ZSYTRF)
#define LAPACK_chetrf LAPACK_NAME(chetrf,CHETRF)
#define LAPACK_zhetrf LAPACK_NAME(zhetrf,ZHETRF)
#define LAPACK_ssptrf LAPACK_NAME(ssptrf,SSPTRF)
#define LAPACK_dsptrf LAPACK_NAME(dsptrf,DSPTRF)
#define LAPACK_csptrf LAPACK_NAME(csptrf,CSPTRF)
#define LAPACK_zsptrf LAPACK_NAME(zsptrf,ZSPTRF)
#define LAPACK_chptrf LAPACK_NAME(chptrf,CHPTRF)
#define LAPACK_zhptrf LAPACK_NAME(zhptrf,ZHPTRF)
#define LAPACK_sgetrs LAPACK_NAME(sgetrs,SGETRS)
#define LAPACK_dgetrs LAPACK_NAME(dgetrs,DGETRS)
#define LAPACK_cgetrs LAPACK_NAME(cgetrs,CGETRS)
#define LAPACK_zgetrs LAPACK_NAME(zgetrs,ZGETRS)
#define LAPACK_sgbtrs LAPACK_NAME(sgbtrs,SGBTRS)
#define LAPACK_dgbtrs LAPACK_NAME(dgbtrs,DGBTRS)
#define LAPACK_cgbtrs LAPACK_NAME(cgbtrs,CGBTRS)
#define LAPACK_zgbtrs LAPACK_NAME(zgbtrs,ZGBTRS)
#define LAPACK_sgttrs LAPACK_NAME(sgttrs,SGTTRS)
#define LAPACK_dgttrs LAPACK_NAME(dgttrs,DGTTRS)
#define LAPACK_cgttrs LAPACK_NAME(cgttrs,CGTTRS)
#define LAPACK_zgttrs LAPACK_NAME(zgttrs,ZGTTRS)
#define LAPACK_spotrs LAPACK_NAME(spotrs,SPOTRS)
#define LAPACK_dpotrs LAPACK_NAME(dpotrs,DPOTRS)
#define LAPACK_cpotrs LAPACK_NAME(cpotrs,CPOTRS)
#define LAPACK_zpotrs LAPACK_NAME(zpotrs,ZPOTRS)
#define LAPACK_dpftrs LAPACK_NAME(dpftrs,DPFTRS)
#define LAPACK_spftrs LAPACK_NAME(spftrs,SPFTRS)
#define LAPACK_zpftrs LAPACK_NAME(zpftrs,ZPFTRS)
#define LAPACK_cpftrs LAPACK_NAME(cpftrs,CPFTRS)
#define LAPACK_spptrs LAPACK_NAME(spptrs,SPPTRS)
#define LAPACK_dpptrs LAPACK_NAME(dpptrs,DPPTRS)
#define LAPACK_cpptrs LAPACK_NAME(cpptrs,CPPTRS)
#define LAPACK_zpptrs LAPACK_NAME(zpptrs,ZPPTRS)
#define LAPACK_spbtrs LAPACK_NAME(spbtrs,SPBTRS)
#define LAPACK_dpbtrs LAPACK_NAME(dpbtrs,DPBTRS)
#define LAPACK_cpbtrs LAPACK_NAME(cpbtrs,CPBTRS)
#define LAPACK_zpbtrs LAPACK_NAME(zpbtrs,ZPBTRS)
#define LAPACK_spttrs LAPACK_NAME(spttrs,SPTTRS)
#define LAPACK_dpttrs LAPACK_NAME(dpttrs,DPTTRS)
#define LAPACK_cpttrs LAPACK_NAME(cpttrs,CPTTRS)
#define LAPACK_zpttrs LAPACK_NAME(zpttrs,ZPTTRS)
#define LAPACK_ssytrs LAPACK_NAME(ssytrs,SSYTRS)
#define LAPACK_dsytrs LAPACK_NAME(dsytrs,DSYTRS)
#define LAPACK_csytrs LAPACK_NAME(csytrs,CSYTRS)
#define LAPACK_zsytrs LAPACK_NAME(zsytrs,ZSYTRS)
#define LAPACK_chetrs LAPACK_NAME(chetrs,CHETRS)
#define LAPACK_zhetrs LAPACK_NAME(zhetrs,ZHETRS)
#define LAPACK_ssptrs LAPACK_NAME(ssptrs,SSPTRS)
#define LAPACK_dsptrs LAPACK_NAME(dsptrs,DSPTRS)
#define LAPACK_csptrs LAPACK_NAME(csptrs,CSPTRS)
#define LAPACK_zsptrs LAPACK_NAME(zsptrs,ZSPTRS)
#define LAPACK_chptrs LAPACK_NAME(chptrs,CHPTRS)
#define LAPACK_zhptrs LAPACK_NAME(zhptrs,ZHPTRS)
#define LAPACK_strtrs LAPACK_NAME(strtrs,STRTRS)
#define LAPACK_dtrtrs LAPACK_NAME(dtrtrs,DTRTRS)
#define LAPACK_ctrtrs LAPACK_NAME(ctrtrs,CTRTRS)
#define LAPACK_ztrtrs LAPACK_NAME(ztrtrs,ZTRTRS)
#define LAPACK_stptrs LAPACK_NAME(stptrs,STPTRS)
#define LAPACK_dtptrs LAPACK_NAME(dtptrs,DTPTRS)
#define LAPACK_ctptrs LAPACK_NAME(ctptrs,CTPTRS)
#define LAPACK_ztptrs LAPACK_NAME(ztptrs,ZTPTRS)
#define LAPACK_stbtrs LAPACK_NAME(stbtrs,STBTRS)
#define LAPACK_dtbtrs LAPACK_NAME(dtbtrs,DTBTRS)
#define LAPACK_ctbtrs LAPACK_NAME(ctbtrs,CTBTRS)
#define LAPACK_ztbtrs LAPACK_NAME(ztbtrs,ZTBTRS)
#define LAPACK_sgecon LAPACK_NAME(sgecon,SGECON)
#define LAPACK_dgecon LAPACK_NAME(dgecon,DGECON)
#define LAPACK_cgecon LAPACK_NAME(cgecon,CGECON)
#define LAPACK_zgecon LAPACK_NAME(zgecon,ZGECON)
#define LAPACK_sgbcon LAPACK_NAME(sgbcon,SGBCON)
#define LAPACK_dgbcon LAPACK_NAME(dgbcon,DGBCON)
#define LAPACK_cgbcon LAPACK_NAME(cgbcon,CGBCON)
#define LAPACK_zgbcon LAPACK_NAME(zgbcon,ZGBCON)
#define LAPACK_sgtcon LAPACK_NAME(sgtcon,SGTCON)
#define LAPACK_dgtcon LAPACK_NAME(dgtcon,DGTCON)
#define LAPACK_cgtcon LAPACK_NAME(cgtcon,CGTCON)
#define LAPACK_zgtcon LAPACK_NAME(zgtcon,ZGTCON)
#define LAPACK_spocon LAPACK_NAME(spocon,SPOCON)
#define LAPACK_dpocon LAPACK_NAME(dpocon,DPOCON)
#define LAPACK_cpocon LAPACK_NAME(cpocon,CPOCON)
#define LAPACK_zpocon LAPACK_NAME(zpocon,ZPOCON)
#define LAPACK_sppcon LAPACK_NAME(sppcon,SPPCON)
#define LAPACK_dppcon LAPACK_NAME(dppcon,DPPCON)
#define LAPACK_cppcon LAPACK_NAME(cppcon,CPPCON)
#define LAPACK_zppcon LAPACK_NAME(zppcon,ZPPCON)
#define LAPACK_spbcon LAPACK_NAME(spbcon,SPBCON)
#define LAPACK_dpbcon LAPACK_NAME(dpbcon,DPBCON)
#define LAPACK_cpbcon LAPACK_NAME(cpbcon,CPBCON)
#define LAPACK_zpbcon LAPACK_NAME(zpbcon,ZPBCON)
#define LAPACK_sptcon LAPACK_NAME(sptcon,SPTCON)
#define LAPACK_dptcon LAPACK_NAME(dptcon,DPTCON)
#define LAPACK_cptcon LAPACK_NAME(cptcon,CPTCON)
#define LAPACK_zptcon LAPACK_NAME(zptcon,ZPTCON)
#define LAPACK_ssycon LAPACK_NAME(ssycon,SSYCON)
#define LAPACK_dsycon LAPACK_NAME(dsycon,DSYCON)
#define LAPACK_csycon LAPACK_NAME(csycon,CSYCON)
#define LAPACK_zsycon LAPACK_NAME(zsycon,ZSYCON)
#define LAPACK_checon LAPACK_NAME(checon,CHECON)
#define LAPACK_zhecon LAPACK_NAME(zhecon,ZHECON)
#define LAPACK_sspcon LAPACK_NAME(sspcon,SSPCON)
#define LAPACK_dspcon LAPACK_NAME(dspcon,DSPCON)
#define LAPACK_cspcon LAPACK_NAME(cspcon,CSPCON)
#define LAPACK_zspcon LAPACK_NAME(zspcon,ZSPCON)
#define LAPACK_chpcon LAPACK_NAME(chpcon,CHPCON)
#define LAPACK_zhpcon LAPACK_NAME(zhpcon,ZHPCON)
#define LAPACK_strcon LAPACK_NAME(strcon,STRCON)
#define LAPACK_dtrcon LAPACK_NAME(dtrcon,DTRCON)
#define LAPACK_ctrcon LAPACK_NAME(ctrcon,CTRCON)
#define LAPACK_ztrcon LAPACK_NAME(ztrcon,ZTRCON)
#define LAPACK_stpcon LAPACK_NAME(stpcon,STPCON)
#define LAPACK_dtpcon LAPACK_NAME(dtpcon,DTPCON)
#define LAPACK_ctpcon LAPACK_NAME(ctpcon,CTPCON)
#define LAPACK_ztpcon LAPACK_NAME(ztpcon,ZTPCON)
#define LAPACK_stbcon LAPACK_NAME(stbcon,STBCON)
#define LAPACK_dtbcon LAPACK_NAME(dtbcon,DTBCON)
#define LAPACK_ctbcon LAPACK_NAME(ctbcon,CTBCON)
#define LAPACK_ztbcon LAPACK_NAME(ztbcon,ZTBCON)
#define LAPACK_sgerfs LAPACK_NAME(sgerfs,SGERFS)
#define LAPACK_dgerfs LAPACK_NAME(dgerfs,DGERFS)
#define LAPACK_cgerfs LAPACK_NAME(cgerfs,CGERFS)
#define LAPACK_zgerfs LAPACK_NAME(zgerfs,ZGERFS)
#define LAPACK_dgerfsx LAPACK_NAME(dgerfsx,DGERFSX)
#define LAPACK_sgerfsx LAPACK_NAME(sgerfsx,SGERFSX)
#define LAPACK_zgerfsx LAPACK_NAME(zgerfsx,ZGERFSX)
#define LAPACK_cgerfsx LAPACK_NAME(cgerfsx,CGERFSX)
#define LAPACK_sgbrfs LAPACK_NAME(sgbrfs,SGBRFS)
#define LAPACK_dgbrfs LAPACK_NAME(dgbrfs,DGBRFS)
#define LAPACK_cgbrfs LAPACK_NAME(cgbrfs,CGBRFS)
#define LAPACK_zgbrfs LAPACK_NAME(zgbrfs,ZGBRFS)
#define LAPACK_dgbrfsx LAPACK_NAME(dgbrfsx,DGBRFSX)
#define LAPACK_sgbrfsx LAPACK_NAME(sgbrfsx,SGBRFSX)
#define LAPACK_zgbrfsx LAPACK_NAME(zgbrfsx,ZGBRFSX)
#define LAPACK_cgbrfsx LAPACK_NAME(cgbrfsx,CGBRFSX)
#define LAPACK_sgtrfs LAPACK_NAME(sgtrfs,SGTRFS)
#define LAPACK_dgtrfs LAPACK_NAME(dgtrfs,DGTRFS)
#define LAPACK_cgtrfs LAPACK_NAME(cgtrfs,CGTRFS)
#define LAPACK_zgtrfs LAPACK_NAME(zgtrfs,ZGTRFS)
#define LAPACK_sporfs LAPACK_NAME(sporfs,SPORFS)
#define LAPACK_dporfs LAPACK_NAME(dporfs,DPORFS)
#define LAPACK_cporfs LAPACK_NAME(cporfs,CPORFS)
#define LAPACK_zporfs LAPACK_NAME(zporfs,ZPORFS)
#define LAPACK_dporfsx LAPACK_NAME(dporfsx,DPORFSX)
#define LAPACK_sporfsx LAPACK_NAME(sporfsx,SPORFSX)
#define LAPACK_zporfsx LAPACK_NAME(zporfsx,ZPORFSX)
#define LAPACK_cporfsx LAPACK_NAME(cporfsx,CPORFSX)
#define LAPACK_spprfs LAPACK_NAME(spprfs,SPPRFS)
#define LAPACK_dpprfs LAPACK_NAME(dpprfs,DPPRFS)
#define LAPACK_cpprfs LAPACK_NAME(cpprfs,CPPRFS)
#define LAPACK_zpprfs LAPACK_NAME(zpprfs,ZPPRFS)
#define LAPACK_spbrfs LAPACK_NAME(spbrfs,SPBRFS)
#define LAPACK_dpbrfs LAPACK_NAME(dpbrfs,DPBRFS)
#define LAPACK_cpbrfs LAPACK_NAME(cpbrfs,CPBRFS)
#define LAPACK_zpbrfs LAPACK_NAME(zpbrfs,ZPBRFS)
#define LAPACK_sptrfs LAPACK_NAME(sptrfs,SPTRFS)
#define LAPACK_dptrfs LAPACK_NAME(dptrfs,DPTRFS)
#define LAPACK_cptrfs LAPACK_NAME(cptrfs,CPTRFS)
#define LAPACK_zptrfs LAPACK_NAME(zptrfs,ZPTRFS)
#define LAPACK_ssyrfs LAPACK_NAME(ssyrfs,SSYRFS)
#define LAPACK_dsyrfs LAPACK_NAME(dsyrfs,DSYRFS)
#define LAPACK_csyrfs LAPACK_NAME(csyrfs,CSYRFS)
#define LAPACK_zsyrfs LAPACK_NAME(zsyrfs,ZSYRFS)
#define LAPACK_dsyrfsx LAPACK_NAME(dsyrfsx,DSYRFSX)
#define LAPACK_ssyrfsx LAPACK_NAME(ssyrfsx,SSYRFSX)
#define LAPACK_zsyrfsx LAPACK_NAME(zsyrfsx,ZSYRFSX)
#define LAPACK_csyrfsx LAPACK_NAME(csyrfsx,CSYRFSX)
#define LAPACK_cherfs LAPACK_NAME(cherfs,CHERFS)
#define LAPACK_zherfs LAPACK_NAME(zherfs,ZHERFS)
#define LAPACK_zherfsx LAPACK_NAME(zherfsx,ZHERFSX)
#define LAPACK_cherfsx LAPACK_NAME(cherfsx,CHERFSX)
#define LAPACK_ssprfs LAPACK_NAME(ssprfs,SSPRFS)
#define LAPACK_dsprfs LAPACK_NAME(dsprfs,DSPRFS)
#define LAPACK_csprfs LAPACK_NAME(csprfs,CSPRFS)
#define LAPACK_zsprfs LAPACK_NAME(zsprfs,ZSPRFS)
#define LAPACK_chprfs LAPACK_NAME(chprfs,CHPRFS)
#define LAPACK_zhprfs LAPACK_NAME(zhprfs,ZHPRFS)
#define LAPACK_strrfs LAPACK_NAME(strrfs,STRRFS)
#define LAPACK_dtrrfs LAPACK_NAME(dtrrfs,DTRRFS)
#define LAPACK_ctrrfs LAPACK_NAME(ctrrfs,CTRRFS)
#define LAPACK_ztrrfs LAPACK_NAME(ztrrfs,ZTRRFS)
#define LAPACK_stprfs LAPACK_NAME(stprfs,STPRFS)
#define LAPACK_dtprfs LAPACK_NAME(dtprfs,DTPRFS)
#define LAPACK_ctprfs LAPACK_NAME(ctprfs,CTPRFS)
#define LAPACK_ztprfs LAPACK_NAME(ztprfs,ZTPRFS)
#define LAPACK_stbrfs LAPACK_NAME(stbrfs,STBRFS)
#define LAPACK_dtbrfs LAPACK_NAME(dtbrfs,DTBRFS)
#define LAPACK_ctbrfs LAPACK_NAME(ctbrfs,CTBRFS)
#define LAPACK_ztbrfs LAPACK_NAME(ztbrfs,ZTBRFS)
#define LAPACK_sgetri LAPACK_NAME(sgetri,SGETRI)
#define LAPACK_dgetri LAPACK_NAME(dgetri,DGETRI)
#define LAPACK_cgetri LAPACK_NAME(cgetri,CGETRI)
#define LAPACK_zgetri LAPACK_NAME(zgetri,ZGETRI)
#define LAPACK_spotri LAPACK_NAME(spotri,SPOTRI)
#define LAPACK_dpotri LAPACK_NAME(dpotri,DPOTRI)
#define LAPACK_cpotri LAPACK_NAME(cpotri,CPOTRI)
#define LAPACK_zpotri LAPACK_NAME(zpotri,ZPOTRI)
#define LAPACK_dpftri LAPACK_NAME(dpftri,DPFTRI)
#define LAPACK_spftri LAPACK_NAME(spftri,SPFTRI)
#define LAPACK_zpftri LAPACK_NAME(zpftri,ZPFTRI)
#define LAPACK_cpftri LAPACK_NAME(cpftri,CPFTRI)
#define LAPACK_spptri LAPACK_NAME(spptri,SPPTRI)
#define LAPACK_dpptri LAPACK_NAME(dpptri,DPPTRI)
#define LAPACK_cpptri LAPACK_NAME(cpptri,CPPTRI)
#define LAPACK_zpptri LAPACK_NAME(zpptri,ZPPTRI)
#define LAPACK_ssytri LAPACK_NAME(ssytri,SSYTRI)
#define LAPACK_dsytri LAPACK_NAME(dsytri,DSYTRI)
#define LAPACK_csytri LAPACK_NAME(csytri,CSYTRI)
#define LAPACK_zsytri LAPACK_NAME(zsytri,ZSYTRI)
#define LAPACK_chetri LAPACK_NAME(chetri,CHETRI)
#define LAPACK_zhetri LAPACK_NAME(zhetri,ZHETRI)
#define LAPACK_ssptri LAPACK_NAME(ssptri,SSPTRI)
#define LAPACK_dsptri LAPACK_NAME(dsptri,DSPTRI)
#define LAPACK_csptri LAPACK_NAME(csptri,CSPTRI)
#define LAPACK_zsptri LAPACK_NAME(zsptri,ZSPTRI)
#define LAPACK_chptri LAPACK_NAME(chptri,CHPTRI)
#define LAPACK_zhptri LAPACK_NAME(zhptri,ZHPTRI)
#define LAPACK_strtri LAPACK_NAME(strtri,STRTRI)
#define LAPACK_dtrtri LAPACK_NAME(dtrtri,DTRTRI)
#define LAPACK_ctrtri LAPACK_NAME(ctrtri,CTRTRI)
#define LAPACK_ztrtri LAPACK_NAME(ztrtri,ZTRTRI)
#define LAPACK_dtftri LAPACK_NAME(dtftri,DTFTRI)
#define LAPACK_stftri LAPACK_NAME(stftri,STFTRI)
#define LAPACK_ztftri LAPACK_NAME(ztftri,ZTFTRI)
#define LAPACK_ctftri LAPACK_NAME(ctftri,CTFTRI)
#define LAPACK_stptri LAPACK_NAME(stptri,STPTRI)
#define LAPACK_dtptri LAPACK_NAME(dtptri,DTPTRI)
#define LAPACK_ctptri LAPACK_NAME(ctptri,CTPTRI)
#define LAPACK_ztptri LAPACK_NAME(ztptri,ZTPTRI)
#define LAPACK_sgeequ LAPACK_NAME(sgeequ,SGEEQU)
#define LAPACK_dgeequ LAPACK_NAME(dgeequ,DGEEQU)
#define LAPACK_cgeequ LAPACK_NAME(cgeequ,CGEEQU)
#define LAPACK_zgeequ LAPACK_NAME(zgeequ,ZGEEQU)
#define LAPACK_dgeequb LAPACK_NAME(dgeequb,DGEEQUB)
#define LAPACK_sgeequb LAPACK_NAME(sgeequb,SGEEQUB)
#define LAPACK_zgeequb LAPACK_NAME(zgeequb,ZGEEQUB)
#define LAPACK_cgeequb LAPACK_NAME(cgeequb,CGEEQUB)
#define LAPACK_sgbequ LAPACK_NAME(sgbequ,SGBEQU)
#define LAPACK_dgbequ LAPACK_NAME(dgbequ,DGBEQU)
#define LAPACK_cgbequ LAPACK_NAME(cgbequ,CGBEQU)
#define LAPACK_zgbequ LAPACK_NAME(zgbequ,ZGBEQU)
#define LAPACK_dgbequb LAPACK_NAME(dgbequb,DGBEQUB)
#define LAPACK_sgbequb LAPACK_NAME(sgbequb,SGBEQUB)
#define LAPACK_zgbequb LAPACK_NAME(zgbequb,ZGBEQUB)
#define LAPACK_cgbequb LAPACK_NAME(cgbequb,CGBEQUB)
#define LAPACK_spoequ LAPACK_NAME(spoequ,SPOEQU)
#define LAPACK_dpoequ LAPACK_NAME(dpoequ,DPOEQU)
#define LAPACK_cpoequ LAPACK_NAME(cpoequ,CPOEQU)
#define LAPACK_zpoequ LAPACK_NAME(zpoequ,ZPOEQU)
#define LAPACK_dpoequb LAPACK_NAME(dpoequb,DPOEQUB)
#define LAPACK_spoequb LAPACK_NAME(spoequb,SPOEQUB)
#define LAPACK_zpoequb LAPACK_NAME(zpoequb,ZPOEQUB)
#define LAPACK_cpoequb LAPACK_NAME(cpoequb,CPOEQUB)
#define LAPACK_sppequ LAPACK_NAME(sppequ,SPPEQU)
#define LAPACK_dppequ LAPACK_NAME(dppequ,DPPEQU)
#define LAPACK_cppequ LAPACK_NAME(cppequ,CPPEQU)
#define LAPACK_zppequ LAPACK_NAME(zppequ,ZPPEQU)
#define LAPACK_spbequ LAPACK_NAME(spbequ,SPBEQU)
#define LAPACK_dpbequ LAPACK_NAME(dpbequ,DPBEQU)
#define LAPACK_cpbequ LAPACK_NAME(cpbequ,CPBEQU)
#define LAPACK_zpbequ LAPACK_NAME(zpbequ,ZPBEQU)
#define LAPACK_dsyequb LAPACK_NAME(dsyequb,DSYEQUB)
#define LAPACK_ssyequb LAPACK_NAME(ssyequb,SSYEQUB)
#define LAPACK_zsyequb LAPACK_NAME(zsyequb,ZSYEQUB)
#define LAPACK_csyequb LAPACK_NAME(csyequb,CSYEQUB)
#define LAPACK_zheequb LAPACK_NAME(zheequb,ZHEEQUB)
#define LAPACK_cheequb LAPACK_NAME(cheequb,CHEEQUB)
#define LAPACK_sgesv LAPACK_NAME(sgesv,SGESV)
#define LAPACK_dgesv LAPACK_NAME(dgesv,DGESV)
#define LAPACK_cgesv LAPACK_NAME(cgesv,CGESV)
#define LAPACK_zgesv LAPACK_NAME(zgesv,ZGESV)
#define LAPACK_dsgesv LAPACK_NAME(dsgesv,DSGESV)
#define LAPACK_zcgesv LAPACK_NAME(zcgesv,ZCGESV)
#define LAPACK_sgesvx LAPACK_NAME(sgesvx,SGESVX)
#define LAPACK_dgesvx LAPACK_NAME(dgesvx,DGESVX)
#define LAPACK_cgesvx LAPACK_NAME(cgesvx,CGESVX)
#define LAPACK_zgesvx LAPACK_NAME(zgesvx,ZGESVX)
#define LAPACK_dgesvxx LAPACK_NAME(dgesvxx,DGESVXX)
#define LAPACK_sgesvxx LAPACK_NAME(sgesvxx,SGESVXX)
#define LAPACK_zgesvxx LAPACK_NAME(zgesvxx,ZGESVXX)
#define LAPACK_cgesvxx LAPACK_NAME(cgesvxx,CGESVXX)
#define LAPACK_sgbsv LAPACK_NAME(sgbsv,SGBSV)
#define LAPACK_dgbsv LAPACK_NAME(dgbsv,DGBSV)
#define LAPACK_cgbsv LAPACK_NAME(cgbsv,CGBSV)
#define LAPACK_zgbsv LAPACK_NAME(zgbsv,ZGBSV)
#define LAPACK_sgbsvx LAPACK_NAME(sgbsvx,SGBSVX)
#define LAPACK_dgbsvx LAPACK_NAME(dgbsvx,DGBSVX)
#define LAPACK_cgbsvx LAPACK_NAME(cgbsvx,CGBSVX)
#define LAPACK_zgbsvx LAPACK_NAME(zgbsvx,ZGBSVX)
#define LAPACK_dgbsvxx LAPACK_NAME(dgbsvxx,DGBSVXX)
#define LAPACK_sgbsvxx LAPACK_NAME(sgbsvxx,SGBSVXX)
#define LAPACK_zgbsvxx LAPACK_NAME(zgbsvxx,ZGBSVXX)
#define LAPACK_cgbsvxx LAPACK_NAME(cgbsvxx,CGBSVXX)
#define LAPACK_sgtsv LAPACK_NAME(sgtsv,SGTSV)
#define LAPACK_dgtsv LAPACK_NAME(dgtsv,DGTSV)
#define LAPACK_cgtsv LAPACK_NAME(cgtsv,CGTSV)
#define LAPACK_zgtsv LAPACK_NAME(zgtsv,ZGTSV)
#define LAPACK_sgtsvx LAPACK_NAME(sgtsvx,SGTSVX)
#define LAPACK_dgtsvx LAPACK_NAME(dgtsvx,DGTSVX)
#define LAPACK_cgtsvx LAPACK_NAME(cgtsvx,CGTSVX)
#define LAPACK_zgtsvx LAPACK_NAME(zgtsvx,ZGTSVX)
#define LAPACK_sposv LAPACK_NAME(sposv,SPOSV)
#define LAPACK_dposv LAPACK_NAME(dposv,DPOSV)
#define LAPACK_cposv LAPACK_NAME(cposv,CPOSV)
#define LAPACK_zposv LAPACK_NAME(zposv,ZPOSV)
#define LAPACK_dsposv LAPACK_NAME(dsposv,DSPOSV)
#define LAPACK_zcposv LAPACK_NAME(zcposv,ZCPOSV)
#define LAPACK_sposvx LAPACK_NAME(sposvx,SPOSVX)
#define LAPACK_dposvx LAPACK_NAME(dposvx,DPOSVX)
#define LAPACK_cposvx LAPACK_NAME(cposvx,CPOSVX)
#define LAPACK_zposvx LAPACK_NAME(zposvx,ZPOSVX)
#define LAPACK_dposvxx LAPACK_NAME(dposvxx,DPOSVXX)
#define LAPACK_sposvxx LAPACK_NAME(sposvxx,SPOSVXX)
#define LAPACK_zposvxx LAPACK_NAME(zposvxx,ZPOSVXX)
#define LAPACK_cposvxx LAPACK_NAME(cposvxx,CPOSVXX)
#define LAPACK_sppsv LAPACK_NAME(sppsv,SPPSV)
#define LAPACK_dppsv LAPACK_NAME(dppsv,DPPSV)
#define LAPACK_cppsv LAPACK_NAME(cppsv,CPPSV)
#define LAPACK_zppsv LAPACK_NAME(zppsv,ZPPSV)
#define LAPACK_sppsvx LAPACK_NAME(sppsvx,SPPSVX)
#define LAPACK_dppsvx LAPACK_NAME(dppsvx,DPPSVX)
#define LAPACK_cppsvx LAPACK_NAME(cppsvx,CPPSVX)
#define LAPACK_zppsvx LAPACK_NAME(zppsvx,ZPPSVX)
#define LAPACK_spbsv LAPACK_NAME(spbsv,SPBSV)
#define LAPACK_dpbsv LAPACK_NAME(dpbsv,DPBSV)
#define LAPACK_cpbsv LAPACK_NAME(cpbsv,CPBSV)
#define LAPACK_zpbsv LAPACK_NAME(zpbsv,ZPBSV)
#define LAPACK_spbsvx LAPACK_NAME(spbsvx,SPBSVX)
#define LAPACK_dpbsvx LAPACK_NAME(dpbsvx,DPBSVX)
#define LAPACK_cpbsvx LAPACK_NAME(cpbsvx,CPBSVX)
#define LAPACK_zpbsvx LAPACK_NAME(zpbsvx,ZPBSVX)
#define LAPACK_sptsv LAPACK_NAME(sptsv,SPTSV)
#define LAPACK_dptsv LAPACK_NAME(dptsv,DPTSV)
#define LAPACK_cptsv LAPACK_NAME(cptsv,CPTSV)
#define LAPACK_zptsv LAPACK_NAME(zptsv,ZPTSV)
#define LAPACK_sptsvx LAPACK_NAME(sptsvx,SPTSVX)
#define LAPACK_dptsvx LAPACK_NAME(dptsvx,DPTSVX)
#define LAPACK_cptsvx LAPACK_NAME(cptsvx,CPTSVX)
#define LAPACK_zptsvx LAPACK_NAME(zptsvx,ZPTSVX)
#define LAPACK_ssysv LAPACK_NAME(ssysv,SSYSV)
#define LAPACK_dsysv LAPACK_NAME(dsysv,DSYSV)
#define LAPACK_csysv LAPACK_NAME(csysv,CSYSV)
#define LAPACK_zsysv LAPACK_NAME(zsysv,ZSYSV)
#define LAPACK_ssysvx LAPACK_NAME(ssysvx,SSYSVX)
#define LAPACK_dsysvx LAPACK_NAME(dsysvx,DSYSVX)
#define LAPACK_csysvx LAPACK_NAME(csysvx,CSYSVX)
#define LAPACK_zsysvx LAPACK_NAME(zsysvx,ZSYSVX)
#define LAPACK_dsysvxx LAPACK_NAME(dsysvxx,DSYSVXX)
#define LAPACK_ssysvxx LAPACK_NAME(ssysvxx,SSYSVXX)
#define LAPACK_zsysvxx LAPACK_NAME(zsysvxx,ZSYSVXX)
#define LAPACK_csysvxx LAPACK_NAME(csysvxx,CSYSVXX)
#define LAPACK_chesv LAPACK_NAME(chesv,CHESV)
#define LAPACK_zhesv LAPACK_NAME(zhesv,ZHESV)
#define LAPACK_chesvx LAPACK_NAME(chesvx,CHESVX)
#define LAPACK_zhesvx LAPACK_NAME(zhesvx,ZHESVX)
#define LAPACK_zhesvxx LAPACK_NAME(zhesvxx,ZHESVXX)
#define LAPACK_chesvxx LAPACK_NAME(chesvxx,CHESVXX)
#define LAPACK_sspsv LAPACK_NAME(sspsv,SSPSV)
#define LAPACK_dspsv LAPACK_NAME(dspsv,DSPSV)
#define LAPACK_cspsv LAPACK_NAME(cspsv,CSPSV)
#define LAPACK_zspsv LAPACK_NAME(zspsv,ZSPSV)
#define LAPACK_sspsvx LAPACK_NAME(sspsvx,SSPSVX)
#define LAPACK_dspsvx LAPACK_NAME(dspsvx,DSPSVX)
#define LAPACK_cspsvx LAPACK_NAME(cspsvx,CSPSVX)
#define LAPACK_zspsvx LAPACK_NAME(zspsvx,ZSPSVX)
#define LAPACK_chpsv LAPACK_NAME(chpsv,CHPSV)
#define LAPACK_zhpsv LAPACK_NAME(zhpsv,ZHPSV)
#define LAPACK_chpsvx LAPACK_NAME(chpsvx,CHPSVX)
#define LAPACK_zhpsvx LAPACK_NAME(zhpsvx,ZHPSVX)
#define LAPACK_sgeqrf LAPACK_NAME(sgeqrf,SGEQRF)
#define LAPACK_dgeqrf LAPACK_NAME(dgeqrf,DGEQRF)
#define LAPACK_cgeqrf LAPACK_NAME(cgeqrf,CGEQRF)
#define LAPACK_zgeqrf LAPACK_NAME(zgeqrf,ZGEQRF)
#define LAPACK_sgeqpf LAPACK_NAME(sgeqpf,SGEQPF)
#define LAPACK_dgeqpf LAPACK_NAME(dgeqpf,DGEQPF)
#define LAPACK_cgeqpf LAPACK_NAME(cgeqpf,CGEQPF)
#define LAPACK_zgeqpf LAPACK_NAME(zgeqpf,ZGEQPF)
#define LAPACK_sgeqp3 LAPACK_NAME(sgeqp3,SGEQP3)
#define LAPACK_dgeqp3 LAPACK_NAME(dgeqp3,DGEQP3)
#define LAPACK_cgeqp3 LAPACK_NAME(cgeqp3,CGEQP3)
#define LAPACK_zgeqp3 LAPACK_NAME(zgeqp3,ZGEQP3)
#define LAPACK_sorgqr LAPACK_NAME(sorgqr,SORGQR)
#define LAPACK_dorgqr LAPACK_NAME(dorgqr,DORGQR)
#define LAPACK_sormqr LAPACK_NAME(sormqr,SORMQR)
#define LAPACK_dormqr LAPACK_NAME(dormqr,DORMQR)
#define LAPACK_cungqr LAPACK_NAME(cungqr,CUNGQR)
#define LAPACK_zungqr LAPACK_NAME(zungqr,ZUNGQR)
#define LAPACK_cunmqr LAPACK_NAME(cunmqr,CUNMQR)
#define LAPACK_zunmqr LAPACK_NAME(zunmqr,ZUNMQR)
#define LAPACK_sgelqf LAPACK_NAME(sgelqf,SGELQF)
#define LAPACK_dgelqf LAPACK_NAME(dgelqf,DGELQF)
#define LAPACK_cgelqf LAPACK_NAME(cgelqf,CGELQF)
#define LAPACK_zgelqf LAPACK_NAME(zgelqf,ZGELQF)
#define LAPACK_sorglq LAPACK_NAME(sorglq,SORGLQ)
#define LAPACK_dorglq LAPACK_NAME(dorglq,DORGLQ)
#define LAPACK_sormlq LAPACK_NAME(sormlq,SORMLQ)
#define LAPACK_dormlq LAPACK_NAME(dormlq,DORMLQ)
#define LAPACK_cunglq LAPACK_NAME(cunglq,CUNGLQ)
#define LAPACK_zunglq LAPACK_NAME(zunglq,ZUNGLQ)
#define LAPACK_cunmlq LAPACK_NAME(cunmlq,CUNMLQ)
#define LAPACK_zunmlq LAPACK_NAME(zunmlq,ZUNMLQ)
#define LAPACK_sgeqlf LAPACK_NAME(sgeqlf,SGEQLF)
#define LAPACK_dgeqlf LAPACK_NAME(dgeqlf,DGEQLF)
#define LAPACK_cgeqlf LAPACK_NAME(cgeqlf,CGEQLF)
#define LAPACK_zgeqlf LAPACK_NAME(zgeqlf,ZGEQLF)
#define LAPACK_sorgql LAPACK_NAME(sorgql,SORGQL)
#define LAPACK_dorgql LAPACK_NAME(dorgql,DORGQL)
#define LAPACK_cungql LAPACK_NAME(cungql,CUNGQL)
#define LAPACK_zungql LAPACK_NAME(zungql,ZUNGQL)
#define LAPACK_sormql LAPACK_NAME(sormql,SORMQL)
#define LAPACK_dormql LAPACK_NAME(dormql,DORMQL)
#define LAPACK_cunmql LAPACK_NAME(cunmql,CUNMQL)
#define LAPACK_zunmql LAPACK_NAME(zunmql,ZUNMQL)
#define LAPACK_sgerqf LAPACK_NAME(sgerqf,SGERQF)
#define LAPACK_dgerqf LAPACK_NAME(dgerqf,DGERQF)
#define LAPACK_cgerqf LAPACK_NAME(cgerqf,CGERQF)
#define LAPACK_zgerqf LAPACK_NAME(zgerqf,ZGERQF)
#define LAPACK_sorgrq LAPACK_NAME(sorgrq,SORGRQ)
#define LAPACK_dorgrq LAPACK_NAME(dorgrq,DORGRQ)
#define LAPACK_cungrq LAPACK_NAME(cungrq,CUNGRQ)
#define LAPACK_zungrq LAPACK_NAME(zungrq,ZUNGRQ)
#define LAPACK_sormrq LAPACK_NAME(sormrq,SORMRQ)
#define LAPACK_dormrq LAPACK_NAME(dormrq,DORMRQ)
#define LAPACK_cunmrq LAPACK_NAME(cunmrq,CUNMRQ)
#define LAPACK_zunmrq LAPACK_NAME(zunmrq,ZUNMRQ)
#define LAPACK_stzrzf LAPACK_NAME(stzrzf,STZRZF)
#define LAPACK_dtzrzf LAPACK_NAME(dtzrzf,DTZRZF)
#define LAPACK_ctzrzf LAPACK_NAME(ctzrzf,CTZRZF)
#define LAPACK_ztzrzf LAPACK_NAME(ztzrzf,ZTZRZF)
#define LAPACK_sormrz LAPACK_NAME(sormrz,SORMRZ)
#define LAPACK_dormrz LAPACK_NAME(dormrz,DORMRZ)
#define LAPACK_cunmrz LAPACK_NAME(cunmrz,CUNMRZ)
#define LAPACK_zunmrz LAPACK_NAME(zunmrz,ZUNMRZ)
#define LAPACK_sggqrf LAPACK_NAME(sggqrf,SGGQRF)
#define LAPACK_dggqrf LAPACK_NAME(dggqrf,DGGQRF)
#define LAPACK_cggqrf LAPACK_NAME(cggqrf,CGGQRF)
#define LAPACK_zggqrf LAPACK_NAME(zggqrf,ZGGQRF)
#define LAPACK_sggrqf LAPACK_NAME(sggrqf,SGGRQF)
#define LAPACK_dggrqf LAPACK_NAME(dggrqf,DGGRQF)
#define LAPACK_cggrqf LAPACK_NAME(cggrqf,CGGRQF)
#define LAPACK_zggrqf LAPACK_NAME(zggrqf,ZGGRQF)
#define LAPACK_sgebrd LAPACK_NAME(sgebrd,SGEBRD)
#define LAPACK_dgebrd LAPACK_NAME(dgebrd,DGEBRD)
#define LAPACK_cgebrd LAPACK_NAME(cgebrd,CGEBRD)
#define LAPACK_zgebrd LAPACK_NAME(zgebrd,ZGEBRD)
#define LAPACK_sgbbrd LAPACK_NAME(sgbbrd,SGBBRD)
#define LAPACK_dgbbrd LAPACK_NAME(dgbbrd,DGBBRD)
#define LAPACK_cgbbrd LAPACK_NAME(cgbbrd,CGBBRD)
#define LAPACK_zgbbrd LAPACK_NAME(zgbbrd,ZGBBRD)
#define LAPACK_sorgbr LAPACK_NAME(sorgbr,SORGBR)
#define LAPACK_dorgbr LAPACK_NAME(dorgbr,DORGBR)
#define LAPACK_sormbr LAPACK_NAME(sormbr,SORMBR)
#define LAPACK_dormbr LAPACK_NAME(dormbr,DORMBR)
#define LAPACK_cungbr LAPACK_NAME(cungbr,CUNGBR)
#define LAPACK_zungbr LAPACK_NAME(zungbr,ZUNGBR)
#define LAPACK_cunmbr LAPACK_NAME(cunmbr,CUNMBR)
#define LAPACK_zunmbr LAPACK_NAME(zunmbr,ZUNMBR)
#define LAPACK_sbdsqr LAPACK_NAME(sbdsqr,SBDSQR)
#define LAPACK_dbdsqr LAPACK_NAME(dbdsqr,DBDSQR)
#define LAPACK_cbdsqr LAPACK_NAME(cbdsqr,CBDSQR)
#define LAPACK_zbdsqr LAPACK_NAME(zbdsqr,ZBDSQR)
#define LAPACK_sbdsdc LAPACK_NAME(sbdsdc,SBDSDC)
#define LAPACK_dbdsdc LAPACK_NAME(dbdsdc,DBDSDC)
#define LAPACK_ssytrd LAPACK_NAME(ssytrd,SSYTRD)
#define LAPACK_dsytrd LAPACK_NAME(dsytrd,DSYTRD)
#define LAPACK_sorgtr LAPACK_NAME(sorgtr,SORGTR)
#define LAPACK_dorgtr LAPACK_NAME(dorgtr,DORGTR)
#define LAPACK_sormtr LAPACK_NAME(sormtr,SORMTR)
#define LAPACK_dormtr LAPACK_NAME(dormtr,DORMTR)
#define LAPACK_chetrd LAPACK_NAME(chetrd,CHETRD)
#define LAPACK_zhetrd LAPACK_NAME(zhetrd,ZHETRD)
#define LAPACK_cungtr LAPACK_NAME(cungtr,CUNGTR)
#define LAPACK_zungtr LAPACK_NAME(zungtr,ZUNGTR)
#define LAPACK_cunmtr LAPACK_NAME(cunmtr,CUNMTR)
#define LAPACK_zunmtr LAPACK_NAME(zunmtr,ZUNMTR)
#define LAPACK_ssptrd LAPACK_NAME(ssptrd,SSPTRD)
#define LAPACK_dsptrd LAPACK_NAME(dsptrd,DSPTRD)
#define LAPACK_sopgtr LAPACK_NAME(sopgtr,SOPGTR)
#define LAPACK_dopgtr LAPACK_NAME(dopgtr,DOPGTR)
#define LAPACK_sopmtr LAPACK_NAME(sopmtr,SOPMTR)
#define LAPACK_dopmtr LAPACK_NAME(dopmtr,DOPMTR)
#define LAPACK_chptrd LAPACK_NAME(chptrd,CHPTRD)
#define LAPACK_zhptrd LAPACK_NAME(zhptrd,ZHPTRD)
#define LAPACK_cupgtr LAPACK_NAME(cupgtr,CUPGTR)
#define LAPACK_zupgtr LAPACK_NAME(zupgtr,ZUPGTR)
#define LAPACK_cupmtr LAPACK_NAME(cupmtr,CUPMTR)
#define LAPACK_zupmtr LAPACK_NAME(zupmtr,ZUPMTR)
#define LAPACK_ssbtrd LAPACK_NAME(ssbtrd,SSBTRD)
#define LAPACK_dsbtrd LAPACK_NAME(dsbtrd,DSBTRD)
#define LAPACK_chbtrd LAPACK_NAME(chbtrd,CHBTRD)
#define LAPACK_zhbtrd LAPACK_NAME(zhbtrd,ZHBTRD)
#define LAPACK_ssterf LAPACK_NAME(ssterf,SSTERF)
#define LAPACK_dsterf LAPACK_NAME(dsterf,DSTERF)
#define LAPACK_ssteqr LAPACK_NAME(ssteqr,SSTEQR)
#define LAPACK_dsteqr LAPACK_NAME(dsteqr,DSTEQR)
#define LAPACK_csteqr LAPACK_NAME(csteqr,CSTEQR)
#define LAPACK_zsteqr LAPACK_NAME(zsteqr,ZSTEQR)
#define LAPACK_sstemr LAPACK_NAME(sstemr,SSTEMR)
#define LAPACK_dstemr LAPACK_NAME(dstemr,DSTEMR)
#define LAPACK_cstemr LAPACK_NAME(cstemr,CSTEMR)
#define LAPACK_zstemr LAPACK_NAME(zstemr,ZSTEMR)
#define LAPACK_sstedc LAPACK_NAME(sstedc,SSTEDC)
#define LAPACK_dstedc LAPACK_NAME(dstedc,DSTEDC)
#define LAPACK_cstedc LAPACK_NAME(cstedc,CSTEDC)
#define LAPACK_zstedc LAPACK_NAME(zstedc,ZSTEDC)
#define LAPACK_sstegr LAPACK_NAME(sstegr,SSTEGR)
#define LAPACK_dstegr LAPACK_NAME(dstegr,DSTEGR)
#define LAPACK_cstegr LAPACK_NAME(cstegr,CSTEGR)
#define LAPACK_zstegr LAPACK_NAME(zstegr,ZSTEGR)
#define LAPACK_spteqr LAPACK_NAME(spteqr,SPTEQR)
#define LAPACK_dpteqr LAPACK_NAME(dpteqr,DPTEQR)
#define LAPACK_cpteqr LAPACK_NAME(cpteqr,CPTEQR)
#define LAPACK_zpteqr LAPACK_NAME(zpteqr,ZPTEQR)
#define LAPACK_sstebz LAPACK_NAME(sstebz,SSTEBZ)
#define LAPACK_dstebz LAPACK_NAME(dstebz,DSTEBZ)
#define LAPACK_sstein LAPACK_NAME(sstein,SSTEIN)
#define LAPACK_dstein LAPACK_NAME(dstein,DSTEIN)
#define LAPACK_cstein LAPACK_NAME(cstein,CSTEIN)
#define LAPACK_zstein LAPACK_NAME(zstein,ZSTEIN)
#define LAPACK_sdisna LAPACK_NAME(sdisna,SDISNA)
#define LAPACK_ddisna LAPACK_NAME(ddisna,DDISNA)
#define LAPACK_ssygst LAPACK_NAME(ssygst,SSYGST)
#define LAPACK_dsygst LAPACK_NAME(dsygst,DSYGST)
#define LAPACK_chegst LAPACK_NAME(chegst,CHEGST)
#define LAPACK_zhegst LAPACK_NAME(zhegst,ZHEGST)
#define LAPACK_sspgst LAPACK_NAME(sspgst,SSPGST)
#define LAPACK_dspgst LAPACK_NAME(dspgst,DSPGST)
#define LAPACK_chpgst LAPACK_NAME(chpgst,CHPGST)
#define LAPACK_zhpgst LAPACK_NAME(zhpgst,ZHPGST)
#define LAPACK_ssbgst LAPACK_NAME(ssbgst,SSBGST)
#define LAPACK_dsbgst LAPACK_NAME(dsbgst,DSBGST)
#define LAPACK_chbgst LAPACK_NAME(chbgst,CHBGST)
#define LAPACK_zhbgst LAPACK_NAME(zhbgst,ZHBGST)
#define LAPACK_spbstf LAPACK_NAME(spbstf,SPBSTF)
#define LAPACK_dpbstf LAPACK_NAME(dpbstf,DPBSTF)
#define LAPACK_cpbstf LAPACK_NAME(cpbstf,CPBSTF)
#define LAPACK_zpbstf LAPACK_NAME(zpbstf,ZPBSTF)
#define LAPACK_sgehrd LAPACK_NAME(sgehrd,SGEHRD)
#define LAPACK_dgehrd LAPACK_NAME(dgehrd,DGEHRD)
#define LAPACK_cgehrd LAPACK_NAME(cgehrd,CGEHRD)
#define LAPACK_zgehrd LAPACK_NAME(zgehrd,ZGEHRD)
#define LAPACK_sorghr LAPACK_NAME(sorghr,SORGHR)
#define LAPACK_dorghr LAPACK_NAME(dorghr,DORGHR)
#define LAPACK_sormhr LAPACK_NAME(sormhr,SORMHR)
#define LAPACK_dormhr LAPACK_NAME(dormhr,DORMHR)
#define LAPACK_cunghr LAPACK_NAME(cunghr,CUNGHR)
#define LAPACK_zunghr LAPACK_NAME(zunghr,ZUNGHR)
#define LAPACK_cunmhr LAPACK_NAME(cunmhr,CUNMHR)
#define LAPACK_zunmhr LAPACK_NAME(zunmhr,ZUNMHR)
#define LAPACK_sgebal LAPACK_NAME(sgebal,SGEBAL)
#define LAPACK_dgebal LAPACK_NAME(dgebal,DGEBAL)
#define LAPACK_cgebal LAPACK_NAME(cgebal,CGEBAL)
#define LAPACK_zgebal LAPACK_NAME(zgebal,ZGEBAL)
#define LAPACK_sgebak LAPACK_NAME(sgebak,SGEBAK)
#define LAPACK_dgebak LAPACK_NAME(dgebak,DGEBAK)
#define LAPACK_cgebak LAPACK_NAME(cgebak,CGEBAK)
#define LAPACK_zgebak LAPACK_NAME(zgebak,ZGEBAK)
#define LAPACK_shseqr LAPACK_NAME(shseqr,SHSEQR)
#define LAPACK_dhseqr LAPACK_NAME(dhseqr,DHSEQR)
#define LAPACK_chseqr LAPACK_NAME(chseqr,CHSEQR)
#define LAPACK_zhseqr LAPACK_NAME(zhseqr,ZHSEQR)
#define LAPACK_shsein LAPACK_NAME(shsein,SHSEIN)
#define LAPACK_dhsein LAPACK_NAME(dhsein,DHSEIN)
#define LAPACK_chsein LAPACK_NAME(chsein,CHSEIN)
#define LAPACK_zhsein LAPACK_NAME(zhsein,ZHSEIN)
#define LAPACK_strevc LAPACK_NAME(strevc,STREVC)
#define LAPACK_dtrevc LAPACK_NAME(dtrevc,DTREVC)
#define LAPACK_ctrevc LAPACK_NAME(ctrevc,CTREVC)
#define LAPACK_ztrevc LAPACK_NAME(ztrevc,ZTREVC)
#define LAPACK_strsna LAPACK_NAME(strsna,STRSNA)
#define LAPACK_dtrsna LAPACK_NAME(dtrsna,DTRSNA)
#define LAPACK_ctrsna LAPACK_NAME(ctrsna,CTRSNA)
#define LAPACK_ztrsna LAPACK_NAME(ztrsna,ZTRSNA)
#define LAPACK_strexc LAPACK_NAME(strexc,STREXC)
#define LAPACK_dtrexc LAPACK_NAME(dtrexc,DTREXC)
#define LAPACK_ctrexc LAPACK_NAME(ctrexc,CTREXC)
#define LAPACK_ztrexc LAPACK_NAME(ztrexc,ZTREXC)
#define LAPACK_strsen LAPACK_NAME(strsen,STRSEN)
#define LAPACK_dtrsen LAPACK_NAME(dtrsen,DTRSEN)
#define LAPACK_ctrsen LAPACK_NAME(ctrsen,CTRSEN)
#define LAPACK_ztrsen LAPACK_NAME(ztrsen,ZTRSEN)
#define LAPACK_strsyl LAPACK_NAME(strsyl,STRSYL)
#define LAPACK_dtrsyl LAPACK_NAME(dtrsyl,DTRSYL)
#define LAPACK_ctrsyl LAPACK_NAME(ctrsyl,CTRSYL)
#define LAPACK_ztrsyl LAPACK_NAME(ztrsyl,ZTRSYL)
#define LAPACK_sgghrd LAPACK_NAME(sgghrd,SGGHRD)
#define LAPACK_dgghrd LAPACK_NAME(dgghrd,DGGHRD)
#define LAPACK_cgghrd LAPACK_NAME(cgghrd,CGGHRD)
#define LAPACK_zgghrd LAPACK_NAME(zgghrd,ZGGHRD)
#define LAPACK_sggbal LAPACK_NAME(sggbal,SGGBAL)
#define LAPACK_dggbal LAPACK_NAME(dggbal,DGGBAL)
#define LAPACK_cggbal LAPACK_NAME(cggbal,CGGBAL)
#define LAPACK_zggbal LAPACK_NAME(zggbal,ZGGBAL)
#define LAPACK_sggbak LAPACK_NAME(sggbak,SGGBAK)
#define LAPACK_dggbak LAPACK_NAME(dggbak,DGGBAK)
#define LAPACK_cggbak LAPACK_NAME(cggbak,CGGBAK)
#define LAPACK_zggbak LAPACK_NAME(zggbak,ZGGBAK)
#define LAPACK_shgeqz LAPACK_NAME(shgeqz,SHGEQZ)
#define LAPACK_dhgeqz LAPACK_NAME(dhgeqz,DHGEQZ)
#define LAPACK_chgeqz LAPACK_NAME(chgeqz,CHGEQZ)
#define LAPACK_zhgeqz LAPACK_NAME(zhgeqz,ZHGEQZ)
#define LAPACK_stgevc LAPACK_NAME(stgevc,STGEVC)
#define LAPACK_dtgevc LAPACK_NAME(dtgevc,DTGEVC)
#define LAPACK_ctgevc LAPACK_NAME(ctgevc,CTGEVC)
#define LAPACK_ztgevc LAPACK_NAME(ztgevc,ZTGEVC)
#define LAPACK_stgexc LAPACK_NAME(stgexc,STGEXC)
#define LAPACK_dtgexc LAPACK_NAME(dtgexc,DTGEXC)
#define LAPACK_ctgexc LAPACK_NAME(ctgexc,CTGEXC)
#define LAPACK_ztgexc LAPACK_NAME(ztgexc,ZTGEXC)
#define LAPACK_stgsen LAPACK_NAME(stgsen,STGSEN)
#define LAPACK_dtgsen LAPACK_NAME(dtgsen,DTGSEN)
#define LAPACK_ctgsen LAPACK_NAME(ctgsen,CTGSEN)
#define LAPACK_ztgsen LAPACK_NAME(ztgsen,ZTGSEN)
#define LAPACK_stgsyl LAPACK_NAME(stgsyl,STGSYL)
#define LAPACK_dtgsyl LAPACK_NAME(dtgsyl,DTGSYL)
#define LAPACK_ctgsyl LAPACK_NAME(ctgsyl,CTGSYL)
#define LAPACK_ztgsyl LAPACK_NAME(ztgsyl,ZTGSYL)
#define LAPACK_stgsna LAPACK_NAME(stgsna,STGSNA)
#define LAPACK_dtgsna LAPACK_NAME(dtgsna,DTGSNA)
#define LAPACK_ctgsna LAPACK_NAME(ctgsna,CTGSNA)
#define LAPACK_ztgsna LAPACK_NAME(ztgsna,ZTGSNA)
#define LAPACK_sggsvp LAPACK_NAME(sggsvp,SGGSVP)
#define LAPACK_dggsvp LAPACK_NAME(dggsvp,DGGSVP)
#define LAPACK_cggsvp LAPACK_NAME(cggsvp,CGGSVP)
#define LAPACK_zggsvp LAPACK_NAME(zggsvp,ZGGSVP)
#define LAPACK_stgsja LAPACK_NAME(stgsja,STGSJA)
#define LAPACK_dtgsja LAPACK_NAME(dtgsja,DTGSJA)
#define LAPACK_ctgsja LAPACK_NAME(ctgsja,CTGSJA)
#define LAPACK_ztgsja LAPACK_NAME(ztgsja,ZTGSJA)
#define LAPACK_sgels LAPACK_NAME(sgels,SGELS)
#define LAPACK_dgels LAPACK_NAME(dgels,DGELS)
#define LAPACK_cgels LAPACK_NAME(cgels,CGELS)
#define LAPACK_zgels LAPACK_NAME(zgels,ZGELS)
#define LAPACK_sgelsy LAPACK_NAME(sgelsy,SGELSY)
#define LAPACK_dgelsy LAPACK_NAME(dgelsy,DGELSY)
#define LAPACK_cgelsy LAPACK_NAME(cgelsy,CGELSY)
#define LAPACK_zgelsy LAPACK_NAME(zgelsy,ZGELSY)
#define LAPACK_sgelss LAPACK_NAME(sgelss,SGELSS)
#define LAPACK_dgelss LAPACK_NAME(dgelss,DGELSS)
#define LAPACK_cgelss LAPACK_NAME(cgelss,CGELSS)
#define LAPACK_zgelss LAPACK_NAME(zgelss,ZGELSS)
#define LAPACK_sgelsd LAPACK_NAME(sgelsd,SGELSD)
#define LAPACK_dgelsd LAPACK_NAME(dgelsd,DGELSD)
#define LAPACK_cgelsd LAPACK_NAME(cgelsd,CGELSD)
#define LAPACK_zgelsd LAPACK_NAME(zgelsd,ZGELSD)
#define LAPACK_sgglse LAPACK_NAME(sgglse,SGGLSE)
#define LAPACK_dgglse LAPACK_NAME(dgglse,DGGLSE)
#define LAPACK_cgglse LAPACK_NAME(cgglse,CGGLSE)
#define LAPACK_zgglse LAPACK_NAME(zgglse,ZGGLSE)
#define LAPACK_sggglm LAPACK_NAME(sggglm,SGGGLM)
#define LAPACK_dggglm LAPACK_NAME(dggglm,DGGGLM)
#define LAPACK_cggglm LAPACK_NAME(cggglm,CGGGLM)
#define LAPACK_zggglm LAPACK_NAME(zggglm,ZGGGLM)
#define LAPACK_ssyev LAPACK_NAME(ssyev,SSYEV)
#define LAPACK_dsyev LAPACK_NAME(dsyev,DSYEV)
#define LAPACK_cheev LAPACK_NAME(cheev,CHEEV)
#define LAPACK_zheev LAPACK_NAME(zheev,ZHEEV)
#define LAPACK_ssyevd LAPACK_NAME(ssyevd,SSYEVD)
#define LAPACK_dsyevd LAPACK_NAME(dsyevd,DSYEVD)
#define LAPACK_cheevd LAPACK_NAME(cheevd,CHEEVD)
#define LAPACK_zheevd LAPACK_NAME(zheevd,ZHEEVD)
#define LAPACK_ssyevx LAPACK_NAME(ssyevx,SSYEVX)
#define LAPACK_dsyevx LAPACK_NAME(dsyevx,DSYEVX)
#define LAPACK_cheevx LAPACK_NAME(cheevx,CHEEVX)
#define LAPACK_zheevx LAPACK_NAME(zheevx,ZHEEVX)
#define LAPACK_ssyevr LAPACK_NAME(ssyevr,SSYEVR)
#define LAPACK_dsyevr LAPACK_NAME(dsyevr,DSYEVR)
#define LAPACK_cheevr LAPACK_NAME(cheevr,CHEEVR)
#define LAPACK_zheevr LAPACK_NAME(zheevr,ZHEEVR)
#define LAPACK_sspev LAPACK_NAME(sspev,SSPEV)
#define LAPACK_dspev LAPACK_NAME(dspev,DSPEV)
#define LAPACK_chpev LAPACK_NAME(chpev,CHPEV)
#define LAPACK_zhpev LAPACK_NAME(zhpev,ZHPEV)
#define LAPACK_sspevd LAPACK_NAME(sspevd,SSPEVD)
#define LAPACK_dspevd LAPACK_NAME(dspevd,DSPEVD)
#define LAPACK_chpevd LAPACK_NAME(chpevd,CHPEVD)
#define LAPACK_zhpevd LAPACK_NAME(zhpevd,ZHPEVD)
#define LAPACK_sspevx LAPACK_NAME(sspevx,SSPEVX)
#define LAPACK_dspevx LAPACK_NAME(dspevx,DSPEVX)
#define LAPACK_chpevx LAPACK_NAME(chpevx,CHPEVX)
#define LAPACK_zhpevx LAPACK_NAME(zhpevx,ZHPEVX)
#define LAPACK_ssbev LAPACK_NAME(ssbev,SSBEV)
#define LAPACK_dsbev LAPACK_NAME(dsbev,DSBEV)
#define LAPACK_chbev LAPACK_NAME(chbev,CHBEV)
#define LAPACK_zhbev LAPACK_NAME(zhbev,ZHBEV)
#define LAPACK_ssbevd LAPACK_NAME(ssbevd,SSBEVD)
#define LAPACK_dsbevd LAPACK_NAME(dsbevd,DSBEVD)
#define LAPACK_chbevd LAPACK_NAME(chbevd,CHBEVD)
#define LAPACK_zhbevd LAPACK_NAME(zhbevd,ZHBEVD)
#define LAPACK_ssbevx LAPACK_NAME(ssbevx,SSBEVX)
#define LAPACK_dsbevx LAPACK_NAME(dsbevx,DSBEVX)
#define LAPACK_chbevx LAPACK_NAME(chbevx,CHBEVX)
#define LAPACK_zhbevx LAPACK_NAME(zhbevx,ZHBEVX)
#define LAPACK_sstev LAPACK_NAME(sstev,SSTEV)
#define LAPACK_dstev LAPACK_NAME(dstev,DSTEV)
#define LAPACK_sstevd LAPACK_NAME(sstevd,SSTEVD)
#define LAPACK_dstevd LAPACK_NAME(dstevd,DSTEVD)
#define LAPACK_sstevx LAPACK_NAME(sstevx,SSTEVX)
#define LAPACK_dstevx LAPACK_NAME(dstevx,DSTEVX)
#define LAPACK_sstevr LAPACK_NAME(sstevr,SSTEVR)
#define LAPACK_dstevr LAPACK_NAME(dstevr,DSTEVR)
#define LAPACK_sgees LAPACK_NAME(sgees,SGEES)
#define LAPACK_dgees LAPACK_NAME(dgees,DGEES)
#define LAPACK_cgees LAPACK_NAME(cgees,CGEES)
#define LAPACK_zgees LAPACK_NAME(zgees,ZGEES)
#define LAPACK_sgeesx LAPACK_NAME(sgeesx,SGEESX)
#define LAPACK_dgeesx LAPACK_NAME(dgeesx,DGEESX)
#define LAPACK_cgeesx LAPACK_NAME(cgeesx,CGEESX)
#define LAPACK_zgeesx LAPACK_NAME(zgeesx,ZGEESX)
#define LAPACK_sgeev LAPACK_NAME(sgeev,SGEEV)
#define LAPACK_dgeev LAPACK_NAME(dgeev,DGEEV)
#define LAPACK_cgeev LAPACK_NAME(cgeev,CGEEV)
#define LAPACK_zgeev LAPACK_NAME(zgeev,ZGEEV)
#define LAPACK_sgeevx LAPACK_NAME(sgeevx,SGEEVX)
#define LAPACK_dgeevx LAPACK_NAME(dgeevx,DGEEVX)
#define LAPACK_cgeevx LAPACK_NAME(cgeevx,CGEEVX)
#define LAPACK_zgeevx LAPACK_NAME(zgeevx,ZGEEVX)
#define LAPACK_sgesvd LAPACK_NAME(sgesvd,SGESVD)
#define LAPACK_dgesvd LAPACK_NAME(dgesvd,DGESVD)
#define LAPACK_cgesvd LAPACK_NAME(cgesvd,CGESVD)
#define LAPACK_zgesvd LAPACK_NAME(zgesvd,ZGESVD)
#define LAPACK_sgesdd LAPACK_NAME(sgesdd,SGESDD)
#define LAPACK_dgesdd LAPACK_NAME(dgesdd,DGESDD)
#define LAPACK_cgesdd LAPACK_NAME(cgesdd,CGESDD)
#define LAPACK_zgesdd LAPACK_NAME(zgesdd,ZGESDD)
#define LAPACK_dgejsv LAPACK_NAME(dgejsv,DGEJSV)
#define LAPACK_sgejsv LAPACK_NAME(sgejsv,SGEJSV)
#define LAPACK_dgesvj LAPACK_NAME(dgesvj,DGESVJ)
#define LAPACK_sgesvj LAPACK_NAME(sgesvj,SGESVJ)
#define LAPACK_sggsvd LAPACK_NAME(sggsvd,SGGSVD)
#define LAPACK_dggsvd LAPACK_NAME(dggsvd,DGGSVD)
#define LAPACK_cggsvd LAPACK_NAME(cggsvd,CGGSVD)
#define LAPACK_zggsvd LAPACK_NAME(zggsvd,ZGGSVD)
#define LAPACK_ssygv LAPACK_NAME(ssygv,SSYGV)
#define LAPACK_dsygv LAPACK_NAME(dsygv,DSYGV)
#define LAPACK_chegv LAPACK_NAME(chegv,CHEGV)
#define LAPACK_zhegv LAPACK_NAME(zhegv,ZHEGV)
#define LAPACK_ssygvd LAPACK_NAME(ssygvd,SSYGVD)
#define LAPACK_dsygvd LAPACK_NAME(dsygvd,DSYGVD)
#define LAPACK_chegvd LAPACK_NAME(chegvd,CHEGVD)
#define LAPACK_zhegvd LAPACK_NAME(zhegvd,ZHEGVD)
#define LAPACK_ssygvx LAPACK_NAME(ssygvx,SSYGVX)
#define LAPACK_dsygvx LAPACK_NAME(dsygvx,DSYGVX)
#define LAPACK_chegvx LAPACK_NAME(chegvx,CHEGVX)
#define LAPACK_zhegvx LAPACK_NAME(zhegvx,ZHEGVX)
#define LAPACK_sspgv LAPACK_NAME(sspgv,SSPGV)
#define LAPACK_dspgv LAPACK_NAME(dspgv,DSPGV)
#define LAPACK_chpgv LAPACK_NAME(chpgv,CHPGV)
#define LAPACK_zhpgv LAPACK_NAME(zhpgv,ZHPGV)
#define LAPACK_sspgvd LAPACK_NAME(sspgvd,SSPGVD)
#define LAPACK_dspgvd LAPACK_NAME(dspgvd,DSPGVD)
#define LAPACK_chpgvd LAPACK_NAME(chpgvd,CHPGVD)
#define LAPACK_zhpgvd LAPACK_NAME(zhpgvd,ZHPGVD)
#define LAPACK_sspgvx LAPACK_NAME(sspgvx,SSPGVX)
#define LAPACK_dspgvx LAPACK_NAME(dspgvx,DSPGVX)
#define LAPACK_chpgvx LAPACK_NAME(chpgvx,CHPGVX)
#define LAPACK_zhpgvx LAPACK_NAME(zhpgvx,ZHPGVX)
#define LAPACK_ssbgv LAPACK_NAME(ssbgv,SSBGV)
#define LAPACK_dsbgv LAPACK_NAME(dsbgv,DSBGV)
#define LAPACK_chbgv LAPACK_NAME(chbgv,CHBGV)
#define LAPACK_zhbgv LAPACK_NAME(zhbgv,ZHBGV)
#define LAPACK_ssbgvd LAPACK_NAME(ssbgvd,SSBGVD)
#define LAPACK_dsbgvd LAPACK_NAME(dsbgvd,DSBGVD)
#define LAPACK_chbgvd LAPACK_NAME(chbgvd,CHBGVD)
#define LAPACK_zhbgvd LAPACK_NAME(zhbgvd,ZHBGVD)
#define LAPACK_ssbgvx LAPACK_NAME(ssbgvx,SSBGVX)
#define LAPACK_dsbgvx LAPACK_NAME(dsbgvx,DSBGVX)
#define LAPACK_chbgvx LAPACK_NAME(chbgvx,CHBGVX)
#define LAPACK_zhbgvx LAPACK_NAME(zhbgvx,ZHBGVX)
#define LAPACK_sgges LAPACK_NAME(sgges,SGGES)
#define LAPACK_dgges LAPACK_NAME(dgges,DGGES)
#define LAPACK_cgges LAPACK_NAME(cgges,CGGES)
#define LAPACK_zgges LAPACK_NAME(zgges,ZGGES)
#define LAPACK_sggesx LAPACK_NAME(sggesx,SGGESX)
#define LAPACK_dggesx LAPACK_NAME(dggesx,DGGESX)
#define LAPACK_cggesx LAPACK_NAME(cggesx,CGGESX)
#define LAPACK_zggesx LAPACK_NAME(zggesx,ZGGESX)
#define LAPACK_sggev LAPACK_NAME(sggev,SGGEV)
#define LAPACK_dggev LAPACK_NAME(dggev,DGGEV)
#define LAPACK_cggev LAPACK_NAME(cggev,CGGEV)
#define LAPACK_zggev LAPACK_NAME(zggev,ZGGEV)
#define LAPACK_sggevx LAPACK_NAME(sggevx,SGGEVX)
#define LAPACK_dggevx LAPACK_NAME(dggevx,DGGEVX)
#define LAPACK_cggevx LAPACK_NAME(cggevx,CGGEVX)
#define LAPACK_zggevx LAPACK_NAME(zggevx,ZGGEVX)
#define LAPACK_dsfrk LAPACK_NAME(dsfrk,DSFRK)
#define LAPACK_ssfrk LAPACK_NAME(ssfrk,SSFRK)
#define LAPACK_zhfrk LAPACK_NAME(zhfrk,ZHFRK)
#define LAPACK_chfrk LAPACK_NAME(chfrk,CHFRK)
#define LAPACK_dtfsm LAPACK_NAME(dtfsm,DTFSM)
#define LAPACK_stfsm LAPACK_NAME(stfsm,STFSM)
#define LAPACK_ztfsm LAPACK_NAME(ztfsm,ZTFSM)
#define LAPACK_ctfsm LAPACK_NAME(ctfsm,CTFSM)
#define LAPACK_dtfttp LAPACK_NAME(dtfttp,DTFTTP)
#define LAPACK_stfttp LAPACK_NAME(stfttp,STFTTP)
#define LAPACK_ztfttp LAPACK_NAME(ztfttp,ZTFTTP)
#define LAPACK_ctfttp LAPACK_NAME(ctfttp,CTFTTP)
#define LAPACK_dtfttr LAPACK_NAME(dtfttr,DTFTTR)
#define LAPACK_stfttr LAPACK_NAME(stfttr,STFTTR)
#define LAPACK_ztfttr LAPACK_NAME(ztfttr,ZTFTTR)
#define LAPACK_ctfttr LAPACK_NAME(ctfttr,CTFTTR)
#define LAPACK_dtpttf LAPACK_NAME(dtpttf,DTPTTF)
#define LAPACK_stpttf LAPACK_NAME(stpttf,STPTTF)
#define LAPACK_ztpttf LAPACK_NAME(ztpttf,ZTPTTF)
#define LAPACK_ctpttf LAPACK_NAME(ctpttf,CTPTTF)
#define LAPACK_dtpttr LAPACK_NAME(dtpttr,DTPTTR)
#define LAPACK_stpttr LAPACK_NAME(stpttr,STPTTR)
#define LAPACK_ztpttr LAPACK_NAME(ztpttr,ZTPTTR)
#define LAPACK_ctpttr LAPACK_NAME(ctpttr,CTPTTR)
#define LAPACK_dtrttf LAPACK_NAME(dtrttf,DTRTTF)
#define LAPACK_strttf LAPACK_NAME(strttf,STRTTF)
#define LAPACK_ztrttf LAPACK_NAME(ztrttf,ZTRTTF)
#define LAPACK_ctrttf LAPACK_NAME(ctrttf,CTRTTF)
#define LAPACK_dtrttp LAPACK_NAME(dtrttp,DTRTTP)
#define LAPACK_strttp LAPACK_NAME(strttp,STRTTP)
#define LAPACK_ztrttp LAPACK_NAME(ztrttp,ZTRTTP)
#define LAPACK_ctrttp LAPACK_NAME(ctrttp,CTRTTP)
#define LAPACK_sgeqrfp LAPACK_NAME(sgeqrfp,SGEQRFP)
#define LAPACK_dgeqrfp LAPACK_NAME(dgeqrfp,DGEQRFP)
#define LAPACK_cgeqrfp LAPACK_NAME(cgeqrfp,CGEQRFP)
#define LAPACK_zgeqrfp LAPACK_NAME(zgeqrfp,ZGEQRFP)

void LAPACK_sgetrf( lapack_int* m, lapack_int* n, float* a, lapack_int* lda,
                    lapack_int* ipiv, lapack_int *info );
void LAPACK_dgetrf( lapack_int* m, lapack_int* n, double* a, lapack_int* lda,
                    lapack_int* ipiv, lapack_int *info );
void LAPACK_cgetrf( lapack_int* m, lapack_int* n, lapack_complex_float* a,
                    lapack_int* lda, lapack_int* ipiv, lapack_int *info );
void LAPACK_zgetrf( lapack_int* m, lapack_int* n, lapack_complex_double* a,
                    lapack_int* lda, lapack_int* ipiv, lapack_int *info );
void LAPACK_sgbtrf( lapack_int* m, lapack_int* n, lapack_int* kl,
                    lapack_int* ku, float* ab, lapack_int* ldab,
                    lapack_int* ipiv, lapack_int *info );
void LAPACK_dgbtrf( lapack_int* m, lapack_int* n, lapack_int* kl,
                    lapack_int* ku, double* ab, lapack_int* ldab,
                    lapack_int* ipiv, lapack_int *info );
void LAPACK_cgbtrf( lapack_int* m, lapack_int* n, lapack_int* kl,
                    lapack_int* ku, lapack_complex_float* ab, lapack_int* ldab,
                    lapack_int* ipiv, lapack_int *info );
void LAPACK_zgbtrf( lapack_int* m, lapack_int* n, lapack_int* kl,
                    lapack_int* ku, lapack_complex_double* ab, lapack_int* ldab,
                    lapack_int* ipiv, lapack_int *info );
void LAPACK_sgttrf( lapack_int* n, float* dl, float* d, float* du, float* du2,
                    lapack_int* ipiv, lapack_int *info );
void LAPACK_dgttrf( lapack_int* n, double* dl, double* d, double* du,
                    double* du2, lapack_int* ipiv, lapack_int *info );
void LAPACK_cgttrf( lapack_int* n, lapack_complex_float* dl,
                    lapack_complex_float* d, lapack_complex_float* du,
                    lapack_complex_float* du2, lapack_int* ipiv,
                    lapack_int *info );
void LAPACK_zgttrf( lapack_int* n, lapack_complex_double* dl,
                    lapack_complex_double* d, lapack_complex_double* du,
                    lapack_complex_double* du2, lapack_int* ipiv,
                    lapack_int *info );
void LAPACK_spotrf( char* uplo, lapack_int* n, float* a, lapack_int* lda,
                    lapack_int *info );
void LAPACK_dpotrf( char* uplo, lapack_int* n, double* a, lapack_int* lda,
                    lapack_int *info );
void LAPACK_cpotrf( char* uplo, lapack_int* n, lapack_complex_float* a,
                    lapack_int* lda, lapack_int *info );
void LAPACK_zpotrf( char* uplo, lapack_int* n, lapack_complex_double* a,
                    lapack_int* lda, lapack_int *info );
void LAPACK_dpstrf( char* uplo, lapack_int* n, double* a, lapack_int* lda,
                    lapack_int* piv, lapack_int* rank, double* tol,
                    double* work, lapack_int *info );
void LAPACK_spstrf( char* uplo, lapack_int* n, float* a, lapack_int* lda,
                    lapack_int* piv, lapack_int* rank, float* tol, float* work,
                    lapack_int *info );
void LAPACK_zpstrf( char* uplo, lapack_int* n, lapack_complex_double* a,
                    lapack_int* lda, lapack_int* piv, lapack_int* rank,
                    double* tol, double* work, lapack_int *info );
void LAPACK_cpstrf( char* uplo, lapack_int* n, lapack_complex_float* a,
                    lapack_int* lda, lapack_int* piv, lapack_int* rank,
                    float* tol, float* work, lapack_int *info );
void LAPACK_dpftrf( char* transr, char* uplo, lapack_int* n, double* a,
                    lapack_int *info );
void LAPACK_spftrf( char* transr, char* uplo, lapack_int* n, float* a,
                    lapack_int *info );
void LAPACK_zpftrf( char* transr, char* uplo, lapack_int* n,
                    lapack_complex_double* a, lapack_int *info );
void LAPACK_cpftrf( char* transr, char* uplo, lapack_int* n,
                    lapack_complex_float* a, lapack_int *info );
void LAPACK_spptrf( char* uplo, lapack_int* n, float* ap, lapack_int *info );
void LAPACK_dpptrf( char* uplo, lapack_int* n, double* ap, lapack_int *info );
void LAPACK_cpptrf( char* uplo, lapack_int* n, lapack_complex_float* ap,
                    lapack_int *info );
void LAPACK_zpptrf( char* uplo, lapack_int* n, lapack_complex_double* ap,
                    lapack_int *info );
void LAPACK_spbtrf( char* uplo, lapack_int* n, lapack_int* kd, float* ab,
                    lapack_int* ldab, lapack_int *info );
void LAPACK_dpbtrf( char* uplo, lapack_int* n, lapack_int* kd, double* ab,
                    lapack_int* ldab, lapack_int *info );
void LAPACK_cpbtrf( char* uplo, lapack_int* n, lapack_int* kd,
                    lapack_complex_float* ab, lapack_int* ldab,
                    lapack_int *info );
void LAPACK_zpbtrf( char* uplo, lapack_int* n, lapack_int* kd,
                    lapack_complex_double* ab, lapack_int* ldab,
                    lapack_int *info );
void LAPACK_spttrf( lapack_int* n, float* d, float* e, lapack_int *info );
void LAPACK_dpttrf( lapack_int* n, double* d, double* e, lapack_int *info );
void LAPACK_cpttrf( lapack_int* n, float* d, lapack_complex_float* e,
                    lapack_int *info );
void LAPACK_zpttrf( lapack_int* n, double* d, lapack_complex_double* e,
                    lapack_int *info );
void LAPACK_ssytrf( char* uplo, lapack_int* n, float* a, lapack_int* lda,
                    lapack_int* ipiv, float* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_dsytrf( char* uplo, lapack_int* n, double* a, lapack_int* lda,
                    lapack_int* ipiv, double* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_csytrf( char* uplo, lapack_int* n, lapack_complex_float* a,
                    lapack_int* lda, lapack_int* ipiv,
                    lapack_complex_float* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_zsytrf( char* uplo, lapack_int* n, lapack_complex_double* a,
                    lapack_int* lda, lapack_int* ipiv,
                    lapack_complex_double* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_chetrf( char* uplo, lapack_int* n, lapack_complex_float* a,
                    lapack_int* lda, lapack_int* ipiv,
                    lapack_complex_float* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_zhetrf( char* uplo, lapack_int* n, lapack_complex_double* a,
                    lapack_int* lda, lapack_int* ipiv,
                    lapack_complex_double* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_ssptrf( char* uplo, lapack_int* n, float* ap, lapack_int* ipiv,
                    lapack_int *info );
void LAPACK_dsptrf( char* uplo, lapack_int* n, double* ap, lapack_int* ipiv,
                    lapack_int *info );
void LAPACK_csptrf( char* uplo, lapack_int* n, lapack_complex_float* ap,
                    lapack_int* ipiv, lapack_int *info );
void LAPACK_zsptrf( char* uplo, lapack_int* n, lapack_complex_double* ap,
                    lapack_int* ipiv, lapack_int *info );
void LAPACK_chptrf( char* uplo, lapack_int* n, lapack_complex_float* ap,
                    lapack_int* ipiv, lapack_int *info );
void LAPACK_zhptrf( char* uplo, lapack_int* n, lapack_complex_double* ap,
                    lapack_int* ipiv, lapack_int *info );
void LAPACK_sgetrs( char* trans, lapack_int* n, lapack_int* nrhs,
                    const float* a, lapack_int* lda, const lapack_int* ipiv,
                    float* b, lapack_int* ldb, lapack_int *info );
void LAPACK_dgetrs( char* trans, lapack_int* n, lapack_int* nrhs,
                    const double* a, lapack_int* lda, const lapack_int* ipiv,
                    double* b, lapack_int* ldb, lapack_int *info );
void LAPACK_cgetrs( char* trans, lapack_int* n, lapack_int* nrhs,
                    const lapack_complex_float* a, lapack_int* lda,
                    const lapack_int* ipiv, lapack_complex_float* b,
                    lapack_int* ldb, lapack_int *info );
void LAPACK_zgetrs( char* trans, lapack_int* n, lapack_int* nrhs,
                    const lapack_complex_double* a, lapack_int* lda,
                    const lapack_int* ipiv, lapack_complex_double* b,
                    lapack_int* ldb, lapack_int *info );
void LAPACK_sgbtrs( char* trans, lapack_int* n, lapack_int* kl, lapack_int* ku,
                    lapack_int* nrhs, const float* ab, lapack_int* ldab,
                    const lapack_int* ipiv, float* b, lapack_int* ldb,
                    lapack_int *info );
void LAPACK_dgbtrs( char* trans, lapack_int* n, lapack_int* kl, lapack_int* ku,
                    lapack_int* nrhs, const double* ab, lapack_int* ldab,
                    const lapack_int* ipiv, double* b, lapack_int* ldb,
                    lapack_int *info );
void LAPACK_cgbtrs( char* trans, lapack_int* n, lapack_int* kl, lapack_int* ku,
                    lapack_int* nrhs, const lapack_complex_float* ab,
                    lapack_int* ldab, const lapack_int* ipiv,
                    lapack_complex_float* b, lapack_int* ldb,
                    lapack_int *info );
void LAPACK_zgbtrs( char* trans, lapack_int* n, lapack_int* kl, lapack_int* ku,
                    lapack_int* nrhs, const lapack_complex_double* ab,
                    lapack_int* ldab, const lapack_int* ipiv,
                    lapack_complex_double* b, lapack_int* ldb,
                    lapack_int *info );
void LAPACK_sgttrs( char* trans, lapack_int* n, lapack_int* nrhs,
                    const float* dl, const float* d, const float* du,
                    const float* du2, const lapack_int* ipiv, float* b,
                    lapack_int* ldb, lapack_int *info );
void LAPACK_dgttrs( char* trans, lapack_int* n, lapack_int* nrhs,
                    const double* dl, const double* d, const double* du,
                    const double* du2, const lapack_int* ipiv, double* b,
                    lapack_int* ldb, lapack_int *info );
void LAPACK_cgttrs( char* trans, lapack_int* n, lapack_int* nrhs,
                    const lapack_complex_float* dl,
                    const lapack_complex_float* d,
                    const lapack_complex_float* du,
                    const lapack_complex_float* du2, const lapack_int* ipiv,
                    lapack_complex_float* b, lapack_int* ldb,
                    lapack_int *info );
void LAPACK_zgttrs( char* trans, lapack_int* n, lapack_int* nrhs,
                    const lapack_complex_double* dl,
                    const lapack_complex_double* d,
                    const lapack_complex_double* du,
                    const lapack_complex_double* du2, const lapack_int* ipiv,
                    lapack_complex_double* b, lapack_int* ldb,
                    lapack_int *info );
void LAPACK_spotrs( char* uplo, lapack_int* n, lapack_int* nrhs, const float* a,
                    lapack_int* lda, float* b, lapack_int* ldb,
                    lapack_int *info );
void LAPACK_dpotrs( char* uplo, lapack_int* n, lapack_int* nrhs,
                    const double* a, lapack_int* lda, double* b,
                    lapack_int* ldb, lapack_int *info );
void LAPACK_cpotrs( char* uplo, lapack_int* n, lapack_int* nrhs,
                    const lapack_complex_float* a, lapack_int* lda,
                    lapack_complex_float* b, lapack_int* ldb,
                    lapack_int *info );
void LAPACK_zpotrs( char* uplo, lapack_int* n, lapack_int* nrhs,
                    const lapack_complex_double* a, lapack_int* lda,
                    lapack_complex_double* b, lapack_int* ldb,
                    lapack_int *info );
void LAPACK_dpftrs( char* transr, char* uplo, lapack_int* n, lapack_int* nrhs,
                    const double* a, double* b, lapack_int* ldb,
                    lapack_int *info );
void LAPACK_spftrs( char* transr, char* uplo, lapack_int* n, lapack_int* nrhs,
                    const float* a, float* b, lapack_int* ldb,
                    lapack_int *info );
void LAPACK_zpftrs( char* transr, char* uplo, lapack_int* n, lapack_int* nrhs,
                    const lapack_complex_double* a, lapack_complex_double* b,
                    lapack_int* ldb, lapack_int *info );
void LAPACK_cpftrs( char* transr, char* uplo, lapack_int* n, lapack_int* nrhs,
                    const lapack_complex_float* a, lapack_complex_float* b,
                    lapack_int* ldb, lapack_int *info );
void LAPACK_spptrs( char* uplo, lapack_int* n, lapack_int* nrhs,
                    const float* ap, float* b, lapack_int* ldb,
                    lapack_int *info );
void LAPACK_dpptrs( char* uplo, lapack_int* n, lapack_int* nrhs,
                    const double* ap, double* b, lapack_int* ldb,
                    lapack_int *info );
void LAPACK_cpptrs( char* uplo, lapack_int* n, lapack_int* nrhs,
                    const lapack_complex_float* ap, lapack_complex_float* b,
                    lapack_int* ldb, lapack_int *info );
void LAPACK_zpptrs( char* uplo, lapack_int* n, lapack_int* nrhs,
                    const lapack_complex_double* ap, lapack_complex_double* b,
                    lapack_int* ldb, lapack_int *info );
void LAPACK_spbtrs( char* uplo, lapack_int* n, lapack_int* kd, lapack_int* nrhs,
                    const float* ab, lapack_int* ldab, float* b,
                    lapack_int* ldb, lapack_int *info );
void LAPACK_dpbtrs( char* uplo, lapack_int* n, lapack_int* kd, lapack_int* nrhs,
                    const double* ab, lapack_int* ldab, double* b,
                    lapack_int* ldb, lapack_int *info );
void LAPACK_cpbtrs( char* uplo, lapack_int* n, lapack_int* kd, lapack_int* nrhs,
                    const lapack_complex_float* ab, lapack_int* ldab,
                    lapack_complex_float* b, lapack_int* ldb,
                    lapack_int *info );
void LAPACK_zpbtrs( char* uplo, lapack_int* n, lapack_int* kd, lapack_int* nrhs,
                    const lapack_complex_double* ab, lapack_int* ldab,
                    lapack_complex_double* b, lapack_int* ldb,
                    lapack_int *info );
void LAPACK_spttrs( lapack_int* n, lapack_int* nrhs, const float* d,
                    const float* e, float* b, lapack_int* ldb,
                    lapack_int *info );
void LAPACK_dpttrs( lapack_int* n, lapack_int* nrhs, const double* d,
                    const double* e, double* b, lapack_int* ldb,
                    lapack_int *info );
void LAPACK_cpttrs( char* uplo, lapack_int* n, lapack_int* nrhs, const float* d,
                    const lapack_complex_float* e, lapack_complex_float* b,
                    lapack_int* ldb, lapack_int *info );
void LAPACK_zpttrs( char* uplo, lapack_int* n, lapack_int* nrhs,
                    const double* d, const lapack_complex_double* e,
                    lapack_complex_double* b, lapack_int* ldb,
                    lapack_int *info );
void LAPACK_ssytrs( char* uplo, lapack_int* n, lapack_int* nrhs, const float* a,
                    lapack_int* lda, const lapack_int* ipiv, float* b,
                    lapack_int* ldb, lapack_int *info );
void LAPACK_dsytrs( char* uplo, lapack_int* n, lapack_int* nrhs,
                    const double* a, lapack_int* lda, const lapack_int* ipiv,
                    double* b, lapack_int* ldb, lapack_int *info );
void LAPACK_csytrs( char* uplo, lapack_int* n, lapack_int* nrhs,
                    const lapack_complex_float* a, lapack_int* lda,
                    const lapack_int* ipiv, lapack_complex_float* b,
                    lapack_int* ldb, lapack_int *info );
void LAPACK_zsytrs( char* uplo, lapack_int* n, lapack_int* nrhs,
                    const lapack_complex_double* a, lapack_int* lda,
                    const lapack_int* ipiv, lapack_complex_double* b,
                    lapack_int* ldb, lapack_int *info );
void LAPACK_chetrs( char* uplo, lapack_int* n, lapack_int* nrhs,
                    const lapack_complex_float* a, lapack_int* lda,
                    const lapack_int* ipiv, lapack_complex_float* b,
                    lapack_int* ldb, lapack_int *info );
void LAPACK_zhetrs( char* uplo, lapack_int* n, lapack_int* nrhs,
                    const lapack_complex_double* a, lapack_int* lda,
                    const lapack_int* ipiv, lapack_complex_double* b,
                    lapack_int* ldb, lapack_int *info );
void LAPACK_ssptrs( char* uplo, lapack_int* n, lapack_int* nrhs,
                    const float* ap, const lapack_int* ipiv, float* b,
                    lapack_int* ldb, lapack_int *info );
void LAPACK_dsptrs( char* uplo, lapack_int* n, lapack_int* nrhs,
                    const double* ap, const lapack_int* ipiv, double* b,
                    lapack_int* ldb, lapack_int *info );
void LAPACK_csptrs( char* uplo, lapack_int* n, lapack_int* nrhs,
                    const lapack_complex_float* ap, const lapack_int* ipiv,
                    lapack_complex_float* b, lapack_int* ldb,
                    lapack_int *info );
void LAPACK_zsptrs( char* uplo, lapack_int* n, lapack_int* nrhs,
                    const lapack_complex_double* ap, const lapack_int* ipiv,
                    lapack_complex_double* b, lapack_int* ldb,
                    lapack_int *info );
void LAPACK_chptrs( char* uplo, lapack_int* n, lapack_int* nrhs,
                    const lapack_complex_float* ap, const lapack_int* ipiv,
                    lapack_complex_float* b, lapack_int* ldb,
                    lapack_int *info );
void LAPACK_zhptrs( char* uplo, lapack_int* n, lapack_int* nrhs,
                    const lapack_complex_double* ap, const lapack_int* ipiv,
                    lapack_complex_double* b, lapack_int* ldb,
                    lapack_int *info );
void LAPACK_strtrs( char* uplo, char* trans, char* diag, lapack_int* n,
                    lapack_int* nrhs, const float* a, lapack_int* lda, float* b,
                    lapack_int* ldb, lapack_int *info );
void LAPACK_dtrtrs( char* uplo, char* trans, char* diag, lapack_int* n,
                    lapack_int* nrhs, const double* a, lapack_int* lda,
                    double* b, lapack_int* ldb, lapack_int *info );
void LAPACK_ctrtrs( char* uplo, char* trans, char* diag, lapack_int* n,
                    lapack_int* nrhs, const lapack_complex_float* a,
                    lapack_int* lda, lapack_complex_float* b, lapack_int* ldb,
                    lapack_int *info );
void LAPACK_ztrtrs( char* uplo, char* trans, char* diag, lapack_int* n,
                    lapack_int* nrhs, const lapack_complex_double* a,
                    lapack_int* lda, lapack_complex_double* b, lapack_int* ldb,
                    lapack_int *info );
void LAPACK_stptrs( char* uplo, char* trans, char* diag, lapack_int* n,
                    lapack_int* nrhs, const float* ap, float* b,
                    lapack_int* ldb, lapack_int *info );
void LAPACK_dtptrs( char* uplo, char* trans, char* diag, lapack_int* n,
                    lapack_int* nrhs, const double* ap, double* b,
                    lapack_int* ldb, lapack_int *info );
void LAPACK_ctptrs( char* uplo, char* trans, char* diag, lapack_int* n,
                    lapack_int* nrhs, const lapack_complex_float* ap,
                    lapack_complex_float* b, lapack_int* ldb,
                    lapack_int *info );
void LAPACK_ztptrs( char* uplo, char* trans, char* diag, lapack_int* n,
                    lapack_int* nrhs, const lapack_complex_double* ap,
                    lapack_complex_double* b, lapack_int* ldb,
                    lapack_int *info );
void LAPACK_stbtrs( char* uplo, char* trans, char* diag, lapack_int* n,
                    lapack_int* kd, lapack_int* nrhs, const float* ab,
                    lapack_int* ldab, float* b, lapack_int* ldb,
                    lapack_int *info );
void LAPACK_dtbtrs( char* uplo, char* trans, char* diag, lapack_int* n,
                    lapack_int* kd, lapack_int* nrhs, const double* ab,
                    lapack_int* ldab, double* b, lapack_int* ldb,
                    lapack_int *info );
void LAPACK_ctbtrs( char* uplo, char* trans, char* diag, lapack_int* n,
                    lapack_int* kd, lapack_int* nrhs,
                    const lapack_complex_float* ab, lapack_int* ldab,
                    lapack_complex_float* b, lapack_int* ldb,
                    lapack_int *info );
void LAPACK_ztbtrs( char* uplo, char* trans, char* diag, lapack_int* n,
                    lapack_int* kd, lapack_int* nrhs,
                    const lapack_complex_double* ab, lapack_int* ldab,
                    lapack_complex_double* b, lapack_int* ldb,
                    lapack_int *info );
void LAPACK_sgecon( char* norm, lapack_int* n, const float* a, lapack_int* lda,
                    float* anorm, float* rcond, float* work, lapack_int* iwork,
                    lapack_int *info );
void LAPACK_dgecon( char* norm, lapack_int* n, const double* a, lapack_int* lda,
                    double* anorm, double* rcond, double* work,
                    lapack_int* iwork, lapack_int *info );
void LAPACK_cgecon( char* norm, lapack_int* n, const lapack_complex_float* a,
                    lapack_int* lda, float* anorm, float* rcond,
                    lapack_complex_float* work, float* rwork,
                    lapack_int *info );
void LAPACK_zgecon( char* norm, lapack_int* n, const lapack_complex_double* a,
                    lapack_int* lda, double* anorm, double* rcond,
                    lapack_complex_double* work, double* rwork,
                    lapack_int *info );
void LAPACK_sgbcon( char* norm, lapack_int* n, lapack_int* kl, lapack_int* ku,
                    const float* ab, lapack_int* ldab, const lapack_int* ipiv,
                    float* anorm, float* rcond, float* work, lapack_int* iwork,
                    lapack_int *info );
void LAPACK_dgbcon( char* norm, lapack_int* n, lapack_int* kl, lapack_int* ku,
                    const double* ab, lapack_int* ldab, const lapack_int* ipiv,
                    double* anorm, double* rcond, double* work,
                    lapack_int* iwork, lapack_int *info );
void LAPACK_cgbcon( char* norm, lapack_int* n, lapack_int* kl, lapack_int* ku,
                    const lapack_complex_float* ab, lapack_int* ldab,
                    const lapack_int* ipiv, float* anorm, float* rcond,
                    lapack_complex_float* work, float* rwork,
                    lapack_int *info );
void LAPACK_zgbcon( char* norm, lapack_int* n, lapack_int* kl, lapack_int* ku,
                    const lapack_complex_double* ab, lapack_int* ldab,
                    const lapack_int* ipiv, double* anorm, double* rcond,
                    lapack_complex_double* work, double* rwork,
                    lapack_int *info );
void LAPACK_sgtcon( char* norm, lapack_int* n, const float* dl, const float* d,
                    const float* du, const float* du2, const lapack_int* ipiv,
                    float* anorm, float* rcond, float* work, lapack_int* iwork,
                    lapack_int *info );
void LAPACK_dgtcon( char* norm, lapack_int* n, const double* dl,
                    const double* d, const double* du, const double* du2,
                    const lapack_int* ipiv, double* anorm, double* rcond,
                    double* work, lapack_int* iwork, lapack_int *info );
void LAPACK_cgtcon( char* norm, lapack_int* n, const lapack_complex_float* dl,
                    const lapack_complex_float* d,
                    const lapack_complex_float* du,
                    const lapack_complex_float* du2, const lapack_int* ipiv,
                    float* anorm, float* rcond, lapack_complex_float* work,
                    lapack_int *info );
void LAPACK_zgtcon( char* norm, lapack_int* n, const lapack_complex_double* dl,
                    const lapack_complex_double* d,
                    const lapack_complex_double* du,
                    const lapack_complex_double* du2, const lapack_int* ipiv,
                    double* anorm, double* rcond, lapack_complex_double* work,
                    lapack_int *info );
void LAPACK_spocon( char* uplo, lapack_int* n, const float* a, lapack_int* lda,
                    float* anorm, float* rcond, float* work, lapack_int* iwork,
                    lapack_int *info );
void LAPACK_dpocon( char* uplo, lapack_int* n, const double* a, lapack_int* lda,
                    double* anorm, double* rcond, double* work,
                    lapack_int* iwork, lapack_int *info );
void LAPACK_cpocon( char* uplo, lapack_int* n, const lapack_complex_float* a,
                    lapack_int* lda, float* anorm, float* rcond,
                    lapack_complex_float* work, float* rwork,
                    lapack_int *info );
void LAPACK_zpocon( char* uplo, lapack_int* n, const lapack_complex_double* a,
                    lapack_int* lda, double* anorm, double* rcond,
                    lapack_complex_double* work, double* rwork,
                    lapack_int *info );
void LAPACK_sppcon( char* uplo, lapack_int* n, const float* ap, float* anorm,
                    float* rcond, float* work, lapack_int* iwork,
                    lapack_int *info );
void LAPACK_dppcon( char* uplo, lapack_int* n, const double* ap, double* anorm,
                    double* rcond, double* work, lapack_int* iwork,
                    lapack_int *info );
void LAPACK_cppcon( char* uplo, lapack_int* n, const lapack_complex_float* ap,
                    float* anorm, float* rcond, lapack_complex_float* work,
                    float* rwork, lapack_int *info );
void LAPACK_zppcon( char* uplo, lapack_int* n, const lapack_complex_double* ap,
                    double* anorm, double* rcond, lapack_complex_double* work,
                    double* rwork, lapack_int *info );
void LAPACK_spbcon( char* uplo, lapack_int* n, lapack_int* kd, const float* ab,
                    lapack_int* ldab, float* anorm, float* rcond, float* work,
                    lapack_int* iwork, lapack_int *info );
void LAPACK_dpbcon( char* uplo, lapack_int* n, lapack_int* kd, const double* ab,
                    lapack_int* ldab, double* anorm, double* rcond,
                    double* work, lapack_int* iwork, lapack_int *info );
void LAPACK_cpbcon( char* uplo, lapack_int* n, lapack_int* kd,
                    const lapack_complex_float* ab, lapack_int* ldab,
                    float* anorm, float* rcond, lapack_complex_float* work,
                    float* rwork, lapack_int *info );
void LAPACK_zpbcon( char* uplo, lapack_int* n, lapack_int* kd,
                    const lapack_complex_double* ab, lapack_int* ldab,
                    double* anorm, double* rcond, lapack_complex_double* work,
                    double* rwork, lapack_int *info );
void LAPACK_sptcon( lapack_int* n, const float* d, const float* e, float* anorm,
                    float* rcond, float* work, lapack_int *info );
void LAPACK_dptcon( lapack_int* n, const double* d, const double* e,
                    double* anorm, double* rcond, double* work,
                    lapack_int *info );
void LAPACK_cptcon( lapack_int* n, const float* d,
                    const lapack_complex_float* e, float* anorm, float* rcond,
                    float* work, lapack_int *info );
void LAPACK_zptcon( lapack_int* n, const double* d,
                    const lapack_complex_double* e, double* anorm,
                    double* rcond, double* work, lapack_int *info );
void LAPACK_ssycon( char* uplo, lapack_int* n, const float* a, lapack_int* lda,
                    const lapack_int* ipiv, float* anorm, float* rcond,
                    float* work, lapack_int* iwork, lapack_int *info );
void LAPACK_dsycon( char* uplo, lapack_int* n, const double* a, lapack_int* lda,
                    const lapack_int* ipiv, double* anorm, double* rcond,
                    double* work, lapack_int* iwork, lapack_int *info );
void LAPACK_csycon( char* uplo, lapack_int* n, const lapack_complex_float* a,
                    lapack_int* lda, const lapack_int* ipiv, float* anorm,
                    float* rcond, lapack_complex_float* work,
                    lapack_int *info );
void LAPACK_zsycon( char* uplo, lapack_int* n, const lapack_complex_double* a,
                    lapack_int* lda, const lapack_int* ipiv, double* anorm,
                    double* rcond, lapack_complex_double* work,
                    lapack_int *info );
void LAPACK_checon( char* uplo, lapack_int* n, const lapack_complex_float* a,
                    lapack_int* lda, const lapack_int* ipiv, float* anorm,
                    float* rcond, lapack_complex_float* work,
                    lapack_int *info );
void LAPACK_zhecon( char* uplo, lapack_int* n, const lapack_complex_double* a,
                    lapack_int* lda, const lapack_int* ipiv, double* anorm,
                    double* rcond, lapack_complex_double* work,
                    lapack_int *info );
void LAPACK_sspcon( char* uplo, lapack_int* n, const float* ap,
                    const lapack_int* ipiv, float* anorm, float* rcond,
                    float* work, lapack_int* iwork, lapack_int *info );
void LAPACK_dspcon( char* uplo, lapack_int* n, const double* ap,
                    const lapack_int* ipiv, double* anorm, double* rcond,
                    double* work, lapack_int* iwork, lapack_int *info );
void LAPACK_cspcon( char* uplo, lapack_int* n, const lapack_complex_float* ap,
                    const lapack_int* ipiv, float* anorm, float* rcond,
                    lapack_complex_float* work, lapack_int *info );
void LAPACK_zspcon( char* uplo, lapack_int* n, const lapack_complex_double* ap,
                    const lapack_int* ipiv, double* anorm, double* rcond,
                    lapack_complex_double* work, lapack_int *info );
void LAPACK_chpcon( char* uplo, lapack_int* n, const lapack_complex_float* ap,
                    const lapack_int* ipiv, float* anorm, float* rcond,
                    lapack_complex_float* work, lapack_int *info );
void LAPACK_zhpcon( char* uplo, lapack_int* n, const lapack_complex_double* ap,
                    const lapack_int* ipiv, double* anorm, double* rcond,
                    lapack_complex_double* work, lapack_int *info );
void LAPACK_strcon( char* norm, char* uplo, char* diag, lapack_int* n,
                    const float* a, lapack_int* lda, float* rcond, float* work,
                    lapack_int* iwork, lapack_int *info );
void LAPACK_dtrcon( char* norm, char* uplo, char* diag, lapack_int* n,
                    const double* a, lapack_int* lda, double* rcond,
                    double* work, lapack_int* iwork, lapack_int *info );
void LAPACK_ctrcon( char* norm, char* uplo, char* diag, lapack_int* n,
                    const lapack_complex_float* a, lapack_int* lda,
                    float* rcond, lapack_complex_float* work, float* rwork,
                    lapack_int *info );
void LAPACK_ztrcon( char* norm, char* uplo, char* diag, lapack_int* n,
                    const lapack_complex_double* a, lapack_int* lda,
                    double* rcond, lapack_complex_double* work, double* rwork,
                    lapack_int *info );
void LAPACK_stpcon( char* norm, char* uplo, char* diag, lapack_int* n,
                    const float* ap, float* rcond, float* work,
                    lapack_int* iwork, lapack_int *info );
void LAPACK_dtpcon( char* norm, char* uplo, char* diag, lapack_int* n,
                    const double* ap, double* rcond, double* work,
                    lapack_int* iwork, lapack_int *info );
void LAPACK_ctpcon( char* norm, char* uplo, char* diag, lapack_int* n,
                    const lapack_complex_float* ap, float* rcond,
                    lapack_complex_float* work, float* rwork,
                    lapack_int *info );
void LAPACK_ztpcon( char* norm, char* uplo, char* diag, lapack_int* n,
                    const lapack_complex_double* ap, double* rcond,
                    lapack_complex_double* work, double* rwork,
                    lapack_int *info );
void LAPACK_stbcon( char* norm, char* uplo, char* diag, lapack_int* n,
                    lapack_int* kd, const float* ab, lapack_int* ldab,
                    float* rcond, float* work, lapack_int* iwork,
                    lapack_int *info );
void LAPACK_dtbcon( char* norm, char* uplo, char* diag, lapack_int* n,
                    lapack_int* kd, const double* ab, lapack_int* ldab,
                    double* rcond, double* work, lapack_int* iwork,
                    lapack_int *info );
void LAPACK_ctbcon( char* norm, char* uplo, char* diag, lapack_int* n,
                    lapack_int* kd, const lapack_complex_float* ab,
                    lapack_int* ldab, float* rcond, lapack_complex_float* work,
                    float* rwork, lapack_int *info );
void LAPACK_ztbcon( char* norm, char* uplo, char* diag, lapack_int* n,
                    lapack_int* kd, const lapack_complex_double* ab,
                    lapack_int* ldab, double* rcond,
                    lapack_complex_double* work, double* rwork,
                    lapack_int *info );
void LAPACK_sgerfs( char* trans, lapack_int* n, lapack_int* nrhs,
                    const float* a, lapack_int* lda, const float* af,
                    lapack_int* ldaf, const lapack_int* ipiv, const float* b,
                    lapack_int* ldb, float* x, lapack_int* ldx, float* ferr,
                    float* berr, float* work, lapack_int* iwork,
                    lapack_int *info );
void LAPACK_dgerfs( char* trans, lapack_int* n, lapack_int* nrhs,
                    const double* a, lapack_int* lda, const double* af,
                    lapack_int* ldaf, const lapack_int* ipiv, const double* b,
                    lapack_int* ldb, double* x, lapack_int* ldx, double* ferr,
                    double* berr, double* work, lapack_int* iwork,
                    lapack_int *info );
void LAPACK_cgerfs( char* trans, lapack_int* n, lapack_int* nrhs,
                    const lapack_complex_float* a, lapack_int* lda,
                    const lapack_complex_float* af, lapack_int* ldaf,
                    const lapack_int* ipiv, const lapack_complex_float* b,
                    lapack_int* ldb, lapack_complex_float* x, lapack_int* ldx,
                    float* ferr, float* berr, lapack_complex_float* work,
                    float* rwork, lapack_int *info );
void LAPACK_zgerfs( char* trans, lapack_int* n, lapack_int* nrhs,
                    const lapack_complex_double* a, lapack_int* lda,
                    const lapack_complex_double* af, lapack_int* ldaf,
                    const lapack_int* ipiv, const lapack_complex_double* b,
                    lapack_int* ldb, lapack_complex_double* x, lapack_int* ldx,
                    double* ferr, double* berr, lapack_complex_double* work,
                    double* rwork, lapack_int *info );
void LAPACK_dgerfsx( char* trans, char* equed, lapack_int* n, lapack_int* nrhs,
                     const double* a, lapack_int* lda, const double* af,
                     lapack_int* ldaf, const lapack_int* ipiv, const double* r,
                     const double* c, const double* b, lapack_int* ldb,
                     double* x, lapack_int* ldx, double* rcond, double* berr,
                     lapack_int* n_err_bnds, double* err_bnds_norm,
                     double* err_bnds_comp, lapack_int* nparams, double* params,
                     double* work, lapack_int* iwork, lapack_int *info );
void LAPACK_sgerfsx( char* trans, char* equed, lapack_int* n, lapack_int* nrhs,
                     const float* a, lapack_int* lda, const float* af,
                     lapack_int* ldaf, const lapack_int* ipiv, const float* r,
                     const float* c, const float* b, lapack_int* ldb, float* x,
                     lapack_int* ldx, float* rcond, float* berr,
                     lapack_int* n_err_bnds, float* err_bnds_norm,
                     float* err_bnds_comp, lapack_int* nparams, float* params,
                     float* work, lapack_int* iwork, lapack_int *info );
void LAPACK_zgerfsx( char* trans, char* equed, lapack_int* n, lapack_int* nrhs,
                     const lapack_complex_double* a, lapack_int* lda,
                     const lapack_complex_double* af, lapack_int* ldaf,
                     const lapack_int* ipiv, const double* r, const double* c,
                     const lapack_complex_double* b, lapack_int* ldb,
                     lapack_complex_double* x, lapack_int* ldx, double* rcond,
                     double* berr, lapack_int* n_err_bnds,
                     double* err_bnds_norm, double* err_bnds_comp,
                     lapack_int* nparams, double* params,
                     lapack_complex_double* work, double* rwork,
                     lapack_int *info );
void LAPACK_cgerfsx( char* trans, char* equed, lapack_int* n, lapack_int* nrhs,
                     const lapack_complex_float* a, lapack_int* lda,
                     const lapack_complex_float* af, lapack_int* ldaf,
                     const lapack_int* ipiv, const float* r, const float* c,
                     const lapack_complex_float* b, lapack_int* ldb,
                     lapack_complex_float* x, lapack_int* ldx, float* rcond,
                     float* berr, lapack_int* n_err_bnds, float* err_bnds_norm,
                     float* err_bnds_comp, lapack_int* nparams, float* params,
                     lapack_complex_float* work, float* rwork,
                     lapack_int *info );
void LAPACK_sgbrfs( char* trans, lapack_int* n, lapack_int* kl, lapack_int* ku,
                    lapack_int* nrhs, const float* ab, lapack_int* ldab,
                    const float* afb, lapack_int* ldafb, const lapack_int* ipiv,
                    const float* b, lapack_int* ldb, float* x, lapack_int* ldx,
                    float* ferr, float* berr, float* work, lapack_int* iwork,
                    lapack_int *info );
void LAPACK_dgbrfs( char* trans, lapack_int* n, lapack_int* kl, lapack_int* ku,
                    lapack_int* nrhs, const double* ab, lapack_int* ldab,
                    const double* afb, lapack_int* ldafb,
                    const lapack_int* ipiv, const double* b, lapack_int* ldb,
                    double* x, lapack_int* ldx, double* ferr, double* berr,
                    double* work, lapack_int* iwork, lapack_int *info );
void LAPACK_cgbrfs( char* trans, lapack_int* n, lapack_int* kl, lapack_int* ku,
                    lapack_int* nrhs, const lapack_complex_float* ab,
                    lapack_int* ldab, const lapack_complex_float* afb,
                    lapack_int* ldafb, const lapack_int* ipiv,
                    const lapack_complex_float* b, lapack_int* ldb,
                    lapack_complex_float* x, lapack_int* ldx, float* ferr,
                    float* berr, lapack_complex_float* work, float* rwork,
                    lapack_int *info );
void LAPACK_zgbrfs( char* trans, lapack_int* n, lapack_int* kl, lapack_int* ku,
                    lapack_int* nrhs, const lapack_complex_double* ab,
                    lapack_int* ldab, const lapack_complex_double* afb,
                    lapack_int* ldafb, const lapack_int* ipiv,
                    const lapack_complex_double* b, lapack_int* ldb,
                    lapack_complex_double* x, lapack_int* ldx, double* ferr,
                    double* berr, lapack_complex_double* work, double* rwork,
                    lapack_int *info );
void LAPACK_dgbrfsx( char* trans, char* equed, lapack_int* n, lapack_int* kl,
                     lapack_int* ku, lapack_int* nrhs, const double* ab,
                     lapack_int* ldab, const double* afb, lapack_int* ldafb,
                     const lapack_int* ipiv, const double* r, const double* c,
                     const double* b, lapack_int* ldb, double* x,
                     lapack_int* ldx, double* rcond, double* berr,
                     lapack_int* n_err_bnds, double* err_bnds_norm,
                     double* err_bnds_comp, lapack_int* nparams, double* params,
                     double* work, lapack_int* iwork, lapack_int *info );
void LAPACK_sgbrfsx( char* trans, char* equed, lapack_int* n, lapack_int* kl,
                     lapack_int* ku, lapack_int* nrhs, const float* ab,
                     lapack_int* ldab, const float* afb, lapack_int* ldafb,
                     const lapack_int* ipiv, const float* r, const float* c,
                     const float* b, lapack_int* ldb, float* x, lapack_int* ldx,
                     float* rcond, float* berr, lapack_int* n_err_bnds,
                     float* err_bnds_norm, float* err_bnds_comp,
                     lapack_int* nparams, float* params, float* work,
                     lapack_int* iwork, lapack_int *info );
void LAPACK_zgbrfsx( char* trans, char* equed, lapack_int* n, lapack_int* kl,
                     lapack_int* ku, lapack_int* nrhs,
                     const lapack_complex_double* ab, lapack_int* ldab,
                     const lapack_complex_double* afb, lapack_int* ldafb,
                     const lapack_int* ipiv, const double* r, const double* c,
                     const lapack_complex_double* b, lapack_int* ldb,
                     lapack_complex_double* x, lapack_int* ldx, double* rcond,
                     double* berr, lapack_int* n_err_bnds,
                     double* err_bnds_norm, double* err_bnds_comp,
                     lapack_int* nparams, double* params,
                     lapack_complex_double* work, double* rwork,
                     lapack_int *info );
void LAPACK_cgbrfsx( char* trans, char* equed, lapack_int* n, lapack_int* kl,
                     lapack_int* ku, lapack_int* nrhs,
                     const lapack_complex_float* ab, lapack_int* ldab,
                     const lapack_complex_float* afb, lapack_int* ldafb,
                     const lapack_int* ipiv, const float* r, const float* c,
                     const lapack_complex_float* b, lapack_int* ldb,
                     lapack_complex_float* x, lapack_int* ldx, float* rcond,
                     float* berr, lapack_int* n_err_bnds, float* err_bnds_norm,
                     float* err_bnds_comp, lapack_int* nparams, float* params,
                     lapack_complex_float* work, float* rwork,
                     lapack_int *info );
void LAPACK_sgtrfs( char* trans, lapack_int* n, lapack_int* nrhs,
                    const float* dl, const float* d, const float* du,
                    const float* dlf, const float* df, const float* duf,
                    const float* du2, const lapack_int* ipiv, const float* b,
                    lapack_int* ldb, float* x, lapack_int* ldx, float* ferr,
                    float* berr, float* work, lapack_int* iwork,
                    lapack_int *info );
void LAPACK_dgtrfs( char* trans, lapack_int* n, lapack_int* nrhs,
                    const double* dl, const double* d, const double* du,
                    const double* dlf, const double* df, const double* duf,
                    const double* du2, const lapack_int* ipiv, const double* b,
                    lapack_int* ldb, double* x, lapack_int* ldx, double* ferr,
                    double* berr, double* work, lapack_int* iwork,
                    lapack_int *info );
void LAPACK_cgtrfs( char* trans, lapack_int* n, lapack_int* nrhs,
                    const lapack_complex_float* dl,
                    const lapack_complex_float* d,
                    const lapack_complex_float* du,
                    const lapack_complex_float* dlf,
                    const lapack_complex_float* df,
                    const lapack_complex_float* duf,
                    const lapack_complex_float* du2, const lapack_int* ipiv,
                    const lapack_complex_float* b, lapack_int* ldb,
                    lapack_complex_float* x, lapack_int* ldx, float* ferr,
                    float* berr, lapack_complex_float* work, float* rwork,
                    lapack_int *info );
void LAPACK_zgtrfs( char* trans, lapack_int* n, lapack_int* nrhs,
                    const lapack_complex_double* dl,
                    const lapack_complex_double* d,
                    const lapack_complex_double* du,
                    const lapack_complex_double* dlf,
                    const lapack_complex_double* df,
                    const lapack_complex_double* duf,
                    const lapack_complex_double* du2, const lapack_int* ipiv,
                    const lapack_complex_double* b, lapack_int* ldb,
                    lapack_complex_double* x, lapack_int* ldx, double* ferr,
                    double* berr, lapack_complex_double* work, double* rwork,
                    lapack_int *info );
void LAPACK_sporfs( char* uplo, lapack_int* n, lapack_int* nrhs, const float* a,
                    lapack_int* lda, const float* af, lapack_int* ldaf,
                    const float* b, lapack_int* ldb, float* x, lapack_int* ldx,
                    float* ferr, float* berr, float* work, lapack_int* iwork,
                    lapack_int *info );
void LAPACK_dporfs( char* uplo, lapack_int* n, lapack_int* nrhs,
                    const double* a, lapack_int* lda, const double* af,
                    lapack_int* ldaf, const double* b, lapack_int* ldb,
                    double* x, lapack_int* ldx, double* ferr, double* berr,
                    double* work, lapack_int* iwork, lapack_int *info );
void LAPACK_cporfs( char* uplo, lapack_int* n, lapack_int* nrhs,
                    const lapack_complex_float* a, lapack_int* lda,
                    const lapack_complex_float* af, lapack_int* ldaf,
                    const lapack_complex_float* b, lapack_int* ldb,
                    lapack_complex_float* x, lapack_int* ldx, float* ferr,
                    float* berr, lapack_complex_float* work, float* rwork,
                    lapack_int *info );
void LAPACK_zporfs( char* uplo, lapack_int* n, lapack_int* nrhs,
                    const lapack_complex_double* a, lapack_int* lda,
                    const lapack_complex_double* af, lapack_int* ldaf,
                    const lapack_complex_double* b, lapack_int* ldb,
                    lapack_complex_double* x, lapack_int* ldx, double* ferr,
                    double* berr, lapack_complex_double* work, double* rwork,
                    lapack_int *info );
void LAPACK_dporfsx( char* uplo, char* equed, lapack_int* n, lapack_int* nrhs,
                     const double* a, lapack_int* lda, const double* af,
                     lapack_int* ldaf, const double* s, const double* b,
                     lapack_int* ldb, double* x, lapack_int* ldx, double* rcond,
                     double* berr, lapack_int* n_err_bnds,
                     double* err_bnds_norm, double* err_bnds_comp,
                     lapack_int* nparams, double* params, double* work,
                     lapack_int* iwork, lapack_int *info );
void LAPACK_sporfsx( char* uplo, char* equed, lapack_int* n, lapack_int* nrhs,
                     const float* a, lapack_int* lda, const float* af,
                     lapack_int* ldaf, const float* s, const float* b,
                     lapack_int* ldb, float* x, lapack_int* ldx, float* rcond,
                     float* berr, lapack_int* n_err_bnds, float* err_bnds_norm,
                     float* err_bnds_comp, lapack_int* nparams, float* params,
                     float* work, lapack_int* iwork, lapack_int *info );
void LAPACK_zporfsx( char* uplo, char* equed, lapack_int* n, lapack_int* nrhs,
                     const lapack_complex_double* a, lapack_int* lda,
                     const lapack_complex_double* af, lapack_int* ldaf,
                     const double* s, const lapack_complex_double* b,
                     lapack_int* ldb, lapack_complex_double* x, lapack_int* ldx,
                     double* rcond, double* berr, lapack_int* n_err_bnds,
                     double* err_bnds_norm, double* err_bnds_comp,
                     lapack_int* nparams, double* params,
                     lapack_complex_double* work, double* rwork,
                     lapack_int *info );
void LAPACK_cporfsx( char* uplo, char* equed, lapack_int* n, lapack_int* nrhs,
                     const lapack_complex_float* a, lapack_int* lda,
                     const lapack_complex_float* af, lapack_int* ldaf,
                     const float* s, const lapack_complex_float* b,
                     lapack_int* ldb, lapack_complex_float* x, lapack_int* ldx,
                     float* rcond, float* berr, lapack_int* n_err_bnds,
                     float* err_bnds_norm, float* err_bnds_comp,
                     lapack_int* nparams, float* params,
                     lapack_complex_float* work, float* rwork,
                     lapack_int *info );
void LAPACK_spprfs( char* uplo, lapack_int* n, lapack_int* nrhs,
                    const float* ap, const float* afp, const float* b,
                    lapack_int* ldb, float* x, lapack_int* ldx, float* ferr,
                    float* berr, float* work, lapack_int* iwork,
                    lapack_int *info );
void LAPACK_dpprfs( char* uplo, lapack_int* n, lapack_int* nrhs,
                    const double* ap, const double* afp, const double* b,
                    lapack_int* ldb, double* x, lapack_int* ldx, double* ferr,
                    double* berr, double* work, lapack_int* iwork,
                    lapack_int *info );
void LAPACK_cpprfs( char* uplo, lapack_int* n, lapack_int* nrhs,
                    const lapack_complex_float* ap,
                    const lapack_complex_float* afp,
                    const lapack_complex_float* b, lapack_int* ldb,
                    lapack_complex_float* x, lapack_int* ldx, float* ferr,
                    float* berr, lapack_complex_float* work, float* rwork,
                    lapack_int *info );
void LAPACK_zpprfs( char* uplo, lapack_int* n, lapack_int* nrhs,
                    const lapack_complex_double* ap,
                    const lapack_complex_double* afp,
                    const lapack_complex_double* b, lapack_int* ldb,
                    lapack_complex_double* x, lapack_int* ldx, double* ferr,
                    double* berr, lapack_complex_double* work, double* rwork,
                    lapack_int *info );
void LAPACK_spbrfs( char* uplo, lapack_int* n, lapack_int* kd, lapack_int* nrhs,
                    const float* ab, lapack_int* ldab, const float* afb,
                    lapack_int* ldafb, const float* b, lapack_int* ldb,
                    float* x, lapack_int* ldx, float* ferr, float* berr,
                    float* work, lapack_int* iwork, lapack_int *info );
void LAPACK_dpbrfs( char* uplo, lapack_int* n, lapack_int* kd, lapack_int* nrhs,
                    const double* ab, lapack_int* ldab, const double* afb,
                    lapack_int* ldafb, const double* b, lapack_int* ldb,
                    double* x, lapack_int* ldx, double* ferr, double* berr,
                    double* work, lapack_int* iwork, lapack_int *info );
void LAPACK_cpbrfs( char* uplo, lapack_int* n, lapack_int* kd, lapack_int* nrhs,
                    const lapack_complex_float* ab, lapack_int* ldab,
                    const lapack_complex_float* afb, lapack_int* ldafb,
                    const lapack_complex_float* b, lapack_int* ldb,
                    lapack_complex_float* x, lapack_int* ldx, float* ferr,
                    float* berr, lapack_complex_float* work, float* rwork,
                    lapack_int *info );
void LAPACK_zpbrfs( char* uplo, lapack_int* n, lapack_int* kd, lapack_int* nrhs,
                    const lapack_complex_double* ab, lapack_int* ldab,
                    const lapack_complex_double* afb, lapack_int* ldafb,
                    const lapack_complex_double* b, lapack_int* ldb,
                    lapack_complex_double* x, lapack_int* ldx, double* ferr,
                    double* berr, lapack_complex_double* work, double* rwork,
                    lapack_int *info );
void LAPACK_sptrfs( lapack_int* n, lapack_int* nrhs, const float* d,
                    const float* e, const float* df, const float* ef,
                    const float* b, lapack_int* ldb, float* x, lapack_int* ldx,
                    float* ferr, float* berr, float* work, lapack_int *info );
void LAPACK_dptrfs( lapack_int* n, lapack_int* nrhs, const double* d,
                    const double* e, const double* df, const double* ef,
                    const double* b, lapack_int* ldb, double* x,
                    lapack_int* ldx, double* ferr, double* berr, double* work,
                    lapack_int *info );
void LAPACK_cptrfs( char* uplo, lapack_int* n, lapack_int* nrhs, const float* d,
                    const lapack_complex_float* e, const float* df,
                    const lapack_complex_float* ef,
                    const lapack_complex_float* b, lapack_int* ldb,
                    lapack_complex_float* x, lapack_int* ldx, float* ferr,
                    float* berr, lapack_complex_float* work, float* rwork,
                    lapack_int *info );
void LAPACK_zptrfs( char* uplo, lapack_int* n, lapack_int* nrhs,
                    const double* d, const lapack_complex_double* e,
                    const double* df, const lapack_complex_double* ef,
                    const lapack_complex_double* b, lapack_int* ldb,
                    lapack_complex_double* x, lapack_int* ldx, double* ferr,
                    double* berr, lapack_complex_double* work, double* rwork,
                    lapack_int *info );
void LAPACK_ssyrfs( char* uplo, lapack_int* n, lapack_int* nrhs, const float* a,
                    lapack_int* lda, const float* af, lapack_int* ldaf,
                    const lapack_int* ipiv, const float* b, lapack_int* ldb,
                    float* x, lapack_int* ldx, float* ferr, float* berr,
                    float* work, lapack_int* iwork, lapack_int *info );
void LAPACK_dsyrfs( char* uplo, lapack_int* n, lapack_int* nrhs,
                    const double* a, lapack_int* lda, const double* af,
                    lapack_int* ldaf, const lapack_int* ipiv, const double* b,
                    lapack_int* ldb, double* x, lapack_int* ldx, double* ferr,
                    double* berr, double* work, lapack_int* iwork,
                    lapack_int *info );
void LAPACK_csyrfs( char* uplo, lapack_int* n, lapack_int* nrhs,
                    const lapack_complex_float* a, lapack_int* lda,
                    const lapack_complex_float* af, lapack_int* ldaf,
                    const lapack_int* ipiv, const lapack_complex_float* b,
                    lapack_int* ldb, lapack_complex_float* x, lapack_int* ldx,
                    float* ferr, float* berr, lapack_complex_float* work,
                    float* rwork, lapack_int *info );
void LAPACK_zsyrfs( char* uplo, lapack_int* n, lapack_int* nrhs,
                    const lapack_complex_double* a, lapack_int* lda,
                    const lapack_complex_double* af, lapack_int* ldaf,
                    const lapack_int* ipiv, const lapack_complex_double* b,
                    lapack_int* ldb, lapack_complex_double* x, lapack_int* ldx,
                    double* ferr, double* berr, lapack_complex_double* work,
                    double* rwork, lapack_int *info );
void LAPACK_dsyrfsx( char* uplo, char* equed, lapack_int* n, lapack_int* nrhs,
                     const double* a, lapack_int* lda, const double* af,
                     lapack_int* ldaf, const lapack_int* ipiv, const double* s,
                     const double* b, lapack_int* ldb, double* x,
                     lapack_int* ldx, double* rcond, double* berr,
                     lapack_int* n_err_bnds, double* err_bnds_norm,
                     double* err_bnds_comp, lapack_int* nparams, double* params,
                     double* work, lapack_int* iwork, lapack_int *info );
void LAPACK_ssyrfsx( char* uplo, char* equed, lapack_int* n, lapack_int* nrhs,
                     const float* a, lapack_int* lda, const float* af,
                     lapack_int* ldaf, const lapack_int* ipiv, const float* s,
                     const float* b, lapack_int* ldb, float* x, lapack_int* ldx,
                     float* rcond, float* berr, lapack_int* n_err_bnds,
                     float* err_bnds_norm, float* err_bnds_comp,
                     lapack_int* nparams, float* params, float* work,
                     lapack_int* iwork, lapack_int *info );
void LAPACK_zsyrfsx( char* uplo, char* equed, lapack_int* n, lapack_int* nrhs,
                     const lapack_complex_double* a, lapack_int* lda,
                     const lapack_complex_double* af, lapack_int* ldaf,
                     const lapack_int* ipiv, const double* s,
                     const lapack_complex_double* b, lapack_int* ldb,
                     lapack_complex_double* x, lapack_int* ldx, double* rcond,
                     double* berr, lapack_int* n_err_bnds,
                     double* err_bnds_norm, double* err_bnds_comp,
                     lapack_int* nparams, double* params,
                     lapack_complex_double* work, double* rwork,
                     lapack_int *info );
void LAPACK_csyrfsx( char* uplo, char* equed, lapack_int* n, lapack_int* nrhs,
                     const lapack_complex_float* a, lapack_int* lda,
                     const lapack_complex_float* af, lapack_int* ldaf,
                     const lapack_int* ipiv, const float* s,
                     const lapack_complex_float* b, lapack_int* ldb,
                     lapack_complex_float* x, lapack_int* ldx, float* rcond,
                     float* berr, lapack_int* n_err_bnds, float* err_bnds_norm,
                     float* err_bnds_comp, lapack_int* nparams, float* params,
                     lapack_complex_float* work, float* rwork,
                     lapack_int *info );
void LAPACK_cherfs( char* uplo, lapack_int* n, lapack_int* nrhs,
                    const lapack_complex_float* a, lapack_int* lda,
                    const lapack_complex_float* af, lapack_int* ldaf,
                    const lapack_int* ipiv, const lapack_complex_float* b,
                    lapack_int* ldb, lapack_complex_float* x, lapack_int* ldx,
                    float* ferr, float* berr, lapack_complex_float* work,
                    float* rwork, lapack_int *info );
void LAPACK_zherfs( char* uplo, lapack_int* n, lapack_int* nrhs,
                    const lapack_complex_double* a, lapack_int* lda,
                    const lapack_complex_double* af, lapack_int* ldaf,
                    const lapack_int* ipiv, const lapack_complex_double* b,
                    lapack_int* ldb, lapack_complex_double* x, lapack_int* ldx,
                    double* ferr, double* berr, lapack_complex_double* work,
                    double* rwork, lapack_int *info );
void LAPACK_zherfsx( char* uplo, char* equed, lapack_int* n, lapack_int* nrhs,
                     const lapack_complex_double* a, lapack_int* lda,
                     const lapack_complex_double* af, lapack_int* ldaf,
                     const lapack_int* ipiv, const double* s,
                     const lapack_complex_double* b, lapack_int* ldb,
                     lapack_complex_double* x, lapack_int* ldx, double* rcond,
                     double* berr, lapack_int* n_err_bnds,
                     double* err_bnds_norm, double* err_bnds_comp,
                     lapack_int* nparams, double* params,
                     lapack_complex_double* work, double* rwork,
                     lapack_int *info );
void LAPACK_cherfsx( char* uplo, char* equed, lapack_int* n, lapack_int* nrhs,
                     const lapack_complex_float* a, lapack_int* lda,
                     const lapack_complex_float* af, lapack_int* ldaf,
                     const lapack_int* ipiv, const float* s,
                     const lapack_complex_float* b, lapack_int* ldb,
                     lapack_complex_float* x, lapack_int* ldx, float* rcond,
                     float* berr, lapack_int* n_err_bnds, float* err_bnds_norm,
                     float* err_bnds_comp, lapack_int* nparams, float* params,
                     lapack_complex_float* work, float* rwork,
                     lapack_int *info );
void LAPACK_ssprfs( char* uplo, lapack_int* n, lapack_int* nrhs,
                    const float* ap, const float* afp, const lapack_int* ipiv,
                    const float* b, lapack_int* ldb, float* x, lapack_int* ldx,
                    float* ferr, float* berr, float* work, lapack_int* iwork,
                    lapack_int *info );
void LAPACK_dsprfs( char* uplo, lapack_int* n, lapack_int* nrhs,
                    const double* ap, const double* afp, const lapack_int* ipiv,
                    const double* b, lapack_int* ldb, double* x,
                    lapack_int* ldx, double* ferr, double* berr, double* work,
                    lapack_int* iwork, lapack_int *info );
void LAPACK_csprfs( char* uplo, lapack_int* n, lapack_int* nrhs,
                    const lapack_complex_float* ap,
                    const lapack_complex_float* afp, const lapack_int* ipiv,
                    const lapack_complex_float* b, lapack_int* ldb,
                    lapack_complex_float* x, lapack_int* ldx, float* ferr,
                    float* berr, lapack_complex_float* work, float* rwork,
                    lapack_int *info );
void LAPACK_zsprfs( char* uplo, lapack_int* n, lapack_int* nrhs,
                    const lapack_complex_double* ap,
                    const lapack_complex_double* afp, const lapack_int* ipiv,
                    const lapack_complex_double* b, lapack_int* ldb,
                    lapack_complex_double* x, lapack_int* ldx, double* ferr,
                    double* berr, lapack_complex_double* work, double* rwork,
                    lapack_int *info );
void LAPACK_chprfs( char* uplo, lapack_int* n, lapack_int* nrhs,
                    const lapack_complex_float* ap,
                    const lapack_complex_float* afp, const lapack_int* ipiv,
                    const lapack_complex_float* b, lapack_int* ldb,
                    lapack_complex_float* x, lapack_int* ldx, float* ferr,
                    float* berr, lapack_complex_float* work, float* rwork,
                    lapack_int *info );
void LAPACK_zhprfs( char* uplo, lapack_int* n, lapack_int* nrhs,
                    const lapack_complex_double* ap,
                    const lapack_complex_double* afp, const lapack_int* ipiv,
                    const lapack_complex_double* b, lapack_int* ldb,
                    lapack_complex_double* x, lapack_int* ldx, double* ferr,
                    double* berr, lapack_complex_double* work, double* rwork,
                    lapack_int *info );
void LAPACK_strrfs( char* uplo, char* trans, char* diag, lapack_int* n,
                    lapack_int* nrhs, const float* a, lapack_int* lda,
                    const float* b, lapack_int* ldb, const float* x,
                    lapack_int* ldx, float* ferr, float* berr, float* work,
                    lapack_int* iwork, lapack_int *info );
void LAPACK_dtrrfs( char* uplo, char* trans, char* diag, lapack_int* n,
                    lapack_int* nrhs, const double* a, lapack_int* lda,
                    const double* b, lapack_int* ldb, const double* x,
                    lapack_int* ldx, double* ferr, double* berr, double* work,
                    lapack_int* iwork, lapack_int *info );
void LAPACK_ctrrfs( char* uplo, char* trans, char* diag, lapack_int* n,
                    lapack_int* nrhs, const lapack_complex_float* a,
                    lapack_int* lda, const lapack_complex_float* b,
                    lapack_int* ldb, const lapack_complex_float* x,
                    lapack_int* ldx, float* ferr, float* berr,
                    lapack_complex_float* work, float* rwork,
                    lapack_int *info );
void LAPACK_ztrrfs( char* uplo, char* trans, char* diag, lapack_int* n,
                    lapack_int* nrhs, const lapack_complex_double* a,
                    lapack_int* lda, const lapack_complex_double* b,
                    lapack_int* ldb, const lapack_complex_double* x,
                    lapack_int* ldx, double* ferr, double* berr,
                    lapack_complex_double* work, double* rwork,
                    lapack_int *info );
void LAPACK_stprfs( char* uplo, char* trans, char* diag, lapack_int* n,
                    lapack_int* nrhs, const float* ap, const float* b,
                    lapack_int* ldb, const float* x, lapack_int* ldx,
                    float* ferr, float* berr, float* work, lapack_int* iwork,
                    lapack_int *info );
void LAPACK_dtprfs( char* uplo, char* trans, char* diag, lapack_int* n,
                    lapack_int* nrhs, const double* ap, const double* b,
                    lapack_int* ldb, const double* x, lapack_int* ldx,
                    double* ferr, double* berr, double* work, lapack_int* iwork,
                    lapack_int *info );
void LAPACK_ctprfs( char* uplo, char* trans, char* diag, lapack_int* n,
                    lapack_int* nrhs, const lapack_complex_float* ap,
                    const lapack_complex_float* b, lapack_int* ldb,
                    const lapack_complex_float* x, lapack_int* ldx, float* ferr,
                    float* berr, lapack_complex_float* work, float* rwork,
                    lapack_int *info );
void LAPACK_ztprfs( char* uplo, char* trans, char* diag, lapack_int* n,
                    lapack_int* nrhs, const lapack_complex_double* ap,
                    const lapack_complex_double* b, lapack_int* ldb,
                    const lapack_complex_double* x, lapack_int* ldx,
                    double* ferr, double* berr, lapack_complex_double* work,
                    double* rwork, lapack_int *info );
void LAPACK_stbrfs( char* uplo, char* trans, char* diag, lapack_int* n,
                    lapack_int* kd, lapack_int* nrhs, const float* ab,
                    lapack_int* ldab, const float* b, lapack_int* ldb,
                    const float* x, lapack_int* ldx, float* ferr, float* berr,
                    float* work, lapack_int* iwork, lapack_int *info );
void LAPACK_dtbrfs( char* uplo, char* trans, char* diag, lapack_int* n,
                    lapack_int* kd, lapack_int* nrhs, const double* ab,
                    lapack_int* ldab, const double* b, lapack_int* ldb,
                    const double* x, lapack_int* ldx, double* ferr,
                    double* berr, double* work, lapack_int* iwork,
                    lapack_int *info );
void LAPACK_ctbrfs( char* uplo, char* trans, char* diag, lapack_int* n,
                    lapack_int* kd, lapack_int* nrhs,
                    const lapack_complex_float* ab, lapack_int* ldab,
                    const lapack_complex_float* b, lapack_int* ldb,
                    const lapack_complex_float* x, lapack_int* ldx, float* ferr,
                    float* berr, lapack_complex_float* work, float* rwork,
                    lapack_int *info );
void LAPACK_ztbrfs( char* uplo, char* trans, char* diag, lapack_int* n,
                    lapack_int* kd, lapack_int* nrhs,
                    const lapack_complex_double* ab, lapack_int* ldab,
                    const lapack_complex_double* b, lapack_int* ldb,
                    const lapack_complex_double* x, lapack_int* ldx,
                    double* ferr, double* berr, lapack_complex_double* work,
                    double* rwork, lapack_int *info );
void LAPACK_sgetri( lapack_int* n, float* a, lapack_int* lda,
                    const lapack_int* ipiv, float* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_dgetri( lapack_int* n, double* a, lapack_int* lda,
                    const lapack_int* ipiv, double* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_cgetri( lapack_int* n, lapack_complex_float* a, lapack_int* lda,
                    const lapack_int* ipiv, lapack_complex_float* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_zgetri( lapack_int* n, lapack_complex_double* a, lapack_int* lda,
                    const lapack_int* ipiv, lapack_complex_double* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_spotri( char* uplo, lapack_int* n, float* a, lapack_int* lda,
                    lapack_int *info );
void LAPACK_dpotri( char* uplo, lapack_int* n, double* a, lapack_int* lda,
                    lapack_int *info );
void LAPACK_cpotri( char* uplo, lapack_int* n, lapack_complex_float* a,
                    lapack_int* lda, lapack_int *info );
void LAPACK_zpotri( char* uplo, lapack_int* n, lapack_complex_double* a,
                    lapack_int* lda, lapack_int *info );
void LAPACK_dpftri( char* transr, char* uplo, lapack_int* n, double* a,
                    lapack_int *info );
void LAPACK_spftri( char* transr, char* uplo, lapack_int* n, float* a,
                    lapack_int *info );
void LAPACK_zpftri( char* transr, char* uplo, lapack_int* n,
                    lapack_complex_double* a, lapack_int *info );
void LAPACK_cpftri( char* transr, char* uplo, lapack_int* n,
                    lapack_complex_float* a, lapack_int *info );
void LAPACK_spptri( char* uplo, lapack_int* n, float* ap, lapack_int *info );
void LAPACK_dpptri( char* uplo, lapack_int* n, double* ap, lapack_int *info );
void LAPACK_cpptri( char* uplo, lapack_int* n, lapack_complex_float* ap,
                    lapack_int *info );
void LAPACK_zpptri( char* uplo, lapack_int* n, lapack_complex_double* ap,
                    lapack_int *info );
void LAPACK_ssytri( char* uplo, lapack_int* n, float* a, lapack_int* lda,
                    const lapack_int* ipiv, float* work, lapack_int *info );
void LAPACK_dsytri( char* uplo, lapack_int* n, double* a, lapack_int* lda,
                    const lapack_int* ipiv, double* work, lapack_int *info );
void LAPACK_csytri( char* uplo, lapack_int* n, lapack_complex_float* a,
                    lapack_int* lda, const lapack_int* ipiv,
                    lapack_complex_float* work, lapack_int *info );
void LAPACK_zsytri( char* uplo, lapack_int* n, lapack_complex_double* a,
                    lapack_int* lda, const lapack_int* ipiv,
                    lapack_complex_double* work, lapack_int *info );
void LAPACK_chetri( char* uplo, lapack_int* n, lapack_complex_float* a,
                    lapack_int* lda, const lapack_int* ipiv,
                    lapack_complex_float* work, lapack_int *info );
void LAPACK_zhetri( char* uplo, lapack_int* n, lapack_complex_double* a,
                    lapack_int* lda, const lapack_int* ipiv,
                    lapack_complex_double* work, lapack_int *info );
void LAPACK_ssptri( char* uplo, lapack_int* n, float* ap,
                    const lapack_int* ipiv, float* work, lapack_int *info );
void LAPACK_dsptri( char* uplo, lapack_int* n, double* ap,
                    const lapack_int* ipiv, double* work, lapack_int *info );
void LAPACK_csptri( char* uplo, lapack_int* n, lapack_complex_float* ap,
                    const lapack_int* ipiv, lapack_complex_float* work,
                    lapack_int *info );
void LAPACK_zsptri( char* uplo, lapack_int* n, lapack_complex_double* ap,
                    const lapack_int* ipiv, lapack_complex_double* work,
                    lapack_int *info );
void LAPACK_chptri( char* uplo, lapack_int* n, lapack_complex_float* ap,
                    const lapack_int* ipiv, lapack_complex_float* work,
                    lapack_int *info );
void LAPACK_zhptri( char* uplo, lapack_int* n, lapack_complex_double* ap,
                    const lapack_int* ipiv, lapack_complex_double* work,
                    lapack_int *info );
void LAPACK_strtri( char* uplo, char* diag, lapack_int* n, float* a,
                    lapack_int* lda, lapack_int *info );
void LAPACK_dtrtri( char* uplo, char* diag, lapack_int* n, double* a,
                    lapack_int* lda, lapack_int *info );
void LAPACK_ctrtri( char* uplo, char* diag, lapack_int* n,
                    lapack_complex_float* a, lapack_int* lda,
                    lapack_int *info );
void LAPACK_ztrtri( char* uplo, char* diag, lapack_int* n,
                    lapack_complex_double* a, lapack_int* lda,
                    lapack_int *info );
void LAPACK_dtftri( char* transr, char* uplo, char* diag, lapack_int* n,
                    double* a, lapack_int *info );
void LAPACK_stftri( char* transr, char* uplo, char* diag, lapack_int* n,
                    float* a, lapack_int *info );
void LAPACK_ztftri( char* transr, char* uplo, char* diag, lapack_int* n,
                    lapack_complex_double* a, lapack_int *info );
void LAPACK_ctftri( char* transr, char* uplo, char* diag, lapack_int* n,
                    lapack_complex_float* a, lapack_int *info );
void LAPACK_stptri( char* uplo, char* diag, lapack_int* n, float* ap,
                    lapack_int *info );
void LAPACK_dtptri( char* uplo, char* diag, lapack_int* n, double* ap,
                    lapack_int *info );
void LAPACK_ctptri( char* uplo, char* diag, lapack_int* n,
                    lapack_complex_float* ap, lapack_int *info );
void LAPACK_ztptri( char* uplo, char* diag, lapack_int* n,
                    lapack_complex_double* ap, lapack_int *info );
void LAPACK_sgeequ( lapack_int* m, lapack_int* n, const float* a,
                    lapack_int* lda, float* r, float* c, float* rowcnd,
                    float* colcnd, float* amax, lapack_int *info );
void LAPACK_dgeequ( lapack_int* m, lapack_int* n, const double* a,
                    lapack_int* lda, double* r, double* c, double* rowcnd,
                    double* colcnd, double* amax, lapack_int *info );
void LAPACK_cgeequ( lapack_int* m, lapack_int* n, const lapack_complex_float* a,
                    lapack_int* lda, float* r, float* c, float* rowcnd,
                    float* colcnd, float* amax, lapack_int *info );
void LAPACK_zgeequ( lapack_int* m, lapack_int* n,
                    const lapack_complex_double* a, lapack_int* lda, double* r,
                    double* c, double* rowcnd, double* colcnd, double* amax,
                    lapack_int *info );
void LAPACK_dgeequb( lapack_int* m, lapack_int* n, const double* a,
                     lapack_int* lda, double* r, double* c, double* rowcnd,
                     double* colcnd, double* amax, lapack_int *info );
void LAPACK_sgeequb( lapack_int* m, lapack_int* n, const float* a,
                     lapack_int* lda, float* r, float* c, float* rowcnd,
                     float* colcnd, float* amax, lapack_int *info );
void LAPACK_zgeequb( lapack_int* m, lapack_int* n,
                     const lapack_complex_double* a, lapack_int* lda, double* r,
                     double* c, double* rowcnd, double* colcnd, double* amax,
                     lapack_int *info );
void LAPACK_cgeequb( lapack_int* m, lapack_int* n,
                     const lapack_complex_float* a, lapack_int* lda, float* r,
                     float* c, float* rowcnd, float* colcnd, float* amax,
                     lapack_int *info );
void LAPACK_sgbequ( lapack_int* m, lapack_int* n, lapack_int* kl,
                    lapack_int* ku, const float* ab, lapack_int* ldab, float* r,
                    float* c, float* rowcnd, float* colcnd, float* amax,
                    lapack_int *info );
void LAPACK_dgbequ( lapack_int* m, lapack_int* n, lapack_int* kl,
                    lapack_int* ku, const double* ab, lapack_int* ldab,
                    double* r, double* c, double* rowcnd, double* colcnd,
                    double* amax, lapack_int *info );
void LAPACK_cgbequ( lapack_int* m, lapack_int* n, lapack_int* kl,
                    lapack_int* ku, const lapack_complex_float* ab,
                    lapack_int* ldab, float* r, float* c, float* rowcnd,
                    float* colcnd, float* amax, lapack_int *info );
void LAPACK_zgbequ( lapack_int* m, lapack_int* n, lapack_int* kl,
                    lapack_int* ku, const lapack_complex_double* ab,
                    lapack_int* ldab, double* r, double* c, double* rowcnd,
                    double* colcnd, double* amax, lapack_int *info );
void LAPACK_dgbequb( lapack_int* m, lapack_int* n, lapack_int* kl,
                     lapack_int* ku, const double* ab, lapack_int* ldab,
                     double* r, double* c, double* rowcnd, double* colcnd,
                     double* amax, lapack_int *info );
void LAPACK_sgbequb( lapack_int* m, lapack_int* n, lapack_int* kl,
                     lapack_int* ku, const float* ab, lapack_int* ldab,
                     float* r, float* c, float* rowcnd, float* colcnd,
                     float* amax, lapack_int *info );
void LAPACK_zgbequb( lapack_int* m, lapack_int* n, lapack_int* kl,
                     lapack_int* ku, const lapack_complex_double* ab,
                     lapack_int* ldab, double* r, double* c, double* rowcnd,
                     double* colcnd, double* amax, lapack_int *info );
void LAPACK_cgbequb( lapack_int* m, lapack_int* n, lapack_int* kl,
                     lapack_int* ku, const lapack_complex_float* ab,
                     lapack_int* ldab, float* r, float* c, float* rowcnd,
                     float* colcnd, float* amax, lapack_int *info );
void LAPACK_spoequ( lapack_int* n, const float* a, lapack_int* lda, float* s,
                    float* scond, float* amax, lapack_int *info );
void LAPACK_dpoequ( lapack_int* n, const double* a, lapack_int* lda, double* s,
                    double* scond, double* amax, lapack_int *info );
void LAPACK_cpoequ( lapack_int* n, const lapack_complex_float* a,
                    lapack_int* lda, float* s, float* scond, float* amax,
                    lapack_int *info );
void LAPACK_zpoequ( lapack_int* n, const lapack_complex_double* a,
                    lapack_int* lda, double* s, double* scond, double* amax,
                    lapack_int *info );
void LAPACK_dpoequb( lapack_int* n, const double* a, lapack_int* lda, double* s,
                     double* scond, double* amax, lapack_int *info );
void LAPACK_spoequb( lapack_int* n, const float* a, lapack_int* lda, float* s,
                     float* scond, float* amax, lapack_int *info );
void LAPACK_zpoequb( lapack_int* n, const lapack_complex_double* a,
                     lapack_int* lda, double* s, double* scond, double* amax,
                     lapack_int *info );
void LAPACK_cpoequb( lapack_int* n, const lapack_complex_float* a,
                     lapack_int* lda, float* s, float* scond, float* amax,
                     lapack_int *info );
void LAPACK_sppequ( char* uplo, lapack_int* n, const float* ap, float* s,
                    float* scond, float* amax, lapack_int *info );
void LAPACK_dppequ( char* uplo, lapack_int* n, const double* ap, double* s,
                    double* scond, double* amax, lapack_int *info );
void LAPACK_cppequ( char* uplo, lapack_int* n, const lapack_complex_float* ap,
                    float* s, float* scond, float* amax, lapack_int *info );
void LAPACK_zppequ( char* uplo, lapack_int* n, const lapack_complex_double* ap,
                    double* s, double* scond, double* amax, lapack_int *info );
void LAPACK_spbequ( char* uplo, lapack_int* n, lapack_int* kd, const float* ab,
                    lapack_int* ldab, float* s, float* scond, float* amax,
                    lapack_int *info );
void LAPACK_dpbequ( char* uplo, lapack_int* n, lapack_int* kd, const double* ab,
                    lapack_int* ldab, double* s, double* scond, double* amax,
                    lapack_int *info );
void LAPACK_cpbequ( char* uplo, lapack_int* n, lapack_int* kd,
                    const lapack_complex_float* ab, lapack_int* ldab, float* s,
                    float* scond, float* amax, lapack_int *info );
void LAPACK_zpbequ( char* uplo, lapack_int* n, lapack_int* kd,
                    const lapack_complex_double* ab, lapack_int* ldab,
                    double* s, double* scond, double* amax, lapack_int *info );
void LAPACK_dsyequb( char* uplo, lapack_int* n, const double* a,
                     lapack_int* lda, double* s, double* scond, double* amax,
                     double* work, lapack_int *info );
void LAPACK_ssyequb( char* uplo, lapack_int* n, const float* a, lapack_int* lda,
                     float* s, float* scond, float* amax, float* work,
                     lapack_int *info );
void LAPACK_zsyequb( char* uplo, lapack_int* n, const lapack_complex_double* a,
                     lapack_int* lda, double* s, double* scond, double* amax,
                     lapack_complex_double* work, lapack_int *info );
void LAPACK_csyequb( char* uplo, lapack_int* n, const lapack_complex_float* a,
                     lapack_int* lda, float* s, float* scond, float* amax,
                     lapack_complex_float* work, lapack_int *info );
void LAPACK_zheequb( char* uplo, lapack_int* n, const lapack_complex_double* a,
                     lapack_int* lda, double* s, double* scond, double* amax,
                     lapack_complex_double* work, lapack_int *info );
void LAPACK_cheequb( char* uplo, lapack_int* n, const lapack_complex_float* a,
                     lapack_int* lda, float* s, float* scond, float* amax,
                     lapack_complex_float* work, lapack_int *info );
void LAPACK_sgesv( lapack_int* n, lapack_int* nrhs, float* a, lapack_int* lda,
                   lapack_int* ipiv, float* b, lapack_int* ldb,
                   lapack_int *info );
void LAPACK_dgesv( lapack_int* n, lapack_int* nrhs, double* a, lapack_int* lda,
                   lapack_int* ipiv, double* b, lapack_int* ldb,
                   lapack_int *info );
void LAPACK_cgesv( lapack_int* n, lapack_int* nrhs, lapack_complex_float* a,
                   lapack_int* lda, lapack_int* ipiv, lapack_complex_float* b,
                   lapack_int* ldb, lapack_int *info );
void LAPACK_zgesv( lapack_int* n, lapack_int* nrhs, lapack_complex_double* a,
                   lapack_int* lda, lapack_int* ipiv, lapack_complex_double* b,
                   lapack_int* ldb, lapack_int *info );
void LAPACK_dsgesv( lapack_int* n, lapack_int* nrhs, double* a, lapack_int* lda,
                    lapack_int* ipiv, double* b, lapack_int* ldb, double* x,
                    lapack_int* ldx, double* work, float* swork,
                    lapack_int* iter, lapack_int *info );
void LAPACK_zcgesv( lapack_int* n, lapack_int* nrhs, lapack_complex_double* a,
                    lapack_int* lda, lapack_int* ipiv, lapack_complex_double* b,
                    lapack_int* ldb, lapack_complex_double* x, lapack_int* ldx,
                    lapack_complex_double* work, lapack_complex_float* swork,
                    double* rwork, lapack_int* iter, lapack_int *info );
void LAPACK_sgesvx( char* fact, char* trans, lapack_int* n, lapack_int* nrhs,
                    float* a, lapack_int* lda, float* af, lapack_int* ldaf,
                    lapack_int* ipiv, char* equed, float* r, float* c, float* b,
                    lapack_int* ldb, float* x, lapack_int* ldx, float* rcond,
                    float* ferr, float* berr, float* work, lapack_int* iwork,
                    lapack_int *info );
void LAPACK_dgesvx( char* fact, char* trans, lapack_int* n, lapack_int* nrhs,
                    double* a, lapack_int* lda, double* af, lapack_int* ldaf,
                    lapack_int* ipiv, char* equed, double* r, double* c,
                    double* b, lapack_int* ldb, double* x, lapack_int* ldx,
                    double* rcond, double* ferr, double* berr, double* work,
                    lapack_int* iwork, lapack_int *info );
void LAPACK_cgesvx( char* fact, char* trans, lapack_int* n, lapack_int* nrhs,
                    lapack_complex_float* a, lapack_int* lda,
                    lapack_complex_float* af, lapack_int* ldaf,
                    lapack_int* ipiv, char* equed, float* r, float* c,
                    lapack_complex_float* b, lapack_int* ldb,
                    lapack_complex_float* x, lapack_int* ldx, float* rcond,
                    float* ferr, float* berr, lapack_complex_float* work,
                    float* rwork, lapack_int *info );
void LAPACK_zgesvx( char* fact, char* trans, lapack_int* n, lapack_int* nrhs,
                    lapack_complex_double* a, lapack_int* lda,
                    lapack_complex_double* af, lapack_int* ldaf,
                    lapack_int* ipiv, char* equed, double* r, double* c,
                    lapack_complex_double* b, lapack_int* ldb,
                    lapack_complex_double* x, lapack_int* ldx, double* rcond,
                    double* ferr, double* berr, lapack_complex_double* work,
                    double* rwork, lapack_int *info );
void LAPACK_dgesvxx( char* fact, char* trans, lapack_int* n, lapack_int* nrhs,
                     double* a, lapack_int* lda, double* af, lapack_int* ldaf,
                     lapack_int* ipiv, char* equed, double* r, double* c,
                     double* b, lapack_int* ldb, double* x, lapack_int* ldx,
                     double* rcond, double* rpvgrw, double* berr,
                     lapack_int* n_err_bnds, double* err_bnds_norm,
                     double* err_bnds_comp, lapack_int* nparams, double* params,
                     double* work, lapack_int* iwork, lapack_int *info );
void LAPACK_sgesvxx( char* fact, char* trans, lapack_int* n, lapack_int* nrhs,
                     float* a, lapack_int* lda, float* af, lapack_int* ldaf,
                     lapack_int* ipiv, char* equed, float* r, float* c,
                     float* b, lapack_int* ldb, float* x, lapack_int* ldx,
                     float* rcond, float* rpvgrw, float* berr,
                     lapack_int* n_err_bnds, float* err_bnds_norm,
                     float* err_bnds_comp, lapack_int* nparams, float* params,
                     float* work, lapack_int* iwork, lapack_int *info );
void LAPACK_zgesvxx( char* fact, char* trans, lapack_int* n, lapack_int* nrhs,
                     lapack_complex_double* a, lapack_int* lda,
                     lapack_complex_double* af, lapack_int* ldaf,
                     lapack_int* ipiv, char* equed, double* r, double* c,
                     lapack_complex_double* b, lapack_int* ldb,
                     lapack_complex_double* x, lapack_int* ldx, double* rcond,
                     double* rpvgrw, double* berr, lapack_int* n_err_bnds,
                     double* err_bnds_norm, double* err_bnds_comp,
                     lapack_int* nparams, double* params,
                     lapack_complex_double* work, double* rwork,
                     lapack_int *info );
void LAPACK_cgesvxx( char* fact, char* trans, lapack_int* n, lapack_int* nrhs,
                     lapack_complex_float* a, lapack_int* lda,
                     lapack_complex_float* af, lapack_int* ldaf,
                     lapack_int* ipiv, char* equed, float* r, float* c,
                     lapack_complex_float* b, lapack_int* ldb,
                     lapack_complex_float* x, lapack_int* ldx, float* rcond,
                     float* rpvgrw, float* berr, lapack_int* n_err_bnds,
                     float* err_bnds_norm, float* err_bnds_comp,
                     lapack_int* nparams, float* params,
                     lapack_complex_float* work, float* rwork,
                     lapack_int *info );
void LAPACK_sgbsv( lapack_int* n, lapack_int* kl, lapack_int* ku,
                   lapack_int* nrhs, float* ab, lapack_int* ldab,
                   lapack_int* ipiv, float* b, lapack_int* ldb,
                   lapack_int *info );
void LAPACK_dgbsv( lapack_int* n, lapack_int* kl, lapack_int* ku,
                   lapack_int* nrhs, double* ab, lapack_int* ldab,
                   lapack_int* ipiv, double* b, lapack_int* ldb,
                   lapack_int *info );
void LAPACK_cgbsv( lapack_int* n, lapack_int* kl, lapack_int* ku,
                   lapack_int* nrhs, lapack_complex_float* ab, lapack_int* ldab,
                   lapack_int* ipiv, lapack_complex_float* b, lapack_int* ldb,
                   lapack_int *info );
void LAPACK_zgbsv( lapack_int* n, lapack_int* kl, lapack_int* ku,
                   lapack_int* nrhs, lapack_complex_double* ab,
                   lapack_int* ldab, lapack_int* ipiv, lapack_complex_double* b,
                   lapack_int* ldb, lapack_int *info );
void LAPACK_sgbsvx( char* fact, char* trans, lapack_int* n, lapack_int* kl,
                    lapack_int* ku, lapack_int* nrhs, float* ab,
                    lapack_int* ldab, float* afb, lapack_int* ldafb,
                    lapack_int* ipiv, char* equed, float* r, float* c, float* b,
                    lapack_int* ldb, float* x, lapack_int* ldx, float* rcond,
                    float* ferr, float* berr, float* work, lapack_int* iwork,
                    lapack_int *info );
void LAPACK_dgbsvx( char* fact, char* trans, lapack_int* n, lapack_int* kl,
                    lapack_int* ku, lapack_int* nrhs, double* ab,
                    lapack_int* ldab, double* afb, lapack_int* ldafb,
                    lapack_int* ipiv, char* equed, double* r, double* c,
                    double* b, lapack_int* ldb, double* x, lapack_int* ldx,
                    double* rcond, double* ferr, double* berr, double* work,
                    lapack_int* iwork, lapack_int *info );
void LAPACK_cgbsvx( char* fact, char* trans, lapack_int* n, lapack_int* kl,
                    lapack_int* ku, lapack_int* nrhs, lapack_complex_float* ab,
                    lapack_int* ldab, lapack_complex_float* afb,
                    lapack_int* ldafb, lapack_int* ipiv, char* equed, float* r,
                    float* c, lapack_complex_float* b, lapack_int* ldb,
                    lapack_complex_float* x, lapack_int* ldx, float* rcond,
                    float* ferr, float* berr, lapack_complex_float* work,
                    float* rwork, lapack_int *info );
void LAPACK_zgbsvx( char* fact, char* trans, lapack_int* n, lapack_int* kl,
                    lapack_int* ku, lapack_int* nrhs, lapack_complex_double* ab,
                    lapack_int* ldab, lapack_complex_double* afb,
                    lapack_int* ldafb, lapack_int* ipiv, char* equed, double* r,
                    double* c, lapack_complex_double* b, lapack_int* ldb,
                    lapack_complex_double* x, lapack_int* ldx, double* rcond,
                    double* ferr, double* berr, lapack_complex_double* work,
                    double* rwork, lapack_int *info );
void LAPACK_dgbsvxx( char* fact, char* trans, lapack_int* n, lapack_int* kl,
                     lapack_int* ku, lapack_int* nrhs, double* ab,
                     lapack_int* ldab, double* afb, lapack_int* ldafb,
                     lapack_int* ipiv, char* equed, double* r, double* c,
                     double* b, lapack_int* ldb, double* x, lapack_int* ldx,
                     double* rcond, double* rpvgrw, double* berr,
                     lapack_int* n_err_bnds, double* err_bnds_norm,
                     double* err_bnds_comp, lapack_int* nparams, double* params,
                     double* work, lapack_int* iwork, lapack_int *info );
void LAPACK_sgbsvxx( char* fact, char* trans, lapack_int* n, lapack_int* kl,
                     lapack_int* ku, lapack_int* nrhs, float* ab,
                     lapack_int* ldab, float* afb, lapack_int* ldafb,
                     lapack_int* ipiv, char* equed, float* r, float* c,
                     float* b, lapack_int* ldb, float* x, lapack_int* ldx,
                     float* rcond, float* rpvgrw, float* berr,
                     lapack_int* n_err_bnds, float* err_bnds_norm,
                     float* err_bnds_comp, lapack_int* nparams, float* params,
                     float* work, lapack_int* iwork, lapack_int *info );
void LAPACK_zgbsvxx( char* fact, char* trans, lapack_int* n, lapack_int* kl,
                     lapack_int* ku, lapack_int* nrhs,
                     lapack_complex_double* ab, lapack_int* ldab,
                     lapack_complex_double* afb, lapack_int* ldafb,
                     lapack_int* ipiv, char* equed, double* r, double* c,
                     lapack_complex_double* b, lapack_int* ldb,
                     lapack_complex_double* x, lapack_int* ldx, double* rcond,
                     double* rpvgrw, double* berr, lapack_int* n_err_bnds,
                     double* err_bnds_norm, double* err_bnds_comp,
                     lapack_int* nparams, double* params,
                     lapack_complex_double* work, double* rwork,
                     lapack_int *info );
void LAPACK_cgbsvxx( char* fact, char* trans, lapack_int* n, lapack_int* kl,
                     lapack_int* ku, lapack_int* nrhs, lapack_complex_float* ab,
                     lapack_int* ldab, lapack_complex_float* afb,
                     lapack_int* ldafb, lapack_int* ipiv, char* equed, float* r,
                     float* c, lapack_complex_float* b, lapack_int* ldb,
                     lapack_complex_float* x, lapack_int* ldx, float* rcond,
                     float* rpvgrw, float* berr, lapack_int* n_err_bnds,
                     float* err_bnds_norm, float* err_bnds_comp,
                     lapack_int* nparams, float* params,
                     lapack_complex_float* work, float* rwork,
                     lapack_int *info );
void LAPACK_sgtsv( lapack_int* n, lapack_int* nrhs, float* dl, float* d,
                   float* du, float* b, lapack_int* ldb, lapack_int *info );
void LAPACK_dgtsv( lapack_int* n, lapack_int* nrhs, double* dl, double* d,
                   double* du, double* b, lapack_int* ldb, lapack_int *info );
void LAPACK_cgtsv( lapack_int* n, lapack_int* nrhs, lapack_complex_float* dl,
                   lapack_complex_float* d, lapack_complex_float* du,
                   lapack_complex_float* b, lapack_int* ldb, lapack_int *info );
void LAPACK_zgtsv( lapack_int* n, lapack_int* nrhs, lapack_complex_double* dl,
                   lapack_complex_double* d, lapack_complex_double* du,
                   lapack_complex_double* b, lapack_int* ldb,
                   lapack_int *info );
void LAPACK_sgtsvx( char* fact, char* trans, lapack_int* n, lapack_int* nrhs,
                    const float* dl, const float* d, const float* du,
                    float* dlf, float* df, float* duf, float* du2,
                    lapack_int* ipiv, const float* b, lapack_int* ldb, float* x,
                    lapack_int* ldx, float* rcond, float* ferr, float* berr,
                    float* work, lapack_int* iwork, lapack_int *info );
void LAPACK_dgtsvx( char* fact, char* trans, lapack_int* n, lapack_int* nrhs,
                    const double* dl, const double* d, const double* du,
                    double* dlf, double* df, double* duf, double* du2,
                    lapack_int* ipiv, const double* b, lapack_int* ldb,
                    double* x, lapack_int* ldx, double* rcond, double* ferr,
                    double* berr, double* work, lapack_int* iwork,
                    lapack_int *info );
void LAPACK_cgtsvx( char* fact, char* trans, lapack_int* n, lapack_int* nrhs,
                    const lapack_complex_float* dl,
                    const lapack_complex_float* d,
                    const lapack_complex_float* du, lapack_complex_float* dlf,
                    lapack_complex_float* df, lapack_complex_float* duf,
                    lapack_complex_float* du2, lapack_int* ipiv,
                    const lapack_complex_float* b, lapack_int* ldb,
                    lapack_complex_float* x, lapack_int* ldx, float* rcond,
                    float* ferr, float* berr, lapack_complex_float* work,
                    float* rwork, lapack_int *info );
void LAPACK_zgtsvx( char* fact, char* trans, lapack_int* n, lapack_int* nrhs,
                    const lapack_complex_double* dl,
                    const lapack_complex_double* d,
                    const lapack_complex_double* du, lapack_complex_double* dlf,
                    lapack_complex_double* df, lapack_complex_double* duf,
                    lapack_complex_double* du2, lapack_int* ipiv,
                    const lapack_complex_double* b, lapack_int* ldb,
                    lapack_complex_double* x, lapack_int* ldx, double* rcond,
                    double* ferr, double* berr, lapack_complex_double* work,
                    double* rwork, lapack_int *info );
void LAPACK_sposv( char* uplo, lapack_int* n, lapack_int* nrhs, float* a,
                   lapack_int* lda, float* b, lapack_int* ldb,
                   lapack_int *info );
void LAPACK_dposv( char* uplo, lapack_int* n, lapack_int* nrhs, double* a,
                   lapack_int* lda, double* b, lapack_int* ldb,
                   lapack_int *info );
void LAPACK_cposv( char* uplo, lapack_int* n, lapack_int* nrhs,
                   lapack_complex_float* a, lapack_int* lda,
                   lapack_complex_float* b, lapack_int* ldb, lapack_int *info );
void LAPACK_zposv( char* uplo, lapack_int* n, lapack_int* nrhs,
                   lapack_complex_double* a, lapack_int* lda,
                   lapack_complex_double* b, lapack_int* ldb,
                   lapack_int *info );
void LAPACK_dsposv( char* uplo, lapack_int* n, lapack_int* nrhs, double* a,
                    lapack_int* lda, double* b, lapack_int* ldb, double* x,
                    lapack_int* ldx, double* work, float* swork,
                    lapack_int* iter, lapack_int *info );
void LAPACK_zcposv( char* uplo, lapack_int* n, lapack_int* nrhs,
                    lapack_complex_double* a, lapack_int* lda,
                    lapack_complex_double* b, lapack_int* ldb,
                    lapack_complex_double* x, lapack_int* ldx,
                    lapack_complex_double* work, lapack_complex_float* swork,
                    double* rwork, lapack_int* iter, lapack_int *info );
void LAPACK_sposvx( char* fact, char* uplo, lapack_int* n, lapack_int* nrhs,
                    float* a, lapack_int* lda, float* af, lapack_int* ldaf,
                    char* equed, float* s, float* b, lapack_int* ldb, float* x,
                    lapack_int* ldx, float* rcond, float* ferr, float* berr,
                    float* work, lapack_int* iwork, lapack_int *info );
void LAPACK_dposvx( char* fact, char* uplo, lapack_int* n, lapack_int* nrhs,
                    double* a, lapack_int* lda, double* af, lapack_int* ldaf,
                    char* equed, double* s, double* b, lapack_int* ldb,
                    double* x, lapack_int* ldx, double* rcond, double* ferr,
                    double* berr, double* work, lapack_int* iwork,
                    lapack_int *info );
void LAPACK_cposvx( char* fact, char* uplo, lapack_int* n, lapack_int* nrhs,
                    lapack_complex_float* a, lapack_int* lda,
                    lapack_complex_float* af, lapack_int* ldaf, char* equed,
                    float* s, lapack_complex_float* b, lapack_int* ldb,
                    lapack_complex_float* x, lapack_int* ldx, float* rcond,
                    float* ferr, float* berr, lapack_complex_float* work,
                    float* rwork, lapack_int *info );
void LAPACK_zposvx( char* fact, char* uplo, lapack_int* n, lapack_int* nrhs,
                    lapack_complex_double* a, lapack_int* lda,
                    lapack_complex_double* af, lapack_int* ldaf, char* equed,
                    double* s, lapack_complex_double* b, lapack_int* ldb,
                    lapack_complex_double* x, lapack_int* ldx, double* rcond,
                    double* ferr, double* berr, lapack_complex_double* work,
                    double* rwork, lapack_int *info );
void LAPACK_dposvxx( char* fact, char* uplo, lapack_int* n, lapack_int* nrhs,
                     double* a, lapack_int* lda, double* af, lapack_int* ldaf,
                     char* equed, double* s, double* b, lapack_int* ldb,
                     double* x, lapack_int* ldx, double* rcond, double* rpvgrw,
                     double* berr, lapack_int* n_err_bnds,
                     double* err_bnds_norm, double* err_bnds_comp,
                     lapack_int* nparams, double* params, double* work,
                     lapack_int* iwork, lapack_int *info );
void LAPACK_sposvxx( char* fact, char* uplo, lapack_int* n, lapack_int* nrhs,
                     float* a, lapack_int* lda, float* af, lapack_int* ldaf,
                     char* equed, float* s, float* b, lapack_int* ldb, float* x,
                     lapack_int* ldx, float* rcond, float* rpvgrw, float* berr,
                     lapack_int* n_err_bnds, float* err_bnds_norm,
                     float* err_bnds_comp, lapack_int* nparams, float* params,
                     float* work, lapack_int* iwork, lapack_int *info );
void LAPACK_zposvxx( char* fact, char* uplo, lapack_int* n, lapack_int* nrhs,
                     lapack_complex_double* a, lapack_int* lda,
                     lapack_complex_double* af, lapack_int* ldaf, char* equed,
                     double* s, lapack_complex_double* b, lapack_int* ldb,
                     lapack_complex_double* x, lapack_int* ldx, double* rcond,
                     double* rpvgrw, double* berr, lapack_int* n_err_bnds,
                     double* err_bnds_norm, double* err_bnds_comp,
                     lapack_int* nparams, double* params,
                     lapack_complex_double* work, double* rwork,
                     lapack_int *info );
void LAPACK_cposvxx( char* fact, char* uplo, lapack_int* n, lapack_int* nrhs,
                     lapack_complex_float* a, lapack_int* lda,
                     lapack_complex_float* af, lapack_int* ldaf, char* equed,
                     float* s, lapack_complex_float* b, lapack_int* ldb,
                     lapack_complex_float* x, lapack_int* ldx, float* rcond,
                     float* rpvgrw, float* berr, lapack_int* n_err_bnds,
                     float* err_bnds_norm, float* err_bnds_comp,
                     lapack_int* nparams, float* params,
                     lapack_complex_float* work, float* rwork,
                     lapack_int *info );
void LAPACK_sppsv( char* uplo, lapack_int* n, lapack_int* nrhs, float* ap,
                   float* b, lapack_int* ldb, lapack_int *info );
void LAPACK_dppsv( char* uplo, lapack_int* n, lapack_int* nrhs, double* ap,
                   double* b, lapack_int* ldb, lapack_int *info );
void LAPACK_cppsv( char* uplo, lapack_int* n, lapack_int* nrhs,
                   lapack_complex_float* ap, lapack_complex_float* b,
                   lapack_int* ldb, lapack_int *info );
void LAPACK_zppsv( char* uplo, lapack_int* n, lapack_int* nrhs,
                   lapack_complex_double* ap, lapack_complex_double* b,
                   lapack_int* ldb, lapack_int *info );
void LAPACK_sppsvx( char* fact, char* uplo, lapack_int* n, lapack_int* nrhs,
                    float* ap, float* afp, char* equed, float* s, float* b,
                    lapack_int* ldb, float* x, lapack_int* ldx, float* rcond,
                    float* ferr, float* berr, float* work, lapack_int* iwork,
                    lapack_int *info );
void LAPACK_dppsvx( char* fact, char* uplo, lapack_int* n, lapack_int* nrhs,
                    double* ap, double* afp, char* equed, double* s, double* b,
                    lapack_int* ldb, double* x, lapack_int* ldx, double* rcond,
                    double* ferr, double* berr, double* work, lapack_int* iwork,
                    lapack_int *info );
void LAPACK_cppsvx( char* fact, char* uplo, lapack_int* n, lapack_int* nrhs,
                    lapack_complex_float* ap, lapack_complex_float* afp,
                    char* equed, float* s, lapack_complex_float* b,
                    lapack_int* ldb, lapack_complex_float* x, lapack_int* ldx,
                    float* rcond, float* ferr, float* berr,
                    lapack_complex_float* work, float* rwork,
                    lapack_int *info );
void LAPACK_zppsvx( char* fact, char* uplo, lapack_int* n, lapack_int* nrhs,
                    lapack_complex_double* ap, lapack_complex_double* afp,
                    char* equed, double* s, lapack_complex_double* b,
                    lapack_int* ldb, lapack_complex_double* x, lapack_int* ldx,
                    double* rcond, double* ferr, double* berr,
                    lapack_complex_double* work, double* rwork,
                    lapack_int *info );
void LAPACK_spbsv( char* uplo, lapack_int* n, lapack_int* kd, lapack_int* nrhs,
                   float* ab, lapack_int* ldab, float* b, lapack_int* ldb,
                   lapack_int *info );
void LAPACK_dpbsv( char* uplo, lapack_int* n, lapack_int* kd, lapack_int* nrhs,
                   double* ab, lapack_int* ldab, double* b, lapack_int* ldb,
                   lapack_int *info );
void LAPACK_cpbsv( char* uplo, lapack_int* n, lapack_int* kd, lapack_int* nrhs,
                   lapack_complex_float* ab, lapack_int* ldab,
                   lapack_complex_float* b, lapack_int* ldb, lapack_int *info );
void LAPACK_zpbsv( char* uplo, lapack_int* n, lapack_int* kd, lapack_int* nrhs,
                   lapack_complex_double* ab, lapack_int* ldab,
                   lapack_complex_double* b, lapack_int* ldb,
                   lapack_int *info );
void LAPACK_spbsvx( char* fact, char* uplo, lapack_int* n, lapack_int* kd,
                    lapack_int* nrhs, float* ab, lapack_int* ldab, float* afb,
                    lapack_int* ldafb, char* equed, float* s, float* b,
                    lapack_int* ldb, float* x, lapack_int* ldx, float* rcond,
                    float* ferr, float* berr, float* work, lapack_int* iwork,
                    lapack_int *info );
void LAPACK_dpbsvx( char* fact, char* uplo, lapack_int* n, lapack_int* kd,
                    lapack_int* nrhs, double* ab, lapack_int* ldab, double* afb,
                    lapack_int* ldafb, char* equed, double* s, double* b,
                    lapack_int* ldb, double* x, lapack_int* ldx, double* rcond,
                    double* ferr, double* berr, double* work, lapack_int* iwork,
                    lapack_int *info );
void LAPACK_cpbsvx( char* fact, char* uplo, lapack_int* n, lapack_int* kd,
                    lapack_int* nrhs, lapack_complex_float* ab,
                    lapack_int* ldab, lapack_complex_float* afb,
                    lapack_int* ldafb, char* equed, float* s,
                    lapack_complex_float* b, lapack_int* ldb,
                    lapack_complex_float* x, lapack_int* ldx, float* rcond,
                    float* ferr, float* berr, lapack_complex_float* work,
                    float* rwork, lapack_int *info );
void LAPACK_zpbsvx( char* fact, char* uplo, lapack_int* n, lapack_int* kd,
                    lapack_int* nrhs, lapack_complex_double* ab,
                    lapack_int* ldab, lapack_complex_double* afb,
                    lapack_int* ldafb, char* equed, double* s,
                    lapack_complex_double* b, lapack_int* ldb,
                    lapack_complex_double* x, lapack_int* ldx, double* rcond,
                    double* ferr, double* berr, lapack_complex_double* work,
                    double* rwork, lapack_int *info );
void LAPACK_sptsv( lapack_int* n, lapack_int* nrhs, float* d, float* e,
                   float* b, lapack_int* ldb, lapack_int *info );
void LAPACK_dptsv( lapack_int* n, lapack_int* nrhs, double* d, double* e,
                   double* b, lapack_int* ldb, lapack_int *info );
void LAPACK_cptsv( lapack_int* n, lapack_int* nrhs, float* d,
                   lapack_complex_float* e, lapack_complex_float* b,
                   lapack_int* ldb, lapack_int *info );
void LAPACK_zptsv( lapack_int* n, lapack_int* nrhs, double* d,
                   lapack_complex_double* e, lapack_complex_double* b,
                   lapack_int* ldb, lapack_int *info );
void LAPACK_sptsvx( char* fact, lapack_int* n, lapack_int* nrhs, const float* d,
                    const float* e, float* df, float* ef, const float* b,
                    lapack_int* ldb, float* x, lapack_int* ldx, float* rcond,
                    float* ferr, float* berr, float* work, lapack_int *info );
void LAPACK_dptsvx( char* fact, lapack_int* n, lapack_int* nrhs,
                    const double* d, const double* e, double* df, double* ef,
                    const double* b, lapack_int* ldb, double* x,
                    lapack_int* ldx, double* rcond, double* ferr, double* berr,
                    double* work, lapack_int *info );
void LAPACK_cptsvx( char* fact, lapack_int* n, lapack_int* nrhs, const float* d,
                    const lapack_complex_float* e, float* df,
                    lapack_complex_float* ef, const lapack_complex_float* b,
                    lapack_int* ldb, lapack_complex_float* x, lapack_int* ldx,
                    float* rcond, float* ferr, float* berr,
                    lapack_complex_float* work, float* rwork,
                    lapack_int *info );
void LAPACK_zptsvx( char* fact, lapack_int* n, lapack_int* nrhs,
                    const double* d, const lapack_complex_double* e, double* df,
                    lapack_complex_double* ef, const lapack_complex_double* b,
                    lapack_int* ldb, lapack_complex_double* x, lapack_int* ldx,
                    double* rcond, double* ferr, double* berr,
                    lapack_complex_double* work, double* rwork,
                    lapack_int *info );
void LAPACK_ssysv( char* uplo, lapack_int* n, lapack_int* nrhs, float* a,
                   lapack_int* lda, lapack_int* ipiv, float* b, lapack_int* ldb,
                   float* work, lapack_int* lwork, lapack_int *info );
void LAPACK_dsysv( char* uplo, lapack_int* n, lapack_int* nrhs, double* a,
                   lapack_int* lda, lapack_int* ipiv, double* b,
                   lapack_int* ldb, double* work, lapack_int* lwork,
                   lapack_int *info );
void LAPACK_csysv( char* uplo, lapack_int* n, lapack_int* nrhs,
                   lapack_complex_float* a, lapack_int* lda, lapack_int* ipiv,
                   lapack_complex_float* b, lapack_int* ldb,
                   lapack_complex_float* work, lapack_int* lwork,
                   lapack_int *info );
void LAPACK_zsysv( char* uplo, lapack_int* n, lapack_int* nrhs,
                   lapack_complex_double* a, lapack_int* lda, lapack_int* ipiv,
                   lapack_complex_double* b, lapack_int* ldb,
                   lapack_complex_double* work, lapack_int* lwork,
                   lapack_int *info );
void LAPACK_ssysvx( char* fact, char* uplo, lapack_int* n, lapack_int* nrhs,
                    const float* a, lapack_int* lda, float* af,
                    lapack_int* ldaf, lapack_int* ipiv, const float* b,
                    lapack_int* ldb, float* x, lapack_int* ldx, float* rcond,
                    float* ferr, float* berr, float* work, lapack_int* lwork,
                    lapack_int* iwork, lapack_int *info );
void LAPACK_dsysvx( char* fact, char* uplo, lapack_int* n, lapack_int* nrhs,
                    const double* a, lapack_int* lda, double* af,
                    lapack_int* ldaf, lapack_int* ipiv, const double* b,
                    lapack_int* ldb, double* x, lapack_int* ldx, double* rcond,
                    double* ferr, double* berr, double* work, lapack_int* lwork,
                    lapack_int* iwork, lapack_int *info );
void LAPACK_csysvx( char* fact, char* uplo, lapack_int* n, lapack_int* nrhs,
                    const lapack_complex_float* a, lapack_int* lda,
                    lapack_complex_float* af, lapack_int* ldaf,
                    lapack_int* ipiv, const lapack_complex_float* b,
                    lapack_int* ldb, lapack_complex_float* x, lapack_int* ldx,
                    float* rcond, float* ferr, float* berr,
                    lapack_complex_float* work, lapack_int* lwork, float* rwork,
                    lapack_int *info );
void LAPACK_zsysvx( char* fact, char* uplo, lapack_int* n, lapack_int* nrhs,
                    const lapack_complex_double* a, lapack_int* lda,
                    lapack_complex_double* af, lapack_int* ldaf,
                    lapack_int* ipiv, const lapack_complex_double* b,
                    lapack_int* ldb, lapack_complex_double* x, lapack_int* ldx,
                    double* rcond, double* ferr, double* berr,
                    lapack_complex_double* work, lapack_int* lwork,
                    double* rwork, lapack_int *info );
void LAPACK_dsysvxx( char* fact, char* uplo, lapack_int* n, lapack_int* nrhs,
                     double* a, lapack_int* lda, double* af, lapack_int* ldaf,
                     lapack_int* ipiv, char* equed, double* s, double* b,
                     lapack_int* ldb, double* x, lapack_int* ldx, double* rcond,
                     double* rpvgrw, double* berr, lapack_int* n_err_bnds,
                     double* err_bnds_norm, double* err_bnds_comp,
                     lapack_int* nparams, double* params, double* work,
                     lapack_int* iwork, lapack_int *info );
void LAPACK_ssysvxx( char* fact, char* uplo, lapack_int* n, lapack_int* nrhs,
                     float* a, lapack_int* lda, float* af, lapack_int* ldaf,
                     lapack_int* ipiv, char* equed, float* s, float* b,
                     lapack_int* ldb, float* x, lapack_int* ldx, float* rcond,
                     float* rpvgrw, float* berr, lapack_int* n_err_bnds,
                     float* err_bnds_norm, float* err_bnds_comp,
                     lapack_int* nparams, float* params, float* work,
                     lapack_int* iwork, lapack_int *info );
void LAPACK_zsysvxx( char* fact, char* uplo, lapack_int* n, lapack_int* nrhs,
                     lapack_complex_double* a, lapack_int* lda,
                     lapack_complex_double* af, lapack_int* ldaf,
                     lapack_int* ipiv, char* equed, double* s,
                     lapack_complex_double* b, lapack_int* ldb,
                     lapack_complex_double* x, lapack_int* ldx, double* rcond,
                     double* rpvgrw, double* berr, lapack_int* n_err_bnds,
                     double* err_bnds_norm, double* err_bnds_comp,
                     lapack_int* nparams, double* params,
                     lapack_complex_double* work, double* rwork,
                     lapack_int *info );
void LAPACK_csysvxx( char* fact, char* uplo, lapack_int* n, lapack_int* nrhs,
                     lapack_complex_float* a, lapack_int* lda,
                     lapack_complex_float* af, lapack_int* ldaf,
                     lapack_int* ipiv, char* equed, float* s,
                     lapack_complex_float* b, lapack_int* ldb,
                     lapack_complex_float* x, lapack_int* ldx, float* rcond,
                     float* rpvgrw, float* berr, lapack_int* n_err_bnds,
                     float* err_bnds_norm, float* err_bnds_comp,
                     lapack_int* nparams, float* params,
                     lapack_complex_float* work, float* rwork,
                     lapack_int *info );
void LAPACK_chesv( char* uplo, lapack_int* n, lapack_int* nrhs,
                   lapack_complex_float* a, lapack_int* lda, lapack_int* ipiv,
                   lapack_complex_float* b, lapack_int* ldb,
                   lapack_complex_float* work, lapack_int* lwork,
                   lapack_int *info );
void LAPACK_zhesv( char* uplo, lapack_int* n, lapack_int* nrhs,
                   lapack_complex_double* a, lapack_int* lda, lapack_int* ipiv,
                   lapack_complex_double* b, lapack_int* ldb,
                   lapack_complex_double* work, lapack_int* lwork,
                   lapack_int *info );
void LAPACK_chesvx( char* fact, char* uplo, lapack_int* n, lapack_int* nrhs,
                    const lapack_complex_float* a, lapack_int* lda,
                    lapack_complex_float* af, lapack_int* ldaf,
                    lapack_int* ipiv, const lapack_complex_float* b,
                    lapack_int* ldb, lapack_complex_float* x, lapack_int* ldx,
                    float* rcond, float* ferr, float* berr,
                    lapack_complex_float* work, lapack_int* lwork, float* rwork,
                    lapack_int *info );
void LAPACK_zhesvx( char* fact, char* uplo, lapack_int* n, lapack_int* nrhs,
                    const lapack_complex_double* a, lapack_int* lda,
                    lapack_complex_double* af, lapack_int* ldaf,
                    lapack_int* ipiv, const lapack_complex_double* b,
                    lapack_int* ldb, lapack_complex_double* x, lapack_int* ldx,
                    double* rcond, double* ferr, double* berr,
                    lapack_complex_double* work, lapack_int* lwork,
                    double* rwork, lapack_int *info );
void LAPACK_zhesvxx( char* fact, char* uplo, lapack_int* n, lapack_int* nrhs,
                     lapack_complex_double* a, lapack_int* lda,
                     lapack_complex_double* af, lapack_int* ldaf,
                     lapack_int* ipiv, char* equed, double* s,
                     lapack_complex_double* b, lapack_int* ldb,
                     lapack_complex_double* x, lapack_int* ldx, double* rcond,
                     double* rpvgrw, double* berr, lapack_int* n_err_bnds,
                     double* err_bnds_norm, double* err_bnds_comp,
                     lapack_int* nparams, double* params,
                     lapack_complex_double* work, double* rwork,
                     lapack_int *info );
void LAPACK_chesvxx( char* fact, char* uplo, lapack_int* n, lapack_int* nrhs,
                     lapack_complex_float* a, lapack_int* lda,
                     lapack_complex_float* af, lapack_int* ldaf,
                     lapack_int* ipiv, char* equed, float* s,
                     lapack_complex_float* b, lapack_int* ldb,
                     lapack_complex_float* x, lapack_int* ldx, float* rcond,
                     float* rpvgrw, float* berr, lapack_int* n_err_bnds,
                     float* err_bnds_norm, float* err_bnds_comp,
                     lapack_int* nparams, float* params,
                     lapack_complex_float* work, float* rwork,
                     lapack_int *info );
void LAPACK_sspsv( char* uplo, lapack_int* n, lapack_int* nrhs, float* ap,
                   lapack_int* ipiv, float* b, lapack_int* ldb,
                   lapack_int *info );
void LAPACK_dspsv( char* uplo, lapack_int* n, lapack_int* nrhs, double* ap,
                   lapack_int* ipiv, double* b, lapack_int* ldb,
                   lapack_int *info );
void LAPACK_cspsv( char* uplo, lapack_int* n, lapack_int* nrhs,
                   lapack_complex_float* ap, lapack_int* ipiv,
                   lapack_complex_float* b, lapack_int* ldb, lapack_int *info );
void LAPACK_zspsv( char* uplo, lapack_int* n, lapack_int* nrhs,
                   lapack_complex_double* ap, lapack_int* ipiv,
                   lapack_complex_double* b, lapack_int* ldb,
                   lapack_int *info );
void LAPACK_sspsvx( char* fact, char* uplo, lapack_int* n, lapack_int* nrhs,
                    const float* ap, float* afp, lapack_int* ipiv,
                    const float* b, lapack_int* ldb, float* x, lapack_int* ldx,
                    float* rcond, float* ferr, float* berr, float* work,
                    lapack_int* iwork, lapack_int *info );
void LAPACK_dspsvx( char* fact, char* uplo, lapack_int* n, lapack_int* nrhs,
                    const double* ap, double* afp, lapack_int* ipiv,
                    const double* b, lapack_int* ldb, double* x,
                    lapack_int* ldx, double* rcond, double* ferr, double* berr,
                    double* work, lapack_int* iwork, lapack_int *info );
void LAPACK_cspsvx( char* fact, char* uplo, lapack_int* n, lapack_int* nrhs,
                    const lapack_complex_float* ap, lapack_complex_float* afp,
                    lapack_int* ipiv, const lapack_complex_float* b,
                    lapack_int* ldb, lapack_complex_float* x, lapack_int* ldx,
                    float* rcond, float* ferr, float* berr,
                    lapack_complex_float* work, float* rwork,
                    lapack_int *info );
void LAPACK_zspsvx( char* fact, char* uplo, lapack_int* n, lapack_int* nrhs,
                    const lapack_complex_double* ap, lapack_complex_double* afp,
                    lapack_int* ipiv, const lapack_complex_double* b,
                    lapack_int* ldb, lapack_complex_double* x, lapack_int* ldx,
                    double* rcond, double* ferr, double* berr,
                    lapack_complex_double* work, double* rwork,
                    lapack_int *info );
void LAPACK_chpsv( char* uplo, lapack_int* n, lapack_int* nrhs,
                   lapack_complex_float* ap, lapack_int* ipiv,
                   lapack_complex_float* b, lapack_int* ldb, lapack_int *info );
void LAPACK_zhpsv( char* uplo, lapack_int* n, lapack_int* nrhs,
                   lapack_complex_double* ap, lapack_int* ipiv,
                   lapack_complex_double* b, lapack_int* ldb,
                   lapack_int *info );
void LAPACK_chpsvx( char* fact, char* uplo, lapack_int* n, lapack_int* nrhs,
                    const lapack_complex_float* ap, lapack_complex_float* afp,
                    lapack_int* ipiv, const lapack_complex_float* b,
                    lapack_int* ldb, lapack_complex_float* x, lapack_int* ldx,
                    float* rcond, float* ferr, float* berr,
                    lapack_complex_float* work, float* rwork,
                    lapack_int *info );
void LAPACK_zhpsvx( char* fact, char* uplo, lapack_int* n, lapack_int* nrhs,
                    const lapack_complex_double* ap, lapack_complex_double* afp,
                    lapack_int* ipiv, const lapack_complex_double* b,
                    lapack_int* ldb, lapack_complex_double* x, lapack_int* ldx,
                    double* rcond, double* ferr, double* berr,
                    lapack_complex_double* work, double* rwork,
                    lapack_int *info );
void LAPACK_sgeqrf( lapack_int* m, lapack_int* n, float* a, lapack_int* lda,
                    float* tau, float* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_dgeqrf( lapack_int* m, lapack_int* n, double* a, lapack_int* lda,
                    double* tau, double* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_cgeqrf( lapack_int* m, lapack_int* n, lapack_complex_float* a,
                    lapack_int* lda, lapack_complex_float* tau,
                    lapack_complex_float* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_zgeqrf( lapack_int* m, lapack_int* n, lapack_complex_double* a,
                    lapack_int* lda, lapack_complex_double* tau,
                    lapack_complex_double* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_sgeqpf( lapack_int* m, lapack_int* n, float* a, lapack_int* lda,
                    lapack_int* jpvt, float* tau, float* work,
                    lapack_int *info );
void LAPACK_dgeqpf( lapack_int* m, lapack_int* n, double* a, lapack_int* lda,
                    lapack_int* jpvt, double* tau, double* work,
                    lapack_int *info );
void LAPACK_cgeqpf( lapack_int* m, lapack_int* n, lapack_complex_float* a,
                    lapack_int* lda, lapack_int* jpvt,
                    lapack_complex_float* tau, lapack_complex_float* work,
                    float* rwork, lapack_int *info );
void LAPACK_zgeqpf( lapack_int* m, lapack_int* n, lapack_complex_double* a,
                    lapack_int* lda, lapack_int* jpvt,
                    lapack_complex_double* tau, lapack_complex_double* work,
                    double* rwork, lapack_int *info );
void LAPACK_sgeqp3( lapack_int* m, lapack_int* n, float* a, lapack_int* lda,
                    lapack_int* jpvt, float* tau, float* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_dgeqp3( lapack_int* m, lapack_int* n, double* a, lapack_int* lda,
                    lapack_int* jpvt, double* tau, double* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_cgeqp3( lapack_int* m, lapack_int* n, lapack_complex_float* a,
                    lapack_int* lda, lapack_int* jpvt,
                    lapack_complex_float* tau, lapack_complex_float* work,
                    lapack_int* lwork, float* rwork, lapack_int *info );
void LAPACK_zgeqp3( lapack_int* m, lapack_int* n, lapack_complex_double* a,
                    lapack_int* lda, lapack_int* jpvt,
                    lapack_complex_double* tau, lapack_complex_double* work,
                    lapack_int* lwork, double* rwork, lapack_int *info );
void LAPACK_sorgqr( lapack_int* m, lapack_int* n, lapack_int* k, float* a,
                    lapack_int* lda, const float* tau, float* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_dorgqr( lapack_int* m, lapack_int* n, lapack_int* k, double* a,
                    lapack_int* lda, const double* tau, double* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_sormqr( char* side, char* trans, lapack_int* m, lapack_int* n,
                    lapack_int* k, const float* a, lapack_int* lda,
                    const float* tau, float* c, lapack_int* ldc, float* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_dormqr( char* side, char* trans, lapack_int* m, lapack_int* n,
                    lapack_int* k, const double* a, lapack_int* lda,
                    const double* tau, double* c, lapack_int* ldc, double* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_cungqr( lapack_int* m, lapack_int* n, lapack_int* k,
                    lapack_complex_float* a, lapack_int* lda,
                    const lapack_complex_float* tau, lapack_complex_float* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_zungqr( lapack_int* m, lapack_int* n, lapack_int* k,
                    lapack_complex_double* a, lapack_int* lda,
                    const lapack_complex_double* tau,
                    lapack_complex_double* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_cunmqr( char* side, char* trans, lapack_int* m, lapack_int* n,
                    lapack_int* k, const lapack_complex_float* a,
                    lapack_int* lda, const lapack_complex_float* tau,
                    lapack_complex_float* c, lapack_int* ldc,
                    lapack_complex_float* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_zunmqr( char* side, char* trans, lapack_int* m, lapack_int* n,
                    lapack_int* k, const lapack_complex_double* a,
                    lapack_int* lda, const lapack_complex_double* tau,
                    lapack_complex_double* c, lapack_int* ldc,
                    lapack_complex_double* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_sgelqf( lapack_int* m, lapack_int* n, float* a, lapack_int* lda,
                    float* tau, float* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_dgelqf( lapack_int* m, lapack_int* n, double* a, lapack_int* lda,
                    double* tau, double* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_cgelqf( lapack_int* m, lapack_int* n, lapack_complex_float* a,
                    lapack_int* lda, lapack_complex_float* tau,
                    lapack_complex_float* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_zgelqf( lapack_int* m, lapack_int* n, lapack_complex_double* a,
                    lapack_int* lda, lapack_complex_double* tau,
                    lapack_complex_double* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_sorglq( lapack_int* m, lapack_int* n, lapack_int* k, float* a,
                    lapack_int* lda, const float* tau, float* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_dorglq( lapack_int* m, lapack_int* n, lapack_int* k, double* a,
                    lapack_int* lda, const double* tau, double* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_sormlq( char* side, char* trans, lapack_int* m, lapack_int* n,
                    lapack_int* k, const float* a, lapack_int* lda,
                    const float* tau, float* c, lapack_int* ldc, float* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_dormlq( char* side, char* trans, lapack_int* m, lapack_int* n,
                    lapack_int* k, const double* a, lapack_int* lda,
                    const double* tau, double* c, lapack_int* ldc, double* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_cunglq( lapack_int* m, lapack_int* n, lapack_int* k,
                    lapack_complex_float* a, lapack_int* lda,
                    const lapack_complex_float* tau, lapack_complex_float* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_zunglq( lapack_int* m, lapack_int* n, lapack_int* k,
                    lapack_complex_double* a, lapack_int* lda,
                    const lapack_complex_double* tau,
                    lapack_complex_double* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_cunmlq( char* side, char* trans, lapack_int* m, lapack_int* n,
                    lapack_int* k, const lapack_complex_float* a,
                    lapack_int* lda, const lapack_complex_float* tau,
                    lapack_complex_float* c, lapack_int* ldc,
                    lapack_complex_float* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_zunmlq( char* side, char* trans, lapack_int* m, lapack_int* n,
                    lapack_int* k, const lapack_complex_double* a,
                    lapack_int* lda, const lapack_complex_double* tau,
                    lapack_complex_double* c, lapack_int* ldc,
                    lapack_complex_double* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_sgeqlf( lapack_int* m, lapack_int* n, float* a, lapack_int* lda,
                    float* tau, float* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_dgeqlf( lapack_int* m, lapack_int* n, double* a, lapack_int* lda,
                    double* tau, double* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_cgeqlf( lapack_int* m, lapack_int* n, lapack_complex_float* a,
                    lapack_int* lda, lapack_complex_float* tau,
                    lapack_complex_float* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_zgeqlf( lapack_int* m, lapack_int* n, lapack_complex_double* a,
                    lapack_int* lda, lapack_complex_double* tau,
                    lapack_complex_double* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_sorgql( lapack_int* m, lapack_int* n, lapack_int* k, float* a,
                    lapack_int* lda, const float* tau, float* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_dorgql( lapack_int* m, lapack_int* n, lapack_int* k, double* a,
                    lapack_int* lda, const double* tau, double* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_cungql( lapack_int* m, lapack_int* n, lapack_int* k,
                    lapack_complex_float* a, lapack_int* lda,
                    const lapack_complex_float* tau, lapack_complex_float* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_zungql( lapack_int* m, lapack_int* n, lapack_int* k,
                    lapack_complex_double* a, lapack_int* lda,
                    const lapack_complex_double* tau,
                    lapack_complex_double* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_sormql( char* side, char* trans, lapack_int* m, lapack_int* n,
                    lapack_int* k, const float* a, lapack_int* lda,
                    const float* tau, float* c, lapack_int* ldc, float* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_dormql( char* side, char* trans, lapack_int* m, lapack_int* n,
                    lapack_int* k, const double* a, lapack_int* lda,
                    const double* tau, double* c, lapack_int* ldc, double* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_cunmql( char* side, char* trans, lapack_int* m, lapack_int* n,
                    lapack_int* k, const lapack_complex_float* a,
                    lapack_int* lda, const lapack_complex_float* tau,
                    lapack_complex_float* c, lapack_int* ldc,
                    lapack_complex_float* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_zunmql( char* side, char* trans, lapack_int* m, lapack_int* n,
                    lapack_int* k, const lapack_complex_double* a,
                    lapack_int* lda, const lapack_complex_double* tau,
                    lapack_complex_double* c, lapack_int* ldc,
                    lapack_complex_double* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_sgerqf( lapack_int* m, lapack_int* n, float* a, lapack_int* lda,
                    float* tau, float* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_dgerqf( lapack_int* m, lapack_int* n, double* a, lapack_int* lda,
                    double* tau, double* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_cgerqf( lapack_int* m, lapack_int* n, lapack_complex_float* a,
                    lapack_int* lda, lapack_complex_float* tau,
                    lapack_complex_float* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_zgerqf( lapack_int* m, lapack_int* n, lapack_complex_double* a,
                    lapack_int* lda, lapack_complex_double* tau,
                    lapack_complex_double* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_sorgrq( lapack_int* m, lapack_int* n, lapack_int* k, float* a,
                    lapack_int* lda, const float* tau, float* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_dorgrq( lapack_int* m, lapack_int* n, lapack_int* k, double* a,
                    lapack_int* lda, const double* tau, double* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_cungrq( lapack_int* m, lapack_int* n, lapack_int* k,
                    lapack_complex_float* a, lapack_int* lda,
                    const lapack_complex_float* tau, lapack_complex_float* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_zungrq( lapack_int* m, lapack_int* n, lapack_int* k,
                    lapack_complex_double* a, lapack_int* lda,
                    const lapack_complex_double* tau,
                    lapack_complex_double* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_sormrq( char* side, char* trans, lapack_int* m, lapack_int* n,
                    lapack_int* k, const float* a, lapack_int* lda,
                    const float* tau, float* c, lapack_int* ldc, float* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_dormrq( char* side, char* trans, lapack_int* m, lapack_int* n,
                    lapack_int* k, const double* a, lapack_int* lda,
                    const double* tau, double* c, lapack_int* ldc, double* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_cunmrq( char* side, char* trans, lapack_int* m, lapack_int* n,
                    lapack_int* k, const lapack_complex_float* a,
                    lapack_int* lda, const lapack_complex_float* tau,
                    lapack_complex_float* c, lapack_int* ldc,
                    lapack_complex_float* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_zunmrq( char* side, char* trans, lapack_int* m, lapack_int* n,
                    lapack_int* k, const lapack_complex_double* a,
                    lapack_int* lda, const lapack_complex_double* tau,
                    lapack_complex_double* c, lapack_int* ldc,
                    lapack_complex_double* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_stzrzf( lapack_int* m, lapack_int* n, float* a, lapack_int* lda,
                    float* tau, float* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_dtzrzf( lapack_int* m, lapack_int* n, double* a, lapack_int* lda,
                    double* tau, double* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_ctzrzf( lapack_int* m, lapack_int* n, lapack_complex_float* a,
                    lapack_int* lda, lapack_complex_float* tau,
                    lapack_complex_float* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_ztzrzf( lapack_int* m, lapack_int* n, lapack_complex_double* a,
                    lapack_int* lda, lapack_complex_double* tau,
                    lapack_complex_double* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_sormrz( char* side, char* trans, lapack_int* m, lapack_int* n,
                    lapack_int* k, lapack_int* l, const float* a,
                    lapack_int* lda, const float* tau, float* c,
                    lapack_int* ldc, float* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_dormrz( char* side, char* trans, lapack_int* m, lapack_int* n,
                    lapack_int* k, lapack_int* l, const double* a,
                    lapack_int* lda, const double* tau, double* c,
                    lapack_int* ldc, double* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_cunmrz( char* side, char* trans, lapack_int* m, lapack_int* n,
                    lapack_int* k, lapack_int* l, const lapack_complex_float* a,
                    lapack_int* lda, const lapack_complex_float* tau,
                    lapack_complex_float* c, lapack_int* ldc,
                    lapack_complex_float* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_zunmrz( char* side, char* trans, lapack_int* m, lapack_int* n,
                    lapack_int* k, lapack_int* l,
                    const lapack_complex_double* a, lapack_int* lda,
                    const lapack_complex_double* tau, lapack_complex_double* c,
                    lapack_int* ldc, lapack_complex_double* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_sggqrf( lapack_int* n, lapack_int* m, lapack_int* p, float* a,
                    lapack_int* lda, float* taua, float* b, lapack_int* ldb,
                    float* taub, float* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_dggqrf( lapack_int* n, lapack_int* m, lapack_int* p, double* a,
                    lapack_int* lda, double* taua, double* b, lapack_int* ldb,
                    double* taub, double* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_cggqrf( lapack_int* n, lapack_int* m, lapack_int* p,
                    lapack_complex_float* a, lapack_int* lda,
                    lapack_complex_float* taua, lapack_complex_float* b,
                    lapack_int* ldb, lapack_complex_float* taub,
                    lapack_complex_float* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_zggqrf( lapack_int* n, lapack_int* m, lapack_int* p,
                    lapack_complex_double* a, lapack_int* lda,
                    lapack_complex_double* taua, lapack_complex_double* b,
                    lapack_int* ldb, lapack_complex_double* taub,
                    lapack_complex_double* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_sggrqf( lapack_int* m, lapack_int* p, lapack_int* n, float* a,
                    lapack_int* lda, float* taua, float* b, lapack_int* ldb,
                    float* taub, float* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_dggrqf( lapack_int* m, lapack_int* p, lapack_int* n, double* a,
                    lapack_int* lda, double* taua, double* b, lapack_int* ldb,
                    double* taub, double* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_cggrqf( lapack_int* m, lapack_int* p, lapack_int* n,
                    lapack_complex_float* a, lapack_int* lda,
                    lapack_complex_float* taua, lapack_complex_float* b,
                    lapack_int* ldb, lapack_complex_float* taub,
                    lapack_complex_float* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_zggrqf( lapack_int* m, lapack_int* p, lapack_int* n,
                    lapack_complex_double* a, lapack_int* lda,
                    lapack_complex_double* taua, lapack_complex_double* b,
                    lapack_int* ldb, lapack_complex_double* taub,
                    lapack_complex_double* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_sgebrd( lapack_int* m, lapack_int* n, float* a, lapack_int* lda,
                    float* d, float* e, float* tauq, float* taup, float* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_dgebrd( lapack_int* m, lapack_int* n, double* a, lapack_int* lda,
                    double* d, double* e, double* tauq, double* taup,
                    double* work, lapack_int* lwork, lapack_int *info );
void LAPACK_cgebrd( lapack_int* m, lapack_int* n, lapack_complex_float* a,
                    lapack_int* lda, float* d, float* e,
                    lapack_complex_float* tauq, lapack_complex_float* taup,
                    lapack_complex_float* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_zgebrd( lapack_int* m, lapack_int* n, lapack_complex_double* a,
                    lapack_int* lda, double* d, double* e,
                    lapack_complex_double* tauq, lapack_complex_double* taup,
                    lapack_complex_double* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_sgbbrd( char* vect, lapack_int* m, lapack_int* n, lapack_int* ncc,
                    lapack_int* kl, lapack_int* ku, float* ab, lapack_int* ldab,
                    float* d, float* e, float* q, lapack_int* ldq, float* pt,
                    lapack_int* ldpt, float* c, lapack_int* ldc, float* work,
                    lapack_int *info );
void LAPACK_dgbbrd( char* vect, lapack_int* m, lapack_int* n, lapack_int* ncc,
                    lapack_int* kl, lapack_int* ku, double* ab,
                    lapack_int* ldab, double* d, double* e, double* q,
                    lapack_int* ldq, double* pt, lapack_int* ldpt, double* c,
                    lapack_int* ldc, double* work, lapack_int *info );
void LAPACK_cgbbrd( char* vect, lapack_int* m, lapack_int* n, lapack_int* ncc,
                    lapack_int* kl, lapack_int* ku, lapack_complex_float* ab,
                    lapack_int* ldab, float* d, float* e,
                    lapack_complex_float* q, lapack_int* ldq,
                    lapack_complex_float* pt, lapack_int* ldpt,
                    lapack_complex_float* c, lapack_int* ldc,
                    lapack_complex_float* work, float* rwork,
                    lapack_int *info );
void LAPACK_zgbbrd( char* vect, lapack_int* m, lapack_int* n, lapack_int* ncc,
                    lapack_int* kl, lapack_int* ku, lapack_complex_double* ab,
                    lapack_int* ldab, double* d, double* e,
                    lapack_complex_double* q, lapack_int* ldq,
                    lapack_complex_double* pt, lapack_int* ldpt,
                    lapack_complex_double* c, lapack_int* ldc,
                    lapack_complex_double* work, double* rwork,
                    lapack_int *info );
void LAPACK_sorgbr( char* vect, lapack_int* m, lapack_int* n, lapack_int* k,
                    float* a, lapack_int* lda, const float* tau, float* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_dorgbr( char* vect, lapack_int* m, lapack_int* n, lapack_int* k,
                    double* a, lapack_int* lda, const double* tau, double* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_sormbr( char* vect, char* side, char* trans, lapack_int* m,
                    lapack_int* n, lapack_int* k, const float* a,
                    lapack_int* lda, const float* tau, float* c,
                    lapack_int* ldc, float* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_dormbr( char* vect, char* side, char* trans, lapack_int* m,
                    lapack_int* n, lapack_int* k, const double* a,
                    lapack_int* lda, const double* tau, double* c,
                    lapack_int* ldc, double* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_cungbr( char* vect, lapack_int* m, lapack_int* n, lapack_int* k,
                    lapack_complex_float* a, lapack_int* lda,
                    const lapack_complex_float* tau, lapack_complex_float* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_zungbr( char* vect, lapack_int* m, lapack_int* n, lapack_int* k,
                    lapack_complex_double* a, lapack_int* lda,
                    const lapack_complex_double* tau,
                    lapack_complex_double* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_cunmbr( char* vect, char* side, char* trans, lapack_int* m,
                    lapack_int* n, lapack_int* k, const lapack_complex_float* a,
                    lapack_int* lda, const lapack_complex_float* tau,
                    lapack_complex_float* c, lapack_int* ldc,
                    lapack_complex_float* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_zunmbr( char* vect, char* side, char* trans, lapack_int* m,
                    lapack_int* n, lapack_int* k,
                    const lapack_complex_double* a, lapack_int* lda,
                    const lapack_complex_double* tau, lapack_complex_double* c,
                    lapack_int* ldc, lapack_complex_double* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_sbdsqr( char* uplo, lapack_int* n, lapack_int* ncvt,
                    lapack_int* nru, lapack_int* ncc, float* d, float* e,
                    float* vt, lapack_int* ldvt, float* u, lapack_int* ldu,
                    float* c, lapack_int* ldc, float* work, lapack_int *info );
void LAPACK_dbdsqr( char* uplo, lapack_int* n, lapack_int* ncvt,
                    lapack_int* nru, lapack_int* ncc, double* d, double* e,
                    double* vt, lapack_int* ldvt, double* u, lapack_int* ldu,
                    double* c, lapack_int* ldc, double* work,
                    lapack_int *info );
void LAPACK_cbdsqr( char* uplo, lapack_int* n, lapack_int* ncvt,
                    lapack_int* nru, lapack_int* ncc, float* d, float* e,
                    lapack_complex_float* vt, lapack_int* ldvt,
                    lapack_complex_float* u, lapack_int* ldu,
                    lapack_complex_float* c, lapack_int* ldc, float* work,
                    lapack_int *info );
void LAPACK_zbdsqr( char* uplo, lapack_int* n, lapack_int* ncvt,
                    lapack_int* nru, lapack_int* ncc, double* d, double* e,
                    lapack_complex_double* vt, lapack_int* ldvt,
                    lapack_complex_double* u, lapack_int* ldu,
                    lapack_complex_double* c, lapack_int* ldc, double* work,
                    lapack_int *info );
void LAPACK_sbdsdc( char* uplo, char* compq, lapack_int* n, float* d, float* e,
                    float* u, lapack_int* ldu, float* vt, lapack_int* ldvt,
                    float* q, lapack_int* iq, float* work, lapack_int* iwork,
                    lapack_int *info );
void LAPACK_dbdsdc( char* uplo, char* compq, lapack_int* n, double* d,
                    double* e, double* u, lapack_int* ldu, double* vt,
                    lapack_int* ldvt, double* q, lapack_int* iq, double* work,
                    lapack_int* iwork, lapack_int *info );
void LAPACK_ssytrd( char* uplo, lapack_int* n, float* a, lapack_int* lda,
                    float* d, float* e, float* tau, float* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_dsytrd( char* uplo, lapack_int* n, double* a, lapack_int* lda,
                    double* d, double* e, double* tau, double* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_sorgtr( char* uplo, lapack_int* n, float* a, lapack_int* lda,
                    const float* tau, float* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_dorgtr( char* uplo, lapack_int* n, double* a, lapack_int* lda,
                    const double* tau, double* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_sormtr( char* side, char* uplo, char* trans, lapack_int* m,
                    lapack_int* n, const float* a, lapack_int* lda,
                    const float* tau, float* c, lapack_int* ldc, float* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_dormtr( char* side, char* uplo, char* trans, lapack_int* m,
                    lapack_int* n, const double* a, lapack_int* lda,
                    const double* tau, double* c, lapack_int* ldc, double* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_chetrd( char* uplo, lapack_int* n, lapack_complex_float* a,
                    lapack_int* lda, float* d, float* e,
                    lapack_complex_float* tau, lapack_complex_float* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_zhetrd( char* uplo, lapack_int* n, lapack_complex_double* a,
                    lapack_int* lda, double* d, double* e,
                    lapack_complex_double* tau, lapack_complex_double* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_cungtr( char* uplo, lapack_int* n, lapack_complex_float* a,
                    lapack_int* lda, const lapack_complex_float* tau,
                    lapack_complex_float* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_zungtr( char* uplo, lapack_int* n, lapack_complex_double* a,
                    lapack_int* lda, const lapack_complex_double* tau,
                    lapack_complex_double* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_cunmtr( char* side, char* uplo, char* trans, lapack_int* m,
                    lapack_int* n, const lapack_complex_float* a,
                    lapack_int* lda, const lapack_complex_float* tau,
                    lapack_complex_float* c, lapack_int* ldc,
                    lapack_complex_float* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_zunmtr( char* side, char* uplo, char* trans, lapack_int* m,
                    lapack_int* n, const lapack_complex_double* a,
                    lapack_int* lda, const lapack_complex_double* tau,
                    lapack_complex_double* c, lapack_int* ldc,
                    lapack_complex_double* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_ssptrd( char* uplo, lapack_int* n, float* ap, float* d, float* e,
                    float* tau, lapack_int *info );
void LAPACK_dsptrd( char* uplo, lapack_int* n, double* ap, double* d, double* e,
                    double* tau, lapack_int *info );
void LAPACK_sopgtr( char* uplo, lapack_int* n, const float* ap,
                    const float* tau, float* q, lapack_int* ldq, float* work,
                    lapack_int *info );
void LAPACK_dopgtr( char* uplo, lapack_int* n, const double* ap,
                    const double* tau, double* q, lapack_int* ldq, double* work,
                    lapack_int *info );
void LAPACK_sopmtr( char* side, char* uplo, char* trans, lapack_int* m,
                    lapack_int* n, const float* ap, const float* tau, float* c,
                    lapack_int* ldc, float* work, lapack_int *info );
void LAPACK_dopmtr( char* side, char* uplo, char* trans, lapack_int* m,
                    lapack_int* n, const double* ap, const double* tau,
                    double* c, lapack_int* ldc, double* work,
                    lapack_int *info );
void LAPACK_chptrd( char* uplo, lapack_int* n, lapack_complex_float* ap,
                    float* d, float* e, lapack_complex_float* tau,
                    lapack_int *info );
void LAPACK_zhptrd( char* uplo, lapack_int* n, lapack_complex_double* ap,
                    double* d, double* e, lapack_complex_double* tau,
                    lapack_int *info );
void LAPACK_cupgtr( char* uplo, lapack_int* n, const lapack_complex_float* ap,
                    const lapack_complex_float* tau, lapack_complex_float* q,
                    lapack_int* ldq, lapack_complex_float* work,
                    lapack_int *info );
void LAPACK_zupgtr( char* uplo, lapack_int* n, const lapack_complex_double* ap,
                    const lapack_complex_double* tau, lapack_complex_double* q,
                    lapack_int* ldq, lapack_complex_double* work,
                    lapack_int *info );
void LAPACK_cupmtr( char* side, char* uplo, char* trans, lapack_int* m,
                    lapack_int* n, const lapack_complex_float* ap,
                    const lapack_complex_float* tau, lapack_complex_float* c,
                    lapack_int* ldc, lapack_complex_float* work,
                    lapack_int *info );
void LAPACK_zupmtr( char* side, char* uplo, char* trans, lapack_int* m,
                    lapack_int* n, const lapack_complex_double* ap,
                    const lapack_complex_double* tau, lapack_complex_double* c,
                    lapack_int* ldc, lapack_complex_double* work,
                    lapack_int *info );
void LAPACK_ssbtrd( char* vect, char* uplo, lapack_int* n, lapack_int* kd,
                    float* ab, lapack_int* ldab, float* d, float* e, float* q,
                    lapack_int* ldq, float* work, lapack_int *info );
void LAPACK_dsbtrd( char* vect, char* uplo, lapack_int* n, lapack_int* kd,
                    double* ab, lapack_int* ldab, double* d, double* e,
                    double* q, lapack_int* ldq, double* work,
                    lapack_int *info );
void LAPACK_chbtrd( char* vect, char* uplo, lapack_int* n, lapack_int* kd,
                    lapack_complex_float* ab, lapack_int* ldab, float* d,
                    float* e, lapack_complex_float* q, lapack_int* ldq,
                    lapack_complex_float* work, lapack_int *info );
void LAPACK_zhbtrd( char* vect, char* uplo, lapack_int* n, lapack_int* kd,
                    lapack_complex_double* ab, lapack_int* ldab, double* d,
                    double* e, lapack_complex_double* q, lapack_int* ldq,
                    lapack_complex_double* work, lapack_int *info );
void LAPACK_ssterf( lapack_int* n, float* d, float* e, lapack_int *info );
void LAPACK_dsterf( lapack_int* n, double* d, double* e, lapack_int *info );
void LAPACK_ssteqr( char* compz, lapack_int* n, float* d, float* e, float* z,
                    lapack_int* ldz, float* work, lapack_int *info );
void LAPACK_dsteqr( char* compz, lapack_int* n, double* d, double* e, double* z,
                    lapack_int* ldz, double* work, lapack_int *info );
void LAPACK_csteqr( char* compz, lapack_int* n, float* d, float* e,
                    lapack_complex_float* z, lapack_int* ldz, float* work,
                    lapack_int *info );
void LAPACK_zsteqr( char* compz, lapack_int* n, double* d, double* e,
                    lapack_complex_double* z, lapack_int* ldz, double* work,
                    lapack_int *info );
void LAPACK_sstemr( char* jobz, char* range, lapack_int* n, float* d, float* e,
                    float* vl, float* vu, lapack_int* il, lapack_int* iu,
                    lapack_int* m, float* w, float* z, lapack_int* ldz,
                    lapack_int* nzc, lapack_int* isuppz, lapack_logical* tryrac,
                    float* work, lapack_int* lwork, lapack_int* iwork,
                    lapack_int* liwork, lapack_int *info );
void LAPACK_dstemr( char* jobz, char* range, lapack_int* n, double* d,
                    double* e, double* vl, double* vu, lapack_int* il,
                    lapack_int* iu, lapack_int* m, double* w, double* z,
                    lapack_int* ldz, lapack_int* nzc, lapack_int* isuppz,
                    lapack_logical* tryrac, double* work, lapack_int* lwork,
                    lapack_int* iwork, lapack_int* liwork, lapack_int *info );
void LAPACK_cstemr( char* jobz, char* range, lapack_int* n, float* d, float* e,
                    float* vl, float* vu, lapack_int* il, lapack_int* iu,
                    lapack_int* m, float* w, lapack_complex_float* z,
                    lapack_int* ldz, lapack_int* nzc, lapack_int* isuppz,
                    lapack_logical* tryrac, float* work, lapack_int* lwork,
                    lapack_int* iwork, lapack_int* liwork, lapack_int *info );
void LAPACK_zstemr( char* jobz, char* range, lapack_int* n, double* d,
                    double* e, double* vl, double* vu, lapack_int* il,
                    lapack_int* iu, lapack_int* m, double* w,
                    lapack_complex_double* z, lapack_int* ldz, lapack_int* nzc,
                    lapack_int* isuppz, lapack_logical* tryrac, double* work,
                    lapack_int* lwork, lapack_int* iwork, lapack_int* liwork,
                    lapack_int *info );
void LAPACK_sstedc( char* compz, lapack_int* n, float* d, float* e, float* z,
                    lapack_int* ldz, float* work, lapack_int* lwork,
                    lapack_int* iwork, lapack_int* liwork, lapack_int *info );
void LAPACK_dstedc( char* compz, lapack_int* n, double* d, double* e, double* z,
                    lapack_int* ldz, double* work, lapack_int* lwork,
                    lapack_int* iwork, lapack_int* liwork, lapack_int *info );
void LAPACK_cstedc( char* compz, lapack_int* n, float* d, float* e,
                    lapack_complex_float* z, lapack_int* ldz,
                    lapack_complex_float* work, lapack_int* lwork, float* rwork,
                    lapack_int* lrwork, lapack_int* iwork, lapack_int* liwork,
                    lapack_int *info );
void LAPACK_zstedc( char* compz, lapack_int* n, double* d, double* e,
                    lapack_complex_double* z, lapack_int* ldz,
                    lapack_complex_double* work, lapack_int* lwork,
                    double* rwork, lapack_int* lrwork, lapack_int* iwork,
                    lapack_int* liwork, lapack_int *info );
void LAPACK_sstegr( char* jobz, char* range, lapack_int* n, float* d, float* e,
                    float* vl, float* vu, lapack_int* il, lapack_int* iu,
                    float* abstol, lapack_int* m, float* w, float* z,
                    lapack_int* ldz, lapack_int* isuppz, float* work,
                    lapack_int* lwork, lapack_int* iwork, lapack_int* liwork,
                    lapack_int *info );
void LAPACK_dstegr( char* jobz, char* range, lapack_int* n, double* d,
                    double* e, double* vl, double* vu, lapack_int* il,
                    lapack_int* iu, double* abstol, lapack_int* m, double* w,
                    double* z, lapack_int* ldz, lapack_int* isuppz,
                    double* work, lapack_int* lwork, lapack_int* iwork,
                    lapack_int* liwork, lapack_int *info );
void LAPACK_cstegr( char* jobz, char* range, lapack_int* n, float* d, float* e,
                    float* vl, float* vu, lapack_int* il, lapack_int* iu,
                    float* abstol, lapack_int* m, float* w,
                    lapack_complex_float* z, lapack_int* ldz,
                    lapack_int* isuppz, float* work, lapack_int* lwork,
                    lapack_int* iwork, lapack_int* liwork, lapack_int *info );
void LAPACK_zstegr( char* jobz, char* range, lapack_int* n, double* d,
                    double* e, double* vl, double* vu, lapack_int* il,
                    lapack_int* iu, double* abstol, lapack_int* m, double* w,
                    lapack_complex_double* z, lapack_int* ldz,
                    lapack_int* isuppz, double* work, lapack_int* lwork,
                    lapack_int* iwork, lapack_int* liwork, lapack_int *info );
void LAPACK_spteqr( char* compz, lapack_int* n, float* d, float* e, float* z,
                    lapack_int* ldz, float* work, lapack_int *info );
void LAPACK_dpteqr( char* compz, lapack_int* n, double* d, double* e, double* z,
                    lapack_int* ldz, double* work, lapack_int *info );
void LAPACK_cpteqr( char* compz, lapack_int* n, float* d, float* e,
                    lapack_complex_float* z, lapack_int* ldz, float* work,
                    lapack_int *info );
void LAPACK_zpteqr( char* compz, lapack_int* n, double* d, double* e,
                    lapack_complex_double* z, lapack_int* ldz, double* work,
                    lapack_int *info );
void LAPACK_sstebz( char* range, char* order, lapack_int* n, float* vl,
                    float* vu, lapack_int* il, lapack_int* iu, float* abstol,
                    const float* d, const float* e, lapack_int* m,
                    lapack_int* nsplit, float* w, lapack_int* iblock,
                    lapack_int* isplit, float* work, lapack_int* iwork,
                    lapack_int *info );
void LAPACK_dstebz( char* range, char* order, lapack_int* n, double* vl,
                    double* vu, lapack_int* il, lapack_int* iu, double* abstol,
                    const double* d, const double* e, lapack_int* m,
                    lapack_int* nsplit, double* w, lapack_int* iblock,
                    lapack_int* isplit, double* work, lapack_int* iwork,
                    lapack_int *info );
void LAPACK_sstein( lapack_int* n, const float* d, const float* e,
                    lapack_int* m, const float* w, const lapack_int* iblock,
                    const lapack_int* isplit, float* z, lapack_int* ldz,
                    float* work, lapack_int* iwork, lapack_int* ifailv,
                    lapack_int *info );
void LAPACK_dstein( lapack_int* n, const double* d, const double* e,
                    lapack_int* m, const double* w, const lapack_int* iblock,
                    const lapack_int* isplit, double* z, lapack_int* ldz,
                    double* work, lapack_int* iwork, lapack_int* ifailv,
                    lapack_int *info );
void LAPACK_cstein( lapack_int* n, const float* d, const float* e,
                    lapack_int* m, const float* w, const lapack_int* iblock,
                    const lapack_int* isplit, lapack_complex_float* z,
                    lapack_int* ldz, float* work, lapack_int* iwork,
                    lapack_int* ifailv, lapack_int *info );
void LAPACK_zstein( lapack_int* n, const double* d, const double* e,
                    lapack_int* m, const double* w, const lapack_int* iblock,
                    const lapack_int* isplit, lapack_complex_double* z,
                    lapack_int* ldz, double* work, lapack_int* iwork,
                    lapack_int* ifailv, lapack_int *info );
void LAPACK_sdisna( char* job, lapack_int* m, lapack_int* n, const float* d,
                    float* sep, lapack_int *info );
void LAPACK_ddisna( char* job, lapack_int* m, lapack_int* n, const double* d,
                    double* sep, lapack_int *info );
void LAPACK_ssygst( lapack_int* itype, char* uplo, lapack_int* n, float* a,
                    lapack_int* lda, const float* b, lapack_int* ldb,
                    lapack_int *info );
void LAPACK_dsygst( lapack_int* itype, char* uplo, lapack_int* n, double* a,
                    lapack_int* lda, const double* b, lapack_int* ldb,
                    lapack_int *info );
void LAPACK_chegst( lapack_int* itype, char* uplo, lapack_int* n,
                    lapack_complex_float* a, lapack_int* lda,
                    const lapack_complex_float* b, lapack_int* ldb,
                    lapack_int *info );
void LAPACK_zhegst( lapack_int* itype, char* uplo, lapack_int* n,
                    lapack_complex_double* a, lapack_int* lda,
                    const lapack_complex_double* b, lapack_int* ldb,
                    lapack_int *info );
void LAPACK_sspgst( lapack_int* itype, char* uplo, lapack_int* n, float* ap,
                    const float* bp, lapack_int *info );
void LAPACK_dspgst( lapack_int* itype, char* uplo, lapack_int* n, double* ap,
                    const double* bp, lapack_int *info );
void LAPACK_chpgst( lapack_int* itype, char* uplo, lapack_int* n,
                    lapack_complex_float* ap, const lapack_complex_float* bp,
                    lapack_int *info );
void LAPACK_zhpgst( lapack_int* itype, char* uplo, lapack_int* n,
                    lapack_complex_double* ap, const lapack_complex_double* bp,
                    lapack_int *info );
void LAPACK_ssbgst( char* vect, char* uplo, lapack_int* n, lapack_int* ka,
                    lapack_int* kb, float* ab, lapack_int* ldab,
                    const float* bb, lapack_int* ldbb, float* x,
                    lapack_int* ldx, float* work, lapack_int *info );
void LAPACK_dsbgst( char* vect, char* uplo, lapack_int* n, lapack_int* ka,
                    lapack_int* kb, double* ab, lapack_int* ldab,
                    const double* bb, lapack_int* ldbb, double* x,
                    lapack_int* ldx, double* work, lapack_int *info );
void LAPACK_chbgst( char* vect, char* uplo, lapack_int* n, lapack_int* ka,
                    lapack_int* kb, lapack_complex_float* ab, lapack_int* ldab,
                    const lapack_complex_float* bb, lapack_int* ldbb,
                    lapack_complex_float* x, lapack_int* ldx,
                    lapack_complex_float* work, float* rwork,
                    lapack_int *info );
void LAPACK_zhbgst( char* vect, char* uplo, lapack_int* n, lapack_int* ka,
                    lapack_int* kb, lapack_complex_double* ab, lapack_int* ldab,
                    const lapack_complex_double* bb, lapack_int* ldbb,
                    lapack_complex_double* x, lapack_int* ldx,
                    lapack_complex_double* work, double* rwork,
                    lapack_int *info );
void LAPACK_spbstf( char* uplo, lapack_int* n, lapack_int* kb, float* bb,
                    lapack_int* ldbb, lapack_int *info );
void LAPACK_dpbstf( char* uplo, lapack_int* n, lapack_int* kb, double* bb,
                    lapack_int* ldbb, lapack_int *info );
void LAPACK_cpbstf( char* uplo, lapack_int* n, lapack_int* kb,
                    lapack_complex_float* bb, lapack_int* ldbb,
                    lapack_int *info );
void LAPACK_zpbstf( char* uplo, lapack_int* n, lapack_int* kb,
                    lapack_complex_double* bb, lapack_int* ldbb,
                    lapack_int *info );
void LAPACK_sgehrd( lapack_int* n, lapack_int* ilo, lapack_int* ihi, float* a,
                    lapack_int* lda, float* tau, float* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_dgehrd( lapack_int* n, lapack_int* ilo, lapack_int* ihi, double* a,
                    lapack_int* lda, double* tau, double* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_cgehrd( lapack_int* n, lapack_int* ilo, lapack_int* ihi,
                    lapack_complex_float* a, lapack_int* lda,
                    lapack_complex_float* tau, lapack_complex_float* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_zgehrd( lapack_int* n, lapack_int* ilo, lapack_int* ihi,
                    lapack_complex_double* a, lapack_int* lda,
                    lapack_complex_double* tau, lapack_complex_double* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_sorghr( lapack_int* n, lapack_int* ilo, lapack_int* ihi, float* a,
                    lapack_int* lda, const float* tau, float* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_dorghr( lapack_int* n, lapack_int* ilo, lapack_int* ihi, double* a,
                    lapack_int* lda, const double* tau, double* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_sormhr( char* side, char* trans, lapack_int* m, lapack_int* n,
                    lapack_int* ilo, lapack_int* ihi, const float* a,
                    lapack_int* lda, const float* tau, float* c,
                    lapack_int* ldc, float* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_dormhr( char* side, char* trans, lapack_int* m, lapack_int* n,
                    lapack_int* ilo, lapack_int* ihi, const double* a,
                    lapack_int* lda, const double* tau, double* c,
                    lapack_int* ldc, double* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_cunghr( lapack_int* n, lapack_int* ilo, lapack_int* ihi,
                    lapack_complex_float* a, lapack_int* lda,
                    const lapack_complex_float* tau, lapack_complex_float* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_zunghr( lapack_int* n, lapack_int* ilo, lapack_int* ihi,
                    lapack_complex_double* a, lapack_int* lda,
                    const lapack_complex_double* tau,
                    lapack_complex_double* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_cunmhr( char* side, char* trans, lapack_int* m, lapack_int* n,
                    lapack_int* ilo, lapack_int* ihi,
                    const lapack_complex_float* a, lapack_int* lda,
                    const lapack_complex_float* tau, lapack_complex_float* c,
                    lapack_int* ldc, lapack_complex_float* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_zunmhr( char* side, char* trans, lapack_int* m, lapack_int* n,
                    lapack_int* ilo, lapack_int* ihi,
                    const lapack_complex_double* a, lapack_int* lda,
                    const lapack_complex_double* tau, lapack_complex_double* c,
                    lapack_int* ldc, lapack_complex_double* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_sgebal( char* job, lapack_int* n, float* a, lapack_int* lda,
                    lapack_int* ilo, lapack_int* ihi, float* scale,
                    lapack_int *info );
void LAPACK_dgebal( char* job, lapack_int* n, double* a, lapack_int* lda,
                    lapack_int* ilo, lapack_int* ihi, double* scale,
                    lapack_int *info );
void LAPACK_cgebal( char* job, lapack_int* n, lapack_complex_float* a,
                    lapack_int* lda, lapack_int* ilo, lapack_int* ihi,
                    float* scale, lapack_int *info );
void LAPACK_zgebal( char* job, lapack_int* n, lapack_complex_double* a,
                    lapack_int* lda, lapack_int* ilo, lapack_int* ihi,
                    double* scale, lapack_int *info );
void LAPACK_sgebak( char* job, char* side, lapack_int* n, lapack_int* ilo,
                    lapack_int* ihi, const float* scale, lapack_int* m,
                    float* v, lapack_int* ldv, lapack_int *info );
void LAPACK_dgebak( char* job, char* side, lapack_int* n, lapack_int* ilo,
                    lapack_int* ihi, const double* scale, lapack_int* m,
                    double* v, lapack_int* ldv, lapack_int *info );
void LAPACK_cgebak( char* job, char* side, lapack_int* n, lapack_int* ilo,
                    lapack_int* ihi, const float* scale, lapack_int* m,
                    lapack_complex_float* v, lapack_int* ldv,
                    lapack_int *info );
void LAPACK_zgebak( char* job, char* side, lapack_int* n, lapack_int* ilo,
                    lapack_int* ihi, const double* scale, lapack_int* m,
                    lapack_complex_double* v, lapack_int* ldv,
                    lapack_int *info );
void LAPACK_shseqr( char* job, char* compz, lapack_int* n, lapack_int* ilo,
                    lapack_int* ihi, float* h, lapack_int* ldh, float* wr,
                    float* wi, float* z, lapack_int* ldz, float* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_dhseqr( char* job, char* compz, lapack_int* n, lapack_int* ilo,
                    lapack_int* ihi, double* h, lapack_int* ldh, double* wr,
                    double* wi, double* z, lapack_int* ldz, double* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_chseqr( char* job, char* compz, lapack_int* n, lapack_int* ilo,
                    lapack_int* ihi, lapack_complex_float* h, lapack_int* ldh,
                    lapack_complex_float* w, lapack_complex_float* z,
                    lapack_int* ldz, lapack_complex_float* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_zhseqr( char* job, char* compz, lapack_int* n, lapack_int* ilo,
                    lapack_int* ihi, lapack_complex_double* h, lapack_int* ldh,
                    lapack_complex_double* w, lapack_complex_double* z,
                    lapack_int* ldz, lapack_complex_double* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_shsein( char* job, char* eigsrc, char* initv,
                    lapack_logical* select, lapack_int* n, const float* h,
                    lapack_int* ldh, float* wr, const float* wi, float* vl,
                    lapack_int* ldvl, float* vr, lapack_int* ldvr,
                    lapack_int* mm, lapack_int* m, float* work,
                    lapack_int* ifaill, lapack_int* ifailr, lapack_int *info );
void LAPACK_dhsein( char* job, char* eigsrc, char* initv,
                    lapack_logical* select, lapack_int* n, const double* h,
                    lapack_int* ldh, double* wr, const double* wi, double* vl,
                    lapack_int* ldvl, double* vr, lapack_int* ldvr,
                    lapack_int* mm, lapack_int* m, double* work,
                    lapack_int* ifaill, lapack_int* ifailr, lapack_int *info );
void LAPACK_chsein( char* job, char* eigsrc, char* initv,
                    const lapack_logical* select, lapack_int* n,
                    const lapack_complex_float* h, lapack_int* ldh,
                    lapack_complex_float* w, lapack_complex_float* vl,
                    lapack_int* ldvl, lapack_complex_float* vr,
                    lapack_int* ldvr, lapack_int* mm, lapack_int* m,
                    lapack_complex_float* work, float* rwork,
                    lapack_int* ifaill, lapack_int* ifailr, lapack_int *info );
void LAPACK_zhsein( char* job, char* eigsrc, char* initv,
                    const lapack_logical* select, lapack_int* n,
                    const lapack_complex_double* h, lapack_int* ldh,
                    lapack_complex_double* w, lapack_complex_double* vl,
                    lapack_int* ldvl, lapack_complex_double* vr,
                    lapack_int* ldvr, lapack_int* mm, lapack_int* m,
                    lapack_complex_double* work, double* rwork,
                    lapack_int* ifaill, lapack_int* ifailr, lapack_int *info );
void LAPACK_strevc( char* side, char* howmny, lapack_logical* select,
                    lapack_int* n, const float* t, lapack_int* ldt, float* vl,
                    lapack_int* ldvl, float* vr, lapack_int* ldvr,
                    lapack_int* mm, lapack_int* m, float* work,
                    lapack_int *info );
void LAPACK_dtrevc( char* side, char* howmny, lapack_logical* select,
                    lapack_int* n, const double* t, lapack_int* ldt, double* vl,
                    lapack_int* ldvl, double* vr, lapack_int* ldvr,
                    lapack_int* mm, lapack_int* m, double* work,
                    lapack_int *info );
void LAPACK_ctrevc( char* side, char* howmny, const lapack_logical* select,
                    lapack_int* n, lapack_complex_float* t, lapack_int* ldt,
                    lapack_complex_float* vl, lapack_int* ldvl,
                    lapack_complex_float* vr, lapack_int* ldvr, lapack_int* mm,
                    lapack_int* m, lapack_complex_float* work, float* rwork,
                    lapack_int *info );
void LAPACK_ztrevc( char* side, char* howmny, const lapack_logical* select,
                    lapack_int* n, lapack_complex_double* t, lapack_int* ldt,
                    lapack_complex_double* vl, lapack_int* ldvl,
                    lapack_complex_double* vr, lapack_int* ldvr, lapack_int* mm,
                    lapack_int* m, lapack_complex_double* work, double* rwork,
                    lapack_int *info );
void LAPACK_strsna( char* job, char* howmny, const lapack_logical* select,
                    lapack_int* n, const float* t, lapack_int* ldt,
                    const float* vl, lapack_int* ldvl, const float* vr,
                    lapack_int* ldvr, float* s, float* sep, lapack_int* mm,
                    lapack_int* m, float* work, lapack_int* ldwork,
                    lapack_int* iwork, lapack_int *info );
void LAPACK_dtrsna( char* job, char* howmny, const lapack_logical* select,
                    lapack_int* n, const double* t, lapack_int* ldt,
                    const double* vl, lapack_int* ldvl, const double* vr,
                    lapack_int* ldvr, double* s, double* sep, lapack_int* mm,
                    lapack_int* m, double* work, lapack_int* ldwork,
                    lapack_int* iwork, lapack_int *info );
void LAPACK_ctrsna( char* job, char* howmny, const lapack_logical* select,
                    lapack_int* n, const lapack_complex_float* t,
                    lapack_int* ldt, const lapack_complex_float* vl,
                    lapack_int* ldvl, const lapack_complex_float* vr,
                    lapack_int* ldvr, float* s, float* sep, lapack_int* mm,
                    lapack_int* m, lapack_complex_float* work,
                    lapack_int* ldwork, float* rwork, lapack_int *info );
void LAPACK_ztrsna( char* job, char* howmny, const lapack_logical* select,
                    lapack_int* n, const lapack_complex_double* t,
                    lapack_int* ldt, const lapack_complex_double* vl,
                    lapack_int* ldvl, const lapack_complex_double* vr,
                    lapack_int* ldvr, double* s, double* sep, lapack_int* mm,
                    lapack_int* m, lapack_complex_double* work,
                    lapack_int* ldwork, double* rwork, lapack_int *info );
void LAPACK_strexc( char* compq, lapack_int* n, float* t, lapack_int* ldt,
                    float* q, lapack_int* ldq, lapack_int* ifst,
                    lapack_int* ilst, float* work, lapack_int *info );
void LAPACK_dtrexc( char* compq, lapack_int* n, double* t, lapack_int* ldt,
                    double* q, lapack_int* ldq, lapack_int* ifst,
                    lapack_int* ilst, double* work, lapack_int *info );
void LAPACK_ctrexc( char* compq, lapack_int* n, lapack_complex_float* t,
                    lapack_int* ldt, lapack_complex_float* q, lapack_int* ldq,
                    lapack_int* ifst, lapack_int* ilst, lapack_int *info );
void LAPACK_ztrexc( char* compq, lapack_int* n, lapack_complex_double* t,
                    lapack_int* ldt, lapack_complex_double* q, lapack_int* ldq,
                    lapack_int* ifst, lapack_int* ilst, lapack_int *info );
void LAPACK_strsen( char* job, char* compq, const lapack_logical* select,
                    lapack_int* n, float* t, lapack_int* ldt, float* q,
                    lapack_int* ldq, float* wr, float* wi, lapack_int* m,
                    float* s, float* sep, float* work, lapack_int* lwork,
                    lapack_int* iwork, lapack_int* liwork, lapack_int *info );
void LAPACK_dtrsen( char* job, char* compq, const lapack_logical* select,
                    lapack_int* n, double* t, lapack_int* ldt, double* q,
                    lapack_int* ldq, double* wr, double* wi, lapack_int* m,
                    double* s, double* sep, double* work, lapack_int* lwork,
                    lapack_int* iwork, lapack_int* liwork, lapack_int *info );
void LAPACK_ctrsen( char* job, char* compq, const lapack_logical* select,
                    lapack_int* n, lapack_complex_float* t, lapack_int* ldt,
                    lapack_complex_float* q, lapack_int* ldq,
                    lapack_complex_float* w, lapack_int* m, float* s,
                    float* sep, lapack_complex_float* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_ztrsen( char* job, char* compq, const lapack_logical* select,
                    lapack_int* n, lapack_complex_double* t, lapack_int* ldt,
                    lapack_complex_double* q, lapack_int* ldq,
                    lapack_complex_double* w, lapack_int* m, double* s,
                    double* sep, lapack_complex_double* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_strsyl( char* trana, char* tranb, lapack_int* isgn, lapack_int* m,
                    lapack_int* n, const float* a, lapack_int* lda,
                    const float* b, lapack_int* ldb, float* c, lapack_int* ldc,
                    float* scale, lapack_int *info );
void LAPACK_dtrsyl( char* trana, char* tranb, lapack_int* isgn, lapack_int* m,
                    lapack_int* n, const double* a, lapack_int* lda,
                    const double* b, lapack_int* ldb, double* c,
                    lapack_int* ldc, double* scale, lapack_int *info );
void LAPACK_ctrsyl( char* trana, char* tranb, lapack_int* isgn, lapack_int* m,
                    lapack_int* n, const lapack_complex_float* a,
                    lapack_int* lda, const lapack_complex_float* b,
                    lapack_int* ldb, lapack_complex_float* c, lapack_int* ldc,
                    float* scale, lapack_int *info );
void LAPACK_ztrsyl( char* trana, char* tranb, lapack_int* isgn, lapack_int* m,
                    lapack_int* n, const lapack_complex_double* a,
                    lapack_int* lda, const lapack_complex_double* b,
                    lapack_int* ldb, lapack_complex_double* c, lapack_int* ldc,
                    double* scale, lapack_int *info );
void LAPACK_sgghrd( char* compq, char* compz, lapack_int* n, lapack_int* ilo,
                    lapack_int* ihi, float* a, lapack_int* lda, float* b,
                    lapack_int* ldb, float* q, lapack_int* ldq, float* z,
                    lapack_int* ldz, lapack_int *info );
void LAPACK_dgghrd( char* compq, char* compz, lapack_int* n, lapack_int* ilo,
                    lapack_int* ihi, double* a, lapack_int* lda, double* b,
                    lapack_int* ldb, double* q, lapack_int* ldq, double* z,
                    lapack_int* ldz, lapack_int *info );
void LAPACK_cgghrd( char* compq, char* compz, lapack_int* n, lapack_int* ilo,
                    lapack_int* ihi, lapack_complex_float* a, lapack_int* lda,
                    lapack_complex_float* b, lapack_int* ldb,
                    lapack_complex_float* q, lapack_int* ldq,
                    lapack_complex_float* z, lapack_int* ldz,
                    lapack_int *info );
void LAPACK_zgghrd( char* compq, char* compz, lapack_int* n, lapack_int* ilo,
                    lapack_int* ihi, lapack_complex_double* a, lapack_int* lda,
                    lapack_complex_double* b, lapack_int* ldb,
                    lapack_complex_double* q, lapack_int* ldq,
                    lapack_complex_double* z, lapack_int* ldz,
                    lapack_int *info );
void LAPACK_sggbal( char* job, lapack_int* n, float* a, lapack_int* lda,
                    float* b, lapack_int* ldb, lapack_int* ilo, lapack_int* ihi,
                    float* lscale, float* rscale, float* work,
                    lapack_int *info );
void LAPACK_dggbal( char* job, lapack_int* n, double* a, lapack_int* lda,
                    double* b, lapack_int* ldb, lapack_int* ilo,
                    lapack_int* ihi, double* lscale, double* rscale,
                    double* work, lapack_int *info );
void LAPACK_cggbal( char* job, lapack_int* n, lapack_complex_float* a,
                    lapack_int* lda, lapack_complex_float* b, lapack_int* ldb,
                    lapack_int* ilo, lapack_int* ihi, float* lscale,
                    float* rscale, float* work, lapack_int *info );
void LAPACK_zggbal( char* job, lapack_int* n, lapack_complex_double* a,
                    lapack_int* lda, lapack_complex_double* b, lapack_int* ldb,
                    lapack_int* ilo, lapack_int* ihi, double* lscale,
                    double* rscale, double* work, lapack_int *info );
void LAPACK_sggbak( char* job, char* side, lapack_int* n, lapack_int* ilo,
                    lapack_int* ihi, const float* lscale, const float* rscale,
                    lapack_int* m, float* v, lapack_int* ldv,
                    lapack_int *info );
void LAPACK_dggbak( char* job, char* side, lapack_int* n, lapack_int* ilo,
                    lapack_int* ihi, const double* lscale, const double* rscale,
                    lapack_int* m, double* v, lapack_int* ldv,
                    lapack_int *info );
void LAPACK_cggbak( char* job, char* side, lapack_int* n, lapack_int* ilo,
                    lapack_int* ihi, const float* lscale, const float* rscale,
                    lapack_int* m, lapack_complex_float* v, lapack_int* ldv,
                    lapack_int *info );
void LAPACK_zggbak( char* job, char* side, lapack_int* n, lapack_int* ilo,
                    lapack_int* ihi, const double* lscale, const double* rscale,
                    lapack_int* m, lapack_complex_double* v, lapack_int* ldv,
                    lapack_int *info );
void LAPACK_shgeqz( char* job, char* compq, char* compz, lapack_int* n,
                    lapack_int* ilo, lapack_int* ihi, float* h, lapack_int* ldh,
                    float* t, lapack_int* ldt, float* alphar, float* alphai,
                    float* beta, float* q, lapack_int* ldq, float* z,
                    lapack_int* ldz, float* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_dhgeqz( char* job, char* compq, char* compz, lapack_int* n,
                    lapack_int* ilo, lapack_int* ihi, double* h,
                    lapack_int* ldh, double* t, lapack_int* ldt, double* alphar,
                    double* alphai, double* beta, double* q, lapack_int* ldq,
                    double* z, lapack_int* ldz, double* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_chgeqz( char* job, char* compq, char* compz, lapack_int* n,
                    lapack_int* ilo, lapack_int* ihi, lapack_complex_float* h,
                    lapack_int* ldh, lapack_complex_float* t, lapack_int* ldt,
                    lapack_complex_float* alpha, lapack_complex_float* beta,
                    lapack_complex_float* q, lapack_int* ldq,
                    lapack_complex_float* z, lapack_int* ldz,
                    lapack_complex_float* work, lapack_int* lwork, float* rwork,
                    lapack_int *info );
void LAPACK_zhgeqz( char* job, char* compq, char* compz, lapack_int* n,
                    lapack_int* ilo, lapack_int* ihi, lapack_complex_double* h,
                    lapack_int* ldh, lapack_complex_double* t, lapack_int* ldt,
                    lapack_complex_double* alpha, lapack_complex_double* beta,
                    lapack_complex_double* q, lapack_int* ldq,
                    lapack_complex_double* z, lapack_int* ldz,
                    lapack_complex_double* work, lapack_int* lwork,
                    double* rwork, lapack_int *info );
void LAPACK_stgevc( char* side, char* howmny, const lapack_logical* select,
                    lapack_int* n, const float* s, lapack_int* lds,
                    const float* p, lapack_int* ldp, float* vl,
                    lapack_int* ldvl, float* vr, lapack_int* ldvr,
                    lapack_int* mm, lapack_int* m, float* work,
                    lapack_int *info );
void LAPACK_dtgevc( char* side, char* howmny, const lapack_logical* select,
                    lapack_int* n, const double* s, lapack_int* lds,
                    const double* p, lapack_int* ldp, double* vl,
                    lapack_int* ldvl, double* vr, lapack_int* ldvr,
                    lapack_int* mm, lapack_int* m, double* work,
                    lapack_int *info );
void LAPACK_ctgevc( char* side, char* howmny, const lapack_logical* select,
                    lapack_int* n, const lapack_complex_float* s,
                    lapack_int* lds, const lapack_complex_float* p,
                    lapack_int* ldp, lapack_complex_float* vl, lapack_int* ldvl,
                    lapack_complex_float* vr, lapack_int* ldvr, lapack_int* mm,
                    lapack_int* m, lapack_complex_float* work, float* rwork,
                    lapack_int *info );
void LAPACK_ztgevc( char* side, char* howmny, const lapack_logical* select,
                    lapack_int* n, const lapack_complex_double* s,
                    lapack_int* lds, const lapack_complex_double* p,
                    lapack_int* ldp, lapack_complex_double* vl,
                    lapack_int* ldvl, lapack_complex_double* vr,
                    lapack_int* ldvr, lapack_int* mm, lapack_int* m,
                    lapack_complex_double* work, double* rwork,
                    lapack_int *info );
void LAPACK_stgexc( lapack_logical* wantq, lapack_logical* wantz, lapack_int* n,
                    float* a, lapack_int* lda, float* b, lapack_int* ldb,
                    float* q, lapack_int* ldq, float* z, lapack_int* ldz,
                    lapack_int* ifst, lapack_int* ilst, float* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_dtgexc( lapack_logical* wantq, lapack_logical* wantz, lapack_int* n,
                    double* a, lapack_int* lda, double* b, lapack_int* ldb,
                    double* q, lapack_int* ldq, double* z, lapack_int* ldz,
                    lapack_int* ifst, lapack_int* ilst, double* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_ctgexc( lapack_logical* wantq, lapack_logical* wantz, lapack_int* n,
                    lapack_complex_float* a, lapack_int* lda,
                    lapack_complex_float* b, lapack_int* ldb,
                    lapack_complex_float* q, lapack_int* ldq,
                    lapack_complex_float* z, lapack_int* ldz, lapack_int* ifst,
                    lapack_int* ilst, lapack_int *info );
void LAPACK_ztgexc( lapack_logical* wantq, lapack_logical* wantz, lapack_int* n,
                    lapack_complex_double* a, lapack_int* lda,
                    lapack_complex_double* b, lapack_int* ldb,
                    lapack_complex_double* q, lapack_int* ldq,
                    lapack_complex_double* z, lapack_int* ldz, lapack_int* ifst,
                    lapack_int* ilst, lapack_int *info );
void LAPACK_stgsen( lapack_int* ijob, lapack_logical* wantq,
                    lapack_logical* wantz, const lapack_logical* select,
                    lapack_int* n, float* a, lapack_int* lda, float* b,
                    lapack_int* ldb, float* alphar, float* alphai, float* beta,
                    float* q, lapack_int* ldq, float* z, lapack_int* ldz,
                    lapack_int* m, float* pl, float* pr, float* dif,
                    float* work, lapack_int* lwork, lapack_int* iwork,
                    lapack_int* liwork, lapack_int *info );
void LAPACK_dtgsen( lapack_int* ijob, lapack_logical* wantq,
                    lapack_logical* wantz, const lapack_logical* select,
                    lapack_int* n, double* a, lapack_int* lda, double* b,
                    lapack_int* ldb, double* alphar, double* alphai,
                    double* beta, double* q, lapack_int* ldq, double* z,
                    lapack_int* ldz, lapack_int* m, double* pl, double* pr,
                    double* dif, double* work, lapack_int* lwork,
                    lapack_int* iwork, lapack_int* liwork, lapack_int *info );
void LAPACK_ctgsen( lapack_int* ijob, lapack_logical* wantq,
                    lapack_logical* wantz, const lapack_logical* select,
                    lapack_int* n, lapack_complex_float* a, lapack_int* lda,
                    lapack_complex_float* b, lapack_int* ldb,
                    lapack_complex_float* alpha, lapack_complex_float* beta,
                    lapack_complex_float* q, lapack_int* ldq,
                    lapack_complex_float* z, lapack_int* ldz, lapack_int* m,
                    float* pl, float* pr, float* dif,
                    lapack_complex_float* work, lapack_int* lwork,
                    lapack_int* iwork, lapack_int* liwork, lapack_int *info );
void LAPACK_ztgsen( lapack_int* ijob, lapack_logical* wantq,
                    lapack_logical* wantz, const lapack_logical* select,
                    lapack_int* n, lapack_complex_double* a, lapack_int* lda,
                    lapack_complex_double* b, lapack_int* ldb,
                    lapack_complex_double* alpha, lapack_complex_double* beta,
                    lapack_complex_double* q, lapack_int* ldq,
                    lapack_complex_double* z, lapack_int* ldz, lapack_int* m,
                    double* pl, double* pr, double* dif,
                    lapack_complex_double* work, lapack_int* lwork,
                    lapack_int* iwork, lapack_int* liwork, lapack_int *info );
void LAPACK_stgsyl( char* trans, lapack_int* ijob, lapack_int* m, lapack_int* n,
                    const float* a, lapack_int* lda, const float* b,
                    lapack_int* ldb, float* c, lapack_int* ldc, const float* d,
                    lapack_int* ldd, const float* e, lapack_int* lde, float* f,
                    lapack_int* ldf, float* scale, float* dif, float* work,
                    lapack_int* lwork, lapack_int* iwork, lapack_int *info );
void LAPACK_dtgsyl( char* trans, lapack_int* ijob, lapack_int* m, lapack_int* n,
                    const double* a, lapack_int* lda, const double* b,
                    lapack_int* ldb, double* c, lapack_int* ldc,
                    const double* d, lapack_int* ldd, const double* e,
                    lapack_int* lde, double* f, lapack_int* ldf, double* scale,
                    double* dif, double* work, lapack_int* lwork,
                    lapack_int* iwork, lapack_int *info );
void LAPACK_ctgsyl( char* trans, lapack_int* ijob, lapack_int* m, lapack_int* n,
                    const lapack_complex_float* a, lapack_int* lda,
                    const lapack_complex_float* b, lapack_int* ldb,
                    lapack_complex_float* c, lapack_int* ldc,
                    const lapack_complex_float* d, lapack_int* ldd,
                    const lapack_complex_float* e, lapack_int* lde,
                    lapack_complex_float* f, lapack_int* ldf, float* scale,
                    float* dif, lapack_complex_float* work, lapack_int* lwork,
                    lapack_int* iwork, lapack_int *info );
void LAPACK_ztgsyl( char* trans, lapack_int* ijob, lapack_int* m, lapack_int* n,
                    const lapack_complex_double* a, lapack_int* lda,
                    const lapack_complex_double* b, lapack_int* ldb,
                    lapack_complex_double* c, lapack_int* ldc,
                    const lapack_complex_double* d, lapack_int* ldd,
                    const lapack_complex_double* e, lapack_int* lde,
                    lapack_complex_double* f, lapack_int* ldf, double* scale,
                    double* dif, lapack_complex_double* work, lapack_int* lwork,
                    lapack_int* iwork, lapack_int *info );
void LAPACK_stgsna( char* job, char* howmny, const lapack_logical* select,
                    lapack_int* n, const float* a, lapack_int* lda,
                    const float* b, lapack_int* ldb, const float* vl,
                    lapack_int* ldvl, const float* vr, lapack_int* ldvr,
                    float* s, float* dif, lapack_int* mm, lapack_int* m,
                    float* work, lapack_int* lwork, lapack_int* iwork,
                    lapack_int *info );
void LAPACK_dtgsna( char* job, char* howmny, const lapack_logical* select,
                    lapack_int* n, const double* a, lapack_int* lda,
                    const double* b, lapack_int* ldb, const double* vl,
                    lapack_int* ldvl, const double* vr, lapack_int* ldvr,
                    double* s, double* dif, lapack_int* mm, lapack_int* m,
                    double* work, lapack_int* lwork, lapack_int* iwork,
                    lapack_int *info );
void LAPACK_ctgsna( char* job, char* howmny, const lapack_logical* select,
                    lapack_int* n, const lapack_complex_float* a,
                    lapack_int* lda, const lapack_complex_float* b,
                    lapack_int* ldb, const lapack_complex_float* vl,
                    lapack_int* ldvl, const lapack_complex_float* vr,
                    lapack_int* ldvr, float* s, float* dif, lapack_int* mm,
                    lapack_int* m, lapack_complex_float* work,
                    lapack_int* lwork, lapack_int* iwork, lapack_int *info );
void LAPACK_ztgsna( char* job, char* howmny, const lapack_logical* select,
                    lapack_int* n, const lapack_complex_double* a,
                    lapack_int* lda, const lapack_complex_double* b,
                    lapack_int* ldb, const lapack_complex_double* vl,
                    lapack_int* ldvl, const lapack_complex_double* vr,
                    lapack_int* ldvr, double* s, double* dif, lapack_int* mm,
                    lapack_int* m, lapack_complex_double* work,
                    lapack_int* lwork, lapack_int* iwork, lapack_int *info );
void LAPACK_sggsvp( char* jobu, char* jobv, char* jobq, lapack_int* m,
                    lapack_int* p, lapack_int* n, float* a, lapack_int* lda,
                    float* b, lapack_int* ldb, float* tola, float* tolb,
                    lapack_int* k, lapack_int* l, float* u, lapack_int* ldu,
                    float* v, lapack_int* ldv, float* q, lapack_int* ldq,
                    lapack_int* iwork, float* tau, float* work,
                    lapack_int *info );
void LAPACK_dggsvp( char* jobu, char* jobv, char* jobq, lapack_int* m,
                    lapack_int* p, lapack_int* n, double* a, lapack_int* lda,
                    double* b, lapack_int* ldb, double* tola, double* tolb,
                    lapack_int* k, lapack_int* l, double* u, lapack_int* ldu,
                    double* v, lapack_int* ldv, double* q, lapack_int* ldq,
                    lapack_int* iwork, double* tau, double* work,
                    lapack_int *info );
void LAPACK_cggsvp( char* jobu, char* jobv, char* jobq, lapack_int* m,
                    lapack_int* p, lapack_int* n, lapack_complex_float* a,
                    lapack_int* lda, lapack_complex_float* b, lapack_int* ldb,
                    float* tola, float* tolb, lapack_int* k, lapack_int* l,
                    lapack_complex_float* u, lapack_int* ldu,
                    lapack_complex_float* v, lapack_int* ldv,
                    lapack_complex_float* q, lapack_int* ldq, lapack_int* iwork,
                    float* rwork, lapack_complex_float* tau,
                    lapack_complex_float* work, lapack_int *info );
void LAPACK_zggsvp( char* jobu, char* jobv, char* jobq, lapack_int* m,
                    lapack_int* p, lapack_int* n, lapack_complex_double* a,
                    lapack_int* lda, lapack_complex_double* b, lapack_int* ldb,
                    double* tola, double* tolb, lapack_int* k, lapack_int* l,
                    lapack_complex_double* u, lapack_int* ldu,
                    lapack_complex_double* v, lapack_int* ldv,
                    lapack_complex_double* q, lapack_int* ldq,
                    lapack_int* iwork, double* rwork,
                    lapack_complex_double* tau, lapack_complex_double* work,
                    lapack_int *info );
void LAPACK_stgsja( char* jobu, char* jobv, char* jobq, lapack_int* m,
                    lapack_int* p, lapack_int* n, lapack_int* k, lapack_int* l,
                    float* a, lapack_int* lda, float* b, lapack_int* ldb,
                    float* tola, float* tolb, float* alpha, float* beta,
                    float* u, lapack_int* ldu, float* v, lapack_int* ldv,
                    float* q, lapack_int* ldq, float* work, lapack_int* ncycle,
                    lapack_int *info );
void LAPACK_dtgsja( char* jobu, char* jobv, char* jobq, lapack_int* m,
                    lapack_int* p, lapack_int* n, lapack_int* k, lapack_int* l,
                    double* a, lapack_int* lda, double* b, lapack_int* ldb,
                    double* tola, double* tolb, double* alpha, double* beta,
                    double* u, lapack_int* ldu, double* v, lapack_int* ldv,
                    double* q, lapack_int* ldq, double* work,
                    lapack_int* ncycle, lapack_int *info );
void LAPACK_ctgsja( char* jobu, char* jobv, char* jobq, lapack_int* m,
                    lapack_int* p, lapack_int* n, lapack_int* k, lapack_int* l,
                    lapack_complex_float* a, lapack_int* lda,
                    lapack_complex_float* b, lapack_int* ldb, float* tola,
                    float* tolb, float* alpha, float* beta,
                    lapack_complex_float* u, lapack_int* ldu,
                    lapack_complex_float* v, lapack_int* ldv,
                    lapack_complex_float* q, lapack_int* ldq,
                    lapack_complex_float* work, lapack_int* ncycle,
                    lapack_int *info );
void LAPACK_ztgsja( char* jobu, char* jobv, char* jobq, lapack_int* m,
                    lapack_int* p, lapack_int* n, lapack_int* k, lapack_int* l,
                    lapack_complex_double* a, lapack_int* lda,
                    lapack_complex_double* b, lapack_int* ldb, double* tola,
                    double* tolb, double* alpha, double* beta,
                    lapack_complex_double* u, lapack_int* ldu,
                    lapack_complex_double* v, lapack_int* ldv,
                    lapack_complex_double* q, lapack_int* ldq,
                    lapack_complex_double* work, lapack_int* ncycle,
                    lapack_int *info );
void LAPACK_sgels( char* trans, lapack_int* m, lapack_int* n, lapack_int* nrhs,
                   float* a, lapack_int* lda, float* b, lapack_int* ldb,
                   float* work, lapack_int* lwork, lapack_int *info );
void LAPACK_dgels( char* trans, lapack_int* m, lapack_int* n, lapack_int* nrhs,
                   double* a, lapack_int* lda, double* b, lapack_int* ldb,
                   double* work, lapack_int* lwork, lapack_int *info );
void LAPACK_cgels( char* trans, lapack_int* m, lapack_int* n, lapack_int* nrhs,
                   lapack_complex_float* a, lapack_int* lda,
                   lapack_complex_float* b, lapack_int* ldb,
                   lapack_complex_float* work, lapack_int* lwork,
                   lapack_int *info );
void LAPACK_zgels( char* trans, lapack_int* m, lapack_int* n, lapack_int* nrhs,
                   lapack_complex_double* a, lapack_int* lda,
                   lapack_complex_double* b, lapack_int* ldb,
                   lapack_complex_double* work, lapack_int* lwork,
                   lapack_int *info );
void LAPACK_sgelsy( lapack_int* m, lapack_int* n, lapack_int* nrhs, float* a,
                    lapack_int* lda, float* b, lapack_int* ldb,
                    lapack_int* jpvt, float* rcond, lapack_int* rank,
                    float* work, lapack_int* lwork, lapack_int *info );
void LAPACK_dgelsy( lapack_int* m, lapack_int* n, lapack_int* nrhs, double* a,
                    lapack_int* lda, double* b, lapack_int* ldb,
                    lapack_int* jpvt, double* rcond, lapack_int* rank,
                    double* work, lapack_int* lwork, lapack_int *info );
void LAPACK_cgelsy( lapack_int* m, lapack_int* n, lapack_int* nrhs,
                    lapack_complex_float* a, lapack_int* lda,
                    lapack_complex_float* b, lapack_int* ldb, lapack_int* jpvt,
                    float* rcond, lapack_int* rank, lapack_complex_float* work,
                    lapack_int* lwork, float* rwork, lapack_int *info );
void LAPACK_zgelsy( lapack_int* m, lapack_int* n, lapack_int* nrhs,
                    lapack_complex_double* a, lapack_int* lda,
                    lapack_complex_double* b, lapack_int* ldb, lapack_int* jpvt,
                    double* rcond, lapack_int* rank,
                    lapack_complex_double* work, lapack_int* lwork,
                    double* rwork, lapack_int *info );
void LAPACK_sgelss( lapack_int* m, lapack_int* n, lapack_int* nrhs, float* a,
                    lapack_int* lda, float* b, lapack_int* ldb, float* s,
                    float* rcond, lapack_int* rank, float* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_dgelss( lapack_int* m, lapack_int* n, lapack_int* nrhs, double* a,
                    lapack_int* lda, double* b, lapack_int* ldb, double* s,
                    double* rcond, lapack_int* rank, double* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_cgelss( lapack_int* m, lapack_int* n, lapack_int* nrhs,
                    lapack_complex_float* a, lapack_int* lda,
                    lapack_complex_float* b, lapack_int* ldb, float* s,
                    float* rcond, lapack_int* rank, lapack_complex_float* work,
                    lapack_int* lwork, float* rwork, lapack_int *info );
void LAPACK_zgelss( lapack_int* m, lapack_int* n, lapack_int* nrhs,
                    lapack_complex_double* a, lapack_int* lda,
                    lapack_complex_double* b, lapack_int* ldb, double* s,
                    double* rcond, lapack_int* rank,
                    lapack_complex_double* work, lapack_int* lwork,
                    double* rwork, lapack_int *info );
void LAPACK_sgelsd( lapack_int* m, lapack_int* n, lapack_int* nrhs, float* a,
                    lapack_int* lda, float* b, lapack_int* ldb, float* s,
                    float* rcond, lapack_int* rank, float* work,
                    lapack_int* lwork, lapack_int* iwork, lapack_int *info );
void LAPACK_dgelsd( lapack_int* m, lapack_int* n, lapack_int* nrhs, double* a,
                    lapack_int* lda, double* b, lapack_int* ldb, double* s,
                    double* rcond, lapack_int* rank, double* work,
                    lapack_int* lwork, lapack_int* iwork, lapack_int *info );
void LAPACK_cgelsd( lapack_int* m, lapack_int* n, lapack_int* nrhs,
                    lapack_complex_float* a, lapack_int* lda,
                    lapack_complex_float* b, lapack_int* ldb, float* s,
                    float* rcond, lapack_int* rank, lapack_complex_float* work,
                    lapack_int* lwork, float* rwork, lapack_int* iwork,
                    lapack_int *info );
void LAPACK_zgelsd( lapack_int* m, lapack_int* n, lapack_int* nrhs,
                    lapack_complex_double* a, lapack_int* lda,
                    lapack_complex_double* b, lapack_int* ldb, double* s,
                    double* rcond, lapack_int* rank,
                    lapack_complex_double* work, lapack_int* lwork,
                    double* rwork, lapack_int* iwork, lapack_int *info );
void LAPACK_sgglse( lapack_int* m, lapack_int* n, lapack_int* p, float* a,
                    lapack_int* lda, float* b, lapack_int* ldb, float* c,
                    float* d, float* x, float* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_dgglse( lapack_int* m, lapack_int* n, lapack_int* p, double* a,
                    lapack_int* lda, double* b, lapack_int* ldb, double* c,
                    double* d, double* x, double* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_cgglse( lapack_int* m, lapack_int* n, lapack_int* p,
                    lapack_complex_float* a, lapack_int* lda,
                    lapack_complex_float* b, lapack_int* ldb,
                    lapack_complex_float* c, lapack_complex_float* d,
                    lapack_complex_float* x, lapack_complex_float* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_zgglse( lapack_int* m, lapack_int* n, lapack_int* p,
                    lapack_complex_double* a, lapack_int* lda,
                    lapack_complex_double* b, lapack_int* ldb,
                    lapack_complex_double* c, lapack_complex_double* d,
                    lapack_complex_double* x, lapack_complex_double* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_sggglm( lapack_int* n, lapack_int* m, lapack_int* p, float* a,
                    lapack_int* lda, float* b, lapack_int* ldb, float* d,
                    float* x, float* y, float* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_dggglm( lapack_int* n, lapack_int* m, lapack_int* p, double* a,
                    lapack_int* lda, double* b, lapack_int* ldb, double* d,
                    double* x, double* y, double* work, lapack_int* lwork,
                    lapack_int *info );
void LAPACK_cggglm( lapack_int* n, lapack_int* m, lapack_int* p,
                    lapack_complex_float* a, lapack_int* lda,
                    lapack_complex_float* b, lapack_int* ldb,
                    lapack_complex_float* d, lapack_complex_float* x,
                    lapack_complex_float* y, lapack_complex_float* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_zggglm( lapack_int* n, lapack_int* m, lapack_int* p,
                    lapack_complex_double* a, lapack_int* lda,
                    lapack_complex_double* b, lapack_int* ldb,
                    lapack_complex_double* d, lapack_complex_double* x,
                    lapack_complex_double* y, lapack_complex_double* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_ssyev( char* jobz, char* uplo, lapack_int* n, float* a,
                   lapack_int* lda, float* w, float* work, lapack_int* lwork,
                   lapack_int *info );
void LAPACK_dsyev( char* jobz, char* uplo, lapack_int* n, double* a,
                   lapack_int* lda, double* w, double* work, lapack_int* lwork,
                   lapack_int *info );
void LAPACK_cheev( char* jobz, char* uplo, lapack_int* n,
                   lapack_complex_float* a, lapack_int* lda, float* w,
                   lapack_complex_float* work, lapack_int* lwork, float* rwork,
                   lapack_int *info );
void LAPACK_zheev( char* jobz, char* uplo, lapack_int* n,
                   lapack_complex_double* a, lapack_int* lda, double* w,
                   lapack_complex_double* work, lapack_int* lwork,
                   double* rwork, lapack_int *info );
void LAPACK_ssyevd( char* jobz, char* uplo, lapack_int* n, float* a,
                    lapack_int* lda, float* w, float* work, lapack_int* lwork,
                    lapack_int* iwork, lapack_int* liwork, lapack_int *info );
void LAPACK_dsyevd( char* jobz, char* uplo, lapack_int* n, double* a,
                    lapack_int* lda, double* w, double* work, lapack_int* lwork,
                    lapack_int* iwork, lapack_int* liwork, lapack_int *info );
void LAPACK_cheevd( char* jobz, char* uplo, lapack_int* n,
                    lapack_complex_float* a, lapack_int* lda, float* w,
                    lapack_complex_float* work, lapack_int* lwork, float* rwork,
                    lapack_int* lrwork, lapack_int* iwork, lapack_int* liwork,
                    lapack_int *info );
void LAPACK_zheevd( char* jobz, char* uplo, lapack_int* n,
                    lapack_complex_double* a, lapack_int* lda, double* w,
                    lapack_complex_double* work, lapack_int* lwork,
                    double* rwork, lapack_int* lrwork, lapack_int* iwork,
                    lapack_int* liwork, lapack_int *info );
void LAPACK_ssyevx( char* jobz, char* range, char* uplo, lapack_int* n,
                    float* a, lapack_int* lda, float* vl, float* vu,
                    lapack_int* il, lapack_int* iu, float* abstol,
                    lapack_int* m, float* w, float* z, lapack_int* ldz,
                    float* work, lapack_int* lwork, lapack_int* iwork,
                    lapack_int* ifail, lapack_int *info );
void LAPACK_dsyevx( char* jobz, char* range, char* uplo, lapack_int* n,
                    double* a, lapack_int* lda, double* vl, double* vu,
                    lapack_int* il, lapack_int* iu, double* abstol,
                    lapack_int* m, double* w, double* z, lapack_int* ldz,
                    double* work, lapack_int* lwork, lapack_int* iwork,
                    lapack_int* ifail, lapack_int *info );
void LAPACK_cheevx( char* jobz, char* range, char* uplo, lapack_int* n,
                    lapack_complex_float* a, lapack_int* lda, float* vl,
                    float* vu, lapack_int* il, lapack_int* iu, float* abstol,
                    lapack_int* m, float* w, lapack_complex_float* z,
                    lapack_int* ldz, lapack_complex_float* work,
                    lapack_int* lwork, float* rwork, lapack_int* iwork,
                    lapack_int* ifail, lapack_int *info );
void LAPACK_zheevx( char* jobz, char* range, char* uplo, lapack_int* n,
                    lapack_complex_double* a, lapack_int* lda, double* vl,
                    double* vu, lapack_int* il, lapack_int* iu, double* abstol,
                    lapack_int* m, double* w, lapack_complex_double* z,
                    lapack_int* ldz, lapack_complex_double* work,
                    lapack_int* lwork, double* rwork, lapack_int* iwork,
                    lapack_int* ifail, lapack_int *info );
void LAPACK_ssyevr( char* jobz, char* range, char* uplo, lapack_int* n,
                    float* a, lapack_int* lda, float* vl, float* vu,
                    lapack_int* il, lapack_int* iu, float* abstol,
                    lapack_int* m, float* w, float* z, lapack_int* ldz,
                    lapack_int* isuppz, float* work, lapack_int* lwork,
                    lapack_int* iwork, lapack_int* liwork, lapack_int *info );
void LAPACK_dsyevr( char* jobz, char* range, char* uplo, lapack_int* n,
                    double* a, lapack_int* lda, double* vl, double* vu,
                    lapack_int* il, lapack_int* iu, double* abstol,
                    lapack_int* m, double* w, double* z, lapack_int* ldz,
                    lapack_int* isuppz, double* work, lapack_int* lwork,
                    lapack_int* iwork, lapack_int* liwork, lapack_int *info );
void LAPACK_cheevr( char* jobz, char* range, char* uplo, lapack_int* n,
                    lapack_complex_float* a, lapack_int* lda, float* vl,
                    float* vu, lapack_int* il, lapack_int* iu, float* abstol,
                    lapack_int* m, float* w, lapack_complex_float* z,
                    lapack_int* ldz, lapack_int* isuppz,
                    lapack_complex_float* work, lapack_int* lwork, float* rwork,
                    lapack_int* lrwork, lapack_int* iwork, lapack_int* liwork,
                    lapack_int *info );
void LAPACK_zheevr( char* jobz, char* range, char* uplo, lapack_int* n,
                    lapack_complex_double* a, lapack_int* lda, double* vl,
                    double* vu, lapack_int* il, lapack_int* iu, double* abstol,
                    lapack_int* m, double* w, lapack_complex_double* z,
                    lapack_int* ldz, lapack_int* isuppz,
                    lapack_complex_double* work, lapack_int* lwork,
                    double* rwork, lapack_int* lrwork, lapack_int* iwork,
                    lapack_int* liwork, lapack_int *info );
void LAPACK_sspev( char* jobz, char* uplo, lapack_int* n, float* ap, float* w,
                   float* z, lapack_int* ldz, float* work, lapack_int *info );
void LAPACK_dspev( char* jobz, char* uplo, lapack_int* n, double* ap, double* w,
                   double* z, lapack_int* ldz, double* work, lapack_int *info );
void LAPACK_chpev( char* jobz, char* uplo, lapack_int* n,
                   lapack_complex_float* ap, float* w, lapack_complex_float* z,
                   lapack_int* ldz, lapack_complex_float* work, float* rwork,
                   lapack_int *info );
void LAPACK_zhpev( char* jobz, char* uplo, lapack_int* n,
                   lapack_complex_double* ap, double* w,
                   lapack_complex_double* z, lapack_int* ldz,
                   lapack_complex_double* work, double* rwork,
                   lapack_int *info );
void LAPACK_sspevd( char* jobz, char* uplo, lapack_int* n, float* ap, float* w,
                    float* z, lapack_int* ldz, float* work, lapack_int* lwork,
                    lapack_int* iwork, lapack_int* liwork, lapack_int *info );
void LAPACK_dspevd( char* jobz, char* uplo, lapack_int* n, double* ap,
                    double* w, double* z, lapack_int* ldz, double* work,
                    lapack_int* lwork, lapack_int* iwork, lapack_int* liwork,
                    lapack_int *info );
void LAPACK_chpevd( char* jobz, char* uplo, lapack_int* n,
                    lapack_complex_float* ap, float* w, lapack_complex_float* z,
                    lapack_int* ldz, lapack_complex_float* work,
                    lapack_int* lwork, float* rwork, lapack_int* lrwork,
                    lapack_int* iwork, lapack_int* liwork, lapack_int *info );
void LAPACK_zhpevd( char* jobz, char* uplo, lapack_int* n,
                    lapack_complex_double* ap, double* w,
                    lapack_complex_double* z, lapack_int* ldz,
                    lapack_complex_double* work, lapack_int* lwork,
                    double* rwork, lapack_int* lrwork, lapack_int* iwork,
                    lapack_int* liwork, lapack_int *info );
void LAPACK_sspevx( char* jobz, char* range, char* uplo, lapack_int* n,
                    float* ap, float* vl, float* vu, lapack_int* il,
                    lapack_int* iu, float* abstol, lapack_int* m, float* w,
                    float* z, lapack_int* ldz, float* work, lapack_int* iwork,
                    lapack_int* ifail, lapack_int *info );
void LAPACK_dspevx( char* jobz, char* range, char* uplo, lapack_int* n,
                    double* ap, double* vl, double* vu, lapack_int* il,
                    lapack_int* iu, double* abstol, lapack_int* m, double* w,
                    double* z, lapack_int* ldz, double* work, lapack_int* iwork,
                    lapack_int* ifail, lapack_int *info );
void LAPACK_chpevx( char* jobz, char* range, char* uplo, lapack_int* n,
                    lapack_complex_float* ap, float* vl, float* vu,
                    lapack_int* il, lapack_int* iu, float* abstol,
                    lapack_int* m, float* w, lapack_complex_float* z,
                    lapack_int* ldz, lapack_complex_float* work, float* rwork,
                    lapack_int* iwork, lapack_int* ifail, lapack_int *info );
void LAPACK_zhpevx( char* jobz, char* range, char* uplo, lapack_int* n,
                    lapack_complex_double* ap, double* vl, double* vu,
                    lapack_int* il, lapack_int* iu, double* abstol,
                    lapack_int* m, double* w, lapack_complex_double* z,
                    lapack_int* ldz, lapack_complex_double* work, double* rwork,
                    lapack_int* iwork, lapack_int* ifail, lapack_int *info );
void LAPACK_ssbev( char* jobz, char* uplo, lapack_int* n, lapack_int* kd,
                   float* ab, lapack_int* ldab, float* w, float* z,
                   lapack_int* ldz, float* work, lapack_int *info );
void LAPACK_dsbev( char* jobz, char* uplo, lapack_int* n, lapack_int* kd,
                   double* ab, lapack_int* ldab, double* w, double* z,
                   lapack_int* ldz, double* work, lapack_int *info );
void LAPACK_chbev( char* jobz, char* uplo, lapack_int* n, lapack_int* kd,
                   lapack_complex_float* ab, lapack_int* ldab, float* w,
                   lapack_complex_float* z, lapack_int* ldz,
                   lapack_complex_float* work, float* rwork, lapack_int *info );
void LAPACK_zhbev( char* jobz, char* uplo, lapack_int* n, lapack_int* kd,
                   lapack_complex_double* ab, lapack_int* ldab, double* w,
                   lapack_complex_double* z, lapack_int* ldz,
                   lapack_complex_double* work, double* rwork,
                   lapack_int *info );
void LAPACK_ssbevd( char* jobz, char* uplo, lapack_int* n, lapack_int* kd,
                    float* ab, lapack_int* ldab, float* w, float* z,
                    lapack_int* ldz, float* work, lapack_int* lwork,
                    lapack_int* iwork, lapack_int* liwork, lapack_int *info );
void LAPACK_dsbevd( char* jobz, char* uplo, lapack_int* n, lapack_int* kd,
                    double* ab, lapack_int* ldab, double* w, double* z,
                    lapack_int* ldz, double* work, lapack_int* lwork,
                    lapack_int* iwork, lapack_int* liwork, lapack_int *info );
void LAPACK_chbevd( char* jobz, char* uplo, lapack_int* n, lapack_int* kd,
                    lapack_complex_float* ab, lapack_int* ldab, float* w,
                    lapack_complex_float* z, lapack_int* ldz,
                    lapack_complex_float* work, lapack_int* lwork, float* rwork,
                    lapack_int* lrwork, lapack_int* iwork, lapack_int* liwork,
                    lapack_int *info );
void LAPACK_zhbevd( char* jobz, char* uplo, lapack_int* n, lapack_int* kd,
                    lapack_complex_double* ab, lapack_int* ldab, double* w,
                    lapack_complex_double* z, lapack_int* ldz,
                    lapack_complex_double* work, lapack_int* lwork,
                    double* rwork, lapack_int* lrwork, lapack_int* iwork,
                    lapack_int* liwork, lapack_int *info );
void LAPACK_ssbevx( char* jobz, char* range, char* uplo, lapack_int* n,
                    lapack_int* kd, float* ab, lapack_int* ldab, float* q,
                    lapack_int* ldq, float* vl, float* vu, lapack_int* il,
                    lapack_int* iu, float* abstol, lapack_int* m, float* w,
                    float* z, lapack_int* ldz, float* work, lapack_int* iwork,
                    lapack_int* ifail, lapack_int *info );
void LAPACK_dsbevx( char* jobz, char* range, char* uplo, lapack_int* n,
                    lapack_int* kd, double* ab, lapack_int* ldab, double* q,
                    lapack_int* ldq, double* vl, double* vu, lapack_int* il,
                    lapack_int* iu, double* abstol, lapack_int* m, double* w,
                    double* z, lapack_int* ldz, double* work, lapack_int* iwork,
                    lapack_int* ifail, lapack_int *info );
void LAPACK_chbevx( char* jobz, char* range, char* uplo, lapack_int* n,
                    lapack_int* kd, lapack_complex_float* ab, lapack_int* ldab,
                    lapack_complex_float* q, lapack_int* ldq, float* vl,
                    float* vu, lapack_int* il, lapack_int* iu, float* abstol,
                    lapack_int* m, float* w, lapack_complex_float* z,
                    lapack_int* ldz, lapack_complex_float* work, float* rwork,
                    lapack_int* iwork, lapack_int* ifail, lapack_int *info );
void LAPACK_zhbevx( char* jobz, char* range, char* uplo, lapack_int* n,
                    lapack_int* kd, lapack_complex_double* ab, lapack_int* ldab,
                    lapack_complex_double* q, lapack_int* ldq, double* vl,
                    double* vu, lapack_int* il, lapack_int* iu, double* abstol,
                    lapack_int* m, double* w, lapack_complex_double* z,
                    lapack_int* ldz, lapack_complex_double* work, double* rwork,
                    lapack_int* iwork, lapack_int* ifail, lapack_int *info );
void LAPACK_sstev( char* jobz, lapack_int* n, float* d, float* e, float* z,
                   lapack_int* ldz, float* work, lapack_int *info );
void LAPACK_dstev( char* jobz, lapack_int* n, double* d, double* e, double* z,
                   lapack_int* ldz, double* work, lapack_int *info );
void LAPACK_sstevd( char* jobz, lapack_int* n, float* d, float* e, float* z,
                    lapack_int* ldz, float* work, lapack_int* lwork,
                    lapack_int* iwork, lapack_int* liwork, lapack_int *info );
void LAPACK_dstevd( char* jobz, lapack_int* n, double* d, double* e, double* z,
                    lapack_int* ldz, double* work, lapack_int* lwork,
                    lapack_int* iwork, lapack_int* liwork, lapack_int *info );
void LAPACK_sstevx( char* jobz, char* range, lapack_int* n, float* d, float* e,
                    float* vl, float* vu, lapack_int* il, lapack_int* iu,
                    float* abstol, lapack_int* m, float* w, float* z,
                    lapack_int* ldz, float* work, lapack_int* iwork,
                    lapack_int* ifail, lapack_int *info );
void LAPACK_dstevx( char* jobz, char* range, lapack_int* n, double* d,
                    double* e, double* vl, double* vu, lapack_int* il,
                    lapack_int* iu, double* abstol, lapack_int* m, double* w,
                    double* z, lapack_int* ldz, double* work, lapack_int* iwork,
                    lapack_int* ifail, lapack_int *info );
void LAPACK_sstevr( char* jobz, char* range, lapack_int* n, float* d, float* e,
                    float* vl, float* vu, lapack_int* il, lapack_int* iu,
                    float* abstol, lapack_int* m, float* w, float* z,
                    lapack_int* ldz, lapack_int* isuppz, float* work,
                    lapack_int* lwork, lapack_int* iwork, lapack_int* liwork,
                    lapack_int *info );
void LAPACK_dstevr( char* jobz, char* range, lapack_int* n, double* d,
                    double* e, double* vl, double* vu, lapack_int* il,
                    lapack_int* iu, double* abstol, lapack_int* m, double* w,
                    double* z, lapack_int* ldz, lapack_int* isuppz,
                    double* work, lapack_int* lwork, lapack_int* iwork,
                    lapack_int* liwork, lapack_int *info );
void LAPACK_sgees( char* jobvs, char* sort, LAPACK_S_SELECT2 select,
                   lapack_int* n, float* a, lapack_int* lda, lapack_int* sdim,
                   float* wr, float* wi, float* vs, lapack_int* ldvs,
                   float* work, lapack_int* lwork, lapack_logical* bwork,
                   lapack_int *info );
void LAPACK_dgees( char* jobvs, char* sort, LAPACK_D_SELECT2 select,
                   lapack_int* n, double* a, lapack_int* lda, lapack_int* sdim,
                   double* wr, double* wi, double* vs, lapack_int* ldvs,
                   double* work, lapack_int* lwork, lapack_logical* bwork,
                   lapack_int *info );
void LAPACK_cgees( char* jobvs, char* sort, LAPACK_C_SELECT1 select,
                   lapack_int* n, lapack_complex_float* a, lapack_int* lda,
                   lapack_int* sdim, lapack_complex_float* w,
                   lapack_complex_float* vs, lapack_int* ldvs,
                   lapack_complex_float* work, lapack_int* lwork, float* rwork,
                   lapack_logical* bwork, lapack_int *info );
void LAPACK_zgees( char* jobvs, char* sort, LAPACK_Z_SELECT1 select,
                   lapack_int* n, lapack_complex_double* a, lapack_int* lda,
                   lapack_int* sdim, lapack_complex_double* w,
                   lapack_complex_double* vs, lapack_int* ldvs,
                   lapack_complex_double* work, lapack_int* lwork,
                   double* rwork, lapack_logical* bwork, lapack_int *info );
void LAPACK_sgeesx( char* jobvs, char* sort, LAPACK_S_SELECT2 select,
                    char* sense, lapack_int* n, float* a, lapack_int* lda,
                    lapack_int* sdim, float* wr, float* wi, float* vs,
                    lapack_int* ldvs, float* rconde, float* rcondv, float* work,
                    lapack_int* lwork, lapack_int* iwork, lapack_int* liwork,
                    lapack_logical* bwork, lapack_int *info );
void LAPACK_dgeesx( char* jobvs, char* sort, LAPACK_D_SELECT2 select,
                    char* sense, lapack_int* n, double* a, lapack_int* lda,
                    lapack_int* sdim, double* wr, double* wi, double* vs,
                    lapack_int* ldvs, double* rconde, double* rcondv,
                    double* work, lapack_int* lwork, lapack_int* iwork,
                    lapack_int* liwork, lapack_logical* bwork,
                    lapack_int *info );
void LAPACK_cgeesx( char* jobvs, char* sort, LAPACK_C_SELECT1 select,
                    char* sense, lapack_int* n, lapack_complex_float* a,
                    lapack_int* lda, lapack_int* sdim, lapack_complex_float* w,
                    lapack_complex_float* vs, lapack_int* ldvs, float* rconde,
                    float* rcondv, lapack_complex_float* work,
                    lapack_int* lwork, float* rwork, lapack_logical* bwork,
                    lapack_int *info );
void LAPACK_zgeesx( char* jobvs, char* sort, LAPACK_Z_SELECT1 select,
                    char* sense, lapack_int* n, lapack_complex_double* a,
                    lapack_int* lda, lapack_int* sdim, lapack_complex_double* w,
                    lapack_complex_double* vs, lapack_int* ldvs, double* rconde,
                    double* rcondv, lapack_complex_double* work,
                    lapack_int* lwork, double* rwork, lapack_logical* bwork,
                    lapack_int *info );
void LAPACK_sgeev( char* jobvl, char* jobvr, lapack_int* n, float* a,
                   lapack_int* lda, float* wr, float* wi, float* vl,
                   lapack_int* ldvl, float* vr, lapack_int* ldvr, float* work,
                   lapack_int* lwork, lapack_int *info );
void LAPACK_dgeev( char* jobvl, char* jobvr, lapack_int* n, double* a,
                   lapack_int* lda, double* wr, double* wi, double* vl,
                   lapack_int* ldvl, double* vr, lapack_int* ldvr, double* work,
                   lapack_int* lwork, lapack_int *info );
void LAPACK_cgeev( char* jobvl, char* jobvr, lapack_int* n,
                   lapack_complex_float* a, lapack_int* lda,
                   lapack_complex_float* w, lapack_complex_float* vl,
                   lapack_int* ldvl, lapack_complex_float* vr, lapack_int* ldvr,
                   lapack_complex_float* work, lapack_int* lwork, float* rwork,
                   lapack_int *info );
void LAPACK_zgeev( char* jobvl, char* jobvr, lapack_int* n,
                   lapack_complex_double* a, lapack_int* lda,
                   lapack_complex_double* w, lapack_complex_double* vl,
                   lapack_int* ldvl, lapack_complex_double* vr,
                   lapack_int* ldvr, lapack_complex_double* work,
                   lapack_int* lwork, double* rwork, lapack_int *info );
void LAPACK_sgeevx( char* balanc, char* jobvl, char* jobvr, char* sense,
                    lapack_int* n, float* a, lapack_int* lda, float* wr,
                    float* wi, float* vl, lapack_int* ldvl, float* vr,
                    lapack_int* ldvr, lapack_int* ilo, lapack_int* ihi,
                    float* scale, float* abnrm, float* rconde, float* rcondv,
                    float* work, lapack_int* lwork, lapack_int* iwork,
                    lapack_int *info );
void LAPACK_dgeevx( char* balanc, char* jobvl, char* jobvr, char* sense,
                    lapack_int* n, double* a, lapack_int* lda, double* wr,
                    double* wi, double* vl, lapack_int* ldvl, double* vr,
                    lapack_int* ldvr, lapack_int* ilo, lapack_int* ihi,
                    double* scale, double* abnrm, double* rconde,
                    double* rcondv, double* work, lapack_int* lwork,
                    lapack_int* iwork, lapack_int *info );
void LAPACK_cgeevx( char* balanc, char* jobvl, char* jobvr, char* sense,
                    lapack_int* n, lapack_complex_float* a, lapack_int* lda,
                    lapack_complex_float* w, lapack_complex_float* vl,
                    lapack_int* ldvl, lapack_complex_float* vr,
                    lapack_int* ldvr, lapack_int* ilo, lapack_int* ihi,
                    float* scale, float* abnrm, float* rconde, float* rcondv,
                    lapack_complex_float* work, lapack_int* lwork, float* rwork,
                    lapack_int *info );
void LAPACK_zgeevx( char* balanc, char* jobvl, char* jobvr, char* sense,
                    lapack_int* n, lapack_complex_double* a, lapack_int* lda,
                    lapack_complex_double* w, lapack_complex_double* vl,
                    lapack_int* ldvl, lapack_complex_double* vr,
                    lapack_int* ldvr, lapack_int* ilo, lapack_int* ihi,
                    double* scale, double* abnrm, double* rconde,
                    double* rcondv, lapack_complex_double* work,
                    lapack_int* lwork, double* rwork, lapack_int *info );
void LAPACK_sgesvd( char* jobu, char* jobvt, lapack_int* m, lapack_int* n,
                    float* a, lapack_int* lda, float* s, float* u,
                    lapack_int* ldu, float* vt, lapack_int* ldvt, float* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_dgesvd( char* jobu, char* jobvt, lapack_int* m, lapack_int* n,
                    double* a, lapack_int* lda, double* s, double* u,
                    lapack_int* ldu, double* vt, lapack_int* ldvt, double* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_cgesvd( char* jobu, char* jobvt, lapack_int* m, lapack_int* n,
                    lapack_complex_float* a, lapack_int* lda, float* s,
                    lapack_complex_float* u, lapack_int* ldu,
                    lapack_complex_float* vt, lapack_int* ldvt,
                    lapack_complex_float* work, lapack_int* lwork, float* rwork,
                    lapack_int *info );
void LAPACK_zgesvd( char* jobu, char* jobvt, lapack_int* m, lapack_int* n,
                    lapack_complex_double* a, lapack_int* lda, double* s,
                    lapack_complex_double* u, lapack_int* ldu,
                    lapack_complex_double* vt, lapack_int* ldvt,
                    lapack_complex_double* work, lapack_int* lwork,
                    double* rwork, lapack_int *info );
void LAPACK_sgesdd( char* jobz, lapack_int* m, lapack_int* n, float* a,
                    lapack_int* lda, float* s, float* u, lapack_int* ldu,
                    float* vt, lapack_int* ldvt, float* work, lapack_int* lwork,
                    lapack_int* iwork, lapack_int *info );
void LAPACK_dgesdd( char* jobz, lapack_int* m, lapack_int* n, double* a,
                    lapack_int* lda, double* s, double* u, lapack_int* ldu,
                    double* vt, lapack_int* ldvt, double* work,
                    lapack_int* lwork, lapack_int* iwork, lapack_int *info );
void LAPACK_cgesdd( char* jobz, lapack_int* m, lapack_int* n,
                    lapack_complex_float* a, lapack_int* lda, float* s,
                    lapack_complex_float* u, lapack_int* ldu,
                    lapack_complex_float* vt, lapack_int* ldvt,
                    lapack_complex_float* work, lapack_int* lwork, float* rwork,
                    lapack_int* iwork, lapack_int *info );
void LAPACK_zgesdd( char* jobz, lapack_int* m, lapack_int* n,
                    lapack_complex_double* a, lapack_int* lda, double* s,
                    lapack_complex_double* u, lapack_int* ldu,
                    lapack_complex_double* vt, lapack_int* ldvt,
                    lapack_complex_double* work, lapack_int* lwork,
                    double* rwork, lapack_int* iwork, lapack_int *info );
void LAPACK_dgejsv( char* joba, char* jobu, char* jobv, char* jobr, char* jobt,
                    char* jobp, lapack_int* m, lapack_int* n, double* a,
                    lapack_int* lda, double* sva, double* u, lapack_int* ldu,
                    double* v, lapack_int* ldv, double* work, lapack_int* lwork,
                    lapack_int* iwork, lapack_int *info );
void LAPACK_sgejsv( char* joba, char* jobu, char* jobv, char* jobr, char* jobt,
                    char* jobp, lapack_int* m, lapack_int* n, float* a,
                    lapack_int* lda, float* sva, float* u, lapack_int* ldu,
                    float* v, lapack_int* ldv, float* work, lapack_int* lwork,
                    lapack_int* iwork, lapack_int *info );
void LAPACK_dgesvj( char* joba, char* jobu, char* jobv, lapack_int* m,
                    lapack_int* n, double* a, lapack_int* lda, double* sva,
                    lapack_int* mv, double* v, lapack_int* ldv, double* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_sgesvj( char* joba, char* jobu, char* jobv, lapack_int* m,
                    lapack_int* n, float* a, lapack_int* lda, float* sva,
                    lapack_int* mv, float* v, lapack_int* ldv, float* work,
                    lapack_int* lwork, lapack_int *info );
void LAPACK_sggsvd( char* jobu, char* jobv, char* jobq, lapack_int* m,
                    lapack_int* n, lapack_int* p, lapack_int* k, lapack_int* l,
                    float* a, lapack_int* lda, float* b, lapack_int* ldb,
                    float* alpha, float* beta, float* u, lapack_int* ldu,
                    float* v, lapack_int* ldv, float* q, lapack_int* ldq,
                    float* work, lapack_int* iwork, lapack_int *info );
void LAPACK_dggsvd( char* jobu, char* jobv, char* jobq, lapack_int* m,
                    lapack_int* n, lapack_int* p, lapack_int* k, lapack_int* l,
                    double* a, lapack_int* lda, double* b, lapack_int* ldb,
                    double* alpha, double* beta, double* u, lapack_int* ldu,
                    double* v, lapack_int* ldv, double* q, lapack_int* ldq,
                    double* work, lapack_int* iwork, lapack_int *info );
void LAPACK_cggsvd( char* jobu, char* jobv, char* jobq, lapack_int* m,
                    lapack_int* n, lapack_int* p, lapack_int* k, lapack_int* l,
                    lapack_complex_float* a, lapack_int* lda,
                    lapack_complex_float* b, lapack_int* ldb, float* alpha,
                    float* beta, lapack_complex_float* u, lapack_int* ldu,
                    lapack_complex_float* v, lapack_int* ldv,
                    lapack_complex_float* q, lapack_int* ldq,
                    lapack_complex_float* work, float* rwork, lapack_int* iwork,
                    lapack_int *info );
void LAPACK_zggsvd( char* jobu, char* jobv, char* jobq, lapack_int* m,
                    lapack_int* n, lapack_int* p, lapack_int* k, lapack_int* l,
                    lapack_complex_double* a, lapack_int* lda,
                    lapack_complex_double* b, lapack_int* ldb, double* alpha,
                    double* beta, lapack_complex_double* u, lapack_int* ldu,
                    lapack_complex_double* v, lapack_int* ldv,
                    lapack_complex_double* q, lapack_int* ldq,
                    lapack_complex_double* work, double* rwork,
                    lapack_int* iwork, lapack_int *info );
void LAPACK_ssygv( lapack_int* itype, char* jobz, char* uplo, lapack_int* n,
                   float* a, lapack_int* lda, float* b, lapack_int* ldb,
                   float* w, float* work, lapack_int* lwork, lapack_int *info );
void LAPACK_dsygv( lapack_int* itype, char* jobz, char* uplo, lapack_int* n,
                   double* a, lapack_int* lda, double* b, lapack_int* ldb,
                   double* w, double* work, lapack_int* lwork,
                   lapack_int *info );
void LAPACK_chegv( lapack_int* itype, char* jobz, char* uplo, lapack_int* n,
                   lapack_complex_float* a, lapack_int* lda,
                   lapack_complex_float* b, lapack_int* ldb, float* w,
                   lapack_complex_float* work, lapack_int* lwork, float* rwork,
                   lapack_int *info );
void LAPACK_zhegv( lapack_int* itype, char* jobz, char* uplo, lapack_int* n,
                   lapack_complex_double* a, lapack_int* lda,
                   lapack_complex_double* b, lapack_int* ldb, double* w,
                   lapack_complex_double* work, lapack_int* lwork,
                   double* rwork, lapack_int *info );
void LAPACK_ssygvd( lapack_int* itype, char* jobz, char* uplo, lapack_int* n,
                    float* a, lapack_int* lda, float* b, lapack_int* ldb,
                    float* w, float* work, lapack_int* lwork, lapack_int* iwork,
                    lapack_int* liwork, lapack_int *info );
void LAPACK_dsygvd( lapack_int* itype, char* jobz, char* uplo, lapack_int* n,
                    double* a, lapack_int* lda, double* b, lapack_int* ldb,
                    double* w, double* work, lapack_int* lwork,
                    lapack_int* iwork, lapack_int* liwork, lapack_int *info );
void LAPACK_chegvd( lapack_int* itype, char* jobz, char* uplo, lapack_int* n,
                    lapack_complex_float* a, lapack_int* lda,
                    lapack_complex_float* b, lapack_int* ldb, float* w,
                    lapack_complex_float* work, lapack_int* lwork, float* rwork,
                    lapack_int* lrwork, lapack_int* iwork, lapack_int* liwork,
                    lapack_int *info );
void LAPACK_zhegvd( lapack_int* itype, char* jobz, char* uplo, lapack_int* n,
                    lapack_complex_double* a, lapack_int* lda,
                    lapack_complex_double* b, lapack_int* ldb, double* w,
                    lapack_complex_double* work, lapack_int* lwork,
                    double* rwork, lapack_int* lrwork, lapack_int* iwork,
                    lapack_int* liwork, lapack_int *info );
void LAPACK_ssygvx( lapack_int* itype, char* jobz, char* range, char* uplo,
                    lapack_int* n, float* a, lapack_int* lda, float* b,
                    lapack_int* ldb, float* vl, float* vu, lapack_int* il,
                    lapack_int* iu, float* abstol, lapack_int* m, float* w,
                    float* z, lapack_int* ldz, float* work, lapack_int* lwork,
                    lapack_int* iwork, lapack_int* ifail, lapack_int *info );
void LAPACK_dsygvx( lapack_int* itype, char* jobz, char* range, char* uplo,
                    lapack_int* n, double* a, lapack_int* lda, double* b,
                    lapack_int* ldb, double* vl, double* vu, lapack_int* il,
                    lapack_int* iu, double* abstol, lapack_int* m, double* w,
                    double* z, lapack_int* ldz, double* work, lapack_int* lwork,
                    lapack_int* iwork, lapack_int* ifail, lapack_int *info );
void LAPACK_chegvx( lapack_int* itype, char* jobz, char* range, char* uplo,
                    lapack_int* n, lapack_complex_float* a, lapack_int* lda,
                    lapack_complex_float* b, lapack_int* ldb, float* vl,
                    float* vu, lapack_int* il, lapack_int* iu, float* abstol,
                    lapack_int* m, float* w, lapack_complex_float* z,
                    lapack_int* ldz, lapack_complex_float* work,
                    lapack_int* lwork, float* rwork, lapack_int* iwork,
                    lapack_int* ifail, lapack_int *info );
void LAPACK_zhegvx( lapack_int* itype, char* jobz, char* range, char* uplo,
                    lapack_int* n, lapack_complex_double* a, lapack_int* lda,
                    lapack_complex_double* b, lapack_int* ldb, double* vl,
                    double* vu, lapack_int* il, lapack_int* iu, double* abstol,
                    lapack_int* m, double* w, lapack_complex_double* z,
                    lapack_int* ldz, lapack_complex_double* work,
                    lapack_int* lwork, double* rwork, lapack_int* iwork,
                    lapack_int* ifail, lapack_int *info );
void LAPACK_sspgv( lapack_int* itype, char* jobz, char* uplo, lapack_int* n,
                   float* ap, float* bp, float* w, float* z, lapack_int* ldz,
                   float* work, lapack_int *info );
void LAPACK_dspgv( lapack_int* itype, char* jobz, char* uplo, lapack_int* n,
                   double* ap, double* bp, double* w, double* z,
                   lapack_int* ldz, double* work, lapack_int *info );
void LAPACK_chpgv( lapack_int* itype, char* jobz, char* uplo, lapack_int* n,
                   lapack_complex_float* ap, lapack_complex_float* bp, float* w,
                   lapack_complex_float* z, lapack_int* ldz,
                   lapack_complex_float* work, float* rwork, lapack_int *info );
void LAPACK_zhpgv( lapack_int* itype, char* jobz, char* uplo, lapack_int* n,
                   lapack_complex_double* ap, lapack_complex_double* bp,
                   double* w, lapack_complex_double* z, lapack_int* ldz,
                   lapack_complex_double* work, double* rwork,
                   lapack_int *info );
void LAPACK_sspgvd( lapack_int* itype, char* jobz, char* uplo, lapack_int* n,
                    float* ap, float* bp, float* w, float* z, lapack_int* ldz,
                    float* work, lapack_int* lwork, lapack_int* iwork,
                    lapack_int* liwork, lapack_int *info );
void LAPACK_dspgvd( lapack_int* itype, char* jobz, char* uplo, lapack_int* n,
                    double* ap, double* bp, double* w, double* z,
                    lapack_int* ldz, double* work, lapack_int* lwork,
                    lapack_int* iwork, lapack_int* liwork, lapack_int *info );
void LAPACK_chpgvd( lapack_int* itype, char* jobz, char* uplo, lapack_int* n,
                    lapack_complex_float* ap, lapack_complex_float* bp,
                    float* w, lapack_complex_float* z, lapack_int* ldz,
                    lapack_complex_float* work, lapack_int* lwork, float* rwork,
                    lapack_int* lrwork, lapack_int* iwork, lapack_int* liwork,
                    lapack_int *info );
void LAPACK_zhpgvd( lapack_int* itype, char* jobz, char* uplo, lapack_int* n,
                    lapack_complex_double* ap, lapack_complex_double* bp,
                    double* w, lapack_complex_double* z, lapack_int* ldz,
                    lapack_complex_double* work, lapack_int* lwork,
                    double* rwork, lapack_int* lrwork, lapack_int* iwork,
                    lapack_int* liwork, lapack_int *info );
void LAPACK_sspgvx( lapack_int* itype, char* jobz, char* range, char* uplo,
                    lapack_int* n, float* ap, float* bp, float* vl, float* vu,
                    lapack_int* il, lapack_int* iu, float* abstol,
                    lapack_int* m, float* w, float* z, lapack_int* ldz,
                    float* work, lapack_int* iwork, lapack_int* ifail,
                    lapack_int *info );
void LAPACK_dspgvx( lapack_int* itype, char* jobz, char* range, char* uplo,
                    lapack_int* n, double* ap, double* bp, double* vl,
                    double* vu, lapack_int* il, lapack_int* iu, double* abstol,
                    lapack_int* m, double* w, double* z, lapack_int* ldz,
                    double* work, lapack_int* iwork, lapack_int* ifail,
                    lapack_int *info );
void LAPACK_chpgvx( lapack_int* itype, char* jobz, char* range, char* uplo,
                    lapack_int* n, lapack_complex_float* ap,
                    lapack_complex_float* bp, float* vl, float* vu,
                    lapack_int* il, lapack_int* iu, float* abstol,
                    lapack_int* m, float* w, lapack_complex_float* z,
                    lapack_int* ldz, lapack_complex_float* work, float* rwork,
                    lapack_int* iwork, lapack_int* ifail, lapack_int *info );
void LAPACK_zhpgvx( lapack_int* itype, char* jobz, char* range, char* uplo,
                    lapack_int* n, lapack_complex_double* ap,
                    lapack_complex_double* bp, double* vl, double* vu,
                    lapack_int* il, lapack_int* iu, double* abstol,
                    lapack_int* m, double* w, lapack_complex_double* z,
                    lapack_int* ldz, lapack_complex_double* work, double* rwork,
                    lapack_int* iwork, lapack_int* ifail, lapack_int *info );
void LAPACK_ssbgv( char* jobz, char* uplo, lapack_int* n, lapack_int* ka,
                   lapack_int* kb, float* ab, lapack_int* ldab, float* bb,
                   lapack_int* ldbb, float* w, float* z, lapack_int* ldz,
                   float* work, lapack_int *info );
void LAPACK_dsbgv( char* jobz, char* uplo, lapack_int* n, lapack_int* ka,
                   lapack_int* kb, double* ab, lapack_int* ldab, double* bb,
                   lapack_int* ldbb, double* w, double* z, lapack_int* ldz,
                   double* work, lapack_int *info );
void LAPACK_chbgv( char* jobz, char* uplo, lapack_int* n, lapack_int* ka,
                   lapack_int* kb, lapack_complex_float* ab, lapack_int* ldab,
                   lapack_complex_float* bb, lapack_int* ldbb, float* w,
                   lapack_complex_float* z, lapack_int* ldz,
                   lapack_complex_float* work, float* rwork, lapack_int *info );
void LAPACK_zhbgv( char* jobz, char* uplo, lapack_int* n, lapack_int* ka,
                   lapack_int* kb, lapack_complex_double* ab, lapack_int* ldab,
                   lapack_complex_double* bb, lapack_int* ldbb, double* w,
                   lapack_complex_double* z, lapack_int* ldz,
                   lapack_complex_double* work, double* rwork,
                   lapack_int *info );
void LAPACK_ssbgvd( char* jobz, char* uplo, lapack_int* n, lapack_int* ka,
                    lapack_int* kb, float* ab, lapack_int* ldab, float* bb,
                    lapack_int* ldbb, float* w, float* z, lapack_int* ldz,
                    float* work, lapack_int* lwork, lapack_int* iwork,
                    lapack_int* liwork, lapack_int *info );
void LAPACK_dsbgvd( char* jobz, char* uplo, lapack_int* n, lapack_int* ka,
                    lapack_int* kb, double* ab, lapack_int* ldab, double* bb,
                    lapack_int* ldbb, double* w, double* z, lapack_int* ldz,
                    double* work, lapack_int* lwork, lapack_int* iwork,
                    lapack_int* liwork, lapack_int *info );
void LAPACK_chbgvd( char* jobz, char* uplo, lapack_int* n, lapack_int* ka,
                    lapack_int* kb, lapack_complex_float* ab, lapack_int* ldab,
                    lapack_complex_float* bb, lapack_int* ldbb, float* w,
                    lapack_complex_float* z, lapack_int* ldz,
                    lapack_complex_float* work, lapack_int* lwork, float* rwork,
                    lapack_int* lrwork, lapack_int* iwork, lapack_int* liwork,
                    lapack_int *info );
void LAPACK_zhbgvd( char* jobz, char* uplo, lapack_int* n, lapack_int* ka,
                    lapack_int* kb, lapack_complex_double* ab, lapack_int* ldab,
                    lapack_complex_double* bb, lapack_int* ldbb, double* w,
                    lapack_complex_double* z, lapack_int* ldz,
                    lapack_complex_double* work, lapack_int* lwork,
                    double* rwork, lapack_int* lrwork, lapack_int* iwork,
                    lapack_int* liwork, lapack_int *info );
void LAPACK_ssbgvx( char* jobz, char* range, char* uplo, lapack_int* n,
                    lapack_int* ka, lapack_int* kb, float* ab, lapack_int* ldab,
                    float* bb, lapack_int* ldbb, float* q, lapack_int* ldq,
                    float* vl, float* vu, lapack_int* il, lapack_int* iu,
                    float* abstol, lapack_int* m, float* w, float* z,
                    lapack_int* ldz, float* work, lapack_int* iwork,
                    lapack_int* ifail, lapack_int *info );
void LAPACK_dsbgvx( char* jobz, char* range, char* uplo, lapack_int* n,
                    lapack_int* ka, lapack_int* kb, double* ab,
                    lapack_int* ldab, double* bb, lapack_int* ldbb, double* q,
                    lapack_int* ldq, double* vl, double* vu, lapack_int* il,
                    lapack_int* iu, double* abstol, lapack_int* m, double* w,
                    double* z, lapack_int* ldz, double* work, lapack_int* iwork,
                    lapack_int* ifail, lapack_int *info );
void LAPACK_chbgvx( char* jobz, char* range, char* uplo, lapack_int* n,
                    lapack_int* ka, lapack_int* kb, lapack_complex_float* ab,
                    lapack_int* ldab, lapack_complex_float* bb,
                    lapack_int* ldbb, lapack_complex_float* q, lapack_int* ldq,
                    float* vl, float* vu, lapack_int* il, lapack_int* iu,
                    float* abstol, lapack_int* m, float* w,
                    lapack_complex_float* z, lapack_int* ldz,
                    lapack_complex_float* work, float* rwork, lapack_int* iwork,
                    lapack_int* ifail, lapack_int *info );
void LAPACK_zhbgvx( char* jobz, char* range, char* uplo, lapack_int* n,
                    lapack_int* ka, lapack_int* kb, lapack_complex_double* ab,
                    lapack_int* ldab, lapack_complex_double* bb,
                    lapack_int* ldbb, lapack_complex_double* q, lapack_int* ldq,
                    double* vl, double* vu, lapack_int* il, lapack_int* iu,
                    double* abstol, lapack_int* m, double* w,
                    lapack_complex_double* z, lapack_int* ldz,
                    lapack_complex_double* work, double* rwork,
                    lapack_int* iwork, lapack_int* ifail, lapack_int *info );
void LAPACK_sgges( char* jobvsl, char* jobvsr, char* sort,
                   LAPACK_S_SELECT3 selctg, lapack_int* n, float* a,
                   lapack_int* lda, float* b, lapack_int* ldb, lapack_int* sdim,
                   float* alphar, float* alphai, float* beta, float* vsl,
                   lapack_int* ldvsl, float* vsr, lapack_int* ldvsr,
                   float* work, lapack_int* lwork, lapack_logical* bwork,
                   lapack_int *info );
void LAPACK_dgges( char* jobvsl, char* jobvsr, char* sort,
                   LAPACK_D_SELECT3 selctg, lapack_int* n, double* a,
                   lapack_int* lda, double* b, lapack_int* ldb,
                   lapack_int* sdim, double* alphar, double* alphai,
                   double* beta, double* vsl, lapack_int* ldvsl, double* vsr,
                   lapack_int* ldvsr, double* work, lapack_int* lwork,
                   lapack_logical* bwork, lapack_int *info );
void LAPACK_cgges( char* jobvsl, char* jobvsr, char* sort,
                   LAPACK_C_SELECT2 selctg, lapack_int* n,
                   lapack_complex_float* a, lapack_int* lda,
                   lapack_complex_float* b, lapack_int* ldb, lapack_int* sdim,
                   lapack_complex_float* alpha, lapack_complex_float* beta,
                   lapack_complex_float* vsl, lapack_int* ldvsl,
                   lapack_complex_float* vsr, lapack_int* ldvsr,
                   lapack_complex_float* work, lapack_int* lwork, float* rwork,
                   lapack_logical* bwork, lapack_int *info );
void LAPACK_zgges( char* jobvsl, char* jobvsr, char* sort,
                   LAPACK_Z_SELECT2 selctg, lapack_int* n,
                   lapack_complex_double* a, lapack_int* lda,
                   lapack_complex_double* b, lapack_int* ldb, lapack_int* sdim,
                   lapack_complex_double* alpha, lapack_complex_double* beta,
                   lapack_complex_double* vsl, lapack_int* ldvsl,
                   lapack_complex_double* vsr, lapack_int* ldvsr,
                   lapack_complex_double* work, lapack_int* lwork,
                   double* rwork, lapack_logical* bwork, lapack_int *info );
void LAPACK_sggesx( char* jobvsl, char* jobvsr, char* sort,
                    LAPACK_S_SELECT3 selctg, char* sense, lapack_int* n,
                    float* a, lapack_int* lda, float* b, lapack_int* ldb,
                    lapack_int* sdim, float* alphar, float* alphai, float* beta,
                    float* vsl, lapack_int* ldvsl, float* vsr,
                    lapack_int* ldvsr, float* rconde, float* rcondv,
                    float* work, lapack_int* lwork, lapack_int* iwork,
                    lapack_int* liwork, lapack_logical* bwork,
                    lapack_int *info );
void LAPACK_dggesx( char* jobvsl, char* jobvsr, char* sort,
                    LAPACK_D_SELECT3 selctg, char* sense, lapack_int* n,
                    double* a, lapack_int* lda, double* b, lapack_int* ldb,
                    lapack_int* sdim, double* alphar, double* alphai,
                    double* beta, double* vsl, lapack_int* ldvsl, double* vsr,
                    lapack_int* ldvsr, double* rconde, double* rcondv,
                    double* work, lapack_int* lwork, lapack_int* iwork,
                    lapack_int* liwork, lapack_logical* bwork,
                    lapack_int *info );
void LAPACK_cggesx( char* jobvsl, char* jobvsr, char* sort,
                    LAPACK_C_SELECT2 selctg, char* sense, lapack_int* n,
                    lapack_complex_float* a, lapack_int* lda,
                    lapack_complex_float* b, lapack_int* ldb, lapack_int* sdim,
                    lapack_complex_float* alpha, lapack_complex_float* beta,
                    lapack_complex_float* vsl, lapack_int* ldvsl,
                    lapack_complex_float* vsr, lapack_int* ldvsr, float* rconde,
                    float* rcondv, lapack_complex_float* work,
                    lapack_int* lwork, float* rwork, lapack_int* iwork,
                    lapack_int* liwork, lapack_logical* bwork,
                    lapack_int *info );
void LAPACK_zggesx( char* jobvsl, char* jobvsr, char* sort,
                    LAPACK_Z_SELECT2 selctg, char* sense, lapack_int* n,
                    lapack_complex_double* a, lapack_int* lda,
                    lapack_complex_double* b, lapack_int* ldb, lapack_int* sdim,
                    lapack_complex_double* alpha, lapack_complex_double* beta,
                    lapack_complex_double* vsl, lapack_int* ldvsl,
                    lapack_complex_double* vsr, lapack_int* ldvsr,
                    double* rconde, double* rcondv, lapack_complex_double* work,
                    lapack_int* lwork, double* rwork, lapack_int* iwork,
                    lapack_int* liwork, lapack_logical* bwork,
                    lapack_int *info );
void LAPACK_sggev( char* jobvl, char* jobvr, lapack_int* n, float* a,
                   lapack_int* lda, float* b, lapack_int* ldb, float* alphar,
                   float* alphai, float* beta, float* vl, lapack_int* ldvl,
                   float* vr, lapack_int* ldvr, float* work, lapack_int* lwork,
                   lapack_int *info );
void LAPACK_dggev( char* jobvl, char* jobvr, lapack_int* n, double* a,
                   lapack_int* lda, double* b, lapack_int* ldb, double* alphar,
                   double* alphai, double* beta, double* vl, lapack_int* ldvl,
                   double* vr, lapack_int* ldvr, double* work,
                   lapack_int* lwork, lapack_int *info );
void LAPACK_cggev( char* jobvl, char* jobvr, lapack_int* n,
                   lapack_complex_float* a, lapack_int* lda,
                   lapack_complex_float* b, lapack_int* ldb,
                   lapack_complex_float* alpha, lapack_complex_float* beta,
                   lapack_complex_float* vl, lapack_int* ldvl,
                   lapack_complex_float* vr, lapack_int* ldvr,
                   lapack_complex_float* work, lapack_int* lwork, float* rwork,
                   lapack_int *info );
void LAPACK_zggev( char* jobvl, char* jobvr, lapack_int* n,
                   lapack_complex_double* a, lapack_int* lda,
                   lapack_complex_double* b, lapack_int* ldb,
                   lapack_complex_double* alpha, lapack_complex_double* beta,
                   lapack_complex_double* vl, lapack_int* ldvl,
                   lapack_complex_double* vr, lapack_int* ldvr,
                   lapack_complex_double* work, lapack_int* lwork,
                   double* rwork, lapack_int *info );
void LAPACK_sggevx( char* balanc, char* jobvl, char* jobvr, char* sense,
                    lapack_int* n, float* a, lapack_int* lda, float* b,
                    lapack_int* ldb, float* alphar, float* alphai, float* beta,
                    float* vl, lapack_int* ldvl, float* vr, lapack_int* ldvr,
                    lapack_int* ilo, lapack_int* ihi, float* lscale,
                    float* rscale, float* abnrm, float* bbnrm, float* rconde,
                    float* rcondv, float* work, lapack_int* lwork,
                    lapack_int* iwork, lapack_logical* bwork,
                    lapack_int *info );
void LAPACK_dggevx( char* balanc, char* jobvl, char* jobvr, char* sense,
                    lapack_int* n, double* a, lapack_int* lda, double* b,
                    lapack_int* ldb, double* alphar, double* alphai,
                    double* beta, double* vl, lapack_int* ldvl, double* vr,
                    lapack_int* ldvr, lapack_int* ilo, lapack_int* ihi,
                    double* lscale, double* rscale, double* abnrm,
                    double* bbnrm, double* rconde, double* rcondv, double* work,
                    lapack_int* lwork, lapack_int* iwork, lapack_logical* bwork,
                    lapack_int *info );
void LAPACK_cggevx( char* balanc, char* jobvl, char* jobvr, char* sense,
                    lapack_int* n, lapack_complex_float* a, lapack_int* lda,
                    lapack_complex_float* b, lapack_int* ldb,
                    lapack_complex_float* alpha, lapack_complex_float* beta,
                    lapack_complex_float* vl, lapack_int* ldvl,
                    lapack_complex_float* vr, lapack_int* ldvr, lapack_int* ilo,
                    lapack_int* ihi, float* lscale, float* rscale, float* abnrm,
                    float* bbnrm, float* rconde, float* rcondv,
                    lapack_complex_float* work, lapack_int* lwork, float* rwork,
                    lapack_int* iwork, lapack_logical* bwork,
                    lapack_int *info );
void LAPACK_zggevx( char* balanc, char* jobvl, char* jobvr, char* sense,
                    lapack_int* n, lapack_complex_double* a, lapack_int* lda,
                    lapack_complex_double* b, lapack_int* ldb,
                    lapack_complex_double* alpha, lapack_complex_double* beta,
                    lapack_complex_double* vl, lapack_int* ldvl,
                    lapack_complex_double* vr, lapack_int* ldvr,
                    lapack_int* ilo, lapack_int* ihi, double* lscale,
                    double* rscale, double* abnrm, double* bbnrm,
                    double* rconde, double* rcondv, lapack_complex_double* work,
                    lapack_int* lwork, double* rwork, lapack_int* iwork,
                    lapack_logical* bwork, lapack_int *info );
void LAPACK_dsfrk( char* transr, char* uplo, char* trans, lapack_int* n,
                   lapack_int* k, double* alpha, const double* a,
                   lapack_int* lda, double* beta, double* c );
void LAPACK_ssfrk( char* transr, char* uplo, char* trans, lapack_int* n,
                   lapack_int* k, float* alpha, const float* a, lapack_int* lda,
                   float* beta, float* c );
void LAPACK_zhfrk( char* transr, char* uplo, char* trans, lapack_int* n,
                   lapack_int* k, double* alpha, const lapack_complex_double* a,
                   lapack_int* lda, double* beta, lapack_complex_double* c );
void LAPACK_chfrk( char* transr, char* uplo, char* trans, lapack_int* n,
                   lapack_int* k, float* alpha, const lapack_complex_float* a,
                   lapack_int* lda, float* beta, lapack_complex_float* c );
void LAPACK_dtfsm( char* transr, char* side, char* uplo, char* trans,
                   char* diag, lapack_int* m, lapack_int* n, double* alpha,
                   const double* a, double* b, lapack_int* ldb );
void LAPACK_stfsm( char* transr, char* side, char* uplo, char* trans,
                   char* diag, lapack_int* m, lapack_int* n, float* alpha,
                   const float* a, float* b, lapack_int* ldb );
void LAPACK_ztfsm( char* transr, char* side, char* uplo, char* trans,
                   char* diag, lapack_int* m, lapack_int* n,
                   lapack_complex_double* alpha, const lapack_complex_double* a,
                   lapack_complex_double* b, lapack_int* ldb );
void LAPACK_ctfsm( char* transr, char* side, char* uplo, char* trans,
                   char* diag, lapack_int* m, lapack_int* n,
                   lapack_complex_float* alpha, const lapack_complex_float* a,
                   lapack_complex_float* b, lapack_int* ldb );
void LAPACK_dtfttp( char* transr, char* uplo, lapack_int* n, const double* arf,
                    double* ap, lapack_int *info );
void LAPACK_stfttp( char* transr, char* uplo, lapack_int* n, const float* arf,
                    float* ap, lapack_int *info );
void LAPACK_ztfttp( char* transr, char* uplo, lapack_int* n,
                    const lapack_complex_double* arf, lapack_complex_double* ap,
                    lapack_int *info );
void LAPACK_ctfttp( char* transr, char* uplo, lapack_int* n,
                    const lapack_complex_float* arf, lapack_complex_float* ap,
                    lapack_int *info );
void LAPACK_dtfttr( char* transr, char* uplo, lapack_int* n, const double* arf,
                    double* a, lapack_int* lda, lapack_int *info );
void LAPACK_stfttr( char* transr, char* uplo, lapack_int* n, const float* arf,
                    float* a, lapack_int* lda, lapack_int *info );
void LAPACK_ztfttr( char* transr, char* uplo, lapack_int* n,
                    const lapack_complex_double* arf, lapack_complex_double* a,
                    lapack_int* lda, lapack_int *info );
void LAPACK_ctfttr( char* transr, char* uplo, lapack_int* n,
                    const lapack_complex_float* arf, lapack_complex_float* a,
                    lapack_int* lda, lapack_int *info );
void LAPACK_dtpttf( char* transr, char* uplo, lapack_int* n, const double* ap,
                    double* arf, lapack_int *info );
void LAPACK_stpttf( char* transr, char* uplo, lapack_int* n, const float* ap,
                    float* arf, lapack_int *info );
void LAPACK_ztpttf( char* transr, char* uplo, lapack_int* n,
                    const lapack_complex_double* ap, lapack_complex_double* arf,
                    lapack_int *info );
void LAPACK_ctpttf( char* transr, char* uplo, lapack_int* n,
                    const lapack_complex_float* ap, lapack_complex_float* arf,
                    lapack_int *info );
void LAPACK_dtpttr( char* uplo, lapack_int* n, const double* ap, double* a,
                    lapack_int* lda, lapack_int *info );
void LAPACK_stpttr( char* uplo, lapack_int* n, const float* ap, float* a,
                    lapack_int* lda, lapack_int *info );
void LAPACK_ztpttr( char* uplo, lapack_int* n, const lapack_complex_double* ap,
                    lapack_complex_double* a, lapack_int* lda,
                    lapack_int *info );
void LAPACK_ctpttr( char* uplo, lapack_int* n, const lapack_complex_float* ap,
                    lapack_complex_float* a, lapack_int* lda,
                    lapack_int *info );
void LAPACK_dtrttf( char* transr, char* uplo, lapack_int* n, const double* a,
                    lapack_int* lda, double* arf, lapack_int *info );
void LAPACK_strttf( char* transr, char* uplo, lapack_int* n, const float* a,
                    lapack_int* lda, float* arf, lapack_int *info );
void LAPACK_ztrttf( char* transr, char* uplo, lapack_int* n,
                    const lapack_complex_double* a, lapack_int* lda,
                    lapack_complex_double* arf, lapack_int *info );
void LAPACK_ctrttf( char* transr, char* uplo, lapack_int* n,
                    const lapack_complex_float* a, lapack_int* lda,
                    lapack_complex_float* arf, lapack_int *info );
void LAPACK_dtrttp( char* uplo, lapack_int* n, const double* a, lapack_int* lda,
                    double* ap, lapack_int *info );
void LAPACK_strttp( char* uplo, lapack_int* n, const float* a, lapack_int* lda,
                    float* ap, lapack_int *info );
void LAPACK_ztrttp( char* uplo, lapack_int* n, const lapack_complex_double* a,
                    lapack_int* lda, lapack_complex_double* ap,
                    lapack_int *info );
void LAPACK_ctrttp( char* uplo, lapack_int* n, const lapack_complex_float* a,
                    lapack_int* lda, lapack_complex_float* ap,
                    lapack_int *info );
void LAPACK_sgeqrfp( lapack_int* m, lapack_int* n, float* a, lapack_int* lda,
                     float* tau, float* work, lapack_int* lwork,
                     lapack_int *info );
void LAPACK_dgeqrfp( lapack_int* m, lapack_int* n, double* a, lapack_int* lda,
                     double* tau, double* work, lapack_int* lwork,
                     lapack_int *info );
void LAPACK_cgeqrfp( lapack_int* m, lapack_int* n, lapack_complex_float* a,
                     lapack_int* lda, lapack_complex_float* tau,
                     lapack_complex_float* work, lapack_int* lwork,
                     lapack_int *info );
void LAPACK_zgeqrfp( lapack_int* m, lapack_int* n, lapack_complex_double* a,
                     lapack_int* lda, lapack_complex_double* tau,
                     lapack_complex_double* work, lapack_int* lwork,
                     lapack_int *info );

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _LAPACKE_H_ */

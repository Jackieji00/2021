/*
 * trans.c - Matrix transpose B = A^T
 *
 * Each transpose function must have a prototype of the form:
 * void trans(int M, int N, int A[N][M], int B[M][N]);
 *
 * A transpose function is evaluated by counting the number of misses
 * on a 1KB direct mapped cache with a block size of 32 bytes.
 */
#include <stdio.h>
#include "cachelab.h"

int is_transpose(int M, int N, int A[N][M], int B[M][N]);

/*
 * transpose_submit - This is the solution transpose function that you
 *     will be graded on for Part B of the assignment. Do not change
 *     the description string "Transpose submission", as the driver
 *     searches for that string to identify the transpose function to
 *     be graded.
 */
char transpose_submit_desc[] = "Transpose submission";
void transpose_submit(int M, int N, int A[N][M], int B[M][N])
{
  int b1,b2,b3,b4,b5,b6,b7,b8,i,j,k; //*+3=11
  int bsize;//11+1=12
  if(M==32){ //case for 32x32
    bsize = 8;
    for (i = 0; i < N; i+=bsize) {
      for (j = 0; j < M; j+=bsize) {
        for(k=0;k<bsize;k++){
          b1 = A[i+k][j];
          b2 = A[i+k][j+1];
          b3 = A[i+k][j+2];
          b4 = A[i+k][j+3];
          b5 = A[i+k][j+4];
          b6 = A[i+k][j+5];
          b7 = A[i+k][j+6];
          b8 = A[i+k][j+7];
          B[j][i+k] = b1;
          B[j+1][i+k] = b2;
          B[j+2][i+k] = b3;
          B[j+3][i+k] = b4;
          B[j+4][i+k] = b5;
          B[j+5][i+k] = b6;
          B[j+6][i+k] = b7;
          B[j+7][i+k] = b8;
        }
      }
    }
  }else if (M==64){ //case for 64 x64
    bsize = 4;
    for (i = 0; i < N; i+=bsize+4) {
      for (j = 0; j < M; j+=bsize+4) {
        for(k=0;k<bsize;k++){
          b1 = A[i+k][j];
          b2 = A[i+k][j+1];
          b3 = A[i+k][j+2];
          b4 = A[i+k][j+3];
          b5 = A[i+k][j+4];
          b6 = A[i+k][j+5];
          b7 = A[i+k][j+6];
          b8 = A[i+k][j+7];
          B[j][i+k] = b1;
          B[j+1][i+k] = b2;
          B[j+2][i+k] = b3;
          B[j+3][i+k] = b4;
          B[j][i+k+4] = b5;
          B[j+1][i+k+4] = b6;
          B[j+2][i+k+4] = b7;
          B[j+3][i+k+4] = b8;
        }
        for(k=0;k<bsize;k++){
          b1 = A[i+4][j+k];
          b2 = A[i+5][j+k];
          b3 = A[i+6][j+k];
          b4 = A[i+7][j+k];
          b5 = B[j+k][i+4];
          b6 = B[j+k][i+5];
          b7 = B[j+k][i+6];
          b8 = B[j+k][i+7];
          B[j+k][i+4] = b1;
          B[j+k][i+5] = b2;
          B[j+k][i+6] = b3;
          B[j+k][i+7] = b4;
          B[j+k+4][i] = b5;
          B[j+k+4][i+1] = b6;
          B[j+k+4][i+2] = b7;
          B[j+k+4][i+3] = b8;
        }
        for(k=4;k<bsize+4;k++){
          b1 = A[i+k][j+4];
          b2 = A[i+k][j+5];
          b3 = A[i+k][j+6];
          b4 = A[i+k][j+7];
          B[j+4][i+k] = b1;
          B[j+5][i+k] = b2;
          B[j+6][i+k] = b3;
          B[j+7][i+k] = b4;
        }
      }
    }
  }else{ //case for 61 x67
    for(i=0;i<N;i+=17){
      for(j=0;j<M;j+=17){
        for(k=0;k+i<N&&k<17;k++){
          for(b1=0;b1+j<M&&b1<17;b1++){
            B[j+b1][i+k]=A[i+k][j+b1];
          }
        }
      }
    }
  }
}

/*
 * You can define additional transpose functions below. We've defined
 * a simple one below to help you get started.
 */

char trans_d[] = "test one";
void transT(int M, int N, int A[N][M], int B[M][N]){
  int b1,b2,b3,b4,b5,b6,b7,b8,i,j,k; //*+3=11
  int bsize;//11+1=12
  if(M==32){ //case for 32x32
    bsize = 8;
    for (i = 0; i < N; i+=bsize) {
      for (j = 0; j < M; j+=bsize) {
        for(k=0;k<bsize;k++){
          b1 = A[i+k][j];
          b2 = A[i+k][j+1];
          b3 = A[i+k][j+2];
          b4 = A[i+k][j+3];
          b5 = A[i+k][j+4];
          b6 = A[i+k][j+5];
          b7 = A[i+k][j+6];
          b8 = A[i+k][j+7];
          B[j][i+k] = b1;
          B[j+1][i+k] = b2;
          B[j+2][i+k] = b3;
          B[j+3][i+k] = b4;
          B[j+4][i+k] = b5;
          B[j+5][i+k] = b6;
          B[j+6][i+k] = b7;
          B[j+7][i+k] = b8;
        }
      }
    }
  }else if (M==64){ //case for 64 x64
    bsize = 4;
    for (i = 0; i < N; i+=bsize+4) {
      for (j = 0; j < M; j+=bsize+4) {
        for(k=0;k<bsize;k++){
          b1 = A[i+k][j];
          b2 = A[i+k][j+1];
          b3 = A[i+k][j+2];
          b4 = A[i+k][j+3];
          b5 = A[i+k][j+4];
          b6 = A[i+k][j+5];
          b7 = A[i+k][j+6];
          b8 = A[i+k][j+7];
          B[j][i+k] = b1;
          B[j+1][i+k] = b2;
          B[j+2][i+k] = b3;
          B[j+3][i+k] = b4;
          B[j][i+k+4] = b5;
          B[j+1][i+k+4] = b6;
          B[j+2][i+k+4] = b7;
          B[j+3][i+k+4] = b8;
        }
        for(k=0;k<bsize;k++){
          b1 = A[i+4][j+k];
          b2 = A[i+5][j+k];
          b3 = A[i+6][j+k];
          b4 = A[i+7][j+k];
          b5 = B[j+k][i+4];
          b6 = B[j+k][i+5];
          b7 = B[j+k][i+6];
          b8 = B[j+k][i+7];
          B[j+k][i+4] = b1;
          B[j+k][i+5] = b2;
          B[j+k][i+6] = b3;
          B[j+k][i+7] = b4;
          B[j+k+4][i] = b5;
          B[j+k+4][i+1] = b6;
          B[j+k+4][i+2] = b7;
          B[j+k+4][i+3] = b8;
        }
        for(k=4;k<bsize+4;k++){
          b1 = A[i+k][j+4];
          b2 = A[i+k][j+5];
          b3 = A[i+k][j+6];
          b4 = A[i+k][j+7];
          B[j+4][i+k] = b1;
          B[j+5][i+k] = b2;
          B[j+6][i+k] = b3;
          B[j+7][i+k] = b4;
        }
      }
    }
  }else{ //case for 61 x67
    for(i=0;i<N;i+=16){
      for(j=0;j<M;j+=16){
        for(k=0;k+i<N&&k<16;k++){
          for(b1=0;b1+j<M&&b1<16;b1++){
            B[j+b1][i+k]=A[i+k][j+b1];
          }
        }
      }
    }
  }
}
/*
 * trans - A simple baseline transpose function, not optimized for the cache.
 */
char trans_desc[] = "Simple row-wise scan transpose";
void trans(int M, int N, int A[N][M], int B[M][N])
{
    int i, j, tmp;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            tmp = A[i][j];
            B[j][i] = tmp;
        }
    }

}

/*
 * registerFunctions - This function registers your transpose
 *     functions with the driver.  At runtime, the driver will
 *     evaluate each of the registered functions and summarize their
 *     performance. This is a handy way to experiment with different
 *     transpose strategies.
 */
void registerFunctions()
{
    /* Register your solution function */
    registerTransFunction(transpose_submit, transpose_submit_desc);

    /* Register any additional transpose functions */
    registerTransFunction(trans, trans_desc);
    registerTransFunction(transT, trans_d);

}

/*
 * is_transpose - This helper function checks if B is the transpose of
 *     A. You can check the correctness of your transpose by calling
 *     it before returning from the transpose function.
 */
int is_transpose(int M, int N, int A[N][M], int B[M][N])
{
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; ++j) {
            if (A[i][j] != B[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

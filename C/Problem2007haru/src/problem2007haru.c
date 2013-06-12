#include <stdio.h>
#define SIZE  10

void prtMat(double a[SIZE][SIZE], int n);
void prod(double a[SIZE][SIZE], double b[SIZE][SIZE], double c[SIZE][SIZE], int n);
void aPow(int p, double a[SIZE][SIZE], double x[SIZE][SIZE], int n);
void copyMat(double a[SIZE][SIZE], double b[SIZE][SIZE], int n);
void unitMat(double e[SIZE][SIZE], int n);


int main(void)
{
  double a[SIZE][SIZE], x[SIZE][SIZE];
  int n = 3;
  int p;
  a[0][0] = 1; a[0][1] = 0; a[0][2] = 2;
  a[1][0] = 0; a[1][1] = 3; a[1][2] = 0;
  a[2][0] = 4; a[2][1] = 0; a[2][2] = 5;
  printf("[行列A]\n");          prtMat(a, n);
  p = 0; aPow(p, a, x, n);
  printf("[行列Aの%d乗]\n", p); prtMat(x, n);
  p = 1; aPow(p, a, x, n);
  printf("[行列Aの%d乗]\n", p); prtMat(x, n);
  p = 3; aPow(p, a, x, n);
  printf("[行列Aの%d乗]\n", p); prtMat(x, n);
  return 0;
}


void prtMat(double a[SIZE][SIZE], int n)
{
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf(" %3.1f", a[i][j]);
    }
    printf("\n");
  }
}


void prod(double a[SIZE][SIZE], double b[SIZE][SIZE], double c[SIZE][SIZE], int n)
{
  int i, j, k;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      c[i][j] = 0;
      for (k = 0; k < n; k++) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }
}


void aPow(int p, double a[SIZE][SIZE], double x[SIZE][SIZE], int n)
{
  double b[SIZE][SIZE];
  if (p < 0) {
    printf("aPow: Error!\n");
  } else if (p == 0) {
    unitMat(x, n);
  } else {
    copyMat(a, x, n);  /* x <- a */
    while (p > 1) {
      prod(a, x, b, n);
      copyMat(b, x, n);
      p--;
    }
  }
}



void copyMat(double a[SIZE][SIZE], double b[SIZE][SIZE], int n)
{
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      b[i][j] = a[i][j];
    }
  }
}


void unitMat(double e[SIZE][SIZE], int n)
{
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (i == j) {
        e[i][j] = 1;
      } else {
        e[i][j] = 0;
      }
    }
  }
}

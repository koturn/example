#include <stdio.h>
#include <math.h>
#define PI     3.1415926
#define NSIZE  100

typedef struct {
  double rl;
  double im;
} Complex;

int  inputData(double x[]);
void dft(int n, double x[], Complex f[]);


int main(void)
{
  int     k, n;
  double  x[NSIZE];
  Complex f[NSIZE];

  n = inputData(x);
  dft(n, x, f);
  printf("| k| f.rl| f.im|\n");
  for (k = 0; k < n; k++) {
    printf("|%2d|%5.1f|%5.1f|\n", k, f[k].rl, f[k].im);
  }
  return 0;
}


int inputData(double x[])
{
  int i, n;
  printf("データ数: ");
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    printf("データ数%d: ", i);
    scanf("%lf", &x[i]);
  }
  return n;
}



void dft(int n, double x[], Complex f[])
{
  int k;
  for (k = 0; k < n; k++) {
    int i = 0;
    f[k].rl = 0.0;
    f[k].im = 0.0;
    for (i = 0; i < n; i++) {
      f[k].rl +=  x[i] * cos(2 * PI * k * i / n);
      f[k].im += -x[i] * sin(2 * PI * k * i / n);
    }
    f[k].rl /= sqrt(n);
    f[k].im /= sqrt(n);
  }
}

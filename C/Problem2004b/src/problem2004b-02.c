#ifdef DEBUG
#  include <stdio.h>
#endif
#include <math.h>
#define PI  3.14159265


void sindata(int len, float freq, float tdel, float amp, float *x);


#ifndef DEBUG
int main(void)
{
  float x[5000], tdel = 5e-5, freq = 100, amp = 5;
  int len = 1000;
  sindata(len, freq, tdel, amp, x);
  return 0;
}
#else

int main(void)
{
  float x[5000], tdel = 5e-5, freq = 100, amp = 5;
  int len = 1000;
  int i;
  sindata(len, freq, tdel, amp, x);

  for (i = 0; i < len; i++) {
    printf("x[%4d] = %f\n", i, x[i]);
  }
  return 0;
}
#endif



void sindata(int len, float freq, float tdel, float amp, float *x)
{
  int i;
  for (i = 0; i < len; i++) {
    x[i] = amp * sin(2 * PI * freq * i * tdel);
  }
}

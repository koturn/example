#include <stdio.h>


int f1(int n, int m)
{
  int i;
  for (i = 0; i < m - 1; i++) {
    n /= 10;
  }
  return n % 10;
}


int main(void)
{
  int a, b, c, d, e;
  for (a = 10; a <= 99; a++) {
    for (b = 10; b <= 99; b++) {
      c =  a * f1(b, 1);
      d = (a * f1(b, 2)) * 10;
      e =  c + d;
      if (f1(d, 3) == 4) {
        if (f1(e, 3) == 3) {
          printf("  %d\n",  a);
          printf(" x%d\n",  b);
          printf(" ---\n");
          printf(" %d\n",   c);
          printf("%d\n",    d);
          printf("----\n");
          printf("%d\n",    e);
        }
      }
    }
  }
  return 0;
}

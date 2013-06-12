#include <stdio.h>


int main(void)
{
  int data1[6] = {31, 29, 31, 30, 31, 30};
  int data2[6] = {0};
  int i, cnt;
  int *p1, *p2;
  cnt = 0;
  p1 = data1;
  p2 = data2;

  for (i = 0; i < 6; i++) {
    if (((*p1) % 2) == 1) {
      *p2 = *p1;
      printf("%d\n", *p2);
      p2++;
      cnt++;
    }
    p1++;
  }
  printf("N = %d\n", cnt);
  return 0;
}

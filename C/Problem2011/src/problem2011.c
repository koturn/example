#include <stdio.h>
#include <stdlib.h>

typedef struct {
  double r;
  double x0;
  double y0;
  double area;
} Circle;

#define PI  3.141592654

void getCircle(int n, Circle c[]);
void prtCircle(int n, Circle c[]);
void sort(int n, Circle c[]);


int main(void)
{
  int seed, n;
  Circle c[100];

  printf("乱数seed : ");
  scanf("%d", &seed);
  srand(seed);

  printf("円の個数 : ");
  scanf("%d", &n);

  getCircle(n, c);
  sort(n, c);
  prtCircle(n, c);

  return 0;
}



void getCircle(int n, Circle c[])
{
  int i;
  for (i = 0; i < n; i++) {
    c[i].r    = rand() / 32767.0 * 10.0;
    c[i].x0   = rand() / 32767.0 * 20.0 - 10.0;
    c[i].y0   = rand() / 32767.0 * 20.0 - 10.0;
    c[i].area = PI * c[i].r * c[i].r;
  }
}

void prtCircle(int n, Circle c[])
{
  int i;
  printf(" no:    r (   x0,    y0)   面積\n");
  for (i = 0; i < n; i++) {
    printf("%3d:%5.1f (%5.1f, %5.1f) %6.1f\n", i + 1, c[i].r, c[i].x0, c[i].y0, c[i].area);
  }
}

void sort(int n, Circle c[])
{
  int i, j;
  Circle tmp;
  for (i = 0; i < n - 1; i++) {
    for (j = i + 1; j < n; j++) {
      if (c[i].area < c[j].area) {
        tmp  = c[j];
        c[j] = c[i];
        c[i] = tmp;
      }
    }
  }
}

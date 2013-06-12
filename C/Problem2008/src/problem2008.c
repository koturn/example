#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
  double x, y;
} Point;

typedef struct {
  Point  p[3];
  double area;
} Triangle;

void getTriangle(int n, Triangle t[]);
void calcArea(int n, Triangle t[]);
void prtTriangle(int n, Triangle t[]);
void sortTriangle(int n, Triangle t[]);


int main(void)
{
  int seed, n;
  Triangle tri[100];
  printf("乱数 seed : ");
  scanf("%d", &seed);
  srand(seed);

  printf("3角形の個数 : ");
  scanf("%d", &n);

  getTriangle(n, tri);
  calcArea(n, tri);
  sortTriangle(n, tri);
  prtTriangle(n, tri);

  return 0;
}


void getTriangle(int n, Triangle t[])
{
#ifndef DEBUG
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < 3; j++) {
      t[i].p[j].x = (double)(rand() % 201 - 100) / 10;
      t[i].p[j].y = (double)(rand() % 201 - 100) / 10;
    }
  }
#else
  t[0].p[0].x = -9.3; t[0].p[0].y = -2.9; t[0].p[1].x =  0.7; t[0].p[1].y =  9.3; t[0].p[2].x = -8.0; t[0].p[2].y =  9.0;
  t[1].p[0].x = -0.7; t[1].p[0].y =  5.0; t[1].p[1].x = -7.5; t[1].p[1].y = -1.9; t[1].p[2].x =  2.2; t[1].p[2].y =  0.3;
  t[2].p[0].x = -7.5; t[2].p[0].y = -9.9; t[2].p[1].x = -2.2; t[2].p[1].y = -4.7; t[2].p[2].x =  4.1; t[2].p[2].y = -5.3;
  t[3].p[0].x =  5.1; t[3].p[0].y = -7.5; t[3].p[1].x = -2.9; t[3].p[1].y = -1.7; t[3].p[2].x = -5.9; t[3].p[2].y =  3.4;
  t[4].p[0].x = -0.2; t[4].p[0].y = -0.0; t[4].p[1].x = -3.3; t[4].p[1].y =  0.4; t[4].p[2].x =  2.4; t[4].p[2].y =  3.2;
#endif
}


void calcArea(int n, Triangle t[])
{
  int i;
  for (i = 0; i < n; i++) {
    double a = sqrt(pow((t[i].p[1].x - t[i].p[0].x), 2.0) + pow((t[i].p[1].y - t[i].p[0].y), 2.0));
    double b = sqrt(pow((t[i].p[2].x - t[i].p[1].x), 2.0) + pow((t[i].p[2].y - t[i].p[1].y), 2.0));
    double c = sqrt(pow((t[i].p[0].x - t[i].p[2].x), 2.0) + pow((t[i].p[0].y - t[i].p[2].y), 2.0));
    double s = (a + b + c) / 2.0;
    t[i].area = sqrt(s * (s - a) * (s - b) * (s - c));
  }
}


void prtTriangle(int n, Triangle t[])
{
  int i, j;
  printf("(     V1     ) (     V2     ) (     V3     )  Area\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < 3; j++) {
      printf("(%5.1f, %5.1f) ", t[i].p[j].x,  t[i].p[j].y);
    }
    printf("%5.1f\n", t[i].area);
  }
}


void sortTriangle(int n, Triangle t[])
{
  int i;
  for (i = 0; i < n - 1; i++) {
    int j;
    for (j = i + 1; j < n; j++) {
      if (t[i].area < t[j].area) {
        Triangle tmp = t[i];
        t[i]         = t[j];
        t[j]         = tmp;
      }
    }
  }
}

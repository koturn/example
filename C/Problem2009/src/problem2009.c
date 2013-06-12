#include <stdio.h>

typedef struct {
  int    area;
  double cx, cy;
} FEATURE;

unsigned char Im[5][10] =
{
  {0, 1, 1, 0, 0, 2, 0, 0, 0, 0},
  {0, 1, 1, 0, 0, 2, 0, 4, 4, 4},
  {0, 1, 0, 0, 0, 2, 0, 0, 4, 4},
  {0, 0, 0, 2, 2, 2, 2, 0, 0, 4},
  {0, 0, 0, 2, 2, 2, 2, 0, 0, 4}
};

void calc(int m, int n, int p, unsigned char Im[5][10], FEATURE *f)
{
  int i, x, y, a;
  double cx, cy;
  for (i = 1; i <= p; i++) {
    cx = 0, cy = 0, a = 0;
    for (y = 0; y < n; y++) {
      for (x = 0; x < m; x++) {
        if (i == Im[x][y]) {
          a++;
          cx += x;
          cy += y;
        }
      }
    }
    f[i].area = a;
    if (a != 0) {
      f[i].cx = cx / a;
      f[i].cy = cy / a;
    }
  }
}

void prtFeature(int n, FEATURE *f)
{
  int i;
  for (i = 1; i <= n; i++) {
    if (f[i].area != 0) {
      printf("%2d:  %2d : (%.1f, %.1f)\n", i, f[i].area, f[i].cy, f[i].cx);
    }
  }
}


int main(void)
{
  FEATURE fea[10];
  calc(5, 10, 4, Im, fea);
  prtFeature(4, fea);
  return 0;
}

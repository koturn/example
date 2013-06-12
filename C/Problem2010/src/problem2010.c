#include <stdio.h>
#include <math.h>
#define PI  3.1415926

int main(void)
{
  double r, g, b;
  double y, cB, cR, s, h, rd;
  printf("Y S H ([0-1.0] [0-1.0] [0-360.0]): ");
  scanf("%lf %lf %lf", &y, &s, &h);
  while (1) {
    rd = h * PI / 180.0;
    cB = s * cos(rd);
    cR = s * sin(rd);
    r = y + cR;
    g = y - 0.3 / 0.59 * cR - 0.11 / 0.59 * cB;
    b = y + cB;
    if (r < 0.0 || g < 0.0 || b < 0.0) y += 0.01;
    else break;
  }
  printf("(Y, S, H) = (%4.2f, %4.2f, %4.2f)\n", y, s, h);
  printf("(R, G, B) = (%4.2f, %4.2f, %4.2f)\n", r, g, b);
  return 0;
}

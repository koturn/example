#include <stdio.h>
#include <math.h>

typedef struct {
  double p1[2], p2[2], p3[2];
  double line1, line2, line3;
} Triangle;


double distance(double p1[], double p2[]);
Triangle inputlength(Triangle t);

int main(void)
{
  Triangle tri;
  printf("3点を入力してください\n");
  printf("点1(x, y) "); scanf("%lf,%lf", &tri.p1[0], &tri.p1[1]);
  printf("点2(x, y) "); scanf("%lf,%lf", &tri.p2[0], &tri.p2[1]);
  printf("点3(x, y) "); scanf("%lf,%lf", &tri.p3[0], &tri.p3[1]);
  tri = inputlength(tri);
  printf("辺の長さは%.2f, %.2f, %.2f です\n", tri.line1, tri.line2, tri.line3);
  return 0;
}

double distance(double p1[], double p2[])
{
  return sqrt(((p1[0]) - p2[0]) * ((p1[0]) - p2[0]) + ((p1[1]) - p2[1]) * ((p1[1]) - p2[1]));
}

Triangle inputlength(Triangle t) {
  Triangle ret_t;
  ret_t.line1 = distance(t.p1, t.p2);
  ret_t.line2 = distance(t.p2, t.p3);
  ret_t.line3 = distance(t.p3, t.p1);
  return ret_t;
}

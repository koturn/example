#include <stdio.h>
#include <math.h>

typedef struct {
  char    judge;
  char   *name;
  int     points[4];
  int     ave;
  double  s;
} Person;


void calcSeiseki(int n, int m, Person p[]);
void sort(int n, Person p[]);
void prtSeiseki(int n, Person p[]);


int main(void)
{
  int n = 3, m = 4;
  Person dat[] = {
    {' ', "同志社太郎", {67, 68, 57, 66}},
    {' ', "今出川花子", {98, 75, 77, 88}},
    {' ', "京田辺次郎", {28, 75, 10, 95}},
  };
  calcSeiseki(n, m, dat);
  sort(n, dat);
  prtSeiseki(n, dat);
  return 0;
}


void calcSeiseki(int n, int m, Person p[])
{
  int i;
  double p_ave = 0.0;
  double s     = 0.0;
  for (i = 0; i < n; i++) {
    int j;
    int sum = 0.0;
    for (j = 0; j < m; j++) {
      sum += p[i].points[j];
    }
    p[i].ave  = sum / m;
    p_ave    += p[i].ave;
    if (p[i].ave < 60) {
      p[i].judge = 'F';
    }
  }

  p_ave /= n;
  for (i = 0; i < n; i++) {
    double tmp = p[i].ave - p_ave;
    s += tmp * tmp;
  }
  s = sqrt(s / n);

  for (i = 0; i < n; i++) {
    p[i].s = 10 * (p[i].ave - p_ave) / s + 50;
  }
}


void sort(int n, Person p[])
{
  int i;
  for (i = 0; i < n - 1; i++) {
    int j;
    for (j = i + 1; j < n; j++) {
      if (p[i].ave < p[j].ave) {
        Person tmp = p[i];
        p[i]       = p[j];
        p[j]       = tmp;
      }
    }
  }
}


void prtSeiseki(int n, Person p[])
{
  int i;
  printf("  名前        成績 偏差値\n");
  for (i = 0; i < n; i++) {
    printf("%c %-10s %4d %6.1f\n", p[i].judge, p[i].name, p[i].ave, p[i].s);
  }
}

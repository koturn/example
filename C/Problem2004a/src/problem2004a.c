#include <stdio.h>

typedef struct {
  int  no;        /* 番号 */
  char name[30];  /* 名前 */
  int  ten;       /* 点数 */
} Seiseki;


void swap(int i, int j, Seiseki a[])
{
  Seiseki tmp = a[i];
  a[i]        = a[j];
  a[j]        = tmp;
}


void sort(int n, Seiseki a[])
{
  int i, j;
  for (i = 0; i < n - 1; i++) {
    for (j = i + 1; j < n; j++) {
      if (a[i].ten < a[j].ten) {
        swap(i, j, a);
      }
    }
  }
}


void func1(int n, Seiseki a[], int *max, int *min, double *ave)
{
  int    i;
  double t;
  sort(n, a);
  *max = a[0].ten;
  *min = a[n - 1].ten;

  t = a[0].ten;
  for (i = 1; i < n; i++) {
    t += a[i].ten;
  }
  *ave = t / n;
}


int main(void)
{
  static Seiseki s[] = {
    {1, "あいうえお",  77},
    {2, "かきくけこ",  57},
    {3, "さしすせそ", 100},
    {4, "たちつてと",  85},
  };
  int n = 4, max, min;
  double ave;
  func1(n, s, &max, &min, &ave);
  printf("最高点 = %d (%d番 : %s)\n", max, s[0].no, s[0].name);
  printf("最低点 = %d  平均点 = %5.1f\n", min, ave);

  return 0;
}

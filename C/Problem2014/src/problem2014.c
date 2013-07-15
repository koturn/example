#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define YSIZE   6
#define XSIZE  12

int  median_value(int d[], int num);
void median(int in[YSIZE][XSIZE], int out[YSIZE][XSIZE], int n);
void makeData(int d[YSIZE][XSIZE]);
void prtData(int d[YSIZE][XSIZE]);


int main(void)
{
  int in[YSIZE][XSIZE], out[YSIZE][XSIZE];
  int m = 5, min, max, i, j;
  double ave;

  makeData(in);
  printf("入力データ\n");
  prtData(in);

  min = max = in[0][0];
  ave = 0;
  for (i = 0; i < YSIZE; i++) {
    for (j = 0; j < XSIZE; j++) {
      ave += in[i][j];
      if (min > in[i][j]) min = in[i][j];
      if (max < in[i][j]) max = in[i][j];
    }
  }
  printf("\n最小|最大|平均\n");
  printf("%4d|%4d|%4.1f\n", min, max, ave / (YSIZE * XSIZE));

  median(in, out, m);
  printf("\n%dx%dメディアンフィルタ\n", m, m);
  prtData(out);

  return 0;
}


void median(int in[YSIZE][XSIZE], int out[YSIZE][XSIZE], int n)
{
  int i, j, m, k1, k2, num;
  int d[1000];

  m = (n - 1) / 2;
  for (i = 0; i < YSIZE; i++) {
    for (j = 0; j < XSIZE; j++) {
      if (i < m || j < m || YSIZE - m <= i || XSIZE - m <= j) {
        out[i][j] = in[i][j];
      } else {
        num = 0;
        for (k1 = -m; k1 <= m; k1++) {
          for (k2 = -m; k2 <= m; k2++) {
            d[num] = in[i + k1][j + k2];
            num++;
            out[i][j] = median_value(d, num);
          }
        }
      }
    }
  }
}


int median_value(int d[], int num)
{
  int i, j, tmp;
  for (i = 0; i < num - 1; i++) {
    for (j = i + 1; j < num; j++) {
      if (d[i] > d[j]) {
        tmp  = d[i];
        d[i] = d[j];
        d[j] = tmp;
      }
    }
  }
  return d[num / 2];
}


void makeData(int d[YSIZE][XSIZE])
{
  int i, j;

  FILE *fp = fopen("data.csv", "r");
  for (i = 0; i < YSIZE; i++) {
    for (j = 0; j < XSIZE; j++) {
      fscanf(fp, "%d,", &d[i][j]);
    }
  }
  fclose(fp);
}


void prtData(int d[YSIZE][XSIZE])
{
  int i, j;
  for (i = 0; i < YSIZE; i++) {
    for (j = 0; j < XSIZE; j++) {
      printf(" %2d", d[i][j]);
    }
    puts("");
  }
}

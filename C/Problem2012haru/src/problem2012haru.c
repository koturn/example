#include <stdio.h>

int data[1000];

int  inputData(int data[]);
void sort(int n, int data[]);
int  outputData(int n, int data[]);


int main(void)
{
  int n;

  n = inputData(data);
  printf("データ数 : %d\n", n);
  sort(n, data);
  outputData(n, data);
  return 0;
}


int inputData(int data[])
{
  int   n  = 0;
  int   val;
  FILE *fp = fopen("input.txt", "r");

  if (fp == NULL) {
    return -1;
  }

  while (fscanf(fp, "%d", &val) != EOF) {
    data[n++] = val;
  }
  fclose(fp);
  return n;
}


void sort(int n, int data[])
{
  int i, j;
  for (i = 0; i < n - 1; i++) {
    for (j = i + 1; j < n; j++) {
      if (data[i] < data[j]) {
        int tmp = data[i];
        data[i] = data[j];
        data[j] = tmp;
      }
    }
  }
}


int  outputData(int n, int data[])
{
  int   i;
  FILE *fp = fopen("output.txt", "w");
  if (fp == NULL) {
    return -1;
  }

  for (i = 0; i < n; i++) {
    fprintf(fp, "%d\n", data[i]);
  }
  fclose(fp);
  return 0;
}

#include <stdio.h>
#define NSIZE  300

typedef struct {
  int x, y, z;
  int a, b, c;
} DB;

int NC[4];
DB  Case[4][NSIZE];



int func2(int a, int b, int c)
{
  if (a == b && b == c) {
    return 1;
  } else if (0 < a && a < b && b < c) {
    return 2;
  } else if (0 < c && c < b && b < a) {
    return 3;
  } else {
    return 0;
  }
}


void func1(int x, int y, int z)
{
  int a, b, c, nn;
  a  = (x - y) * (y - z) * (z - x);
  b  =  x * y - y * z;
  c  = (x - y + z) * (x + y - z);
  nn = func2(a, b, c);

  if (nn == 1 || nn == 2 || nn == 3) {
    Case[nn][NC[nn]].x = x;
    Case[nn][NC[nn]].y = y;
    Case[nn][NC[nn]].z = z;
    Case[nn][NC[nn]].a = a;
    Case[nn][NC[nn]].b = b;
    Case[nn][NC[nn]].c = c;
    NC[nn]++;
  }
}


void prtAnswer(char *str[])
{
  int i, j;
  for (i = 1; i < 4; i++) {
    if (NC[i] == 0) {
     printf("%s となる場合は存在しない．\n", str[i]);
    } else {
     printf("%s となるのは以下の%d通りである．\n", str[i], NC[i]);
     printf("(x, y, z) -> (a, b, c)\n");
     for (j = 0; j < NC[i]; j++) {
       printf("(%d, %d, %d) -> (%d, %d, %d)\n",
           Case[i][j].x, Case[i][j].y, Case[i][j].z,
           Case[i][j].a, Case[i][j].b, Case[i][j].c
       );
     }
    }
  }
}


int main(void)
{
  int x, y, z;
  char *str[] = {"", "a = b = c", "0 < a < b < c", "0 < c < b < a"};
  NC[1] = 0; NC[2] = 0; NC[3] = 0;
  for (x = 1; x <= 6; x++) {
    for (y = 1; y <= 6; y++) {
      for (z = 1; z <= 6; z++) {
        func1(x, y, z);
      }
    }
  }
  prtAnswer(str);

  return 0;
}

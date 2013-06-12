#include <stdio.h>
#define H1  1989
#define S1  1926


int change(char g, int y)
{
  int year = -1;
  if (y >= 1) {
    switch (g) {
      case 'H':
        year = H1 + y - 1;
        break;
      case 'S':
        if (y <= 64) {
          year = S1 + y - 1;
        }
        break;
    }
  }
  return year;
}


int main(void)
{
  char g;
  int y1, y2;
  printf("Input the era name (H/S) and year: ");
  scanf("%c%d", &g, &y1);
  y2 = change(g, y1);
  if (y2 != -1) {
    printf("%c %d = %d\n", g, y1, y2);
  } else {
    printf("Out of Range\n");
  }
  return 0;
}

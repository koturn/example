#include <stdio.h>
#define N  9

typedef struct {
  char *name;
  int   value;
  int   num;
} Money;


int func1(int kingaku, Money mon[])
{
  int i;
  int val = (int)(kingaku * 1.05);
  for (i = 0; i < N; i++) {
    while (val - mon[i].value >= 0) {
      val -= mon[i].value;
      mon[i].num++;
    }
  }
  return (int)(kingaku * 1.05);
}


void prtMoney(Money mon[])
{
  int i;
  for (i = 0; i < N; i++) {
    if (mon[i].num > 0) {
      printf("%s = %d 枚\n", mon[i].name, mon[i].num);
    }
  }
}


int main(void)
{
  int kingaku, zeikomi;
  Money mon[] = {
    {"一万円", 10000, 0},
    {"五千円",  5000, 0},
    {"  千円",  1000, 0},
    {"五百円",   500, 0},
    {"  百円",   100, 0},
    {"五十円",    50, 0},
    {"  十円",    10, 0},
    {"  五円",     5, 0},
    {"  一円",     1, 0}
  };
  printf("金額 = "); scanf("%d", &kingaku);
  zeikomi = func1(kingaku, mon);
  printf("税込み金額は%d円です．\n", zeikomi);
  prtMoney(mon);

  return 0;
}

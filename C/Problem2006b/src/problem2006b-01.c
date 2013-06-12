#include <stdio.h>
#include <ctype.h>


void capital(char *st);


int main(void) {
    char str[2][30] = {
      "doshisha university",
      "kyotanabe, 610-0321 japan"
    };
    int i;
    for (i = 0; i < 2; i++) {
      capital(str[i]);
    }
    return 0;
}


void capital(char *st)
{
  int is_top = 1;
  int ch;
  for (; *st != '\0'; st++) {
    if (*st == ' ') {
      ch = ' ';
      is_top = 1;
    } else if (is_top) {
      ch = toupper(*st);
      is_top = 0;
    } else {
      ch = *st;
      is_top = 0;
    }
    putchar(ch);
  }
  putchar('\n');
}

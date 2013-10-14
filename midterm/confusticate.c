#include <stdio.h>

void scramble(int x, int *y);

int main(void)
{
  int a=5, b=23;

  printf("%d %d\n", a, b);
  scramble(b, &a);
  printf("%d %d\n", a, b);
  scramble(a, &b);
  printf("%d %d\n", a, b);

  return 0;
}

void scramble(int x, int *y)
{
  int temp;

  printf("%d %d\n", x, *y);
  temp = x + 1;
  x = *y;
  *y = temp;
  printf("%d %d\n", x, *y);
}

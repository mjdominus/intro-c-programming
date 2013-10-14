
#include <stdio.h>

void swap(int n1, int n2);

int main(void)
{
  int x = 5, y = 119;

  printf("The values of x and y before the swap are %d and %d.", x, y);
  swap(x, y);
  printf("The values of x and y after the swap are %d and %d.", x, y);
  return 0;
}

void swap(int n1, int n2)
{
  int temp;

  temp = n1;
  n1 = n2;
  n2 = temp;
}

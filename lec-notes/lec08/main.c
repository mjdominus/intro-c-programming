
#include <stdio.h>

int main(void)
{
  int x, y;

  x = 5, y = 119;
  printf("The values of x and y before the swap are %d and %d.", x, y);
  swap(x, y);
  printf("The values of x and y after the swap are %d and %d.", x, y);
  return 0;
}
  

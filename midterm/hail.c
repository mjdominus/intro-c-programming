#include <stdio.h>

int main(void)
{
  int t = 4;
 
  while (t-1) {
    printf("%d\n", t);
    if (t%3)
      t = 2*t + t%3;
    else
      t /= 3;
  }

  return 0;
}

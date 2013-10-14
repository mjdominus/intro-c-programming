
#include <stdio.h>

int main(void)
{
  char name[] = { 'J', 'e', 'a', 'n', ' ', 'O', 'g', 'r', 'i', 'n', 'z' };
  int i;

  for (i=10; i>=0; i--)
    printf("%c", name[i]);

  printf("\n");
  return 0;
}
  

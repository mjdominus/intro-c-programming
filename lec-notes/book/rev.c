
#include <stdio.h>

int main(void)
{
  int n[100], i;

  for (i=0; i<100; i++)
    scanf("%d", &(n[i]));

  for (i=99; i>=0; i--) 
    printf("%d\n", n[i]);

  return 0;
}

  


#include <stdio.h>
#include <math.h>		/* For sqrt() */

int main(void)
{
  int n;

  for (;;) {
    printf("Enter a number, 0 to quit.  ");
    if (scanf("%d\n", &n) < 1)	/* Bogus input */
      while (getchar() != '\n')	/* Discard input characters to end of line */
	/* nothing */ ;
    else {
      if (n == 0)
	return 0;
      else if (is_prime(n))
	printf("That number is prime.\n");
      else
	printf("That number is not prime.\n");
    }
  }
}


int is_prime(int n)
{
  int divisor;
  
  for (divisor=2; divisor < sqrt(n); divisor+=1)
    if (n%divisor == 0)
      return 0;

  return 1;
}

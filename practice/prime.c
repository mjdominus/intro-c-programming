
/*
  Write a program which accepts integers from the user
  and reports whether or not they are prime.  Your program should quit
  when the user enters 0. 

  Your program need not check for bogus inputs. 
  */

#include <stdio.h>
#include <math.h>

double sqrt(double n);
int is_composite(int n);

int main(void) 
{
  int the_input;

  printf("Enter numbers to check for primality, 0 to quit.\n");

  for (;;) {
    do {
      scanf("%d", &the_input);
      if (the_input < 0) 
	printf("Don't enter a negative number.  Enter 0 to quit.\n");
    } while (the_input < 0);	/* Don't allow negative inputs */
    
    if (the_input == 0)
      return 0;
    
    if (is_composite(the_input))
      printf("That number is not prime.\n");
    else
      printf("That number is prime.\n");
  }
}

/*
  return 0 if n is prime, otherwise return a prime factor of n 
 */
int is_composite(int n)
{
  int i;
  double s = sqrt(n);		/* n converted to <double> before call */
  
  if (n == 2)
    return 0;

  if (n%2 == 0)			/* n is even */
    return 2;

  for (i = 3; i <= s; i+=2) 
    if (n%i == 0)		/* n is divisible by i */
      return i;

  /* n is not divisible by any integer between 2 and sqrt(n), inclusive.
     Therefore, n is prime.  Reference: -Grundlagen der Mathematiche_, 
     by Landau and is well-known anyway. */

  return 0;
}

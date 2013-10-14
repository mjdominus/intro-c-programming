
/*
The _factorial_ of a positive integer n is the product of all the
intgers between 1 and n, inclusive.  The factorial of 0 is 1.  Write a
function that returns the factorial of its argument.
*/

long int factorial(int n)
{
  int fact = 1;

  if (n == 0) return 1L;	/* long int constants end in capital L */

  while (n) 
    fact *= n--;

  return fact;
}


/* Or you could do it this way: */

long int factorial(int n)
{
  if (n == 0) return 1L;
  else return n * factorial(n-1);
}

/* If you don't understand this second one, don't worry about it---
 * we'll cover it in class. */

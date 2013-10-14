
/*
Write a function that reads doubles from its input and outputs the
square root of each.  Check for negative inputs.
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
  double input;

  while (scanf("%lf", &input) != EOF) {
    if (input < 0)
      printf("You can't take the square root of a negative number, dummy.\n");
    else
      printf("The square root of %f is %f.\n", input, sqrt(input));
  }

  printf("Done.\n");

  return 0;
}

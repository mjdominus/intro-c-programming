/*
Assume that there is a function `toupper' which takes a char argument.
It returns the uppercase version of its argument if the argument was a
lowercase letter; otherwise it returns its argument. That is,
toupper('c') returns 'C'; toupper('F') returns 'F', and toupper('#')
returns '#'.  Write a program which reads its input, translates the
lowercase letters in the input to uppercase, and writes out the result.
Your program should terminate when it sees EOF.

*/

#include <stdio.h>
#include <ctype.h>		/* Happens to provide a `toupper' like 
				   the  one I described. */

int main(void)
{
  int c;

  while ((c = getchar()) != EOF)
    printf("%c", toupper(c));

  return 0;
}

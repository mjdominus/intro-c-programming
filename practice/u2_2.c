
/*

Hieronymus Bonghit was never quite himself after he was struck on the
head by a falling wah-wah pedal at last year's Saint Patrick's Day
Parade.  His irrational hatred of the Irish rock band `U2' has increased
ever since last March.  This week he wants to erase all the files on his
system which mention U2.  The first step is to identify these files.
Write a program which reads its input and reports whether or not the
sequence of characters `U2' appeared anywhere within it.
*/

/* General Solution:  Program searches for any 
 * occurrence of the string `needle'.
 */

#include <stdio.h>

/* To solve the stated problem, change NEEDLE_LENGTH to 2 and
 * NEEDLE to "U2". */
#define NEEDLE_LENGTH 5		/* Length of string we're looking for */
#define NEEDLE "fooey"		/* string we're looking for */

int main(void)
{
  char needle[NEEDLE_LENGTH] = NEEDLE;
  char input[NEEDLE_LENGTH];	/* Will hold the last NEEDLE_LENGTH
				   characters from the input.  We'll
				   compare these characters with those
				   in the NEEDLE to see if we've found
				   what we wanted. */
  int c;
  int i;

  /* initialize input buffer with characters that won't appear in the input */
  for (i=0; i<NEEDLE_LENGTH; i++)
    input[i] = '\0';

  while ((c = getchar()) != EOF) {
    
    /* Shift contents of `input' left one character to make room for new 
       input character; discard oldest input character. */
    for (i=0; i< NEEDLE_LENGTH - 1; i++)
      input[i] = input[i+1];

    input[NEEDLE_LENGTH-1] = c;

    /* Check to see if `input', the record of the last few characters we 
       saw, contains the string we're searching for. */

    for (i=0; i<NEEDLE_LENGTH; i++) 
      if (input[i] != needle[i])
	break;

    /* We could get here in two ways.  Either one of the characters in
       the input didn't match the corresponding character in the needle,
       and so we hit `break', in which case `i' is still less than
       NEEDLE_LENGTH_ or else all the characters matched, and we exited
       the loop normally because (i<NEEDLE_LENGTH), the control, was
       false. Let's see which it was. */

    if ( ! (i < NEEDLE_LENGTH) ) { /* Target found */
      printf("Target `%s' found in input.\n", needle);
      return 0;
    }
    
    /* Keep searching */
  }

  /* We reached EOF */

  printf("Target `%s' not found in input.\n", needle);
  return 0;
}

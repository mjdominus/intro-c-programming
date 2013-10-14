

/* 
  Write a program which prints the letters of the alphabet in a random
  order.  Each letter should appear only once.  Assume a function `chr()'
  which accepts the index of a letter in the alphabet and returns that
  letter.  (For example, chr(0) returns 'a'; chr(25) returns 'z'; chr(12)
  returns 'm'.
  */

char chr(int n);

#include <stdio.h>
#include <stdlib.h>

#define random(n) ((rand()>>6) %(n))
#define NUM_LETTERS 26

int main(void)
{
  int printed[NUM_LETTERS];	/* printed[i] says if we've printed out 
				   the letter with index i yet. */
  int num_printed = 0;		/* Number of letters printed so far. */
  int i;
  srand(time(NULL));

  /* No letter printed so far; initialize structure that says so. */
  for (i=0; i<NUM_LETTERS; i++)
    printed[i] = 0;

  for (num_printed=0; num_printed<NUM_LETTERS; num_printed++) {
    int letter_to_print;

    do 
      letter_to_print = random(NUM_LETTERS);
    while (printed[letter_to_print]) ;

    printf("%c", chr(letter_to_print));
    printed[letter_to_print] = 1;
  }

  printf("\n");
  return 0;
}

/* one way to implement chr() if the character set is ASCII.
   Fails if input is not a lowercase letter. */
char chr(int n)
{
  return n + 'a';
}

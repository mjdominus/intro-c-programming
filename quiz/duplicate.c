
/*

Write a complete program which reads integers from the user, reporting
when the user enters an integer that he or she has already entered.
You program should quit when the user enters the number 0.

Your program need not check for bogus inputs.  Your program must behave
correctly as long as the user enters 30 or fewer different numbers; I
will not penalize you for bad behavior when the user enters more than 30
different numbers.  

18 July 1992 
Mark-Jason Dominus

*/

#include <stdio.h>

#define MAX_NUM_INPUTS 30	/* specification says we need only
				   remember 30 different numbers. */


int main(void)
{
  int the_input;		/* Most recent input */
  int inputs[MAX_NUM_INPUTS];	/* Set of unique inputs so far */
  int inputs_so_far = 0;	/* Count of number of different integers
				   entered so far. */
  int i;
  
  printf("Please enter a sequence of numbers, 0 to quit.\n");
  while (inputs_so_far < MAX_NUM_INPUTS) {
    scanf("%d", &the_input);	/* We needn't check for bogus input */
    
    if (the_input == 0) {	/* Quit */
      printf("Done.\n");
      return 0;
    }

    /* Check to see if the current input has been entered already. */
    for (i=0; i<inputs_so_far; i++)
      if (inputs[i] == the_input)
	break;	

    /* We're out of the loop.  It oculd be because the_input is a 
       repeat, and we hit the `break', or it could be that the_input was
       not a repeat and we fell out of the loop when (i<inputs_so_far) 
       became false.  In the former case, (i<inputs_so_far) will still
       be true. */

    if (i < inputs_so_far)	/* the_input is a repeat---it's 
				   equal to inputs[i]  */
      printf("You entered that number already.\n");
    else			/* the_input is not a repeat */
      inputs[inputs_so_far++] = the_input;
    
  }

  printf("I can't handle any more inputs.\n");
  return 1;
}

/*
Granny's famous Gruel Recipe goes like this:
	3 cups corn meal
	4 cups water
boil water.  add meal.  reduce heat.  cook 20 minutes.  Serves 6. 
Write a program which reads input specifying how many people are coming
over for supper, and which prints out a gruel recipe for enough gruel to
feed them all.  
*/

#include <stdio.h>

#define CANONICAL_GUESTS   6	/* `typical' number of guests */
#define CORN_MEAL          3.0   /* Cups of corn meal for typical number */
#define WATER              4.0   /* Cups of water for typical number */

int main(void)
{
  int num_guests;

  do {
    printf("How many people are coming to dinner?\n");

    while (scanf("%d", &num_guests) < 1) /* Discard line */
      while (getchar() != '\n')
	/* nothing */ ;

    if (num_guests < 0)
      printf("That's a funny number of guests to have!\n");
  } while (num_guests < 0);

  printf("Take:\n");
  printf("%f cups of corn meal, and\n", 
	 (CORN_MEAL / CANONICAL_GUESTS) * num_guests);
  printf("%f cups of water.\n", 
	 (WATER / CANONICAL_GUESTS) * num_guests);
  printf("boil water.  add meal.  reduce heat.  cook 20 minutes.\n");
  printf("Serves %d.\n", num_guests);

  return 0;
}

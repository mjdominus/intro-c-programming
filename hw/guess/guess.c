
/* guess.c
 *
 * This program implements a reference solution
 * to Assignment #1 of my CSE110 course.
 *
 * The problem is to play a guessing game with the user.
 *
 * The REQUIREMENTS section of the assignment:
 *
    Your program will pick a random number between 1 and 100.  Your
program will remember this number but keep it secret.  Your program will
prompt the user to guess a number between 1 and 100 until the user
guesses your program's secret number.  When the user guesses your
program's secret number, the game is over and your program will print an
appropriate message which includes the number of guesses taken by the
user.  When the user enters an incorrect guess, your program will print
an appropriate message and will say whether the guess was too high or
too low.

    You will provide a method by which the user can quit in the middle
of a game if he or she desires.  You will inform the user of how this
may be accomplished.

    After each game, your program will prompt the user to input whether
he or she desires another game.  If not, your program will finish.
Otherwise, it will play again.  The computer will choose a new random
secret number for each game.

    Your program should not assume that the user will always type what
you expect; it must handle bogus inputs gracefully and discard garbage
input.

 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "log.h"

#define YES 1
#define NO  0

#define I_QUIT 0		/* Enter this guess to quit immediately. */
#define MIN_GUESS 1
#define MAX_GUESS 100

int get_guess(void);
int play_again(void);
int flush_line(void);
void init_random(void);
int pick_number(void);
void greet(void);

int main(void)
{
  int secret;			/* Computer's secret number */

  init_random();
  greet();

  for (;;) {
    int guess;			/* Number the user is guessing */
    int num_guesses = 0;	/* Number of guesses user made so far */


    secret = pick_number();
    printf("Okay, I am thinking of a number.\n");

    for (;;) {
      guess = get_guess();
      num_guesses += 1;

      if (guess == I_QUIT) {
	printf("Quitter.\n");
	return 0;		/* Terminate program immediately */
      } else if (guess > secret)
	printf("%d is too high.\n", guess);
      else if (guess < secret)
	printf("%d is too low.\n", guess);
      else {
	printf("That's right.  Congratulations; you took %d guesses.\n",
	       num_guesses);
	break;
      }
    }
  
    if (play_again() == NO) break;
  }
  printf ("Thank you for playing.\n");
  return 0;
}

/*
 * Greet user and explain rules.
 */
void greet(void)
{
  printf("Hello.  We will play a guessing game.\n");
  printf("I will think of a number between %d and %d.\n",
	 MIN_GUESS, MAX_GUESS);
  printf("You will try to guess what this number is.  I will tell you\n");
  printf("If your guess is too high or too low.\n");
  printf("To quit at any time, enter %d instead of a guess.\n", I_QUIT);
  return;
}

/* 
 * Prompt user to guess a number.  Validate input; it must be between
 * MIN_GUESS and MAX_GUESS, inclusive, or else be I_QUIT, which signals
 * that the user wants to quit immediately.
 * Returns valid guess.
 */
int get_guess(void)
{
  int the_guess = -1;		/* Not a valid guess */

  do {
    printf("What is your guess? (Enter %d-%d, or %d to quit.)\n",
	   MIN_GUESS, MAX_GUESS, I_QUIT);

    if (scanf("%d", &the_guess) == 0 ) 
      if (flush_line() == EOF) return 0; /* EOF or error should
					  * terminate game */
  } while ( the_guess != I_QUIT && 
	   (the_guess < MIN_GUESS || the_guess > MAX_GUESS ));

  return the_guess;
}


/*
 * Prompt user to see if he or she wants to play another game.
 * Read answer and interpret.
 * Return YES to play again, NO if not.
 */
int play_again(void)
{
  int answer = -1;		/* Neither YES nor NO */

  do {
    printf("Would you like to play again?\n");  
    printf("Enter 1 for `yes', 0 for `no'.\n");

    if (scanf("%d", &answer) == 0 ) 
      if (flush_line() == EOF) return NO; /* EOF or error should 
					   * terminate game */
  } while ( answer != 0 && answer != 1 );

  if (answer == 0) return NO;
  else             return YES;
}

/*
 * An error occurred in the input, so flush all the input 
 * up to the next newline so scanf can try again.
 * 
 * Returns 0 on success, EOF on end-of-file or error.
 */
int flush_line(void)
{
  int c;

  while ((c = getchar()) != '\n' && c != EOF) 
    /* devour input line */ ;

  if (c == EOF) return EOF;
  else          return 0;
}

/*
 * Seed random number generator. 
 */
void init_random(void)
{
  srand(time(NULL));
}

/*
 * Choose a random number between MIN_GUESS and MAX_GUESS,
 * inclusive.  
 */
int pick_number(void)
{
  return MIN_GUESS + random(MAX_GUESS-MIN_GUESS+1);
}

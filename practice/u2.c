/*

Hieronymus Bonghit was never quite himself after he was struck on the
head by a falling wah-wah pedal at last year's Saint Patrick's Day
Parade.  His irrational hatred of the Irish rock band `U2' has increased
ever since last March.  This week he wants to erase all the files on his
system which mention U2.  The first step is to identify these files.
Write a program which reads its input and reports whether or not the
sequence of characters `U2' appeared anywhere within it.
*/

#include <stdio.h>

/* States that our searcher can be in.
 * If it's in state START, it's looking for a 'U'.  when it sees it, it 
 * goes into state SAW_U and looks for a '2'. If it sees a 2, 
 * it goes into state SAW_2 and reports. */
#define START 0
#define SAW_U 1
#define SAW_2 2

int main(void)
{
  int c;
  int state = START;

  while ((c = getchar()) != EOF) {
    if (state == START && c == 'U') {
      state = SAW_U;
    } else if (state == SAW_U) {
      if (c == '2') {		/* Jackpot! */
	state = SAW_2;
	printf("Begone, Gaelic infidels!\n");
	return 0;
      } else {			/* False alarm -- 
				   `U' followed by something else */
	state = START;
      }
    }
  }
  /* We must have seen EOF.  Quit silently. */

  return 0;
}

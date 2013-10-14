
#include <stdio.h>

int main(void)
{
  int c = 0, w = 0, l = 0;	/* Count of characters, words, lines */
  int ch;			/* Current character */

  while ((ch = getchar()) != EOF) {
    c++;
    if ( ch == ' ' || ch == '\t' || ch == '\n') w++;
    if ( ch == '\n' ) l++;
  }

  printf("Characters: %d.  Words: %d.  Lines: %d.\n", c, w, l);
  return 0;
}


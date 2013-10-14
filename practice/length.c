
/*
Write a program which prints out the length of each line in its input,
halting at EOF.
*/

#include <stdio.h>

int main(void)
{
  int length;
  int c;

  for (;;) {
    length = 0;

    while ((c = getchar()) != EOF && c != '\n')	/* Note short-circuiting */
      length++;

    if (length == 0 && c == EOF) /* End of input */
      return 0;

    printf("%d\n", length);
  }

  /* Not reached */
}

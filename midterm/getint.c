int get_int(int min, int max, char *prompt)
{
  int response;                        /* User's resposnse */
  int c;

  do {
    printf("%s", prompt);
    while (scanf("%d", &response) != 1)
      /* Discard non-numeric input up through next white space. */
      while ((c = getchar()) != ' ' && c != '\t' && c != '\n')
        /* nothing */ ;

    /* When we're out of the while loop, `response' definitely has 
       some integer value in it. */

  } while (response < min || response > max);

  return response;
}

void strrev(char *s)
{
  char *e;               
  int left=0;                        /* Count of characters left to swap */
  char temp;                         /* For swap */

  /* If length of string is less than 2, don't bother. */
  /* Note short-circuiting here---it's {\em very important}\/. */
  if (s[0] == '\0' || s[1] == '\0')
    return;

  /* First, point {\tt e} at end of {\tt s} and compute length of {\tt s}: */
  for (e=s; *e != '\0'; e++)
    left++;

  /* {\tt e} now points to {\tt NUL} character at end of {\tt s}. */
  /* {\tt left} is the number of characters we have to swap. */

  e--;        
  /* {\tt e} now points at last character in {\tt s}. */

  while (left > 1) {            
    temp = *s; *s = *e; *e = temp; /* Swap characters at beginning and end */
    s++; e--;                      /* Move towards middle of string  */
    left -= 2;                     /* two fewer characters to swap. */
  }

}

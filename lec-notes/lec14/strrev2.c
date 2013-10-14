void strrev(char *s)
{
  int i, len = strlen(s);
  char aux[len+1];		/* You can't do this */
  
  aux[len] = '\0';

  for (i=0; i<len; i++)
    aux[i] = s[len-1-i];	/* Copy string backwards */

  for (i=0; i<len; i++)
    s[i] = aux[i];		/* Copy string forwards */

  return;
}

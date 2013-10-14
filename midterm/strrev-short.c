void strrev(char *s)
{
  char *e;               
  int left=0;                        /* Count of characters left to swap */
  char temp;                         /* For swap */

  /* If length of string is less than 2, don't bother. */
  if (s[0] == '\0' || s[1] == '\0')
    return;
  
  /* First, point e at end of s and compute length of s: */
  for (e=s; *e != '\0'; e++)
    left++;
  e--;        


  while (left > 1) {  
    temp = *s; *s = *e; *e = temp;
    s++; e--;                     
    left -= 2;                    
  }

}


int strcmp(char *s1, char *s2)
{ 
  while(1) {
    if ( *s1 == '\0' && *s2 == '\0' )
      return 0;			/* strings are identical */
    else if (*s1 == '\0') 
      return -1;		/* {\tt s1} is a prefix of {\tt s2} */
    else if (*s2 == '\0') 
      return 1; 		/* {\tt s2} is a prefix of {\tt s1} */
    else if ( *s1 < *s2 )
      return -1;		/* {\tt s1} is less */
    else if ( *s1 > *s2 )
      return 1;			/* {\tt s2} is less */
    else {
      s1++; s2++;
    }
  }
}

  

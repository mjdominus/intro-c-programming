
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "lila.h"

char *
  negate_signed_string(const char *s)
{
  char *sn;

  sn = strdup(s);
  if (sn == NULL)
    return NULL;

  switch (*sn) {
  case '-':
    *sn = '+';
    break;
  case '+':
    *sn = '-';
    break;
  default:
    fprintf(stderr, "negate_signed_string (%s) fails.\n", sn);
    abort();
  }
    
  return sn;
}

char * 
  negate_unsigned_string(const char *s)
{
  char *sn;
  
  sn = malloc(strlen(s)+1);
  if (sn == NULL) return NULL;

  strcpy(sn+1, s);
  *sn = '-';

  return sn;
}
  

/* Convert signed string to unsigned string */
char *
  signed_to_unsigned(const char *s)
{
  char *sa;

  sa = strdup(s);
  if (sa == NULL) return NULL;
  
  switch (*sa) {
  case '+':
  case '-':
    return sa+1;
  default:
    return sa;
  }
}

char *
  unsigned_to_signed(int sign, const char *s)
{
  char *ss;

  ss = malloc(strlen(s)+1);
  if (ss == NULL) return NULL;

  strcpy(ss+1, s);
  *ss = ((sign < 0) ? '-' : '+');

  return ss;
}

char *
  normalize_signed(const char *s)
{
  const char *last_nonzero_digit = NULL, *p;
  char *sn;
  int i = 1;

  for (p=s+1; *p; p++)
    if (*p != TO_REP(0))
      last_nonzero_digit = p;

  if (last_nonzero_digit == NULL)
    return strdup("0");
 
  sn = malloc(last_nonzero_digit - s + 1);
  if (sn == NULL) return NULL;

  for (p = last_nonzero_digit; p>s; p--) 
    sn[i++] = *p;

  sn[0] = s[0];    
  sn[last_nonzero_digit - s + 1] = '\0';

  return sn;
}


#include <malloc.h>
#include "lila.h"

char *
  subtract_signed_string(const char *s1, const char *s2)
{
  return add_signed_string(s1, negate_signed_string(s2));
}

char *
  subtract_unsigned_string(const char *s1, const char *s2)
{
  char *dif_str, *end;		/* result */
  const char *e1, *e2;	
  int slen;
  int borrow = 0;

  /* do validity checking on strings */

  if (compare_unsigned_string(s1, s2) < 0)
    abort();

  slen = strlen(s2) + 1;

  if ((dif_str = malloc(slen)) == NULL)
    return NULL;

  for (e1 = s1, e2 = s2, end = dif_str; *e2; e1++, e2++, end++) {
    int dif = TO_NUM(*e1) - TO_NUM(*e2) - borrow;

    if (dif < 0) {
      dif += BASE;
      borrow = 1;
    } else {
      borrow = 0;
    }
    *end = TO_REP(dif);
  }

  for ( ; *e1; e1++, end++) {
    int dif = TO_NUM(*e1) - borrow;
    if (dif < 0) {
      dif += BASE;
      borrow = 1;
    } else {
      borrow = 0;
    }
    *end = TO_REP(dif);

  }

  if (borrow) 
    abort();
  else
    *end = '\0';

  return dif_str;
}
    
  

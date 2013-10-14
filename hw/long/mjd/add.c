
#include <malloc.h>
#include "lila.h"

char *
  add_signed_string(const char *s1, const char *s2)
{
  int m1, m2;			/* Signs of s1 and s2 */
  int c;

  c = compare_unsigned_string(signed_to_unsigned(s1),
			      signed_to_unsigned(s2));

  if (c < 0) {
    const char *temp;
     
    temp = s1;
    s1 = s2;
    s2 = temp;
  }
  
/* The one with larger absolute value is now first. */

  m1 = SIGN(s1); m2 = SIGN(s2);
  
  if (m1 == m2)			/* Add them */
    return unsigned_to_signed
      (m1, 
       add_unsigned_string
       (signed_to_unsigned(s1), signed_to_unsigned(s2))
       );
  else 
    return unsigned_to_signed
      (m1,
       subtract_unsigned_string
       (signed_to_unsigned(s1), signed_to_unsigned(s2))
       );
}

char *
  add_unsigned_string(const char *s1, const char *s2)
{

  char *sum_str, *end;		/* result */
  const char *e1, *e2;	
  int slen;
  int carry = 0;

  /* do validity checking on strings */

  if (strlen(s1) > strlen(s2)) {
    const char *temp;
    
    temp = s1;
    s1 = s2;
    s2 = temp;
  }

  slen = strlen(s2) + 1;

  if ((sum_str = malloc(slen)) == NULL)
    return NULL;

  for (e1 = s1, e2 = s2, end = sum_str; *e1; e1++, e2++, end++) {
    int sum = TO_NUM(*e1) + TO_NUM(*e2) + carry;

    carry = sum / BASE;
    *end = TO_REP(sum % BASE);
  }

  for ( ; *e2; e2++, end++) {
    int sum = TO_NUM(*e2) + carry;

    carry = sum / BASE;
    *end = TO_REP(sum % BASE);
  }

  if (carry) 
    *end = TO_REP(carry);
  else
    *end = '\0';

  return sum_str;
}
    
  

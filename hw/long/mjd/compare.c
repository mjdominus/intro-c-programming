
#include "lila.h"

int
  compare_signed_string(const char *s1, const char *s2)
{
  int m1 = SIGN(s1), m2 = SIGN(s2);

  if (m1 == m2)
    return compare_unsigned_string(s1+1, s2+1);
  else 
    return m1-m2;
}

int
  compare_unsigned_string(const char *s1, const char *s2)
{
  int l1 = strlen(s1), l2 = strlen(s2);
  const char *e1 = s1+l1-1, *e2 = s2+l2-1;

  if (l1 != l2)
    return l1-l2;

  for (e1 = s1+l1-1, e2 = s2+l2-1;
       e1 != s1 && e2 != s2;
       e1--, e2--) {
    if (*e1 != *e2)
      return TO_NUM(*e1)-TO_NUM(*e2);
  }
  if (*e1 == *e2)
    return 0;
  else 
    return TO_NUM(*e1)-TO_NUM(*e2);
}

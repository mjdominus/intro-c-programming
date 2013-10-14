
#include <stdio.h>
#include <string.h>
#include "proto.h"

int
  main(void)
{
  char s1[80], s2[80];

  fgets(s1, 80, stdin);
  *strchr(s1, '\n') = '\0';
  strcpy(s1, normalize_signed(s1));
  fgets(s2, 80, stdin);
  *strchr(s2, '\n') = '\0';
  strcpy(s2, normalize_signed(s2));

  printf("%s + %s = %s\n", s1, s2, normalize_signed(add_signed_string(s1,s2)));
  printf("%s - %s = %s\n", s1, s2, normalize_signed(subtract_signed_string(s1,s2)));
  printf("%s - %s = %s\n", s2, s1, normalize_signed(subtract_signed_string(s2,s1)));


  return 0;
}

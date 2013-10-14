
#include <stdio.h>
#include <malloc.h>
#include "lila.h"

void
  print_signed(const char *s)
{
  char *sn;

  sn = normalize_signed(s);
  puts(sn);
  free(sn);
}





#include <string.h>

#define TO_NUM(r)  ((r) - '0')
#define TO_REP(n)  ((n) + '0')

#define BASE 10

#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))

#ifndef NULL
#define NULL 0
#endif

#define SIGN(s) (((*(s))=='-') ? -1 : 1)

#include "proto.h"
#include "sysproto.h"

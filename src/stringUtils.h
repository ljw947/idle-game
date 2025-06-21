/* String utils for converting to strings */

#ifndef STRINGUTILS_H_
#define STRINGUTILS_H_

#include <stdio.h>
#include <stdlib.h>

static inline char *getString(int num) {
  int size = snprintf(NULL, 0, "%d", num);
  char *str = malloc(size + 1);
  sprintf(str, "%d", num);
  return str;
}

#endif  // STRINGUTILS_H_

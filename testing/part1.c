#include <stddef.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/* Returns a heap allocated, null-terminated, zero-length string. */

char *empty_string(void)
{
  char *emptyString = malloc(sizeof(char));
  *emptyString = '\0';

  return emptyString;
}


/* Given a string, return a heap-allocated copy */

char *clone(const char *str)
{
  char *copy = malloc((strlen(str)+1) * sizeof(char));
  memcpy(copy, str, strlen(str));

  return copy;
}


/* Returns a heap allocated string that consists of "current" appended to
 * "append". This process must either free current or prevent it from
 * being leaked via some other mechanism.
 */

char *push_string(char *current, const char *append)
{
  int currLen = strlen(current);
  int appLen = strlen(append);
  char *newString = malloc((currLen+appLen) * sizeof(char));
  memcpy(newString, current, currLen);
  memcpy((newString+currLen), append, appLen);

  return newString;
}


int main(void) {
  char *str = empty_string();
  str = push_string(str, " This " );
  str = push_string(str, " is " );
  str = push_string(str, " a sequence of " );
  str = push_string(str, " string concatenations! " );
  printf(" %s \n " , str);
  free(str);
  
}

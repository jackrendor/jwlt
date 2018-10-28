/*
    sfunctions.h
    String Functions is a library that contains all the opration that
    jwlt will perform to the strings.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *g_arg(char *string, int argument_pos, char placeholder)
{
  int c2 = 0, current_arg = 0;
  /*
    TODO: fix this shit. I don't want to allocate
          too much space for allocating an argument
          that it's (for example) 3 chars long.
  */
  char *tmp = (char*) malloc(strlen(string));

  for (size_t c=0; c<strlen(string); c++){
    if (string[c] == placeholder){
      current_arg++;
    }else if (current_arg == argument_pos){
      tmp[c2] = string[c];
      c2++;
    }
  }
  return tmp;
}
int isnumber(char *argument)
{
  /*
    Argument checker. I want to be sure
    that a string is an integer.
    I don't want to mess around.

    NOTE: if it's a number, returns 1
          otherwise, 0.
  */

  while (*arg != '\0'){
    if (!isdigit(*arg))
      return 0;
    arg++;
  }
  return 1;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define SESSION_FILENAME ".jwlt.session"

void usage(char *file_name)
{
  printf("Usage:\n");
  printf("   %s\t <charset string> <wordlist lenght> <save interval>\n", file_name);
  printf("   %s\t <charset string> <wordlist lenght>\n", file_name);
  printf("   %s\t [--delete-session / -ds]\n", file_name);
}

int save_progress(int *tracker, int tracker_size)
{
  // Open file in write mode
  FILE *session = fopen(SESSION_FILENAME, "w");

  // Check status of file stream
  if (session == NULL){
    fclose(session);
    return -1;
  }

  for (int i=0; i<tracker_size; i++) {
    // write & check
    if (fprintf(session, "%d-", tracker[i]) <= 0){
      fclose(session);
      return -2;
    }
  }

  // Everything went fine (I hope.)
  fclose(session);
  return 1;
}

void encrease(int *tracker, int tracker_size, int pattern_len)
{
  /*
    This function increase by one the array that
    indexes the charset when printing a char
  */
  tracker[tracker_size-1]++;
  for (int i=tracker_size-1; i>=0; --i){

    if (tracker[i] >= pattern_len){
      tracker[i] = 0;

      // We don't want to add stuff at -1 index
      if (i-1 >= 0)
        tracker[i-1]++;
    }

  }
}

void print_gen(char *pattern, int *tracker, int tracker_size)
{
  /*
    This function prints the word char by char
    based on the tracker array that contains
    all the indices of the charset
  */
  for (int c=0; c<tracker_size; c++){
    printf("%c", pattern[tracker[c]]);
  }
  printf("\n");
}

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

int reload_session(int *tracker, int tracker_size)
{
  /*
    This function reads from the file and
    updated the tracker (or index) to the
    last saved session
  */
  FILE *session = fopen(SESSION_FILENAME, "r");
  if (session == NULL)
    return 0;

  /*
    TODO: Find a workaround to allocate in the
          right way the container.
    NOTE: I hate this shit. This is prone to buffer overflow.
  */
  char container[50];

  // Get one line. It's good enough.
  if (fgets(container, (size_t)50, session) == NULL)
    return -1;

  // Update the tracker (or index)
  for (int i=0; i<tracker_size; i++){
    tracker[i] = atoi(g_arg(container, i, '-'));
  }

  return 1;
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

  int arg_len = strlen(argument);
  for (int i=0; i<arg_len; i++){
    if (!isdigit(argument[i]))
      return 0;
  }
  return 1;
}

int main(int argc, char **argv)
{
  int interval;
  int len;

  // Arguments check
  if (argc > 4){
    //If you supply more than 3 arguments, let's print out a funny error
    printf("OK now tell me what I'm suppose to do with this %d extra argument(s)\n", argc-4);
    return -4;

  } else if(argc == 4){
    /*
      We if the maximum argument was supplied, then
      check if the last two arguments are numbers
    */
    if (!isnumber(argv[2])) {
      puts("[ERROR] Second argument must be a number.");
      return -2;
    }
    if (!isnumber(argv[3])) {
      puts("[ERROR] Third argument must be a number.");
      return -3;
    }

    // Set values
    interval = atoi(argv[3]);
    len = atoi(argv[2]);

  } else if (argc == 3) {
    /*
      Last argument must be an integer
    */
    if (!isnumber(argv[2])) {
      puts("[ERROR] Second argument must be a number.");
      return -2;
    }

    // Set value
    len = atoi(argv[2]);

  } else if (argc == 2) {
    /*
      If only one argument was supplied,
      check if it's a special function
    */
    if (strcmp(argv[1], "--delete-session") == 0 ||
        strcmp(argv[1], "-ds") == 0){
        remove(SESSION_FILENAME);

    }else{
      puts("Ok, I don't know that do  you mean but take a look at this:");
      usage(argv[0]);
      return -1;
    }
    return 1;

  } else {
    puts("Missing arguments.");
    usage(argv[0]);
    return -1;
  }



  // Setting up everything we need
  char *PATTERN = argv[1];
  int PATTERN_LEN = strlen(PATTERN);
  int tracker[len];
  long double combinations = pow(PATTERN_LEN, len);
  int save_counter = 0;

  /*
    Just to be sure that the tracker
    starts everything at zero
  */
  for (int i=0; i<len; i++){
    tracker[i] = 0;
  }

  // Reload the last session if found
  reload_session(tracker, len);

  // The real trick.
  for (long double i=0; i<combinations; i++, save_counter++){
    print_gen(PATTERN, tracker, len);
    encrease(tracker, len, PATTERN_LEN);
    if (save_counter >= interval && interval != 0){
      save_progress(tracker, len);
      save_counter=0;
    }
  }
  // This removes the session file once everything is done.
  remove(SESSION_FILENAME);
}

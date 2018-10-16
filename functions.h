#include <stdio.h>

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
  if (fgets(container, (size_t)50, session) == NULL){
    fclose(session);
    return -1;
  }

  // Update the tracker (or index)
  for (int i=0; i<tracker_size; i++){
    tracker[i] = atoi(g_arg(container, i, '-'));
  }
  fclose(session);
  return 1;
}

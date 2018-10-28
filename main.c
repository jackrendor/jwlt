#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#include "sfunctions.h"
#include "functions.h"


int main(int argc, char **argv)
{
    int interval;
    int len;

    // Arguments check
    if (argc > 4){
        //If you supply more than 3 arguments, let's print out a funny error
        fprintf(stderr, "OK now tell me what I'm suppose to do with this %d extra argument(s)\n", argc-4);
        return -4;

    } else if(argc == 4){
        /*
          If the maximum argument was supplied, then
          check if the last two arguments are numbers
        */
        if (!isnumber(argv[2])) {
            fprintf(stderr, "[ERROR] Second argument must be a number.\n");
            return -2;
        }
        if (!isnumber(argv[3])) {
            fprintf(stderr, "[ERROR] Third argument must be a number.\n");
            return -3;
        }

        // Set values
        interval = atoi(argv[3]);
        len = atoi(argv[2]);

    } else if (argc == 3) {
        //Last argument must be an integer
        if (!isnumber(argv[2])) {
            fprintf(stderr, "[ERROR] Second argument must be a number.\n");
            return -2;
        }

        // Set value
        len = atoi(argv[2]);

    } else if (argc == 2) {
        /*
            If only one argument was supplied,
            check if it's a special function
        */
        if (strcmp(argv[1], "--delete-session") == 0 || strcmp(argv[1], "-ds") == 0){
            remove(SESSION_FILENAME);
        }else{
            fprintf(stderr, "Ok, I don't know that do  you mean but take a look at this:\n");
            usage(argv[0]);
            return -1;
        }
        return 1;
    } else {
        fprintf(stderr, "Missing arguments.\n");
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
    for (int i=0; i<len; i++)
        tracker[i] = 0;

    // Reload the last session if found
    if (reload_session(tracker, len) == 1)
        fprintf(stderr, "Session found and loaded.\n");

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

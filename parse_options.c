
/*Author: Tridib Banik, Student Number: 400514461, MacID: banikt 
 *This C program analyzes various arguments and set base, range mode, and range values.
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "convert.h"

// Usage message thrown to standard error.
void usage() {
    fprintf(stderr, "Usage: ./convert [-b BASE] [-r START FINISH]\n       1 < BASE < 37\n       START and FINISH are long integers\n");
}

// Help message to be shown after using --help flag
void help() {
    puts("Usage: ./convert [-b BASE] [-r START FINISH]\n       1 < BASE < 37\n       START and FINISH are long integers\n");
    puts("Example: If you want to convert a number 9289389 to a number of base 36, type ./convert -b 36 <Enter> 9289389 <Enter>\n");
    puts("Example: If you want to convert a group of numbers from -3 and 3 to numbers of base 2, type ./convert -b 2 -r -3 3 <Enter>\n");
    puts("If you want to exit the program, press ctrl-d\n");
}

void parse_options(int argc, char *argv[], int *base, long *start, long *finish, int *range_mode) {

    // Loop through each argument
    for (int i = 1; i < argc; i++) {
        if ((argc == 2) && (strcmp(argv[i], "--help")) == 0) {
            help();
            exit(0);
        }

        // If -r is used without using -b flag, this results in no output
        else if (strcmp(argv[i], "-r") == 0 && (i + 2 < argc) && (argc == 4)) {
            puts("<no output>");
            exit(0);
        }

        // Check if '-b' is followed by a valid base
        else if (strcmp(argv[i], "-b") == 0 && i + 1 < argc) {
            *base = atoi(argv[++i]);

            // Validate base range
            if (*base < MIN_BASE || *base > MAX_BASE) {
                usage();
                exit(1);
            }
        } 
        
        // Validate if '-r' has valid beginning and ending arguments
        else if (strcmp(argv[i], "-r") == 0 && i + 2 < argc) {
            *start = atol(argv[++i]);
            *finish = atol(argv[++i]);
            *range_mode = 1;
        } 
        
        // Print usage to stderr and exit with error code 1 if any invalid option is found
        else {
            usage();
            exit(1);
        }
    }
}




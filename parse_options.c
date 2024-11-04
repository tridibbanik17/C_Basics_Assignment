#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "convert.h"

/*
void usage() {
    puts("Usage: convert [-b BASE] [-r START FINISH]\n1 < BASE < 37\nSTART and FINISH are long integers\n");
}

void help() {
    puts("Usage: convert [-b BASE] [-r START FINISH]\n1 < BASE < 37\nSTART and FINISH are long integers\n");
    puts("Example: If you want to convert a number 9289389 to a number of base 36, type convert -b 36 <Enter> 9289389 <Enter>\n");
    puts("Example: If you want to convert a group of numbers from -3 and 3 to numbers of base 2, type convert -b 2 -r -3 3 <Enter>\n");
    puts("If you want to exit the program, type EOF <Enter>\n");
}
*/


void parse_options(int argc, char *argv[], int *base, long *start, long *finish, int *range_mode) {
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-b") == 0 && i + 1 < argc) {
            *base = atoi(argv[++i]);
            if (*base < MIN_BASE || *base > MAX_BASE) {
                fprintf(stderr, "Usage: convert [-b BASE] [-r START FINISH]\n1 < BASE < 37\nSTART and FINISH are long integers\n");
                exit(1);
            }
        } else if (strcmp(argv[i], "-r") == 0 && i + 2 < argc) {
            *start = atol(argv[++i]);
            *finish = atol(argv[++i]);
            *range_mode = 1;
        } else {
            fprintf(stderr, "Usage: convert [-b BASE] [-r START FINISH]\n1 < BASE < 37\nSTART and FINISH are long integers\n");
            exit(1);
        }
    }
}




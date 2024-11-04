#include <stdio.h>
#include <stdlib.h>
#include "convert.h"

int main(int argc, char *argv[]) {
    int base = DEFAULT_BASE;
    long start = 0, finish = 0;
    int range_mode = 0;

    parse_options(argc, argv, &base, &start, &finish, &range_mode);

    if (range_mode) {
        convert_range(start, finish, base);
    } else {
        char input[20];
        while (fgets(input, sizeof(input), stdin)) {
            char *endptr;
            long number = strtol(input, &endptr, 10);
            if (*endptr != '\n' && *endptr != '\0') {
                fprintf(stderr, "Error: Non-long-int token encountered.\n");
                exit(1);
            }
            convert_number(number, base);
            printf("\n");
        }
    }

    return 0;
}


/*Author: Tridib Banik, Student Number: 400514461, MacID: banikt 
 *This C program handles program entry, command-line parsing, and control flow.
 */


#include <stdio.h>
#include <stdlib.h>
#include "convert.h"


int main(int argc, char *argv[]) {
    // Default base if none specified by user
    int base = DEFAULT_BASE; 
    // Start and finish values for range, initialized to zero
    long start = 0, finish = 0;
    // Range is required to output converted numbers recursively. It is initialized to zero
    int range_mode = 0;

    parse_options(argc, argv, &base, &start, &finish, &range_mode);

    // If range mode is enabled, convert numbers from start to finish
    if (range_mode) {
        convert_range(start, finish, base);
    } else {
        // Read and convert individual numbers from stdin
        char input[20];

        // Read input line by line
        while (fgets(input, sizeof(input), stdin)) {

            // Pointer to determine where strtol finishes reading
            char *endptr;
            long number = strtol(input, &endptr, 10);

            // Check for non-numeric characters
            if (*endptr != '\n' && *endptr != '\0') {
                fprintf(stderr, "Error: Non-long-int token encountered.\n");
                // Exit with error code 1
                exit(1);
            }

            // Convert and output the converted number in the specified base
            convert_number(number, base);
            printf("\n");
        }
    }

    return 0;
}

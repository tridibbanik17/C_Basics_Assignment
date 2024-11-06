
/*Author: Tridib Banik, Student Number: 400514461, MacID: banikt 
 *This C program performs base conversion.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include "convert.h"

// Converts a single number to the specified base using recursion
void convert_number(long number, int base) {
    const char *digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // For negative integers
    if (number < 0) {
        putchar('-');
        number = -number;
    }
    if (number >= base) {
        convert_number(number / base, base);
    }

    // Output the rightmost digit
    putchar(digits[number % base]);
}

// Converts and prints all numbers in a range from 'start' to 'finish' in the specified base
void convert_range(long start, long finish, int base) {
    long step = (start < finish) ? 1 : -1;
    for (long i = start; (step > 0) ? i <= finish : i >= finish; i += step) {
        convert_number(i, base);
        printf("\n");
    }
}

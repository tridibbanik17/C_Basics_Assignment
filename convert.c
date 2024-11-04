#include <stdio.h>
#include <stdlib.h>
#include "convert.h"

void convert_number(long number, int base) {
    const char *digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (number < 0) {
        putchar('-');
        number = -number;
    }
    if (number >= base) {
        convert_number(number / base, base);
    }
    putchar(digits[number % base]);
}

void convert_range(long start, long finish, int base) {
    long step = (start < finish) ? 1 : -1;
    for (long i = start; (step > 0) ? i <= finish : i >= finish; i += step) {
        convert_number(i, base);
        printf("\n");
    }
}

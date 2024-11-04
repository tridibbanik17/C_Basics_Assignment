#ifndef CONVERT_H
#define CONVERT_H

#include <stdio.h>

#define MIN_BASE 2
#define MAX_BASE 36
#define DEFAULT_BASE 16

void parse_options(int argc, char *argv[], int *base, long *start, long *finish, int *range_mode);
void convert_number(long number, int base);
void convert_range(long start, long finish, int base);
int main(int argc, char *argv[]);

#endif

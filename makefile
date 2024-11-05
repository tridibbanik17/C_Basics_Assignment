# Makefile

CC=gcc
CFLAGS=-Wall -Wextra --coverage -std=c11

all: ctest

ctest: main.o convert.o parse_options.o
	$(CC) $(CFLAGS) -o ctest main.o convert.o parse_options.o

main.o: main.c convert.h
	$(CC) $(CFLAGS) -c main.c

convert.o: convert.c convert.h
	$(CC) $(CFLAGS) -c convert.c

parse_options.o: parse_options.c convert.h
	$(CC) $(CFLAGS) -c parse_options.c

clean:
	rm -f *.o ctest *.gcda *.gcno *.gcov

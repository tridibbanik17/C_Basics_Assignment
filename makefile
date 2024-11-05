# Makefile
CC=gcc
CFLAGS=-Wall -Wextra
TARGET=convert
TEST_TARGET=ctest

all: $(TARGET)

$(TARGET): main.c convert.c
	$(CC) $(CFLAGS) -o $(TARGET) main.c convert.c

$(TEST_TARGET): main.c convert.c
	$(CC) $(CFLAGS) --coverage -o $(TEST_TARGET) main.c convert.c

clean:
	rm -f $(TARGET) $(TEST_TARGET) *.gcno *.gcda *.gcov


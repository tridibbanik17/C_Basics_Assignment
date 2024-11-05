# Makefile
CC=gcc
CFLAGS=-Wall -Wextra
TARGET=convert
TEST_TARGET=ctest

all: $(TARGET)

# Compile to an executable called convert
$(TARGET): main.c convert.c
	$(CC) $(CFLAGS) -o $(TARGET) main.c convert.c

# Compile to an executable called ctest using the --coverage option
$(TEST_TARGET): main.c convert.c
	$(CC) $(CFLAGS) --coverage -o $(TEST_TARGET) main.c convert.c

clean:
	# Remove executable, coverage files and other redundant files
	rm -f $(TARGET) $(TEST_TARGET) *.gcno *.gcda *.gcov


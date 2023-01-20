# the compiler: gcc for C program
CC = gcc

# compiler flags:
#  -Wextra    turns on extra warnings
#  -Wall      turns on most, but not all, compiler warnings
CFLAGS  =  -Wall -Wextra

# the build target executable:
TARGET = are

all:
	$(CC) $(CFLAGS) main.c -o $(TARGET)

clean:
	$(RM) $(TARGET)

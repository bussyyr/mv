# Compiler
CC = gcc

# Compiler flags
CFLAGS = -g -Wall -std=gnu11

# Source files
SRC = src/mv_directory.c src/move_utils.c src/rename_file_directory.c

# Header files
INC = include/mv_directory.h include/move_utils.h

# Output executable
TARGET = mv

# Build target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $^

# Clean up build files
clean:
	rm -f $(TARGET)

# Phony targets
.PHONY: all clean
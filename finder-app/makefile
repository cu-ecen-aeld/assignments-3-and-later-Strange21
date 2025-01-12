# Makefile for "writer" application

# Variables
CROSS_COMPILE ?=
CC := $(CROSS_COMPILE)gcc
CFLAGS := -Wall -Werror -g
LDFLAGS :=

# Target application and object files
TARGET := writer
SRC := writer.c
OBJ := $(SRC:.c=.o)

# Default target to build the writer application
all: $(TARGET)

# Rule to build the target application
$(TARGET): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $^

# Rule to build object files
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Clean target to remove generated files
clean:
	rm -f $(TARGET) $(OBJ)

# Phony targets
.PHONY: all clean

CC = gcc
CFLAGS = -Wall -Wextra

# List all the source files in the current directory
SOURCES := $(wildcard *.c)
# Generate the corresponding object file names
OBJECTS := $(SOURCES:.c=.o)
# Generate the corresponding executable file names
EXECUTABLES := $(SOURCES:.c=)

.PHONY: all clean

all: $(EXECUTABLES)

# Rule to compile each source file into an object file
%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

# Rule to link each object file into an executable file
%: %.o
    $(CC) $(CFLAGS) $< -o $@

clean:
    rm -f $(OBJECTS) $(EXECUTABLES)
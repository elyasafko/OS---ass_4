# Compiler
CC = g++

# Compiler flags
CFLAGS = -pthread -Wall -Wextra

# Target executable
TARGET = my_program

# Source files
SRCS = main.cpp singleton.cpp guard.cpp

# Build target
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

# Clean target
clean:
	rm -f $(TARGET)

# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -g -O2 --coverage -pg -fprofile-arcs -ftest-coverage

# Target executable and source files
TARGET = graph_program
SRCS = main.cpp graph.cpp
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Link target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(TARGET) $(OBJS) *.gcno *.gcda *.gcov gmon.out coverage.info callgrind.out.*
	rm -rf out

# Phony targets
.PHONY: all clean

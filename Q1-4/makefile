# Define the compiler to use
CXX = g++

# Define the flags to pass to the compiler
CXXFLAGS = -Wall -Wextra -std=c++11 -g -O2 --coverage -pg

# Define the flags to pass to the linker
LDFLAGS = --coverage -pg

# Define the target executable
TARGET = graph_program

# Define the source files
SRCS = main.cpp graph.cpp

# Define the object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Rule to link the target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run gprof for profiling
profile: $(TARGET)
	./$(TARGET) 10 5 42
	gprof $(TARGET) gmon.out > analysis.txt

# Run gcov for code coverage
coverage: $(TARGET)
	./$(TARGET) 10 5 42
	gcov main.cpp graph.cpp
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory out

# Run Valgrind callgrind tool for call graph
valgrind_callgrind: $(TARGET)
	valgrind --tool=callgrind ./$(TARGET) 10 5 42

# Clean up build files
clean:
	rm -f $(TARGET) $(OBJS) *.gcno *.gcda *.gcov gmon.out coverage.info callgrind.out.*
	rm -rf out

# Phony targets
.PHONY: all clean valgrind_memcheck profile coverage valgrind_callgrind

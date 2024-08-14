CC=g++
CFLAGS=-Wall -pthread
DEPS = singleton.hpp guard.hpp
OBJ = main.o singleton.o guard.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o main

.PHONY: clean

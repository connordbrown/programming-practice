CXX = g++ # Compiler for C++
CXXFLAGS = -std=c++17 -Wall -Werror -Wpedantic

# runs for 'make all'
all: main

clean:
	rm *.o main

main: Pen.o
	$(CXX) $(CXXFLAGS) main.cpp Pen.o
	-o main

Pen.o: Pen.cpp
	$(CXX) $(CXXFLAGS) -c Pen.cpp
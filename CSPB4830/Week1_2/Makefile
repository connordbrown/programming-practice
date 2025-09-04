# This is an example make file

CXX = g++  # the compiler
CXXFLAGS = -std=c++17 -Wall -Werror -Wpedantic # flags for the compiler (use c++17 standards, turn on all optional warnings); add -ggdb if you want to use gdb to debug!

# runs for 'make all'
all: run_library

clean:
	rm *.o run_library

run_library: run_library.o Library.o
	$(CXX) $(CXXFLAGS) run_library.o Library.o -o run_library

run_library.o: run_library.cpp
	$(CXX) $(CXXFLAGS) -c run_library.cpp

Library.o: Library.cpp
	$(CXX) $(CXXFLAGS) -c Library.cpp
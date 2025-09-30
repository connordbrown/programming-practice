CXX = g++
CXXFLAGS = -std=c++17 -Wall -Werror -Wpedantic

all: tree_main

clean: 
	rm *.o tree_main

tree_main: tree_main.o Tree.o
	$(CXX) $(CXXFLAGS) tree_main.o Tree.o -o tree_main

tree_main.o: tree_main.cpp
	$(CXX) $(CXXFLAGS) -c tree_main.cpp

Tree.o: Tree.cpp
	$(CXX) $(CXXFLAGS) -c Tree.cpp
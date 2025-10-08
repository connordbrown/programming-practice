CXX = g++
CXXFLAGS = -std=c++17 -Wall -Werror -Wpedantic

all: main

clean: 
	rm *.o main

main: main.o Earth.o
	$(CXX) $(CXXFLAGS) main.o Earth.o -o main

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Earth.o: Earth.cpp
	$(CXX) $(CXXFLAGS) -c Earth.cpp
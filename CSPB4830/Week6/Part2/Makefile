CXX = g++
CXXFLAGS = -std=c++17 -Wall -Werror -Wpedantic

all: main

clean: 
	rm *.o main

main: main.o Avatar.o Characteristic.o
	$(CXX) $(CXXFLAGS) main.o Avatar.o Characteristic.o -o main

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Avatar.o: Avatar.cpp
	$(CXX) $(CXXFLAGS) -c Avatar.cpp

Characteristic.o: Characteristic.cpp
	$(CXX) $(CXXFLAGS) -c Characteristic.cpp
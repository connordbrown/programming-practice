CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wpedantic #-Werror 

all: maze

clean:
	rm *.o maze

maze: maze.o Tile.o TileType.o
	$(CXX) $(CXXFLAGS) maze.o Tile.o TileType.o -o maze	

maze.o: maze.cpp
	$(CXX) $(CXXFLAGS) -c maze.cpp

Tile.o: Tile.cpp
	$(CXX) $(CXXFLAGS) -c Tile.cpp

TileType.o: TileType.cpp
	$(CXX) $(CXXFLAGS) -c TileType.cpp
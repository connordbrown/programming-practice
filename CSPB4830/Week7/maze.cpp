#include <iostream>
#include <vector>
#include "TileType.h"
#include "Tile.h"

// Name: Connor Brown

// questions 1 and 2 in Tile.h
// question 3 in TileType.h
// question 4 in TileType.cpp
// questions 5 and 6 in Tile.cpp
// questions 8, 9, 10 and 11 below


// Factory method to create our shared TileType instances
TileType* getTileType(int index)
{
    // we will use a vector to store the different TileType objects
    static std::vector<TileType*> types;

    // 7) hard coded to help you get started; add the remaining Tile types or implement as a factory class or better. Upto you
    if (types.empty()) {
        //types.push_back(new TileType("Wall", "🚧  ", false, false)); // 0

    }

    // 8) return the appropriate pointers
    return nullptr;
    // Hint: what should you return if index is invalid?
}

int main()
{
    // static maze layout now with integers that we will connect to TileType
    int layout[4][4] = {
      {3, 1, 0, 0},
      {0, 1, 1, 0},
      {4, 2, 1, 0},
      {0, 0, 1, 2}
    };
    

    Tile* maze[4][4];

    // create tiles to use flyweight via the factory method defined above
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            //maze[i][j] = new Tile(i, j, // 9) call your factory method); // edit this specifically
        }
    }

    // can remain the same but you are welcome to modify
    std::cout << "Maze:" << std::endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << *maze[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    // 10) delete all pointers
    return 0;
}

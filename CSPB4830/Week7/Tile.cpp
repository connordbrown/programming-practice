#include <iostream>
#include <string>

#include "Tile.h"

Tile::Tile(int x, int y, TileType* type) : x_(x), y_(y), type_(type) {}

// 5) implement getters

// 6) fix the following function as emoji_ is no longer in Tile class
std::ostream& operator<<(std::ostream& os, const Tile& tile) {
    os << tile.emoji_();
    return os;
}

#include <iostream>
#include <string>

#include "Tile.h"

Tile::Tile(int x, int y, TileType* type) : x_(x), y_(y), type_(type) {}

// 5) implement getters
int Tile::get_x() {
    return this->x_;
}

int Tile::get_y() {
    return this->y_;
}

TileType* Tile::get_tile_type() {
    return this->type_;
}

// 6) fix the following function as emoji_ is no longer in Tile class
std::ostream& operator<<(std::ostream& os, const Tile& tile) {
   // os << tile.emoji_();
    return os;
}

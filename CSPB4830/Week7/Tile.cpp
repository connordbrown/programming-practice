#include <iostream>
#include <string>

#include "Tile.h"

Tile::Tile(int x, int y, TileType* type) : x_(x), y_(y), type_(type) {}

// 5) implement getters
int Tile::get_x() const {
    return this->x_;
}

int Tile::get_y() const {
    return this->y_;
}

TileType* Tile::get_tile_type() const {
    return this->type_;
}

// 6) fix the following function as emoji_ is no longer in Tile class
std::ostream& operator<<(std::ostream& os, const Tile& tile) {
    os << tile.get_tile_type()->get_emoji();
    return os;
}

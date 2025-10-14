#include <iostream>
#include <string>
#include "TileType.h"

// 4) implement methods
TileType::TileType(std::string emoji, bool walkable, bool dangerous): emoji_(emoji), walkable_(walkable), dangerous_(dangerous) {}

std::string TileType::get_emoji() {
    return this->emoji_;
}

bool TileType::get_walkable() {
    return this->walkable_;
}

bool TileType::get_dangerous() {
    return this->dangerous_;
}
#include <iostream>
#include <string>
#include "TileType.h"

// 4) implement methods
TileType::TileType(std::string name, std::string emoji, bool walkable, bool dangerous): name_(name), emoji_(emoji), walkable_(walkable), dangerous_(dangerous) {}

std::string TileType::get_name() {
    return this->name_;
}

std::string TileType::get_emoji() {
    return this->emoji_;
}

bool TileType::get_walkable() {
    return this->walkable_;
}

bool TileType::get_dangerous() {
    return this->dangerous_;
}
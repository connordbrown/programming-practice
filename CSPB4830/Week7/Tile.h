#ifndef TILE_H_
#define TILE_H_

#include "TileType.h"

class Tile {
  public:
    Tile(int x, int y, TileType* type);
    // 2) add getters

    friend std::ostream& operator<<(std::ostream& os, const Tile& tile);

  private:
    int x_, y_;
    TileType* type_;
    // 1) Move the following attributes into a new class named TileType
      // std::string emoji_; // each tile has its own emoji
      // bool walkable_;
      // bool dangerous_;
};

#endif // TILE_H_

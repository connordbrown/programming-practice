#ifndef TILE_TYPE_H_
#define TILE_TYPE_H_

// 3) design the TileType class

class TileType {
  public:
    TileType(std::string name, std::string emoji, bool walkable, bool dangerous);
    std::string get_name();
    std::string get_emoji();
    bool get_walkable();
    bool get_dangerous();

  private:
    std::string name_;
    std::string emoji_; // each tile has its own emoji
    bool walkable_;
    bool dangerous_;
};

#endif // TILE_TYPE_H_

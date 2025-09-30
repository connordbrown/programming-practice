#ifndef TREE_H
#define TREE_H

class Tree
{
  public:
    Tree() {number_tree_instances++;}
    virtual void Seed() { number_seeds_ += 1; };
    int get_number_seeds() { return number_seeds_; }
    bool operator==(const Tree &other) const;
    static int number_tree_instances;

  protected:
    static int number_seeds_;
};

#endif // TREE_H

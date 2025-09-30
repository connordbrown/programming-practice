#include <vector>

#include "Tree.h"

// no trees to begin with
int Tree::number_seeds_ = 0;
int Tree::number_tree_instances = 0;

bool Tree::operator==(const Tree& other) const {
    return (this == &other);
}

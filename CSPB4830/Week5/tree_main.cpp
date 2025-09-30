#include <iostream>

#include "Tree.h"

// Name: Connor Brown


int main() {
    Tree oak;
    std::cout << "Number of seeds: " << oak.get_number_seeds() << std::endl;

    // 0) Attempt to directly access the number_seeds_ static field here. Can you do so? why/why not?
    // std::cout << Tree::number_seeds_ << std::endl;
    // No, because number_seeds_ is a private member of Tree class.

    // 1) Instantiate another Tree object here
    Tree ash;

    // 2) Call get_number_seeds() from your tree object instantiated at #1
    std::cout << "Number of seeds: " << ash.get_number_seeds() << std::endl;

    // 3) Test to see whether pointers to your two Tree objects are equal. Implement operator== method in Tree.cpp
    std::cout << (&oak == &ash) << std::endl; // Not equal

    // 4) Call Seed() from the Tree object oak and Seed() from the Tree object instantiated at #1
    // Does changing the value of number_seeds_ from one tree object affect what you see from the other Tree object by calling get_number_seeds()?
    oak.Seed();
    std::cout << "Number of seeds: " << oak.get_number_seeds() << std::endl;
    std::cout << "Number of seeds: " << ash.get_number_seeds() << std::endl;
    ash.Seed();
    std::cout << "Number of seeds: " << oak.get_number_seeds() << std::endl;
    std::cout << "Number of seeds: " << ash.get_number_seeds() << std::endl;
    // YES, they share the same value!

    // 5) Add a subclass of the Tree object.
    // Your subclass should overwrite the Seed() method so that when your subclass uses Seed(), the number_seeds_ should increase by two.
    // Write adequate code to experiment how the static field changes when calling Seed() with your regular Trees versus with the derived class that you implemented.
    // Don't forget the keyword virtual and remember that you shouldn't add a new field to your Tree subclass to accomplish this!

    // The static field increases by one for Seed() calls by base class, and increases by two for Seed() calls by subclass.

    class Conifer: public Tree
    {
    public:
        void Seed() override { number_seeds_ += 2; };
    private:
        std::string cone_type_;
    };

    Conifer pine;
    pine.Seed();
    std::cout << "Number of seeds: " << pine.get_number_seeds() << std::endl;
    oak.Seed();
    std::cout << "Number of seeds: " << oak.get_number_seeds() << std::endl;
    std::cout << "Number of seeds: " << ash.get_number_seeds() << std::endl;
    ash.Seed();
    std::cout << "Number of seeds: " << oak.get_number_seeds() << std::endl;
    std::cout << "Number of seeds: " << ash.get_number_seeds() << std::endl;
    pine.Seed();
    std::cout << "Number of seeds: " << pine.get_number_seeds() << std::endl;
    std::cout << "Number of seeds: " << oak.get_number_seeds() << std::endl;
    std::cout << "Number of seeds: " << ash.get_number_seeds() << std::endl;

    // 6) Add a public static variable to your Tree class that counts how many Trees (and Tree subclasses) have been instantiated.
    // Can you access this via a Tree instance? Can you access it without an instance of Tree?
    // e.g.
    // std::cout << Tree::variable_name << std::endl;
    // std::cout << instance.variable_name << std::endl;
    std::cout << Tree::number_tree_instances << std::endl;
    std::cout << pine.number_tree_instances << std:: endl;

    // Yes, both are valid ways to access the counter variable. It first has to be initialized in Tree implementation file.
}


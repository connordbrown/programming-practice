#include <iostream>
#include <string>
#include <vector>


// 1) implement two functions
// AddToValues(std::vector<int> v1, int v2)
void AddToValues(std::vector<int>& v1, int v2) {
    for (unsigned int i = 0; i < v1.size(); ++i) {
        v1.at(i) += v2;
    }
}

// AddToValues(std::vector<double> v1, double v2)
void AddToValues(std::vector<double>& v1, double v2) {
    for (unsigned int i = 0; i < v1.size(); ++i) {
        v1.at(i) += v2;
    }
}

// 2) Do your AddToValues functions have return values? why/ why not?
// Answer: No, because passing vectors by value can be computationally expensive. 
//         It's more efficient to pass references and modify originals (unless otherwise specified).


int main() {
    // 3) Instantiate an int vector
    std::vector<int> int_vec = {1, 2, 3, 4, 5, 6};

    // 4) call AddToValues, passing in your int vector and another int.
    AddToValues(int_vec, 10);

    // 5) compile this file to object code
    // g++ -std=c++17 -Wall exercise_1.cpp -o exercise_1.o

    // 6) run the command: nm -C exercise_1.o | grep "AddToValues"
    // How many versions of the AddToValues function are in the
    // compiled object code? Copy + paste the relevant lines here:
    //  There are two versions:
    //      00000001000020b8 T AddToValues(std::__1::vector<double, std::__1::allocator<double>>&, double)
    //      0000000100001fa8 T AddToValues(std::__1::vector<int, std::__1::allocator<int>>&, int)
    //
    // If the -C flag isn't working, you can omit it and still complete the exercise
    // -C flag makes the output easier to read but isn't strictly necessary
}

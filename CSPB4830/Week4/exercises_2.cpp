#include <iostream>
#include <string>
#include <vector>


// we'd like to write a function that is applicable to many types but we don't want to copy paste everything

// For example, here is a templated Add function
template <typename T>
T Add(T v1, T v2) {
    return v1 + v2;
}

// 7) implement a templated version of AddToValues, "AddToValues2".
template <typename T>
void AddToValues2(std::vector<T>& v1, T v2) {
    for (unsigned int i = 0; i < v1.size(); ++i) {
        v1.at(i) += v2;
    }
}


int main() {
    // 8) call AddToValues2, passing in an int vector and another int.
    std::vector<int> int_vec = {1, 2, 3, 4, 5, 6};

    // 4) call AddToValues, passing in your int vector and another int.
    AddToValues2<int>(int_vec, 10);

    // 9) compile this file to object code
    // g++ -Wall -std=c++17 exercises_2.cpp -o exercises_2.o
    // then run: nm -C exercises_2.o | grep "AddToValues2"
    // How many versions of the AddToValues2 function are in the
    // compiled object code? Copy + paste the relevant lines here:

    // Just one
    // 00000001000021d8 T void AddToValues2<int>(std::__1::vector<int, std::__1::allocator<int>>&, int)


    // 10) call AddToValues2, passing in a vector of a non-int type and a value that you can add
    // successfully to the elements
    std::vector<double> double_vec = {1.4, 2.6, 3.1, 4.0, 5.6, 6.3};
    AddToValues2<double>(double_vec, 2);

    // 11) compile this file to object code
    // g++ -Wall -std=c++17 exercises2.cpp -c
    // then run: nm -C exercises2.o | grep "AddToValues2"
    // How many versions of the AddToValues2 function are in the
    // compiled object code? Copy + paste the relevant lines here:

    // Two
    // 0000000100000a48 T void AddToValues2<double>(std::__1::vector<double, std::__1::allocator<double>>&, double)
    // 0000000100000984 T void AddToValues2<int>(std::__1::vector<int, std::__1::allocator<int>>&, int)

    // 12) Experiment to find calls to this function that you would like to work but that do not yet work.
    // for each function call that doesn't work, comment about what type of error is produced.

        // std::vector<std::string> string_vec = {"I", "am", "a", "string"};
        // AddToValues2<std::string>(string_vec, 2);
        // "no instance of function template "AddToValues2" matches the argument list"
        // - need to add a second typename U to typename list, so it knows it can add numbers to strings

    // 13) Create a struct that has an int field. Instantiate a vector of these structs.
    // Instantiate another instance of this struct.
    struct int_struct {
        int num1;

        bool operator+=(int_struct d) {
            return (num1 += d.num1);
        }
    };

    std::vector<int_struct> struct_vec = {int_struct{3}, int_struct{1}, int_struct{8}};
    int_struct s2 = {16};

    // 14) Call AddToValues2 w/ the vector of structs and single struct from #12
    AddToValues2(struct_vec, s2);

    // Is there an error? If yes, what is it?
    //
    // Answer: Yes, no viable overloaded '+='

    // 15) If there was an error, attempt to fix it.

    // See modification to int_struct above:
    //         bool operator+=(int_struct d) {
    //         return (num1 += d.num1);
    //         }
}

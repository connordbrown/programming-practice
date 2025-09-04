#include <iostream>
#include <string>
#include <vector>

// 1) Write a function that demonstrates whether ints are pass-by-value or pass-by-reference
// (do not use pointers or c++ references in this function)
// Answer:
void updateInt(int a)
{
  a = 10;
  std::cout << "Inside updateInt: " << a << std::endl;
}


// 2) Write a function that demonstrates whether strings (std::string) are pass-by-value or pass-by-reference
// (do not use pointers or c++ references in this function)
// Answer:
void updateString(std::string s) 
{
  s = "Updated string";
  std::cout << "Inside updateString: " << s << std::endl;
}


// 3) Write a function that demonstrates whether arrays are pass-by-value or pass-by-reference
// recall: to initialize an array -- type name[] = {comma separated elements};
// (do not use pointers or c++ references in this function)
// Answer:
void updateArray(int arr[])
{
  arr[0] = 100;
  std::cout << "Inside updateArray: " << arr[0] << std::endl;
}


// 4) Write a function that demonstrates whether vectors are pass-by-value or pass-by-reference
// (do not use pointers or c++ references in this function)
// Answer:
void updateVector(std::vector<int> vec)
{
  vec.at(0) = 100;
  std::cout << "Inside updateVector: " << vec.at(0) << std::endl;
}

int main()
{

  // testing if int is pass by value or pass by reference
  int a = 5;
  std::cout << "Before: " << a << std::endl;
  updateInt(a);
  std::cout << "After: " << a << std::endl << std::endl;

  // code to call your functions goes here.
  // you may find it useful to print out values in main and inside the function to appropriately demonstrate whether the given type is pass-by-value or pass-by-reference

  // testing if string is pass by value or pass by reference
    std::string s = "Original string";
    std::cout << "Before: " << s << std::endl;
    updateString(s);
    std::cout << "After: " << s << std::endl << std::endl;

  // testing if array is pass by value or pass by reference
    int arr[] = {1, 2, 3, 4, 5};
    std::cout << "Before: " << arr[0] << std::endl;
    updateArray(arr);
    std::cout << "After: " << arr[0] << std::endl << std::endl;

  // testing if vector is pass by value or pass by reference
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::cout << "Before: " << vec[0] << std::endl;
    updateVector(vec);
    std::cout << "After: " << vec[0] << std::endl << std::endl;

  return 0;
}

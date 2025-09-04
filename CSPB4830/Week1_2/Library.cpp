#include <iostream>
#include <string>
#include <vector>

#include "Library.h"


//  Zero argument constructor initializes a library with a shelf but no books.
Library::Library()
{
  std::vector<Book> tmp;
  shelf_ = tmp;  // initialize my shelf
}


//  Prints out each book in the library, one per line to cout
void Library::PrintBooks()
{
  for (Book b : shelf_) {
    std::cout << b.title << " by " << b.author << std::endl;
  }
}

void Library::Donate(const Book b)
{
  this->shelf_.push_back(b);
}

void Library::Donate(const Book b, const int num_copies)
{
  for (unsigned int i = 0; i < num_copies; ++i) {
    this->shelf_.push_back(b);
  }
}

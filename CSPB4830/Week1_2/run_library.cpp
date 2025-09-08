#include <iostream>
#include <vector>
#include "Library.h"

// Name(s): Connor Brown
//
// Complete numbered coding tasks.
// Answer the questions with "Answer: " in the comments by writing your answer in the comments.
// some experiments might result in non-running/non-compiling code. Leave these experiments in, but comment them out.
// Turn in run_library.cpp, Library.h, Library.cpp and a Makefile
// make sure to leave a comment above with your name

int main()
{
  // 1) Instantiate a couple Books. Set their fields equal to some values.
  // Print out the values of the books' fields.

  Book book1 = {"Moby Dick", "Herman Melville"};
  Book book2 = {"Frankenstein", "Mary Shelley"};

  std::cout << book1 << std::endl;

  std::cout << "Title: " << book1.title << std::endl;
  std::cout << "Author: " << book1.author << std::endl;

  std::cout << "Title: " << book2.title << std::endl;
  std::cout << "Author: " << book2.author << std::endl;

  // 2) Instantiate a Library.

  Library myLibrary;

  // 3) Add a void Donate(Book b) method to your Library class.
  // Your Library should store the new book at the end of its shelf.

  // Answer:
  // void Library::Donate(Book b)
  // {
  //   this->shelf_.push_back(b);
  // }

  // 4) Donate one of the Books that you instantiated to your Library.
  //
  // Answer:

  myLibrary.Donate(book1);

  // 5) Print out the books in the Library (use the given PrintBooks method)

  myLibrary.PrintBooks();

  // 6) Change the title and/or author of the book that you donated to something different.
  // Print out the new book information, then print out the books in your
  // Library. Did changing the Book information change it in your Library?
  //
  // Answer (and your hypothesis for why/why not): No, because the book was already donated to and stored in the library before
  // I changed its title and author.
  book1.title = "Green Eggs and Ham";
  book1.author = "Dr. Seuss";

  std::cout << "Title: " << book1.title << std::endl;
  std::cout << "Author: " << book1.author << std::endl;

  myLibrary.PrintBooks();

  // 7) Create two Books that are separate structs (not pointers or references)
  // but that have the same information.
  // use the == operator to test if they are equal. What happens?
  // if it succeeds, are these equal?
  //
  // Answer: Does not compile. == operator does not currently work for structs.
  Book book3 = {"Pride and Prejudice", "Jane Austen"};
  Book book4 = {"Pride and Prejudice", "Jane Austen"};
  // std::cout << (book3 == book4) << std::endl;

  // 8) Create two Book references to your Books from # 7.
  // use the == operator to test if they are equal. What happens?
  // if it succeeds, are these equal?
  //
  // Answer: Does not compile. == operator does not currently work for references.
  Book& bookref1 = book3;
  Book& bookref2 = book4;
  // std::cout << (bookref1 == bookref2) << std::endl;

  // 9) Create two Book pointers to your Books from # 7.
  // use the == operator to test if they are equal. What happens?
  // if it succeeds, are these equal?
  //
  // Answer: Compiles and runs. Output: FALSE. Book pointers are not equal - point to different memory locations
  Book* bookPtr1 = &book3;
  Book* bookPtr2 = &book4;
  std::cout << (bookPtr1 == bookPtr2) << std::endl;

  // 10) Add a void Donate(Book b, int num_copies) method to your Library class.
  // your Library should add num_copies of Book b to its shelf.

  // Answer:
  // void Library::Donate(Book b, int num_copies)
  // {
  //  for (unsigned int i = 0; i < num_copies; ++i) {
  //    this->shelf_.push_back(b);
  //   }
  // }

  // 11) Finally, if you reach this far, work on finding a solution to making it so
  // that you would be able to do any of the comparisons from # 7, 8, and 9

  // Answer: overload equality operator (==) in Book struct.
  // bool operator==(const Book& other) const {
  //   return (title == other.title && author == other.author);
  // }
  // Now, 7, 8, and 9 will work. It is a way of saying they are different copies of a book containing the same information.
  std::cout << (book3 == book4) << std::endl;
  std::cout << (bookref1 == bookref2) << std::endl;
}

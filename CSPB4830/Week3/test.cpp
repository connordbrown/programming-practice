#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "functions_to_implement.cpp"
#include <vector>

TEST_CASE ( "Factorials are computed", "[factorial]") // tag
{
  CHECK( Factorial(0) == 1 ); // assertion
  REQUIRE( Factorial(1) == 1 );
  REQUIRE( Factorial(2) == 2 );
  REQUIRE( Factorial(3) == 6 );
  REQUIRE( Factorial(10) == 3628800 );
}

TEST_CASE("incrementing values in integer vector", "[addN]")
{
	std::vector<int> v{1,2,3,5,6,7,8,10};

	SECTION("checking with +ve n")
  {
		int n=5;
		std::vector<int> res = AddN(v, n);
		srand(time(NULL));
		int random = rand()%v.size();
		REQUIRE(v.size() == res.size());
		REQUIRE( res[0] == 6 );
		REQUIRE( res[v.size()-1] == 15 );
		REQUIRE(res[random] == v[random]+n);
	}
	SECTION("checking with -ve n")
  {
		int n=-5;
		std::vector<int> res = AddN(v, n);
		srand(time(NULL));
		int random = rand()%v.size();
		REQUIRE(v.size() == res.size());
		REQUIRE( res[0] == -4 );
		REQUIRE( res[v.size()-1] == 5 );
		REQUIRE(res[random] == v[random]+n);
	}
}

TEST_CASE("splitting string on separator into vector of strings", "[Split]")
{
	std::string s = ",This string, written for testing, but not for clarity, is hard to read.,";

	std::vector<std::string> v = {"", "This string", " written for testing", " but not for clarity", " is hard to read."};

	std::vector<std::string> test_vec = Split(s, ",");
	REQUIRE(test_vec == v);
}

TEST_CASE("removing the first occurrence of second string from first string", "[RemoveFirstSubstring]")
{
	std::string s1 = "I willfully will write a will.";
	std::string s2 = "will willfully wrote a will.";
	std::string s3 = "will";

	std::string test1 = RemoveFirstSubstring(s1, s3);
	REQUIRE(test1 == "I fully will write a will.");

	std::string test2 = RemoveFirstSubstring(s2, s3);
	REQUIRE(test2 == " willfully wrote a will.");
}

TEST_CASE("joining all strings in a vector together using glue string in between them", "[Join]")
{
	std::vector<std::string> v1 = {"This string", " written for testing", " but not for clarity", " is hard to read."};
	std::vector<std::string> v2 = {"I", " (name)", " am writing a short", " short", " string."};

	std::string test1 = Join(v1, ",");
	REQUIRE(test1 == "This string, written for testing, but not for clarity, is hard to read.");

	std::string test2 = Join(v2, ",");
	REQUIRE(test2 == "I, (name), am writing a short, short, string.");
}

TEST_CASE("creating a vector with true for numbers less than given value and false for those greater than or equal to value", "[LessMask]")
{
	std::vector<double> num_vec = {1.0, 2.5, 3, 4.8, 7, 9.1, 10};
	double less_val = 4.8;
	std::vector<bool> test_vec = {true, true, true, false, false, false, false};

	std::vector<bool> test = LessMask(num_vec, less_val);
	REQUIRE(test.size() == test_vec.size());
	REQUIRE(test == test_vec);
}

TEST_CASE("takes two vectors of integers, removes elements from first vector if they are also in second vector", "[MatchVectors]")
{
	std::vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::vector<int> b = {1, 2, 8, 9, 10, 11, 12, 13};
	std::vector<int> test_vec = {3, 4, 5, 6, 7};

	std::vector<int> test = MatchVectors(a, b);
	REQUIRE(test == test_vec);
}
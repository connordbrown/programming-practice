#include <iostream>
#include "Earth.h"

// Name: Connor Brown

int main(int argc, char **argv)
{
  // 0) Implement your Earth's constructor in Earth.cpp

  // 1) Get an instance of your earth object
	Earth &e = Earth::GetInstance();

  // 2) Get another instance of your earth object
  Earth &e2 = Earth::GetInstance();

  // 3) Test to see if the two Earth instances from #1 and #2 are stored at the same location in memory.
  std::cout << "Address of e: " << &e << std::endl;
  std::cout << "Address of e2: " << &e2 << std::endl;
  // Yes, they are at same memory location.

  // 3) Call IncreasePopulation from one of your Earth instances.
	// Can you see this change from your other Earth instance?
  e.IncreasePopulation();
  std::cout << e2.get_population() << std::endl;
  // Yes, change is visible in other Earth instance.

  // 4) Create a public field in your Earth object. Do you need an instance of an Earth object to access this field?
  std::cout << "Number of continents: " << Earth::NUM_CONTINENTS << std::endl;
  std::cout << "Number of moons: " << Earth::NUM_MOONS << std::endl;
  // No, as long as the field is static.

	return 0;
}

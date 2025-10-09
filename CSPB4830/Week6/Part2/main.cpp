#include <iostream>
#include <vector>
#include "Characteristic.h"
#include "Avatar.h"

// Name: Connor Brown


int main()
{
  // Part 1 (factory)
  // Questions 0, 1, 2, 3 are in Characteristic.h

  // 4) get pointers to one of each type of your Characteristic objects via your CharacteristicFactory. // Then, call the Characteristic's get_count method to see how many Characteristic objects have been instantiated.
  Characteristic* strength = CharacteristicFactory::GetStrength();
  Characteristic* intelligence = CharacteristicFactory::GetIntelligence();
  Characteristic* wisdom = CharacteristicFactory::GetWisdom();

  std::cout << "Objects created: " << Characteristic::get_count() << std::endl;

  // 5) are your CharacteristicFactory's Get____() methods static or non-static? Do you think that they should be one or the other? Justify your answer.

  // They are static methods. I think they should be static, because they abstract away/provide a wrapper for the implementation details of the Characteristic class.
  // They are not maintaining class attributes/state, they are just creating objects. Also, I do not need to create an object to create other objects. It feels simpler.

  // If your methods are static, what would change if they were non-static?

  // A CharacteristicFactory object would have to be instantiated, and then the methods called on the object.

  // If they are non-static, what would change if they were static?

  // Would no longer need a CharacteristicFactory object. Methods could be called using the class itself.

  // 6) Feel free to create more Avatars here
  Avatar thor(23);
  Avatar loki(21);

  // 7) Add a few characteristics to your Avatars. Test out the TransferCharacteristics method.
  thor.AddCharacteristic(CharacteristicFactory::GetStrength());
  thor.AddCharacteristic(CharacteristicFactory::GetWisdom());

  loki.AddCharacteristic(CharacteristicFactory::GetIntelligence());
  loki.AddCharacteristic(CharacteristicFactory::GetWisdom());

  std::cout << "Thor given characteristics:" << std::endl;
  for (Characteristic* c : thor.get_characteristics())
  {
    std::cout << *(c) << std::endl;
  }

  std::cout << "Loki given characteristics:" << std::endl;
  for (Characteristic* c : loki.get_characteristics())
  {
    std::cout << *(c) << std::endl;
  }

  std::cout << std::endl;


  // Part 2 (prototype)
  // // Questions 8, 9 and 10 are in Avatar.h
  // 11) Create some new Avatar * objects by using the Avatar's Clone() method. Does this method use dynamic dispatch?
  // Answer: Yes
  // How did you test this?

  // The Avatar clones only inherit hereditary characteristics, as seen by the output of the following code.
  Avatar* thor_clone = thor.Clone();
  Avatar* loki_clone = loki.Clone();

  std::cout << "Thor clone characteristics:" << std::endl;
  for (Characteristic* c : (*thor_clone).get_characteristics())
  {
    std::cout << *(c) << std::endl;
  }

  std::cout << "Loki clone characteristics:" << std::endl;
  for (Characteristic* c : (*loki_clone).get_characteristics())
  {
    std::cout << *(c) << std::endl;
  }

  std::cout << std::endl;

  // However, the Human clones only inherit non-hereditary characteristics, as seen by the output of the following code.
  Human steve(25);
  steve.AddCharacteristic(CharacteristicFactory::GetStrength());
  steve.AddCharacteristic(CharacteristicFactory::GetIntelligence());

  std::cout << "Steve given characteristics:" << std::endl;
  for (Characteristic* c : steve.get_characteristics())
  {
    std::cout << *(c) << std::endl;
  }

  Human* steve_clone = steve.Clone();

  std::cout << "Steve clone characteristics:" << std::endl;
  for (Characteristic* c : (*steve_clone).get_characteristics())
  {
    std::cout << *(c) << std::endl;
  }




  // If you finish:
  // -------------
  // 12) Write a new function in this file void EvaluateSurvival(Avatar *a) (not associated with any classes) that takes an avatar and tests how well an avatar would survive in different conditions based on its characteristics
  // You have complete creative freedom here. Feel free to add methods to the Characterictic/Avatar classes.
  // (The only requirements are the function definition and that you must call Clone() within that function).
  // Call your EvaluateSurvival function as many times as is necessary for your experiments.
}

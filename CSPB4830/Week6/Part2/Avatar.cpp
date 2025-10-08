#include <string>
#include <vector>

#include "Characteristic.h"
#include "Avatar.h"


void Avatar::TransferCharacteristics(Avatar* otherAvatar)
{
  srand(time(0));
  for (Characteristic* c : characteristics_)
  {
    if (c->get_isTransferable())
    {
      double rand_chance = static_cast <double> (rand()) / static_cast <double> (RAND_MAX);
      if (rand_chance < c->get_adaptability())
      {
        otherAvatar->AddCharacteristic(c);
      }
    }
  }
}

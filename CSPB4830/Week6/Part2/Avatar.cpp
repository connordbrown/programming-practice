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

Avatar* Avatar::Clone()
{
  Avatar* clone = new Avatar(0);

  // search for inherited characteristics
  for (Characteristic* c : this->characteristics_) {
    if (c->get_isInherited()) {
      // make deep copy of inherited characteristic
      Characteristic* inherited_copy = new Characteristic(*c);
      // give inherited characteristic to clone
      clone->AddCharacteristic(inherited_copy);
    }
  }

  return clone;
}

Human* Human::Clone()
{
  Human* clone = new Human(0);

  // search for non-inherited characteristics
  for (Characteristic* c : this->get_characteristics()) {
    if (!(c->get_isInherited())) {
      // make deep copy of non-inherited characteristic
      Characteristic* inherited_copy = new Characteristic(*c);
      // give non-inherited characteristic to clone
      clone->AddCharacteristic(inherited_copy);
    }
  }

  return clone;
}

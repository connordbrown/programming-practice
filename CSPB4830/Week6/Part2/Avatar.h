#ifndef AVATAR_H
#define AVATAR_H

#include <vector>
#include "Characteristic.h"

class Avatar
{
  public:
    Avatar(int currentAge) : currentAge_(currentAge) {}

    int get_currentAge() const { return currentAge_; }

    void age(int years) { currentAge_ += years; }

    std::vector<Characteristic *> get_characteristics() const { return characteristics_; }

    void AddCharacteristic(Characteristic *c) { characteristics_.push_back(c); }
    void TransferCharacteristics(Avatar* otherAvatar);

    // 8) Create a virtual Avatar* Clone() method.
    // When an avatar is cloned, the clone starts at age 0
    // Characteristics that are hereditary should be inherited.
    virtual Avatar* Clone();

  private:
    int currentAge_;  // Age of the Avatar
    std::vector<Characteristic *> characteristics_;  // Collection of characteristics
};

// 9) Create 1 subclass of Avatar. For this subclass, make its cloning behavior slightly different.
// For instance, some Cloned avatars might also inherit non-hereditary characteristics.
// It's up to you!

class Human : public Avatar {
  public:
    // constructor
    Human(int currentAge) : Avatar(currentAge) {}

    // overrride virtual clone method
    Human* Clone() override;
};

// 10) In your main.cpp, instantiate your subclass. (the rest of the work for this part of the exercise will happen in main.)

#endif // AVATAR_H

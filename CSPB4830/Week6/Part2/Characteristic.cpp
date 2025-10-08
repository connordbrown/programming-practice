#include <iostream>
#include <string>

#include "Characteristic.h"

int Characteristic::field_counter_ = 0;

std::ostream& operator<<(std::ostream &os, const Characteristic &c) {
    os << c.get_characteristicName();
    // TODO: print out more information if you want to
    return os;
}

Characteristic* CharacteristicFactory::GetStrength() {
    return new Characteristic("Strength", true, false, 100.0, 0.0, 100.0);
}

Characteristic* CharacteristicFactory::GetIntelligence() {
    return new Characteristic("Intelligence", true, true, 100.0, 100.0, 50.0);
}

Characteristic* CharacteristicFactory::GetWisdom() {
    return new Characteristic("Wisdom", true, true, 50.0, 100.0, 100.0);
}


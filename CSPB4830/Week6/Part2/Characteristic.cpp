#include <iostream>
#include <string>

#include "Characteristic.h"

int Characteristic::field_counter_ = 0;

std::ostream& operator<<(std::ostream &os, const Characteristic &c) {
    os << c.get_characteristicName();
    // TODO: print out more information if you want to
    return os;
}

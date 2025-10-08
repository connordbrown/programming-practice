#include <iostream>
#include <string>

#include "Characteristic.h"

std::ostream& operator<<(std::ostream &os, const Characteristic &c) {
    os << c.get_characteristicName();
    // TODO: print out more information if you want to
    return os;
}

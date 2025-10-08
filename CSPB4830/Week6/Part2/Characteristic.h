#ifndef CHARACTERISTIC_H
#define CHARACTERISTIC_H

#include <string>
#include <iostream>

class Characteristic
{
  public:
    // Constructor to initialize all the properties of the characteristic
    Characteristic(std::string characteristicName,
                   bool isTransferable,
                   bool isInherited,
                   double strength,
                   double adaptability,
                   double stability) :
        characteristicName_(characteristicName),
        isTransferable_(isTransferable),
        isInherited_(isInherited),
        strength_(strength),
        adaptability_(adaptability),
        stability_(stability) {}

    std::string get_characteristicName() const { return characteristicName_; }
    bool get_isTransferable() const { return isTransferable_; }
    bool get_isInherited() const { return isInherited_; }
    double get_strength() const { return strength_; }
    double get_adaptability() const { return adaptability_; }
    double get_stability() const { return stability_; }

    friend std::ostream& operator<<(std::ostream &os, const Characteristic &c);

  private:
    std::string characteristicName_;
    bool isTransferable_;  // Whether the characteristic can be transferred
    bool isInherited_;  // Whether the characteristic is inherited during cloning
    double strength_;  // Defining power of the characteristic
    double adaptability_;  // How easily the characteristic adapts
    double stability_;  // How stable the characteristic is over time

    // 0) Add a static int field counter_, then modify Characteristic.cpp to initialize the field properly.
    // Then, modify the Characteristic constructor so that every time a Characteristic is instantiated, counter_ is increased by one.

    // Then, add a static get_count function to the Characteristic class.
};


class CharacteristicFactory
{
  public:
    // 1) Implement a static method to get a "Strength" characteristic.
    // This characteristic is transferable, not inherited, and has high strength and stability, but low adaptability.
    static Characteristic* GetStrength();

    // 2) Implement a static method to get an "Intelligence" characteristic.
    // This characteristic is transferable, inherited, and has high adaptability and strength, but moderate stability.
    static Characteristic* GetIntelligence();

    // 3) Implement a static method to get a "Wisdom" characteristic.
    // Wisdom is inherited, transferable, and has high stability and adaptability, but moderate strength.
    static Characteristic* GetWisdom();
};

#endif // CHARACTERISTIC_H

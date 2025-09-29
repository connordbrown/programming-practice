#include<iostream>

class Animal
{
  public:
    Animal(std::string sound): sound_(sound) {}
    std::string MakeSound() {return sound_; }
    int get_power() {return 0; }
  private:
    std::string sound_;
};

class Reptile: public Animal
{
  public:
    Reptile(std::string sound): Animal(sound) {}
    int get_power() {return 2;}
};

class Alligator: public Reptile
{
  public:
    Alligator(std::string sound, char snout): Reptile(sound +  "growl"), snout_shape_(snout) {}
    int get_power()  {return 10;}
    char get_snout_shape() {return snout_shape_;}
  private:
    char snout_shape_;
};

class Turtle: public Reptile
{
  public:
    Turtle(std::string sound, char shell): Reptile(sound + "cowabunga"), has_shell_(shell) {}
    int get_power() {return 3;}
    char has_shell() {return has_shell_;}
  private:
    char has_shell_;
};


int main()
{
  Animal cow("mooo");
  std::cout << cow.MakeSound() << std::endl;
  std::cout << cow.get_power() << std::endl;

  Reptile crocodile("snap");
  std::cout << crocodile.MakeSound() << std::endl;
  std::cout << crocodile.get_power() << std::endl;

  Alligator louis("hiss", 'u');
  std::cout << louis.MakeSound() << std::endl;
  std::cout << louis.get_power() << std::endl;
  std::cout << louis.get_snout_shape() << std::endl;

  Turtle mikey("hey", 'Y');
  std::cout << mikey.MakeSound() << std::endl;
  std::cout << mikey.get_power() << std::endl;
  std::cout << mikey.has_shell() << std::endl;

  return 0;
}

#include <iostream>
#include "string.hpp"

int main()
{
  String myString("This is string.");
  String myString2('j');
  String empty;

  std::cout << "Full string: " << myString << std::endl;
  std::cout << "One char: " << myString2 << std::endl;
  std::cout << "Empty string: " << empty << std::endl;

  std::cout << ":D yay! Done testing output operator." << std::endl;
}

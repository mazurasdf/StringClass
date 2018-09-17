#include <iostream>
#include <cassert>
#include "string.hpp"

int main()
{
  String myString;

  assert(myString.length() == 0);

  assert(myString[0] == '\0');

  std::cout << ":D yay! Done testing default constructor" << std::endl;

  return 0;

}

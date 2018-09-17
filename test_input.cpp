#include <iostream>
#include "string.hpp"
#include "string.cpp"

int main()
{
  String placeHere;
  String placeHere2;

  std::cin >> placeHere >> placeHere2;

  std::cout << "first: " << placeHere << std::endl << "second: " << placeHere2 << std::endl;

  return 0;
}

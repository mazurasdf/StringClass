#include <iostream>
#include <cassert>
#include "string.hpp"

//PLUS OVERLOADERS

int main()
{
  //string and string
  {
    String left("Drake&");
    String right("Josh");

    assert("Drake&Josh" == (left + right));
  }

  //char[] and string
  {
    String island(", Kate!");

    assert("We have to go back, Kate!" == ("We have to go back" + island));
  }

  //char and string
  {
    String incomplete("ppend");

    assert("Append" == ('A' + incomplete));
  }

  //plus equals
  {
    String left("pb and ");
    String right("jelly");

    left += right;

    std::cerr << "" << String("pb and jelly") << "\n";
    std::cout << std::endl << left << std::endl;

    assert(left == "pb and jelly");
  }
  std::cout << ":D yay! Done testing plus operators" << std::endl;
}

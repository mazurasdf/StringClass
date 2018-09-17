#include <iostream>
#include <cassert>
#include "string.hpp"

//EQUALITY OPERATOR OVERLOADER TESTS

int main()
{
  //OPERATOR== TESTS
  {
    //string and string
    {
      String left("yes");
      String right("yes");
      
      String var("o");
      String var2("o");

      assert(left == right);
      assert(var == var2);
    }

    //char[] and string
    {
      String var("hello");
      String var2("p");

      assert("hello" == var);
      assert("p" == var2);
    }

    //char and string
    {
      String var('L');

      assert('L' == var);
    }
    
    std::cout << "\tFinished operator== tests" << std::endl;
  }

  //OPERATOR!= TEST 
  {
    String black("black");
    String white("white");

    assert(black != white);

    std::cout << "\tFinished operator!= test" << std::endl;
  }
  
  //OPERATOR< AND OPERATOR<= TESTS
  {
    //string and string, also operator<=
    {
      String aardvark("aardvark");
      String aardvark2("aardvark");//return of the aardvark
      String zebra("zebra");
      String Aardvark("Aardvark");
      String Zebra("Zebra");

      assert(aardvark < zebra);
      assert(Aardvark < Zebra);
      assert(Zebra < aardvark);
      assert(aardvark <= zebra);
      assert(Aardvark <= Zebra);
      assert(Zebra <= aardvark);
      assert(aardvark <= aardvark2);
    }
    //char[] and string
    {
      String mimosa("mimosa");
      
      assert("Screwdriver" < mimosa);//true irl too
    }

    //char and string
    {
      String hawaii("hawai`i");

      assert('a' < hawaii);
    }
    std::cout << "\tFinished operator< and operator<= tests" << std::endl;
  }

  //OPERATOR> AND OPERATOR>= TESTS
  {
    String pirates("pirates");
    String ninjas("ninjas");
    String pirates2("pirates");

    assert(pirates > ninjas);
    assert(pirates >= ninjas);
    assert(pirates >= pirates2);

    std::cout << "\tFinished operator> and operator>= tests" << std::endl;
  }

  std::cout << ":D yay! Done testing equality operators." << std::endl;
}

/**
 * @file string-interface.hpp
 *
 * @version 1.0
 * @date Spring 2017
 * @authors Dr. J. Maletic, Michael John Decker
 *
 * Interface definition of String class for Project 2, milestone 1.
 *
 * To use the supplied test oracles you will need to use this interface and namings.
 * You must also have all of these methods and functions defined for your string class.
 *
 * You will either have use this interface or call your methods through this interface.
 *
 * You need to implement all of the methods and funcitons declared here.
 */

#ifndef CS23001_STRING_INTERFACE_HPP
#define CS23001_STRING_INTERFACE_HPP

#include <iostream>
#include <cassert>

// size of the array.
const int STRING_SIZE = 256;

/**
 * @invariant str[length()] == 0
 *         && 0 <= length() <= capacity()
 *         && capacity() == STRING_SIZE - 1
 *
 */
class String {
private:
    char str[STRING_SIZE];
public:
    // constructor: empty string, String('x'), and String("abcd")
    String();
    String(char);
    String(const char[]);

    // subscript: accessor/modifier and accessor
    char & operator[](int);
    char   operator[](int) const;

    // max chars that can be stored (not including null terminator)
    int capacity() const;
    // number of char in string
    int length  () const;

    // concatenation
    String   operator+ (const String &) const;
    String & operator+=(String);

    // relational methods
    bool operator==(const String &) const;
    bool operator< (const String &) const;

    // i/o
    friend std::istream & operator>>(std::istream &, String &);
    friend std::ostream & operator<<(std::ostream &, const String &);

};

// free functios for concatenation and relational
String operator+       (const char[],  const String &);
String operator+       (char,          const String &);
bool   operator==      (const char[],  const String &);
bool   operator==      (char,          const String &);
bool   operator<       (const char[],  const String &);
bool   operator<       (char,          const String &);
bool   operator<=      (const String &, const String &);
bool   operator!=      (const String &, const String &);
bool   operator>=      (const String &, const String &);
bool   operator>       (const String &, const String &);

#endif

//last revised 03/17/17

#include <iostream>
#include <cassert>
#include "string.hpp"

String::String(int num)
{
  //string size is the num
  string_size = num;

  //make a new char array of size num
  str = new char[num];

  //last character is null terminator
  str[num - 1] = 0;
}

String::String(int num, const char * cstr)
{
  string_size = num;
  
  str = new char[num];
 
  //run through cstr and copy over each char
  int pos = 0;
  while(cstr[pos] != 0)
    {
      str[pos] = cstr[pos];
      ++pos;
    }

  //last char in cstr is entered at correct spot
  str[pos] = 0;
}

void String::reset_capacity(int newCap)
{
  //make a new string with the new cap and same char array
  String temp(newCap, str);
  //swap them and the old one will go out of scope and delete
  swap(temp);
}

//re-implemented for milestone 2
String::String()
{
  //just size of 1
  string_size = 1;
  
  //and make new array with just a null terminator in it
  str = new char[string_size];
  str[0] = 0;
}

//re-implemented for milestone 2
String::String(char ch)
{
  //size 2 for single char and null terminator
  string_size = 2;

  str = new char[string_size];

  str[0] = ch;
  str[1] = 0;
}

//re-implemented for milestone 2
String::String(const char * cstr)
{
  //count how big the parameter is
  int pos = 0;
  while(cstr[pos] != 0)
    {
      ++pos;
    }

  //reassign string_size
  string_size = pos + 1;

  //create new array of same size as parameter
  str = new char[string_size];

  //assign values to member variable
  for(int i = 0; i < string_size - 1; ++i)//get rid of -1 kinda not really fixes
    {
      str[i] = cstr[i];
    }
  
  //add null terminator
  str[string_size - 1] = 0;//used to not be -1 but fixed now
}

//copy constructor
String::String(const String & copy)
{
  //copy size,make new char[],copy chars, add null terminator
  string_size = copy.string_size;

  str = new char[string_size];

  for(int pos = 0; pos < string_size; ++pos)
    {
      str[pos] = copy.str[pos];
    }

  str[string_size - 1] = 0;
}

//destructor
String::~String()
{
  delete [] str;
}

//assignment operator for milestone 2
String & String::operator=(String rhs)
{
  //switch values with rhs
  swap(rhs);

  //return deref this and since rhs is a copy, it's destroyed
  return *this;
}

//constant time swap for milestone 2
void String::swap(String & other)
{
  //switch around the sizes
  int temp_size = string_size;
  string_size = other.string_size;
  other.string_size = temp_size;

  //switchy switch with the char pointers
  char * temp_str = str;
  str = other.str;
  other.str = temp_str;
}

//will not change for milestone 2
inline int String::length() const
{
  int size = 0;
  while(str[size] != 0)
    ++size;

  return size;
}

//re-implemented for milestone 2
inline int String::capacity() const
{
  return string_size - 1;
}

//non const bracket operator
char & String::operator[](int i)
{
  assert(i >= 0);
  assert(i <= length());

  return str[i];
}

char String::operator[](int i) const
{
  assert(i >= 0);
  assert(i < length());

  return str[i];
}

bool String::operator==(const String& rhs) const
{
  int pos = 0;
  //if lengths differ, automatically false
  if (length() != rhs.length()) return false;
  
  //check each value in str until reach null terminator
  while(str[pos] != '\0')
    {
      //if not equal, return false
      if (str[pos] != rhs.str[pos])
	{
	  return false;
	}
      //else keep iterating
      ++pos;
    }

  //if both of these are null terminator, return true. else false
  return str[pos] == rhs.str[pos];
}

std::istream & operator>>(std::istream& in, String & rhs)
{
  //run through str
  int pos = 0;
  rhs.reset_capacity(0);

  while(in >> rhs.str[pos])
    {
      rhs.reset_capacity(pos + 1);
      ++pos;
    }

  rhs.str[pos] = '\0';

  return in;
}

std::ostream& operator<<(std::ostream& out, const String& rhs)
{
  out << rhs.str;
  return out;
}

bool String::operator<(const String& rhs) const
{
  int pos = 0;
  //if rhs.str and str keep giving same char, run until they don't
  //or they reach null terminator
  while(str[pos] != 0
	&& rhs.str[pos] != 0
	&& str[pos] == rhs.str[pos])
    {
      ++pos;
    }
  //at first different character or null terminator, return result
  return str[pos] < rhs.str[pos];
}

//re-implemented for milestone 2
String String::operator+(const String& rhs) const
{
  //make new String with accomodating size
  String result((length() + rhs.length() + 1),str);
  //for iterating, need an offset
  int offset = length();

  //run through and add each char in rhs.str to result.str
  int pos = 0;
  while(rhs.str[pos] != 0)
    {
      result.str[offset + pos] = rhs.str[pos];
      ++pos;
    }

  //null terminator
  result.str[offset + pos] = 0;

  return result;
}

String& String::operator+=(String rhs)
{
  //change cap to accomodating size
  reset_capacity(length() + rhs.length() + 1);
  //offset for iterator
  int offset = length();
  //run through rhs.str
  int pos = 0;
  while(rhs.str[pos] != 0)
    {
      //if this exceeds the cap for whatever reason, stop
      if((offset + pos) >= capacity()) break;
      //otherwise keep adding and iterating
      str[offset + pos] = rhs.str[pos];
      ++pos;
    }

  //null terminator
  str[offset + pos] = 0;
  return *this;
}

/*
 *
 * FREE FUNCTIONS ARE BELOW
 *
 */

String operator+(const char a[],const String & b)
{
  String thing(a);//stringer things have never been seen
  return thing + b;
}

String operator+(char a,const String & b)
{
  String thing(a);
  return thing + b;
}

bool operator==(const char a[],const String & b)
{
  String thing(a);
  return (thing==b);
}

bool operator==(char a,const String & b)
{
  String thing(a);
  return (thing==b);
}

bool operator<(const char a[],const String & b)
{
  String thing(a);
  return (thing<b);
}

bool operator<(char a,const String & b)
{
  String thing(a);
  return (thing<b);
}

bool operator>=(const String & a, const String & b)
{
  return !(a<b);
}

bool operator!=(const String & a, const String & b)
{
  return !(a==b);
}

bool operator<=(const String & a, const String & b)
{
  return ((a<b) || (a==b));
}

bool operator>(const String & a, const String & b)
{
  return (!(a<b) && !(a==b));
}

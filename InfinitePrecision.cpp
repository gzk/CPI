//============================================================================
// Name        : InfintePrecision.cpp
// Author      : Serge Iovlef
// Version     :
// Copyright   : LGPL
// Description : Hello World in C, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>

#include <iostream>

/** @brief The class Integer wrap the fundamental C type int.*/

class Integer
{
  private:
    int digits_;

  public:
    /** Constructor. get the digits.
     *  @param d initial value
     **/
    Integer(int d =0) : digits_(d)
    { }
    /** Accessory. get the digits. */
    int digits() const { return digits_;}

    Integer& operator+=(Integer const& j)
    {
      digits_ += j.digits_;
      return *this;
    }

};

/** @brief Overloading of the ostream << for the type Integer.
 *  @param os the output stream
 *  @param output the value to send to the stream
 **/
std::ostream& operator << (std::ostream& os, const Integer& output)
{
  os << output.digits();
  return os;
}

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    std::cout << "You have to give a number.\n";
    return -1;
  }

  Integer i(atoi(argv[1]));
  std::cout << "You give the number:" << i << "\n";
  Integer j(10);
  i += j;
  std::cout << "Adding 10 to your number, you get:" << i << "\n";

	return EXIT_SUCCESS;
}

#ifndef HUGEINTEGER_H
#define HUGEINTEGER_H
#include <iostream>
#include <string>
class HugeInteger
{
 friend std::ostream &operator<<( std::ostream &, const HugeInteger & );

public:
   HugeInteger();

   HugeInteger( const std::string &);
   HugeInteger operator+(const HugeInteger &) const;
   /* addition operator overloading for ¡§HugeInteger + HugeInteger¡¨*/
   HugeInteger operator+(const std::string &) const;
   /* addition operator overloading for ¡§HugeInteger + string that represents a large integer value¡¨*/
    HugeInteger operator-(const HugeInteger &) const;
   /* subtraction operator overloading for ¡§HugeInteger ¡V HugeInteger¡¨*/
    HugeInteger operator-(const std::string &) const;
   /* subtraction operator overloading for ¡§HugeInteger - string that represents a large integer value¡¨*/
    HugeInteger operator*(const HugeInteger &) const;
/* multiplication operator overloading for ¡§HugeInteger * HugeInteger¡¨*/
    HugeInteger operator*(const std::string &) const;
   /* multiplication operator overloading for ¡§HugeInteger * string that represents a large integer value¡¨*/
    HugeInteger operator/(const HugeInteger &) const;
/* division operator overloading for ¡§HugeInteger / HugeInteger¡¨*/
    HugeInteger operator/(const std::string &) const;
   /* division operator overloading for ¡§HugeInteger / string that represents a large integer value¡¨*/
    bool operator>(const HugeInteger &) const;
/* relational operator overloading for ¡§HugeInteger > HugeInteger¡¨*/
/* stream insertion operator ¡§<<¡¨ overloading*/
private:
   int integer[42];
   int noOfDigits;
 };
#endif

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
   /* addition operator overloading for ˇ§HugeInteger + HugeIntegerˇ¨*/
   HugeInteger operator+(const std::string &) const;
   /* addition operator overloading for ˇ§HugeInteger + string that represents a large integer valueˇ¨*/
    HugeInteger operator-(const HugeInteger &) const;
   /* subtraction operator overloading for ˇ§HugeInteger ˇV HugeIntegerˇ¨*/
    HugeInteger operator-(const std::string &) const;
   /* subtraction operator overloading for ˇ§HugeInteger - string that represents a large integer valueˇ¨*/
    HugeInteger operator*(const HugeInteger &) const;
/* multiplication operator overloading for ˇ§HugeInteger * HugeIntegerˇ¨*/
    HugeInteger operator*(const std::string &) const;
   /* multiplication operator overloading for ˇ§HugeInteger * string that represents a large integer valueˇ¨*/
    HugeInteger operator/(const HugeInteger &) const;
/* division operator overloading for ˇ§HugeInteger / HugeIntegerˇ¨*/
    HugeInteger operator/(const std::string &) const;
   /* division operator overloading for ˇ§HugeInteger / string that represents a large integer valueˇ¨*/
    bool operator>(const HugeInteger &) const;
/* relational operator overloading for ˇ§HugeInteger > HugeIntegerˇ¨*/
/* stream insertion operator ˇ§<<ˇ¨ overloading*/
private:
   int integer[42];
   int noOfDigits;
 };
#endif

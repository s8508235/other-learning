#ifndef HUGEINTEGER_H
#define HUGEINTEGER_H
#include <iostream>
#include <string>
class HugeInteger
{
public:
   HugeInteger();
   HugeInteger( const std::string &);

   // addition operator; HugeInteger + HugeInteger
   HugeInteger add( const HugeInteger & ) const;
   // HugeInteger + string that represents large integer value
   HugeInteger add( const std::string & ) const;
   // subtraction operator; HugeInteger - HugeInteger
   HugeInteger subtract( const HugeInteger &  ) const;
   // HugeInteger - string that represents large integer value
   HugeInteger subtract( const std::string & ) const;

   bool isGreaterThan( const HugeInteger &  ) const;
   void output() const;
private:
   int integer[42];
   int noOfDigits;
        };
#endif

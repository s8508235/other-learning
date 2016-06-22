//========================DO-NOT-MODIFY-THE-FILE========================
#ifndef Hashs_hpp
#define Hashs_hpp

#include <iostream>
#include <string.h>
#define SIZE 23

//The data structure that present a hash table.

class Hash
{
public:
    Hash():data(""){};
    //string that stores input data
    std::string data;
};

class Hashs
{
public:
    //Hash array, which represents a Hash table
    Hash table[SIZE];

    //reset the Hashs
    void reset();

    //comparison operator between string array and Hashs table
    bool operator==(const std::string l[]);

    //ouput operator of Hashs
    friend std::ostream& operator<<(std::ostream &os, const Hashs &ls);
};

#endif
//========================DO-NOT-MODIFY-THE-FILE========================

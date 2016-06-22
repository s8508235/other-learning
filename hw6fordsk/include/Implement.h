#ifndef HW6CPP_IMPLEMENT_H
#define HW6CPP_IMPLEMENT_H

#include "HashOperations.h"

class Implement : public HashOperations
{
public:

    //----------------------------------------------------------------------
    // return your student ID
    // e.g. return "123456789"
    //----------------------------------------------------------------------
    virtual const char* getStudentID();

    //----------------------------------------------------------------------
    // add the string by hash function to the hash table.
	//
    //----------------------------------------------------------------------
    virtual void add(Hashs &inst, std::string str);

};

#endif

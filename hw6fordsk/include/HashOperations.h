//========================DO-NOT-MODIFY-THE-FILE========================

#ifndef HashOperations_H
#define HashOperations_H

#include "Hashs.h"
#include <string>

//It contains the functions that you have to override in implement.h/.cpp.
class HashOperations
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

//========================DO-NOT-MODIFY-THE-FILE========================

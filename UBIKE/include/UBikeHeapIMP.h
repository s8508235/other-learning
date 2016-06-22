//*************DO-NOT-MODIFY-THE-FILE-NAME******************
//*************DO-NOT-MODIFY-THE-CLASS-NAME*****************

#ifndef UBikeHeapIMP_h
#define UBikeHeapIMP_h

//KEEP-THIS-HEADER-UNTOUCHED
#include "UBikeHeapADT.h"

class UBikeHeapIMP : public UBikeHeapADT
{
    public:
    //=================================================================
    // add the ubike pointer to the heap
    //=================================================================
    virtual void addUBikePtr(UBike* ubptr);

    //=================================================================
    // remove the ubike pointer in this heap at "index"
    //=================================================================
    virtual UBike* removeUBikePtr(int heapIndex);
};

#endif

//*************DO-NOT-MODIFY-THE-FILE-NAME******************
//*************DO-NOT-MODIFY-THE-CLASS-NAME*****************

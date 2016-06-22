//*************DO-NOT-MODIFY-THE-FILE-NAME******************
//*************DO-NOT-MODIFY-THE-CLASS-NAME*****************

#ifndef UBikeSystemIMP_h
#define UBikeSystemIMP_h

//KEEP-THIS-HEADER-UNTOUCHED
#include "UBikeSystemADT.h"

class UBikeSystemIMP : public UBikeSystemADT
{public:
     //=================================================================
    // read the map and initialize this->priceTable
    //=================================================================
    virtual void InitDistTable
    (std::string MapFile);

    //=================================================================
    // add a new bike to the system
    //=================================================================
    virtual void NewBike
    (std::string classType, std::string license,
     int mile, std::string station);

    //=================================================================
    // remove the bike license
    //=================================================================
    virtual void JunkIt
    (std::string license);

    //=================================================================
    // rent a bike
    //=================================================================
    virtual void Rent
    (std::string classType, std::string station);

    //=================================================================
    // return the bike
    //=================================================================
    virtual void Return
    (std::string station, std::string license, int returnMile);

    //=================================================================
    // move the ubike license to another station
    //=================================================================
    virtual void Trans
    (std::string station, std::string license);

    //=================================================================
    // clear all the allocated memories for ubikes
    //=================================================================
    virtual void ShutDown();

};

#endif

//*************DO-NOT-MODIFY-THE-FILE-NAME******************
//*************DO-NOT-MODIFY-THE-CLASS-NAME*****************

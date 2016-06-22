//*************DO-NOT-MODIFY-THE-FILE-NAME******************
//*************DO-NOT-MODIFY-THE-HEADER*********************

//KEEP-THIS-HEADER-UNTOUCHED
#include "UBikeHeapIMP.h"

//DO SOMETHINE HERE

// num is the size of heap.

//=================================================================
// add the ubike pointer to the heap
//=================================================================
#include <iostream>

void UBikeHeapIMP::addUBikePtr(UBike* ubptr)
{
    int cur = ++number;
	ubptr->heapIndex = cur;
	(*this)[cur] = ubptr;

	while( cur>1 && (*this)[cur/2]->mileage < (*this)[cur]->mileage ){
	    (*this)[cur]->heapIndex = cur/2;
	    (*this)[cur/2]->heapIndex = cur;

	    UBike* tmp = (*this)[cur];
	    (*this)[cur] = (*this)[cur/2];
	    (*this)[cur/2] = tmp;

		cur /= 2;
	}

}
//=================================================================
// remove the ubike pointer in this heap at "index"
//=================================================================
UBike* UBikeHeapIMP::removeUBikePtr(int heapIndex)
{
        UBike* temp = (*this)[heapIndex];
    int to;

    if(this->number == 1){
        (*this)[heapIndex] = NULL;
        this->number = 0;
    }
    else if(this->number == heapIndex){//remove the last
        (*this)[heapIndex] = NULL;
        this->number--;
    }
    else{
        (*this)[heapIndex] = (*this)[this->number];
        (*this)[heapIndex]->heapIndex = heapIndex;
        (*this)[this->number] = NULL;
        this->number --;

        //bubble up
        if(heapIndex>1 && (*this)[heapIndex]->mileage > (*this)[heapIndex/2]->mileage){
            while( heapIndex>1 && (*this)[heapIndex/2]->mileage < (*this)[heapIndex]->mileage ){
                (*this)[heapIndex]->heapIndex = heapIndex/2;
                (*this)[heapIndex/2]->heapIndex = heapIndex;

                UBike* tmp = (*this)[heapIndex];
                (*this)[heapIndex] = (*this)[heapIndex/2];
                (*this)[heapIndex/2] = tmp;

                heapIndex/=2;
            }
        }

        //bubble down
        else{
            while( (*this)[heapIndex*2] != NULL ){
                if( (*this)[heapIndex*2+1] == NULL &&
                    (*this)[heapIndex]->mileage < (*this)[heapIndex*2]->mileage )
                        to = heapIndex*2;

                else if( ((*this)[heapIndex*2] != NULL && (*this)[heapIndex*2+1] != NULL) &&
                         ((*this)[heapIndex]->mileage  < (*this)[heapIndex*2]->mileage   ||
                          (*this)[heapIndex]->mileage  < (*this)[heapIndex*2+1]->mileage) )
                        to = ( (*this)[heapIndex*2]->mileage >= (*this)[heapIndex*2+1]->mileage ) ? heapIndex*2 : heapIndex*2+1;

                else break;

                (*this)[heapIndex]->heapIndex = to;
                (*this)[to]->heapIndex = heapIndex;

                UBike* tmp = (*this)[heapIndex];
                (*this)[heapIndex] = (*this)[to];
                (*this)[to] = tmp;

                heapIndex = to;
            }
        }
    }
    return temp;
}


//=================================================================
// information
//=================================================================


//*************DO-NOT-MODIFY-THE-FILE-NAME******************
//*************DO-NOT-MODIFY-THE-HEADER*********************

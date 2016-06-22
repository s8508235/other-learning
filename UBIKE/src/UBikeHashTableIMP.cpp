//*************DO-NOT-MODIFY-THE-FILE-NAME******************
//*************DO-NOT-MODIFY-THE-HEADER*********************

//KEEP-THIS-HEADER-UNTOUCHED
#include "UBikeHashTableIMP.h"
#include <string>
#include <bitset>
using namespace std;
unsigned long long license_to_address(string a);

//DO SOMETHINE HERE
void UBikeHashTableIMP::addUBikePtr(UBike* ubptr)
{
    unsigned long long address;
    address = license_to_address(ubptr->license);
    (*this)[address].push_back(ubptr);
}

UBike* UBikeHashTableIMP::findUBikePtr(std::string license, bool toRemove)
{
    unsigned long long address;
    UBike *tmp;
    address = license_to_address(license);

    for (auto it = (*this)[address].begin() ; it != (*this)[address].end() ; it++)
    {
        if ( (*it)->license == license)
        {
            if (toRemove)
            {
                tmp = (*it);
                it = (*this)[address].erase(it);
                return tmp;
            }
            else
            {
                return *it;
            }
        }
    }
    return NULL;
}

unsigned long long license_to_address(string a)
{
    int i , j , s = 0 ;
    unsigned long long address;
    for (i = 0; i < 5; i++)
    {
        if (i == 0)
        {
            if (a[i] >= 'A')
            {
                s = a[i] - 'A' + 10;
            }
            else
            {
                s = a[i] - '0';
            }
        }
        else
        {
            if (a[i] >= 'A')
            {
                s = s * 31 + a[i] - 'A' + 10;
            }
            else
            {
                s = s * 31 + a[i] - '0';
            }
        }
    }

    bitset<30> b(s);
    bitset<8> addr;

    for (i = 0 , j = 10 ; j < 18 ; i++ , j++)
    {
        addr.set(i , b[j]);
    }

    address = addr.to_ullong();

    return address;
}
//*************DO-NOT-MODIFY-THE-FILE-NAME******************
//*************DO-NOT-MODIFY-THE-HEADER*********************

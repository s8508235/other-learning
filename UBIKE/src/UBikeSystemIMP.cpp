//*************DO-NOT-MODIFY-THE-FILE-NAME******************
//*************DO-NOT-MODIFY-THE-HEADER*********************

//KEEP-THIS-HEADER-UNTOUCHED
#include "UBikeSystemIMP.h"
using namespace std;
//DO SOMETHINE HERE
void UBikeSystemIMP::InitDistTable(string MapFile)
{
    priceTable.calcAllPairsShortestPath(MapFile);
}

void UBikeSystemIMP::NewBike(string classType, string license, int mile, string station)
{
    UBike *newBike = new UBike;
    newBike->classType = classType;
    newBike->license = license;
    newBike->mileage = mile;
    newBike->station = station;
    newBike->isRented = false;
    ubHashTable.addUBikePtr(newBike);
	ubStations[station][classType].addUBikePtr(newBike);
}

void UBikeSystemIMP::JunkIt(string license)
{

    UBike* delBike = ubHashTable.findUBikePtr(license, false);
	if( delBike!=NULL && delBike->isRented!=true ){
        ubHashTable.findUBikePtr(license, true);
        ubStations[delBike->station][delBike->classType].removeUBikePtr(delBike->heapIndex);
		delete delBike;
        delBike = NULL;
    }
	//std::cout << toString();

}

void UBikeSystemIMP::Rent(string classType, string station)
{
    if(ubStations[station][classType].isEmpty()) return;

	UBike *rentBike = ubStations[station][classType].removeUBikePtr(1);
	ubStations[station]["Rented"].addUBikePtr(rentBike);
    rentBike->isRented = true;
}

void UBikeSystemIMP::Return(string station, string license, int returnMile)
{
    UBike *retBike = ubHashTable.findUBikePtr(license, false);
	if(retBike==NULL) return;
    if(retBike->isRented == false) return;

	net += priceTable.calcPrice(returnMile-(retBike->mileage), retBike->classType, retBike->station, station);
	ubStations[retBike->station]["Rented"].removeUBikePtr(retBike->heapIndex);
	retBike->mileage = returnMile;
	retBike->isRented = false;
	ubStations[retBike->station][retBike->classType].addUBikePtr(retBike);

}

void UBikeSystemIMP::Trans(string station, string license)
{
    UBike *transBike = ubHashTable.findUBikePtr(license, false);
	if(transBike==NULL || transBike->isRented==true ) return ;
	ubStations[transBike->station][transBike->classType].removeUBikePtr(transBike->heapIndex);
	ubStations[station][transBike->classType].addUBikePtr(transBike);
	transBike->station = station;
}

void UBikeSystemIMP::ShutDown()
{
    for(int i=0; i < 256; i ++) ubHashTable[i].clear();

	for(int i=0; i < 12; i ++){
        for(int j=0; j < 5; j ++){
			int x = ubStations[StationNames[i]][HeapNames[j]].number;
			for(int k=0; k < x; k ++)
                ubStations[StationNames[i]][HeapNames[j]][k] = NULL;
            ubStations[StationNames[i]][HeapNames[j]].number = 0;
		}
	}

}

//*************DO-NOT-MODIFY-THE-FILE-NAME******************
//*************DO-NOT-MODIFY-THE-HEADER*********************

//*************DO-NOT-MODIFY-THE-FILE-NAME******************
//*************DO-NOT-MODIFY-THE-HEADER*********************

//KEEP-THIS-HEADER-UNTOUCHED
#include "PriceTableIMP.h"
#include <fstream>
void PriceTableIMP::calcAllPairsShortestPath(std::string mapFile)
{

    std::ifstream ifs(mapFile);
    std::string first;
    std::string st1,st2;
    for(int i = 0; i < 12; i++)
    {
        for(int j = 0; j < 12; j++)
        if(i!=j) distTable.at(StationNames[i]).at(StationNames[j])=1000000;
    }
    while(ifs>>st1)
    {
        int dist;
        ifs>>st2>>dist;
        distTable.at(st1).at(st2) = dist;
        distTable.at(st2).at(st1) = dist;
    }



    int vertices = 12;/*
    std::cout<<"original" << std::endl;
    for(int i = 0; i < vertices; i++)
    {
        for(int j = 0; j < vertices; j++)
        std::cout << distTable.at(StationNames[i]).at(StationNames[j]) << " ";
        std::cout << std::endl;
    }*/
    for(int k = 0; k < vertices; k++)
        for(int i = 0; i < vertices; i++)
            for(int j = 0; j < vertices; j++)
            {   int a = distTable.at(StationNames[i]).at(StationNames[j]);
                int b = distTable.at(StationNames[i]).at(StationNames[k]);
                int c = distTable.at(StationNames[k]).at(StationNames[j]);

                if(a>b+c)
                {
                    distTable.at(StationNames[i]).at(StationNames[j]) = b+c;
                    distTable.at(StationNames[j]).at(StationNames[i]) = b+c;
                }


            }
/*
std::cout<<"changed" << std::endl;
    // Print out final distance matrix
    for(int i = 0; i < vertices; i++)
    {
        for(int j = 0; j < vertices; j++)
        std::cout << distTable.at(StationNames[i]).at(StationNames[j]) << " ";
        std::cout << std::endl;
    }*/
}

int PriceTableIMP::calcPrice
(int milageDiff, std::string bClass, std::string from, std::string toStation)
{
    int t = distTable.at(from).at(toStation);
    //std::cout<<from<<" to "<<toStation<<":"<<t<<std::endl;
    if(milageDiff<t)
    {
        if(bClass=="Electric") return 30*milageDiff;
        else if(bClass=="Lady") return 25*milageDiff;
        else if(bClass=="Road") return 15*milageDiff;
        else if (bClass=="Hybrid") return 20*milageDiff;
        else{} //std::cout<<"what did u do"<<std::endl;
    }
    else
    {
        if(bClass=="Electric") return 40*milageDiff;
        else if(bClass=="Lady") return 30*milageDiff;
        else if(bClass=="Road") return 20*milageDiff;
        else if (bClass=="Hybrid") return 25*milageDiff;
        else{} //std::cout<<"what did you do"<<std::endl;
    }
    return 0;
}
void PriceTableIMP::clear_pricetable()
{
    for(int i =0;i<12;i++)
    {
        for(int j = 0;j<12;j++)
        {
                distTable.at(StationNames[i]).at(StationNames[j]) =0;
        }
    }
}

//*************DO-NOT-MODIFY-THE-FILE-NAME******************
//*************DO-NOT-MODIFY-THE-HEADER*********************

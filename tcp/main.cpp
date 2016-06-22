#include <iostream>
#include <windows.h>
using namespace std;
#include <winsock.h>
int main()
{
    HANDLE hfind;
    WIN32_FIND_DATA FindData;


    hfind = FindFirstFile("D:\\Download\\*",&FindData);
    cout<<FindData.cFileName<<endl;
FindData.
    while (FindNextFile(hfind,&FindData))
    {
        cout<<FindData.cFileName<<endl;
    }
    FindClose(hfind);
    return 0;
}

#include <iostream>
#include "stdlib.h"
#include <map>
using namespace std;
typedef struct stline
{

    int next_x=-1;
    int next_y=-1;
    bool pass= false;
}stline;

int main()
{

    system("gcc -S test.c -o test.o");
    int a,b,c;
    cin>>a>>b>>c;
    int i ;
    stline x[b][a];
    for(i=0;i<c;i++)
    {
        int j,k,l;
        cin>>j>>k>>l;
        j--;
        k--;
        l--;
        x[j][k].next_x = j+1;
        x[j][k].next_y = l;
        x[j+1][l].next_x = j;
        x[j+1][l].next_y = k;
    }/*
    cout<<endl;
    for(int w=0;w<b;w++)
    {
        for(i=0;i<a;i++)
        {
            cout<<x[w][i].next_x<<" "<<x[w][i].next_y<<" ";
        }cout<<endl;
    }*/
    int cur_x=0,cur_y = a-1;
   // cout<<a<<endl;
    while(cur_y>0)
    {
        if(x[cur_x][cur_y].next_x>=0&& x[cur_x][cur_y].pass==false)
        {
            int w = x[cur_x][cur_y].next_y;
            int v = x[cur_x][cur_y].next_x;
            cur_x = v;
            cur_y = w;
            //cout<<"cur_x:"<<cur_x<<"cur_y:"<<cur_y<<endl;
            x[cur_x][cur_y].pass=true;
        }
        else
        {
            cur_y--;
        }
    }
    cout<<cur_x+1<<endl;
    return 0;
}

#include <iostream>
using namespace std;
#include "function.h"
void Block ::clockwise90()
{
    int i,j ;
    char re[size][size];
    for(i=0; i<size ; i++)
    {
        for(j=0; j<size; j++)
        {
            re[i][j]=  pattern[i][j] ;
        }
    }
    for(i=0; i<size ; i++)
    {
        for(j=0; j<size; j++)
        {
            pattern[i][j]=  re[size-j-1][i] ;
        }
    }
    // cout<<*this<<endl;
}

Block& Block ::doublesize()
{
    int i,j;
    char re[size*2][size*2];
        for(i=0; i<2*size; i++)
        {
            for(j=0; j<2*size; j++)
            {
                re[i][j] = pattern[i/2][j/2];
            }
        }

    Block x ;
    x = Block {size*2,""};
    *this =  x;
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            // cout<<"re["<<i<<"]["<<j<<"]:"<<re[i][j]<<endl;
            pattern[i][j] = re[i][j];
            //  cout<<"pattern["<<i<<"]["<<j<<"]:"<<pattern[i][j]<<endl;
        }
    }
  //  cout<<*this<<endl;
    return *this ;
}
bool equal(const Block& a, const Block& b )
{
  /*  int i,j;
    Block c,d;
    char reg1[a.size][a.size];
    char reg2[b.size][b.size];
    c.size = a.size ;
    for(i=0; i<c.size; i++)
    {
        for(j=0; j<c.size; j++)
        {
            reg1[i][j] = a.pattern[i][j];
        }
    }
    d.size = b.size;
    for(i=0; i<d.size; i++)
    {
        for(j=0; j<d.size; j++)
        {
            reg2[i][j] = b.pattern[i][j];
        }
    }*/
    if(a.size == b.size)
    {
     /*   int s,fl = 0,cw = 0;
        s = a.size;
        while(cw<4)
        {
            for(i=0; i<s; i++)
            {
                for(j=0; j<s; j++)
                {
                    if(reg1[i][j]==reg2[i][j])
                    {
                        fl = 0;
                    }
                    else
                    {
                        fl = 1;
                    }
                }
            }
            if(fl ==0) return true;
            else
            {
                cw ++;
                for(i=0; i<c.size; i++)
                {
                    for(j=0; j<c.size; j++)
                    {
                        c.pattern[i][j] = reg1[i][j];
                    }
                }
                //  cout<<"dd"<<endl;
                c.clockwise90();
            }
        }*/
        return true ;
    }
    else
    {
        return false;
    }
}

#include "function.h"
#include <iostream>


void Block ::clockwise90()
{
    int i,j;
    char ans[size][size];
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            ans[i][j] = pattern[i][j];
        }
    }
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            pattern[i][j] = ans[size-j-1][i];
        }
    }
}
bool invariant(const Block& a)
{
    Block *b;
    b = new Block{a};
    b->clockwise90() ;
    int i,j;
    for(i=0;i<a.size;i++)
    {
        for(j=0;j<a.size;j++)
        {
                if(b->pattern[i][j]!=a.pattern[i][j])
                {
                    return false;
                }
        }
    }
    return true ;
}

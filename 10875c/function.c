#include "function.h"
#include "stdio.h"
#include "stdlib.h"
void sortArray(int R,int (*array)[COLUMN])
{
    for(int i = 0; i < 5; i++)
	for(int j = 0; j < R; j++)
	    for(int w = 0; w + j + 1 < R; w++)
		{
		    if(array[w][i]>array[w+1][i])
            {
                int a = array[w][i];
                array[w][i] = array[w+1][i];
                array[w+1][i] = a;
            }
		}
    }
    return ;
}

#include <iostream>
#include "function.h"
#include <string>
#include <algorithm>
void WordCount ::readWords()
{
    numberOfTotalWords = 0;
    int i=0;
    while(cin>>words[i])
    {
        i++;
        numberOfTotalWords ++ ;
    }
}
void WordCount ::sortWords()
{/*
    int j;
    int i;
    for(i=0;i<numberOfTotalWords;i++)
    {
         for(j=0;j<numberOfTotalWords-i;j++)
        {
            if(words[j].compare(words[j+1])==1)
            {
                swap(words[j],words[j+1]);
            }
        }
    }*/
    sort(words,words+numberOfTotalWords);
}
void WordCount::countWords()
{
    int j,k,x;
    x= 0;
    k = 0;
    int *c;
    c = new int [numberOfTotalWords];
    for(k=0;k<numberOfTotalWords;k++)
    {
        c[k]=1;
    }
    numberOfDiffWords = 1;
    k = 0;
    string *diff;
    diff = new string [numberOfTotalWords];
       for(j=0;j<numberOfTotalWords;)
        {

               while( words[j].compare(words[j+1]) == 0)
               {
                   c[x] ++;
                   j++;
               }

                    if(j==numberOfTotalWords-1) break ;
                while( words[j].compare(words[j+1]) != 0)
                {
                    if(j==numberOfTotalWords-1) break ;
                    diff[k] = words[j];
                    diff[k+1]=words[j+1];
                    k++;
                    j++;
                    x++;
                    numberOfDiffWords++;
                }
        }/*
            int i;
         for(i=0;i<numberOfDiffWords;i++)
            {
                cout<<diff[i]<<" "<<c[i]<<endl;
            }*/
                diffwords = diff;
                counting = c ;
}
void WordCount ::dumpResult()
{
    int i;
    for(i=0;i<numberOfDiffWords;i++)
            {
                cout<<diffwords[i]<<" "<<counting[i]<<endl;
            }
}

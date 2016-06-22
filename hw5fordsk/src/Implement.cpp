#include "Implement.h"
#include <iostream>
#include<algorithm>
using namespace std;
const char* Implement::getStudentID() const
{
    return "103062210";
}
bool myfunction (const LetterStat& a,const LetterStat& b)
{
    if(a.count==b.count)
        return a.c<b.c;
    else
        return (a.count>b.count);
}
void Implement::analyzeText(LetterStats &stats, std::string str)const
{
    unsigned int i;
    for(i=0;i<str.length();i++)
    {
        str[i]=toupper(str[i]);
        if(isalpha(str[i]))
        {
            for(unsigned int j =0;j<26;j++)
            {
                if(str[i]==stats.data[j].c)
                {
                    stats.data[j].count++;
                    break;
                }
            }
        }
    }
    sort(stats.data,stats.data+26,myfunction);
}


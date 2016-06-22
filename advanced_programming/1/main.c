#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char str[120000][40];
int	isCompound[120000];
int main()
{
    int num_word = 0,i,j;
    memset(str,0,sizeof(str));
    memset(isCompound,0,sizeof(isCompound));
    while(scanf("%s",str[num_word])!=EOF){num_word++;}
    for(i=0;i<num_word;i++)
    {
        for(j=i+1;j<num_word;j++)
        {
            if(isCompound[j]) continue;
            else if(strncmp(str[i] ,str[j],strlen(str[i])) == 0)
            {
                bsearch(str[j]+strlen(str[i]),str,num_word,40,strcmp);
            }
            else
                break;
        }
    }
    for(i=0;i<num_word;i++)
    {
        if(isCompound[i])
            printf("%s\n",str[i]);
    }
    return 0;
}

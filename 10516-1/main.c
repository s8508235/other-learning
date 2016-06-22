#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct clan
{
    char name[150000][11][11];
} cn;
int num[150000];
int main()
{
    cn *all;
    all = (cn*) malloc(sizeof(cn));
    scanf("%s",all->name[0][0]);
    if(strcmp(all->name[0][0],"END")==0)
    {
        printf("\n");
        return 0;
    }
    scanf("%s",all->name[1][0]);
    num[0]=2;
    int last ;
    last = 0 ;
    char ch[7];
    int i = 0,k = 0;
    while(scanf("%s",ch))
    {
        if(strcmp(ch,"END")==0) break ;
        k = 0;
        while(1)
        {
            if(strcmp(ch,all->name[0][k]) == 0)
            {
                scanf("%s",all->name[num[k]][k]);
                num[k]++;
                break ;
            }
            else
            {
                if(num[k]==0)
                {
                    strcpy(all->name[0][k],ch);
                    scanf("%s",all->name[1][k]);
                    num[k] = 2;
                    last = k ;
                    break ;
                }
                else
                {
                    k ++;
                }
            }
        }
    }
    printf("%s",all->name[0][last]);
    for(i=1;i<num[last];i++)
    {
        printf(" %s",all->name[i][last]);
    }
    printf("\n");
    return 0;
}

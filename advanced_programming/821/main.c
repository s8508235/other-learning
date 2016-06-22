#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 50
int maps[105][105];
int cnt ;
void init(){
    cnt = 0;

	int i,j;
	for( i=0;i<105;i++)
    {
        for(j=0;j<105;j++)
        {
            if(i!=j)
            maps[i][j] = max;
            else
            maps[i][j] = 0;
        }
	}
}
int min(int a,int b)
{
    return (a<b)?a:b;
}
int main()
{
    int st1,st2,cases = 1;
    while(scanf("%d%d",&st1,&st2) && st1&& st2)
    {
        init();
        st1--,st2--;
        maps[st1][st2] = 1;
        while(scanf("%d %d",&st1,&st2)&& st1&& st2)
        {
            st1--,st2--;
            maps[st1][st2]= 1;
            cnt ++;
        }
        int i,j,k;
        double sum = 0;
        for( k=0; k<105; k++)
        {
            for( i=0; i<105; i++)
            {
                for( j=0; j<105; j++)
                {
                    maps[i][j]=min(maps[i][j],maps[i][k]+maps[k][j]);
                }
            }
        }
        double nsum = 0;
        for( i=0; i<105; i++)
        {
            for( j=0; j<105; j++)
            {
                if (maps[i][j]!=max && maps[i][j] !=0) sum+=maps[i][j],nsum++;
            }
        }
        printf("Case %d: average length between pages = %.3f clicks\n",cases++,sum/(nsum));
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int parent[26];
char word[30005][1005];
void initial()
{
    memset(parent,-1,sizeof(parent));
}
int Find(int x)
{
    if(parent[x]<0) return x;
    else
    {
        return parent[x]=Find(parent[x]);
    }
}
void Union(int x,int y)
{
    int Fx=Find(x);
    int Fy=Find(y);
    printf("%d %d\n",Fx,Fy);
    printf("%d %d\n",parent[Fx],parent[Fy]);
    if(Fx!=Fy)
    {
        if(parent[Fx]<parent[Fy])
        {
            parent[Fx]+=parent[Fy];
            parent[Fy]=Fx;
        }
        else
        {
            parent[Fy]+=parent[Fx];
            parent[Fx]=Fy;
        }
    }
    else
        parent[Fx]--;
    printf("%d %d\n",parent[Fx],parent[Fy]);
}
int main()
{
    int caseN;
    scanf("%d",&caseN);
    while(caseN--)
    {
        int wordN,i;
        scanf("%d",&wordN);

        initial();
        int table[26][26]={};
        for( i=0;i<wordN;i++)
        {
            scanf("%s",word[i]);
            int head=word[i][0]-'a';
            int last=word[i][strlen(word[i])-1]-'a';
            table[head][last]++;//head connect last
            Union(head,last);
        }


        int cnt=0;
        for( i=0;i<26;i++)
        {
            if(parent[i]<-1) cnt++;
        }

        int connected=(cnt==1);//是否為連通圖

        int start=0,End=0;
        int possible=1,j;
        for( i=0;i<26 && connected;i++)
        {
            int indegree=0;
            int outdegree=0;
            for( j=0;j<26;j++)
            {
                outdegree+=table[i][j];
                indegree+=table[j][i];
            }
            if(indegree!=outdegree)
            {
                if(indegree==outdegree+1)
                    start++;
                else if(indegree+1==outdegree)
                    End++;
                else
                    possible=0;
            }
        }
        possible&=((start==1 && End==1)||(start==0 && End==0));
        if(connected && possible)
        {
            printf("Ordering is possible.\n");
        }
        else
        {
            printf("The door cannot be opened.\n");
        }
    }
    return 0;
}

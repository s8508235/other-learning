#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void sub(int a,int b,int i);
char s[1000];
char ans[100][1000];
int compare(const void * a, const void * b)
{
    return strcmp((char*)a,(char*)b);
}
int main()
{
    char ch;
    int x=0;
    while ((ch=getchar())!='\n')
    {
        s[x]=ch;
        x++;
    }

    int n;
    scanf("%d",&n);

    int i;
    int a,b;
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        ans[i][b+1]='\0';
        sub(a,b,i);

    }


    qsort(ans,n,sizeof(ans[0]),compare);
    for(i=0;i<n;i++)
    {
        printf("%s\n",ans[i]);
    }
    return 0;
}
void sub(int a,int b,int i)
{
    int j;
    int k =0;
    for(j=a;j<=b;j++)
    {
        ans[i][k]=s[j];

        k++;
    }

    return ;
}

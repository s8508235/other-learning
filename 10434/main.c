#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[1000];
char ans[101][1000];
void sub(int a,int b);
int cmp(const void *a,const void *b)
{
    return strcmp((char*)a,(char*)b);
}
int main()
{
    char ch;
    int q=0;
    while ((ch=getchar())!='\n')
    {
        s[q]=ch;
        q++;
    }
    int n;
    scanf("%d",&n);
    int a,b;
    int i;
    for(i=0; i<n; i++)
    {
        scanf("%d%d",&a,&b);
        sub(a,b);
    }
    int l;
    l=strlen(s); /*printf("l:%d\n",l);*/ int k=0;
    int j=0;
    for(i=0; i<l; i++)
    {
        if(s[i]!='Q')
        {
            ans[k][j]=s[i];
            /* printf("ans[%d][%d]:%c\n",k,j,ans[k][j]);*/
             j++;
        }
        else
        {
            if(s[i+1]!='Q')
            {
                if(j==0)
                {
                    continue;
                }
                k++;
                j=0;
            }
        }
        if(i==l-1&&s[i]=='Q')
        {
            k--;
        }
    }
    /* ab000abc0e*/
     /*printf("%d\n",k);*/
     /*
     for(i=0;i<=k;i++)
     { printf("%s\n",ans[i]); }*/
      /* for(i=0;i<k+1;i++)
      { qsort(ans[i],strlen(ans[i]),sizeof(char),cmp);
       }*/
    qsort(ans,k+1,sizeof(*ans),cmp);
    for(i=0; i<k+1; i++)
    {
        printf("%s\n",ans[i]);
    }
    return 0;
}
void sub(int a,int b)
{
    int k;
    for(k=a; k<=b; k++)
    {
        s[k]='Q';
    }
}

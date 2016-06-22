#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[1000][10];
int c[1000];
int tag[1000];
int main()
{
    int i,j;
    char ch;
    i=0;
    j=0;
    int flag;
    while(1){


        while ((ch=getchar())!=' ')
            {
                if(s[i][0]=='E')
                {
                flag=1;

                }
                 if(s[i][1]=='N')
                {
                flag++;

                }
                 if(s[i][2]=='D')
                {
                flag++;

                }

                if(flag==3) break;

                if(ch=='\n') {
                            //printf("XD\n");
                            i++;
                            j=0;
                          continue;
                        }
                s[i][j]=ch;
            //printf("s[%d][%d] : %c ",i,j,s[i][j]);
            j++;
            if(j==6) break;
            }
            //printf("\n");
            if(flag==3) break;
    i++;
    j=0;
    }
    int a,b;
   /* for(a=0;a<i;a++)
    {
            printf("s[%d]:%s\n",a,s[a]);
    }*/
    for(a=0;a<i;a++)
    {
        for(b=a;b<i;b++)
        {
            if( tag[b] >= 0)
            {
                if(strcmp(s[a],s[b])==0)
                {
                    c[a]++;
                   // printf("c[%d]:%d\n",a,c[a]);
                    tag[a]=1;
                    //printf("tag[%d]:%d\n",a,tag[a]);
                    if(a!=b)
                    tag[b]=-1;
                   // printf("tag[%d]: %d\n",b,tag[b]);
                }
            }

        }

    }
    int max;
    for(a=0;a<i;a++)
    {
        if(c[a]>0)
        {
            max=a;
        }
    }
    printf("%s\n",s[max]);
    printf("%d\n",c[max]);
    return 0;
}

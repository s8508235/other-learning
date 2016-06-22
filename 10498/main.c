#include <stdio.h>
#include <stdlib.h>
int c[10000];
int d[10000];
void f(int i);
int x;
int n;
int main()
{
    int z;
    int i;
    i=0;
    while(1){
        scanf("%d",&n);

        if(n<0) {
            z=x;
                break;
        }
            i=0;
            f(i);
    }

    for(i=0;i<=z;i++)
    {
        if(c[i]==0) {
                printf("\n");
                break;
        }
        printf("%d\n",c[i]);
    }
    return 0;
}
void f(int i)
{
    if(n>c[i]&&d[i]<5)
    {
        c[i]=n;
        d[i]++;
    }
    else {
        x=i+1;
        f(x);
    }
}

#include <stdio.h>
#include <stdlib.h>
int f(int n);
int ans;
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if(n==0) break;
        int x;
        x=f(n);
        printf("%d\n",x);
        ans=0;
    }
    return 0;
}
int f(int n)
{


    if(n>0){
    ans += n*n ;
    f(n-1);
    }

    return ans;
}
//1 5 14 30

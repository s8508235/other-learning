#include <stdio.h>
#include <stdlib.h>
typedef struct bignum
{
    int num[3000];
    int size;
}bignum;
bignum multbignum(bignum a,int b)
{
    int i;
    bignum ans;
    for(i=0;i<3000;i++)
    {
        ans.num[i] = 0;
    }
    int carry = 0;
    for(ans.size= 0;ans.size<a.size||carry;ans.size++)
    {
        ans.num[ans.size] = a.num[ans.size] * b+carry;
        carry = ans.num[ans.size] / 10;
        ans.num[ans.size] %= 10;
    }
    if(ans.num[ans.size]) ans.size ++;
    return ans;
}
int main()
{
    int num;
    while(scanf("%d",&num)!=EOF)
    {
        int i;
        bignum first;
        first.num[0] = 1;
        first.size = 1;
        for(i=2;i<=num;i++)
        {
            first = multbignum(first,i);
        }
        printf("%d!\n",num);
             i=first.size-1;
            for(;i>=0;i--)
            {
                printf("%d",first.num[i]);
            }
            printf("\n");
        }

    return 0;
}

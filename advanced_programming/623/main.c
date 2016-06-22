#include <stdio.h>
#include <stdlib.h>
typedef struct bignum
{
    int num[3000];
    int size;
}bignum;
bignum list[1005];
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
void build_list()
{
    int i,j;
    bignum first;
    first.num[0] = 1;
    first.size = 1;
    list[0] = list[1] = first;
    for(j=2;j<=1000;j++)
    {
        first = multbignum(first,j);
        list[j].size = i =first.size-1;
        list[j].size++;
        for(;i>=0;i--)
        {
            list[j].num[i] = first.num[i];
        }
    }
}
void print_ans(int num)
{
    int i;
    for(i=list[num].size-1 ; i >=0 ;i --)
        printf("%d",list[num].num[i]);
}
int main()
{
    int num;
    build_list();
    while(scanf("%d",&num)!=EOF)
    {
        printf("%d!\n",num);
        print_ans(num);
            printf("\n");
    }
    return 0;
}

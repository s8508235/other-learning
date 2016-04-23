#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int isprime[100001];
void build_prime()
{
    int j;
    int m = (int)(sqrt(100000)+0.001);
    for(j=0; j<=100000; j++) isprime[j] = 1;
    for(j=2; j<=m; j++)
    {
        if(isprime[j]==1)
        {
            int k;
            for(k=j*j; k<=m; k+=j)
            {
                isprime[k] = 0;
            }
        }
    }
}
int main()
{
    int N;
    scanf("%d",&N);
    int i;
    build_prime();
    for(i=0; i<N; i++)
    {
        int L,U;
        scanf("%d %d",&L,&U);
        int j;
        int z;
        int m =  (int)(sqrt(U)+0.001);
        int nlist[m+1];
        for(z=0; z<=m; z++)
        {
            nlist[z]=0;
        }
        int x;
        int max_num = 0,max = 0;
        for(z = L;z<=U;z++)
        {
            x = z;
            int num = 0,tmp = 1;
            for(j=2;j<=m;j++)
            {
                if(isprime[j]==1 && x%j==0)
                {
                    nlist[num] = 0;
                    while(x%j==0)
                    {
                        x/=j;
                        nlist[num]++;
                    }
                    tmp *= nlist[num]+1;
                    num++;
                }
            }
            if(x>1)
            {
                nlist[num] = 1;
                num++;
                tmp *= 2;
            }
            if(tmp>max)
            {
                max = tmp;
                max_num = z;
            }
        }

        printf("Between %d and %d, %d has a maximum of %d divisors.\n",L,U,max_num,max);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int isprime[47000];
int flag[1000000];
void build_prime()
{
    int j;
    int m = (int)(sqrt(47000)+0.001);
    for(j=0; j<=47000; j++) isprime[j] = 1;
    isprime[0] = 0;
    isprime[1] = 0;
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
    build_prime();
    int L,U;
    while((scanf("%d %d",&L,&U))!=EOF)
    {
        int i,j;
        int m =  (int)(sqrt(U)+0.001);
        int re_prime[47000];
        int prime_list[47000];
        for(i=0;i<47000;i++)
        {
            re_prime[i] = 0;
            prime_list[i] = 0;
        }
        int p_num = 0;
        for(i=2;i<=m;i++)
        {
            if(isprime[i])
                prime_list[p_num++] = i;
        }
        int num = 0;

        for(i=0;i<1000000;i++)
        {
            flag[i] = 1;
        }
        for(j=0;j<p_num;j++)
        {
                i = L;
            if(i%prime_list[j]!=0)
            {
                i = prime_list[j]*(L/prime_list[j]+1);
            }
            for(;i<=U && i>0;i+=prime_list[j])
            {
               if(flag[i-L])
               {
                    if(i % prime_list[j]==0 && i!=prime_list[j])
                    {
                            flag[i-L] = 0;
                    }
               }

            }
        }
        if(L==1)
        flag[0] = 0;

        for(i=0;i<1000001 && i<=U-L;i++)
        {
            if(flag[i] )
            {
                re_prime[num++] = L+i;
            }
        }
        if(num>1)
        {
            int tar_num1,tar_num2,max_num = 0;
            int min_num = 2147483647,z,zz;
            for(i=0;i<num -1 ;i++)
            {
              if( re_prime[i+1] - re_prime[i] >max_num)
              {
                  max_num = re_prime[i+1] - re_prime[i];
                  tar_num1 = i;
                  tar_num2 = i+1;
              }
              if( re_prime[i+1] - re_prime[i] < min_num)
              {
                  min_num = re_prime[i+1] - re_prime[i];
                  z = i;
                  zz = i+1;
              }
            }
            printf("%d,%d are closest, %d,%d are most distant.\n",re_prime[z],re_prime[zz],re_prime[tar_num1],re_prime[tar_num2]);
        }
        else
        printf("There are no adjacent primes.\n");
    }

    return 0;
}

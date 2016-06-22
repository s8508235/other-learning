#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int peo[200000];
long long int nprime[200000];
typedef struct man{
    long long int id;
    long long int next ;
}man ;
void f(long long int n);
int main()
{
    long long int i,j,k;
    for(i=0;i<200000;i++)
    {
        peo[i] = 1;
    }
    peo[0]=0;
    peo[1]=0;
        int sqrt_200000 = sqrt(200000);
    for ( i=2; i<=sqrt_200000; i++){
         if (peo[i])
            for ( k=(200000-1)/i, j=i*k; k>=i; k--, j-=i){
                 if (peo[k])
                    peo[j] = 0;
            }

    }
    j = 0 ;
    for( i = 2 ; i<200000 ; i++){
        if(!peo[i]){
            nprime[j] = i;
            j++;
        }
    }
    long long int n;
    while(scanf("%lld",&n)!=EOF)
    {
        f(n);
    }
    return 0;
}
void f(long long int n)
{
    man *fat;
    fat = (man*) malloc((n+1)*sizeof(man));

    long long int i,j,k,x,z;
    for(i=1;i<=n;i++){
        fat[i].id = i;
        fat[i].next = i+1;
    }
    fat[n].next = 1;
    i=1;
    z=0;
    for(k = n ;k>1;k--){
       // printf("start:%lld\n",z);
        if(nprime[z]%k==0) j = k;
        else j = nprime[z]%k;

        for(;j>1;j--)
        {
            x = i;
            i = fat[i].next;
        }
        fat[x].next = fat[i].next;
        i= fat[i].next;
        z++;
    }
    printf("%lld\n",fat[i].id);
    return ;
}

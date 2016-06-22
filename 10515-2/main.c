#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int peo[200000];
long long int nprime[200000];
typedef struct man{
    long long int id;
    struct man *next ;
    struct man *prev ;
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

    long long int i,j,k;
    for(i=1;i<=n;i++)
    {
        fat[i].id = i;
        if(i!=n)
        fat[i].next=&fat[i+1];
        else
        fat[n].next=&fat[1];
        if(i!=1)
        fat[i].prev=&fat[i-1];
        else
        fat[1].prev=&fat[n];
    }
    long long int num ;
    num = n ;
    man *temp;

    temp = &fat[1];
    for(j=0;j<n-1;j++){
        for(k=0;k<(nprime[j]%num-1+nprime[j])%nprime[j];k++){
           temp = temp -> next;
        }
        //printf("START\n");
        temp -> prev -> next = temp -> next ;
        temp -> next -> prev = temp -> prev ;
        temp = temp ->next;
        num--;
        //printf("END\n");
    }
    printf("%lld\n",temp ->id);
    return ;
}


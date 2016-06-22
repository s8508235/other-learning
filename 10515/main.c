#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int peo[200000];
long long int nprime[200000];
void f(long long int n);
typedef struct man{
    long long int id;
    struct man *next ;
    struct man *prev ;
}man ;
int main()
{
    long long int i,j,k;
    for(i=0;i<200000;i++)
    {
        peo[i] = 1;
    }
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
    while(scanf("%lld",&n)!=EOF){
        f(n);
    }


    return 0;
}
void f(long long int n){
    long long int i,j;
    man *head,*curr,*temp;
    head = (man*) malloc(sizeof(man));
    head ->id = 1;
    curr = head ;
    for(i=2;i<=n;i++){
        temp = (man*) malloc(sizeof(man)) ;
        temp -> id = i;
        curr -> next = temp ;
        temp -> prev = curr ;
        curr = temp ;
    }
    curr -> next = head ;
    head -> prev = curr ;
    curr = head ;
    int k;
    long long int num ;
    num = n ;
    for(j=0;j<n-1;j++){
        for(k=0;k<(nprime[j]%num-1+nprime[j])%nprime[j];k++){
            curr = curr -> next;
        }
        curr -> prev -> next = curr -> next ;
        curr -> next -> prev = curr -> prev ;
        curr = curr -> next ;
        num--;
    }
    printf("%lld\n",curr -> id);
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int m[130000];
int w[100000];
typedef struct man{

    int id;
    struct man *next;
    struct man *prev;
}man;
int main()
{
     long long int i,j;
    for(i=2;i<130000;i++){
        m[i]=1;
    }
     //printf("??");
     long long int sqrt_130000;
     sqrt_130000 = sqrt(130000);
     long long int n;
     long long int k;
       int flag=0;
        for(i=2;i<=sqrt_130000;i++)
        {
                if (m[i]==1){
                for(k=(130000-1)/i,j=k*i;k>=i;k--,j-=i)
                {
                    if(m[k]==1)
                    {
                        m[j]=0;
                    }
                }
            }

        }
    while (scanf("%lld",&n)!=EOF)
    {
        for(i=2;i<130000;i++){
            if(m[j]==0){
                    if(flag == n) break ;
                w[flag] = j;
                flag++;
            }
        }
        flag = 0;
        man *head,*curr,*temp;
        head = (man*) malloc(sizeof(man));
        head -> id = 1;
        curr = head ;
    for(i=2;i<=n;i++){
        curr -> next = (man*) malloc(sizeof(man));
        temp = curr ;
        curr = curr -> next ;
        curr -> prev = temp ;
        curr -> id = i ;
        }
        curr ->next = head ;
        head ->prev = curr ;
        curr = head;
        int num;
        num = n;
        for(i=0;i<n-1;i++){

            for(j=0;j<(w[i]%num-1+w[i])%w[i];j++){
                curr = curr -> next;
            }
            curr ->prev ->next = curr ->next ;
            curr ->next ->prev = curr ->prev ;
            temp = curr -> next;
            //free(curr);
            curr = temp ;
            num--;
        }
        printf("%d\n",curr->id);
        //free(curr);
    }



        return 0;
}

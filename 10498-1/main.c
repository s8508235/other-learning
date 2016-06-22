#include <stdio.h>
#include <stdlib.h>
typedef struct table
{
    long long int mem;
    struct table *next ;
    int f;
} table;
int main()
{
    int i=1;
    table *first,*curr,*temp;
    first = (table*) malloc(sizeof(table));
    first->mem = -1;
    first->f = 0;
    first->next = NULL ;
    curr = first;
    long long int n;
    while(scanf("%lld",&n))
    {
        if(n<=0)
        {
            break ;
        }
        curr = first;
        while(1)
        {
            if(n>curr->mem&&curr->f!=5)
            {
                curr->mem = n;
                curr->f++;
                break ;
            }
            else
            {
                if(curr->next == NULL)
                {
                    temp = (table*) malloc(sizeof(table));
                    curr ->next = temp;
                    curr = curr->next ;
                    curr->f = 1;
                    curr->mem = n;
                    curr->next = NULL ;
                    i++;
                    break ;
                }
                curr = curr->next;
            }
        }
    }

    curr  = first;
    for(n=1;n<=i;n++){
        if(curr->mem<0){
            printf("\n");
            break ;
        }
        printf("%lld\n",curr->mem);
        curr = curr->next;
    }
    return 0;
}

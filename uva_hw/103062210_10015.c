#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}node;
int isprime[12257001];
int primelist[3600];
void build_prime()
{
    int j;
    int m = (int)(sqrt(1100000000)+0.001);
    for(j=0; j<=12257000; j++) isprime[j] = 1;
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
    int p_cnt = 0;
    for(j=0;j<=m;j++)
    {
        if(isprime[j])
            primelist[p_cnt++]  = j;
    }
}

int main()
{
    int l;
    build_prime();
    while( scanf("%d",&l) && l>0)
    {
        node *head,*temp,*curr,*ncur;
        int i;
        head = (node*)malloc(sizeof(node));
        curr=head;
        ncur=head;
        curr -> data =1;
        if(l>1)
        {
             for(i=2;i<=l;i++)
            {
                curr ->next = (node*)malloc(sizeof(node));
                ncur=curr;
                curr=curr->next ;
                curr->prev=ncur;
                curr->data=i;
            }
        }
        curr ->next = head;
        head ->prev = curr;
        curr = head;
        int cnt=1;

        int primecnt = 0;
        while (primecnt<l)
        {
            int living = l - primecnt;
            int need_cycle = primelist[primecnt];
            need_cycle %= living;
            temp =  curr->prev;
            if(need_cycle ==0)
            {
                temp = curr;
                curr = curr->prev;
                curr->prev->next = temp;
                temp->prev = curr->prev;
                curr = temp;
            }
            else
            {    cnt = 1;
                while(cnt< need_cycle)
                {
                    cnt++;
                    temp = curr;
                    curr = curr->next;
                }
                {
                    curr = curr->next;
                    curr->prev = temp;
                    temp->next = curr;
                }
            }
            primecnt++;
        }
        printf("%d\n",curr->data);
    }


    return 0;
}

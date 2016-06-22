#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}node;


int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    node *head,*temp,*curr,*ncur;
    int i;
    head = (node*)malloc(sizeof(node));
    curr=head;
    ncur=head;
    curr -> data =1;
    for(i=2;i<=n;i++)
    {
        curr ->next = (node*)malloc(sizeof(node));
        ncur=curr;
        curr=curr->next ;
        curr->prev=ncur;
        curr->data=i;
    }
    curr ->next = head;
    head ->prev = curr;
    curr = head;
    int cou=1;
    int flag = 1;
   while (1)
    {
        if(flag == 1)
        {
            temp = curr -> next;

        cou++;
            if(cou == m )
            {
            curr -> next =temp -> next ;
            temp -> next ->prev =curr ;
                if(curr -> next == curr) break ;
            free(temp);
            flag = 0;
            cou = 1;
            }

            if(flag == 1)     curr = curr ->next ;
        }
        else
        {
            temp = curr -> prev ;
            cou++;
            if(cou == m)
            {
                curr->prev=temp ->prev;
                temp->prev->next=curr;
                    if(curr -> next == curr) break ;
                free(temp);
                flag =1;
                cou=1;
            }
            if(flag == 0) curr = curr->prev;
        }
    }
    printf("%d\n",curr->data);

    return 0;
}

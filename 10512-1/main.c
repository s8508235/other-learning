#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct books
{
    int id;
    struct books *next;
    struct books *prev;
}bk;
bk* find_head(int num,bk *zz);
int n;
int main()
{
    scanf("%d",&n);
    int ex[n];
    int i;
    for(i=0;i<n;i++)
    {
        ex[i] = 0;
    }
    bk *head,*curr,*temp,*fat;
    head = (bk*) malloc(sizeof(bk));
    head ->id = 0;
    curr = head;
    for(i=1;i<n;i++)
    {
        temp = (bk*) malloc(sizeof(bk));
        curr->next = temp ;
        temp ->id = i;
        temp ->prev = curr;
        curr = curr->next ;
    }
    printf("%d\n",curr->id);
    head ->prev = curr;
    curr ->next = head;
    int num1,num2;
    char ch1[20];
    char ch2[20];
    while(scanf("%s",ch1)!=EOF)
    {
        if(strcmp(ch1,"exit")==0) break ;
        else if(strcmp(ch1,"move")==0)
        {
            scanf("%d",&num1);
            if(ex[num1]==1||num1>=n||num1<0) {
                    scanf("%s",ch2);
                    scanf("%d",&num2);
                    continue ;
            }
            scanf("%s",ch2);
            if(strcmp(ch2,"on")==0)
            {
                scanf("%d",&num2);
                if(ex[num2]==1||num2>=n||num2<0) {
                    continue ;
            }
                if(head->id == num1)
                {
                    head= head->next;
                }
                temp =find_head(num1,head);
                fat = find_head(num2,head);
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                fat ->next ->prev = temp ;
                temp->prev = fat;
                temp->next = fat->next;
                fat ->next = temp ;
                //printf("o head:%d\n",head->id);
            }
            else if(strcmp(ch2,"under")==0)
            {
                scanf("%d",&num2);
                if(ex[num2]==1||num2>=n||num2<0){
                    continue ;
            }
                temp= find_head(num1,head);
                fat = find_head(num2,head);
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                fat ->prev ->next = temp ;
                temp ->next = fat;
                temp->prev = fat->prev;
                fat->prev = temp ;
                if(head->id == num2)
                {
                    head = find_head(num1,head) ;
                }
            }
        }
        else if(strcmp(ch1,"remove")==0)
        {
            scanf("%d",&num1);
            if(ex[num1]==1||num1>=n||num1<0) continue ;
            ex[num1]=1;
            if(head->id==num1)
            {
            head = head ->next ;
            }
            temp = find_head(num1,head);
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            n--;
            //printf("head:%d\n",head->id);
        }
        else{
        }
    }
    curr = head;
    for(i=0;i<n;i++)
    {
        printf("%d ",curr->id);
        curr = curr->next;
    }
    printf("\n");
    return 0;
}
bk* find_head(int num,bk *zz)
{
    int i ;
    for(i=0;i<n;i++)
    {
        if(zz->id == num)
            break ;
        zz = zz->next;
    }
    return zz;
}

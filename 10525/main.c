#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char ch1[30];
char ch2[30];
char ch3[30];
typedef struct block
{
    char ch[30];
    struct block *next ;
    struct block *prev ;
}bk;
int check(char *c);
bk *head,*curr,*temp,*tail;
void re();
int main()
{
    head = (bk*) malloc(sizeof(bk));
    tail = (bk*) malloc(sizeof(bk));
    head -> next = tail;
    tail -> prev = head;
    tail -> next = tail;
    while (scanf("%s",ch1)!=EOF)
    {
        if(!strcmp(ch1,"InsertAfter"))
        {
            scanf("%s",ch2);
            if(check(ch2))
            {
                scanf("%s",ch3);
                temp = (bk*) malloc(sizeof(bk));
                strcpy(temp->ch,ch3);
                temp -> next = curr ->next ;
                curr -> next -> prev = temp ;
                curr -> next = temp ;
                temp -> prev = curr ;
                //printf("ia:%s\n",temp->ch);
            }
            else
            {
                printf("InsertAfter error\n");
            }

        }
        else if(!strcmp(ch1,"InsertBack"))
        {
            temp = (bk*) malloc(sizeof(bk));
            temp -> next = tail ;
            temp -> prev = tail ->prev ;
            tail -> prev -> next = temp ;
            tail -> prev = temp ;
            scanf("%s",ch2);
            strcpy(temp->ch,ch2);
            //printf("ib:%s\n",temp->ch);
        }
        else if(!strcmp(ch1,"Delete"))
        {
            scanf("%s",ch2);
            if(check(ch2))
            {
                curr -> prev -> next = curr -> next ;
                curr -> next -> prev = curr -> prev ;
                free(curr);
            }
            else printf("Delete error\n");
        }
        else if(!strcmp(ch1,"Reverse"))
        {
            re();
        }
        else if(!strcmp(ch1,"Print"))
        {
            curr = head -> next ;
            printf("%s",curr ->ch);
            curr = curr ->next ;
            while (curr !=tail)
            {
                printf("->%s",curr->ch);
                curr = curr -> next;
            }
            printf("\n");
        }
    }
    return 0;
}
int check(char *c)
{
    //printf("c:%s\n",c);
    curr = head->next ;
    while(curr!=tail){
            if(!strcmp(curr->ch,c)) {
                    //printf("check ok\n");
                    return 1;
            }
        curr =curr ->next;
    }
    //printf("check failed\n");
    return 0;
}
void re()
{
    //printf("start re\n");
    curr = tail ;
    while (curr != head)
    {
        curr -> next = curr -> prev;
        curr = curr -> next;
    }
    curr = tail ;
    temp = tail ;
    //printf("stage 1\n");
    while(1)
    {
        temp = curr ;
        curr = curr ->next;
        curr ->prev =temp ;
        if( curr == head ) break ;
    }
    curr = tail ;
    tail = head ;
    head = curr ;
    //printf("clear\n");
    return ;
}

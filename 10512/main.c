#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct books
{
    int id;
    struct books *next;
    struct books *prev;
}bk;
bk* find_head(int num,bk *curr);
int n;
bk *book,*curr_d;
int main()
{

    scanf("%d",&n);

    book = (bk*) malloc(n*sizeof(bk));
    int i ;
    for(i=0;i<n;i++)
    {
        book[i].id = i;
        book[i].next = &book[i+1];
        book[i].prev = &book[i-1];
    }
    curr_d = &book[0];
    book[0].prev = &book[n-1];
    book[n-1].next = &book[0];
    int num1,num2;
    char ch1[7];
    char ch2[5];//  1  3 2 0 4
    while(scanf("%s",ch1)!=EOF)
    {
        if(strcmp(ch1,"exit")==0) break ;
        else if(strcmp(ch1,"move")==0)
        {
            scanf("%d",&num1);
            scanf("%s",ch2);
            if(strcmp(ch2,"on")==0)
            {
                if(curr_d == &book[num1])
                {
                curr_d = curr_d->next;
                //printf("chon\n");
                }
                scanf("%d",&num2);
                bk *temp,*fatt;
                temp = find_head(num1,curr_d);
                fatt = find_head(num2,curr_d);
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                temp->prev = fatt;
                temp->next = fatt->next;
                fatt ->next = temp ;
            }
            else if(strcmp(ch2,"under")==0)
            {
                scanf("%d",&num2);
                bk *temp,*fatt;
                temp = find_head(num1,curr_d);//2
                fatt = find_head(num2,curr_d);//0
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                fatt ->prev ->next = temp ;
                temp ->next = fatt;
                temp->prev = fatt->prev;
                fatt->prev = temp ;

                if(curr_d == &book[num1])
                {
                    curr_d = curr_d->prev ;

                }
            }
        }
        else if(strcmp(ch1,"remove")==0)
        {
            scanf("%d",&num1);
            bk *temp;
            temp = &book[num1];
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            n--;
            if(curr_d == &book[num1])
            {

            curr_d = curr_d ->next ;
            }

            free(&book[num1]);
        }
        else{
            printf("ERROR\n");
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d ",curr_d->id);
        curr_d = curr_d->next;
    }
    printf("\n");
    return 0;
}
bk* find_head(int num,bk *curr)
{
    int i ;
    for(i=0;i<n;i++)
    {
        if(curr->id == book[num].id)
            break ;
        curr = curr->next;

    }
    return curr;
}

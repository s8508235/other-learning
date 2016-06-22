#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct mon{
    char id;
    struct mon *next;
    struct mon *prev;
}mon;
int main()
{
    mon *curr,*head,*tail,*temp;
    head = (mon*) malloc(sizeof(mon));
    tail = (mon*) malloc(sizeof(mon));
    head ->next = tail ;
    tail ->prev = head ;
    tail ->next = tail ;
    curr = tail;
    char ch;
    while(scanf("%c",&ch)!=EOF)
    {
        if(ch=='\n') break ;


        if(ch=='@'){
                curr = head ->next;
        }
        else if(ch=='%'){
                if(curr == tail ) continue;
               /* else if(curr -> next == tail){
                     tail = curr;
                     curr->next = curr;
                }*/else{
                    curr ->next ->prev = curr ->prev;
                    curr ->prev ->next = curr ->next;
                    curr = curr ->next;
                }

       }
       else if(ch=='#'){
                curr = tail;
       }
       else {
            temp = (mon*) malloc(sizeof(mon));

            temp ->id = ch;

            temp ->next = curr;

            curr ->prev ->next = temp ;

            temp ->prev = curr ->prev ;

            curr ->prev = temp ;

       }
    }
    curr = head ->next;

    while (curr!=tail){
        printf("%c",curr->id);
        curr=curr->next;
    }   printf("\n");

    return 0;
}

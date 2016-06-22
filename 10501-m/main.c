#include <stdio.h>
#include <stdlib.h>
typedef struct box
{
    char data[1];
    struct box *next;
    struct box *prev;
}box;
int main()
{
    char ch;
    box *head,*curr,*tail,*temp;
    head = (box*)malloc(sizeof(box));
    tail = (box*)malloc(sizeof(box));
    head ->next = tail ;
    tail ->prev = head ;
    tail -> next = tail ;
    curr = tail ;
    while((ch=getchar())!=EOF)
    {
        if(ch=='@')
        {
            curr = head -> next ;
        }
        else if(ch=='%')
        {
            if (curr ->next == tail||curr == tail)
            {
                continue ;
            }
            else
            {
                curr -> prev -> next = curr -> next ;
                curr -> next -> prev = curr -> prev ;
                curr = curr ->next ;
            }

        }
        else if(ch=='#')
        {
            curr = tail ;

        }
        else if(ch=='\n') break ;
        else
        {
            temp = (box*)malloc(sizeof(box));
            temp -> data[0] = ch;
            temp -> prev = curr -> prev ;
            curr -> prev -> next = temp ;
            temp -> next = curr ;
            curr -> prev = temp ;
        }
    }
    curr  =  head ->next ;
    while (curr != tail)
    {
        printf("%c",curr->data[0]);
        curr = curr -> next;
    }
    printf("\n");
    return 0;
}

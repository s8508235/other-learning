#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct group
{
    int num;
    char name[7];
    char member[100000][11];
    struct group *next;
} gp;
int main()
{
    gp *head,*curr,*temp,*last;
    char ch1[7];
    char ch2[11];
    int i = 0;
    head = (gp*)malloc(sizeof(gp));
    scanf("%s",ch1);
    strcpy(head->name,ch1);
    if(!strcmp(ch1,"END")) {
            printf("\n");
            return 0;
    }
    scanf("%s",ch2);
    head ->num = 0;
    strcpy(head->member[head->num],ch2);
    head ->num ++;
    curr = head;
    curr ->next = curr ;
    last = head;
    while(scanf("%s",ch1))
    {
        if(!strcmp(ch1,"END")) break ;
        curr = head ;
        while(1)
        {
            if(!strcmp(ch1,curr->name))
            {
                scanf("%s",ch2);
                strcpy(curr->member[curr->num],ch2);
                curr ->num++;
                break ;
            }
            else if(curr->next == curr)
            {
                temp = (gp*)malloc(sizeof(gp));
                strcpy(temp ->name ,ch1);
                scanf("%s",ch2);
                temp -> num = 0;
                strcpy(temp->member[temp->num],ch2);
                temp -> num ++;
                curr -> next = temp ;
                temp -> next = temp ;
                curr = temp ;
                last = temp ;
                break ;
            }
            else
            {
                curr = curr ->next;
            }
        }
    }
    printf("%s",last->name);
    for(i=0;i<last->num;i++){
            printf(" ");
        printf("%s",last->member[i]);
    }
    printf("\n");
    return 0;
}

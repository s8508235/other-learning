#include <stdio.h>
#include <stdlib.h>
typedef struct monkey
{
    char id;
    struct monkey *next;
}monkey;

int main()
{
    monkey *head,*curr,*tail;

    char ch;
    head = (monkey*) malloc(sizeof(monkey));
    curr = head;
    tail = head;
    int flag = 0;
    while (scanf("%c", &ch)!=EOF){
            if(ch == '@')
            {
                monkey *temp;

                if(flag !=3){

                scanf("%c",&ch);
                monkey *empty;
                empty = (monkey*) malloc(sizeof(monkey));
                temp = head;
                head = empty;
                head->id = ch;
                curr = head;
                }

                while(1){

                    scanf("%c",&ch);
                    //printf("%c\n",ch);
                    if(ch== '#'){
                            flag = 2;
                            curr->next = temp;
                            break;
                    }
                    else if(ch=='%')
                    {
                        //printf("%c\n",curr->id);
                        curr->next = temp->next;
                        //free(temp);
                        temp = curr->next;
                       // printf("%c\n",temp->id);

                    continue;

                    }
                    else if(ch == '\n') {
                           // printf("%c\n",curr->id);
                        curr->next = temp;
                    //printf("%c\n",temp->id);
                        flag = 1;
                        break;
                    }
                    curr->next =(monkey*) malloc(sizeof(monkey));
                    curr = curr->next;
                    curr->id = ch;
                }
            }
            if(ch== '#'||flag==2)
            {
                curr = tail->next;
                scanf("%c",&ch);
            }
            if(ch== '%')
            {
                monkey *fat;
                fat = curr->next;
                curr->next = fat->next;
                //free(fat);

                continue;
            }
            if(flag==1) break;


            curr->id = ch;

            tail = curr;
            curr->next = (monkey*) malloc(sizeof(monkey));
            curr = curr->next;
            flag =0;
    }
    tail->next =tail;

    curr=head;
    while (curr->next!=curr){
        printf("%c",curr->id);
        curr=curr->next;
    }
    printf("\n");

    return 0;
}

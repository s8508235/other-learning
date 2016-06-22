#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct group{
    char name[6];
    char mem[10];
    struct group *next;
    struct group *same;
}group;
int main()
{


    group *first,*curr,*last;
    first = (group*) malloc(sizeof(group));
    first ->next =NULL;
    first ->same = NULL;
    scanf("%s",first->name);
    //printf("%s\n",first->name);
    scanf("%s",first->mem);
    //printf("%s\n",first->mem);
    last = first ;
    char s[6];
    char c[10];
    int i;
    while (1){
            curr = first;
            scanf("%s",s);
            if(strcmp(s,"END")==0) break ;
            scanf("%s",c);



            //printf("%s\n",s);
            while (curr->next!=NULL){

                if(strcmp(curr->name,s)==0 ) break ;
                curr = curr->next;
            }
            if(strcmp(s,curr->name)!=0){

                curr -> next = (group*) malloc(sizeof(group));
                curr = curr->next;
                curr ->next = NULL;
                curr -> same = NULL;
                for(i=0;i<strlen(s);i++){
                    curr->name[i]=s[i];
                }
                curr ->name[i] = '\0';
               // printf("1:name:%s\n",curr->name);
                for(i=0;i<strlen(c);i++){
                    curr->mem[i]=c[i];
                }
                curr ->mem[i] = '\0';
                //printf("1:mem:%s\n",curr->mem);
                last = curr ;
            }
            else {
                    while (curr->same!=NULL){
                       curr = curr->same ;
                    }
                curr ->same = (group*) malloc(sizeof(group));
                curr = curr -> same;
                curr ->same =NULL;
                curr ->next =NULL;
                /*for(i=0;i<strlen(s);i++){
                    curr->name[i]=s[i];
                }curr ->name[i] = '\0';
                printf("2:name:%s\n",curr->name);*/
                for(i=0;i<strlen(c);i++){
                    curr->mem[i]=c[i];
                }
                curr ->mem[i] = '\0';
                //printf("2:mem:%s\n",curr->mem);
            }
           // printf("%s\n",c);

    }
    printf("%s ",last->name);
    while(1){
        printf("%s",last->mem);
        if(last->same==NULL) break;
        printf(" ");
        last = last -> same;
    }
    printf("\n");
    return 0;
}

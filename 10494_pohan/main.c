#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct _table
{
    int type_num;
    int place;
    struct _table *pre;
    struct _table *next;
}tab;

int main(void)
{
    int n,tag=1;
    int i;
    int A=0,B=0;
    tab *tb;
    tab *bk;
    tab *tmp,*table;
    char input[20];

    scanf("%d",&n);
    tb = (tab*)malloc(n*sizeof(tab));
    bk = (tab*)malloc(n*sizeof(tab));
    for(i=0;i<n;i++){
        tb[i].type_num = -1;
        tb[i].pre = NULL;
        tb[i].next = &bk[i];
        bk[i].type_num = i;
        bk[i].place = i;
        bk[i].pre = &tb[i];
        bk[i].next = NULL;
    }

    gets(input);
    gets(input);
    while(strncmp(input,"exit",4)){

        i=0;
        if(!strncmp(input,"move",4)){

            while(isdigit(input[i+5])){
                A = input[i+5]-'0'+ A*10;
                i++;
            }

            if(!strncmp(input+i+6,"onto",4)){

                while(isdigit(input[i+11])){
                    B = input[i+11]-'0' + B*10;
                    i++;
                }
                if(A == B || bk[A].place == bk[B].place)
                    tag=0;
                if(tag==1)
                {
                    tmp = &bk[A];
                    while(tmp != NULL){
                        tmp->pre->next = NULL;
                        table = &tb[tmp->type_num];
                        tmp->place = tmp->type_num;

                        while(table->next != NULL){
                            table = table->next;
                        }
                        //printf("table=%d",table->type_num);
                        table->next = tmp;
                        //printf(" %d",table->next->type_num);
                        tmp->pre = table;
                        //printf(" %d\n",tmp->pre->type_num);
                        tmp = tmp->next;
                    }

                    tmp = bk[B].next;
                    while(tmp != NULL){
                        tmp->pre->next = NULL;
                        table = &tb[tmp->type_num];
                        tmp->place = tmp->type_num;

                        while(table->next != NULL){
                            table = table->next;
                        }
                        //printf("list = %d,bk = %d\n",table->type_num,tmp->type_num);
                        table->next = tmp;
                        tmp->pre = table;
                        tmp = tmp->next;
                    }
                    tmp = bk[A].pre;
                    tmp->next = NULL;
                    bk[B].next = &bk[A];
                    bk[A].pre = &bk[B];
                    bk[A].next = NULL;
                    bk[A].place = bk[B].place;
                    /*for(i=0;i<n;i++){
                        printf("table = ");
                        tmp = &tb[i];
                        while(tmp != NULL){
                            printf(" %d",tmp->type_num);
                            tmp = tmp->next;
                        }
                        printf("\n");
                    }*/
                }
            }
            else{

                while(isdigit(input[i+11])){
                    B = input[i+11]-'0' + B*10;
                    i++;
                }
                if(A == B || bk[A].place == bk[B].place)
                    tag=0;
                if(tag==1)
                {
                tmp = &bk[A];
                while(tmp != NULL){
                    tmp->pre->next = NULL;
                    table = &tb[tmp->type_num];
                    tmp->place = tmp->type_num;

                    while(table->next != NULL){
                        table = table->next;
                    }
                    //printf("table=%d",table->type_num);
                    table->next = tmp;
                    //printf(" %d",table->next->type_num);
                    tmp->pre = table;
                    //printf(" %d\n",tmp->pre->type_num);
                    tmp = tmp->next;
                }

                table = &tb[bk[B].place];
                while(table->next != NULL){
                    table = table->next;
                }
                tmp = &bk[A];
                tmp->pre->next = NULL;
                table->next = tmp;
                tmp->pre = table;
                tmp->place = bk[B].place;

                /*for(i=0;i<n;i++){
                    printf("table = ");
                    tmp = &tb[i];
                    while(tmp != NULL){
                        printf(" %d",tmp->type_num);
                        tmp = tmp->next;
                    }
                    printf("\n");
                }*/
                }
            }

        }
        else if(!strncmp(input,"pile",4)){

            while(isdigit(input[i+5])){

                A = input[i+5]-'0'+ A*10;
                i++;
            }

            if(!strncmp(input+i+6,"onto",4)){

                while(isdigit(input[i+11])){
                    B = input[i+11]-'0' + B*10;
                    i++;
                }
                if(A == B || bk[A].place == bk[B].place)
                    tag=0;
                if(tag==1)
                {
                tmp = bk[B].next;
                while(tmp != NULL){
                    tmp->pre->next = NULL;
                    table = &tb[tmp->type_num];
                    tmp->place = tmp->type_num;

                    while(table->next != NULL){
                        table = table->next;
                    }
                    //printf("table=%d",table->type_num);
                    table->next = tmp;
                    //printf(" %d",table->next->type_num);
                    tmp->pre = table;
                    //printf(" %d\n",tmp->pre->type_num);
                    tmp = tmp->next;
                }

                tmp = &bk[A];
                tmp->pre->next = NULL;
                table = &tb[bk[B].place];
                while(table->next != NULL){
                    table = table->next;
                }

                while(tmp != NULL){
                    tmp->place = bk[B].place;
                    tmp->pre = table;
                    table->next = tmp;
                    tmp = tmp->next;
                    table = table->next;
                }

                /*for(i=0;i<n;i++){
                    printf("table = ");
                    tmp = &tb[i];
                    while(tmp != NULL){
                        printf(" %d",tmp->type_num);
                        tmp = tmp->next;
                    }
                    printf("\n");
                }*/
                }
            }

            else{

                while(isdigit(input[i+11])){
                    B = input[i+11]-'0' + B*10;
                    i++;
                }
                if(A == B || bk[A].place == bk[B].place)
                    tag=0;
                if(tag==1)
                {
                tmp = &bk[A];
                tmp->pre->next = NULL;
                table = &tb[bk[B].place];
                while(table->next != NULL){
                    table = table->next;
                }

                while(tmp != NULL){
                    tmp->place = bk[B].place;
                    tmp->pre = table;
                    table->next = tmp;
                    tmp = tmp->next;
                    table = table->next;
                }

               /* for(i=0;i<n;i++){
                    printf("table = ");
                    tmp = &tb[i];
                    while(tmp != NULL){
                        printf(" %d",tmp->type_num);
                        tmp = tmp->next;
                    }
                    printf("\n");
                }*/
                }
            }

        }

        A=0;B=0;tag=1;
        gets(input);
    }



    for(i=0;i<n;i++){
        printf("%d:",i);
        tmp = tb[i].next;
        while(tmp != NULL){
            printf(" %d",tmp->type_num);
            tmp = tmp->next;
        }
        printf("\n");
    }
    free(tb);
    free(bk);

    return 0;
}

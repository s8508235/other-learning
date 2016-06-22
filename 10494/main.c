#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct table{
    struct bo *book;
    int id;
    struct table *next;

}table;
typedef struct bo{
    struct bo *next;
    int id;
}bo;
void mt(int num,int ber);
void mv(int num,int ber);
void pt(int num,int ber);
void pv(int num,int ber);
table *head,*curr;
void re(table *a);
int n;
char mo[]={'m','o','v','e','\0'};

char on[]={'o','n','t','o','\0'};

char er[]={'o','v','e','r','\0'};

char pi[]={'p','i','l','e','\0'};

char it[]={'e','x','i','t','\0'};
int main()
{
    //printf("%s %s %s %s %s\n",mo,on,er,pi,it);
    scanf("%d",&n);
    int i;
    bo *top;
    head = (table*) malloc(sizeof(table));
    head -> id = 0;
    top = (bo*) malloc(sizeof(bo));
    top -> id = 0;
    top -> next = top ;
    head -> book = top  ;
    curr = head ;

    for(i=1;i<n;i++){
            bo *rad;
        rad = (bo*) malloc(sizeof(bo));
        rad -> id = i;
        rad -> next = rad ;
        curr -> next = (table*) malloc(sizeof(table));
        curr = curr -> next ;
        curr -> book = rad;
        curr -> id = i ;
    }


    char ch[4];
    char ch1[4];

    int num;
    int ber;

    while(1){
           // printf("@@\n");
            scanf("%s",ch);


            if((strcmp(ch,mo))==0){
                    //printf("*");
                    scanf("%d",&num);
                   // printf("num success");
                    scanf("%s",ch1);
                   // printf("ch1 success");
                    if(strcmp(ch1,on)==0){
                       // printf("**");
                        scanf("%d",&ber);
                        mt(num,ber);
                    }
                    else if(strcmp(ch1,er)==0){
                        scanf("%d",&ber);
                        mv(num,ber);
                    }
            }
            else if(strcmp(ch,pi)==0){
                     scanf("%d",&num);
                     scanf("%s",ch1);
                    if(strcmp(ch1,on)==0){
                        scanf("%d",&ber);
                        pt(num,ber);
                    }
                    else if(strcmp(ch1,er)==0){
                        scanf("%d",&ber);
                        pv(num,ber);
                    }
            }
            else if(strcmp(ch,it)==0){
                break;
            }



    }
    table *show;
    show = head ;
    for(i=0;i<n;i++)
    {
        printf("%d:",show -> id);
        while(show -> book != NULL){
            printf("%d ",show -> book-> id);
            show -> book = show -> book -> next;
        }
        show = show -> next;
    }


    return 0;
}
void mt(int num,int ber){
    //printf("%d %d\n",num,ber);
    int i;
    table *a,*b;
    a = head ;
    for(i=0;i<num;i++){
        a = a->next ;
    }
    //printf("fat\n");
    re(a);
    b = head ;
    for(i=0;i<ber ; i++){
        b = b->next ;
    }
    //printf("fbt\n");
    re(b);
    //printf("re com\n");
    b -> book ->next = a -> book ;
    printf("%d\n",b->book->next->id);
    a -> book = NULL;
}
void mv(int num,int ber){
     int i;
    table *a,*b;
    a = head ;
    for(i=0;i<num;i++){
        a = a->next ;
    }
    re(a);
    b = head ;
    for(i=0;i<ber ; i++){
        b = b->next ;
    }
    bo *fat;
    fat = b -> book ;
    while (fat->next!=fat){
            printf("QQ\n");
         fat = fat -> next;
    }
    fat -> next = a -> book;
    a -> book = NULL;
}
void pt(int num,int ber){
     int i;
    table *a,*b;
    a = head ;
    for(i=0;i<num;i++){
        a = a->next ;
    }

    b = head ;
    for(i=0;i<ber ; i++){
        b = b->next ;
    }
}
void pv(int num,int ber){
     int i;
    table *a,*b;
    a = head ;
    for(i=0;i<num;i++){
        a = a->next ;
    }
    b = head ;
    for(i=0;i<ber ; i++){
        b = b->next ;
    }
}
void re(table *a){
    bo *chan;
    chan = a -> book ;
    //printf("%d\n",chan->id);
    //printf("enter a\n");
    while (chan->next!=chan){
            printf("QQ\n");
         chan = chan -> next;
    }
    //printf("check book \n");
    if(a -> book -> id == a -> id ) return ;
    table *change ;
    change = head ;
    while(1){
        change = change -> next ;
        if(change -> id == chan -> id ) {
                change -> book = chan ;
                break ;
        }
    }
    printf("return books\n");


    re(a);

}

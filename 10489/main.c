#include <stdio.h>
#include <stdlib.h>

typedef struct man{

    int id;
    struct man* next;
}man;
int m[28000];
int p[3000];
int main()
{
    int i,j;
    for(i=2;i<27500;i++)
    {
        m[i]=1;
    }
    for(i=2;i<27500;i++)
    {
        if(m[i]==1)
        {
            for(j=i*i;j<27500;j+=i)
            {
                if((j%i)==0) m[j]=0;
            }
        }
    }
    j=1;
    for(i=2;i<27500;i++)
    {
        if(m[i]){

            p[j]=i;
            j++;
        }
    }

    int n;
    while ((scanf("%d",&n)!=EOF)){
    man *head,*curr,*temp;

    head = (man*)malloc(sizeof(man));

    curr=head;
    head->id = 1;

    for(i=2;i<=n;i++)
    {
        curr->next =(man*)malloc(sizeof(man));
        curr = curr->next;
        curr-> id = i;
    }
    curr->next = head;
    temp = head;
    int flag=1;

    j=1;
    while (1)
    {
            if(temp->next == temp) {
                    flag = 0;
                    break;
            }
        for(i=0;i<((p[j]%n)-1+p[j])%p[j];i++)
        {

            curr=temp;
            temp=temp->next;
        }
            if(flag ==0) break;

        curr->next = temp->next;

        free(temp);
        temp = curr->next;
        j++;
        n--;
    }
    printf("%d",temp->id);
    }
    return 0;
}

#include<stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct _node
{
    int num;
    int next;
}man;


int b[1000000]={0};
int main(void)
{
    int i,k=0,x,tmp;
    unsigned j;
    int a[100000]={0};
    man *z;


    for(i=2;i<1000000;i++)
        if(b[i]==0){
            for(j=i+i;j<1000000;j=j+i)
                b[j]=1;
        }

    for(i=2;i<200000;i++){
        if(k>=100000)break;
        if(b[i]==1){
            a[k]=i;
            k++;
        }
    }

    while(scanf("%d",&k)!=EOF)
    {
        z = (man*)malloc(k*sizeof(man));

        for(i=0;i<k;i++){
            z[i].num = i;
            z[i].next = i+1;
        }
        z[k-1].next = 0;
        i=0;
        j=0;
        for(;k>1;k--){

            if(a[j]%k==0)x=k;
            else x=a[j]%k;

            //printf("x=%d\n",x);
            for(;x>1;x--){
                tmp = i;
                i = z[i].next;
            }
            //printf("i=%d\n\n",z[i].num);
            z[tmp].next = z[i].next;
            i = z[i].next;
            j++;
        }
        printf("%d\n",z[i].num+1);

    }

    return 0;
}

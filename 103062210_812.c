#include <stdio.h>
#include <stdlib.h>
int pro_case[51][21];/*all case*/
int num[51];/*amount of number for each case*/
int ans_case[51][21];
int max_pro[51];
int ans[1100];
int w;
void searching(int a,int sum,int index,int amount,const int largest)
{
    if(a<w)
    {
        if(sum==largest && index<=num[a])
        {
            ans_case[a][amount]=1;
        }
        if(index<num[a])
        {
                int x = pro_case[a][index];
                searching(a,sum+x,index+1,amount+1,largest);
                index = -1;
                amount = -1;
        }
    }
}
void putting(int a,int b,int total)
{
    if(a<w)
    {
        if(b<=num[a])
        {
            if(ans_case[a][b])
            {

                putting(a+1,0,total+b);
                putting(a,b+1,total);
            }
            else
            {
                putting(a,b+1,total);
            }
        }
        else
        {
        }
    }
    else
    {
            ans[total] = 1;
            return ;
    }

    return ;
}
int main()
{
    int zzz=0;
    while(scanf("%d",&w) && w>0)
    {
        if(zzz>0) printf("\n");
        zzz++;
        int i,j;/*standard input*/

        for(i=0;i<1100;i++)
        {
            ans[i] = 0;
        }
        for(i=0;i<w;i++)
        {
            int max_temp_pro = -1,case_pro = 0;
            scanf("%d",&num[i]);
            if(num[i]>0)
            {
                for(j=0;j<num[i];j++)
                {
                    int z;
                    scanf("%d",&z);
                    pro_case[i][j] = 10-z;
                    case_pro +=pro_case[i][j];
                    if(case_pro>=max_temp_pro)
                    {
                        max_temp_pro = case_pro;
                    }
                }
                max_pro[i] = max_temp_pro;
                if(max_pro[i]<0)
                {
                    for(j=0;j<num[i];j++)
                    {
                        pro_case[i][j] = 0;
                    }
                    w--,i--;
                }
            }
            else w--,i--;
        }/*count each case's max profit        */
        int max_profit = 0;
        for(i=0;i<w;i++)
        {
            max_profit += max_pro[i];
            searching(i,0,0,0,max_pro[i]);
        }/*
        printf("collection:\n");
        for(i=0;i<w;i++)
        {
            for(j=0;j<21;j++)
                if(ans_case[i][j])
                    printf("%d ",j);
            printf("\n");
        }*/
        putting(0,0,0);
        int cnt = 0;
        printf("Workyards %d\n",zzz);
        printf("Maximum profit is %d.\n",max_profit);
        printf("Number of pruls to buy:");
        i=0;
        cnt = 0;
        while(cnt<10 && i<1100)
        {
            if(ans[i]==1)
            {
                printf(" %d",i);
            cnt++;
            }
            i++;
        }
        printf("\n");
        for(i=0;i<w;i++)/*clear*/
        {
            for(j=0;j<21;j++)
            {
                pro_case[i][j]=0;
                ans_case[i][j]=0;
            }
            num[i]=0;
            max_pro[i]=0;
        }
    }
    return 0;
}

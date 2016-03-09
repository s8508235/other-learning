#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
typedef struct bignum
{
int num[1001];
int size;
}bignum;
int main()
{
    int N;
    scanf("%d",&N);
    int i;
    for(i=0;i<N;i++)
    {
        char x[1001];
        scanf("%s",x);
        int length = strlen(x);
        int j = 0;
        bignum cal;
        cal.size = length;
        for(j = length-1;j>=0;j--)
        {
            cal.num[length-j-1] = x[j]-'0';
        }
        for(j=0;j<cal.size;j++)
        {
            printf("%d ",cal.num[j]);
        }printf("\n");


        bignum ans;
        ans.size = (length%2)?((length+1)/2):(length/2);
        printf("length:%d\n",length);
        for(j=0;j<ans.size;j++)
        {
            ans.num[j] = 0;
        }
        printf("size of ans:%d\n",ans.size);
        int ans_fat = ans.size;
        j = cal.size-1;
        int rem = 0;
        while(ans_fat>=0)
        {
            if(ans_fat%2)
            {
                printf("1:std:%d %d \n",cal.num[j],cal.num[j-1]);
                double z  = cal.num[j]*100 + cal.num[--j]*10 + cal.num[--j]+ rem;
                printf("current z:%f\n",z);
                ans.num[ans_fat] = sqrt((z));/*testing
                int zz = sqrt(z);
                */
                rem = z - ans.num[ans_fat]*ans.num[ans_fat];printf("rem:%d\n",rem );
                rem*=100;
                ans_fat--;
                printf("current ans_Fat:%d\n",ans_fat);
            }
            else
            {
                printf("0:std:%d %d \n",cal.num[j],cal.num[j-1]);
                double z  = cal.num[j]*10 + cal.num[--j]+ rem;
                printf("current z:%f\n",z);
                ans.num[ans_fat] = sqrt((z));/*testing
                int zz = sqrt(z);
                */
                rem = z - ans.num[ans_fat]*ans.num[ans_fat];printf("rem:%d\n",rem );
                rem*=100;
                ans_fat--;
                printf("current ans_Fat:%d\n",ans_fat);
            }
        }
    }
    return 0;
}

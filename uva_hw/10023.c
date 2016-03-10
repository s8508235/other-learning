#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
typedef struct bignum
{
int num[1001];
int size;
}bignum;
void p_bignum(bignum a);
bignum bignum_shift(bignum diver,int x);
bignum rem;
bignum multbignum(bignum a,int b)
{
    int i;
    bignum ans;
    for(i=0;i<1000;i++)
    {
        ans.num[i] = 0;
    }
    int carry = 0;
    for(ans.size= 0;ans.size<a.size||carry;ans.size++)
    {
        ans.num[ans.size] = a.num[ans.size] * b+carry;
        carry = ans.num[ans.size] / 10;
        ans.num[ans.size] %= 10;
    }
    if(ans.num[ans.size]) ans.size ++;

    p_bignum(ans);
    return ans;
}
int cmp_bignum(bignum x,bignum y)
{
    if(x.size>y.size)
    {
        return 0;
    }
    else if (x.size==y.size)
    {
        int i ;
        for(i=x.size-1;i>=0;i--)
        {
            if(x.num[i]>y.num[i])
            {
                return 0;
            }
            else if (x.num[i]==y.num[i])
            {
                if(i==0)
                {
                    printf("equal!\n");
                    return 1;
                }
            }
            else return 1;
        }
    }
    else
    {
        return 1;
    }
}
bignum sub_bignum(bignum y,bignum x)
{
    int i;
    bignum re;
    for(i=0;i<1000;i++)
    {
        re.num[i] = 0;
    }
    for(i=0;i<y.size;i++)
    {
        if(x.num[i] > y.num[i])
        {
            y.num[i+1]--;
            re.num[i] = y.num[i]+10-x.num[i];
        }
        else
            re.num[i] = y.num[i]-x.num[i];
    }
    if(re.num[y.size-1]) re.size = y.size;
    else re.size = y.size -1 ;

    if(re.size==0) re.size = 1;
    printf("sub the num!\n");
    p_bignum(re);
    return re;
}
int searching(bignum x,bignum y)
{
    int i;
    for(i=9;i>0;i--)
    {
        x.num[0] = i;
        printf("searching x:\n");
        p_bignum(x);
        if(cmp_bignum(multbignum(x,i),y))
        {
            rem =sub_bignum(y,multbignum(x,i));
            printf("find rem!\n");
            p_bignum(rem);
            break;
        }
    }
    if(i==0) rem = y;
    return i;
}
bignum bignum_shift(bignum diver,int x)
{
    int i ;
    for(i=diver.size;i>=0;i--)
    {
        diver.num[i+x] = diver.num[i];
    }
    diver.size +=x;
    for(i=x-1;i>=0;i--)
        diver.num[i] = 0;
    printf("end shift\n");
    p_bignum(diver);
    return diver;
}
bignum additself(bignum a)
{
    a.num[0] += a.num[0];
    printf("dup:%d\n",a.num[0]);
    int i ;
    for(i=a.size-1;i>=0;i--)
    {
        if(a.num[i]>9)
        {
            a.num[a.size] = a.num[a.size-1]/10;
            a.num[a.size-1]%=10;
        }
    }
    if(a.num[a.size]) a.size++;

    p_bignum(a);
    return a;
}
void p_bignum(bignum a)
{
    int i;
    printf("len of bignum:%d\n",a.size);
    for(i=a.size-1;i>=0;i--)
    {
        printf("%d",a.num[i]);
    }
    printf("\n");
}
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
      //  printf("create cal num\n");
       // p_bignum(cal);
        bignum ans;
        ans.size = (length%2)?((length+1)/2):(length/2);
        int ans_fat = ans.size-1;

        bignum diver;/*diver to store the number which is */
        diver.size = 1;
        rem.size = 0;
        for(j=0;j<1001;j++)
        {
            ans.num[j] = 0;
            diver.num[j] = 0;
            rem.num[j] = 0;
        }
        if(length%2)
        {
            j = cal.size;
            cal.num[j] = 0;
        }
        else
        {
            j = cal.size-1;
        }
        while(j>0)
        {
            bignum sub;
       //     printf("copy rem\n");
            sub.size = rem.size;
            int z;
            for(z= 0 ;z<rem.size;z++)
            {
                sub.num[z] = rem.num[z];
            }
                sub = bignum_shift(sub,2);
                sub.num[1] = cal.num[j];
                sub.num[0] = cal.num[j-1];
                for(z=sub.size-1;z>=0;z--)
                {
                    if(sub.num[z]==0)
                    {
                    //    printf("down!\n");
                        sub.size--;
                    }
                    else break;
                }
             //   printf("create sub num\n");
                p_bignum(sub);
              //  printf("start searching\n");
                diver.num[0] = searching(diver,sub);
            //    printf("current ans:%d\n",diver.num[0]);
                ans.num[ans_fat] =  diver.num[0];
                ans_fat--;
                j-=2;
            if( (rem.size> 1) && (rem.num[0]>0) || (j>0))
            {
           //     printf("add itself\n");
                diver = additself(diver);
          //      p_bignum(diver);
         //       printf("shift\n");
                diver = bignum_shift(diver,1);
          //      p_bignum(diver);
            }
            else
            {
                break;
            }
        }
        p_bignum(ans);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
struct Adder
{
    long long int a;
    long long int b;
    long long int ans;
};
struct Adder ad[1000000];
int cmp(const void *a,const void *b)
{
    struct Adder x1,x2;
    x1 = *(struct Adder*)(a);
    x2 = *(struct Adder*)(b);
    if(x1.ans>x2.ans) return 1;
    else if (x1.ans==x2.ans)return 0;
    else return -1;
}
int cmp_int(const void *a,const void *b)
{
    long long int x,y;
    x =*(int*) a;
    y =*(int*) b;
    if(x>y) return 1;
    else if (x==y)return 0;
    else return -1;
}
int searching(int x,int y,int w,struct Adder ad[])
{
    int up = w-1;
    int lw= 0;
    int ans = x-y;/*
            printf("up:%d ans:%lld\n",up,ans);*/
    int mid ;
    while(up>=lw)
    {
        mid =(up+lw)/2;
        if(ad[mid].ans<ans)
            lw = mid+1;
        else if(ad[mid].ans>ans)
            up = mid-1;
        else
        {
            int k ;
            for(k=mid; k<=up; k++)
            {
                if(ad[mid].ans!=ans)
                    break;
                if(x!=ad[mid].a && x!=ad[mid].b && y!=ad[mid].a && y!=ad[mid].b)
                    return 1;
            }
            for(k=mid-1; k>=lw; k--)
            {
                if(ad[mid].ans!=ans)
                    break;
                if(x!=ad[mid].a && x!=ad[mid].b && y!=ad[mid].a && y!=ad[mid].b)
                    return 1;
            }
            return 0;
        }
    }
    return 0;
}
int main()
{
    int S;

    while(scanf("%d",&S)==1&&S)
    {
        long long int se[S];
        int i,j;
        for(i=0; i<S; i++)
            scanf("%lld",&se[i]);
        qsort(se,S,sizeof(se[0]),cmp_int);
        int w= 0;
        for(i=0; i<S; i++)
        {
            for(j=i+1; j<S; j++)
            {
                ad[w].a=se[i];
                ad[w].b=se[j];
                ad[w].ans = se[i]+se[j];
                w++;
            }
        }
        qsort(ad,w,sizeof(ad[1]),cmp);/*print ad.ans
            for(i=0;i<w;i++)
                printf("%lld\n",ad[i].ans);*/
        int flag= 0;
        long long int ans=0;
        for(i=S-1; i>=0; i--)
        {
            for(j=0; j<S; j++)
            {
                if(i==j) continue;
                int searesult = searching(se[i],se[j],w,ad);
                if(searesult)
                {
                    if(!flag)
                    {
                        ans= se[i];
                        flag = 1;
                    }
                    else if(se[i]>ans) ans = se[i];
                }
                /*
                printf("%d\n",mid);
                printf("found num:%lld\n",ad[mid].ans);*/
            }

        }
            if(flag==0) printf("no solution\n");
            else printf("%lld\n",ans);
            for(i=0; i<w; i++)
            {
                ad[i].a=0;
                ad[i].b=0;
                ad[i].ans = 0;
            }
    }


    return 0;
}

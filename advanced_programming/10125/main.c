#include <stdio.h>
#include <stdlib.h>
int elements[1000];
struct a_plus_b
{

    int a;

    int b;

    int sum;

};
struct a_plus_b x[1000000];

int search_comp(int d, int c, int x_index, int x_index_tb[])
{
    int i,lower_bound=0, upper_bound=x_index-1, mid;
    struct a_plus_b value;
    int y = d-c;
    while(lower_bound <= upper_bound)
    {
        mid = (lower_bound+upper_bound)/2;
        value = x[x_index_tb[mid]];
        if(value.sum > y) upper_bound = mid-1;
        else if(value.sum < y) lower_bound = mid+1;
        else
        {
            for(i = mid; i <= upper_bound; i++)
            {
                if(value.sum != y)
                    break;
                if(d!=value.a && d!=value.b && c!=value.a && c!=value.b)
                    return 1;
            }
            for(i = mid-1; i >= lower_bound; i--)
            {
                if(value.sum != y)
                    break;
                if(d!=value.a && d!=value.b && c!=value.a && c!=value.b)
                    return 1;
            }
            return 0;
        }
    }
    return 0;
}
int comp_func(const void *a, const void *b)
{
    int c = x[*(int*)a].sum;
    int d = x[*(int*)b].sum;
    if (c>d) return 1;
    else if (c< d) return -1;
    else return 0;
}
int main()
{
    int i, j, element_num;
    while(scanf("%d",&element_num)==1 && element_num)
    {
        int x_index = 0;
        int x_index_tb[element_num*(element_num-1)/2];
        for (i=0; i< element_num; i++)
            scanf("%d", &elements[i]);
        for (i=0; i< element_num; i++)
        {
            for (j=i+1; j< element_num; j++)
            {
                x[x_index].sum = elements[i]+elements[j];
                x[x_index].a = elements[i];
                x[x_index].b = elements[j];
                x_index_tb[x_index] = x_index;
                x_index++;
            }
        }
        qsort(x_index_tb, x_index, sizeof(int), comp_func);
        int y1bs, max=0, flag=0;
        for (i=element_num-1; i>=0; i--)
        {
            for (j=0; j< element_num; j++)
            {
                if (i==j) continue;
                y1bs = search_comp(elements[i], elements[j], x_index, x_index_tb);
                if(y1bs == 1)
                {
                    if (flag==0)
                    {
                        max = elements[i];
                        flag = 1;
                    }
                    else if (elements[i]>max) max = elements[i];
                }
            }
        }
        if (flag==1)
            printf("%d\n",max);
        else
            printf("no solution\n");
    }
    return 0;
}

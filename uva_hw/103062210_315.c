#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct rel
{
    int NO;
    struct rel *next;
}rel;
typedef struct dfs_rel
{
    int NO;
    struct rel *next;
    int color;
}dfs_rel;
typedef enum {WHITE,GRAY,BLACK}dfs_color;
dfs_rel **net;
int N;
void search_pnt(int pos);
int cnt;
void reset_color()
{
    int i;
    for(i=1;i<=N;i++)
    {
        net[i]->color = WHITE;
    }
}
int cnt_cri()
{
    int i ;
    int ans = 0;
    for(i=1;i<=N;i++)
    {
        cnt = 0;
        net[i]->color = GRAY;

        if(i<N)
        search_pnt(i+1);
        else
        search_pnt(1);
        reset_color();
        if(cnt !=N-1) ans++;
    }
    return ans;
}
void search_pnt(int pos)
{
    rel *curr = malloc(sizeof(rel));
    if(net[pos]->color !=BLACK)
    {
        if(net[pos]->color ==WHITE)
        {
            cnt++;
            net[pos]->color = GRAY;
        }
        else return ;
        curr = net[pos]->next ;
        if(curr !=NULL)
        {
            while(1)
            {
                search_pnt(curr->NO);
                if(curr->next ==NULL)
                {
                    net[pos]->color = BLACK;
                    break;
                }
                else
                    curr = curr->next;
            }
        }
    }
    return ;
}
int main()
{
    int i;
    while(scanf("%d",&N) && N>0)
    {
        net = malloc(sizeof(dfs_rel)*(N+1));
        for(i=0;i<=N;i++)
        {
            net[i] = malloc(sizeof(dfs_rel));
            net[i]->NO = i;
            net[i]->next = NULL;
            net[i]->color = WHITE;
        }
        int in;
        while(scanf("%d",&in) && in>0)
        {
            char des = 'a';
            char c;
            scanf("%c",&c);
            if(c=='\n') continue;
            while(des!='\n')
            {
                int dir;
                scanf("%d%c",&dir,&des);/*num and space*/
                rel *tmp;
                tmp = malloc(sizeof(rel));
                tmp->next = NULL;
                tmp->NO = dir;
                rel *curr;
                curr = malloc(sizeof(rel));
                curr->next = NULL;
                curr->NO = in;
                if( NULL == net[in]->next)
                    net[in]->next = tmp;
                else
                {
                    rel *curr_rel= malloc(sizeof(rel));
                    curr_rel = net[in]->next;
                    while(curr_rel->next!=NULL)
                    {
                        curr_rel = curr_rel->next;
                    }
                    curr_rel->next = tmp;
                }
                if(NULL == net[dir]->next)
                    net[dir]->next = curr;
                else
                {
                    rel *curr_rel = malloc(sizeof(rel));
                    curr_rel = net[dir]->next;
                    while(curr_rel->next!=NULL)
                    {
                        curr_rel = curr_rel->next;
                    }
                    curr_rel->next = curr;
                }
            }
        }
        int critical;
        critical = cnt_cri();
        printf("%d\n",critical);
    }
    return 0;
}

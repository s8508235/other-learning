#include <stdio.h>
#include <stdlib.h>
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
dfs_rel **relation;
int max_relation_cnt,curr_relation_cnt;
void DFS(int pos)
{
    rel *curr = malloc(sizeof(rel));
    if(relation[pos]->color !=BLACK)
    {
        if(relation[pos]->color ==WHITE)
        {
            curr_relation_cnt++;
            relation[pos]->color = GRAY;
        }
        else return ;
        curr = relation[pos]->next ;
        if(curr !=NULL)
        {
            while(1)
            {
                DFS(curr->NO);
                if(curr->next ==NULL)
                {
                    relation[pos]->color = BLACK;
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
    int t;
    scanf("%d",&t);
    int i;
    for(i=0;i<t;i++)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        relation = malloc(sizeof(dfs_rel)*(n+1));
        int j;
        for(j=0;j<n;j++)
        {
            relation[j] = malloc(sizeof(dfs_rel));
            relation[j]->NO = j;
            relation[j]->next=NULL;
            relation[j]->color = WHITE;
        }
        max_relation_cnt=0;
        for(j=0;j<m;j++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            a--;
            b--;
            if(relation[a]->next ==NULL)
            {
                rel *new_rel;
                new_rel = malloc(sizeof(rel));
                new_rel->NO = relation[b]->NO;
                new_rel->next = NULL;
                relation[a]->next = new_rel;
            }
            else
            {
                rel *new_rel;
                new_rel = malloc(sizeof(rel));
                rel *curr_rel;
                curr_rel = relation[a]->next;
                new_rel->NO = relation[b]->NO;
                new_rel->next = NULL;
                while(curr_rel->next!=NULL)
                    curr_rel = curr_rel->next;
                curr_rel ->next = new_rel;
            }
            /*undirect */
            if(relation[b]->next ==NULL)
            {
                rel *new_rel;
                new_rel = malloc(sizeof(rel));
                new_rel->NO = relation[a]->NO;
                new_rel->next = NULL;
                relation[b]->next = new_rel;
            }
            else
            {
                rel *new_rel;
                new_rel = malloc(sizeof(rel));
                rel *curr_rel;
                curr_rel = relation[b]->next;
                new_rel->NO = relation[a]->NO;
                new_rel->next = NULL;
                while(curr_rel->next!=NULL)
                    curr_rel = curr_rel->next;
                curr_rel->next = new_rel;
            }
        }
        for(j=0;j<n;j++)
        {
            curr_relation_cnt = 0;
             DFS(relation[j]->NO);
            if(curr_relation_cnt > max_relation_cnt)
                max_relation_cnt = curr_relation_cnt;
        }
        if(max_relation_cnt == 1) printf("0\n");
        else printf("%d\n",max_relation_cnt);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int maps[1000][1000];/*11463*/
int start_city,end_city;
int city_num,path_num;
int path[1000];
int vis[1000];
int ans[1000];
void print_path(int num)
{
    int i;
    printf("path->");
    for(i=0; i<num; i++)
        printf("%2d",path[i]);
    printf("\n");
}
void print_ans()
{
    int i;
    printf("ans->");
    for(i=0; i<city_num; i++)
        printf("%2d",ans[i]);
    printf("\n");
}
void BFS(int start)
{
    memset(path,200,sizeof(path));
    memset(vis,0,sizeof(vis));
    memset(ans,0,sizeof(ans));
    int p = 0, q = 0;
    path[q++] =start;
    vis[start] = 1;
    while(q > p)
    {
        int i;
        int p_find = path[p ++];
        for(i=0; i<city_num; i++)
        {
            if(maps[p_find][i] == 1 && vis[i] == 0)
                path[q++] = i,ans[i] = ans[p_find] + 1,vis[i] = 1;;
        }
      //print_path(go_path_num);
    }
     //print_ans();
}
int main()
{
    int case_num,cases = 1;
    scanf("%d",&case_num);
    while(case_num --)
    {
        memset(maps,0,sizeof(maps));
        scanf("%d%d",&city_num,&path_num);
        int i,j,k;
        for ( i = 0; i < city_num; ++ i)
        {
            for ( j = 0; j < city_num; ++ j)
                maps[i][j] = 101;
            maps[i][i] = 0;
        }
        for(i=0; i<path_num; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            maps[a][b] = maps[b][a] = 1;
        }
        scanf("%d%d",&start_city,&end_city);
        for ( k = 0; k < city_num; ++ k)
		for ( i = 0; i < city_num; ++ i)
		for ( j = 0; j < city_num; ++ j)
			if (maps[i][j] > maps[i][k]+maps[k][j])
				maps[i][j] = maps[i][k]+maps[k][j];
        int max_num = 0;
        for ( k = 0; k < city_num; ++ k)
			if (max_num < maps[start_city][k]+maps[k][end_city])
				max_num = maps[start_city][k]+maps[k][end_city];
        printf("Case %d: %d\n",cases++,max_num);
        /*
        BFS(start_city);
        int tmp[city_num];
        for(k=0; k<city_num; k++)
            tmp[k] = ans[k];
        int ans_num[city_num];
        BFS(end_city);
        for(k=0; k<city_num; k++)
        {
            ans_num[k]  = tmp[k] + ans[k];
        }

        int max_num = tmp[end_city];
        for(i=0; i<city_num; i++)
        {
            if(max_num < ans_num[i])
                max_num = ans_num[i];
        }
        printf("Case %d: %d\n",cases++,max_num);*/
    }
    return 0;
}

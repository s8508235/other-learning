#include <stdio.h>
#include <string.h>
int link[21][21][101];
int size[21][21];
int cost[21];

int used[21];
int Q[21];
void bfs(int n)
{
    int i,j;
    for ( i = 0; i < 21; ++ i)
    {
        cost[i] = 20002;
        used[i] = 0;
    }
    used[1] = 1;
    cost[1] = 0;
    Q[0] = 1;

    int move = 0,save = 1;
    while (move < save)
    {
        int now = Q[move ++];
        int min = 20002,New = 0;
        for ( i = 2; i <= n; ++ i)
        {
            if (used[i]) continue;
            for ( j = 0; j < size[now][i]; ++ j)
            {
                int costnew = cost[now]/100*100+link[now][i][j];
                if (costnew%100 < cost[now]%100)
                    costnew = costnew+100;
                if (cost[i] > costnew)
                    cost[i] = costnew;
            }
            if (min > cost[i])
            {
                min = cost[i];
                New = i;
            }
        }
        if (New)
        {
            Q[save ++] = New;
            cost[New] = min;
            used[New] = 1;
        }
    }

    if (save == n)
        printf("%d\n",cost[Q[save-1]]);
    else printf("-1\n");
}

int main()
{
    int T,n,k,a,b,m,t,i,j;
    scanf("%d",&T);
    while (T --)
    {
        scanf("%d%d",&n,&k);
        memset(size, 0, sizeof(size));
        for ( i = 0; i < k; ++ i)
        {
            scanf("%d%d%d",&a,&b,&m);
            for ( j = 0; j < m; ++ j)
            {
                scanf("%d",&t);
                link[a][b][size[a][b] ++] = t;
                link[b][a][size[b][a] ++] = t;
            }
        }

        bfs(n);
    }
    return 0;
}

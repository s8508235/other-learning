#include <cstdio>
#include <cstdlib>
using namespace std;
struct edge {
    int start;
    int end;
    int dist;
} graph[300000];
int n, m;
int cmp(const void *a, const void *b){
    edge *p = (edge *) a;
    edge *q = (edge *) b;
    return p->dist - q->dist;
}
int main()
{
    while(scanf("%d %d",&m ,&n) != EOF){
        int total = 0;
        for (int i = 0; i < n; i++){
            scanf ("%d %d %d", &graph[i].start, &graph[i].end, &graph[i].dist);
        }
        qsort(graph, n, sizeof(graph[0]), cmp); //sort edges by its cost

        int i =0;
        int zz=0;
        int flag[n];
            for(int b = 0;b<m;b++)
            {

                   flag[b]=-1;
            }
        while(zz<m-1&&i<n)
        {

            if(flag[graph[i].start]==flag[graph[i].end]&&flag[graph[i].start]>=0&&flag[graph[i].end]>=0)
            {
                zz--;
            }
            else
            {
                graph[n+zz] = graph[i];
                if(flag[graph[i].end]>=0 && flag[graph[i].start]>=0)
                {
                    int w = flag[graph[i].end];
                    for(int b = 0;b<m;b++)
                    {
                        if(flag[b]==w)
                        {
                            flag[b] = flag[graph[i].start];
                        }
                    }
                }
                else if (flag[graph[i].end]<0 && flag[graph[i].start]>=0)
                {
                    flag[graph[i].end] = flag[graph[i].start];
                }
                else if (flag[graph[i].end]>=0 && flag[graph[i].start]<0)
                {
                  flag[graph[i].start] =   flag[graph[i].end];
                }
                else
                {
                      flag[graph[i].end] = graph[i].start;
                      flag[graph[i].start] = graph[i].start;
                }
            }
            i++;
            zz++;

        }
        for(i = n;i<n+zz;i++)
        {
            total +=graph[i].dist;
        }
        printf ("%d\n", total);
    }
    return 0;
}

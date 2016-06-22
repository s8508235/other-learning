#include <iostream>

using namespace std;
class lines
{
public:

    int x;
    int y;
    int  **line;
    int **to_x;
private:

};
int main()
{
    lines *a;
    a = new lines;
    int i,l;
    cin>>a->y>>a->x>>l;
    a->y++;
    a->x++;
    a->line = new int*[a->x];
    a->to_x = new int*[a->x];
    for( i =0;i<a->x;i++)
    {
        a->line[i] = new int[a->y];
        a->to_x[i] = new int[a->y];
    }
    int j;
    int flag[a->x][a->y];
    for(i=0;i<a->x;i++)
    {
        for(j=0;j<a->y;j++)
        {
            flag[i][j] = 0;
            a->line[i][j]=-1;
            a->to_x[i][j]=-1;
        }
    }
    for(i=1;i<=l;i++)
    {
        int w,x,y;
        cin>>w>>x>>y;
        a->line[w][x] = y;//抵達之y
        a->to_x[w][x] = w+1;//抵達之x
        a->line[w+1][y] = x;//抵達之y
        a->to_x[w+1][y] = w;
        flag[w][x] = 1;
        flag[w+1][y] = 1;
    }/*
    for(i=0;i<a->x;i++)
    {
        for(j=0;j<a->y;j++)
        cout<<a->line[i][j]<<" ";
        cout<<endl;
    }cout<<endl;
    for(i=0;i<a->x;i++)
    {
        for(j=0;j<a->y;j++)
        cout<<a->to_x[i][j]<<" ";
        cout<<endl;
    }cout<<endl;
    for(i=0;i<a->x;i++)
    {
        for(j=0;j<a->y;j++)
        cout<<flag[i][j]<<" ";
        cout<<endl;
    }*/
    int cur_x = 1,cur_y =a->y;
    while(cur_y>=0)
    {//cout<<cur_x<<" "<<cur_y<<endl;
        if(flag[cur_x][cur_y]>0)
        {
         //   cout<<cur_x<<" "<<cur_y<<endl;
            flag[cur_x][cur_y] = 0;
            int h= a->line[cur_x][cur_y];
            int v = a->to_x[cur_x][cur_y];
           // cout<<v<<" "<<h<<endl;
            flag[v][h] = 0;
            cur_x = v;
            cur_y = h;
        }
        else
        {
            cur_y--;
        }
    }
    cout<<cur_x<<endl;
    return 0;
}

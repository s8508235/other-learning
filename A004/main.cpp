#include <iostream>
#include <map>
using namespace std;

int main()
{

    int a,b,c;
    cin>>a>>b>>c;
    a++;
    int i,x,y ;
    int w[b][b][a];
    for(i=0;i<b;i++)
        for(x=0;x<b;x++)
        for(y=0;y<a;y++)
        {
            w[i][x][y]=-1;
        }

    for(i=0;i<c;i++)
    {
        int j,k,l;
        cin>>j>>k>>l;
        j--;
        w[j][j+1][k] = l;//j->j+1 at k to j+1's l
        w[j+1][j][l] = k;//j+1->j at l to j's k

    }/*
        for(i=0;i<b;i++)
        {
            for(x=0;x<b;x++)
            {
               for(y=0;y<a;y++)
                {
                    cout<<w[i][x][y]<<" ";
                }
                cout<<endl;
            }
            cout<<endl;
        }*/

    int cur_x=0,cur_y = a-1;
    while(cur_y>0)
    {
        if( w[cur_x][cur_x+1][cur_y]>0&&cur_x<b-1)
        {
            //cout<<"to y:"<<w[cur_x][cur_x+1][cur_y]<<endl;
            //cout<<"0:"<<"cur_x:"<<cur_x+1<<" cur_y:"<<cur_y<<endl;
            int v= w[cur_x][cur_x+1][cur_y];
            w[cur_x][cur_x+1][cur_y] = -1;
            w[cur_x+1][cur_x][cur_y] = -1;
            cur_x = cur_x+1;
            cur_y = v;
           // cout<<"0:"<<"cur_x:"<<cur_x+1<<" cur_y:"<<cur_y<<endl;
        }
        else if(w[cur_x][cur_x-1][cur_y]>0&&cur_x>0)
        {
          //  cout<<"to y:"<<w[cur_x][cur_x-1][cur_y]<<endl;
           // cout<<"1:"<<"cur_x:"<<cur_x+1<<" cur_y:"<<cur_y<<endl;
            int v= w[cur_x][cur_x-1][cur_y];
            w[cur_x][cur_x-1][cur_y] = -1;
            w[cur_x-1][cur_x][cur_y] = -1;
            cur_x = cur_x-1;
            cur_y = v;
            //cout<<"1:"<<"cur_x:"<<cur_x+1<<" cur_y:"<<cur_y<<endl;
        }//cout<<"  cur_x:"<<cur_x+1<<" cur_y:"<<cur_y<<endl;

        cur_y--;
    }
    cout<<cur_x+1<<endl;
    return 0;
}

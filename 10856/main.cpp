#include <cstdio>
#include <cstdlib>
using namespace std;
struct point{
    int x;
    int y;
};
bool choose_path(point start,point end,int r);
int main() {
    int point1_X, point1_Y, point2_X, point2_Y, rounds;
    while(scanf("%d %d %d %d %d", &point1_X, &point1_Y, &point2_X, &point2_Y, &rounds) != EOF){
        point start, end;
        start.x = point1_X;
        start.y = point1_Y;
        end.x = point2_X;
        end.y = point2_Y;
        if(choose_path(start,end,rounds)) printf("Y\n");
        else printf("F\n");
    }
}
bool choose_path(point start,point end,int r)
{
    bool w1=0,w2=0,w3=0,w4=0,w5=0,w6=0,w7=0,w8=0;
        if(start.x==end.x && start.y==end.y) return true;
        else
        {
            if(r>1)
            {
                point z1,z2,z3,z4,z5,z6,z7,z8;
                z1.x = start.x-2;
                z1.y = start.y-1;
                w1=choose_path(z1,end,r-1);
                z2.x =start.x -1;//2
                z2.y =start.y -2;
                w2=choose_path(z2,end,r-1);
                z3.x = start.x +1;//3
                z3.y = start.y -2;
                w3=choose_path(z3,end,r-1);
                z4.x = start.x +2;//4
                z4.y = start.y -1;
                w4=choose_path(z4,end,r-1);
                z5.x = start.x +2;//5
                z5.y = start.y +1;
                w5=choose_path(z5,end,r-1);
                z6.x = start.x +1;//6
                z6.y = start.y +2;
                w6=choose_path(z6,end,r-1);
                z7.x = start.x -1;//7
                z7.y = start.y +2;
                w7=choose_path(z7,end,r-1);
                z8.x = start.x -2;//8
                z8.y = start.y +1;
                w8=choose_path(z8,end,r-1);
            }
        }

   // printf("%d %d\n",start.x,start.y);

 //   printf("%d %d %d %d %d %d %d %d\n",w1,w2,w3,w4,w5,w6,w7,w8);
    if(w1||w2||w3||w4||w5||w6||w7||w8) return true;
    else return false;
}

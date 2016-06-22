#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char a[5][5];
char b[5][5];
char s[5][5]=
{
    {
        '1','1','1','1','1'
    } ,
    {
        '0','1','1','1','1'
    } ,
    {
        '0','0',' ','1','1'
    } ,
    {
        '0','0','0','0','1'
    } ,
    {
        '0','0','0','0','0'
    }
};
typedef struct point
{
    int x,y;
} point;
int step,l;
point bfs1[100],bfs2[100];
int num_1,num_2;
typedef struct board
{
    char ma[5][5];
} board;
board map[100];
int board_num=0;
void copy_board_b()
{
    memcpy(map[board_num++].ma,b,sizeof(b));
}
int check_board_a()
{
    int i;
    for(i=0; i<board_num; i++)
    {
        if(memcmp(map[i].ma,a,sizeof(a)) == 0)
            return 0;
    }
    return 1;
}
int check_board_b()
{
    int i;
    for(i=0; i<board_num; i++)
    {
        if(memcmp(map[i].ma,b,sizeof(b)) == 0)
            return 0;
    }
    return 1;
}
void init()
{
    num_1 = 0,num_2 = 0,l= 0;
    int i;
    for(i=0; i<100; i++)
        bfs1[i].x = 0,bfs1[i].y = 0,bfs2[i].x = 0,bfs2[i].y = 0;
}
int dr[8]= { 1, 2, 2, 1,-1,-2,-2,-1};
int dc[8]= {-2,-1, 1, 2, 2, 1,-1,-2};
int isValid(int r, int c)
{
    if(r>=5||r<0)return 0;
    if(c>=5||c<0)return 0;
    return 1;
}
void swap(char *x,char *y)
{
    int a,b;
    a = *x-'\0';
    b = *y-'\0';
    a = a^b;
    b = a^b;
    a = a^b;
    *x = a + '\0';
    *y = b + '\0';
}
void jump_a(int ra,int ca,int rb,int cb)
{
    swap(&a[ra][ca],&a[rb][cb]);
}
void jump_b(int ra,int ca,int rb,int cb)
{
    swap(&b[ra][ca],&b[rb][cb]);
}
int min(int x,int y)
{
    return (x<y)?x:y;
}
void push(int num,int set,int x,int y)
{
    if(set == 0)
        bfs1[num].x = x,bfs1[num].y = y;
    else if(set == 1)
        bfs2[num].x = x,bfs2[num].y = y;
}
void assign_point(int set,point *p,int get)
{
    if(set == 0)
        p->x = bfs1[get].x,p->y = bfs1[get].y;
    else if(set == 1)
        p->x = bfs2[get].x,p->y = bfs2[get].y;
}
void print_a()
{
    int i,j;
    for(i=0; i<5; i++)
    {
        for(j=0; j<5; j++)
            printf("%2c",a[i][j]);
        printf("\n");
    }
    printf("\n");
}
void print_b()
{
    int i,j;
    for(i=0; i<5; i++)
    {
        for(j=0; j<5; j++)
            printf("%2c",b[i][j]);
        printf("\n");
    }
    printf("\n");
}
void print_board()
{
    printf("board start: %d\n",board_num);
    int i,j,k;
    for(i=0; i<board_num; i++)
    {
        for(j=0; j<5; j++)
        {
            for(k=0; k<5; k++)
            {
                printf("%2c",map[i].ma[j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    printf("board end\n");
}
void bfs_2(int r, int c)
{
    int p = 0;
    push(num_1++,0,r,c);
    while(num_1 > p)
    {
        if(l == 17) break;
        int i;
        point zz,go;
        assign_point(0,&zz,p++);
        l++;
        for(i = 0; i<8; i++)
        {
            go.x = zz.x + dr[i];
            go.y = zz.y + dc[i];
            if(isValid(go.x,go.y))
            {
                jump_a(zz.x,zz.y,go.x,go.y);
                if(check_board_a() == 1)
                {
                    push(num_1++,0,go.x,go.y);
                }
                else
                {
                    printf("NOOOOOO");
                    step = min(step,l);
                    break;
                }
                jump_a(zz.x,zz.y,go.x,go.y);
            }
        }
    }
   // print_board();
}
void bfs_last()
{
    int p = 0;
    push(num_2++,1,2,2);
    while(num_2 > p)
    {
        if(l == 8) break;
        int i;
        point zz,go;
        assign_point(1,&zz,p++);
        printf("%d %d\n",zz.x,zz.y);
        l++;
        for(i = 0; i<8; i++)
        {
            go.x = zz.x + dr[i];
            go.y = zz.y + dc[i];
            if(isValid(go.x,go.y))
            {
                jump_b(zz.x,zz.y,go.x,go.y);
                if(check_board_b() == 1)
                {
                    push(num_2++,1,go.x,go.y);
                    copy_board_b();
                }
                jump_b(zz.x,zz.y,go.x,go.y);
            }
        }
        printf("num:%d\n",num_2);
    }
    printf("lll:%d\n",l);
}
int main()
{
    int tc,i,j,k;
    scanf("%d",&tc);
    memcpy(b,s,sizeof(b));
    char st[20];
    gets(st);
    bfs_last();
    for( i=0; i<tc; i++)
    {
        init();
        int r,c;
        for( j=0; j<5; j++)
        {
            gets(st);
            for( k=0; k<5; k++)
            {
                a[j][k]=st[k];
                if(st[k]==' ')
                {
                    r = j;
                    c = k;
                }
            }
        }
        step=17;
        bfs_2(r,c);
        if(step==17)
            printf("Unsolvable in less than 17 move(s).\n");
        else
            printf("Solvable in %d move(s).\n",step);
    }
    return 0;
}

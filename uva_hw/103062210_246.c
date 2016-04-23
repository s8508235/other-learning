#include <stdio.h>
#include <stdlib.h>
int in[52];
typedef struct linkedlist
{
    int list[52];
    int num;
}linkedlist;
linkedlist pile[7];
linkedlist save[8];
linkedlist temp[8];
int deck[52];
int tmp_deck[52];
int cnt = 0;
int deck_index = 0;
int feq,cnt_tmp;
void deal_card(int pos);
int draw_case();
void deal_card_draw_case(int pos)
{
    int i;
    save[pos].list[save[pos].num++] = save[7].list[0];
    save[7].num--;
    for(i=0;i<save[7].num;i++)
        save[7].list[i] = save[7].list[i+1];
    save[7].list[i] = 0;
    while(save[pos].num >2)
    {
        if((save[pos].list[0] + save[pos].list[1] + save[pos].list[save[pos].num-1]) %10 ==0)
        {
            save[7].list[save[7].num++] = save[pos].list[0];
            save[7].list[save[7].num++] = save[pos].list[1];
            save[7].list[save[7].num++] = save[pos].list[save[pos].num-1];
            save[pos].list[0] = 0;
            save[pos].list[1] = 0;
            save[pos].list[save[pos].num-1] = 0;
            for(i=0;i<save[pos].num;i++)
            {
                save[pos].list[i] =  save[pos].list[i+2];
            }
            save[pos].num-=3;
        }
        else if((save[pos].list[0] + save[pos].list[save[pos].num-1] + save[pos].list[save[pos].num-2]) %10 ==0)
        {
            save[7].list[save[7].num++] = save[pos].list[0];
            save[7].list[save[7].num++] = save[pos].list[save[pos].num-2];
            save[7].list[save[7].num++] = save[pos].list[save[pos].num-1];
            save[pos].list[0] = 0;
            save[pos].list[save[pos].num-1] = 0;
            save[pos].list[save[pos].num-2] = 0;
            for(i=0;i<save[pos].num;i++)
            {
                save[pos].list[i] =  save[pos].list[i+1];
            }
            save[pos].num-=3;
        }
        else if((save[pos].list[save[pos].num-1] + save[pos].list[save[pos].num-2] + save[pos].list[save[pos].num-3]) %10 ==0)
        {
            save[7].list[save[7].num++] = save[pos].list[save[pos].num-3];
            save[7].list[save[7].num++] = save[pos].list[save[pos].num-2];
            save[7].list[save[7].num++] = save[pos].list[save[pos].num-1];
            save[pos].list[save[pos].num-1] = 0;
            save[pos].list[save[pos].num-2] = 0;
            save[pos].list[save[pos].num-3] = 0;
            save[pos].num-=3;
        }
        else break;
    }
}
void re()
{
    int i,j,k;
    cnt=14;
    for(i=0;i<7;i++)
    {
        pile[i].num = 2;
        save[i].num = 2;
        for(j=0;j<2;j++)
        {
            pile[i].list[j]=temp[i].list[j];
            save[i].list[j]=temp[i].list[j];
        }
    }
    deck_index=38;
    save[7].num=38;
    for(i=0;i<deck_index;i++)
    {
        deck[i]=temp[7].list[i];
        save[7].list[i]=temp[7].list[i];
    }
    for(k=1,i=0;k<=feq;k++)
    {
        if(i>=7) i=0;
        while(pile[i].num==0)
        {
            i++;
            if(i>=7)    i=0;
        }
        deal_card(i++);
    }
    for(j=0;draw_case()==0;)
    {
        if(i>=7)    i=0;
        if(j>=7)    j=0;
        while(pile[i].num==0)
        {
            i++;
            if(i>=7)    i=0;
        }
        deal_card(i++);
        while(save[j].num==0)
        {
            j++;
            if(j>=7)    j=0;
        }
        deal_card_draw_case(j++);
    }
}
void record()
{
    int i,j;
    for(i=0;i<7;i++)
    {
        save[i].num=pile[i].num;
        for(j=0;j<pile[i].num;j++)
            save[i].list[j]=pile[i].list[j];
    }
    save[7].num=deck_index;
    for(i=0;i<deck_index;i++)
        save[7].list[i]=deck[i];
}
int draw_case()
{
    int i,j;
    for(i=0;i<7;i++)
    {
        if(save[i].num != pile[i].num)
            return 0;
        for(j=0;j<pile[i].num;j++)
        {
            if(save[i].list[j] != pile[i].list[j])
                return 0;
        }
    }
    if(save[7].num != deck_index)
        return 0;
    for(i=0;i<deck_index;i++)
    {
        if(save[7].list[i]!=deck[i])
            return 0;
    }
    return 1;
}
void deal_card(int  pos)
{
    int i;
    cnt++;
    pile[pos].list[pile[pos].num] = deck[0];
    pile[pos].num++;
    deck_index--;
    for(i=0;i<deck_index;i++)
        deck[i] = deck[i+1];
    deck[i] = 0;
    while(pile[pos].num >2)
    {
        if((pile[pos].list[0] + pile[pos].list[1] + pile[pos].list[pile[pos].num-1]) %10 ==0)
        {
            deck[deck_index++] = pile[pos].list[0];
            deck[deck_index++] = pile[pos].list[1];
            deck[deck_index++] = pile[pos].list[pile[pos].num-1];
            pile[pos].list[0] = 0;
            pile[pos].list[1] = 0;
            pile[pos].list[pile[pos].num-1] = 0;
            for(i=0;i<pile[pos].num;i++)
            {
                pile[pos].list[i] =  pile[pos].list[i+2];

            }
            pile[pos].num-=3;
        }
        else if((pile[pos].list[0] + pile[pos].list[pile[pos].num-1] + pile[pos].list[pile[pos].num-2]) %10 ==0)
        {
            deck[deck_index++] = pile[pos].list[0];
            deck[deck_index++] = pile[pos].list[pile[pos].num-2];
            deck[deck_index++] = pile[pos].list[pile[pos].num-1];
            pile[pos].list[0] = 0;
            pile[pos].list[pile[pos].num-1] = 0;
            pile[pos].list[pile[pos].num-2] = 0;
            for(i=0;i<pile[pos].num;i++)
            {
                pile[pos].list[i] =  pile[pos].list[i+1];
            }
            pile[pos].num-=3;
        }
        else if((pile[pos].list[pile[pos].num-1] + pile[pos].list[pile[pos].num-2] + pile[pos].list[pile[pos].num-3]) %10 ==0)
        {
            deck[deck_index++] = pile[pos].list[pile[pos].num-3];
            deck[deck_index++] = pile[pos].list[pile[pos].num-2];
            deck[deck_index++] = pile[pos].list[pile[pos].num-1];
            pile[pos].list[pile[pos].num-1] = 0;
            pile[pos].list[pile[pos].num-2] = 0;
            pile[pos].list[pile[pos].num-3] = 0;
            pile[pos].num-=3;
        }
        else break;
    }
}
int main()
{
    int i;
    while(1)
    {
        deck_index = 0;
        cnt = 0;
        for(i=0;i<=7;i++)
        {
            int j;
            for(j=0;j<52;j++)
            {
                if(i<7)
                pile[i].list[j]=0;
                save[i].list[j]=0;
                temp[i].list[j]=0;
            }
            if(i<7)
            pile[i].num = 0;
            save[i].num = 0;
            temp[i].num = 0;
        }
        for(i=0;i<52;i++)
        {
            deck[i] = 0;
            tmp_deck[i] = 0;
        }
        for(i=0;i<52;i++)
        {
            scanf("%d",&in[i]);
            if(i<7)
            {
                pile[cnt].list[0] = in[i];
                pile[cnt].num ++;
                temp[cnt].list[0] = in[i];
                temp[cnt].num ++;
                cnt  ++;
            }
            else if(i<14 && i >=7)
            {
                pile[cnt%7].list[1] = in[i];
                pile[cnt%7].num ++;
                temp[cnt%7].list[1] = in[i];
                temp[cnt%7].num ++;
                cnt++;
            }
            else
            {
                temp[7].list[deck_index] = in[i];
                deck[deck_index] = in[i];
                deck_index++;
            }
            if(in[i]==0) return 0;
        }
        for(i=0;i<=7;i++)
        {
            if(i==7) i = 0;
            if(pile[i].num==0) continue;
            deal_card(i);
            if(deck_index  ==52)
            {
                printf("Win : %d\n",cnt);
                break;
            }
            else if(deck_index ==0)
            {
                printf("Loss: %d\n",cnt);
                break;
            }
            else if(draw_case())
            {
                feq = cnt-cnt_tmp;
                re();
                printf("Draw: %d\n",cnt);
                break;
            }

            if(cnt==2 || cnt==4 || cnt==8 || cnt==16 || cnt==32 || cnt==64 || cnt==128 || cnt==256 || cnt==512 || cnt==1024 || cnt==2048)
            {
                cnt_tmp = cnt;
                record();
            }
        }

    }

    return 0;
}


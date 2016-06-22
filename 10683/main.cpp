#include <iostream>

using namespace std;
typedef struct order
{
    int num;
    struct order *next;
    struct order *prev;
}order;
void ex(order *head,order *tail)
{
    order *curr,*adder,*tt;
    curr = head->next;
    //cout<<"@@:"<<curr->num<<endl;
    int nb,nn=1;
    nb = curr->num;
    while(curr!=tail)
    {
        tt = curr;
        curr = curr->next;
        if(nb==curr->num)
        {
            nn++;
            tt->next->prev = tt ->prev;
            tt ->prev ->next = tt ->next;
          //  cout<<"++"<<endl;
        }
        else{
            adder = new order;
            if(nn/10==0)
            {
                adder->num = nn;
                tt->prev->next = adder;
                adder->prev = tt->prev;
                adder->next = tt;
                tt->prev = adder;
            }
            else if(nn/10==1)
            {
                order *adder2;
                adder2 = new order;
                adder->num = nn/10;
                adder2->num = nn%10;
                tt->prev ->next = adder;
                adder->prev = tt->prev;
                adder->next = adder2;
                adder2->prev = adder;
                adder2->next = tt;
                tt->prev =adder2;
            }
            else{}
            nn=1;
            nb = curr->num;
          //  cout<<"rd"<<endl;
        }
    }/*
    curr = head->next;
    while(curr!=tail)
    {
        cout<<curr->num;
        curr = curr->next;
    }cout<<endl;*/
    return ;
}
int main()
{
    int n;
    cin>>n;
    while(n>0)
    {
        string x;
        cin>>x;
        order *head,*curr,*tail;
        head = new order;
        tail = new order;
        curr = head;
        for(unsigned j=0;j<x.length();j++)
        {
            order *temp;
            temp = new order;
            temp -> num = x[j]-'0';
            curr -> next = temp;
            temp -> prev = curr;
            curr = temp;
        }
        curr ->next = tail ;
        tail ->next = head ;
        head ->prev = tail ;
        int w;
        cin>>w;
        while(w>0)
        {
            ex(head,tail);
            w--;
        }
        curr = head->next;
        while(curr!=tail)
        {
            cout<<curr->num;
            curr = curr ->next;
        }
        cout<<endl;
        n--;
    }
    return 0;
}

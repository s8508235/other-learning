#include <iostream>
typedef struct lists
{
    int num;
    struct lists *next;
    struct lists *prev;
}lists;
using namespace std;
int N;
lists* s(int n,lists *head)
{
    int i;
    lists *x;
    x = head->next;
    for(i=0;i<N;i++)
    {
        if(x->num == n) break;
        x = x->next;
    }
    return x;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin>>N;
    lists *head,*tail;
    head = new lists;
    head ->num = 0;
    lists *curr;
    curr = head;
    int i;
    for(i=1;i<=N;i++)
    {
        lists *temp;
        temp = new lists;
        temp ->num = i;
        curr ->next = temp;
        temp ->prev = curr;
        curr = temp ;
    }
    tail = new lists;
    tail ->num = 0;
    head ->prev = tail ;
    curr ->next = tail ;
    tail ->prev = curr ;
    string str;
    while(cin>>str && str!="Exit")
    {
        if(str.compare("Move")==0)
        {
            int a,b;
            cin>>a;
            cin>>b;
            lists *t,*e,*w;
            t = s(b,head);
            w = s(a,head);
            e = t->prev;
            if(e==w)
            {
                continue;
            }
            else{
                  // cout<<t->num<<" "<<e->num<<endl;
            e->next = head ->next;
            head ->next ->prev = e ;
            head ->next = e;
            e->prev = head ;
           // cout<<w->num<<endl;
            w->next = t;
            t->prev = w;
            }

        }
    }
            curr = head->next;
            cout<<curr->num;
            curr =curr->next;
            for(i=0;i<N-1;i++)
            {
            cout<<" "<<curr->num;
            curr = curr->next;
            }
            cout<<endl;
    return 0;
}

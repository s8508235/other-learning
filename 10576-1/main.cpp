#include <iostream>

using namespace std;
struct Node
{
    int prev;
    int next;

};
Node s[1000003];
int main()
{
    int i;
    int N;
    cin>>N;
    for(i=0;i<=N+1;i++)
    {
        s[i].next  = i+1;
        s[i].prev = i-1;
    }
    string ch;
    while(cin>>ch && ch.compare("Exit")!=0)
    {
        if(ch.compare("Move")==0)
        {
            int a,b;
            cin>>a>>b;
            int p,q,r;
            p = s[a].next;
            q = s[b].prev;
            if(a==q) continue;
            r = s[0].next;
            s[a].next = b;
            s[b].prev = a;
            s[r].prev = q;
            s[q].next = r;
            s[0].next = p;
            s[p].prev = 0;
        }

    }
    int t = s[0].next;
    cout<<t; --N;
    while(N>0)
    {
        t = s[t].next;
        cout<<" "<<t;
        --N;
    }
    cout<<endl;
    return 0;
}

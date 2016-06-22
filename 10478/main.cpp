#include <iostream>

using namespace std;
unsigned long long  GCD(unsigned long long  a,unsigned long long  b){
    if (a%b == 0)
        return b;
    else
        return GCD(b, a%b);
}
int main()
{
    unsigned long long  N;
    while(cin>>N){
    unsigned long long  ans1,ans2;
    cin>>ans1;
    cin>>ans2;
    unsigned long long  w;
    w = GCD(ans1,ans2);
    ans1 /=w;
    ans2 /=w;
    unsigned long long  i,n1,n2;
    for(i=0;i<N-1;i++)
    {
        cin>>n1;
        cin>>n2;
        w = GCD(n1,n2);
        n1/= w;
        n2/= w;
       unsigned long long  x;
        x = ans2*n2/GCD(ans2,n2);
        ans1 = ans1 * x / ans2 + n1 * x  / n2 ;
        ans2 = x ;
        unsigned long long z;
        z = GCD(ans1,ans2);
        ans1/=z;
        ans2/=z;
    }
    unsigned long long  y = GCD(ans1,ans2);
    ans1 = ans1/y;
    ans2 = ans2/y;
    cout<<ans1<<"/"<<ans2<<endl;
    }
    return 0;
}

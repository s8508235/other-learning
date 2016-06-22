#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n>0)
    {
        int a;
        cin>>a;
        string x1,x2;
        int n1[a],n2[a];
        int i;
            cin>>x1;
            cin>>x2;
        for(i=0;i<a;i++)
        {
           n1[i] = x1[i]-'0';
           n2[i] = x2[i]-'0';
        }
        int n3[a];
        int c[a];
        for(i=0;i<a;i++)
        {
          n3[i]=0;
          c[i] = 0;
        }
        for(i=a-1;i>=0;i--)
        {
          n3[i] = (n1[i]+n2[i]+c[i])%2;
          if((n1[i]+n2[i]+c[i])>1)
          {
              c[i-1]++;
          }
        }

            for(i=0;i<a;i++)
            {
                cout<<n3[i];
            }
            cout<<endl;

        n--;
    }
    return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int x,y,k,n;
    cin>>x>>y;
    cin>>k;
    cin>>n;
    int i ;
    int file[n];
    int ff[n];
    int oring[n];
    for(i=0;i<n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int d = (a-x)*(a-x)+(b-y)*(b-y);
        file[i] = d;
        ff[i] = c;
    }

    for(i=0;i<n;i++)
    {
        oring[i] = file[i];
    }

    sort(file,file+n);
    int res=0;
    for(int j = 0;j<k;j++)
    {
         for(i=0;i<n;i++)
        {
            if(oring[i]==file[j])
            {
              res +=  ff[i];
              //cout<<file[j]<<" "<<oring[i]<<endl;
             // cout<<j<<" "<<i<<" "<<ff[i]<<endl;
              break;
            }
        }
    }
    float zz = res;
    if((zz/k - res/k)>0.5) cout<<res/k+1<<endl;
    else
    cout<<res/k<<endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    int n,m;
    while(cin>>n &&n!=0)
    {
        vector<int> N(n);
        for(int i = 0;i<n;i++)
        {
            cin>>N[i];
        }
        cin>>m;
        vector <int> M(m);
        for(int i = 0;i<m;i++)
        {
            cin>>M[i];
        }
        sort(N.begin(),N.end());
        sort(M.begin(),M.end());
        int i=0,j=0;
        vector <int> x;
        while(i<n &&j<m)
        {
            if(N[i]==M[j])
            {
                x.push_back(N[i]);
                i++;
                j++;
            }
            else if(N[i]>M[j])
            {
                j++;
            }
            else{
                i++;
            }
        }
        if(x.empty())
        {
            cout<<"empty"<<endl;
        }
        else{
            cout<<x[0];
            unsigned int z;
            for(z=1;z<x.size();z++)
            {
                cout<<" "<<x[z];
            }
            cout<<endl;
        }
    }
    return 0;
}

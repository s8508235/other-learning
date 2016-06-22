#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    std::ios_base::sync_with_stdio(false);
    while (1)
    {
        int n1,n2;
        cin>>n1;
        if(n1==0)break;
        int s1[n1];
        int i;
        for(i=0;i<n1;i++)
        {
            cin>>s1[i];
        }
        cin>>n2;
        int s2[n2];
        for(i=0;i<n2;i++)
        {
            cin>>s2[i];
        }
        sort(s1,s1+n1);
        sort(s2,s2+n2);
        int j=0;
        i = 0;
        vector <int> x;
        while(i<n1 && j<n2)
        {
                if(s1[i]==s2[j])
                {
                    x.push_back(s1[i]);
                    i++;
                    j++;
                }
                else if(s1[i]<s2[j])
                {
                    i++;
                }
                else
                {
                    j++;
                }
        }
        if(x.empty())
        {
            cout<<"empty"<<endl;
        }
        else{
                cout<<x[0];
                for (unsigned int z=1; z<x.size(); z++)
                {
                cout <<' '<< x[z];
                }
        cout <<endl;
        }
    }
    return 0;
}

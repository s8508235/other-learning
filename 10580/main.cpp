#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    int n;
    vector<int> num;
    while(cin>>n)
    {
        int i;
        for(i=0;;i++)
        {
            int a;
            cin>>a;
            if(a==0) break;
            num.push_back(a);
        }
        int ans=0;
        int nbofit = i;
        int ed = i;
        vector<int> flag(nbofit,1);
        i = 0;
        int sum=0;
        while(1)
        {
                sum +=num[i];
                ed--;

            if(sum>n)
            {
                sum = num[i];
                ans++;
            }
            i++;
           if(ed==0) break;
        }
            cout<<ans+1<<endl;
            num.clear();
    }

    return 0;
}

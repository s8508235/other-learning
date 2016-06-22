#include <iostream>

using namespace std;
int ch(int *x,int b);
int main()
{
    int a ,b;
    cin>>a;
    int i=0,j = 0;
    for(i=0;i<a;i++)
    {
        cin>>b;
        int x[b];
        for(j=0;j<b;j++)
        {
            cin>>x[j];
        }
        int ans = ch(x,b);
        cout<<"Optimal train swapping takes "<<ans<<" swaps."<<endl;
    }

    return 0;
}
int ch(int *x,int b)
{
    int i,j =0;
    int a=0;
    for (int w = 0;w<b;w++)
    for (i=0;i<b-1;i++)
    {
            if(x[i]>x[i+1])
            {
              //  cout<<x[i]<<" "<<x[j]<<endl;
                swap(x[i],x[i+1]);
                a++;
            }
    }
   // cout<<a<<endl;
    return  a;
}

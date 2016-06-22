#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
map<char,int> M;
string last = "";
void hisogram(string str,int k)
{
    for(char c ='A';c<='K';c++)
    {
        M[c] = 0;
    }
        for(int j = 0;j<str.length();j++)
        {
            if(M[str[j]]<k)
            {
                 M[str[j]]++;
            }
        }

}
void gen(char start,int k,string str);
int main()
{
    std::ios_base::sync_with_stdio(false);
    int N;
    cin>>N;
    while(N>0)
    {
        string S;
        int K;
        cin>>S;
        cin >>K;

        hisogram(S,K);
        gen('A',K,last);
        cout<<endl;
        N--;
        last = "";
    }
    return 0;
}
void gen(char start,int k,string str)
{
    if(k>0)
    {
        for(;start<='K';start++)
        {
            char c ;
            c = start;
            if(M[c]>0)
            {
                M[c]--;
               // cout<<"c:"<<c<<" "<<M[c]<<endl;
                string rstr(1,c);
                gen(c,k-1,str+rstr);
                M[c]++;
            }
        }
    }
    else
    {
        if(str!=last)
        {
            last = str;
            cout<<str<<endl;
        }
    }
}

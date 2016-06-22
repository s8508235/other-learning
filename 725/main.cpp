#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    stack<string> a;
    string w;
    int num = 0;
    while((cin>>w)!=NULL)
    {
        if (w=="MAKECELL")
        {
            string s;
            cin>>s;
            a.push(s);
            num ++;
        }
        else if (w=="COMBINE")
        {
            int s;
            cin>>s;
            if(num<s)
            {
                cout<<"LACK OF CELL"<<endl;
            }
            else
            {
                string st;
                for(int i =0;i<s;i++)
                {
                    st += a.top()+"-";
                    a.pop();
                    num--;
                }
                //st.resize(st.size()-1);
                st.erase(st.size()-1,st.size());
                cout<<st<<endl;
            }
        }
        else {
        }
    }
    return 0;
}

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue <string> fat;
    string ch;
    while(cin>>ch)
    {
        if(ch.compare("Push")==0)
        {
            string c;
            cin>>c;
            fat.push(c);
        }
        else if(ch.compare("Pop")==0)
        {
            if(fat.empty())
            {
            }
            else
            fat.pop();
        }
        else if (ch.compare("Front")==0)
        {
            if(fat.empty())
            {
                cout<<"empty"<<endl;
            }
            else
            cout<<fat.front()<<endl;
        }
    }
    return 0;
}

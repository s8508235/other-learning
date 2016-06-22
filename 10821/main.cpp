#include <iostream>

using namespace std;
typedef struct fat
{
    int n;
    struct fat* next;

}fat;
int main()
{
    int a,b;
    cin>>a>>b;
    int i;
    fat *head;
    head = new fat;
    head->n = 1;
    head->next = NULL;
    fat *x;
    x = new fat;
    x = head;
    for(i=2;i<=a;i++)
    {
        fat *z;
        z = new fat;
        z->n = i;
        x->next = z;
        z->next = NULL;
        x = z;
    }
    x->next = head;
    int cy = a;
    if(b==0)
    {
        x = head;
        for(i=1;i<cy;i++)
        {
            cout<<x->n<<" ->";
            x = x->next;
        }
        cout<<x->n<<endl;
        return 0;
    }
    while(cy>1)
    {
        x = head;
        for(i=1;i<cy;i++)
        {
            cout<<x->n<<" ->";
            x = x->next;
        }
        cout<<x->n<<endl;
        x = head;
        if(b!=1)
        {
             for(i=1;i<b-1;i++)
            {
                x = x->next;
            }

        }
        else
        {
            for(i=1;i<cy;i++)
            {
                x = x->next;
            }
        }
            x->next = x->next->next;
            head = x->next;
        cy--;
    }
    cout<<head->n<<endl;
    return 0;
}

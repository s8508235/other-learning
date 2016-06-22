#include "Implement.h"

// add your code here
bool Stack::isempty() const
{
    if(this->top==-1)
        return 1;
    else
        return 0;
}
Stack::Stack(int abcde=10)
{
    cap = abcde;
    why = new char (sizeof(char)*cap);
    top = -1;
}
void Stack::Push(const char& x)
{
    if (top==cap-1)
    {
        char* w;
        w = new char (sizeof(char)*cap*2);
        for(int i=0;i<cap;i++)
        {
            w[i] = why[i];
        }
        cap*=2;
        why = w;
        std::cout<<"why:"<<why<<std::endl;
    }
    top ++;
    why[top] = x;
}
void Stack::Pop()
{
    if(!isempty())
    {
        top--;
    }
}
const char* Implement::getStudentID()
{
    return "103062210";
}

void Implement::infix2Prefix(Expression &prefix, const Expression &infix)
{
    Stack temp;
    Expression t;
    t.resize(infix.sz);
    t.sz = infix.sz;
    for (int i=0;i<infix.sz;i++)
    {
        t.data[infix.sz-1-i] = infix.data[i];
        //std::cout<<"t.data["<<infix.sz-1-i<<"]"<<t.data[infix.sz-1-i]<<std::endl;
    }
    int pf = infix.sz   ;
    for(int i =0;i<infix.sz;i++)
    {
        if(t.data[i] ==')'||t.data[i]=='(')
        {
            pf--;
        }
    }
    //std::cout<<pf<<std::endl;
    prefix.resize(pf);
    prefix.sz = pf;
    for(int i =0;i<infix.sz;i++)
    {
        if(isdigit(t.data[i]))
        {
            prefix.data[pf-1] = t.data[i];
            pf--;
        }
        else if (t.data[i]==')')
        {
            temp.Push(t.data[i]);
        }
        else if(t.data[i]=='(')
        {
            while(temp.why[temp.top]!=')')
            {
                prefix.data[pf-1]=temp.why[temp.top];
                temp.Pop();
                pf--;
            }
            temp.Pop();
        }
        else if(t.data[i]=='*'||t.data[i]=='/')
        {
            temp.Push(t.data[i]);
        }
        else if (t.data[i]=='+'||t.data[i]=='-')
        {
            while(temp.why[temp.top]=='/'||temp.why[temp.top]=='*')
            {
                prefix.data[pf-1]=temp.why[temp.top];
                pf--;
                temp.Pop();
            }
            temp.Push(t.data[i]);
        }
        else
        {
            std::cout<<"what"<<std::endl;
        }
        if (i==infix.sz-1 && !temp.isempty())
        {
            while(!temp.isempty())
            {
                prefix.data[pf-1] = temp.why[temp.top];
                pf--;
                temp.Pop();
            }
        }
    }
}
void Implement::infix2Postfix(Expression &postfix, const Expression &infix)
{
    Stack ttt;
    int pf = infix.sz;
    for(int i =0;i<infix.sz;i++)
    {
        if(infix.data[i] ==')'||infix.data[i]=='(')
        {
            pf--;
        }
    }
    postfix.resize(pf);
    postfix.sz = pf;
    pf = 0;
    for(int i =0;i<infix.sz;i++)
    {
        if(isdigit(infix.data[i]))
        {
            postfix.data[pf] = infix.data[i];
            pf++;
        }
        else if (infix.data[i]=='(')
        {
            ttt.Push(infix.data[i]);
        }
        else if((infix.data[i]=='+'||infix.data[i]=='-'))
        {
            while (ttt.why[ttt.top]=='*'||ttt.why[ttt.top]=='/'||ttt.why[ttt.top]=='+'||ttt.why[ttt.top]=='-')
            {
                postfix.data[pf] = ttt.why[ttt.top];
                pf++;
                ttt.Pop();
            }
            ttt.Push(infix.data[i]);
        }
        else if (infix.data[i]=='*'||infix.data[i]=='/')
        {
            while (ttt.why[ttt.top]=='*'||ttt.why[ttt.top]=='/')
            {
                postfix.data[pf] = ttt.why[ttt.top];
                pf++;
                ttt.Pop();
            }
            ttt.Push(infix.data[i]);
        }
        else if (infix.data[i] ==')')
        {
            while(ttt.why[ttt.top]!='(')
            {
                postfix.data[pf] = ttt.why[ttt.top];
                pf++;
                ttt.Pop();
            }
            ttt.top --;
        }

        if (i==infix.sz-1 && pf!=postfix.sz)
        {
            while(!ttt.isempty())
            {
                postfix.data[pf] = ttt.why[ttt.top];
                ttt.Pop();
                pf++;
            }
        }
    }
}
int Implement::evalPrefix(const Expression &prefix)
{
    int p[prefix.sz];
    int top = -1;
    for(int i=prefix.sz-1;i>=0;i--)
    {
        if(isdigit(prefix.data[i]))
        {
            top++;
            p[top] = prefix.data[i]-'0';
        }
        else if (prefix.data[i]=='+')
        {
            int sum;
            sum = p[top];
            top--;
            int ans;
            ans = p[top];
            p[top] = ans+sum;
        }
        else if (prefix.data[i]=='-')
        {
            int sum;
            sum = p[top];
            top--;
            int ans;
            ans = p[top];
            p[top] = sum-ans;
        }
        else if (prefix.data[i]=='*')
        {
            int sum;
            sum = p[top];
            top--;
            int ans;
            ans = p[top];
            p[top] = ans*sum;
        }
        else if (prefix.data[i]=='/')
        {
            int sum;
            sum = p[top];
            top--;
            int ans;
            ans = p[top];
            p[top] = sum/ans;
            //std::cout<<p[top]<<std::endl;
        }
    }
    return p[top];
}
int Implement::evalPostfix(const Expression &postfix)
{
    Stack evpostfix;

    for(int i = 0;i<postfix.sz;i++)
    {
        if(isdigit(postfix.data[i]))
        {
            evpostfix.Push(postfix.data[i]);
        }
        else if (postfix.data[i]=='+')
        {
            int sum;
            sum = evpostfix.why[evpostfix.top]-'0';
            evpostfix.Pop();
            sum +=evpostfix.why[evpostfix.top]-'0';
            evpostfix.Pop();
            evpostfix.Push((sum+'0'));
        }
        else if (postfix.data[i]=='-')
        {
            int sum;
            sum = evpostfix.why[evpostfix.top]-'0';
            evpostfix.Pop();
            int ans;
            ans =evpostfix.why[evpostfix.top]-'0';
            evpostfix.Pop();
            evpostfix.Push(((ans-sum)+'0'));
        }
        else if (postfix.data[i]=='*')
        {
            int sum;
            sum = evpostfix.why[evpostfix.top]-'0';
            evpostfix.Pop();
            sum *=evpostfix.why[evpostfix.top]-'0';
            evpostfix.Pop();
            evpostfix.Push((sum+'0'));
        }
        else if (postfix.data[i]=='/')
        {
            int sum;
            sum = evpostfix.why[evpostfix.top]-'0';
            evpostfix.Pop();
            int ans;
            ans =evpostfix.why[evpostfix.top]-'0';
            evpostfix.Pop();
            evpostfix.Push(((ans/sum)+'0'));
        }
    }
    return evpostfix.why[evpostfix.top]-'0';
}

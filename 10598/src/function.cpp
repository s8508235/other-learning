#include <iostream>
#include "function.h"
using namespace std;
Array_stack ::Array_stack()
{

    max_size = 0;
    int i;
    for(i=0;i<100;i++)
    {
        number[i] = 0;
    }
}
int Array_stack ::pop(){
    if(max_size==0)
    {
        return 0;
    }
    number[max_size] = '\0';
    max_size --;
    return max_size;
}
void Array_stack ::print(std::ostream &output)
{
    if(max_size ==0)    return ;
    int i ;
    std::cout<<number[max_size-1];
    for(i=max_size-2;i>=0;i--)
    {
       std::cout<<" "<<number[i];
    }
}
void Array_stack ::push(const int &num)
{
    number[max_size] = num ;
    max_size ++;

}
Array_stack ::~Array_stack()
{

}
List_stack ::List_stack()
{
    head = new ListNode(0);
    head ->nextPtr = tail ;
    head ->prevPtr = tail;
    tail = new ListNode(0);
    tail ->nextPtr = head ;
    tail ->prevPtr = head ;
}
int List_stack ::pop()
{
    ListNode *x ;
    x = tail ->prevPtr ;
    if(x==head) return 0;

    x ->prevPtr ->nextPtr = tail ;
    x ->nextPtr ->prevPtr = x ->prevPtr ;
    delete x ;
    return 0;
}
void List_stack ::print(std::ostream &output)
{

    ListNode *x ;
    x = tail->prevPtr ;
    if(x==head) return ;
    std::cout <<x->data;
    x = x->prevPtr ;
    while (x!=head)
    {
       std::cout<<" "<<x->data ;
        x = x ->prevPtr  ;
    }
}
void List_stack ::push(const int &num)
{
    ListNode *x ;
    x = new ListNode (num);
    x ->nextPtr = tail ;
    x ->prevPtr = tail ->prevPtr;
    tail ->prevPtr ->nextPtr = x ;
    tail ->prevPtr = x ;
}
List_stack ::~List_stack()
{

}
ostream &operator<<(ostream &output, Stack &a)
{
    a.print(output);
    return output;
}

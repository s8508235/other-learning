#include "function.h"
#include <iostream>
using namespace std;
OWList ::OWList()
{
    firstPtr =NULL;
    lastPtr =NULL;
}
OWList ::~OWList()
{
    delete firstPtr;
    delete lastPtr ;
}
void OWList ::insertAtFront(const int & value)
{
    ListNode *x,*curr;
    x = firstPtr ;
    firstPtr = new ListNode(value);
    firstPtr->nextPtr = x;
    curr = firstPtr;
    while(curr->nextPtr!=NULL)
    {
        curr = curr ->nextPtr;
    }
    lastPtr = curr ;
    // cout<<"f:"<<firstPtr->data<<" iafl:"<<lastPtr->data<<endl;
}
void OWList ::removeFromFront()
{

    if(isEmpty()==0)
    {
        ListNode *x,*curr;
        x = firstPtr ;
        firstPtr = x->nextPtr ;
        delete x;
        if(isEmpty()==1) return ;
        else
        {
            curr = firstPtr;

            if(curr!=lastPtr)
            {
                while(curr->nextPtr!=NULL)
                {
                    curr = curr->nextPtr ;
                }
                lastPtr = curr ;
            }
            else
            {
                lastPtr = curr ;
            }
        }
    }
    else
    {

    }
    //cout<<"f:"<<firstPtr->data<<" rffl:"<<lastPtr->data<<endl;
}
bool OWList ::isEmpty()const
{
    if(firstPtr==NULL) return true;
    else return false;
}
void OWList ::print() const
{
    if(isEmpty()==0)
    {
        ListNode *x;
        x = firstPtr ;
        cout<<x->data;
        x = firstPtr->nextPtr ;
        while(x!=NULL)
        {
            cout<<" "<<x->data;
            x = x->nextPtr ;
        }
    }
    else
    {
    }
}
void TWList ::insertAtBack(const int &value)
{
    if(isEmpty()==0)
    {
        ListNode *x,*y ;
    y = lastPtr;
    x = new ListNode(value);

    y->nextPtr = x ;
    lastPtr = x;
    lastPtr ->nextPtr = NULL ;
    }
    else{
        firstPtr = new ListNode(value);
        lastPtr = firstPtr ;
        lastPtr ->nextPtr = NULL ;
    }
    // cout<<"last -1:"<<y->data<<" last:"<<x->data<<endl;
    // cout<<"end ib"<<endl;
}
void TWList ::removeFromBack()
{
    if(isEmpty()==0)
    {
        ListNode *x;
        //cout<<"@@rfb"<<endl;
        x = firstPtr ;
        if(firstPtr !=lastPtr)
        {
            while(x->nextPtr!=lastPtr)
            {
                x = x->nextPtr ;
            }
        }
        else
        {
            delete lastPtr ;
            firstPtr = NULL;
            lastPtr =NULL ;
            return ;
           // cout<<"zz"<<endl;
        }

       delete lastPtr ;
           // cout<<"end of x:"<<x->data<<endl;
            lastPtr = x;
            lastPtr ->nextPtr = NULL;

    }
    else
    {

    }
    //cout<<"f:"<<firstPtr->data<<" last:"<<lastPtr->data<<endl;
}

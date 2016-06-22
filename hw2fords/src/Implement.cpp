#include "Implement.h"
#include <iostream>
const char* Implement::getStudentID()
{
    return "103062210";
}
Node* Implement::InsertBack(Node *head, string name)
{
    if(head!=NULL)
    {
        Node* curr;
        curr = new Node;
        curr = head;
        while(curr->next!=NULL)
        {
            curr = curr->next;
        }
        Node* temp;
        temp = new Node;
        temp->data = name;
        curr->next= temp;
        temp->next = NULL;
    }
    else{
        head = new Node();
        head->data= name;
        head->next = NULL;
    }
    return head;
}
Node* Implement::InsertAfter(Node *head, string name1, string name2)
{
    if(head!=NULL)
    {
        int flag = 0;
        Node* curr;
        curr = new Node;
        curr = head;
        while(curr->data!=name1)
        {
            curr = curr->next;
            if(curr ==NULL)
            {
                flag = 1;
                break;
            }
        }
        if(!flag)
        {
            Node* temp;
            temp = new Node;
            temp->data = name2;
            temp->next = curr->next;
            curr->next = temp;
        }
    }
    return head;
}
Node* Implement::Delete(Node *head, string name)
{
    if(head!=NULL)
    {
        Node* curr;
        curr = new Node;
        curr = head;
        Node* bfdel;
        bfdel = new Node;
        bfdel = head;
        int flag = 0;
              while(curr->data!=name)
                {
                    bfdel = curr;
                    curr = curr->next;
                    if(curr ==NULL)
                    {
                        flag = 1;
                        break;
                    }
                }
                if(head->data ==name)
                {
                    head= head->next;
                }
        if(!flag)
        {
            bfdel->next = curr->next;
        }
    }
    return head;
}
Node* Implement::Reverse(Node *head)
{
    if(head->next!=NULL)
    {
        Node* tail;
        tail = new Node;
        tail = head;
        Node* curr;
        curr = new Node;
        curr = head->next;
        Node* temp;
        temp  = new Node;
        while(curr!=NULL)
        {
            temp = curr;
            curr= curr->next;
            temp->next = tail;
            tail = temp;
        }
        if(head->next->next==NULL)
        {
            tail = head->next;
        }
        head->next = NULL;
        head = tail;
    }
    return head;
}

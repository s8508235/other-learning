#include "function.h"
#include <iostream>
using namespace std;

Josephus ::Josephus()
{
    int i;
    for(i=0; i<10005; i++)
    {
        sequence[i] = 0;
    }
    noOfPeople = 1;
}
Josephus ::Josephus(const int &numbers)
{
    noOfPeople = numbers;
    generateSquare(numbers);
    generatecircularlinkedList(numbers);
}
Josephus ::~Josephus()
{
}
int Josephus ::kill() const
{
    Node *clean,*tail,*h;
    h = head ;
    clean=tail = h ->prev ;
    int i,j,k,l;
    i = noOfPeople;
    j = 1;
        while(i>1)
        {
            k = sequence[j] % i ;
            l = 0;
            while(l<k)
            {
                clean = tail ;
                tail = tail ->next ;
                l++;
            }
            if(k ==0) clean = clean ->next ;

            clean ->next = tail ->next;
            tail ->next->prev = clean ;
            delete tail ;
            tail = clean ;
            j++;
            i--;
        }/*
        i = tail ->number;
    delete tail ;*/
    return tail->number;
}
void Josephus ::generatecircularlinkedList(const int &num)
{
    Node *temp,*curr ;

    head = new Node(1);
    curr = head ;
    int i;
    for(i=2; i<=num; i++)
    {

        temp = new Node(i);
        curr->next = temp ;
        temp ->prev = curr;
        curr = temp ;
    }
    curr ->next = head;
    head ->prev = curr;
}
void Josephus ::generateSquare(const int &num)
{
    int i;
    for(i=1; i<num; i++)
    {
        sequence[i] = i*i;
    }
}

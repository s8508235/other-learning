#include <iostream>
#include <string>
#include "function.h"
using namespace std;

HugeInteger ::HugeInteger()
{
    int i;
    for(i=0;i<42;i++)
    {
        integer[i] = 0;
    }
    noOfDigits = 0;
}
HugeInteger ::HugeInteger(const std::string &name)
{
   // cout<<"first run "<<endl;
    int i,j ;
    for(i=0;i<42;i++)
    {
        if(isdigit(name[i])!=1) {
                j  =  i;
                break ;
        }
    }
    for(i=0;i<42;i++)
    {
        integer[i] = 0 ;
    }
    this->noOfDigits = j;
    //cout<<"j:"<<j<<endl;
    for(i=0;i<noOfDigits;i++)
    {
        integer[i] = name[j-1] - '0' ;
        j--;
    }
   /*  for(i=0;i<noOfDigits;i++)
    {
       cout<<"integer["<<i<<"]:"<< integer[i] <<endl;
        cout<<"name["<<i<<"]:"<< name[i] <<endl;
    }*/
}
HugeInteger HugeInteger ::add(const HugeInteger &fat) const
{

    int i ;
    HugeInteger x;
    int c[43];
    c[0]=0;
    int j ;
    j = max(fat.noOfDigits,this->noOfDigits);
   // cout<<"j:"<<j<<endl;
    for(i=0;i<=j;i++)
    {
        c[i]=0;
        x.integer[i] = 0;
    }
    c[i+1] = 0;
    x.noOfDigits = j ;
    for(i=0;i<=j;i++)
    {
        x.integer[i]=this->integer[i]+fat.integer[i]+c[i];
        if(x.integer[i]>=10){
            x.integer[i]-=10;
            c[i+1] ++;
        }/*
        cout<<"c["<<i+1<<"]:"<<c[i+1]<<endl;

        cout<<"x.integer["<<i<<"]:"<<x.integer[i]<<endl;*/
    }
    //cout<<"end"<<endl;
    if(x.integer[i-1]!=0) x.noOfDigits++;/*
    for(i=0;i<x.noOfDigits;i++)
    {
       cout<<"x.integer["<<i<<"]:"<< x.integer[i] <<endl;
        cout<<"fat["<<i<<"]:"<< fat.integer[i] <<endl;
    }*/
    return x ;
}
 HugeInteger HugeInteger ::add(const std::string &fat) const
{
   int i,j;
   int c[42];
   HugeInteger x,y;
   for(i=0;i<42;i++){
    if(isdigit(fat[i])==0) {
            j = i;
        break;
    }
   }
   for(i=0;i<42;i++)
    {
        c[i] = 0;
        y.integer[i]=0;
        x.integer[i]=0;
   }
   c[i+1] = 0;
   x.noOfDigits = j;
   for(i=0;i<x.noOfDigits;i++)
   {
        x.integer[i] = fat[j-1]-'0';
        j--;
   }/*
   for(i=0;i<x.noOfDigits;i++)
   {
        cout<<"x["<<i<<"]:"<<x.integer[i]<<endl;
   }*/
    y.noOfDigits = max(x.noOfDigits,this->noOfDigits);
    for(i=0;i<=y.noOfDigits;i++){
        y.integer[i] = x.integer[i] + this->integer[i] + c[i];
            if(y.integer[i]>=10){
                y.integer[i]-=10;
                c[i+1]++;
            }
    }
    if(y.integer[i-1]!=0) {
            y.noOfDigits ++;
    }/*
    for(i=0;i<y.noOfDigits;i++){
        cout<<"y.integer["<<i<<"]:"<<y.integer[i]<<endl;
    }*/
   return y;
}
HugeInteger HugeInteger ::subtract(const HugeInteger &fat) const
{
    int i ;
    HugeInteger x;
    int c[43];
    c[0]=0;
    int j ;
    j = max(fat.noOfDigits,this->noOfDigits);
    for(i=0;i<=j;i++)
    {
        c[i]=0;
        x.integer[i] = 0;
    }

    x.noOfDigits = j ;
    for(i=0;i<j;i++){
            if(this->integer[i]+c[i]<fat.integer[i]){
                c[i+1]--;
            }
        x.integer[i] = this->integer[i] - fat.integer[i]+c[i+1]*(-10)+c[i];
    }
    if(x.integer[i-1]==0) x.noOfDigits--;/*
    for(i=0;i<x.noOfDigits;i++)
    {
       cout<<"x.integer["<<i<<"]:"<< x.integer[i] <<endl;
        cout<<"fat["<<i<<"]:"<< fat.integer[i] <<endl;
    }*/
     return x ;
}
HugeInteger HugeInteger ::subtract(const std::string &fat)const

{
    int i,j;
   int c[42];
   HugeInteger x,y;
   for(i=0;i<42;i++){
    if(isdigit(fat[i])==0){
        j = i;
        break ;
    }
   }
   c[0]=0;
      for(i=0;i<42;i++)
    {
        c[i] = 0;
        y.integer[i]=0;
        x.integer[i]=0;
   }
   c[i]=0;
   x.noOfDigits = j;
   for(i=0;i<x.noOfDigits;i++)
   {
        x.integer[i] = fat[j-1]-'0';
        j--;
   }
/*
   for(i=0;i<x.noOfDigits;i++)
    {
       cout<<"x.integer["<<i<<"]:"<< x.integer[i] <<endl;
    }*/
   y.noOfDigits = max(x.noOfDigits,this->noOfDigits);/*
   for(i=0;i<y.noOfDigits;i++){
    cout<<"this->integer["<<i<<"]:"<< this->integer[i] <<endl;
   }*/
    for(i=0;i<y.noOfDigits;i++){
              if(x.integer[i]>this->integer[i]+c[i]){
                c[i+1]--;
              }
            y.integer[i] = this->integer[i] - x.integer[i] + c[i+1]*(-10)+c[i];
    }

    if(y.integer[i-1]==0){
        y.noOfDigits --;
    }
/*
    for(i=0;i<y.noOfDigits;i++){
            cout<<"wt??"<<endl;
        cout<<"y.integer["<<i<<"]:"<<y.integer[i]<<endl;
    }*/
    return y ;
}
bool HugeInteger ::isGreaterThan(const HugeInteger &fat) const

{
    int i;
    for(i=this->noOfDigits-1;i>0;i--){
        if(this->integer[i]>fat.integer[i]){
            return true ;
        }
        else return false ;
    }
    return false ;
}
void HugeInteger::output() const
{
       int i;
       for(i=this->noOfDigits-1;i>=0;i--)
            std::cout<<this->integer[i];
}

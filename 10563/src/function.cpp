#include <iostream>
#include "function.h"
#include <string.h>
using namespace std;
HugeInteger ::HugeInteger()
{
    int i;
    for(i=0; i<42; i++)
    {
        integer[i] = 0;
    }
    noOfDigits = 1;
}
HugeInteger ::HugeInteger(const std::string &name)
{
    int i,j ;
    for(i=0; i<42; i++)
    {
        if(isdigit(name[i])!=1)
        {
            j  =  i;
            break ;
        }
    }
    for(i=0; i<42; i++)
    {
        integer[i] = 0 ;
    }
    this->noOfDigits = j;
    for(i=0; i<noOfDigits; i++)
    {
        integer[i] = name[j-1] - '0' ;
        j--;
    }
}
HugeInteger  HugeInteger:: operator+(const HugeInteger &fat) const
{

    int i ;
    HugeInteger x;
    int c[43];
    c[0]=0;
    int j ;
    j = max(fat.noOfDigits,this->noOfDigits);

    for(i=0; i<=j; i++)
    {
        c[i]=0;
        x.integer[i] = 0;
    }
    c[i+1] = 0;
    x.noOfDigits = j ;
    for(i=0; i<=j; i++)
    {
        x.integer[i]=this->integer[i]+fat.integer[i]+c[i];
        if(x.integer[i]>=10)
        {
            x.integer[i]-=10;
            c[i+1] ++;
        }
    }

    if(x.integer[i-1]!=0) x.noOfDigits++;
    return x ;
}
HugeInteger HugeInteger ::operator+(const std::string &fat) const
{
    int i,j;
    int c[42];
    HugeInteger x,y;
    for(i=0; i<42; i++)
    {
        if(isdigit(fat[i])==0)
        {
            j = i;
            break;
        }
    }
    for(i=0; i<42; i++)
    {
        c[i] = 0;
        y.integer[i]=0;
        x.integer[i]=0;
    }
    c[i+1] = 0;
    x.noOfDigits = j;
    for(i=0; i<x.noOfDigits; i++)
    {
        x.integer[i] = fat[j-1]-'0';
        j--;
    }/*
   for(i=0;i<x.noOfDigits;i++)
   {
        cout<<"x["<<i<<"]:"<<x.integer[i]<<endl;
   }*/
    y.noOfDigits = max(x.noOfDigits,this->noOfDigits);
    for(i=0; i<=y.noOfDigits; i++)
    {
        y.integer[i] = x.integer[i] + this->integer[i] + c[i];
        if(y.integer[i]>=10)
        {
            y.integer[i]-=10;
            c[i+1]++;
        }
    }
    if(y.integer[i-1]!=0)
    {
        y.noOfDigits ++;
    }/*
    for(i=0;i<y.noOfDigits;i++){
        cout<<"y.integer["<<i<<"]:"<<y.integer[i]<<endl;
    }*/
    return y;
}
HugeInteger HugeInteger ::operator-(const HugeInteger &fat) const
{
    int i ;
    HugeInteger x;
    int c[43];
    c[0]=0;
    int j ;
    j = max(fat.noOfDigits,this->noOfDigits);
    for(i=0; i<=j; i++)
    {
        c[i]=0;
        x.integer[i] = 0;
    }

    x.noOfDigits = j ;
    for(i=0; i<j; i++)
    {
        if(this->integer[i]+c[i]<fat.integer[i])
        {
            c[i+1]--;
        }
        x.integer[i] = this->integer[i] - fat.integer[i]+c[i+1]*(-10)+c[i];
    }
    if(x.integer[i-1]==0) x.noOfDigits--;

    return x ;
}
HugeInteger HugeInteger ::operator-(const std::string &fat)const
{
    int i,j;
    int c[42];
    HugeInteger x,y;
    for(i=0; i<42; i++)
    {
        if(isdigit(fat[i])==0)
        {
            j = i;
            break ;
        }
    }
    c[0]=0;
    for(i=0; i<42; i++)
    {
        c[i] = 0;
        y.integer[i]=0;
        x.integer[i]=0;
    }
    c[i]=0;
    x.noOfDigits = j;
    for(i=0; i<x.noOfDigits; i++)
    {
        x.integer[i] = fat[j-1]-'0';
        j--;
    }

    y.noOfDigits = max(x.noOfDigits,this->noOfDigits);
    for(i=0; i<y.noOfDigits; i++)
    {
        if(x.integer[i]>this->integer[i]+c[i])
        {
            c[i+1]--;
        }
        y.integer[i] = this->integer[i] - x.integer[i] + c[i+1]*(-10)+c[i];
    }

    if(y.integer[i-1]==0)
    {
        y.noOfDigits --;
    }

    return y ;
}
HugeInteger HugeInteger :: operator*(const HugeInteger &fat) const
{
    HugeInteger x;
    int i,j,k ;
    k  = this->noOfDigits + fat.noOfDigits;
    int mux[k];
    for(i=0; i<k; i++)
    {
        mux[i] = 0;
    }
    int z = 0;
    for(i=0; i<this->noOfDigits; i++)
    {
        for(j=0; j<fat.noOfDigits; j++)
        {
            z = i + j;
            mux[z] += this->integer[i]*fat.integer[j];
            if(mux[z]>=10)
            {
                mux[z+1]+=mux[z]/10;
                mux[z]=mux[z]%10;
            }
        }
    }
    for(i=0; i<k; i++)
    {
        x.integer[i] =  mux[i];
    }
    x.noOfDigits = k;

    while(mux[k-1]==0)
    {
        x.noOfDigits --;
        k--;
        if(k==1) break ;
    }
    return x ;
}
HugeInteger HugeInteger :: operator*(const std:: string&fat) const
{
    int i,j;

    HugeInteger x,y;
    for(i=0; i<42; i++)
    {
        if(isdigit(fat[i])==0)
        {
            j = i;
            break ;
        }
    }
    for(i=0; i<42; i++)
    {
        y.integer[i]=0;
        x.integer[i]=0;
    }
    x.noOfDigits = j;
    for(i=0; i<x.noOfDigits; i++)
    {
        x.integer[i] = fat[j-1]-'0';
        j--;
    }
    int k ;
    k  = this->noOfDigits + x.noOfDigits;
    int mux[k];
    for(i=0; i<k; i++)
    {
        mux[i] = 0;
    }
    int z = 0;
    for(i=0; i<this->noOfDigits; i++)
    {
        for(j=0; j<x.noOfDigits; j++)
        {
            z = i + j;
            mux[z] += this->integer[i]*x.integer[j];
            if(mux[z]>=10)
            {
                mux[z+1]=mux[z+1]+mux[z]/10;
                mux[z] = mux[z]%10;
            }
        }
    }
    for(i=0; i<k; i++)
    {
        y.integer[i] =  mux[i];
    }
    y.noOfDigits = k;

    while(mux[k-1]==0)
    {
        y.noOfDigits --;
        k--;
        if(k==1) break ;
    }
    return y ;
}
bool HugeInteger ::operator>(const HugeInteger &fat) const
{
    int i;
    int j = max(this->noOfDigits,fat.noOfDigits);
    for(i=j-1; i>=0; i--)
    {
        if(this->integer[i]>fat.integer[i])
        {
            return true ;
        }
        else if(this->integer[i]==fat.integer[i])
        {

        }
        else return false ;
    }
    return false ;
}
HugeInteger HugeInteger :: operator/(const HugeInteger &fat) const
{
    HugeInteger w,x,y,z,a,b,c,d;

    int i;
    for(i=0;i<42;i++)
    {
        w.integer[i]=0;
        x.integer[i]=0;
        y.integer[i]=0;
        z.integer[i]=0;
        a.integer[i]=0;
        b.integer[i]=0;
        c.integer[i]=0;
        d.integer[i]=0;
    }
    for(i=0;i<this->noOfDigits;i++)
    {
        d.integer[i] = this->integer[i];
        z.integer[i] = this->integer[i];
    }
    d.noOfDigits = this->noOfDigits;
    z.noOfDigits =this->noOfDigits;
    a.noOfDigits = 1 ;
    y.integer[0] = 1;
    y.noOfDigits = 1;
    if(fat>d) return HugeInteger ("0") ;

    while((d>a)&&((a>d)==0))
    {
        x = d + a;
        for(i=x.noOfDigits-1;i>=0;i--)
        {
            if(x.integer[i]%2 ==1&& i!=0)
            {
                x.integer[i-1] += 10;
            }
            x.integer[i]/=2;
        }

        for(i=x.noOfDigits-1;i>=0;i--)
        {
            if(x.integer[i]==0){
                x.noOfDigits--;
            }
            else{
                break ;
            }
        }
        c = fat * x;
        if(c > z)
        {
            d = x - y ;
        }
        else if(z>c)
        {
            a = x + y ;
        }
        else {
            return x ;
        }
    }

    return d;
}
HugeInteger HugeInteger :: operator/(const std::string &fat) const
{
    HugeInteger d,x;
    x.noOfDigits = noOfDigits;
    int i;
    for(i=0;i<noOfDigits;i++)
    {
        x.integer[i] = integer[i];
    }
    d = x/(HugeInteger(fat));
   /* int i,j;
    HugeInteger w,x,y,z,a,b,c,d;

    for(i=0;i<42;i++)
    {
        w.integer[i]=0;
        x.integer[i]=0;
        y.integer[i]=0;
        z.integer[i]=0;
        a.integer[i]=0;
        b.integer[i]=0;
        c.integer[i]=0;
        d.integer[i]=0;
    }
    for(i=0; i<42; i++)
    {
        if(isdigit(fat[i])==0)
        {
            j = i;
            break ;
        }
    }
    b.noOfDigits = j;
    for(i=0; i<b.noOfDigits; i++)
    {
        b.integer[i] = fat[j-1]-'0';
        j--;
    }
    for(i=0;i<this->noOfDigits;i++)
    {
        d.integer[i] = this->integer[i];
        z.integer[i] = this->integer[i];
    }
    d.noOfDigits = this->noOfDigits;
    z.noOfDigits =this->noOfDigits;
    a.noOfDigits = 1 ;
    y.integer[0] = 1;
    y.noOfDigits = 1;
    if(b>d) return HugeInteger ("0") ;

    while((d>a)&&((a>d)==0))
    {
        x = d + a;
        for(i=x.noOfDigits-1;i>=0;i--)
        {
            if(x.integer[i]%2 ==1&& i!=0)
            {
                x.integer[i-1] += 10;
            }
            x.integer[i]/=2;
        }
        for(i=x.noOfDigits-1;i>=0;i--)
        {
            if(x.integer[i]==0){
                x.noOfDigits--;
            }
            else{
                break ;
            }
        }
        c = b * x;
        if(c > z)
        {
            d = x - y ;
        }
        else if(z>c)
        {
            a = x + y ;
        }
        else {
            return x ;
        }
    }
*/
    return d;
}
ostream &operator<<( ostream &output, const HugeInteger &a )
{
    int i;
    for(i=a.noOfDigits-1; i>=0; i--)
        std::cout<<a.integer[i];
    return output ;
}

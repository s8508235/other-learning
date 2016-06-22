#include <iostream>
#include "function.h"
using namespace std;
int GCD(int a,int b);
int lcm(int a,int b);
Rational::Rational(int a,int b)
{
    //cout<<"fat";
    numerator = a;
    // cout<<a<<endl;
    denominator = b;
    //cout<<b<<endl;
    this->reduce();
}

Rational Rational::addition(const Rational &x) const

{
    Rational y;
    int w;
    w = lcm(x.denominator,this->denominator);
    y.numerator = x.numerator * w / x.denominator + this->numerator * w /this->denominator;
    y.denominator = w;
    y.reduce();
    if(y.denominator<0) {
        y.denominator = -y.denominator;
        y.numerator = -y.numerator;
    }
    return y ;
}

Rational Rational::subtraction( const Rational &x) const

{
    Rational y;
    int w;
    w = lcm(x.denominator,this->denominator);
    //cout<<"w:"<<w<<endl;

    y.numerator = this->numerator * w / this->denominator - x.numerator * w/x.denominator;
   // cout<<"1:"<<x.numerator * w / x.denominator <<"2:"<< this->numerator * w /this->denominator<<endl;
    y.denominator = w;
   // cout<<"y:"<<y.numerator<<"/"<<y.denominator<<endl;
    y.reduce();
    if(y.denominator<0) {
        y.denominator = -y.denominator;
        y.numerator = -y.numerator;
    }
    return y ;
}

Rational Rational::multiplication( const Rational &x ) const
{
    Rational y;
    y.numerator=x.numerator*this->numerator;
    y.denominator = x.denominator * this->denominator;
    y.reduce();
    if(y.denominator<0) {
        y.denominator = -y.denominator;
        y.numerator = -y.numerator;
    }
    return y ;
}
Rational Rational::division ( const Rational &x ) const
{
    Rational y;
    y.numerator = this->numerator*x.denominator;
    //cout<<"y.n:"<<y.numerator;
    y.denominator = this->denominator * x.numerator;
   // cout <<" y.d:"<<y.denominator;
    y.reduce();
    if(y.denominator<0) {
        y.denominator = -y.denominator;
        y.numerator = -y.numerator;
    }
    return y ;
}
void Rational::printRational() const
{
    cout<<numerator<<"/"<<denominator;
}
void Rational::reduce()
{
    int a,b;
    a = numerator;
    b = denominator;
    int x;

    x = GCD(a,b);
    numerator /=x;
    denominator /=x ;
}
int GCD(int a, int b){
    if(a==0||b==0) return 1;
    /*int i = 1;

    if(a<0 && b>0){
        a = -a;
        i = -1;
    }
    else if(a>0&& b<0)
    {
        b = -b;
        i = -1;
    }
    else if(a<0&&b<0)
    {
        a = -a;
        b = -b;
    }

    if(a<b) return GCD(b,a);

    //cout<<"a:"<<a<<"b:"<<b<<endl;
*/
        if (a%b == 0)
        return b;
        else
        return GCD(b, a%b);
}
int lcm(int a,int b){
    int t;
    t= a*b/GCD(a, b);
    return t;

}

#ifndef Implement_h
#define Implement_h

#include "ExpressionEval.h"

class Implement : public ExpressionEval
{
public:

    // all you have to do is add codes here
    virtual const char* getStudentID();

    //----------------------------------------------------------------------
    // convert the input infix expression to prefix one
    //----------------------------------------------------------------------
    virtual void infix2Prefix(Expression &prefix, const Expression &infix);

    //----------------------------------------------------------------------
    // convert the input infix expression to postfix one
    //----------------------------------------------------------------------
    virtual void infix2Postfix(Expression &postfix, const Expression &infix);

    //----------------------------------------------------------------------
    // evaluate the input prefix expression
    //----------------------------------------------------------------------
    virtual int evalPrefix(const Expression &prefix);

    //----------------------------------------------------------------------
    // evaluate the input postfix expression
    //----------------------------------------------------------------------
    virtual int evalPostfix(const Expression &postfix);
};
class Stack
{
    public:
            Stack(int );
            bool isempty() const;
            void Push(const char& item);
            void Pop();
            char* why;
            int top;
            int cap;
};
#endif

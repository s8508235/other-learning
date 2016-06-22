#include "YourTest.h"
void YourTest( ExpressionEval & inst )
{
    try
    {
        //test cases
        Expression exps[3][3];
        int value[3];

        //test case 1
        exps[0][0] = "(1+2)/3+5-7-2-2+8"; //infix
        exps[0][1] =     "+---+/+12357228"; //prefix
        exps[0][2] =     "12+3/5+7-2-2-8+"; //postfix
        value[0]   =                3; //evaluation value

        //test case 2
        exps[1][0] = "5+7*1+(4-8)-5+4"; //infix
        exps[1][1] =   "+-++5*71-4854"; //prefix
        exps[1][2] =   "571*+48-+5-4+"; //postfix
        value[1]   =             7; //evaluation value

        //test case 3
        exps[2][0] = "((1*2)+(6/2))-((1*2)+(6/2))"; //infix
        exps[2][1] =   "-+*12/62+*12/62"; //prefix
        exps[2][2] =   "12*62/+12*62/+-"; //postfix
        value[2]   =            0; //evaluation value

        //try each case
        bool isPass = true;
        for(int i=0;i<3;i++)
        {
            std::cout << "process the test case " << i << "... ";

            //convert infix to prefix and postfix
            Expression urPrefix, urPostfix;
            inst.infix2Prefix (  urPrefix, exps[i][0] );
            inst.infix2Postfix( urPostfix, exps[i][0] );

            //evaluate the expression using prefix, postfix.
            int urValuePre  = inst.evalPrefix ( exps[i][1] );
            int urValuePost = inst.evalPostfix( exps[i][2] );

            //compare your result with the ground truth
            bool pass1 = urPrefix==exps[i][1] && urPostfix==exps[i][2];
            bool pass2 = urValuePre==value[i] && urValuePost==value[i];

            if( pass1 && pass2 )
                std::cout << "done." << std::endl;
            else
            {
                std::cout << "fail." << std::endl;

                std::cout << "[ yours | answer ]" << std::endl;
                std::cout << "prefix:    [ if" << urPrefix    << " | " << exps[i][1] << " ]" << std::endl;
                std::cout << "postfix:   [ " << urPostfix   << " | " << exps[i][2] << " ]" << std::endl;
                std::cout << "eval pre:  [ " << urValuePre  << " | " <<   value[i] << " ]" << std::endl;
                std::cout << "eval post: [ " << urValuePost << " | " <<   value[i] << " ]" << std::endl;
                std::cout << "" << std::endl;
            }
            isPass = isPass && pass1 && pass2;
        }

        std::cout << inst.getStudentID();
        if( isPass )
            std::cout << " passes my test.";
        else
            std::cout << " fails my test.";
        std::cout << std::endl;
    }
    catch(const char* str)
    {
        std::cout << "The implementation is not done. : [" << str << "]" << std::endl;
    }
}
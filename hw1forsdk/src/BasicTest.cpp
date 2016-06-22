//========================DO-NOT-MODIFY-THE-FILE========================

#include "BasicTest.h"

void BasicTest( ExpressionEval & inst )
{
    try
    {
        //test cases
        Expression exps[3][3];
        int value[3];

        //test case 1
        exps[0][0] = "(1+2)*3*(2+3/1)"; //infix
        exps[0][1] =     "**+123+2/31"; //prefix
        exps[0][2] =     "12+3*231/+*"; //postfix
        value[0]   =                45; //evaluation value

        //test case 2
        exps[1][0] = "5+2*1+(4-5)"; //infix
        exps[1][1] =   "++5*21-45"; //prefix
        exps[1][2] =   "521*+45-+"; //postfix
        value[1]   =             6; //evaluation value

        //test case 3
        exps[2][0] = "1+(7*1+2)*3"; //infix
        exps[2][1] =   "+1*+*7123"; //prefix
        exps[2][2] =   "171*2+3*+"; //postfix
        value[2]   =            28; //evaluation value

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
            std::cout << " passes the basic test.";
        else
            std::cout << " fails the basic test.";
        std::cout << std::endl;
    }
    catch(const char* str)
    {
        std::cout << "The implementation is not done. : [" << str << "]" << std::endl;
    }
}

//========================DO-NOT-MODIFY-THE-FILE========================

//========================DO-NOT-MODIFY-THE-FILE========================
#include "BasicTest.h"

void BasicTest( const TextAnalyzer &inst )
{
    try
    {
        LetterStats ls;
        inst.analyzeText(ls, "pqrStUuvvwwwxxyyYyyzzz !0*-+");

        //Y W Z U V X P Q R S T A B C D E F G H I J K L M N O
        //5 3 3 2 2 2 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
        std::string ansOrder = "YWZUVXPQRSTABCDEFGHIJKLMNO";
        int ansCount[] = {5,3,3,2,2,2,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

        bool pass = true;
        for(int i=0;i<26;i++)
        {
            pass &= ls.data[i].c == ansOrder[i];
            pass &= ls.data[i].count == ansCount[i];
        }

        if( pass )
            std::cout << "you pass the basic test" << std::endl;
        else
            std::cout << "you fail the basic test" << std::endl;
    }
    catch(const char* str)
    {
        std::cout << "The implementation is not done. : [" << str << "]" << std::endl;
    }
}

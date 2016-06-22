#include "YourTest.h"

void YourTest( const TextAnalyzer &inst )
{
     try
    {
        LetterStats ls;
        inst.analyzeText(ls, "*- yugio*-5h duelmonsters reverse generationnext fivedragons zexal arcv/)(!0*-+");

        //Y W Z U V X P Q R S T A B C D E F G H I J K L M N O
        //5 3 3 2 2 2 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
        std::string ansOrder = "ERNAOSGITVDLUXCFHMYZBJKPQW";
        int ansCount[] = {10,6,5,4,4,4,3,3,3,3,2,2,2,2,1,1,1,1,1,1,0,0,0,0,0,0};

        bool pass = true;
        for(int i=0;i<26;i++)
        {
            pass &= ls.data[i].c == ansOrder[i];
            pass &= ls.data[i].count == ansCount[i];
        }

        if( pass )
            std::cout << "you pass your test" << std::endl;
        else
            std::cout << "you fail your test" << std::endl;
    }
    catch(const char* str)
    {
        std::cout << "The implementation is not done. : [" << str << "]" << std::endl;
    }
}

//========================DO-NOT-MODIFY-THE-FILE========================

#ifndef TextAnalyzer_H
#define TextAnalyzer_H

#include "LetterStats.h"
#include <string>

class TextAnalyzer
{
public:
    //----------------------------------------------------------------------
    // return your student ID
    //----------------------------------------------------------------------
    virtual const char* getStudentID()const;

    //----------------------------------------------------------------------
    // Analyze the text and finish the following.
    // 1. eliminate non-letter chars(!0123*,.....)
    // 2. capitalize each letter
    // 3. Sort the stats with respect to frequency in descending order. If a few
    //    letters have the same frequency, they are sorted in alphabetically
    //    ascending order.
    //
    // For example:
    // the input string "pqrStUuvvwwwxxyyYyyzzz !0*-+" will lead to the result
    // CharStats::data
    //     c: Y W Z U V X P Q R S T A B C D E F G H I J K L M N O
    // count: 5 3 3 2 2 2 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
    //----------------------------------------------------------------------
    virtual void analyzeText(LetterStats &stats, std::string str)const;
};

#endif

//========================DO-NOT-MODIFY-THE-FILE========================

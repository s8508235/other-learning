#ifndef LetterStats_hpp
#define LetterStats_hpp

#include <iostream>

// stats for a letter
class LetterStat
{
public:
    LetterStat():c('A'),count(0){};

    //letter
    char c;

    //count of c
    int count;
};

class LetterStats
{
public:
    // stats array from A to Z
    LetterStat data[26];

    LetterStats();

    //reset the LetterStats
    void reset();

    //comparison operator between two LetterStats
    bool operator==(const LetterStats &ls);

    //operator<<
    friend std::ostream& operator<<(std::ostream &os, const LetterStats &ls);
};

#endif /* CharStats_hpp */

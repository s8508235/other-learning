#include "LetterStats.h"

LetterStats::LetterStats()
{
    this->reset();
}

//reset the LetterStats
void LetterStats::reset()
{
    for(int i=0;i<26;i++)
    {
        this->data[i].c = i+'A';
        this->data[i].count = 0;
    }
}

//comparison operator between two LetterStats
bool LetterStats::operator==(const LetterStats &ls)
{
    for(int i=0;i<26;i++)
    {
        if( ls.data[i].c != this->data[i].c )
            return false;

        if( ls.data[i].count != this->data[i].count )
            return false;
    }
    return true;
}

//operator<<
std::ostream& operator<<(std::ostream &os, const LetterStats &ls)
{
    for(int i=0;i<26;i++)
        std::cout << ls.data[i].c << " ";
    std::cout << std::endl;
    for(int i=0;i<26;i++)
        std::cout << ls.data[i].count << " ";
    std::cout << std::endl;

    return os;
}

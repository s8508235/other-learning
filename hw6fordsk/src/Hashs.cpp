#include "Hashs.h"

//reset the Hashs
void Hashs::reset()
{
    for(int i=0;i<SIZE;i++)
		this->table[i].data="";
}

//comparison operator between string array and Hashs table
bool Hashs::operator==(const std::string l[])
{
    for(int i=0;i<SIZE;i++)
    {
        if( l[i]!= this->table[i].data )
            return false;
    }
    return true;
}

//ouput operator of Hashs
std::ostream& operator<<(std::ostream &os, const Hashs &ls)
{
    for(int i=0;i<SIZE;i++)
        std::cout <<i<<": "<< ls.table[i].data << "\n";
    std::cout << std::endl;

    return os;
}

#include "Implement.h"
int ruleA(char c);
int rule(char c);
const char* Implement::getStudentID()
{
    return "103062210";
}//a b c d e f g h i j k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z
// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25

void Implement::add(Hashs &inst, std::string str)
{
    int check_empty=0;
    for(int j = 0;j<23;j++)
    {
        if(inst.table[j].data!="")
            check_empty++;
    }
    if(check_empty!=23)
    {
        char s;
        unsigned int i=0;
        s = str[i];
        int fc = rule(s);
        while(inst.table[fc].data!="")
        {
           if(str.length()>1&& i!=str.length()-1)
           {
                i++;
                s = str[i];
                fc = rule(s);
           }
           else
           {
               if(fc!=22)
               fc++;
               else
                fc = 0;
           }

        }
        inst.table[fc].data = str;
    }
    else
    {
        char s ;
        s = str[str.length()-1];
        int fc = rule(s);
        inst.table[fc].data = str;
    }
    return ;



}
int ruleA(char c)
{
    if(toupper(c)-'A'<10)
    {
        return 7;
    }
    else if (toupper(c)-'K'>=0&&toupper(c)-'K'<10)
    {
        return 11;
    }
    else if(toupper(c)-'U'>=0&&toupper(c)-'U'<6)
    {
        return 13;
    }
    return -1;
}
int rule(char c)
{
    int rule = ruleA(c);
    int f = (toupper(c)-'A') *rule;
    int fc = f %23;
    return fc;
}

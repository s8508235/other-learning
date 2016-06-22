//========================DO-NOT-MODIFY-THE-FILE========================

#include "BasicTest.h"
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>


void BasicTest( HashOperations &inst)
{
    try
    {
        int passNum = 0;
        //try each case
        int num=1;
		std::string item[10]={"a","b","c","d","e","f","g","h","i","j"};
		std::string item_res[SIZE]={"a","","","h","","e","","b","","","i","","f","","c","","","j","","g","","d",""};
		std::string item_2[15]={"k","l","m","n","o","p","q","r","s","t","U","v","apple","Queen","King"};
		std::string item_2_res[SIZE]={"apple","","t","r","p","n","l","U","Queen","","King","","","","s","q","o","m","k","","v","",""};
		std::string item_3[5]={"a","ab","abbe","abbbbc","abbbbcceed"};
		std::string item_3_res[SIZE]={"a","","","","","abbe","","ab","","","","","","","abbbbc","","","","","","","abbbbcceed",""};
		std::string item_4[24]={"a","b","c","d","e","f","g","h","i","j","k","L","m","n","o","p","Q","R","S","T","U","V","W","a"};
        std::string item_4_res[SIZE]={"a","V","T","h","p","e","L","b","n","R","i","U","f","W","c","Q","o","j","k","g","m","d","S"};
		std::string item_5[24]={"a","b","c","d","e","f","g","h","i","j","k","L","m","n","o","p","Q","R","S","T","U","V","W","aa"};
        std::string item_5_res[SIZE]={"aa","V","T","h","p","e","L","b","n","R","i","U","f","W","c","Q","o","j","k","g","m","d","S"};
		std::string item_6[25]={"a","b","c","d","e","f","g","h","i","j","k","L","m","n","o","p","Q","R","S","T","U","V","W","aa","brb"};
        std::string item_6_res[SIZE]={"aa","V","T","h","p","e","L","brb","n","R","i","U","f","W","c","Q","o","j","k","g","m","d","S"};

		Hashs stat;
		//////////////////    basic test 1    ////////////////////
		for(int i=0;i<sizeof(item)/sizeof(std::string);i++)
			inst.add(stat,item[i]);
		bool ispass=stat==item_res;

		if(ispass)
			std::cout<<"basic test 1 Pass!!!"<<"\n";
		else
			std::cout<<"basic test 1 Fail###"<<"\n";
		stat.reset();
		//////////////////    basic test 2    ////////////////////
		for(int i=0;i<sizeof(item_2)/sizeof(std::string);i++)
			inst.add(stat,item_2[i]);
		ispass=stat==item_2_res;
		if(ispass)
			std::cout<<"basic test 2 Pass!!!"<<"\n";
		else
			std::cout<<"basic test 2 Fail###"<<"\n";
		stat.reset();
		//////////////////    basic test 3    ////////////////////
		for(int i=0;i<sizeof(item_3)/sizeof(std::string);i++)
			inst.add(stat,item_3[i]);
		ispass=stat==item_3_res;
		if(ispass)
			std::cout<<"basic test 3 Pass!!!"<<"\n";
		else
			std::cout<<"basic test 3 Fail###"<<"\n";
        stat.reset();
        /// ////////////////////////////////////////// 4

		for(int i=0;i<sizeof(item_4)/sizeof(std::string);i++)
			inst.add(stat,item_4[i]);
        ispass=stat==item_4_res;

        for(int i=0;i<SIZE;i++){
            std::cout<<i<<":"<<stat.table[i].data<<std::endl;
        }
        std::cout<<std::endl;

		if(ispass)
			std::cout<<"basic test 4 Pass!!!"<<"\n";
		else
			std::cout<<"basic test 4 Fail###"<<"\n";
        stat.reset();
        /// //////////////////////////// 5
		for(int i=0;i<sizeof(item_5)/sizeof(std::string);i++)
			inst.add(stat,item_5[i]);
        ispass=stat==item_5_res;

        for(int i=0;i<SIZE;i++){
            std::cout<<i<<":"<<stat.table[i].data<<std::endl;
        }
        std::cout<<std::endl;

		if(ispass)
			std::cout<<"basic test 5 Pass!!!"<<"\n";
		else
			std::cout<<"basic test 5 Fail###"<<"\n";
        stat.reset();
        /// //////////////////////////// 6
		for(int i=0;i<sizeof(item_6)/sizeof(std::string);i++)
			inst.add(stat,item_6[i]);
        ispass=stat==item_6_res;

       /* for(int i=0;i<SIZE;i++){
            std::cout<<i<<":"<<stat.table[i].data<<std::endl;
        }
        std::cout<<std::endl;*/

		if(ispass)
			std::cout<<"basic test 6 Pass!!!"<<"\n";
		else
			std::cout<<"basic test 6 Fail###"<<"\n";
        stat.reset();

    }
    catch(const char* str)
    {
        std::cout << "The implementation is not done. : [" << str << "]" << std::endl;
    }
}

//========================DO-NOT-MODIFY-THE-FILE========================

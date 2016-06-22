//========================DO-NOT-MODIFY-THE-FILE========================

#include <iostream>
#include "Implement.h"

#include "BasicTest.h"
#include "YourTest.h"

int main()
{
	Implement implementObj;

    //execute the basic test designed by TA
    std::cout << "TA's basic test:" << std::endl;
	BasicTest( implementObj );
    std::cout << std::endl;

    //execute your tests
    std::cout << "Your test:" << std::endl;
    YourTest ( implementObj );
    std::cout << std::endl;

	return 0;
}

//========================DO-NOT-MODIFY-THE-FILE========================

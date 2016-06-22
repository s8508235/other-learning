#include "YourTest.h"

void YourTest(  GraphOperations &inst )
{
    try
    {
        inst.adjListAllocation(100);
        bool pass = true;
        inst.addEdge(0,0);
        inst.addEdge(0,1);
        inst.addEdge(0,2);
        inst.addEdge(0,3);
        inst.addEdge(1,2);
        inst.addEdge(1,3);
        inst.addEdge(2,3);
        pass &= (3 == inst.degree(2));
        pass &= (true == inst.isExistPath(0,1));
        inst.deleteEdge(0,1);
        inst.deleteEdge(0,2);
        inst.deleteEdge(1,3);
        pass &= (true == inst.isExistPath(0,1));
        inst.deleteVertex(0);
        pass &= (2 == inst.degree(2));
        if( pass )
            std::cout << inst.getStudentID() << " passes the basic test." << std::endl;
        else
            std::cout << inst.getStudentID() << " fails the basic test." << std::endl;
        inst.deleteGraph(100);

    }
    catch(const char* str)
    {
        std::cout << "The implementation is not done. : [" << str << "]" << std::endl;
    }


}

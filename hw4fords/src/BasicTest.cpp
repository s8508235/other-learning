//========================DO-NOT-MODIFY-THE-FILE========================
#include "BasicTest.h"
void BasicTest(  GraphOperations &inst )
{
    try
    {
        inst.adjListAllocation(100);
        bool pass = true;
        inst.addEdge(0,1);
        inst.addEdge(0,2);
        inst.addEdge(0,3);
        inst.addEdge(0,4);
        inst.addEdge(1,3);
        inst.addEdge(1,4);
        inst.addEdge(2,5);
        inst.addEdge(4,5);
        inst.addEdge(5,4);
        inst.addEdge(5,6);
        inst.addEdge(6,7);
        pass &= (3 == inst.degree(4));
        pass &= (true == inst.isExistPath(3,7));
        inst.deleteEdge(6,7);
        pass &= (false == inst.isExistPath(3,7));
        inst.deleteVertex(5);
        pass &= (1 == inst.degree(2));
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
//========================DO-NOT-MODIFY-THE-FILE========================

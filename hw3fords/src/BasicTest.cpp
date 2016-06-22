//========================DO-NOT-MODIFY-THE-FILE========================
#include "BasicTest.h"
using namespace std;
void BasicTest( const BinearyTreeOperations &inst )
{
    try
    {
        TreeNode *root;
        inst.constructTree( &root, "(99()(35(37()())()))" );

        bool pass = true;
        pass &= root->weight == 99;
        pass &= root->left == NULL;
        pass &= root->right->weight == 35;
        pass &= root->right->left->weight == 37;
        pass &= root->right->right == NULL;
        pass &= root->right->left->left == NULL;
        pass &= root->right->left->right == NULL;
        pass &= 2==inst.treeHeight(root);
        pass &= 171==inst.treeWeight(root);
        pass &= 1==inst.leafNum(root);
        pass &= 171==inst.maxPathWeight(root);
        if( pass )
            std::cout << inst.getStudentID() << " passes the basic test." << std::endl;
        else
            std::cout << inst.getStudentID() << " fails the basic test." << std::endl;

        inst.deleteTree( &root );
    }
    catch(const char* str)
    {
        std::cout << "The implementation is not done. : [" << str << "]" << std::endl;
    }
}
//========================DO-NOT-MODIFY-THE-FILE========================

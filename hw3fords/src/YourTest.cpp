#include "YourTest.h"

void YourTest( const BinearyTreeOperations &inst )
{

    try
    {
        TreeNode *root;
        inst.constructTree( &root, "()" );

        bool pass = true;
        pass &= root == NULL;
        std::cout<<pass<<std::endl;
        /*
        pass &= root->left==NULL ;
        pass &= root->right->weight == 35;
        pass &= root->right->left->weight == 37;
        pass &= root->right->right == NULL;
        pass &= root->right->left->left== NULL;
        pass &= root->right->left->right->weight == 14;*/
        pass &= 4==inst.treeHeight(root);
        pass &= 270==inst.treeWeight(root);
        pass &= 1==inst.leafNum(root);
        pass &= 270==inst.maxPathWeight(root);

        if( pass )
            std::cout << inst.getStudentID() << " passes YourTest." << std::endl;
        else
            std::cout << inst.getStudentID() << " fails YourTest." << std::endl;

        inst.deleteTree( &root );
    }
    catch(const char* str)
    {
        std::cout << "The implementation is not done. : [" << str << "]" << std::endl;
    }
}

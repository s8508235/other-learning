#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

std::vector<int> treeIn;
std::vector<int> treePre;

void str2Array(std::vector<int> &treeOrder, std::string treeStr)
{
    treeOrder.clear();

    int node;
    std::istringstream iss(treeStr);
    while( iss >> node )
        treeOrder.push_back(node);
}

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data):left(NULL),right(NULL)
    {
        this->data = data;
    }
};

void deleteTree(Node **proot)
{
    if( *proot == NULL )
        return;

    deleteTree( &((*proot)->left) );
    deleteTree( &((*proot)->right) );
    delete *proot;
}

void buildTree(Node **proot, int inStart, int inEnd, int preStart, int preEnd )
{
    if( inStart >= inEnd )
        return;
    if( preStart >= preEnd )
        return;

    int rootData = treePre[ preStart ];
    *proot = new Node(rootData);

    //find root
    int i=inStart;
    for(;i<inEnd;i++)
        if( rootData==treeIn[i] )
            break;
    if( i==inEnd )
        std::cout << "error" << std::endl;
    int leftTreeNodeNum = i-inStart;

    int leftInStart = inStart;
    int leftInEnd = leftInStart + leftTreeNodeNum;
    int leftPreStart = preStart+1;
    int leftPreEnd = leftPreStart + leftTreeNodeNum;

    int rightInStart = leftInEnd + 1;
    int rightInEnd = inEnd;
    int rightPreStart = leftPreEnd;
    int rightPreEnd = preEnd;

    buildTree( &((*proot)->left),  leftInStart, leftInEnd, leftPreStart, leftPreEnd );
    buildTree( &((*proot)->right), rightInStart, rightInEnd, rightPreStart, rightPreEnd );
}

//Please complete the function to finish the quiz.
//================================================================
int calcTreeHeight(const Node *root)
{
    if(root)
    {//.....
      int lh,rh;
      lh = calcTreeHeight(root->left) ;
      rh = calcTreeHeight(root->right);
      return std::max(lh,rh)+1;
    }
    return -1;
}
//================================================================

int main(void)
{
    std::string treeInStr, treePreStr;
    while( std::getline(std::cin, treeInStr) )
    {
        std::getline(std::cin, treePreStr);

        str2Array( treeIn, treeInStr );
        str2Array( treePre, treePreStr );

        Node *root = NULL;
        buildTree( &root, 0, treeIn.size(), 0, treePre.size() );
        std::cout << calcTreeHeight( root ) << std::endl;
        deleteTree( &root );
    }

    return 0;
}

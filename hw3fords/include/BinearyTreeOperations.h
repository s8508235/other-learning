//========================DO-NOT-MODIFY-THE-FILE========================

#ifndef BTO_H
#define BTO_H

#include <string>
#include <iostream>

class TreeNode
{
public:
    int weight;
    TreeNode *left, *right;
    TreeNode(int d):weight(d),left(NULL),right(NULL){}
};

class BinearyTreeOperations
{
public:
    //----------------------------------------------------------------------
    // return your student ID
    //----------------------------------------------------------------------
    virtual const char* getStudentID()const;

    //----------------------------------------------------------------------
    //input a tree string in S-expression, construct the tree.
    //----------------------------------------------------------------------
    virtual void constructTree(TreeNode **proot, std::string treeStr)const;

    //----------------------------------------------------------------------
    //release and delete the tree
    //----------------------------------------------------------------------
    virtual void deleteTree(TreeNode **proot)const;

    //----------------------------------------------------------------------
    //calc the height of the tree
    //----------------------------------------------------------------------
    virtual int treeHeight(const TreeNode *root)const;

    //----------------------------------------------------------------------
    //calc the sum of the weight
    //----------------------------------------------------------------------
    virtual int treeWeight(const TreeNode *root)const;

    //----------------------------------------------------------------------
    //calc the number of leaf nodes
    //----------------------------------------------------------------------
    virtual int leafNum(const TreeNode *root)const;

    //----------------------------------------------------------------------
    //calc the max path weight from root to leaf.
    //----------------------------------------------------------------------
    virtual int maxPathWeight(const TreeNode *root)const;
};

#endif

//========================DO-NOT-MODIFY-THE-FILE========================

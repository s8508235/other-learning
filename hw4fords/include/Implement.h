#ifndef IMPLEMENT_H
#define IMPLEMENT_H

#include "GraphOperations.h"

class Implement : public GraphOperations
{
public:

    //----------------------------------------------------------------------
    // return your student ID
    //----------------------------------------------------------------------
    virtual const char* getStudentID();
    //----------------------------------------------------------------------
    //add an edge between the vertex_1 and the vertex_2
    //----------------------------------------------------------------------
    virtual void addEdge(const int label_1, const int label_2);

    //----------------------------------------------------------------------
    //delete an edge between the vertex_1 and the vertex_2
    //----------------------------------------------------------------------
    virtual void deleteEdge(const int label_1, const int label_2);

    //----------------------------------------------------------------------
    //delete the vertex of the graph
    //----------------------------------------------------------------------
    virtual void deleteVertex(const int label);

    //----------------------------------------------------------------------
    //calc the degree of the vertex
    //----------------------------------------------------------------------
    virtual int degree(const int label);

    //----------------------------------------------------------------------
    //check if it exists a path between the vertex_1 and the vertex_2
    //----------------------------------------------------------------------
    virtual bool isExistPath(const int label_1, const int label_2);
};


#endif

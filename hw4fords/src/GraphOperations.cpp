//========================DO-NOT-MODIFY-THE-FILE========================
#include "GraphOperations.h"
void GraphOperations::adjListAllocation(int n)
{
    this->adjacencyList = new AdjList[n];
    for(int i = 0; i < n; i++){
        this->adjacencyList[i].exist = false;
        this->adjacencyList[i].head = NULL;
    }
}

void GraphOperations::deleteGraph(int n)
{
    for(int i = 0; i < n; i++) {
        Vertex* cur;
        Vertex* cur_next;
        if(this->adjacencyList[i].exist == true) {
            cur = this->adjacencyList[i].head;
            while(cur != NULL) {
                cur_next = cur->next;
                delete cur;
                cur =  cur_next;
            }
            this->adjacencyList[i].exist = false;
            this->adjacencyList[i].head = NULL;
        }
    }
    delete[] (this->adjacencyList);
}

const char* GraphOperations::getStudentID()
{
	throw "getStudentID";
}

void GraphOperations::addEdge(const int lable_1, const int label_2)
{
    throw "addEdge";
}

void GraphOperations::deleteEdge(const int label_1, const int label_2)
{
    throw "deleteEdge";
}

void GraphOperations::deleteVertex(const int label)
{
    throw "deleteVertex";
}

int GraphOperations::degree(const int label)
{
    throw "degree";
}

bool GraphOperations::isExistPath(const int label_1, const int label_2)
{
    throw "isExistPath";
}
//========================DO-NOT-MODIFY-THE-FILE========================

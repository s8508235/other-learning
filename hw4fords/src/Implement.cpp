#include "Implement.h"
void store_path(int* path,Vertex *x,AdjList *adj,int label);
int path[101];
const char* Implement::getStudentID()
{
    return "103062210";
}
void Implement::addEdge(const int label_1, const int label_2)
{
    if(adjacencyList[label_1].exist)
    {
        if(adjacencyList[label_2].exist)
        {//std::cout<<"Both exist"<<std::endl;
            if(label_1 ==label_2) return ;
            Vertex *x;
            x = new Vertex;
            x = adjacencyList[label_1].head;
            while(x->next!=NULL)
            {
                if(x->label==label_2) {
                     //   std::cout<<"off"<<std::endl;
                        return ;
                }
                x = x->next;
            } if(x->label==label_2) {
                     //   std::cout<<"off"<<std::endl;
                        return ;
                }
            Vertex *v2;
            v2 = new Vertex;
            v2->label = label_2;
            v2->next = NULL;
            x->next = v2;

            Vertex *y;
            y = new Vertex;
            y = adjacencyList[label_2].head;
            while(y->next!=NULL)
            {
                y = y->next;
            }
            Vertex *v1;
            v1 = new Vertex;
            v1->label = label_1;
            v1->next = NULL;
            y->next =v1;
        }
        else
        {//std::cout<<"only 1 exists"<<std::endl;
            Vertex *v2;
            v2 = new Vertex;
            v2->label = label_2;
            Vertex *v1;
            v1 = new Vertex;
            v1->label = label_1;
            Vertex *v3;
            v3 = new Vertex;
            v3->label = label_2;
            v3->next = NULL;
            v2->next = v1;
            v2->next->next = NULL;
            adjacencyList[label_2].exist = true;
            adjacencyList[label_2].head  = v2;
            Vertex *x;
            x = new Vertex;
            x = adjacencyList[label_1].head;
            while(x->next!=NULL)
            {
                x = x->next;
            }
            x->next = v3;
        }
    }
    else
    {
        if(adjacencyList[label_2].exist)
        {//std::cout<<"only 2 exists"<<std::endl;
            Vertex *v2;
            v2 = new Vertex;
            v2->label = label_2;
            Vertex *v1;
            v1 = new Vertex;
            v1->label = label_1;
            Vertex *v3;
            v3 = new Vertex;
            v3->label = label_1;
            v3->next = NULL;
            v1->next = v2;
            v1->next->next = NULL;
            adjacencyList[label_1].exist = true;
            adjacencyList[label_1].head  = v1;
            Vertex *x;
            x = new Vertex;
            x = adjacencyList[label_2].head;
            while(x->next!=NULL)
            {
                x = x->next;
            }
            x->next = v3;
        }
        else//nope
        {//std::cout<<"NONE"<<std::endl;
            if(label_1==label_2) return ;
            Vertex *v1;
            v1 = new Vertex;
            v1->label = label_1;
            Vertex *v2;
            v2 = new Vertex;
            v2->label = label_2;
            Vertex *v3;
            v3 =new Vertex;
            v3->label = label_1;
            Vertex *v4;
            v4 = new Vertex;
            v4->label = label_2;
            v1->next = v4;
            v1->next ->next = NULL;
            v2->next = v3;
            v2->next->next = NULL;
            adjacencyList[label_1].exist = true;
            adjacencyList[label_2].exist = true;
            adjacencyList[label_1].head  = v1;
            adjacencyList[label_2].head  = v2;
        }
    }
    Vertex *v;
    v  = new Vertex;
    v = adjacencyList[label_1].head;
    std::cout<<label_1<<":";
    while(v!=NULL)
    {
        std::cout<<v->label<<" ";
        v = v->next;
    }std::cout<<std::endl;
    std::cout<<label_2<<":";
    v = adjacencyList[label_2].head;
    while(v!=NULL)
    {
        std::cout<<v->label<<" ";
        v = v->next;
    }std::cout<<std::endl;
}
void Implement::deleteEdge(const int label_1, const int label_2)
{
    if(adjacencyList[label_1].exist&&adjacencyList[label_2].exist)
    {
            Vertex *v1;
    v1 = new Vertex;
    v1 = adjacencyList[label_1].head;
    Vertex *v2;
    v2 = new Vertex;
    v2 = adjacencyList[label_2].head;
    Vertex *x;
    x = new Vertex;
    Vertex *temp;
    temp = new Vertex;
    temp = v1;
    x = v1;
    while(x!=NULL)
    {
        if(x->label==label_2) break;
        temp = x;
        x = x->next;
    }
    if(x==NULL)
    {
        return ;
    }
    else
    {
        temp->next = x->next;
    }
    x = v2;
    temp = v2;
    while(x!=NULL)
    {
        if(x->label==label_1) break;
        temp = x;
        x = x->next;
    }
    temp->next = x->next;/*
    Vertex *v;
    v  = new Vertex;
    v = adjacencyList[label_1].head;

    std::cout<<label_1<<":";
    while(v!=NULL)
    {
        std::cout<<v->label<<" ";
        v = v->next;
    }std::cout<<std::endl;
    std::cout<<label_2<<":";
    v = adjacencyList[label_2].head;
    while(v!=NULL)
    {
        std::cout<<v->label<<" ";
        v = v->next;
    }std::cout<<std::endl;
    std::cout<<"DE COM"<<std::endl;*/
    }
}
void Implement::deleteVertex(const int label)
{
    Vertex *bye;
    bye = new Vertex;
    bye = adjacencyList[label].head;
    Vertex *curr;
    curr = new Vertex;
    curr = bye->next;
    while(curr!=NULL)
    {
        deleteEdge(bye->label,curr->label);
        curr = curr->next;
    }
    //show
    adjacencyList[label].exist = false;
    adjacencyList[label].head = NULL;
   // std::cout<<"DV COM"<<std::endl;
}
int Implement::degree(const int label)
{
    Vertex *curr;
    curr = new Vertex;
    curr = adjacencyList[label].head->next;
    int ans = 0;
    while(curr!=NULL)
    {
        curr = curr->next;
        ans++;
    }
    return ans;
}
bool Implement::isExistPath(const int label_1, const int label_2)
{
    if(adjacencyList[label_1].exist &&adjacencyList[label_2].exist)
    {
        int i;
        for(i=0;i<=100;i++)
        {
            path[i]=0;
        }
        Vertex *curr;
        curr = new Vertex;
        curr = adjacencyList[label_1].head;
        store_path(path,curr,adjacencyList,label_2);
  //     std::cout<<"isexist:"<<path[label_2]<<std::endl;
        if(path[label_2]) return true;
        else return false;
    }
    else
    {
        return false;
    }
}
void store_path(int* path,Vertex *x,AdjList *adj,int flag)
{/*
    if(x!=NULL)
    std::cout<<x->label<<std::endl;
    else
    {
      //  std::cout<<"NULLLL"<<std::endl;
    }*/
    if(x!=NULL)
    {
        while(path[x->label])
        {
            x = x->next;
            if(x==NULL){
             //   std::cout<<"NULLLLLL"<<std::endl;
            break;
            }
            if(path[x->label]==0){
              //  std::cout<<"@@"<<std::endl;
                break;
            }/*
            if(x!=NULL)
            std::cout<<x->label<<std::endl;*/
        }
           // if(x==NULL) std::cout<<"@@"<<std::endl;
            if(x!=NULL)
            {
            path[x->label]=1;
            //std::cout<<"nt"<<std::endl;
            store_path(path,x->next,adj,flag);
           // std::cout<<"adj"<<std::endl;
            store_path(path,adj[x->label].head,adj,flag);
             //std::cout<<"zz"<<std::endl;
            }
    }
    else
    return ;
}

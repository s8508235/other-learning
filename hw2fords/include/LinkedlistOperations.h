//========================DO-NOT-MODIFY-THE-FILE========================

#ifndef HWCPP_ADT_H
#define HWCPP_ADT_H

#include "Node.h"
#include <string>

using namespace std;


//It contains the fucntions that you have to override in implement.h/.cpp.
class LinkedlistOperations
{
public:
    //----------------------------------------------------------------------
    // return your student ID
    // e.g. return "123456789"
    //----------------------------------------------------------------------
    virtual const char* getStudentID();

    //----------------------------------------------------------------------
    // Insert name at the end of the linked list.
	// e.g. original list (head) : "A -> B" => InsertBack(head, C) => "A -> B -> C"
    //----------------------------------------------------------------------
    virtual Node* InsertBack(Node *head, string name);

    //----------------------------------------------------------------------
    // Insert name2 after the first name1 in the linked list.
	// If the InsertAfter error happened , do nothing.
	// e.g. original list (head) : "A -> A" => InsertAfter(head, A, B) => "A -> B -> A"
	// e.g. original list (head) : "A -> A" => InsertAfter(head, C, B) => "A -> A"
    //----------------------------------------------------------------------
    virtual Node* InsertAfter(Node *head, string name1, string name2);

    //----------------------------------------------------------------------
    // Remove the first name from the linked list.
	// If the Delete error happened , do nothing.
	// e.g. original list (head) : "A -> B -> C" => Delete(head,B) => "A -> C"
	// e.g. original list (head) : "A -> B -> C" => Delete(head,Y) => "A -> B -> C"
    //----------------------------------------------------------------------
    virtual Node* Delete(Node *head, string name);

    //----------------------------------------------------------------------
    // Reverse the linked list.
	// e.g. original list (head) : "A -> B -> C" =>Reverse(head) => "C -> B -> A"
    //----------------------------------------------------------------------
    virtual Node* Reverse(Node *head);

};


#endif

//========================DO-NOT-MODIFY-THE-FILE========================

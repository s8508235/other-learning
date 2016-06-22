//========================DO-NOT-MODIFY-THE-FILE========================

#include "BasicTest.h"
#include <iostream>
#include <stdlib.h>
void show_node(Node *n);
void BasicTest( LinkedlistOperations & inst )
{
    try
    {
		Node *node=NULL;
		std::cout<<"------------------------\nbasic test "<<"\n";
		node=inst.InsertAfter(node,"Jonathon","Joseph");
		show_node(node);
		node=inst.Delete(node, "Joestar");
		show_node(node);
		node=inst.Delete(node, "Jotora");
		show_node(node);
		node=inst.InsertBack(node,"Jonathon");
		show_node(node);
		node=inst.InsertBack(node,"Jotora");
		show_node(node);
		node=inst.InsertBack(node,"Jonathoi");
		show_node(node);
		node=inst.InsertBack(node,"Jonathon");
		show_node(node);
		node=inst.Delete(node, "Joestar");
		show_node(node);
		node=inst.Delete(node, "Jonathoi");
		show_node(node);
		node=inst.InsertAfter(node,"Jonathon","Joseph");
		show_node(node);
		node=inst.InsertAfter(node,"Joseph","Mike");
		show_node(node);
		node=inst.InsertBack(node,"James");
		show_node(node);
		node=inst.Delete(node, "Jonathon");
		show_node(node);
		node=inst.Delete(node, "Mike");
		show_node(node);
		node=inst.Reverse(node);
		show_node(node);
		node=inst.Delete(node, "Jostar");
		show_node(node);
		node=inst.Delete(node, "Joseph");
		show_node(node);
		node=inst.Delete(node, "James");
		show_node(node);
		node=inst.Delete(node, "Jonathon");
		show_node(node);
		node=inst.Delete(node, "Jonathon");
		show_node(node);
		node=inst.InsertBack(node,"Jonathon");
		show_node(node);
		node=inst.Reverse(node);
		show_node(node);
		std::cout << "Done."<<"\n------------------------" << std::endl;
		bool isPass= (node->data=="John");

		free(node);
		node=NULL;

		std::cout << inst.getStudentID()<<std::endl;
		if( isPass )
			std::cout << "You passes the basic test.";
		else
			std::cout << "You fails the basic test.";
		std::cout << std::endl;
    }
    catch(const char* str)
    {
        std::cout << "The implementation is not done. : [" << str << "]" << std::endl;
    }
}
void show_node(Node *n)
{
    Node *curr;
    curr= new Node;
    curr = n;
    while(curr!=NULL)
    {
		std::cout<<curr->data<<" ";
		curr = curr->next;
    }
    std::cout<<"\n";
}
//========================DO-NOT-MODIFY-THE-FILE========================

#include<bits/stdc++.h>
using namespace std;
    // Following is the class structure of the Node class:
    //below functional code can be integrated with the driver function to solve the problem

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };


bool detectCycle(Node *head)
{
    if(head==NULL or head->next==NULL)
        return false;
	Node* sptr=head;
    Node* dptr=head;
    while(sptr and dptr){
        dptr=dptr->next;
        if(dptr)
            dptr=dptr->next;
        sptr=sptr->next;
        if(sptr==dptr)
            return true;
    }
    return false;
}

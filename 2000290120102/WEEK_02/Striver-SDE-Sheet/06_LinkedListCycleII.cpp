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


Node *firstNode(Node *head)
{
    if(head==NULL or head->next==NULL)
        return NULL;
	Node* ptr=head;
    Node* sptr=head;
    Node* dptr=head;
    while(dptr->next and dptr->next->next){
        sptr=sptr->next;     
        dptr=dptr->next->next;          
        if(sptr==dptr){
            while(sptr!=ptr){
                sptr=sptr->next;
                ptr=ptr->next;
            }
            return ptr;
        }
    }
    return NULL;
}
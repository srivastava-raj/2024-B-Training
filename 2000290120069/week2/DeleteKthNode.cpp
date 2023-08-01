#include<bits/stdc++.h>
using namespace std;
// Following is the class structure of the Node class:
//Below code involves the functional implementation of the problem
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


Node* removeKthNode(Node* head, int k)
{
    Node* ptr=head;
    Node* ptr1=head;
    int c=0;
    while(ptr){
        c++;
        ptr=ptr->next;
    }
    int l=c-k,p=0;
    if(l==0){
        return head->next;
    }
    while(ptr1){
        p++;
        if(p==l)
            ptr1->next=ptr1->next->next;
        ptr1=ptr1->next;
    }
    return head;
}

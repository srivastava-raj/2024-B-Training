#include<iostream>
using namespace std;

class Node{
    public:

    int data;
    Node* next;

    Node(int d)
    {
        this->data=d;
        this->next=NULL;

    }
    ~Node()
    {
        if(this->next!=NULL)
        {
            
            delete next;
            this->next=NULL;
        }
    }
};


void insertNode(Node* &tail,int element,int d)
{
    if(tail==NULL)
    {
        Node * newnode =new Node(d);
        tail=newnode;
        newnode->next=newnode;
    }
    else
    {
        Node* current=tail;
        while(current->data!=element)
        {
            current=current->next;
        }
        Node* temp=new Node(d);
        temp->next=current;
        current->next=temp;
    }
}


void print(Node* &tail)
{
    Node* temp=tail;
    do
    {
        cout<<tail->data<<" ";
        tail=tail->next;
    }
    while(tail!=temp);
}



int main()
{
   Node * tail=NULL;

   insertNode(tail,5,3);
   print(tail);
   insertNode(tail,3,5);
   print(tail);
   insertNode(tail,5,7);
   print(tail);
   return 0;
}
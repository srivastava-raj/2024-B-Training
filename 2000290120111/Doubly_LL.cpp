#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node* prev;

    //Constructor
    Node(int d)
    {
        this->data=d;
        this->next=NULL;
        this->prev=NULL;
    }
};


void insertAtBig(Node* &head,Node* &tail,int d)
{
    if(head==NULL)
    {
        Node* temp=new Node(d);
        head=temp;
        tail=temp;
    }
    else{
    Node* temp=new Node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;
    }
}


void insertAtTail(Node* &head,Node* &tail,int d)
{
    if(tail==NULL)
    {
        Node * temp=new Node(d);
        head=temp;
        tail=temp;
    }
    else{
    Node* temp=new Node(d);

    tail->next=temp;
    temp->prev=tail;
    tail=temp;
    }
    
}


void insertAtPosition(Node* &tail,Node* &head,int position,int d)
{
    if(position==1)
    {
        insertAtBig(head,tail,d);
        return;

    }
    Node* temp=head;
    int count=1;
    while(count<position-1)
    {
        temp=temp->next;
        count++;
    }
    if(temp==NULL)
    {
        insertAtTail(head,tail,d);
        return;
    }

    Node* node1=new Node(d);
    node1->next=temp->next;
    temp->next->prev=node1;
    temp->next=node1;
    node1->prev=temp;

    
}

//Deletion

void deleteAtPosition(Node* &head,Node* &tail,int position)
{
    if(position==1)
    {
    Node* temp=head;
    temp->next->prev=NULL;
    head=temp->next;
    temp->next=NULL;
    delete temp;
    }
    else
    {
    int count=1;
    Node* current =head;
    Node * previous = NULL;
    while(count<position)
    {
      previous=current;
      current =current ->next;
      count++;
    }
    // if(current->next=NULL)
    // {
    //     tail=previous;
    //     current->prev=NULL;
    //     previous->next=NULL;
    //     delete current;

    // }

    current->prev=NULL;
    previous->next=current->next;
    //current->next->prev=previous;
    current->next=NULL;
    delete current;
    }
}





void print(Node* &head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}





int main()
{
    Node* head=NULL;
    Node* tail=NULL;
    insertAtBig(head,tail,5);
    print(head);
    cout<<endl;
    insertAtTail(head,tail,7);
    print(head);
    cout<<endl;
    insertAtPosition(tail,head,4,98);
    print(head);
    cout<<endl;
    deleteAtPosition(head,tail,2);
    print(head);
    cout<<endl;
    cout<<head->data<<endl;
    cout<<tail->data<<endl;
    return 0;
}
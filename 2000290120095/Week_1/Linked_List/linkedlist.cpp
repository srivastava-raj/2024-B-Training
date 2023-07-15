#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};

void insertAtTail(node* &head,int val)
{
    node* n=new node(val);
    if(head == NULL)
    {
    head=n;
    return;
    }
    node *temp=head;
    while(temp->next!=NULL)
    temp=temp->next;
    temp->next=n;

}

void insertAtHead(node* &head,int val)
{
    node* n=new node(val);
    n->next=head;
    head=n;
}

void display(node* head){
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data;
        cout<<"->";
        temp=temp->next;

    }
    cout<<"NULL";
}

node* reverse(node* &head){
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;
    while(currptr!=NULL)
    {
        nextptr=currptr->next;
        currptr->next = prevptr;
        prevptr= currptr;
        currptr=nextptr;
    }
    return prevptr;
}


int main()
{

    node* head=NULL;
    insertAtTail(head,10);
    insertAtTail(head,20);
    insertAtTail(head,30);
    insertAtTail(head,40);
    insertAtTail(head,50);
    insertAtTail(head,60);
    insertAtHead(head,5);

    display(head);
    node* revhead = reverse(head);
    cout<<endl;
    display(revhead);

}
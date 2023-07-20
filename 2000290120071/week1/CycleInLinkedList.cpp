#include<iostream>
using namespace std;

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

void makeCycle(node* head)
{
    node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=head->next->next;
}

bool detectCycle(node *head)
{
    node* slow = head;
    node* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow)
        return true;
    }
    return false;
}

void removeCycle(node* head)
{
    node* slow=head;
    node* fast=head;
    do{
        slow=slow->next;
        fast=fast->next->next;
    }while(slow!=fast);
    fast=head;
    while(slow->next!=fast->next){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=NULL;


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
    cout<<detectCycle(head);
    makeCycle(head);
    cout<<detectCycle(head);
    removeCycle(head);
    cout<<detectCycle(head);
    // display(head);
}

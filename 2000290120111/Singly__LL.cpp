#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node * next;
    //Constructor
    Node(int data)
    {
        this->data=data;
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



void insertAtBig(Node * &head, int d)
{
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;
}



void insertAtTail(Node * &tail,int d)
{
    Node* temp=new Node(d);
   tail->next=temp;
   tail=temp;
}



void insertAtMid(Node* &tail,Node* &head,int position,int d)
{
     if(position==1)
    {
        insertAtBig(head,d);
        return;
    }
    
    Node* temp=head;
    int count=1;
    while(count<position-1)
    {
        temp=temp->next;
        count++;
    }
   
    if(temp->next==NULL)
    {
        insertAtTail(tail,d);
        return;
    }
    Node * newnode1=new Node(d);
    newnode1->next=temp->next;
    temp->next=newnode1;

}


void deletenode(Node* &head,int position)
{
    if(position==1)
    {
        Node * temp=head;
        head=head->next;
        //free up the memory of position we deleted.
        temp->next=NULL;
        delete temp;
    }
    else
    {
        Node * prev=NULL;
        Node * current=head;
        int count=1;
        while(count<position)
        {
           prev=current;
           current=current->next;
           count++; 
        }
       /* if(current->next=NULL)
        {
            tail->next=prev->next;
            prev->next=current->next;
        }
        */
         prev->next=current->next;
    //free up the memory of postion we deleted.
    current->next=NULL;
    delete current->next;  
    }
}



void print(Node* &head)
{
    Node * temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

int main()
{

Node * node1=new Node(10);
Node * head=node1;
Node * tail=node1;

insertAtBig(head,8);
print(head);
insertAtBig(head,32);

insertAtTail(tail,21);
insertAtTail(tail,37);
insertAtTail(tail,71);

insertAtTail(tail,97);
print(head);
insertAtMid(tail,head,1,25);
cout<<endl;
print(head);
cout<<endl;
cout<<head->data<<endl;
cout<<tail->data<<endl;
deletenode(head,2);
cout<<endl;
deletenode(head,7);
print(head);
return 0;
}
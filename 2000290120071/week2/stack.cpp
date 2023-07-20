#include<iostream>
#include<string.h>
using namespace std;

struct node{
    int roll_no;
    string name;
    int percentage;
    node* next;
    node(int roll ,string _name,int per )
    {
        roll_no=roll;
        name=_name;
        percentage=per;
        next=NULL;
    }

};

void InsertAtTail(node* &head,int roll,string _name,int per)
{
    node* n=new node(roll,_name,per);
    if(head==NULL)
    {
        head=n;
        return;
    }
    node* temp = head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
}

void display(node* head)
{
    node* temp=head;
    while(temp!=NULL)
    {
     
        cout<<"Roll no: "<<temp->roll_no<<endl;
        cout<<"Name: "<<temp->name<<endl;
        cout<<"Percentage: "<<temp->percentage<<endl;
        cout<<"   |"<<endl;
        cout<<"   *"<<endl;

        temp=temp->next;
    }
    cout<<"NULL";
}

void max_min(node* head)
{
    node* temp=head;
    node* tempmax=head;
    node* tempmin=head;
    while(temp!=NULL)
    {
        if(temp->percentage>tempmax->percentage)
        tempmax=temp;
        if(temp->percentage<tempmin->percentage)
        tempmin=temp;

        temp=temp->next;
    }
    cout<<"\n---->Student who has scored maximum percentage is: \n";
    cout<<"Roll no. : "<<tempmax->roll_no<<endl;
    cout<<"Name : "<<tempmax->name<<endl;
    cout<<"Percentage: "<<tempmax->percentage<<endl;

    cout<<"\n---->Student who has scored minimum percentage is: \n";
    cout<<"Roll no. : "<<tempmin->roll_no<<endl;
    cout<<"Name : "<<tempmin->name<<endl;
    cout<<"Percentage: "<<tempmin->percentage<<endl;
}

int main()
{
    node* head=NULL;
    cout<<"Enter the details of five students: "<<endl<<endl;
    for(int i=0;i<5;i++)
    {
        int roll,per;
        string name;
        cout<<"Enter the detail of "<<i+1<<" student-->"<<endl;
        cout<<"Roll no. :";
        cin>>roll;
        cout<<"Name: ";
        cin>>name;
        cout<<"Percentage: ";
        cin>>per;
        InsertAtTail(head,roll,name,per);
        cout<<endl;

    }
    cout<<"--------->Details of the students are as follows <--------"<<endl;
    cout<<endl;
    display(head);
    max_min(head);

}

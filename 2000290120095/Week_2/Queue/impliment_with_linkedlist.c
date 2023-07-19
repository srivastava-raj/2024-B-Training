#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
}*front=NULL,*rear=NULL;

void enqueue()
{
    int item;
    struct node*temp,*p=rear;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value to enter : ");
    scanf("%d",&item);
    
    if(rear==NULL)   //if queue is empty
    {
        front=rear=temp;
        temp->data=item;
        temp->link=NULL;
    }
    else{
        p->link=temp;
        temp->data=item;
        temp->link=NULL;
        rear=temp;
    }
}

void dequeue()
{
    if(front==NULL)
    {
        printf("Queue is empty !");
    }
    else if(front!=NULL && front==rear)
    {
        front=rear=NULL;
    }
    else
    {
        front=front->link;
    }
}

void display()
{
    if(front==NULL)
    {
        printf("Queue is empty \n");
    }
    else{
    struct node*p=front;
    printf("Queue is : \n");
    while (p!=NULL)
    {
       printf("%d\n",p->data);
       p=p->link; 
    }
    }
}
int main()
{
    int choice;
        printf("1. Insert \n");
        printf("2. Delete \n");
        printf("3. Display all values \n");
        printf("4. Exit \n");
    while(1)
    {
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        
        default:
            break;
        }
        
    }
}
#include<stdio.h>
#include<stdlib.h>
#define max 10

int queue[max];
int front=-1;
int rear=-1;

void enqueue()
{
    int item;
    printf("Enter the value to enter : ");
    scanf("%d",&item);
    if(rear==max-1)
    {
        printf("Queue is full \n ");
    }
    else if(rear==-1)
    {
        rear++;
        front++;
        queue[rear]=item;
    }
    else
    {
        queue[++rear]=item;
    }


}

void dequeue()
{
    if(front==-1 || front==rear+1)
    {
        printf("Queue is empty already  \n");
    }
    else
    {
        front++;
    }
}

void display()
{
    if(front==-1 || front==rear+1)
    {
        printf("Queue is empty  \n");
    }
    else{
        printf("Our queue is :\n");
    for(int i=front;i<=rear;i++)
    {
        printf("%d\n",queue[i]);
    }
    }
}
int main()
{
    int choice;
    while (1)
    {
        printf("1. Insert \n");
        printf("2. Delete \n");
        printf("3. traverse all data  \n");
        printf("4. exit \n");
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
        case 4: exit(1);
        
        default:
            break;
        }


    }
return 0;    
}
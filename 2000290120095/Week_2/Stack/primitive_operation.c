
#include<stdio.h>
#include<stdlib.h>

struct node {
     int data;
     struct node *next;


};

struct node *push(struct node* top,int info)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    if(top==NULL)
    {

    //here head of linked list is treated as top
        top=temp;
        temp->data=info;
        temp->next=NULL;
        return top;
    }
    
    temp->data=info;
    temp->next=top;
    top=temp;
     return top; 
    
}

struct node *pop(struct node* top)
{
    if(top==NULL)
    {
     printf("Stack is Empty\n");   
     return 0;
    }
    
    struct node* temp;
    temp=top;
    printf("Value pop out is %d",temp->data);
    printf("\n");
    top=temp->next;
    return top;

    
}

int main()
{
    struct node *top=NULL;
    int c,info;
    while(c!=0)
    {
        printf("Enter your choice :\n");
        printf("press 1 --> push\n");
         printf("press 2 --> pop\n");
          printf("press 0 --> exit\n");
        scanf("%d",&c);
        if(c==1)
        {
            printf("Enter the value \n");
            scanf("%d",&info);
            top=push(top,info);
        }
        if(c==2)
        {
            top=pop(top);
        }
        if(c==0)
        {
            exit(0);
        }
    }

}
// Doubly linked list Primitive operations
// Md faizal
// Roll no: (27)2000290120095
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int value;
    struct node* next;
    struct node* prev;

};

struct node *insertion(struct node *head)
{
    struct node *tmp;
    tmp=(struct node*)malloc(sizeof(struct node));
    
    int item;
    printf("Enter the value of node : ");
    scanf("%d",&item);
   if(head==NULL)
   {
       head=tmp;
       tmp->value=item;
       tmp->next=NULL;
       tmp->prev=NULL;
   } 
   else
   {
   struct node *p=head;
   while(p->next!=NULL)
   {
       p=p->next;
   }
   p->next=tmp;
   tmp->value=item;
   tmp->next=NULL;
   tmp->prev=p;
   }
   return head;
}

void delete(struct node *head)
{
    struct node *p,*tmp;
    p=head;
    while (p->next!=NULL)
    {
        p=p->next;
    }
    tmp= p->prev;
    tmp->next=NULL;

}

void traverse_f(struct node *head)
{
    struct node *tmp=head;
    do
    {
        printf("%d \n",tmp->value);
        tmp=tmp->next;
    }
    while(tmp->next!=NULL);
    printf("%d\n",tmp->value);

}

void traverse_b(struct node *head)
{
    struct node *tmp=head;
    while(tmp->next!=NULL)
    {
        tmp=tmp->next;
    }
    do
    {
        printf("%d\n",tmp->value);
        tmp=tmp->prev;
    }
    while (tmp->prev!=NULL);
    printf("%d\n",tmp->value);
    

}

int main()
{
    int choice;
    struct node *head;
    head=NULL;
    printf("Press 1 for insertion of a node \n");
    printf("Press 2 for delete a node\n");
    printf("Press 3 for traverase farward all node \n");
    printf("press 4 for traverse backward all nodes \n");
    printf("Press 0 for to exit \n");
    while(choice!=0)
    {
    printf("Enter your choice :\n");
    scanf("%d",&choice);
        switch (choice)
        {
        case 1:
        head=insertion(head);
            break;
        case 2:
        delete(head);
            break;
        case 3:
        traverse_f(head);
            break;
        case 4:
        traverse_b(head);
            break;
        }
    }
    return 0;
}
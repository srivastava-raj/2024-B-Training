#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *create_list(struct node *start)
{
    int data;
    printf("Enter the data of node\n");
    scanf("%d",&data);
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    if(start==NULL)
    {
       temp->link=NULL;
       temp->info=data;
       start=temp;
       return start;
    }
    else{
        struct node *p;
        p=start;
        while(p->link!=NULL)
        {
            p=p->link;
        }
        p->link=temp;
        temp->info=data;
        temp->link=NULL;
        return start;
    }

}

struct node *traverse_list(struct node *start)
{
    struct node *temp;
    temp=start;
    while(temp!=NULL)
    {
        printf("Data is :%d\n",temp->info);
        temp=temp->link;
    }
}

int main()
{
    int choice;
    struct node *start=NULL;
    printf("Enter your choice press 0 to exit \n");
    printf("Press 1 for add new node \n");
    printf("Press 2 for to traverse to all node \n");
    while(choice!=0)
    {
        printf("\t");
    scanf("%d",&choice);
    if(choice==1)
    {
    start=create_list(start);   
    }
    if(choice==2)
    {
    traverse_list(start);
    }
    }
 
}

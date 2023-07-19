//primitive opertion on a circular linked list
//Md faizal
//Roll no-(27)-2000290120095

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *next;


};

struct node *insertion(struct node *head)
{
    struct node *tmp;
    int item;
    printf("Enter the value of node : ");
    scanf("%d",&item);
    tmp=(struct node*)malloc(sizeof(struct node));

    if(head==NULL)
    {
        tmp->info=item;
        head=tmp;
        tmp->next=head;
    }
    else{
        struct node *p=head;
        while(p->next!=head)
        {
            p=p->next;
        }
        p->next=tmp;
        tmp->info=item;
        tmp->next=head;
    }
    return head;
}

void delete(struct node *head)
{
    if(head==NULL)
    printf("list is empty \n");

    struct node *p=head;
    while(p->next!=head)
    {
        p=p->next;
    }
    p->next=head;

}


void traverse(struct node *head)
{
    struct node *tmp=head;
    int i=1;
    do
    {
        printf("Value of %d node is : %d\n",i,tmp->info);
        i++;
        tmp=tmp->next;
    }
    while(tmp->next!=head);
}



int main()
{
    int choice;
    struct node *head;
    head=NULL;
    printf("Press 1 for insertion of a node \n");
    printf("Press 2 for delete a node\n");
    printf("Press 3 for traverase all node \n");
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
        traverse(head);
            break;

        }
    }
}
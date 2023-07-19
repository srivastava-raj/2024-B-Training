#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node {
     int data;
     struct node *next;
};


struct node *top=NULL;
struct node *push(int info)
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

void traversal(struct node *top)
{
    struct node *p=top;
    while(p!=NULL)
    {
        printf("%c \t",p->data);
        p=p->next;
    }
    printf("\n");
}

struct node* pop()
{
    if(top==NULL)
    {
     printf("Stack is Empty\n");   
     return 0;
    }
    struct node* temp;
    temp=top;
    top=temp->next;
    return top;
}

int priority (char symbol)
{
    switch (symbol)
    {
    case '(':
        return 0;
        break;
    case '+':
    case '-':
        return 1;
        break;
    case '*':
    case '/':
    case '%':
        return 2;
        
    default:
        break;
    }
}


int main()
{
    char input[50],output[50];
    int j=0;
    printf("Enter the infix expression : ");
    gets(input);
    for(int i=0;i<strlen(input);i++)
    {
        if(input[i]=='('|| input[i]=='*'|| input[i]=='/'|| input[i]=='+'|| input[i]=='-' || input[i]==')')
        {
            if(top==NULL)
            {
                top=push(input[i]);
            }

            else if(priority(input[i])<=priority(top->data))
            {
                while(priority(input[i])>priority(top->data))
                {
                    output[j++]=top->data;
                    top=pop(top);
                }
                    top=push(input[i]);

            }

            else if(input[i]==')')
            {
                while(top->data!='(')
                {

                output[j++]=top->data;
                    top=pop(top);
                }

                 top=pop(top);
            }

            else
            {
                top=push(input[i]);
            }
        }
        else{
            output[j++]=input[i];
        }    
        traversal(top);
    }
    for(int i=0;i<j;i++)
    {
        printf("%c \t",output[i]);
    }
       
    
return 0;
}
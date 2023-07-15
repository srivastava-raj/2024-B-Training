#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char stack[20];
int top=-1;

void push(char a)
{
   if(top==20)
   {
       printf("Stack overflow \n");
       exit(0);
   }

    stack[++top]=a;
    
}

void pop()
{
    top--;
}


int main()
{
    char str[50];
    printf("Enter the Parenthesized Arithmetic Expression ");
    scanf("%s",str);
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]=='(')
        {
        push(str[i]);
        }
        if(str[i]==')')
        {
        pop();
        }
        else
        {
            continue;
        }
    }
    
    if(top==-1)
    {
        printf("It is valid mathematical expression ");
    }
    else if(top<=-1)
    {
        printf("INVALID expression \n");
        printf(" left parenthesis is more than right");
    }
     else if(top>=-1)
    {
        printf("INVALID expression \n");
        printf(" right parenthesis is more than left");
    }

    return 0;
}
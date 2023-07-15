//Reverse of string using stack(help of array)


#include<stdio.h>
#include<string.h>
char stack[20];
 int top=-1;

void push(char a)
{

    stack[++top]=a;

}
char pop()
{
    return stack[top--];
}
int main()
{
    char str[20],stack[20];
    printf("Enter the string :");
    gets(str);
    for(int i=0;i<strlen(str);i++)
    {
       push(str[i]);
    }
    for(int i=0;i<strlen(str);i++)
    {
        str[i]=pop();
    }
    printf("Reverse string is :");
    puts(str);

    

return 0;
}
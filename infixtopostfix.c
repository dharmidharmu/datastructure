#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <ctype.h>#include <ctype.h>
#define SIZE 40
char pop();
void push(char);
int pre(char ch);
int stack[SIZE];
int top=-1;
void push(char ch)
{
    stack[++top]=ch;
}
char pop()
{
    return stack[top--];
}
int pre(char ch)
{
    switch(ch)
    {
        case '#': return 0;
    case '(':
        return 1;
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 3;
    case '^':
        return 4;
    }
}

void main()
{
    char infix[20],postfix[20];
    int i=0,j=0;
    char ch,elem;
    printf("enter the infix expresssion\n");
    scanf("%s",infix);
    push('#');
    while((ch=infix[i++])!='\0')
    {
        if(ch=='(')
        {
            push(ch);
        }
        else if(ch==')')
        {
            while(stack[top]!='(')
            postfix[j++]=pop();
            elem=pop();
        }
        else if(isalnum(ch))
            push(ch);
        else
        {
            while(pre(stack[top])>=pre(ch))
               postfix[j++]=pop();
               push(ch);
        }

    }
        while( stack[top] != '#')
  postfix[j++]=pop();
    postfix[j]='\0';
    printf("the postfix expression is %s",postfix);
}

#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>

 struct node
{
    char ch;
    struct node *prev;
    struct node *next;
};
typedef struct node node;

node *stack[11];
int top=10;
void push(node *ele)
{
    if(top<=0)
    {
        printf("stack is full\n");

    }
    else
    stack[top]=ele;
    top--;
}
node *pop()
{
    if(top>=10)
    {
        printf("stack is empty\n");

    }
    else
    return stack[++top];
}
void display(node *ele)
{
    if(ele!=NULL)
    {


        display(ele->prev);
    printf("%c",ele->ch);
    display(ele->next);
    }

}
void convert(char exp[])
{
   node *op1,  *op2;
	node *temp;
	int i;
	for (i=0;exp[i]!='\0';i++)
	if (exp[i] >= 'a'&& exp[i] <= 'z'|| exp[i] >= 'A' && exp[i] <= 'Z')
	{
		temp = (node*)malloc(sizeof(node));
		temp->ch = exp[i];
		temp->next = NULL;
		temp->prev = NULL;
		push(temp);
	}
	else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' ||
exp[i] == '^')
	{
		op1 = pop();
		op2 = pop();
		temp = (node*)malloc(sizeof(node));
		temp->ch = exp[i];
		temp->next = op1;
		temp->prev = op2;
		push(temp);
	}

}
void main()
{
	char exp[50];

	printf("Enter the postfix expression :\n");
	scanf("%s", exp);
	convert(exp);
	printf("The Equivalent Infix expression is:\n");
	display(pop());


}

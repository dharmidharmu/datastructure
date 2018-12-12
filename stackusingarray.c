#include<stdio.h>

#include<conio.h>

#define size 5

int stack[size];

int top;

void push()

{

	int n;

	printf("\n Enter item in stack");

	scanf("%d",&n);

	if(top==size-1)

	{

		printf("\nStack is Full");

	}

	else

	{

		top=top+1;

		stack[top]=n;

	}

}

void pop()

{

	int item;

	if(top==-1)

	{

		printf("\n Stack is empty");

	}

	else

	{

		item=stack[top];

		printf("\n item popped is=%d", item);

		top--;

	}

}

void display()

{

	int i;

	printf("\n item in stack are");

	for(i=top; i>=0; i--)

	printf("\n %d", stack[i]);

}

void main()

{

	char ch,ch1;

	ch ='y';

	ch1='y';

	top=-1;



	while(ch!='n')

	{

		push();

		printf("\n Do you want to push any item in stack y/n");

		ch=getch();

	}

	display();

	while(ch1!='n')

	{

		printf("\n Do you want to delete  any item in stack y/n");

		ch1=getch();

		pop();

	}

	display();



}


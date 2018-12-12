#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
    int no;
    struct node *next;

};
struct node *top;
void push();
void pop();
void display();
void push()
{
    struct node *new=(struct node*)malloc(sizeof(struct node));
    printf("enter the item to insert \n");
    scanf("%d",&new->no);
    new->next=NULL;
    if(top==NULL)
    {
        top=new;
    }
     else{

        new->next=top;
    top=new;
     }


}
void pop()
{
    if(top==NULL)
    {
    printf("Stack is empty\n");
    return;
    }
    struct node* ptr;
    ptr=top;
    printf("the element popped is %d",ptr->no);
    top=top->next;
    free(ptr);

}
void display()
{
    struct node *ptr;
    if(top==NULL)
    {
        printf("no elements to display\n");
        return;
    }
    printf("the elements are\n");
    for(ptr=top;ptr!=NULL;ptr=ptr->next)
    {
        printf("%d\n",ptr->no);
    }

}
void main()
{
    int n;
   top=NULL;
   while(1)
   {
   printf("enter your option\n");
   printf("push  1\n");
   printf("pop 2\n");
   printf("display 3\n");
   scanf("%d",&n);
   switch(n)
   {
   case 1:
    push();
    break;
   case 2:
    pop();
    break;
   case 3:
    display();
    break;
   default:
    printf("enter valid choice\n");
   }
   }

}

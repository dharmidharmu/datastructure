#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int no;
    struct node* next;
    struct node* prev;
};
struct node*top;
struct node*tail;
void insertion(int x);
void deletion();
void display();
void insertion(int x)
{

    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->no=x;
     temp->next=NULL;
    if(tail==NULL)
    {

     temp->prev=NULL;
      tail=temp;
      top=temp;
    }

   else
   {
        temp->prev=tail;
        tail->next=temp;
    tail=temp;

   }

}
void deletion()
{
    if(top==NULL)
    {
        printf("there is no element in the queue\n");
    }
    printf("the deleted element is %d\n",top->no);
    top=top->next;
    top->prev=NULL;

}
void display()
{
    struct node *p;
    p=top;
    printf("the elements are\n");
    while(p!=NULL)
    {
        printf("%d\n",p->no);
        p=p->next;
    }
}
void main()
{
    int a;
    top=tail=NULL;
    while(1)
    {


    printf("enter your choice\n1.insertion press 1\n2.remove press 2\n3.display\n4.exit\n");
    scanf("%d",&a);
    switch(a)
    {
    case 1:
    {


        int item;
        printf("enter the item to insert into the queue\n");
        scanf("%d",&item);
        insertion(item);
    }
        break;
    case 2:
        deletion();
        break;
    case 3:
        display();
        break;
    case 4:
        printf("Thank you\n");
        break;
    default:
        printf("please select valid option\n");
    }
    }

}

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int no;
    struct node *next;
};
struct node *head;
void createlist(int);
void display();
void insertbegin();
void insertend();
void insertloc();
void deletebegin();
void deleteend();
void deleteloc();
void search();
void sort();

void createlist(int a)
{
    for(int i=0;i<a;i++)
    {
        struct node *ptr;

        struct node *new=(struct node*)malloc(sizeof(struct node));
        printf("enter the item %d\n",i+1);
        scanf("%d",&new->no);

        if(head==NULL)
        {
            head=new;
            new->next=head;
        }
        else{

            for(ptr=head;ptr->next!=head;ptr=ptr->next);
            new->next=ptr->next;
            ptr->next=new;



        }

        }

    }
    void display()
    {
        struct node* ptr;
         printf("the elements are \n");
         ptr=head;
         do
         {
            printf("%d\n",ptr->no);
            ptr=ptr->next;
         }while(ptr!=head);


    }
    void insertbegin()
    {
        struct node *ptr;
        struct node* new=(struct node*)malloc(sizeof(struct node*));
        printf("enter the data of the item\n");
        scanf("%d",&new->no);
        for(ptr=head;ptr->next!=head;ptr=ptr->next);
        new->next=ptr->next;
        ptr->next=new;
        head=new;


    }
    void insertend()
    {
        struct node *new=(struct node*)malloc(sizeof(struct node));
        struct node *ptr;
        printf("enter the data of the item\n");
        scanf("%d",&new->no);

            for(ptr=head;ptr->next!=NULL;ptr=ptr->next);
            ptr->next=new;
             new->next=NULL;

    }
    void insertloc()
    {
        int n;
        printf("enter the location to insert the data\n");
        scanf("%d",&n);
        struct node *new=(struct node*)malloc(sizeof(struct node));
         printf("enter the data of the item\n");
        scanf("%d",&new->no);


        struct node*ptr;
        int i;
        for(i=1,ptr=head;i<n-1;i++)
        {
            ptr=ptr->next;
            if(ptr->next==head)
            {
                printf("please enter valid location\n");

                break;
            }

        }
        new->next=ptr->next;
            ptr->next=new;



    }
    void deletebegin()
    {
       struct node* ptr,*p;
       p=head;
        for(ptr=head;ptr->next!=head;ptr=ptr->next);
       p=ptr->next;
       ptr->next=head->next;
       head=head->next;
       free(p);


    }
    void deleteend()
    {
        struct node *ptr,*p;
        for(ptr=head;ptr->next->next!=head;ptr=ptr->next);
        p=ptr->next;
        ptr->next=ptr->next->next;
        free(p);


    }
    void deleteloc()
    {
        int n;
        struct node *ptr;
        struct node *p;
        printf("enter the location to delete\n");
        scanf("%d",&n);
        int i;
        for(i=1,ptr=head;i<n-1;i++)
        {
            ptr=ptr->next;
            if(ptr->next==head)
            {



                 printf("please enter valid location\n");

                break;
            }
        }
        p=ptr->next;
        ptr->next=ptr->next->next;
        free(p);



    }
    void search()
    {
        int n;
        printf("enter the value to search\n");
        scanf("%d",&n);
        struct node *p;
        int i;
        for(p=head,i=1;p->next!=head;p=p->next,i++)
        {
            if(p->no==n)
            {
                printf("the element %d is present in the location %d\n",n,i);
                return;
            }
        }
        printf("the element %d is not present in the list\n");

    }
    void sort()
    {
        struct node *ptr1,*ptr2;
         int temp;

        for(ptr1=head;ptr1->next!=head;ptr1=ptr1->next)
            {


            for(ptr2=ptr1->next;ptr2!=head;ptr2=ptr2->next)
        {
            if(ptr1->no>ptr2->no)
            {


        temp=ptr1->no;
        ptr1->no=ptr2->no;
        ptr2->no=temp;
            }
        }

            }
    }
    void main()
{
    head=NULL;
    int n;
    printf("enter no. of elements do you want to insert in linked list\n");
    scanf("%d",&n);
    createlist(n);
    while(1)
    {



    printf("choose here\n");
    printf("insertion press 1\n");
    printf("deletion press 2\n");
    printf("display press 3\n");
    printf("search press 4\n");
    printf("sort press 5\n");
    int ch;
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:







printf("at begin press 4\n");
        printf("at end press 5\n");
        printf("at location press 6\n");

         int ca;
        scanf("%d",&ca);
        switch(ca)
        {
            case 4:

                insertbegin();
            break;

            case 5:



            insertend();
                break;

            case 6:



                 insertloc();
                break;

            default:
                printf("enter correct letter\n");
                break;
        }
        break;


            case 2:
                printf("at begin press 4\n");
        printf("at end press 5\n");
        printf("at location press 6\n");

         int fa;
        scanf("%d",&fa);
        switch(fa)
        {
            case 4:

                deletebegin();
            break;

            case 5:



            deleteend();
                break;

            case 6:



                 deleteloc();
                break;

            default:
                printf("enter correct letter\n");
                break;
        }
                break;
            case 3:
                display();
                break;
            case 4:
                search();
                break;
            case 5:
                sort();
                break;
            default:
                printf("enter correct option\n");
                break;
    }
}
}



#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *tree;
void create_tree(struct node*);
struct node *insertelement(struct node*,int);
void preordertraversal(struct node*);
void inordertraversal(struct node*);
void postordertraversal(struct node*);
struct node *findsmallestelement(struct node*);
struct node *findlargestelement(struct node*);
struct node *deleteelement(struct node*,int);
struct node *mirrorimage(struct node*);
int totalnodes(struct node*);
int totalexternalnodes(struct node*);
int totalinternalnodes(struct node*);
int height(struct node*);
struct node*deletetree(struct node*);
int main()
{
    int option,val;
    struct node* ptr;
    create_tree(tree);
    do
    {
        printf("Enter your option\n");
        printf("1.Insert Element\n");
        printf("2.Preorder traversal\n");
        printf("3.inorder traversal\n");
        printf("4.postorder traversal\n");
        printf("5.find smallest element\n");
        printf("6.find largest element\n");
        printf("7.delete an element\n");
        printf("8.count the no. of nodes\n");
        printf("9.count the no. of external nodes\n");
        printf("10.count the no. of internal nodes\n");
        printf("11.height of the tree\n");
        printf("12.mirror image\n");
        printf("13.delete the tree\n");
        printf("14.Exit\n");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            printf("enter the value to be insert\n");
            scanf("%d",&val);
            tree=insertelement(tree,val);
            break;
        case 2:
            printf("the elements in preorder are\n");
            preordertraversal(tree);
            break;
        case 3:
            printf("the elements in inorder are\n");
            inordertraversal(tree);
            break;
        case 4:
            printf("the elements in postorder are\n");
            postordertraversal(tree);
            break;
        case 5:
            ptr=findsmallestelement(tree);
            printf("the smallest element is %d\n",ptr->data);
            break;
        case 6:
            ptr=findlargestelement(tree);
            printf("the largest element is %d\n",ptr->data);
            break;
        case 7:
            printf("enter the element to be deleted\n");
            scanf("%d",&val);
            tree=deleteelement(tree,val);
            break;
        case 8:
            printf("the no. of nodes = %d\n",totalnodes(tree));
            break;
        case 9:
            printf("the no. of external nodes = %d\n",totalexternalnodes(tree));
            break;
        case 10:
            printf("the no. of nodes = %d\n",totalinternalnodes(tree));
            break;
        case 11:
            printf("the height of the tree =%d\n",height(tree));
            break;
        case 12:
            tree=mirrorimage(tree);
            break;
        case 13:
            tree=deletetree(tree);
            break;



        }

    }while(option!=14);
    return 0;
}
void create_tree(struct node *tree)
{
    tree=NULL;
}
struct node *insertelement(struct node *tree,int val)
{
    struct node *ptr,*nodeptr,*parentptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=val;
        ptr->left=NULL;
        ptr->right=NULL;
    if(tree==NULL)
    {
        tree=ptr;ptr->data=val;
        ptr->left=NULL;
        ptr->right=NULL;
        tree->left=NULL;
        tree->right=NULL;
    }
    else{
        parentptr=NULL;
        nodeptr=tree;
        if(nodeptr!=NULL)
        {

            while(nodeptr!=NULL)
            {
                parentptr=nodeptr;
                if(val<nodeptr)
                    nodeptr=nodeptr->left;
                else
                    nodeptr=nodeptr->right;
            }
            if(val<parentptr)
                parentptr->left=ptr;
            else
                parentptr->right=ptr;
        }

    }
    return tree;

}
void preordertraversal(struct node *tree)
{
    if(tree!=NULL)
    {
        printf("%d\t",tree->data);
        preordertraversal(tree->left);
        preordertraversal(tree->right);
    }
}
void inordertraversal(struct node *tree)
{
    if(tree!=NULL)
    {
        inordertraversal(tree->left);
        printf("%d\t",tree->data);
        inordertraversal(tree->right);
    }
}
void postordertraversal(struct node *tree)
{
    if(tree!=NULL)
    {
        postordertraversal(tree->left);
        postordertraversal(tree->right);
        printf("%d\t",tree->data);
    }
}
struct node *findsmallestelement(struct node* tree)
{
    if(tree==NULL || (tree->left==NULL))
        return tree;
    else
        findsmallestelement(tree->left);
}
struct node *findlargestelement(struct node* tree)
{
    if(tree==NULL || (tree->right==NULL))
        return tree;
    else
        findlargestelement(tree->left);
}
struct node* deleteelement(struct node*tree,int val)
{
 if(tree==NULL)
    return tree;
 if(val<tree->data)
    tree->left=deleteelement(tree->left,val);
 else if(val>tree->data)
    tree->right=deleteelement(tree->right,val);
 else{
    if(tree->left==NULL)
    {
        struct node* temp=tree->right;
        free(tree);
        return temp;
    }
    else if(tree->right==NULL)
    {
        struct node* temp=tree->left;
        free(tree);
        return temp;
    }
    struct node* temp=findsmallestelement(tree->right);
    tree->data=temp->data;
    tree->right=deleteelement(tree->right,temp->data);
 }
 return tree;
}
int totalnodes(struct node* tree)
{
    if(tree==NULL)
        return 0;

    else
        return (totalnodes(tree->left)+totalnodes(tree->right)+1);
}
int totalexternalnodes(struct node* tree)
{
    if(tree==NULL)
        return 0;
    else if((tree->left==NULL)&&(tree->right==NULL))
        return 1;
    else
        return (totalexternalnodes(tree->left)+totalexternalnodes(tree->right));
}
int totalinternalnodes(struct node* tree)
{
    if((tree==NULL)||((tree->left==NULL)&& (tree->right==NULL)))
        return 0;
    else
        return (totalinternalnodes(tree->left)+totalinternalnodes(tree->right)+1);
}
int height(struct node *tree)
{
    int leftheight,rightheight;
    if(tree==NULL)
        return 0;
    else
    {
        leftheight=height(tree->left);
        rightheight=height(tree->right);
        if(leftheight>rightheight)
            return(leftheight+1);
        else
            return(rightheight+1);
    }
}
struct node* mirrorimage(struct node* tree)
{
    struct node* ptr;
    if(tree!=NULL)
    {
        mirrorimage(tree->left);
        mirrorimage(tree->right);
        ptr=tree->left;
        ptr->left=ptr->right;
        tree->right=ptr;
    }

}
struct node *deletetree(struct node* tree)
{
    if(tree!=NULL)
    {
        deletetree(tree->left);
        deletetree(tree->right);
        free(tree);
    }
}


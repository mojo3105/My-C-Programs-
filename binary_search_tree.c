#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int data)
{
    struct node *n=(struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}

void preorder(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

//function to check the given binary tree is binary search tree or not
int isbst(struct node *root)
{
    static struct node *prev=NULL;
    if(root!=NULL)
    {
        if(!isbst(root->left))
          return 0;
        if(prev!=NULL && root->data<prev->data)
          return 0;
        prev=root;
        return isbst(root->right);    
    }
    else
    {
        return 1;
    }
}

//searching element in binary search tree recursively
struct node *search(struct node *root, int key)
{
    if(root==NULL)
     return NULL;
    if(root->data==key)
     return root;
    else if(root->data>key)
     return search(root->left, key);
    else if(root->data<key)
     return search(root->right, key);     
}

//searching element in binary search tree iteratively
struct node *itrsearch(struct node *root, int key)
{
    while(root!=NULL)
    {
        if(root->data==key)
         return root;
        else if(key<root->data)
         root=root->left;
        else if(key>root->data)
         root=root->right;  
    }
    return NULL;
}

//insertion in binary search tree
void insert(struct node *root, int key)
{
    struct node *prev=NULL;
    while(root!=NULL)
    {
        prev=root;
        if(key==root->data)
        {
          printf("\nThe element %d is already in binary search tree\n", root->data);
          return 0;
        }  
        else if(key<root->data)
         root=root->left;
        else if(key>root->data)
         root=root->right;
    }
    struct node *new=createnode(key);
    if(key<prev->data)
     prev->left=new;
    else
     prev->right=new;  
}

int main()
{
   //creating a node variable using create node function 
   struct node *p1= createnode(4);
   struct node *p2= createnode(3);
   struct node *p3= createnode(5);
   
   //linking the nodes
   p1->left=p2;
   p1->right=p3;
   
   printf("Inorder of given binary tree is ");
   inorder(p1);
   if(isbst(p1))
     printf("\nThe given tree is binary search tree");
   else 
     printf("\nThe given tree is not binary search tree");  

   struct node *n= itrsearch(p1, 4);
   if(n!=NULL)
    printf("\nThe found element is %d\n", n->data);
   else
    printf("\nThe element is not found\n");   
   insert(p1, 3);
   inorder(p1); 
   return 0;
}
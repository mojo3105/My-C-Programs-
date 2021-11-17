#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int key;
    struct node *left;
    struct node *right;
    int height; // height because we need to make an avl tree
};

int max(int a, int b)
{
  if(a>=b)
    return a;
  else
    return b;  
}

int getheight(struct node *n)
{
    if(n==NULL)
     return 0;
    return n->height; 
}

struct node *createnode(int key)
{
    struct node *n=(struct node*)malloc(sizeof(struct node));
    n->key=key;
    n->left=NULL;
    n->right=NULL;
    n->height=1;
    return n;
}

int getbalencefactor(struct node *n)
{
    if(n==NULL)
      return 0;
    return getheight(n->left)- getheight(n->right);  
}

struct node *rightrotate(struct node *y)
{
    struct node *x=y->left;
    struct node *t2=x->right;

    x->right=y;
    y->left=t2;

    y->height=max(getheight(y->left) , getheight(y->right)) +1;
    x->height=max(getheight(x->left) , getheight(x->right)) +1;
    return x;
}

struct node *leftrotate(struct node *x)
{
    struct node *y=x->right;
    struct node *t2=y->left;

    y->left=x;
    x->right=t2;

    y->height=max(getheight(y->left) , getheight(y->right)) +1;
    x->height=max(getheight(x->left) , getheight(x->right)) +1;
    return y;
}

struct node *insert(struct node *n, int key)
{
    if(n==NULL)
     return createnode(key);

    if(key<n->key)
      n->left=insert(n->left, key); 

    else if(key>n->key) 
     n->right=insert(n->right, key);

    n->height=max(getheight(n->left), getheight(n->right))+1;

    int bf=getbalencefactor(n);


    // ll insertion case 
    if(bf>1 && key<n->left->key)
     return rightrotate(n);


    // rr insertion case
    if(bf<-1 && key>n->right->key) 
     return leftrotate(n);


    // left right insertion case
    if(bf>1 && key>n->left->key)
    {
        n->left=leftrotate(n->left);
        return rightrotate(n);
    }


     //  right left insertion case
    if(bf>1 && key>n->left->key)
    {
        n->right=rightrotate(n->right);
        return leftrotate(n);
    }

    return n;   
}


void preorder(struct node *root, int key)
{
    if(root!=NULL)
    {
        printf("%d ",root->key);
        preorder(root->left, key);
        preorder(root->right, key);
    }
}

int main()
{
    struct node *root= NULL;
    root=insert(root,1);
    root=insert(root,2);
    root=insert(root,3);
    root=insert(root,4);
    root=insert(root,5);
    root=insert(root,6);

    preorder(root, 1);
    return 0;
}
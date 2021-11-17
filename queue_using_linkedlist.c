#include<stdlib.h>
#include<stdio.h>

//declaring a linked list which we are going to treat as queue
struct node
{
    int data;
    struct node *next;
};

//declaring a global variable or instance of structure
struct node *f=NULL;
struct node *r=NULL;

void linked_list_traversal(struct node *ptr)
{
    while(ptr!= NULL)
    {
        printf("\nElement: %d",ptr->data);
        ptr= ptr->next;
    }
}

void enque(int val)
{
    struct node *n=(struct node*)malloc(sizeof(struct node));
    if(n==NULL)
     printf("\nQueue is full");
    else
    {
        n->data=val;
        n->next=NULL;
        if(f==NULL)
         f=r=n;
        else 
        {
            r->next=n;
            r=n;
        } 
        printf("\nEnqued element is %d",n->data);
    } 
}

int deque()
{
    int val=-1;
    struct node *ptr=f;
    if(f==NULL)
     printf("\nQueue is empty\n");
    else 
    {
        f=f->next;
        val=ptr->data;
        free(ptr);
    } 
    return val;
}

void main()
{
    linked_list_traversal(f);
    printf("\nDequeuing element %d\n", deque());
    enque(34);
    enque(4);
    enque(7);
    enque(17);
    printf("\nDequeuing element %d", deque());
    linked_list_traversal(f);
    enque(45);
    enque(90);
    linked_list_traversal(f);
}
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

void linked_list_traversal_forward(struct node *ptr)
{
    while(ptr!= NULL)
    {
        printf("Element: %d\n",ptr->data);
        ptr= ptr->next;
    }
}

void linked_list_traversal_reverse(struct node *ptr)
{
    while(ptr!= NULL)
    {
        printf("Element: %d\n",ptr->data);
        ptr= ptr->prev;
    }
}

//linked list insertion at head 
struct node* llinsertionathead(struct node *head)
{
    int data; 
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data you want to insert at head of the linked list\n");
    scanf("%d",&data);
    ptr->data=data;
    ptr->next=head;
    head->prev=ptr;
    ptr->prev=NULL;
    return ptr; 
}

//linked list insertion in between 
struct node* llinbet(struct node *head)
{
    int data,i=0,in; 
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data you want to insert\n");
    scanf("%d",&data);
    printf("Enter the index at which you want to insert data\n");
    scanf("%d",&in);
    struct node *p= head;
    p->prev=head->prev;
    while(i!= in-1)
    {
        p= p->next;
        i++;
    }
    ptr->data= data;
    ptr->next= p->next;
    p->next=ptr;
    ptr->prev=p;
    while(p->prev!=NULL)
     p=p->prev;
    return head;
}


void main()
{
    //Allocating dynamic memory in heap using malloc and we need to import stdlib.h for malloc 
  struct node *head = (struct node*)malloc(sizeof(struct node));
  struct node *second = (struct node*)malloc(sizeof(struct node));
  struct node *third = (struct node*)malloc(sizeof(struct node));
  struct node *fourth = (struct node*)malloc(sizeof(struct node));
  
  //link first(head) and second node
  head->prev=NULL;
  head->data= 7;
  head->next= second;

  //link second and third node
  second->prev=head;
  second->data= 49;
  second->next= third;

  //link third and second node
  third->prev=second;
  third->data= 55;
  third->next= fourth;

  //terminate the link at last node
  fourth->prev=third;
  fourth->data= 65;
  fourth->next= NULL;

  //doubly linked list traversal forward direction
  linked_list_traversal_forward(head);

  //entering the element at head
  //head= llinsertionathead(head);

  //entering the element in between
  head=llinbet(head);
  //doubly linked list traversal reverse direction
  linked_list_traversal_forward(head);
  linked_list_traversal_reverse(fourth);
}
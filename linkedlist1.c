#include<stdio.h>
#include<stdlib.h>

//linked list declaration as a structure
struct node
{
    int data;
    struct node *next;
};

//linked list traversal function defination
void linked_list_traversal(struct node *ptr)
{
    while(ptr!= NULL)
    {
        printf("Element: %d\n",ptr->data);
        ptr= ptr->next;
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
    while(i!= in-1)
    {
        p= p->next;
        i++;
    }
    ptr->data= data;
    ptr->next= p->next;
    p->next=ptr;
    return head;
}

//Insertion at the end
struct node *insert_at_end(struct node *head)
{
    int data;
    struct node *ptr= (struct node*)malloc(sizeof(struct node));
    printf("\nEnter the element you want to insert at the end of the linked list\n");
    scanf("%d",&data);
    ptr->data=data;
    struct node *p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
}

//linked list element deletion at the starting 
struct node *delete_first(struct node *head)
{
    struct node *ptr=head;
    head=head->next;
    free(ptr);
    return head;
}

//linked list element deletion at index
struct node *delete_at_index(struct node *head)
{
    int i,in;
    struct node *ptr=head;
    struct node *p=head->next;
    printf("\nEnter the index at which you want to delete the element\n");
    scanf("%d",&in);
    for(i=1;i<in-i;i++)
    {
        ptr=ptr->next;
        p=p->next;
    }
    ptr->next=p->next;
    free(p);
    return head;
}

//linked list deletion at end node
struct node *delete_at_end(struct node *head)
{
    struct node *ptr=head;
    struct node *p=head->next;
    while(p->next!=NULL)
    {
      ptr=ptr->next;
      p=p->next;
    }
    ptr->next=p->next;
    free(p);
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
  head->data= 7;
  head->next= second;

  //link second and third node
  second->data= 49;
  second->next= third;

  //link third and second node
  third->data= 55;
  third->next= fourth;

  //terminate the link at last node
  fourth->data= 65;
  fourth->next= NULL;

  //linked list traversal using function declaration
  linked_list_traversal(head);

  //linked list insertion at the begining
  //head= llinsertionathead(head);
  
  //linked list insertion at end
  //head=insert_at_end(head);


  //linked list insertion in between
  //head= llinbet(head);

  //linked list delete at first
  //head=delete_first(head);

  //linked list delete at index
  //head=delete_at_index(head);

  //linked list delete at index
  head=delete_at_end(head);
  linked_list_traversal(head);
}
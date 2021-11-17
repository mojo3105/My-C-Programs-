#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void clltraversal(struct node *head)
{
    struct node *ptr = head;
    do
    {
        printf("Element is %d\n",ptr->data);
        ptr=ptr->next;
    } while (ptr!=head);
    
}

struct node *insertionatfirst(struct node *head, int val)
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data=val;
    struct node *p=head->next;
    while(p->next!=head)
     p=p->next;
    p->next=ptr;
    ptr->next=head;
    head=ptr;
    return head; 
}


void main()
{
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
  fourth->next= head;

  clltraversal(head);
  head=insertionatfirst(head,68);

  clltraversal(head);

}
#include<stdio.h>
#include<stdlib.h>

//defining the stack using array
struct stack
{
    int size;
    int top;
    int *arr;
};

//ensure the stack is empty
int isempty(struct stack *ptr)
{
    if(ptr->top ==-1)
      return 1;
    else
      return 0;   
}

//ensure the stack is full
int isfull(struct stack *ptr)
{
    if(ptr->top==ptr->size)
       return 1;
    else
       return 0;   
}

//creating a push function for entering the element in stack
void push(struct stack *ptr, int val)
{
  if(!isfull)
   printf("\nstack overflow");
  else
  {
    ptr->top++;
    ptr->arr[ptr->top]=val;
  } 
}

//creating a function for removing the element from stack
int pop(struct stack *ptr)
{
  if(!isempty)
  {
   printf("\nstack underflow");
   return -1;
  } 
  else
  {
    int val=ptr->arr[ptr->top];
    ptr->top=ptr->top-1;
    return val;
  } 
}

//accessing the elements of stack 
void stack_traversal(struct stack *ptr)
{
  for(int i=0; i<=ptr->size; i++)
  {
     if(ptr->arr[i]==0)
       break;
     printf("\nstack element form top at %d is %d",ptr->top,ptr->arr[i]);
  }    
}

//peeking an element in stack
int peek(struct stack *ptr, int i)
{
  int index=ptr->top-i+1;
  if(index<0)
  {
    printf("\nNot a valid position for stack");
    return -1;
  }
  else 
  {
    return ptr->arr[index];
  }
}

//funtion who returns the value of stack at the top
int stacktop(struct stack *ptr)
{
  return ptr->arr[ptr->top];
}

//fuction who returns the value of stack at the bottom
int stackbottom(struct stack *ptr)
{
  return ptr->arr[0];
}

void main()
{
  struct stack *sp=(struct stack*)malloc(sizeof(struct stack));
  sp->size=20;
  sp->top=-1;
  sp->arr=(int*)malloc(sp->size*sizeof(int));
  //checking for empty or not
  // if(isempty(sp))
  //   printf("stack is empty");
  // else 
  //   printf("stack is not empty"); 

  //mannually pushing an element in stack
  // sp->arr[0]=4;
  // sp->top++;
  // if(!isfull)
  //  printf("\nstack is full");
  // else
  //  printf("\nstack is not full");     

  push(sp, 65);
  push(sp, 69);
  push(sp, 44);
  push(sp, 35);
  push(sp, 23);
  push(sp, 24);
  push(sp, 85);
  push(sp, 26);
  push(sp, 78);
  push(sp, 45);
  push(sp, 90);
  push(sp, 02);
  push(sp, 45);
  push(sp, 10);
  push(sp, 69);

  // printf("\nThe removed element from stack is %d",pop(sp));

  // printf("\nAfter poping operation the elements are-");
  // stack_traversal(sp);
  for(int j=1; j<sp->top ;j++)                             //here we are traversing through the element of stack but opposite of our traversal function
   printf("\nThe value at position %d is %d",j,peek(sp,j));

  printf("\nThe element at bottom of stack is %d ",stackbottom(sp));
  printf("\nThe element at top of stack is %d ",stacktop(sp));




  
  
  
  
  
      

    
}
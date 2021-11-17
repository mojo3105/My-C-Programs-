#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//defining the stack using array
struct stack
{
    int size;
    int top;
    char *arr;
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
void push(struct stack *ptr, char val)
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
char pop(struct stack *ptr)
{
  if(!isempty)
  {
   printf("\nstack underflow");
   return -1;
  } 
  else
  {
    char val=ptr->arr[ptr->top];
    ptr->top=ptr->top-1;
    return val;
  }
}

//creating a funciton for deciding the operator precedence
int precedence(char ch)
{
    if(ch=='*' || ch=='/')
     return 3;
    else if(ch=='+' || ch=='-')
     return 2;
    return 0;  
}

//creating a function for checking an element is operator or not
int isoperator(char ch)
{
    if(ch=='*' || ch=='/'  || ch=='+' || ch=='-')
     return 1;
    else 
     return 0;
}

//fuction who return the value at top
int stacktop(struct stack *ptr)
{
  return ptr->arr[ptr->top];
}

void intopo(char *infix)
{
    struct stack *sp;
    sp->size=100;
    sp->top=-1;
    sp->arr=(char*)malloc(sp->size*sizeof(char));
    char *postfix=(char*)malloc((strlen(infix)+1)*sizeof(char));
    int i=0,j=0;
    while(infix[i]!=0)
    {
        if(!isoperator(infix[i]))
        {
            postfix[j]=infix[i];
            i++;
            j++;
        }
        else
        {
            if(precedence(infix[i])>precedence(stacktop(sp)))
            {
                push(sp,infix[i]);
                i++;
            }
            else
            {
                postfix[j]=pop(sp);
                j++;
            }
        }
    }
    while(!isempty(sp))
    {
        postfix[j]=pop(sp);
        j++;
    }

    for(i=0;i<9;i++)
     printf("%c",postfix[i]);
}

void main()
{
    char *infix="x-y/z-k*d";
    intopo(infix);
    printf("the infix is do it's postfix %s",infix);
}
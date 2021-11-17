#include<stdio.h>
#include<stdlib.h>

struct cqueue
{
    int size;
    int f;
    int r;
    int *arr;
};

void enque(struct cqueue *q, int val)
{
    if((q->r+1)%q->size==q->f)          //this is the condition for queue is full or not 
     printf("\nQueue overflow");
    else
    {
        q->r=(q->r+1)%q->size;
        q->arr[q->r]=val;
        printf("\nElement enterd in queue is %d",q->arr[q->r]);
    } 
}

int deque(struct cqueue *q)
{
    int a=-1;
    if(q->r==q->f)                  //this is the condition for queue is empty or not
     printf("\nQueue underflow");
    else
    {
        q->f=(q->f+1)%q->size;
        a=q->arr[q->f];
    } 
    return a;
}

void main()
{
    struct cqueue *q;
    q->size=4;
    q->r=q->f=0;
    q->arr=(int*)malloc(q->size*sizeof(int));
    enque(q,44);
    enque(q,45);
    enque(q,46);
    enque(q,47);
    // printf("\nDequeued element is %d",deque(q));
    // printf("\nDequeued element is %d",deque(q));
    // printf("\nDequeued element is %d",deque(q));
    // printf("\nDequeued element is %d",deque(q));
}
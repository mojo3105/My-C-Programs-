#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

void enque(struct queue *q, int val)
{
    if(q->r==q->size-1)
     printf("\nQueue overflow");
    else
    {
        q->r++;
        q->arr[q->r]=val;
        printf("\nElement enterd in queue is %d",q->arr[q->r]);
    } 
}

int deque(struct queue *q)
{
    int a=-1;
    if(q->r==a)
     printf("\nQueue underflow");
    else
    {
        q->f++;
        a=q->arr[q->f];
    } 
    return a;
}

void main()
{
    struct queue *q;
    q->size=100;
    q->r=q->f=-1;
    q->arr=(int*)malloc(q->size*sizeof(int));
    enque(q,44);
    enque(q,45);
    enque(q,46);
    enque(q,47);
    printf("\nDequeued element is %d",deque(q));
}
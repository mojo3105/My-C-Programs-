#include<stdio.h>
#include<stdlib.h>
 
struct Node{
    int data;
    struct Node * next;
};

 
void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("\nElement: %d", ptr->data);
        ptr = ptr->next; 
    }
}
 
int isEmpty(struct Node* top){
    if (top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
 
int isFull(struct Node* top){
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    if(p==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
 
struct Node* push(struct Node* top, int x){
    if(isFull(top)){
        printf("Stack Overflow\n");
    }
    else{
        struct Node* n = (struct Node*) malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}
 
int pop(struct Node** top){
    if(isEmpty(*top)){
        printf("Stack Underflow\n");
    }
    else{
        struct Node* n = *top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        return x; 
    }
}

 
int main(){
    struct Node* top = NULL;
    // printf("Checking for stack to be empty");
    // if(isEmpty)
    //  printf("\nStack Underflow");
    // else
    //  printf("\nStack is not empty");

    //entering the element in stack 
    top=push(top,35);
    top=push(top,36);
    top=push(top,37);
    top=push(top,38);

    // printf("\nChecking for stack to be full");
    // if(isFull)
    //  printf("\nStack overflow");
    // else 
    //  printf("\nStack is not full");

    //printing the element in stack
    linkedListTraversal(top);

    //removing the element from the stack
    int ele=pop(&top);
    printf("\npopped element is %d",ele);
    return 0;
}

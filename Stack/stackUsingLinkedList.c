#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr){
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    
}

int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull()
{
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

struct Node *pushInStack(struct Node *top,int data){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if(isFull()){
        printf("Stack overflow");
    }
    else{
        newNode->data = data;
        newNode->next = top;
        top = newNode;
        return top;
    }
}

struct Node *popFromStack(struct Node *top){
    if(isEmpty(top)){
        printf("Stack is underflow");
    }
    else{
        struct Node *n = top;
        top = top->next;
        int element = n->data;
        free(n);
        return top;
    }
}

int main(int argc, char const *argv[])
{

    struct Node *top = NULL;
    top = pushInStack(top,56);
    top = pushInStack(top,59);
    top = pushInStack(top,63);
    top = popFromStack(top);
    linkedListTraversal(top);
    return 0;
}

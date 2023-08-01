#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
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

struct Node *pushInStack(struct Node *top, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (isFull())
    {
        printf("Stack overflow");
    }
    else
    {
        newNode->data = data;
        newNode->next = top;
        top = newNode;
        return top;
    }
}

struct Node *popFromStack(struct Node *top)
{
    if (isEmpty(top))
    {
        printf("Stack is underflow");
    }
    else
    {
        struct Node *n = top;
        top = top->next;
        int element = n->data;
        free(n);
        return top;
    }
}

int peekFromStack(struct Node *top, int index)
{
    struct Node *ptr = top;
    int initialIndex = 1;
    if (index <= 0 || top == NULL)
    {
        printf("Please enter valid index \n");
        return -1;
    }
    while (ptr != NULL)
    {
        if (initialIndex == index)
        {
            break;
        }
        ptr = ptr->next;
        initialIndex++;
    }
    if (ptr == NULL)
    {
        printf("Please enter valid index \n");
        return -1;
    }
    int myValue = ptr->data;
    printf("Your selected element is %d", myValue);
}

int getBottomElementFromStack(struct Node *top)
{
    struct Node *ptr = top;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    printf("The bottom element of stack is %d \n", ptr->data);
    return 1;
}

int getTopElementFromStack(struct Node *top)
{
    printf("The top elements of stack is %d \n", top->data);
    return 1;
}

int main(int argc, char const *argv[])
{

    struct Node *top = NULL;
    top = pushInStack(top, 56);
    top = pushInStack(top, 59);
    top = pushInStack(top, 63);
    // top = popFromStack(top);
    linkedListTraversal(top);
    peekFromStack(top, 44);
    getBottomElementFromStack(top);
    getTopElementFromStack(top);
    return 0;
}

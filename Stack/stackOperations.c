#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int pushInStack(struct stack *ptr, int data)
{
    if (isFull(ptr))
    {
        printf("Your stack is full\n");
        return -1;
    }
    else
    {
        ptr->arr[ptr->top + 1] = data;
        ptr->top++;
        printf("Successfully pushed %d in to the stack\n", data);
        return 0;
    }
}

int popFromStack(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Your stack is empty!\n");
        return -1;
    }
    else
    {
        int element = ptr->arr[ptr->top];
        ptr->top = ptr->top - 1;
        printf("Successfully poped out %d from the stack.\n", element);
        return 0;
    }
}

int peekFromStack(struct stack *ptr, int position)
{
    int arrayIndex = ptr->top - position + 1;
    if (arrayIndex < 0)
    {
        printf("Not a valid position!");
        return -1;
    }
    else
    {
        return ptr->arr[arrayIndex];
    }
}

void getStackBottom(struct stack *ptr){
    printf("Stack's bottom element is %d \n",ptr->arr[0]);
}

void getStackTop(struct stack *ptr){
    printf("Stack's top element is %d \n",ptr->arr[ptr->top]);
}

int main(int argc, char const *argv[])
{

    struct stack *myFirstStack = (struct stack *)malloc(sizeof(struct stack));
    myFirstStack->size = 10;
    myFirstStack->top = -1;
    myFirstStack->arr = (int *)malloc(myFirstStack->size * sizeof(int));

    pushInStack(myFirstStack, 56);
    pushInStack(myFirstStack, 25);
    pushInStack(myFirstStack, 42);
    pushInStack(myFirstStack, 78);
    pushInStack(myFirstStack, 67);
    pushInStack(myFirstStack, 44);
    pushInStack(myFirstStack, 75);
    pushInStack(myFirstStack, 56);
    pushInStack(myFirstStack, 78);
    pushInStack(myFirstStack, 14);
    pushInStack(myFirstStack, 17);
    pushInStack(myFirstStack, 1);

    popFromStack(myFirstStack);
    popFromStack(myFirstStack);
    popFromStack(myFirstStack);

    pushInStack(myFirstStack, 76);
    pushInStack(myFirstStack, 89);
    pushInStack(myFirstStack, 144);
    pushInStack(myFirstStack, 25);

    for (int i = 1; i <= myFirstStack->top + 1; i++)
    {
        printf("%d ", peekFromStack(myFirstStack, i));
    }
    printf("\n");

    getStackBottom(myFirstStack);
    getStackTop(myFirstStack);

    return 0;
}

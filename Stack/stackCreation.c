#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int main(int argc, char const *argv[])
{

    struct stack *myFirstStack = (struct stack *)malloc(sizeof(struct stack));

    myFirstStack->size = 80;
    myFirstStack->top = -1;
    myFirstStack->arr = (int *)malloc(myFirstStack->size * sizeof(int));

    return 0;
}

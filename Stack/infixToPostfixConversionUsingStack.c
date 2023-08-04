#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int size;
    int top;
    char *arr;
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

int pushInStack(struct stack *ptr, char data)
{
    if (isFull(ptr))
    {
        return -1;
    }
    else
    {
        ptr->arr[ptr->top + 1] = data;
        ptr->top++;
        return 0;
    }
}

int popFromStack(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        return -1;
    }
    else
    {
        int element = ptr->arr[ptr->top];
        ptr->top = ptr->top - 1;
        return element;
    }
}

int getStackTop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}

int precedence(char ch)
{
    if (ch == '*' || ch == '/')
    {
        return 3;
    }
    else if (ch == '+' || ch == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

int isOperator(char ch)
{
    if (ch == '*' || ch == '/' || ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char *infixToPostfix(char *infix)
{

    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));

    int i = 0; // Track infix traversal
    int j = 0; // Track postfix addition

    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }

        else
        {
            if (precedence(infix[i]) > precedence(getStackTop(sp)))
            {
                pushInStack(sp, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = popFromStack(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))
    {
        postfix[j] = popFromStack(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main(int argc, char const *argv[])
{
    char *infix = "a-b";
    char *postFix = infixToPostfix(infix);
    printf("%s", postFix);
    return 0;
}

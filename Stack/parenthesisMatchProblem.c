#include <stdio.h>
#include <stdlib.h>

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
        return 0;
    }
}

int parenthesisMatching(char *exp){

    struct stack* sp;
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char*)malloc(sp->size*sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if(exp[i] == '('){
            pushInStack(sp,'(');
        }
        else if(exp[i] == ')'){
            if(isEmpty(sp)){
                return 0;
            }
            popFromStack(sp);
        }
    }
    if(isEmpty(sp)){
        return 1;
    }
    else{
        return 0;
    }
    
}

int main(int argc, char const *argv[])
{
    char *exp = "45k3l((30)";
    size_t length = strlen(exp);
    printf("%d\n",length);

    if(parenthesisMatching(exp)){
        printf("Parenthesis is matching.");
    }
    else{
        printf("Parenthesis is not matching.");
    }

    return 0;
}


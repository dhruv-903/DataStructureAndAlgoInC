#include <stdio.h>
#include <stdlib.h>

struct customArray
{
    int arraySize;
    int usedSize;
    int *ptr;
};

void createCustomArray(int totalSize, int totalUsedSize, struct customArray *myArray)
{
    (*myArray).arraySize = totalSize;
    (*myArray).usedSize = totalUsedSize;
    (*myArray).ptr = (int *)malloc(totalSize * sizeof(int));
};

void addElement(struct customArray *myArray)
{
    int n;
    for (int i = 0; i < myArray->usedSize; i++)
    {
        printf("Enter the %d element\n", i);
        scanf("%d", &n);
        myArray->ptr[i] = n;
    }
};

void showArrayElements(struct customArray *myArray)
{
    for (int i = 0; i < myArray->usedSize; i++)
    {
        printf("%d ", myArray->ptr[i]);
    }
}

int main(int argc, char const *argv[])
{
    struct customArray firstArray;
    int maxArraySize = 10;
    int usedSize = 8;
    createCustomArray(maxArraySize, usedSize, &firstArray);
    addElement(&firstArray);
    showArrayElements(&firstArray);
    return 0;
}
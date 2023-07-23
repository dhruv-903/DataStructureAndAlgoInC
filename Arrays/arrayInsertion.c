#include <stdio.h>

void display(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int arrayInsertion(int array[], int size, int element, int capacity, int index)
{

    if (index >= capacity)
    {
        return -1;
    }
    else
    {
        for (int i = size - 1; i >= index; i--)
        {
            array[i + 1] = array[i];
        }
        array[index] = element;
        return 1;
    }
};

int sortedArrayInsertion(int array[], int size, int element, int capacity)
{
    if (element >= array[size - 1])
    {
        array[size] = element;
    }
    else if (element <= array[0])
    {
        for (int j = size - 1; j >= 0; j--)
        {
            array[j + 1] = array[j];
        }
        array[0] = element;
    }
    int index = 0;
    for (int i = 0; i < size; i++)
    {
       if(array[i] < element){
        index = i;
        continue;
       }
       for (int j = size-1; j >= index+1; j--)
       {
        array[j+1] = array[j];
       }
       array[index+1] = element;
       break;
    }
}

int main(int argc, char const *argv[])
{
    int array[100] = {11, 12, 13, 15, 16};

    int capacity = sizeof(array) / sizeof(array[0]);
    int size = 5, element = 14, index = 3;

    display(array, size);
    // arrayInsertion(array, size, element, capacity, index);
    sortedArrayInsertion(array, size, element, capacity);
    size += 1;
    display(array, size);

    return 0;
}

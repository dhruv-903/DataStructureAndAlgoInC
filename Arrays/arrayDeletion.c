#include <stdio.h>

void display(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int arrayDeletion(int array[], int size, int capacity, int index){

    if(index >= size){
        return -1;
    }

    for (int i = index; i < size-1; i++)
    {
        array[i] = array[i+1];
    }
    return 1;
    

};

int main(int argc, char const *argv[])
{
    int array[100] = {11, 12, 13, 15, 16};

    int capacity = sizeof(array) / sizeof(array[0]);
    int size = 5, index = 1;

    display(array, size);
    arrayDeletion(array, size, capacity, index);
    size -= 1;
    display(array, size);

    return 0;
}

#include <stdio.h>

int linearSearch(int array[],int size,int element){
    for (int i = 0; i < size; i++)
    {
        if(array[i] == element){
            return 1;
        }
    }
    
}

int main(int argc, char const *argv[])
{
    int array[] = {23,4,2,52,4};
    int size = sizeof(array)/sizeof(array[0]) , element = 4;
    int result = linearSearch(array,size,element);

    if(result == 1){
        printf("Element found");
    }
    else{
        printf("Element not found");
    }
    
    return 0;
}

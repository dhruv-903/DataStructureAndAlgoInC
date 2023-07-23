#include <stdio.h>

int binarySearch(int array[], int size, int element)
{
    int low, mid, high;
    low = 0;
    high = size-1;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (array[mid] == element)
        {
            return mid;
        }
        if (array[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int array[] = {5, 9, 12, 18, 22, 27};
    int size = sizeof(array) / sizeof(array[0]), element = 27;
    int result = binarySearch(array, size, element);

    if (result == -1)
    {
        printf("Element not found!");
    }
    else
    {
        printf("Element found");
    }

    return 0;
}

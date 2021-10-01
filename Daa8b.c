/* For a given array : 99, 1, 5, 8, 75, 0, 665, 1, 0, 9, 1,  2, 5, 32, 67. Sort the first half using normal quicksort. Second half using Randomized quick sort. Sort the final result using Randomized quick sort. */
#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int low, int high)
{
    //pivot element to be placed a the right position
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        //if the current element is smaller than pivot.
        if (arr[j] <= pivot)
        {
            //increment the index of the smaller element and then swap.
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void rand_quicksort(int *arr, int start, int end)
{
    if (start < end)
    {
        int pivot = start;
        pivot = rand() % (end - start) + start;
        pivot = partition(arr, start, end);
        rand_quicksort(arr, start, pivot - 1);
        rand_quicksort(arr, pivot + 1, end);
    }
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* p is the partioning index,
        arr[p] which is now at the right place*/
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        // quickSort(arr, p + 1, high);
        rand_quicksort(arr, p + 1, high);
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {99, 1, 5, 8, 75, 0, 665, 1, 0, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    printf("The sorted array is: \n");
    printArray(arr, n);
    return 0;
}

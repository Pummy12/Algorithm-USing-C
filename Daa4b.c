WAP to sort half of an array with n elements with INSERTION sort and  other half with MERGE sort. The two  subarrays that will be produced will be combined through Merge sort technique to produce the final sorted array. Array size = n. Also mention the time complexity in your solution.
#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key && j <= n) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
 
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int test_case;
    printf("Enter the number of test case : \n");
    scanf("%d", &test_case);
    
    while(test_case--){

        printf("Enter the size of array :- \n");
        int size_of_arr;
        
        scanf("%d", &size_of_arr);
        
        int arr[size_of_arr];
        
        printf("Using Random Function : \n");
        
        for(int i = 0 ; i < size_of_arr ; i++)
            arr[i] = rand()%100;
        
        printf("Given array is \n");
        printArray(arr, size_of_arr);
        
        int m1 = (size_of_arr+1)/2;
        
        insertionSort(arr, m1);
        
        printf("\nInsertion Sort in half array(from index 0 till %d)\n",m1);
        printArray(arr, size_of_arr);
        
        mergeSort(arr, m1, size_of_arr-1);
        printf("\nMerge Sort in another half array(from index %d to %d)\n",m1+1, size_of_arr-1);
        printArray(arr, size_of_arr);
        
        printf("\nafter this we have to use merge function for sorting this\n");
        merge(arr, 0, (size_of_arr-1)/2, size_of_arr-1);
        
        printArray(arr, size_of_arr);
        
    }
    
    return 0;
}

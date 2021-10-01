#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void merge(int a[], int lb, int mid, int ub)
{
    int b[50], i, j, k;
    i = lb;
    j = mid + 1;
    k = lb;
    while (i <= mid && j <= ub)
    {
        if (a[i] <= a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }
    if (i > mid)
    {
        while (j <= ub)
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    else
    {
        while (i <= mid)
        {
            b[k] = a[i];
            i++;
            k++;
        }
    }
    for (k = lb; k <= ub; k++)
    {
        a[k] = b[k];
    }
}

void mergesort(int a[], int lb, int ub)
{
    int mid;
    if (lb < ub)
    {
        mid = (lb + ub) / 2;
        mergesort(a, lb, mid);
        mergesort(a, mid + 1, ub);
        merge(a, lb, mid, ub);
    }
}

int main()
{
 
    int a[50];
    int n;
    printf("Enter the array size -> ");
    scanf("%d", &n);
    printf("Enter the array elemtnts -> ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &n);
    }
    printf("Entered array is -> ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
   double x = clock();

   
    mergesort(a, 0, n - 1);

    printf("Sorted array is -> ");
    for (int i = 0; i < n; i++)
    {
        printf("  %d  ", a[i]);
    }
    double y = clock();
    double z = y - x;
    printf("\nTime:%f", z);
}
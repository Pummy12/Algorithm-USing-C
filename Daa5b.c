//WAP to find the first K minimum elements from N unsorted elements. Also for remaining (N-K) elements print in descending order.
#include<stdio.h>
void bubbleSort(int arr[], int n)
	{
		int i, j, temp;
   		for (i = 0; i < n-1; i++)      
       	for (j = 0; j < n-i-1; j++) 
           	if (arr[j] > arr[j+1])
              	{
              		temp = arr[j];
              		arr[j] = arr[j + 1];
              		arr[j + 1] = temp;
              	}
	}

int main(){
	int i, n, k;

	printf("Enter the size of array\n");
	scanf("%d", &n);
	int arr[n];
	
	printf("Enter elements to the array\n");
	for(i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	
	bubbleSort(arr, n); //sorting the array
	
	printf("Enter the no of elements to be extracted\n");
	scanf("%d", &k);
	
	printf("The %d minimum elements are:-\n", k);
	for(i=0; i<k; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	
	printf("the rest %d elements in descending order:-\n", n-k);
	for(i=n-1; i>=k; i--)
	{
		printf("%d ", arr[i]);	
	}
	printf("\n");
}

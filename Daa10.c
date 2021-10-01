/*
Q. WAP to implement apply the max-heapify to the root node of the initial tree. Extract/Print that new root (1st element) element out. Apply the max-heapify again to the 3rd node. Extract/Print the new root (3rd element),  

Apply the max-heapify again to the 5th node. Extract/Print the new root (5th element)
22, 88, 45, 9, 1 -9, 2, 56, 14.
Also find the time for different input size entries.
*/


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
void maxHeapify(int a[],int i,int n){
    int right = i*2+1;
    int left = i*2;
    int largest;
    if(left<=n && a[left]>a[i]){
        largest = left;
    }else {
        largest = i;
    }
    if(right<=n && a[right]>a[largest]){
        largest = right;
    }
    if(largest != i){
        swap(&a[i],&a[largest]);
        maxHeapify(a,largest,n);
    }
}

int main(){
    clock_t tem_req;
    tem_req = clock();
    int n;
    printf("Enter no of elements--");
    scanf("%d",&n);
    int a[n+1];
    a[0] = 0;
    for(int i=1;i<=n;i++)
    {
        a[i] = rand() % 56;
    }
    for(int i =1;i<=n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    for(int i=1;i<=5;i+=2){
        maxHeapify(a,i,n);
        printf("%d node:-%d\n",i,a[i]);
    }
    tem_req = tem_req - clock();
    printf("Total time taken: %f\n", tem_req);
    return 0;
}

/*Write a program to display an array of n integers (n>1) in O(n) time, where at every index of the array should contain the product of all elements in the array except the element at the given index. No additional array declaration is allowed.
Example:
Input : 10, 4, 1, 6, 2
Output : 48,120,480,80,240 */
#include<stdio.h>
int main()
{
    int arr[5]={10,4,1,6,2};
    int p=1;
    for(int i=0;i<5;i++)
    {
        p = p*arr[i];
    }
    for(int i=0;i<5;i++)
    {
        arr[i] = p/arr[i];
    }
    for(int i=0;i<5;i++)
    {
        printf("%d ",arr[i]);
    }
}

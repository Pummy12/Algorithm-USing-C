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
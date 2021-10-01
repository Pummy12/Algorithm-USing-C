// Write a program for finding i and j in an array A for any key such that A[j]^2 + A[i]^2 == key
#include<stdio.h>
int main()
{
    int arr[5]={1,4,8,2,3};
    int key = 20;
    int q = -1,w=-1;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if((arr[i]*arr[i])+(arr[j]*arr[j]) == key)
            {
                q=i;w=j;
                break;
            }
        }
        if(q!=-1) break;
    }
    printf("%d %d",q,w);
}

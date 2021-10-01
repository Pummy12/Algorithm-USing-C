#include<stdio.h>
int main()
{
    int arr[5]={1,2,3,4,5};
    int key = 9;
    int q=-1,w=-1,e=-1;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            for(int k=0;k<5;k++)
            {
                if(arr[i]+arr[j]+arr[k]==key)
                {
                    q=i;w=j;e=k;
                }
            }
            if(q!=-1&&w!=-1&&e!=-1) break;
        }
        if(q!=-1&&w!=-1&&e!=-1) break;
    }
    printf("%d %d %d",q,w,e);
}
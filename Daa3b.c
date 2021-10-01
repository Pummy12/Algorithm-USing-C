//a)Consecutive integer checking algo
#include<stdio.h>
void main()
{
   int a,b,ans;
     printf("Enter the 2 numbers:\n");
     scanf("%d%d",&a,&b);

ans=GCD(a,b);
printf("GCD of a and b =%d",ans);
}

int GCD(int a,int b)
{
 int temp,i;
  temp=a>=b?b:a;

for(i=temp;i>=1;i--)
{
 if(a%i==0&&b%i==0)
{
  return(i);
}
}
}
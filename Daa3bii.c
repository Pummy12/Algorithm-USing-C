//b) middle school procedure

#include<stdio.h>
void main()
{
   int a,b,gcd;
     printf("Enter the 2 numbers:\n");
     scanf("%d%d",&a,&b);

gcd=GCD(a,b);
printf("GCD of a and b =%d",gcd);
}

int GCD(int a,int b)
{
  int temp,i;
  int ans=1;
  int m=0,n=0;
  temp=a>=b?b:a;

for(i=2;i<=temp;i++)
  {
    n=0;
    m=0;
    if(a%i==0)
       {
         m=1;
         a=a/i;
       }

    if(b%i==0)
      {
        n=1;
        b=b/i;
       }

  if(m==1&&n==1)
   {
    ans=ans*i;
   }
  if(n==1||n==1)
  {
   i--;
   }
 }
return (ans);
}

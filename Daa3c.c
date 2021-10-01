//Time Complexity: T(n) = T(n-1) + T(n-2) which is exponential. 
//Write a program to compute the nth Fibonacci number recursively and find its time complexity
#include<stdio.h>
int main ()
{
int num;
printf("Enter number :");
scanf("%d",&num);
printf("%d", fib(num));
getchar();
return 0;
}
int fib(int n)
{
if (n <= 1)
	return n;
return fib(n-1) + fib(n-2);
}



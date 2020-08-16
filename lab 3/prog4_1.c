#include<stdio.h>
int fib(int n);
int main()
{
	int n, i;
	printf("Enter value of n:");
	scanf("%d", &n);
	printf("fibonaci series:\n");
	for(i=0; i<n; i++)
	{
		printf("%d\t", fib(i));
	}

}
int fib(int n)
{
	if(n<=1)
	{
		return n;
	}
	
	
	return fib(n-1)+fib(n-2);
	
}
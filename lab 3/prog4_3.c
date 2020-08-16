#include<stdio.h>
#include<string.h>
int palin(char str[], int, int);
void main()
{
	char str[20];
	printf("Enter the string\n");
	
	scanf("%s", str);
	int n=strlen(str);
	int flag=palin(str, n, 0);
	if(flag)
		printf("String is a palindrome");
	else
		printf("String is not a palindrome");


}
int palin(char str[], int n, int i)
{
	if(str[i]!=str[n-i-1])
		return 0;
	else if(i<=n/2)
	{
		palin(str, n, i+1);
		return 1;
	}

		
	
	

}
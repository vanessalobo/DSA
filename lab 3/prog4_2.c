#include<stdio.h>
#include<string.h>
void copy(char str1[], char str2[], int);
void main()
{
	char str1[10], str2[10];
	printf("Enter the string\n");
	//fflush(stdin);
	scanf("%s", str1);
	//int n=strlen(str1);
	copy(str1, str2, 0);
	//fflush(stdin);
	printf("The copied string is:\n");
	printf("%s", str2);

}
void copy(char str1[], char str2[], int index)
{
	
	str2[index]=str1[index];
	if(str1[index]=='\0')
		return;
	index++;
	copy(str1, str2, index);


}
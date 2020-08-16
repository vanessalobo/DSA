#include<stdio.h>
int moves=0;
void tower(int n, char, char, char);
void main()
{

	int n;
	printf("Enter the number of discs\n");
	scanf("%d", &n);
	tower(n, 'A', 'B', 'C');
	printf("No of moves=%d", moves);



}
void tower(int n, char source, char temp, char dest)
{
	if(n==1)
	{
		printf("move disk 1 from %c to %c\n", source, dest);
		moves++;
		return;
	}
	tower(n-1, source, dest, temp);
	printf("move disk %d from %c to %c\n", n, source, dest);
	moves++;
	tower(n-1, temp, source, dest);
}

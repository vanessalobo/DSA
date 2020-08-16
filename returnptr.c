#include<stdio.h>
int *ptr(int *);
void main()
{
    int a;
    scanf("%d", &a);
    printf("%p", ptr(&a));
}
int *ptr(int *p)
{
    return p;
}

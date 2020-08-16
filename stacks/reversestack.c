#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
void push(char);
void reverseStr(char str[], int);
char tops();
void pop();
int isEmpty();
int isFull();
void display();
char s[MAX];
int top=-1;
int main()
{
    char str[100];
    printf("Enter string:");
    scanf("%s", str);
    int n=strlen(str);
    reverseStr(str, n);
    printf("Reverse: %s", str);
    return 0;

}
void reverseStr(char str[100], int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        push(str[i]);
    }
    display();
    for(i=0; i<n; i++)
    {
        str[i]=tops();
        pop();
    }

}
void push(char x)
{

    if(isFull())
    {
        printf("Stack overflow");
        return;
    }

        else
        {
            top=top+1;
            s[top]=x;
            return;
        }
}
void pop()
{
    if(isEmpty())
    {
        printf("Stack underflow");
        return;
    }

    else
    {
        top--;
        return;

    }

}
void display()
{
    printf("Stack:");
    for(int i=0; i<=top; i++)
    {
        printf("%c\t", s[i]);
    }
}
int isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
int isFull()
{
    if(top==MAX-1)
        return 1;
    else
        return 0;
}
char tops()
{
    return s[top];
}

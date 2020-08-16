#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
void push(char);
int palin(char str[], int);
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
    if(palin(str, n))
        printf("Palindrome");
    else
        printf("Not a palindrome");

    return 0;

}
int palin(char str[100], int n)
{
    int i, flag;
    if(n%2==0)
    {
        for(i=0; i<n/2; i++)
        {
            push(str[i]);
        }


    }
    else
    {
        for(i=0; i<=n/2; i++)
            push(str[i]);
    }
    for(i=n/2; i<n; i++)
    {
        if(str[i]!=tops())
        {
            flag=0;
            break;
        }
        else
        {
            pop();
            flag=1;

        }
    }
    return flag;


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


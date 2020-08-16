#include<stdio.h>
#include<stdlib.h>
#define MAX 100
void push(int*, int);
void pop(int*);
int isEmpty();
int isFull();
void display(int*);
int tops(int*);

int top=-1;

int main()
{

    int *s;
    int rem, n;
    s=(int*)calloc(MAX, sizeof(int));
    printf("enter binary number:");
    scanf("%d", &n);
    while(n>0)
    {
        rem=n%2;
        push(s, rem);
        n=n/2;
    }
    while(!isEmpty())
    {
        printf("%d", tops(s));
        pop(s);

    }



    return 0;


}

void push(int *s, int x)
{

    if(isFull())
    {
        printf("Stack overflow");
        return;
    }

        else
        {
            top=top+1;
            *(s+top)=x;
            return;
        }
}
void pop(int *s)
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
void display(int *s)
{
    printf("Stack:");
    for(int i=0; i<=top; i++)
    {
        printf("%d\t", *(s+i));
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
int tops(int *s)
{
    return s[top];
}


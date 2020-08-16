#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define MAXSTACKS 10;
void push(int);
void pop();
int isEmpty();
int isFull();
void display();
int s[MAX];
int top[MAXSTACKS];
int

int main()
{
    int op, x, n;
    int num=MAX/n;
    printf("Enter number of stacks:");
    scanf("%d", &n);
    int top[MAXSTACKS], beg[MAXSTACKS];

    for(int i=0; i<n; i++)
    {
        top[i]=beg[i]=num*i-1;
    }
    printf("**menu**\n");
    printf("1.push\n2.pop\n3.Display\n4.exit\n");

    while(1)
    {
        printf("Enter op:");
        scanf("%d", &op);

        switch(op)
        {
        case 1:
            printf("enter element:");
            scanf("%d", &x);
            push(x);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);


        }
    }
    return 0;

}
void push(int no, int x)
{

    if(isFull(no, top, beg))
    {
        printf("Stack overflow");
        return;
    }

        else
        {
            top[no]=top[no]+1;
            s[top[no]]=x;
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
        printf("%d\t", s[i]);
    }
}
int isEmpty()
{
    if(top[no]==beg[no])
        return 1;
    else
        return 0;
}
int isFull(int no, int top[], int beg[])
{
    if(top[no]==beg[no+1])
        return 1;
    else
        return 0;
}


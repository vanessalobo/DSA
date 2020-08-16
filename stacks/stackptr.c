#include<stdio.h>
#include<stdlib.h>
#define MAX 100
void push(int*, int);
void pop(int*);
int isEmpty();
int isFull();
void display(int*);

int top=-1;

int main()
{
    int op, x;
    printf("**menu**\n");
    printf("1.push\n2.pop\n3.Display\n4.exit\n");
        int *s;
        s=(int*)calloc(MAX, sizeof(int));

    while(1)
    {
        printf("Enter op:");
        scanf("%d", &op);


        switch(op)
        {
        case 1:
            printf("enter element:");
            scanf("%d", &x);
            push(s, x);
            break;
        case 2:
            pop(s);
            break;
        case 3:
            display(s);
            break;
        case 4:
            exit(0);
        }
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


#include<stdio.h>
#include<stdlib.h>

typedef struct stack* STACK;
struct stack
{
    int *arr;
    int MAX;
    int top;


};
STACK  s;

STACK init(int capacity)
{
    STACK s=(STACK)malloc(sizeof(struct stack));
    s->top=-1;
    s->MAX=capacity;

    s->arr=(int *)calloc(s->MAX, sizeof(int));
    return s;
}
int isEmpty()
{
    if(s->top==-1)
    {
        return 1;
    }
    else
        return 0;
}
int isFull()
{
    if(s->top==s->MAX)
    {
        return 1;
    }
    else
        return 0;
}

void push(int x)
{

    if(isFull())
        printf("Stack overflow\n");
    else{

    s->top=s->top+1;
    s->arr[s->top]=x;
    //printf("%d", s.top);
    }

}
void pop()
{
    if(isEmpty())
        printf("Stack underflow\n");
    else
    {
        //printf("the popped element is %d", s.arr[s.top]);
        s->top--;
        //printf("%d", s.top);
    }
}
void display()
{
    if(!isEmpty())
    {
        printf("Stack:");
        for(int i=0; i<=(s->top); i++)
            printf("%d\t", s->arr[i]);
    }
}


void main()
{
    //typedef struct TACK;

    s=init(10);
    int op, x;


    printf("**menu**\n");
    while(1)
    {


    printf("enter options:1.push\n2.pop\n3.display\n4.exit\n");
    scanf("%d", &op);
    switch(op)
    {
    case 1:
        printf("Enter element:");
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
}

#include<stdio.h>
#include<stdlib.h>
#define MAX 10




typedef struct
{
    char data[MAX];
    int top;


}STACK;
void display(STACK *s);
int isEmpty(STACK *s);
int isFull(STACK *s);
void push(STACK *s, char x);
void pop(STACK *s);
void init(STACK *s)
{
    s->top=-1;


}
int isEmpty(STACK *s)
{
    if(s->top==-1)
    {
        return 1;
    }
    else
        return 0;
}
int isFull(STACK *s)
{
    if(s->top==MAX-1)
    {
        return 1;
    }
    else
        return 0;
}

void push(STACK *s, int x)
{
    if(isFull(STACK *s))
        printf("Stack overflow\n");
    else{

    s->top=s->top+1;
    s->data[s->top]=x;
    //printf("%d", s.top);
    }

}
void pop(STACK *s)
{
    if(isEmpty(STACK *s))
        printf("Stack underflow\n");
    else
    {
        //printf("the popped element is %d", s.data[s.top]);
        s->top--;
        //printf("%d", s.top);
    }
}
void display(STACK *s)
{
    if(!isEmpty(STACK *s))
    {
        printf("Stack:");
        for(int i=0; i<=(s->top); i++)
            printf("%d\t", s->data[i]);
    }
}


void main()
{
    //typedef struct stack STACK;
    STACK s;
    int op, x;
    s.top=-1;

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
        push(&s, x);
        break;
    case 2:
        pop(&s);
        break;
    case 3:
        display(&s);
        break;
    case 4:
        exit(0);
    }
    }
}

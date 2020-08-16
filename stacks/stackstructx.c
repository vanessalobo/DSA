#include<stdio.h>
#include<stdlib.h>
#define MAX 10
typedef struct stack *STACK;
struct stack
{
int data[MAX];
int top;

};
STACK init()
{
    STACK s;
    s=(STACK)malloc(sizeof(struct stack));
    s->top=-1;
    return s;
}
int isFull(STACK s)
{
    if(s->top==MAX)
        return 1;
    else
        return 0;
}
int isEmpty(STACK s)
{
    if(s->top==-1)
        return 1;
    else
        return 0;
}
void push(STACK s, int x)
{
    if(isFull(s))
    {
        printf("full");
        return;
    }
    s->top++;
    s->data[s->top]=x;

}
int pop(STACK s)
{
    int ele=s->data[s->top];
    s->top--;
    return ele;
}
void display(STACK s)
{
    printf("stack");
    for(int i=0; i<=s->top; i++)
        printf("%d", s->data[i]);

}
void main()
{
    STACK s=init();
    push(s, 1);
    push(s, 2);
    push(s, 3);
    display(s);
    printf("popped=%d", pop(s));
    display(s);
}



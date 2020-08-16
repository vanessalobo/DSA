#include<stdio.h>
#include<stdlib.h>
#define MAX 10
typedef struct
{
    int datas[MAX];
    int top;


}STACK;
//STACK *s;
typedef struct
{
	int dataq[MAX];
	int front;
	int rear;

}QUEUE;
QUEUE *q;
void initq()
{
	q->front=-1;
	q->rear=-1;
}
int isEmpty()
{
	if(q->front==-1 && q->rear==-1)
		return 1;
	else
		return 0;
}
void push(STACK *s, int x)
{
    if(s->top==MAX-1)
        printf("Stack overflow\n");
    else{

    s->top=s->top+1;
    s->datas[s->top]=x;
    //printf("%d", s.top);
    }

}
int pop(STACK *s)
{
    int x;
    if(s->top==-1)
        printf("Stack underflow\n");
    else
    {
        x=s->datas[s->top];
        s->top--;
        //printf("%d", s.top);
    }
    return x;
}
void insert(int x)
{
	if(q->rear=MAX-1)
	{
		printf("Queue overflow\n");
		return;
	}
	else if(isEmpty())
	{
		q->front=0;
		q->rear=0;
	}
	else
	{
		q->rear=q->rear+1;

	}
	q->dataq[q->rear]=x;
}

int del()
{
    int x;
	if(isEmpty())
	{
		printf("Queue underflow\n");
		return 999;
	}
	else if(q->front==q->rear)
	{
	    x=q->dataq[q->front];
		q->front=-1;
		q->rear=-1;
	}
	else{
        x=q->dataq[q->front];
        q->front=q->front+1;
	}
	return x;

}

void display()
{
    for(int i=q->front; i<=q->rear; i++)
        printf("%d\t", q->dataq[i]);
}
void main()
{
    int n, x;

    initq();
    printf("enter number of queue elements:");
    scanf("%d", &n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &x);
        insert(x);
    }
    STACK *s;
    s->top=-1;
    while(!isEmpty())
    {
        push(s, del());

    }
    display();
    while(s->top!=-1)
    {
        printf("%d", pop(s));
    }

}

#include<stdio.h>
#include<stdlib.h>
#define MAX 10
typedef struct queue *Q;
struct queue
{
int data[MAX];
int front;
int rear;
};
Q init()
{
    Q q;
    q=(Q)malloc(sizeof(struct queue));
    q->front=-1;
    q->rear=-1;
    return q;
}
int isEmpty(Q q)
{
    if(q->front==-1 && q->rear==-1)
        return 1;
    else
        return 0;
}
int isFull(Q q)
{
    if(q->rear==MAX)
        return 1;
    else
        return 0;

}
void insert(Q q, int x)
{
    if(isFull(q))
    {
        printf("full");
        return;

    }
    if(isEmpty(q))
    {
        q->front=0;
        q->rear=0;
        q->data[q->rear]=x;
        return;
    }
    q->rear++;
    q->data[q->rear]=x;

}
int del(Q q)
{
    int ele;
    if(isEmpty(q))
    {
        printf("empty");
        return;
    }
    else if(q->rear==q->front)
    {
        ele=q->data[q->front];
        q->rear=-1;
        q->front=-1;
        return ele;
    }
    else
    {
        ele=q->data[q->front];
        q->front++;
        return ele;
    }

}
void display(Q q)
{
    printf("queue");
    for(int i=q->front; i<=q->rear; i++)
        printf("%d", q->data[i]);
}
void main()
{
    Q q;
    q=init();
    insert(q, 1);
    insert(q, 2);
    insert(q, 3);
    display(q);
    printf("del=%d", del(q));
    display(q);

}

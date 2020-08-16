#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int q[MAX], front=-1, rear=-1;
void enqueue(int);
void dequeue();
int isFull();
int isEmpty();
void display();

int main()
{
    int op, x;
    printf("**menu**\n");
    while(1)
    {
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your choice:");
        scanf("%d", &op);
        switch(op)
        {
        case 1:
            printf("Enter element:");
            scanf("%d", &x);
            enqueue(x);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        }
    }
}
void enqueue(int x)
{
    //printf("front before=%d", front);
   //printf("rear before=%d", rear);
    //printf("full=%d", isFull());
    if(isFull())
        return;
    else if(isEmpty())
    {
        front++;
        rear++;
        q[rear]=x;
        //printf("%d", q[rear]);


    }
    else
    {
        rear++;
        q[rear]=x;
        //printf("%d", q[rear]);


    }


    //printf("front=%d", front);
    //printf("rear=%d", rear);
}
void dequeue()
{
    if(isEmpty())
    {
        return;
    }
    else if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
        front=front+1;
}
int isEmpty()
{
    if(front==-1 && rear==-1)
        return 1;
    else
        return 0;
}
int isFull()
{
    if(rear==MAX-1)
        return 1;
    else
        return 0;
}
void display()
{
    printf("Queue:");
    for(int i=front; i<=rear; i++)
    {
        printf("%d\t", q[i]);
    }
}

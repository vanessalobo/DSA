#include<stdio.h>
#include<stdlib.h>
#define MAX 5
typedef struct
{
	int data[MAX];
	int front;
	int rear;

}QUEUE;
QUEUE *q;

void init()
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
int isFull()
{
	if((q->rear)==MAX-1)
		return 1;
	else
		return 0;
}


void insert(int x)
{
	if(isFull())
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
	q->data[q->rear]=x;
}

void delete()
{
	if(isEmpty())
	{
		printf("Queue underflow\n");
		return;
	}
	else if(q->front==q->rear)
	{
		q->front=-1;
		q->rear=-1;
	}
	else
		q->front=q->front+1;
}
void display()
{
	printf("Queue:");
	for(int i=q->front; i<=q->rear; i++)
	{
		printf("%d\t", q->data[i]);
	}
}
int main()
{
	q=(QUEUE*)calloc(MAX, sizeof(QUEUE));
	init();

	int op;
	int x;
	while(1)
	{
		printf("1.insert\n2.delete\n3.display\n4.exit\n");
		scanf("%d", &op);
		switch(op)
		{
			case 1:
			printf("Enter element:");
			//fflush(stdin);
			scanf("%d", &x);
			insert(x);
			break;
			case 2:
			delete();
			break;
			case 3:
			display();
			break;
			case 4:
			free(q);
			exit(0);

		}


	}


}

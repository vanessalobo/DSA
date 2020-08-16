#include<stdio.h>
#include<stdlib.h>
#define MAX 5
typedef struct
{
	char data[MAX];
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
	if((q->rear+1)%MAX==q->front)
		return 1;
	else
		return 0;
}


void insert(char x)
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
		q->rear=(q->rear+1)%MAX;

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
		q->front=(q->front+1)%MAX;
}
void display()
{
	printf("Queue:");
	for(int i=q->front; i<=q->rear; i++)
	{
		printf("%c\t", q->data[i]);
	}
}
int main()
{
	q=(QUEUE*)calloc(MAX, sizeof(QUEUE));
	init();

	int op;
	char x;
	while(1)
	{
		printf("1.insert\n2.delete\n3.display\n4.exit\n");
		scanf("%d", &op);
		switch(op)
		{
			case 1:
			printf("Enter element:");
			fflush(stdin);
			scanf("%c", &x);
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

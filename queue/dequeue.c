#include<stdio.h>
#include<process.h>
#include<stdlib.h>
#define MAX 30

typedef struct
{
	int data[MAX];
	int rear,front;
}QUEUE;

void initialize(QUEUE *p);
int empty(QUEUE *p);
int full(QUEUE *p);
void enqueueR(QUEUE *p,int x);
void enqueueF(QUEUE *p,int x);
int dequeueF(QUEUE *p);
int dequeueR(QUEUE *p);
void print(QUEUE *p);

void main()
{
	int i,x,op,n;
	QUEUE *q;
	q=(QUEUE*)calloc(MAX, sizeof(QUEUE));

	initialize(q);

	while(1)
	{
		printf("\n1.Insert(rear)\n2.Insert(front)\n3.Delete(rear)\n4.Delete(front)");
		printf("\n5.Print\n6.Exit\n\nEnter your choice:");
		scanf("%d",&op);

		switch(op)
		{

			case 1: printf("\nEnter element to be inserted:");
					scanf("%d",&x);

					if(full(q))
					{
						printf("\nQueue is full!!");
						exit(0);
					}

					enqueueR(q,x);
					break;

			case 2: printf("\nEnter the element to be inserted:");
					scanf("%d",&x);

					if(full(q))
					{
						printf("\nQueue is full!!");
						exit(0);
					}

					enqueueF(q,x);
					break;

			case 3: if(empty(q))
					{
						printf("\nQueue is empty!!");
						exit(0);
					}

					x=dequeueR(q);
					printf("\nElement deleted is %d\n",x);
					break;

			case 4: if(empty(q))
					{
						printf("\nQueue is empty!!");
						exit(0);
					}

					x=dequeueF(q);
					printf("\nElement deleted is %d\n",x);
					break;

			case 5: print(q);
					break;

			case 6:
                exit(0);
		}
	}
}

void initialize(QUEUE *P)
{
	P->rear=-1;
	P->front=-1;
}

int empty(QUEUE *P)
{
	if(P->rear==-1)
		return(1);

	return(0);
}

int full(QUEUE *P)
{
	if((P->rear+1)%MAX==P->front)
		return(1);

	return(0);
}

void enqueueR(QUEUE *P,int x)
{
	if(empty(P))
	{
		P->rear=0;
		P->front=0;
		P->data[0]=x;
	}
	else
	{
		P->rear=(P->rear+1)%MAX;
		P->data[P->rear]=x;
	}
}

void enqueueF(QUEUE *P,int x)
{
	if(empty(P))
	{
		P->rear=0;
		P->front=0;
		P->data[0]=x;
	}
	else
	{
		P->front=(P->front-1+MAX)%MAX;
		P->data[P->front]=x;
	}
}

int dequeueF(QUEUE *P)
{
	int x;

	x=P->data[P->front];

	if(P->rear==P->front)	//delete the last element
		initialize(P);
	else
		P->front=(P->front+1)%MAX;

	return(x);
}

int dequeueR(QUEUE *P)
{
	int x;

	x=P->data[P->rear];

	if(P->rear==P->front)
		initialize(P);
	else
		P->rear=(P->rear-1+MAX)%MAX;

	return(x);
}

void print(QUEUE *P)
{
	if(empty(P))
	{
		printf("\nQueue is empty!!");
		exit(0);
	}

	int i;
	i=P->front;

	while(i!=P->rear)
	{
		printf("\n%d",P->data[i]);
		i=(i+1)%MAX;
	}

	printf("\n%d\n",P->data[P->rear]);
}

#include<stdio.h>
#include<stdlib.h>
#define MAX 20
typedef struct queue *que;
struct queue
{
	int data[MAX];
	int front;
	int rear;

};
void search(que q, int);

que init()
{
    que q=(que)malloc(sizeof(struct queue));
	q->front=-1;
	q->rear=-1;
	return q;
}

void insert(que q, int x)
{
	if(q->rear==MAX-1)
	{
		printf("Queue overflow\n");
		return;
	}
	else if(q->front==-1 && q->rear==-1)
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

int delete(que q)
{
	if(q->front==-1 && q->rear==-1)
	{
		printf("Queue underflow\n");
		return -999;
	}
	else if(q->front==q->rear)
	{
		int a=q->data[q->front];
		q->front=-1;
		q->rear=-1;
		return a;
	}
	else
	{
		int a=q->data[q->front];
		q->front=q->front+1;
		return a;
	}
}
void display(que q)
{
	printf("Queue:");
	for(int i=q->front; i<=q->rear; i++)
	{
		printf("%d\t", q->data[i]);
	}
}
int main()
{
	que q=init();

	int ele;
	printf("Enter element:");
	scanf("%d", &ele);

	int op, x;
	printf("1.insert\n2.exit\n");

	do
	{
		scanf("%d", &op);
		printf("enter queue element:");
		scanf("%d", &x);
		insert(q,x);




	}
	while(op!=2);
	search(q, ele);
	printf("original queue:\n");
	display(q);

	return 0;



}
void search(que q, int ele)
{
	que temp=q;
	int flag;
	//init(temp);
	while(temp->front!=-1 && temp->rear!=-1)
	{
		int x;
		x=delete(q);
		//insert(&temp, x);

		if(ele==x)
		{
			printf("FOUND");
			return;

		}



	}
	printf("not found");





}

#include<stdio.h>
#include<stdlib.h>
#define MAX 5
typedef struct
{
	int data[2*MAX];
	int front1;
	int rear1;
	int front2;
	int rear2;

}QUEUE;
QUEUE *q;

void init()
{
	q->front1=-1;
	q->rear1=-1;
	q->front2=MAX-1;
	q->rear2=MAX-1;
}
int isEmpty1()
{
	if(q->front1==-1 && q->rear1==-1)
		return 1;
	else
		return 0;
}
int isEmpty2()
{
	if(q->front2==-1 && q->rear2==-1)
		return 1;
	else
		return 0;
}
int isFull1()
{
	if((q->rear1+1)%MAX==q->front1)
		return 1;
	else
		return 0;
}
int isFull2()
{
	if((q->rear2+1)%(2*MAX)==q->front2)
		return 1;
	else
		return 0;
}


void insert1(int x)
{
	if(isFull1())
	{
		printf("Queue 1 overflow\n");
		return;
	}
	else if(isEmpty1())
	{
		q->front1=0;
		q->rear1=0;
	}
	else
	{
		q->rear1=(q->rear1+1)%MAX;

	}
	q->data[q->rear1]=x;
}

void delete1()
{
	if(isEmpty1())
	{
		printf("Queue 1 underflow\n");
		return;
	}
	else if(q->front1==q->rear1)
	{
		q->front1=-1;
		q->rear1=-1;
	}
	else
		q->front1=(q->front1+1)%MAX;
}
void display1()
{
	printf("Queue 1:");
	for(int i=(q->front1)+1; i<=q->rear1; i++)
	{
		printf("%d\t", q->data[i]);
	}
}
void insert2(int x)
{
	if(isFull2())
	{
		printf("Queue 2 overflow\n");
		return;
	}
	else if(isEmpty2())
	{
		q->front2=MAX-1;
		q->rear2=MAX-1;
	}
	else
	{
		q->rear2=(q->rear2+1)%(2*MAX);

	}
	q->data[q->rear2]=x;
}

void delete2()
{
	if(isEmpty2())
	{
		printf("Queue 2 underflow\n");
		return;
	}
	else if(q->front2==q->rear2)
	{
		q->front2=-1;
		q->rear2=-1;
	}
	else
		q->front2=(q->front2+1)%(2*MAX);
}
void display2()
{
	printf("Queue 2:");
	for(int i=(q->front2)+1; i<=q->rear2; i++)
	{
		printf("%d\t", q->data[i]);
	}
}
int main()
{
    int sno, op, x;
    q=(QUEUE*)calloc(2*MAX, sizeof(QUEUE));

    while(1)
    {
        printf("Enter 1 for Queue 1 and 2 for Queue 2, 0 to exit:");
        scanf("%d", &sno);
        switch(sno)
        {
        case 0:
            exit(0);

        case 1:
            printf("Enter 1.insert\n2.delete\n3.display\n");
            scanf("%d", &op);
            switch(op)
            {
            case 1:
                printf("Enter element to be inserted:");
                scanf("%d", &x);
                insert1(x);
                break;
            case 2:
                delete1();
                break;
            case 3:
                display1();
                break;

            }
            break;
        case 2:
            printf("Enter 1.insert\n2.delete\n3.display\n");
            scanf("%d", &op);
            switch(op)
            {
            case 1:
                printf("Enter element to be inserted:");
                scanf("%d", &x);
                insert2(x);
                break;
            case 2:
                delete2();
                break;
            case 3:
                display2();
                break;

            }
            break;



        }

    }

}

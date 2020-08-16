#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int pop1();
int pop2();
void push1(int);
void push2(int);
void display1();
void display2();
int *s;
int top1=-1;
int top2=MAX-1;
void main()
{
    int sno, op, x;
    s=(int*)calloc(2*MAX, sizeof(int));

    while(1)
    {
        printf("Enter 1 for stack 1 and 2 for stack 2, 0 to exit:");
        scanf("%d", &sno);
        switch(sno)
        {
        case 0:
            exit(0);

        case 1:
            printf("Enter 1.push\n2.pop\n3.display\n");
            scanf("%d", &op);
            switch(op)
            {
            case 1:
                printf("Enter element to be pushed:");
                scanf("%d", &x);
                push1(x);
                break;
            case 2:
                printf("The element popped from stack 1: %d", pop1());
                break;
            case 3:
                display1();
                break;

            }
            break;
        case 2:
            printf("Enter 1.push\n2.pop\n3.display\n");
            scanf("%d", &op);
            switch(op)
            {
            case 1:
                printf("Enter element to be pushed:");
                scanf("%d", &x);
                push2(x);
                break;
            case 2:
                printf("The element popped from stack 2: %d", pop2());
                break;
            case 3:
                display2();
                break;

            }
            break;



        }

    }

}
void push1(int x)
{
    if(top1==MAX-1)
        printf("Stack 1 overflow\n");
    else
    {
            top1++;
            s[top1]=x;
    }


}
void push2(int x)
{
    if(top2==2*MAX-1)
        printf("Stack 2 overflow\n");
    else
    {
            top2++;
            s[top2]=x;
    }
}
int pop1()
{
    if(top1==-1){
        printf("Stack 1 underflow");
        return -99;
    }
    else{
        return s[top1--];
    }

}
int pop2()
{
    if(top2==MAX-1){
        printf("Stack 2 underflow");
        return -99;
    }
    else{
        return s[top2--];
    }

}
void display1()
{
    printf("STACK 1:\n");
    for(int i=0; i<=top1; i++)
        printf("%d\t", s[i]);
}
void display2()
{
    printf("STACK 2:\n");
    for(int i=MAX; i<=top2; i++)
        printf("%d\t", s[i]);
}

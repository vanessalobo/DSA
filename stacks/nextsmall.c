#include<stdio.h>
#include<stdlib.h>
#define MAX 100
void push(int);
void pop();
int isEmpty();
int isFull();
void display();
int tops();
int *s;
int top=-1;

int main()
{
    int count;

    s=(int*)calloc(MAX, sizeof(int));
    int a[100], n, i, k;
    printf("Enter limit:");
    scanf("%d", &n);
    printf("enter elements:\n");
    //fflush(stdin);
    for(i=0; i<n; i++)
        scanf("%d", &a[i]);
    push(a[0]);
    printf("enter k:");
    scanf("%d", &k);
    count=0;
    for(i=1; i<n; i++)
    {

        while(!isEmpty()&&(tops()<a[i])&&count<k)
        {
            pop(s);
            count++;
        }
        push(a[i]);

    }
    display();









    return 0;


}

void push(int x)
{

    if(isFull())
    {
        printf("Stack overflow");
        return;
    }

        else
        {
            top=top+1;
            *(s+top)=x;
            return;
        }
}
void pop()
{
    if(isEmpty())
    {
        printf("Stack underflow");
        return;
    }

    else
    {
        top--;
        return;

    }

}
void display()
{
    printf("Stack:");
    for(int i=0; i<=top; i++)
    {
        printf("%d\t", *(s+i));
    }
}
int isEmpty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}
int isFull()
{
    if(top==MAX-1)
        return 1;
    else
        return 0;
}
int tops()
{
    return s[top];
}


#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct{
char arr[MAX];
int size;
int tos;
}Stack;


void initialize(Stack *s ,int n)
{s->size=n;
s->tos = -1;
return;
}

int isEmpty(Stack *s)
{
if(s->tos == -1){
printf("Stack Underflow \n");
return 1;}
else
return 0;
}

int isFull(Stack *s)
{
if(s->tos == (s->size - 1)){
printf("Stack Overflow \n");
return 1;}
else
return 0;
}

void push(Stack *s, char val)
{
if(isFull(s) == 1){
return;}
s->arr[++(s->tos)] = val;
}

void pop(Stack *s)
{
if(isEmpty(s) == 1)
return;
else{
printf("%c was poped out \n", s->arr[(s->tos)--]);
}
}

void display(Stack *s)
{
for(int i=s->tos; i>=0; i--)
printf("%c \n",s->arr[i]);
}

void main()
{
int k,flag=1;
char ch;
printf("Enter the size of the stack =");
scanf("%d",&k);
Stack *s1;
initialize(s1,k);
while(1){
printf("Menu:1.Display\n2.Push\n3.Pop\n4.exit\n");
scanf("%d",&flag);
switch(flag)
{
case 1: display(s1);
        break;
case 2: printf("Enter the value:");
        fflush(stdin);
        scanf("%c",&ch);
        scanf("%c",&ch);
        push(s1,ch);
        break;
case 3: pop(s1);
break;
case 4:exit(0);


}
}
}



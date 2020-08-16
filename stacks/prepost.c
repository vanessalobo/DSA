#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
void push(char);
void pop();

int isEmpty();
int isFull();
void display();
char tops();
char *s;
int top=-1;

int main()
{


    s=(char*)calloc(MAX, sizeof(char));
    char pre[100], post[100], a;
    int i, j=0;
    printf("Enter prefix expression:");
    scanf("%s", pre);
    for(i=0;i<strlen(pre);i++)
   {
      if(pre[i]=='+'||pre[i]=='-'||pre[i]=='*'||pre[i]=='/')
      {
         push(pre[i]);
      }
      else
      { post[j++]=pre[i];
        while(!isEmpty()&&(s[top]=='@'))
        {
            a=tops();
            pop();
            post[j++]=tops();
            pop();
        }
        push('@');
      }
   }
   printf("Postfix expression: %s\n", post);













    return 0;


}

void push(char x)
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
char tops()
{
    return s[top];
}

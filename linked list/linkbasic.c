#include<stdio.h>
#include<stdlib.h>
typedef struct node* nodeptr;
struct node
{
    int data;
    nodeptr next;
};

nodeptr getnode()
{
    nodeptr temp;
    temp=(nodeptr)malloc(sizeof(struct node));
    return temp;
}
int isEmpty(nodeptr head)
{
    return (head?1:0);
}
void insertFront(nodeptr head, int x)
{
    nodeptr temp;
    temp=getnode();
    temp->data=x;
    temp->next=NULL;
    temp->next=head; //insert at beginning
    head=temp;
    printf("%d", temp->data);
    printf("x");


}
void insertLast(nodeptr head, int x)
{

    nodeptr temp, rear;
    temp=getnode();
    temp->data=x;
    temp->next=NULL;
    if(isEmpty(head))
        head=temp;
    else
    {

        rear=head;
        while(rear!=NULL)
            rear=rear->next;
        rear->next=temp;

    }
    printf("%d", temp->data);
    printf("x");

}
void print(nodeptr head)
{
    nodeptr temp;
    temp=getnode();

        // cant lose address of head so we need a temp variable
    temp=head;
    while(temp!=NULL)
    {
        printf("%d\n", temp->data);
        temp=temp->next;


    }

}
int main()
{
    nodeptr head;
    int n, x;

    //printf("number of elements:");

    //scanf("%d", &n);
    insertFront(head, 2);
    insertFront(head, 3);
    insertLast(head, 4);
    insertLast(head, 5);
    print(head);
}

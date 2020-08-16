#include<stdio.h>
#include<stdlib.h>
typedef struct node* nodeptr;
struct node
{

    int data;
    nodeptr next;
};

nodeptr getnode(int x)
{
    nodeptr temp;
    temp=(nodeptr)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
    return temp;
}
void push(nodeptr *front, nodeptr *rear, int x)
{
    nodeptr temp=getnode(x);

    if(*front==NULL && *rear==NULL)
    {
        *front=temp;
        *rear=temp;
        temp->next=NULL;
        return;




    }
    nodeptr ptr=*rear;
    ptr->next=temp;
    *rear=temp;
    temp->next=NULL;





}
void pop(nodeptr *front, nodeptr *rear)
{
    nodeptr temp;
    if(*front==NULL)
    {
        printf("stck underflow");
        return;
    }
    temp=*front;
    printf("popped element=%d", temp->data);
    *front=temp->next;
    free(temp);
    return;



}


void display(nodeptr *front, nodeptr *rear)
{
    printf("queue:\n");
    nodeptr temp=*front;
    while(temp!=*rear)
    {

        printf("%d\t",  temp->data);
        temp=temp->next;
    }
    printf("%d", temp->data);

    printf("done");
    return;
}
void main()
{
    nodeptr front=NULL;
    nodeptr rear=NULL;
    push(&front, &rear, 2);
    push(&front, &rear, 3);
    push(&front, &rear, 4);
    //printf("top=%d", topdisp(top));
    //top=pop(top);
    //printf("top=%d", topdisp(top));
    display(&front, &rear);

     pop(&front, &rear);
pop(&front, &rear);

    display(&front, &rear);


}


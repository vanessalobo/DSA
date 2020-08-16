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
nodeptr push(nodeptr top, int x)
{
    nodeptr temp=getnode(x);

    if(top==NULL)
    {
        top=temp;
        //temp->next=NULL;

        return top;


    }
    temp->next=top;
    top=temp;
    return top;




}
nodeptr pop(nodeptr top)
{
    nodeptr temp;
    if(top==NULL)
    {
        printf("stck underflow");
    }
    temp=top;
    printf("popped element=%d", top->data);
    top=temp->next;
    free(temp);
    return top;



}
int isEmpty(nodeptr top)
{
    return top?1:0;
}
int topdisp(nodeptr top)
{
    return top->data;
}
void display(nodeptr top)
{
    printf("stack:\n");
    nodeptr temp=top;
    while(temp->next!=NULL)
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
    nodeptr top=NULL;
    top=push(top, 2);
    top=push(top, 3);
    top=push(top, 4);
    //printf("top=%d", topdisp(top));
    //top=pop(top);
    //printf("top=%d", topdisp(top));
    display(top);
    printf("top=%d", topdisp(top));
    top=pop(top);
    printf("top=%d", topdisp(top));
    display(top);


}


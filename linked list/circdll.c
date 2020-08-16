#include<stdio.h>
#include<stdlib.h>
typedef struct node* nodeptr;
struct node
{

    int data;
    nodeptr prev;
    nodeptr next;
};

nodeptr getnode(int x)
{
    nodeptr temp;
    temp=(nodeptr)malloc(sizeof(struct node));
    temp->data=x;
    temp->prev=NULL;
    temp->next=NULL;

}
nodeptr insertFront(nodeptr last, int x)
{
    nodeptr temp;
    temp=getnode(x);
    if(last=NULL)
    {
        last=temp;
        temp->next=temp;
        temp->prev=temp;
    }
    else
    {
        nodeptr first;
        first=last->next;
        temp->next=first;
        first->prev=temp;
        last->next=temp;
        temp->prev=last;
    }
    printf("done");
    return last;


}
nodeptr insertBack(nodeptr last, int x)
{
    nodeptr temp;
    temp=getnode(x);
    if(last=NULL)
    {
        last=temp;
        temp->next=temp;
        temp->prev=temp;
    }
    else
    {
        temp->next=last->next;
        last->next->prev=temp;
        last->next=temp;
        temp->prev=last;
        
        
        last=temp;
    }
    printf("done");
    return last;
}
nodeptr deleteFront(nodeptr last)
{
    int x;
    nodeptr first;

    first=last->next;
    x=first->data;
    nodeptr temp=first;
    first=temp->next;
    last->next=first;
    first->prev=last;
    free(temp);
    printf("deleted=%d", x);


}
nodeptr deleteLast(nodeptr last)
{
    int x;
    nodeptr temp;
    x=temp->data;
    temp=last;
    last=temp->prev;
    last->next=temp->next;
    temp->next->prev=last;
    free(temp);



    printf("deleted=%d", x);
}
void display(nodeptr last)
{
    nodeptr first=last->next;
    while(first!=last)
    {
        printf("%d\t", first->data);
        first=first->next;
    }
    printf("%d\t", first->data);
}
void main()
{
    nodeptr last=NULL;
    last=insertFront(last, 1);
    last=insertBack(last, 2);
    //display(last);
}

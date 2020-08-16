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
int length(nodeptr head)
{
    nodeptr temp;
    int count=0;
    temp=head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}

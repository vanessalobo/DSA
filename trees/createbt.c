#include<stdio.h>
#include<stdlib.h>
typedef struct node* nodeptr;
struct node
{
    int data;
    nodeptr lchild;
    nodeptr rchild;
};
nodeptr getnode()
{
    nodeptr temp=(nodeptr)malloc(sizeof(struct node));
    temp->lchild=NULL;
    temp->rchild=NULL;
    return temp;
}
nodeptr create(int item)
{
    int x;

    if(item!=-1)
    {
        nodeptr temp=getnode();
        temp->data=item;
        printf("Enter lchild of %d:", item);
        scanf("%d", &x);
        temp->lchild=create(x);

        printf("enter rchild of %d:", item);
        scanf("%d", &x);
        temp->rchild=create(x);
        return temp;


    }
    else
        return NULL;
}
void main()
{
    int item;
    nodeptr root=NULL;
    printf("creating tree\n");
    printf("enter root");
    scanf("%d", &item);
    root=create(item);
}

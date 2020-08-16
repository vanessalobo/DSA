#include<stdio.h>
#include<stdlib.h>
typedef struct node* tnp;
struct tnode
{
    int data;
    nodeptr lchild;
    nodeptr rchild;
};
typedef struct snode* snp;
struct snode
{

    tnp t;
    snp next;
};
void push(tnp *t, snp *top)
{
    snp newtnode=(snp)malloc(sizeof(struct snode));
    newtnode->t=t;
    newtnode->next=*top;
    *top=newtnode;




}
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



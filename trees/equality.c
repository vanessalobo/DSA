#include<stdio.h>
#include<stdlib.h>
typedef struct node* nodeptr;
struct node
{
    int data;
    nodeptr lchild;
    nodeptr rchild;
};
int isEqual(nodeptr root1, nodeptr root2)
{
    return ((!root1&&!root2)||(root1 && root2 && (root1->data==root2->data)&& isEqual(root1->lchild, root2->lchild)&& isEqual(root1->rchild, root2->rchild)));
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
void main()
{
    int item;
    nodeptr root1=NULL;
    nodeptr root2=NULL;
    printf("creating tree 1\n");
    printf("enter root 1");
    scanf("%d", &item);
    root1=create(item);
    printf("creating tree 2\n");
    printf("enter root 2");
    scanf("%d", &item);
    root2=create(item);
    printf("equality=%d", isEqual(root1, root2));
}

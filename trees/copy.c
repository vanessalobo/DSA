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
nodeptr copy(nodeptr root)
{
    if(root==NULL)
    {
        return NULL;
    }
    nodeptr temp=getnode();
    temp->data=root->data;
    temp->lchild=copy(root->rchild);
    temp->rchild=copy(root->lchild);
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
void inorder(nodeptr root)
{

    if(root!=NULL)
    {
        inorder(root->lchild);
        printf("%d\t", root->data);
        inorder(root->rchild);

    }
}
void main()
{
    int item;
    nodeptr root=NULL;
    nodeptr root2;
    printf("creating tree 1\n");
    printf("enter root 1");
    scanf("%d", &item);
    root=create(item);
      printf("copying\n");
   root2=copy(root);
   inorder(root2);
}


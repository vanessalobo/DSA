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
void inorder(nodeptr root)
{

    if(root!=NULL)
    {
        inorder(root->lchild);
        printf("%d\t", root->data);
        inorder(root->rchild);

    }
}
void preorder(nodeptr root)
{

    if(root!=NULL)
    {
        printf("%d\t", root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }

}
void postorder(nodeptr root)
{

    if(root!=NULL)
    {

        postorder(root->lchild);
        postorder(root->rchild);
        printf("%d\t", root->data);
    }

}
void main()
{
    int item;
    nodeptr root=NULL;
    printf("creating tree\n");
    printf("enter root");
    scanf("%d", &item);
    root=create(item);
    printf("inorder traversal");
    inorder(root);
    printf("preorder traversal");
    preorder(root);
    printf("postorder traversal");
    postorder(root);
}



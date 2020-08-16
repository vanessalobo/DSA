#include<stdio.h>
#include<stdlib.h>
typedef struct node* nodeptr;
struct node
{
    int data;
    nodeptr rchild;
    nodeptr lchild;
};
nodeptr getnode(int x)
{

    nodeptr temp;
    temp=(nodeptr)malloc(sizeof(struct node));
    temp->data=x;
    temp->rchild=NULL;
    temp->lchild=NULL;
    return temp;

}
nodeptr insert(nodeptr root, int x)
{

    nodeptr temp=getnode(x);
    if(root==NULL)
        root=temp;
    else if(x<=root->data)
    {
        root->lchild=insert(root->lchild, x);
    }
    else
    {
        root->rchild=insert(root->rchild, x);
    }
    return root;
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
int min(nodeptr root)
{
    nodeptr current=root;
    while(current->lchild!=NULL)
    {
        current=current->lchild;
    }
    return current->data;

}
int max(nodeptr root)
{
    nodeptr current=root;
    while(current->rchild!=NULL)
    current=current->rchild;
    return current->data;

}
int maxrec(nodeptr root)
{
    if(root==NULL)
        printf("empty");
    else if(root->rchild==NULL)
        return root->data;
    else
        return maxrec(root->rchild);
}
int minrec(nodeptr root)
{
    if(root==NULL)
        printf("empty");
    else if(root->lchild==NULL)
        return root->data;
    else
        return minrec(root->lchild);
}
/*int arr[100];
void minmaxin(nodeptr root)
{
    static int i=0;
    if(root)
    {
        minmaxin(root->lchild);
        arr[i]=root->data;
        i++;
        minmax(root->rchild);
    }




}*/
void main()
{

    nodeptr root=NULL;
    root=insert(root, 3);
    root=insert(root, 1);
    root=insert(root, 2);
    root=insert(root, 4);
    inorder(root);
   printf("min =%d", min(root));
   printf("min rec =%d", minrec(root));
    printf("max rec =%d", maxrec(root));
     printf("max=%d", max(root));
}

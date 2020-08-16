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
int itersearch(nodeptr root, int key)
{
    while(root!=NULL)
    {
        if(root->data==key)
            return 1;
        else if(key<root->data)
        {
            root=root->lchild;

        }
        else
            root=root->rchild;
    }
    return 0;
}
nodeptr insertit(nodeptr root, int x)
{
    nodeptr temp=getnode(x);

    if(root==NULL)
    {
        root=temp;
        return root;
    }
    nodeptr parent=NULL;
    nodeptr cur=root;
    while(cur!=NULL)
    {
        parent=cur;

        if(x<cur->data)
        {
            cur=cur->lchild;
        }
        else
            cur=cur->rchild;
    }
    if(x<parent->data)
        parent->lchild=temp;
    else
        parent->rchild=temp;

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
int search(nodeptr root, int key)
{

    if(root==NULL)
    {

        return 0;
    }
    else if(root->data==key)
    return 1;
    else if(key<root->data)

    {
        return search(root->lchild, key);

    }
    else
        return search(root->rchild, key);

}
void main()
{

    nodeptr root=NULL;
    root=insert(root, 3);
    root=insert(root, 1);
    root=insert(root, 2);
    root=insert(root, 4);
    root=insertit(root, 7);
    root=insertit(root, 6);
    inorder(root);
    if(search(root, 4))
        printf("found");
    else
        printf("not found");
    if(itersearch(root, 4))
        printf("found");
    else
        printf("not found");
}

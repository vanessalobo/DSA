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
int search(nodeptr root, int ele)
{
    static int t=0;
    if(root!=NULL)
    {
        if(root->data==ele){
            t++;
            return t;
        }
            if(t==0)search(root->lchild, ele);
    if(t==0)search(root->rchild, ele);
    }


}
int leafnodes(nodeptr root)
{

    if(root==NULL)
        return 0;
    else if(root->rchild==NULL && root->lchild==NULL)
        return 1;

  else return leafnodes(root->lchild) + leafnodes(root->rchild);

}
int nodes(nodeptr root)
{
    if(root==NULL)
        return 0;
    else
        return (1+nodes(root->lchild)+nodes(root->rchild));
}
int max(int a, int b)
{
    if(a>b)
        return a;
    else return b;
}
int height(nodeptr root)
{
    if(root==NULL)
        return 0;
    return (1+ max(height(root->lchild), height(root->rchild)));
}
int ancestors(nodeptr root, int ele)
{
    if(root==NULL)
        return 0;
    else if(root->data==ele)
        return 1;
    else{
        if(ancestors(root->lchild, ele)|| ancestors(root->rchild, ele))
            {
                printf("%d\t", root->data);
                return 1;
            }
        }
        return 0;


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
    int ele;
    printf("creating tree 1\n");
    printf("enter root 1");
    scanf("%d", &item);
    root=create(item);
    printf("enter ele");
    scanf("%d", &ele);
    if(search(root, ele))
        printf("found");
    else printf("not found");
    printf("count =%d", nodes(root));
    printf("height=%d", height(root));
    printf("leaf nodes=%d", leafnodes(root));
    int anc;
    scanf("%d", &anc);
    if(ancestors(root, anc))
        printf("yay");
    else
        printf("nay");
}


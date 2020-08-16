#include<stdio.h>
#include<stdlib.h>
#define MAX 10
typedef struct node* nodeptr;
struct node
{
    int data;
    nodeptr lchild;
    nodeptr rchild;
    int flag;
};
typedef struct stk* stack;
struct stk
{
    nodeptr tree[MAX];
    int top;


};
typedef struct queue* que;
struct queue
{
    nodeptr treeq[MAX];
    int front;
    int rear;
};
que initq()
{
    que q=(que)malloc(sizeof(struct queue));
    q->front=-1;
    q->rear=-1;
    return q;
}
int isEmptyq(que q)
{
    if(q->front==-1 && q->rear==-1)
        return 1;
    else
        return 0;
}
void insert(que q, nodeptr item)
{
    if(isEmptyq(q))
    {
        q->front=0;
        q->rear=0;
        q->treeq[0]=item;
    }
    else
    {
        q->rear++;
        q->treeq[q->rear]=item;
    }

}
void deleteq(que q)
{
    if(q->rear==q->front)
    {
        q->rear=-1;
        q->front=-1;
    }
    else
    {
        q->front--;
    }
}
nodeptr frontq(que q)
{
    printf("%d\t", q->front);
    return q->treeq[q->front];
}

stack init()
{
    stack s;
    s=(stack)malloc(sizeof(struct stk));
    s->top=-1;
    return s;

}
void push(stack s, nodeptr item)
{
   s->top++;
   s->tree[s->top]=item;


}
int isEmpty(stack s)
{
    if(s->top==-1)
        return 1;
    else
        return 0;
}
void pop(stack s)
{
    if(isEmpty(s)){
        printf("empty");
        return;
    }
    s->top--;


}
nodeptr tops(stack s)
{
    int x=s->top;
    return s->tree[x];
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
void inorder(nodeptr root)
{
    nodeptr cur;
    stack s;
    s=init();
    //printf("done");
    if(root==NULL)
    {
        printf("empty tree");
        return;
    }
    cur=root;
    int done=0;
    //printf("done");
    while(!done)
    {
        while(cur!=NULL)
        {
            //printf("done");
            push(s, cur);
            cur=cur->lchild;
            //printf("hsjh");
        }
        printf("empty=%d\n", isEmpty(s));
        if(!isEmpty(s))
        {
            //printf("doneREE");
            cur=tops(s);
            pop(s);

            printf("%d\t", cur->data);
            cur=cur->rchild;
        }
        else
            done=1;
    }
}
void preorder(nodeptr root)
{
    nodeptr cur;
    stack s=init();
    if(root==NULL){
        printf("empty");
        return;
    }
    push(s, root);
    while(!isEmpty(s))
    {
        cur=tops(s);
        pop(s);
        printf("%d\t", cur->data);
        if(cur->rchild)
            push(s, cur->rchild);
        if(cur->lchild)
            push(s, cur->lchild);
    }



}
void postorder(nodeptr root)
{
    stack s=init();
    nodeptr cur;
if(root==NULL)
{
    printf("empty");
    return;

}
    cur=root;
    while(1)
    {
        while(cur!=NULL)
        {
            push(s, cur);
            (s->tree[s->top])->flag=1;
            cur=cur->lchild;
        }
        while(tops(s)->flag<0)
        {
            cur=tops(s);
            pop(s);
            printf("%d\t", cur->data);
            if(isEmpty(s))
                return;
        }
        cur=tops(s);
        cur=cur->rchild;
        (s->tree[s->top])->flag=-1;
    }

}
void qdisplay(que q)
{
    for(int i=q->front; i<=q->rear; i++)
    {

        printf("%d", q->treeq[i]->data);
    }


}
void level(nodeptr root)
{
    que q=initq();
    if(root==NULL)
    {
        printf("empty");
        return;
    }
    insert(q, root);
    while(!isEmptyq(q))
    {
        nodeptr temp=frontq(q);
        deleteq(q);
        printf("%d\t", temp->data);
        if(temp->lchild)
            insert(q, temp->lchild);
        printf("%d", frontq(q));
        if(temp->rchild)
            insert(q, temp->rchild);
        //printf("%d", frontq(q));

        printf("queue");
        qdisplay(q);
    }
}
void insertnode(nodeptr root, char dir[10], int ele)
{
    nodeptr temp, cur, parent;

    temp=getnode();
    temp->data=ele;
    parent=NULL;
    cur=root;
    int i=0;//direction
    while(cur && dir[i])
    {
        parent=cur;
        if(dir[i]=='L')
            cur=cur->lchild;
        else
            cur=cur->rchild;
        i++;
    }
    //not possible insertion
    if((cur!=NULL)||(dir[i]!='\0'))
    {
        printf("not possible");
        free(temp);
        return;
    }
    if(dir[i-1]=='L')
        parent->lchild=temp;
    else
        parent->rchild=temp;
}

void main()
{
    int item;
    nodeptr root=NULL;

    printf("creating tree 1\n");
    printf("enter root 1");
    scanf("%d", &item);
    root=create(item);
    inorder(root);
    preorder(root);
    postorder(root);
    printf("level\n");
    level(root);
    printf("insertion");
    insertnode(root, "LLR", 6);
    inorder(root);
}


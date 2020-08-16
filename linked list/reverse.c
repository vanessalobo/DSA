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
    temp->next=NULL;
    temp->data=x;


    return temp;
}
nodeptr insertBack(nodeptr head, int x)
{
    //int x;
    nodeptr rear;
    rear=head;
    nodeptr temp=getnode(x);
    //printf("Enter data:");
    //scanf("%d", &(temp->data));
    //temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else

    {
        while((rear->next)!=NULL)
        {
            rear=rear->next;
        }
        rear->next=temp;


    }
    return head;



}
nodeptr reverse(nodeptr head)
{
    nodeptr prev, cur, next;
    cur=head;
    prev=next=NULL;
    if(cur->next==NULL)
    {
        return head;
    }
    while(cur!=NULL)
    {
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    head=prev;
    return head;
}
void display(nodeptr head)
{
    nodeptr temp;
    if(head==NULL)
    {
        printf("List is empty");
        return;
    }
   temp=head;
   printf("The list elements are:\n");
   while(temp!=NULL)
   {
       printf("%d\t", temp->data);
       temp=temp->next;

   }

}
void main()
{
    nodeptr head=NULL;
    head=insertBack(head, 1);
    head=insertBack(head, 2);
    head=insertBack(head, 3);
    head=insertBack(head, 4);
    head=insertBack(head, 5);
    display(head);
    head=reverse(head);
    display(head);

}

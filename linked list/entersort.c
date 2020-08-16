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
    temp->data=x;
    temp->next=NULL;
    return temp;
}
int length(nodeptr head)
{
    nodeptr temp;
    int count=0;
    temp=head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}
nodeptr insertBefore(nodeptr head, int ele, int x)
{
    nodeptr temp=getnode(x);
    nodeptr preptr, ptr;

    if(head==NULL)
    {
        head=temp;

    }
    else if(length(head)==1)
    {
        temp->next=head;
        head=temp;

    }
    else
    {
        ptr=head;
        while(ptr->data!=ele)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        temp->next=ptr;
        preptr->next=temp;
    }
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
nodeptr enter(nodeptr head, int x)
{
    nodeptr ptr=head;
    if(head==NULL)
    {
        nodeptr temp=getnode(x);
        head=temp;
        temp->next=NULL;
        return head;
    }
    while(ptr->next!=NULL)
    {
        printf("data:%d\n", ptr->data);
        if(x<ptr->data)
        {
            head=insertBefore(head, ptr->data, x);
            return head;
        }
        //printf("done");
        ptr=ptr->next;
    }
    nodeptr temp=getnode(x);
    ptr->next=temp;
    temp->next=NULL;
    return head;

}
void main()
{

    nodeptr head=NULL;
    head=enter(head, 2);
    head=enter(head, 5);
    head=enter(head, 3);
    head=enter(head, 4);
    display(head);

}

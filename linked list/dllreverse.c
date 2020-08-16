#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node* nodeptr;
struct node
{

    char data[10];
    nodeptr prev;
    nodeptr next;
};

nodeptr getnode(char x[10])
{
    nodeptr temp;
    temp=(nodeptr)malloc(sizeof(struct node));

    strcpy(temp->data, x);
    temp->prev=NULL;
    temp->next=NULL;

}
nodeptr insertBack(nodeptr head, char x[10])
{
    nodeptr temp=getnode(x);
    nodeptr ptr;
    if(head==NULL)
    {
        head=temp;
        //return head;
    }
    else
    {
        ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
        temp->prev=ptr;
    }
    return head;
}
nodeptr reverse(nodeptr head)
{
  nodeptr curr=head;
  nodeptr temp=NULL;
  while(curr!=NULL)
  {
      temp=curr->prev;
      curr->prev=curr->next;
      curr->next=temp;
      curr=curr->prev;
  }
  head=temp;
  return head;

}
nodeptr rev(nodeptr head)
{

}
void display(nodeptr head)
{
    nodeptr temp=head;
    while(temp!=NULL)
    {
        printf("%s\t", temp->data);
        temp=temp->next;
    }
}
void main()
{
    nodeptr head=NULL;
    insertBack(head, "abc");
    insertBack(head, "pqr");
    insertBack(head, "xyz");
    display(head);
    head=reverse(head);
    display(head);
}


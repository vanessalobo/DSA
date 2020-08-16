#include<stdio.h>
#include<stdlib.h>
typedef struct node* nodeptr;
struct node
{

    int data;
    nodeptr prev;
    nodeptr next;
};
nodeptr head=NULL;
nodeptr getnode(int x)
{
    nodeptr temp;
    temp=(nodeptr)malloc(sizeof(struct node));
    temp->data=x;
    temp->prev=NULL;
    temp->next=NULL;

}
void insertFront(int x)
{

    nodeptr temp;
    temp=getnode(x);
    if(head==NULL)
    {
        head=temp;
        return;
    }
    else
    {
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
}
void insertBack(int x)
{
    nodeptr temp=getnode(x);
    nodeptr ptr;
    if(head==NULL)
    {
        head=temp;
        return;
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
}
void insertPosFront(int pos, int x)
{
    nodeptr temp=getnode(x);
    nodeptr ptr=head;
    if(head==NULL)
    {
        head=temp;
        return;
    }
    else
    {
        for(int i=1; i<pos-1; i++)
            ptr=ptr->next;
            printf("%d", ptr->data);
        temp->next=ptr->next;
        (ptr->next)->prev=temp;
        printf("%d", ptr->next->prev->data);
        temp->prev=ptr;
        ptr->next=temp;

    }
}
void display()
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
int deleteBack()
{
    nodeptr ptr;
    ptr=head;
    while(ptr->next!=NULL)
        ptr=ptr->next;
    int ele=ptr->data;
    nodeptr preptr;
    preptr=ptr->prev;
    preptr->next=NULL;

    free(ptr);

    return ele;

}
int deleteFront()
{
    nodeptr ptr;
    ptr=head;
    int ele=ptr->data;
    head=ptr->next;
    head->prev=NULL;

    free(ptr);
    return ele;




}
void main()
{
    insertFront(2);
    insertFront(3);
    insertFront(4);
    insertBack(1);
    insertBack(5);
    insertPosFront(3, 10);
    display();
    printf("deleted: %d", deleteBack());
    printf("deleted: %d", deleteFront());
    display();
}

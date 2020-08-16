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
nodeptr insertBack(nodeptr head, int x)
{
    //int x;
    nodeptr rear;
    rear=head;
    nodeptr temp=getnode(x);


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
nodeptr removeDuplicates(nodeptr root)
{
    nodeptr temp=root;

    while(temp->next!=NULL)
    {
        if(temp->data==temp->next->data)
        temp->next=temp->next->next;
        temp=temp->next;

    }
    return root;
 // your code goes here
}
void main()
{
    nodeptr head=NULL;
   head=insertBack(head, 1);
   head=insertBack(head, 1);
   head=insertBack(head, 2);
   head=insertBack(head, 3);
   head=insertBack(head, 3);
   display(head);
    head=removeDuplicates(head);
    display(head);

}

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
void swap(nodeptr a, nodeptr b)
{
    int temp;
    temp=a->data;
    a->data=b->data;
    b->data=temp;

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

nodeptr sort(nodeptr head)
{
    nodeptr *a, *b;
    int n=length(head);
    *a=head;
    *b=NULL;

    for(int i=0; i<n; i++)
    {
        *a=head;
           *b=*a;
        *a=*a->next;
        for(int j=0; j<n-i-1; j++)
        {
            if(*a->data < *b->data)
            {
                swap(&a, &b);
            }
            *b=*a;
        *a=*a->next;


        }
    }
    return head;
}
void main()
{
    nodeptr head=NULL;
    head= insertBack(head, 4);
    head=insertBack(head, 2);
    //display(a);
    head=insertBack(head, 3);

    head=insertBack(head, 1);
    display(head);
    head=sort(head);
    display(head);

}

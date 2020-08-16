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

    nodeptr temp=getnode(x);

    if(head==NULL)
    {
        head=temp;

    }
    else

    {
        nodeptr ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;


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
   //printf("%d\t", temp->data);
   while(temp!=NULL)
   {



       printf("%d\t", temp->data);
       temp=temp->next;


   }

}
/*int isMember(nodeptr head, int x)
{
    nodeptr temp;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->data==x)
            return 1;
        temp=temp->next;
    }
    return 0;
}*/
nodeptr mergeSort(nodeptr h1, nodeptr h2)
{
    nodeptr h3;
    if(h1==NULL)
        return h2;
    if(h2==NULL)
        return h1;
    while(h1!=NULL && h2!=NULL)
    {
        if(h1->data<h2->data)
        {
            h3=insertBack(h3, h1->data);
            h1=h1->next;
        }
        else
        {

            h3=insertBack(h3, h2->data);
            h2=h2->next;
        }


    }
    display(h3);
    while(h1!=NULL)
    {
        h3=insertBack(h3, h1->data);
        h1=h1->next;
    }
    while(h2!=NULL)
    {
        h3=insertBack(h3, h2->data);
        h2=h2->next;
    }
    return h3;
}
void main()
{
    nodeptr h1=NULL;
    nodeptr h2=NULL;
    h1=insertBack(h1, 1);
    h1=insertBack(h1, 2);
    h1=insertBack(h1, 3);
    h1=insertBack(h1, 3);
    h2=insertBack(h2, 2);
    h2=insertBack(h2, 2);
    h2=insertBack(h2, 4);
    h2=insertBack(h2, 4);
    h2=insertBack(h2, 5);
    h2=insertBack(h2, 6);
    display(h1);
    display(h2);
    nodeptr h3;
    h3=mergeSort(h1, h2);
    display(h3);

}

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
int isMember(nodeptr head, int x)
{
    nodeptr temp=head;
    while(temp!=NULL)
    {

        if(x==temp->data){
        return 1;

        }
        temp=temp->next;
    }
    return 0;
}

nodeptr insertBack(nodeptr head, int x)
{
    //int x;
    nodeptr rear;

    nodeptr temp=getnode(x);

    if(head==NULL)
    {
        head=temp;
        return head;
    }
    else

    {
        rear=head;
        while((rear->next)!=NULL)
        {
            rear=rear->next;
        }
        rear->next=temp;
        return head;


    }



}
void superset(nodeptr headsup, nodeptr headset)
{
    nodeptr tempsup, tempset;
    tempset=headset;
    tempsup=headsup;
    int flag=0;
    while(tempset!=NULL)
    {
        if(!isMember(tempsup, tempset->data)){
            flag=1;
            break;
        }
        tempset=tempset->next;

    }
    if(flag)
    {
        printf("not superset");
    }
    else
        printf("superset");

}
void subset(nodeptr headsub, nodeptr headset)
{
    nodeptr tempsub, tempset;
    int flag=0;
    while(tempsub!=0)
    {
        if(!isMember(tempset, tempsub->data))
        {
            flag=1;
            break;
        }
        tempsub=tempsub->next;
    }
    if(flag)
        printf("not subset");
    else printf("subset");

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
   //printf("The list elements are:\n");
   while(temp!=NULL)
   {
       printf("%d\t", temp->data);
       temp=temp->next;

   }

}
void main()
{

    nodeptr head1=NULL;
    nodeptr head2=NULL;
    printf("set elements:");

    head1=insertBack(head1, 1);
    head1=insertBack(head1, 2);
    head1=insertBack(head1, 3);
    head1=insertBack(head1, 4);
    display(head1);
    printf("set superset elements:");
    head2=insertBack(head2, 5);
    head2=insertBack(head2, 1);
    head2=insertBack(head2, 2);
    head2=insertBack(head2, 7);
    head2=insertBack(head2, 4);
    head2=insertBack(head2, 3);
    display(head2);
    superset(head2, head1);
    subset(head1, head2);
}

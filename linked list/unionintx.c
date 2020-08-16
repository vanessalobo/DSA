#include<stdio.h>
#include<stdlib.h>
typedef struct node* nodeptr;
struct node
{

    int data;
    nodeptr next;
};
nodeptr getnode()
{
    nodeptr temp;
    temp=(nodeptr)malloc(sizeof(struct node));
    return temp;
}
nodeptr insertBack(nodeptr head, int x)
{
    //int x;
    nodeptr rear;
    rear=head;
    nodeptr temp=getnode();

    temp->data=x;
    temp->next=NULL;
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
int isMember(nodeptr head, int x)
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
}
nodeptr Union(nodeptr a, nodeptr b)
{
    nodeptr u=NULL;


    nodeptr temp;

    temp=a;
    while(temp!=NULL)
    {
        u=insertBack(u, temp->data);
        //display(c);
        temp=temp->next;
    }
    //display(c);
    temp=b;
    while(temp!=NULL)
    {
        if(!isMember(a, temp->data))
        {
            u=insertBack(u, temp->data);

        }
        temp=temp->next;
    }

   /* temp=first;
    first=first->next;
    free(temp); */
    return u;
}
nodeptr intersection(nodeptr a, nodeptr b)
{
    nodeptr i=NULL;
    nodeptr tempa=a;
    nodeptr tempb=b;
    while(tempa!=NULL)
    {
        if(isMember(tempb, tempa->data))
        {
            i=insertBack(i, tempa->data);

        }
        tempa=tempa->next;
    }
    return i;


}
void main()
{
    nodeptr a=NULL, b=NULL;

   a= insertBack(a, 2);
    a=insertBack(a, 3);
    //display(a);
    a=insertBack(a, 4);

    b=insertBack(b, 3);
    b=insertBack(b, 4);
    b=insertBack(b, 5);
    printf("list 1:");
    display(a);
    printf("list 2:");
    display(b);
    printf("union:");
    nodeptr x=Union(b, a);
    display(x);
    printf("Intersection:");
    display(intersection(a, b));



}

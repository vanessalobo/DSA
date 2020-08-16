#include<stdio.h>
#include<stdlib.h>
typedef struct node* nodeptr;
struct node
{
    int data;
    nodeptr next;
};
nodeptr last=NULL;
nodeptr getnode()
{
    nodeptr temp;
    temp=(nodeptr)malloc(sizeof(struct node));
    return temp;
}
int length()
{
    nodeptr head=last->next;
    int count=1;
    //temp=last;
    while(head!=last)
    {
        count++;
        head=head->next;
    }
    return count;
}

void insertFront()
{

    nodeptr temp=getnode();
    printf("Enter data:");
    scanf("%d", &(temp->data));

    temp->next=NULL;
    if(last==NULL)
    {

        temp->next=temp;
        last=temp;

    }
    else
    {

        temp->next=last->next;
        last->next=temp;

    }
}
void insertBack()
{
    //int x;

    nodeptr temp=getnode();
    printf("Enter data:");
    scanf("%d", &(temp->data));
    temp->next=NULL;
    if(last==NULL)
    {
        temp->next=temp;
        last=temp;
    }
    else

    {
        temp->next=last->next;
        last->next=temp;
        last=temp;


    }



}
void insertPosFront()
{
    nodeptr temp=getnode();
    nodeptr ptr;



    int pos;
    printf("Enter position:");
    scanf("%d", &pos);
    printf("Enter data:");
    scanf("%d", &(temp->data));
    temp->next=NULL;

    if(last==NULL)
    {
        last=temp;
        temp->next=temp;
    }
    else
    {
        ptr=last->next;
        for(int i=1; i<pos-1; i++)
        {
            ptr=ptr->next;
        }
        printf("%d", ptr->data);
        temp->next=ptr->next;
        ptr->next=temp;

    }

}

int deleteFront()
{
    nodeptr ptr=last->next;
    int ele;
    if(last==NULL)
    {
        printf("List is empty");
        return -999;
    }

    else if(ptr->next==ptr)
    {
        ele=ptr->data;
        free(ptr);
        last=NULL;
        return ele;
    }
    else
    {


        ele=ptr->data;
        last->next=ptr->next;
        free(ptr);

        return ele;
    }



}
int deleteBack()
{
    nodeptr ptr, temp;
    ptr=last->next;
    temp=last;

    int ele;
    if(last==NULL)
    {
        printf("List is empty");
        return -999;
    }
    else if(temp->next==temp)
    {

        ele=temp->data;
        last=NULL;
        free(temp);
        return ele;
    }
    else
    {
       while(ptr->next!=last)
       {
           ptr=ptr->next;
       }
       printf("%d", temp->data);
       ele=temp->data;
       last=ptr;
       last->next=temp->next;
       return ele;


    }
}

void display()
{
    nodeptr temp;
    if(last==NULL)
    {
        printf("List is empty");
        return;
    }
   temp=last->next;
   printf("The list elements are:\n");
   printf("%d\t", temp->data);
   while(temp!=last)
   {


       temp=temp->next;
       printf("%d\t", temp->data);


   }

}
void main()      //main() starts
{
        int choice;
        while(1){
                printf("\n***SINGLE LINKED LIST OPERATIONS:****\n");
                printf("\n                MENU                             \n");
                printf("---------------------------------------\n");
                printf("\n 1.Insert at the beginning      \n");
                printf("\n 2.Insert at the end  \n");
                printf("\n 3. Insert at specified position Front\n");
                printf("\n 4. Insert at specified position Back(not working)\n");
                printf("\n 5. Insert after element    \n");
                printf("\n 6.insert before element(dont choose)    \n");
                printf("\n 7.Delete front \n");
                printf("\n 8.Delete back\n");
                printf("\n 9.Delete from specified position front (dont)   \n");
                printf("\n 10.Exit       \n");
                printf("\n--------------------------------------\n");
                printf("Enter your choice:\t");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                                        insertFront();
                                        break;
                        case 2:
                                        insertBack();
                                        break;
                        case 3:

                            insertPosFront();
                            break;
                        case 4:
                            //insertPosBack();
                            break;
                        case 5: //insertAfter();
                        break;
                        case 6:
                            printf("Deleted element= %d", deleteFront());
                            break;
                        case 7:
                            printf("Deleted element= %d", deleteBack());
                            break;
                        case 8:
                            //printf("Deleted element= %d", deletePosFront());
                            break;

                        case 9:
                            printf("Length=%d", length());
                            break;
                        case 10: display();
                        break;
                        case 11:
                            //insertBefore();
                            break;
                        case 12:
                            //printf("deleted element=%d", deletePosFront());
                            break;


                        default: exit(0);

                }//end of switch()*
        }

}//


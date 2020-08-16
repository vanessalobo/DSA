#include<stdio.h>
#include<stdlib.h>
typedef struct node* nodeptr;
struct node
{

    int data;
    nodeptr next;
};
nodeptr head=NULL;
nodeptr getnode()
{
    nodeptr temp;
    temp=(nodeptr)malloc(sizeof(struct node));


    return temp;
}
int length()
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

void insertFront()
{
    int x;
    nodeptr temp=getnode();
    printf("Enter data:");
    scanf("%d", &x);
    temp->data=x;
    temp->next=NULL;
    if(head==NULL)
    {

        head=temp;

    }
    else
    {

        temp->next=head;
        head=temp;
    }
}
void insertBack()
{
    //int x;
    nodeptr rear;
    rear=head;
    nodeptr temp=getnode();
    printf("Enter data:");
    scanf("%d", &(temp->data));
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

    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        ptr=head;
        for(int i=1; i<pos-1; i++)
        {
            ptr=ptr->next;
        }
        temp->next=ptr->next;
        ptr->next=temp;

    }

}
void insertPosBack()
{
    nodeptr temp=getnode();
    nodeptr ptr;



    int pos;
    printf("Enter position:");
    scanf("%d", &pos);
    printf("Enter data:");
    scanf("%d", &(temp->data));
    temp->next=NULL;

    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        ptr=head;
        pos=length()-pos+2;

        for(int i=1; i<pos-1; i++)
        {
            ptr=ptr->next;
        }
        //printf("%d", ptr->data);

        temp->next=ptr->next;
        ptr->next=temp;


    }

}
void insertAfter()
{
    int ele;
    nodeptr ptr;
    nodeptr temp=getnode();
    printf("Enter element after which to insert");
    scanf("%d", &ele);
    printf("enter data:");
    scanf("%d", &(temp->data));
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        ptr=head;
        while(ptr->data!=ele)
        {
            ptr=ptr->next;
        }
        temp->next=ptr->next;
        ptr->next=temp;
    }


}
void insertBefore()
{
    nodeptr temp=getnode();
    nodeptr preptr, ptr;
    int ele;
    printf("Enter element before which insert:");
    scanf("%d", &ele);
    printf("Enter data:");
    scanf("%d", &temp->data);
    if(head==NULL)
    {
        head=temp;
        return;
    }
    else if(length()==1)
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

}

int deleteFront()
{
    nodeptr ptr;
    int ele;
    if(head==NULL)
    {
        printf("List is empty");
        return -999;
    }

    else
    {
        ptr=head;
        head=head->next;
        ele=ptr->data;
        free(ptr);
        return ele;
    }



}
int deleteBack()
{
    nodeptr ptr, preptr;
    int ele;
    if(head==NULL)
    {
        printf("List is empty");
        return -999;
    }
    else if(length()==1)
    {
        ptr=head;
        ele=ptr->data;
        head=NULL;
        free(ptr);
        return ele;
    }
    else
    {
        ptr=head;

        while(ptr->next!=NULL)
        {
            preptr=ptr;
            ptr=ptr->next;

        }
        ele=ptr->data;
        free(ptr);
        preptr->next=NULL;
        return ele;

    }
}
int deletePosFront()
{
    nodeptr delptr=NULL;
    nodeptr ptr;
    int ele, pos;
    if(head==NULL)
    {
        printf("Empty list");
        return -999;
    }
    else if(pos==1)
    {
        ptr=head;
        head=head->next;
        ele=ptr->data;
        free(ptr);
        return ele;
    }
    else
    {
        ptr=head;
        //preptr=NULL;
        printf("Enter position:");
        scanf("%d", &pos);
        for(int i=1; i<pos-1; i++)
        {
            //preptr=ptr;
            ptr=ptr->next;
        }
        //printf("%d", ptr->data);
        //printf("%d", preptr->data);
        delptr=ptr->next;
        ptr->next=delptr->next;
        //preptr->next=ptr->next;
        ele=delptr->data;
        free(delptr);

        return ele;
    }

}
int deleteAfter()
{
    nodeptr ptr, postptr;
    printf("Enter element");
    int x;
    scanf("%d", &x);
    if(head==NULL)
    {
        printf("Empty list");
    }
    else
    {
        ptr=head;
        while(ptr->data!=x)
        {

            ptr=ptr->next;

        }

        postptr=ptr->next;
        int ele=postptr->data;
        ptr->next=postptr->next;
return ele;

    }

}
void deleteEle()
{
    nodeptr ptr, preptr;
    ptr=head;
    preptr=NULL;
    printf("Enter element");
    int x;
    scanf("%d", &x);
    if(head==NULL)
    {
        printf("Empty list");
        //return -999;
    }
    else if(ptr->data==x)
    {
        head=head->next;
        free(ptr);

    }
    else
    {

        while(ptr->data!=x)
        {
            preptr=ptr;

            ptr=ptr->next;

        }

        preptr->next=ptr->next;
        free(ptr);
        //int ele=ptr->data;
//ptr->next=postptr->next;
//return ele;
    }


}
void deleteAllEle()
{
    nodeptr ptr, preptr;
    ptr=head;
    preptr=NULL;
    printf("Enter element");
    int x;
    scanf("%d", &x);
    if(head==NULL)
    {
        printf("Empty list");
        //return -999;
    }

    else
    {
        nodeptr temp=ptr;
        while(temp->data==x)
        {
            ptr=temp;
        head=temp->next;

        temp=temp->next;

        free(ptr);
        //ptr=head;



        }

        while(temp!=NULL)
        {
            preptr=temp;

            temp=temp->next;
            if(temp->data==x)
            {
                preptr->next=temp->next;
                temp=temp->next;
                //free(ptr);
            }

        }

        //preptr->next=ptr->next;
        //int ele=ptr->data;
//ptr->next=postptr->next;
//return ele;
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
                            insertPosBack();
                            break;
                        case 5: insertAfter();
                        break;
                        case 6:
                            printf("Deleted element= %d", deleteFront());
                            break;
                        case 7:
                            printf("Deleted element= %d", deleteBack());
                            break;
                        case 8:
                            printf("Deleted element= %d", deleteAfter());
                            break;

                        case 9:
                            printf("Length=%d", length());
                            break;
                        case 10: display();
                        break;
                        case 11:
                            insertBefore();
                            break;
                        case 12:
                            printf("deleted element=%d", deletePosFront());
                            break;
                        case 13:
                           deleteEle();
                           break;
                        case 14:
                            deleteAllEle();
                            break;


                        default: exit(0);

                }//end of switch()*
        }

}//

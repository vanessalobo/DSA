#include<stdio.h>
#include<stdlib.h>
typedef struct{
    char name[20];
    int roll;
    float cgpa;

}STUDENT;
void read(STUDENT *p)
{
    printf("enter name");
    scanf("%s", p->name);
    printf("enter roll");
    scanf("%d", &p->roll);
    printf("enter cgpa");
    scanf("%f", &p->cgpa);
    printf("\n");
}
void display(STUDENT *p)
{
    printf("name");
    scanf("%s", p->name);
    printf("roll");
    scanf("%d", p->roll);
    printf("cgpa");
    scanf("%f", p->cgpa);
    printf("\n");
}
void sort(STUDENT *p, int n)
{
    STUDENT temp;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n-i-1; j++)

        {
            if(((p+j)->roll)>((p+j+1)->roll))
            {
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }

}
void main()
{
    STUDENT *p;
    int n;
    printf("enter elem");
    scanf("%d", &n);
    p=(STUDENT *)calloc(n, sizeof(STUDENT));
    int i;
    //for(i=0; i<n; i++)
        read(p);
    //for(i=0; i<n; i++)
        display(p);
    sort(p, n);
    for(i=0; i<n; i++)
        display(p+i);
}

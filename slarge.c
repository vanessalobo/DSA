#include<stdio.h>
#include<stdlib.h>
int slarge(int a[], int);

void main()
{
    int *a, n, i;
    printf("enter limit");
    scanf("%d", &n);
    a=(int *)calloc(n, sizeof(int));
    for(i=0; i<n; i++)
        scanf("%d", (a+i));
    for(i=0; i<n; i++)
        printf("%d", *(a+i));
    //slarge(a, n);
    printf("slarge=%d", slarge(a, n));



}
int slarge(int a[], int n)
{
    int l, s;
    l=s=a[0];
    for(int i=0; i<n; i++)
    {

        if(a[i]>l)
            {
                s=l;
                ld=a[i];
            }
        else if(a[i]>s && a[i]<l)
            s=a[i];

    }
    return s;
}

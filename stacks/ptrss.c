#include<stdio.h>
void main()
{

    int a=10;
    int *p;
    int **q;
    p=&a;
    q=&p;
    int ***r=&q;
    printf("%d", *p);
    printf("%p\n", &p);
    printf("%d\n", **q);
    printf("%p\n", &q);
    printf("%p\n", *r);
    printf("%d\n", ***r);


}

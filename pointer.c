#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
    int a=10;
    int *p;
    int **q;
    int ***r;
    p=&a;
    q=&p;
    r=&q;
    printf("a=%d", a);
    printf("from p=%d", *p);
    printf("from q=%d", **q);
    printf("from r=%d", ***r);
    //char str1="abc";
    //char str2[10];
    //strcpy(str2, str1);
    char x='a';
    printf("ascii of a=%d", x);
    //printf("%s", str2);
    char d='1';
    printf("%d", d-'0');

}

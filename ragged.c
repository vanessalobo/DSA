#include<stdio.h>
#include<stdlib.h>
void main()
{

    int n, i, m, j;
    printf("enter the number of rows:");
    scanf("%d", &m);
    int **ptr;
    ptr=(int **)calloc(m+1, sizeof(int *));
    for(i=0; i<m; i++)
    {


        printf("ENTER no of elements in %d row", i+1);
        scanf("%d", &n);
        ptr[i]=(int *)calloc(n+1, sizeof(int));
        printf("eneter elem");
        for(j=1; j<=n; j++)
            scanf("%d", &ptr[i][j]);
        ptr[i][0]=n;
        printf("size of row %d=%d", i+1, ptr[i][0]);

    }
    ptr[m]=NULL;
    for(i=0; i<m; i++)
    {
        for(j=1; j<=*ptr[i]; j++)
            printf("%d\t", ptr[i][j]);
        printf("\n");
    }
    for(i=0; i<m; i++)
        free(ptr[i]);
    free(ptr);


}

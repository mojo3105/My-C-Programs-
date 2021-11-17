#include<stdio.h>

void main()
{
    int a[10], min, temp, i, n, j;
    printf("Enter the size of array\n");
    scanf("%d",&n);
    printf("Enter the elements of array of above size\n");
    for(i=0;i<n;i++)
    {
         scanf(" %d",&a[i]);
    } 
    printf("\nRunning selection sort...");
    for(i=0; i<n-1; i++)
    {
        min=i;
        for(j=i+1 ;j<n; j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            } 
        }
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
    printf("\nThe output after selection sort is \n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
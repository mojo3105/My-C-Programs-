#include<stdio.h>

void main()
{
    int a[100],key,i,n,j;
    printf("Enter the size of array\n");
    scanf("%d",&n);
    printf("\nEnter the elements of array of above size\n");
    for(i=0;i<n;i++)
    {
         scanf(" %d",&a[i]);
    } 
    for(i=1;i<=n-1;i++)
    {
        key=a[i];
        j=i-1;
        while(j>=0 && a[j]>key)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
    printf("The output after insertion sort is \n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
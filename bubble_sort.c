#include<stdio.h>

void main()
{
    int arr[100], n,i,temp;
    printf("Enter the size of array\n");
    scanf("%d",&n);
    printf("\nEnter the elements of array of above size\n");
    for(i=0;i<n;i++)
    {
         scanf(" %d",&arr[i]);
    } 
    for(i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("The output after bubble sort is \n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}
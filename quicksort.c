#include<stdio.h>

int partition(int a[], int low, int high)
{
    int pivot =a[low];
    int i=low+1;
    int j=high;
    int temp;
    do
    {
        while (a[i]<=pivot)
        {
            i++;
        }
        while(a[j]>pivot)
        {
            j--;
        }
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }while(i<j);
    temp=a[low];
    a[low]=a[j];
    a[j]=temp;
    return j;
}

void quicksortf(int a[], int low, int high)
{
    int partitionindex;
    if(low<high)
    {
        partitionindex= partition(a,low,high);
        quicksortf(a, low, partitionindex-1);
        quicksortf(a, partitionindex+1, high);
    }
}

void main()
{
    int a[10], temp, i, n, j, low, high, mid;
    printf("Enter the size of array\n");
    scanf("%d",&n);
    printf("Enter the elements of array of above size\n");
    for(i=0;i<n;i++)
    {
         scanf(" %d",&a[i]);
    } 
    quicksortf(a,0,n-1);
    printf("\nThe output after quicksort is \n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
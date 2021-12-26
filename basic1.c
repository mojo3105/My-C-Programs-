#include<stdio.h>
#include<string.h>

void main()
{
    char s1[100], s2[100], s3[100];
    printf("Enter the two strings \n");
    scanf("%s",s1);
    scanf("%s",s2);
    printf("\nThe conatinated string is %s",strcat(s1,s2));
    
    
//    int n,i=0,rev=0,n1;
//    printf("Enter the number=");
//    scanf("%d",&n1);
//    n=n1;
//    while(n!=0)
//    {
//      i=n%10;
//      rev=rev*10+i;
//      n=n/10;  
//    }
//   if(rev==n1)
//     printf("\nThe given number is palindrome ");
//   else
//     printf("\nThe given number is not a palindrome ");  

}
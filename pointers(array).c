#include <stdio.h>
int main()
{
    int n,i,j;
    printf("Enter the number of the elements in the array: ");
    scanf("%d",&n);
    
    int arr[n];
    
    printf("Enter %d numbers:\n",n);
    for (i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int sum = 0;
    int *ptr = arr;
    for (int j=0;j<n;j++)
    {
        sum = sum + *ptr;
        ptr++;
    }
    printf("Sum of the numbers is %d\n",sum);
    return 0;
}

#include<stdio.h>
void rec(int a1[],int b,int d,int *max)
{
    if (d>b)
    return;
    
    if (a1[d]>*max)
    *max=a1[d];
    rec(a1,b,d+1,max);
}

int main()
{
    int a,i;
    printf("Enter total number of elements\n");
    scanf("%d",&a);
    
    int arr[a];
    for(i=0;i<a;i++)
    {
        printf("Enter the number %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    int max = arr[0];
    rec(arr,a-1,0,&max);
    printf("The largest number is %d\n",max);
    return 0;
}

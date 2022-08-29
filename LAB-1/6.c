#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,n;
    int sum=0;
    printf("Enter n: ");
    scanf("%d",&n);
    int *arr=(int*)calloc(n,sizeof(int));
    printf("Enter values: ");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    for(i=0;i<n;i++)
        sum=sum+arr[i];
    printf("Sum is: %d\n\n",sum);
    return 0;
}

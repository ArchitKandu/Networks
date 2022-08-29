#include<stdio.h>
int main()
{
    int *p;
    int a;
    printf("Enter a: ");
    scanf("%d",&a);
    p=&a;
    printf("Call by reference: %d\n\n",*p);
    return 0;
}

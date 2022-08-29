#include<stdio.h>
int main()
{
    int a,b,temp;
    printf("Enter a and b: ");
    scanf("%d%d",&a,&b);
    printf("\nInitial a: %d\nInitial b: %d\n",a,b);
    temp=a;
    a=b;
    b=temp;
    printf("\nFinal a: %d\nFinal b: %d\n\n",a,b);
    return 0;
}

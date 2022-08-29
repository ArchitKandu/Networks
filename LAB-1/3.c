#include<stdio.h>
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int main()
{
    int a,b;
    printf("Enter a and b: ");
    scanf("%d%d",&a,&b);
    printf("\nInitial a: %d\nInitial b: %d\n",a,b);
    swap(&a,&b);
    printf("\nFinal a: %d\nFinal b: %d\n\n",a,b);
    return 0;
}

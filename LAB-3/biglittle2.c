#include<stdio.h>
int main(){
    unsigned int a = 0x01234567;
    char *c = (char *) &a;
    for(int i=0;i<4;i++)
        printf("\nAddress of 0x%x is: %d",c[i],&c[i]);
    printf("\n\n");
    return 0;
}

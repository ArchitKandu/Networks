#include<stdio.h>
int main(){
    unsigned int x = 0x01234567;
    char *c =(char *)&x;
    printf("\n*c is: 0x%x\n",*c);
    if(*c==0x10)
        printf("The Architecture is Little Endian.\n\n");
    else
        printf("The Architecture is Big Endian.\n\n");
    return 0;
}

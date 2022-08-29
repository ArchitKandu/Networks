#include<stdio.h>
//typedef unsigned char BYTE;
int main(){
    unsigned int value = 01234567;
    char a,b,c,d;
    a = (char)(value & 0xFF);
    b = (char)((value >> 8) & 0xFF);
    c = (char)((value >> 16) & 0xFF);
    d = (char)((value >> 24) & 0xFF);
    printf("\na = %c", a);
    printf("\nb = %c", b);
    printf("\nc = %c", c);
    printf("\nd = %c\n\n", d);
    return 0;
}

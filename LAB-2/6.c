#include<stdio.h>
typedef unsigned char BYTE;
int main(){
    unsigned int value = 11223344;
    BYTE a,b,c,d;
    a = (value & 0xFF);
    b = ((value >> 8) & 0xFF);
    c = ((value >> 16) & 0xFF);
    d = ((value >> 24) & 0xFF);
    printf("\na = %02X", a);
    printf("\nb = %02X", b);
    printf("\nc = %02X", c);
    printf("\nd = %02X\n\n", d);
    return 0;
}

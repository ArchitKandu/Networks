#include<stdio.h>
#include<string.h>
int main(){
    int count=0;
    char data[25];
    printf("\nEnter databits: ");
    scanf("%s",data);
    printf("\nBefore Bit Stuffing: %s",data);
    printf("\nAfter Bit Stuffing: ");
    for(int i=0;i<strlen(data);i++){
        if(data[i]=='1')
            count++;
        else
            count=0;
        printf("%c",data[i]);
        if(count==5){
            printf("0");
            count=0;
        }
    }
    printf("\n\n");
    return 0;
}

#include<stdio.h>
#include<string.h>
int main() {
    char frame[25][25],str[25][25];
    char flag[10];
    strcpy(flag,"flag");
    char esc[10];
    strcpy(esc,"esc");
    int i,j,k=0,n;
    strcpy(frame[k++],"flag");
    printf("\nEnter number of String: ");
    scanf("%d",&n);
    printf("Enter String:\n");
    for(i=0;i<=n;i++)
        gets(str[i]);
    for(i=1;i<=n;i++) {
        if(strcmp(str[i],flag)!=0 && strcmp(str[i],esc)!=0)
            strcpy(frame[k++],str[i]);
        else {
            strcpy(frame[k++],"esc");
            strcpy(frame[k++],str[i]);
        }
    }
    strcpy(frame[k++],"flag");
    printf("\nByte stuffing at sender side:\n");
    for(i=0;i<k;i++)
        printf("%s\t",frame[i]);
    printf("\n\n");
    return 0;
}

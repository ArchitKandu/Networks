#include<stdio.h>
struct student{
    int dID;
    char fname[20];
    char lname[20];
    float p;
}s[5];
int main(){
    for(int i=0;i<5;i++){
        printf("\n\n-----Student %d-----",i+1);
        printf("\nEnter Details Id: ");
        scanf("%d",&s[i].dID);
        printf("Enter First Name: ");
        scanf("%s",s[i].fname);
        printf("Enter Last Name: ");
        scanf("%s",s[i].lname);
        printf("Enter points: ");
        scanf("%f",&s[i].p);
    }
    for(int i=0;i<5;i++){
        printf("\n\n-----Student %d-----",i+1);
        printf("\nDetails Id: %d",s[i].dID);
        printf("\nFirst Name: %s",s[i].fname);
        printf("\nLast Name: %s",s[i].lname);
        printf("\nPoints: %.2f",s[i].p);
    }
    return 0;
}

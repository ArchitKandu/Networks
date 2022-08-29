#include<stdio.h>
struct student{
    char name[20];
    int roll;
    int age;
    char state[10];
}s[2];
int main()
{
    for(int i=0;i<2;i++) {
        printf("\n-----STUDENT %d-----",i+1);
        printf("\nEnter Name: ");
        scanf("%s",s[i].name);
        printf("Enter Roll No.: ");
        scanf("%d",&s[i].roll);
        printf("Enter Age: ");
        scanf("%d",&s[i].age);
        printf("Enter State: ");
        scanf("%s",s[i].state);
        printf("\n\n-----OUTPUT-----\n");
        printf("Name: %s",s[i].name);
        printf("\nRoll No.: %d",s[i].roll);
        printf("\nAge: %d",s[i].age);
        printf("\nState: %s\n\n",s[i].state);
    }
    return 0;
}

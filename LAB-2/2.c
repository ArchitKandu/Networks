#include<stdio.h>
#include<stdlib.h>
struct employee{
    char name[20];
    int id;
    int age;
    char gender[6];
    char city[15];
}e1;
int main(){
    printf("\nEnter Name: ");
    scanf("%s",e1.name);
    printf("Enter ID: ");
    scanf("%d",&e1.id);
    printf("Enter Gender: ");
    scanf("%s",e1.gender);
    printf("Enter Age: ");
    scanf("%d",&e1.age);
    printf("Enter City: ");
    scanf("%s",e1.city);
    struct employee *ptr1 = (struct employee*)malloc(sizeof(struct employee));
    *ptr1=e1;
    printf("\n\n-----OUTPUT-----\n");
    printf("Name: %s",ptr1->name);
    printf("\nID: %d",ptr1->id);
    printf("\nGender: %s",ptr1->gender);
    printf("\nAge: %d",ptr1->age);
    printf("\nCity: %s\n\n",ptr1->city);
    return 0;
}

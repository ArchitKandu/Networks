#include<stdio.h>
#include<stdlib.h>
struct student{
    char name[20];
    int age;
    int SubId;
}s;
int main(){
    printf("\nEnter Name: ");
    scanf("%s",s.name);
    printf("Enter Age: ");
    scanf("%d",&s.age);
    printf("Enter Subject Id: ");
    scanf("%d",&s.SubId);
    printf("\n\n-----OUTPUT (Struct Variable)-----\n");
    printf("Name is: %s",s.name);
    printf("\nAge is: %d",s.age);
    printf("\nSubject Id is: %d",s.SubId);
    struct student *p = (struct student*)malloc(sizeof(struct student));
    *p=s;
    printf("\n\n-----OUTPUT (Pointer Variable)-----\n");
    printf("Name is: %s",p->name);
    printf("\nAge is: %d",p->age);
    printf("\nSubject Id is: %d\n\n",p->SubId);
    return 0;
}

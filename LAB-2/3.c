#include<stdio.h>
#include<stdlib.h>
struct person{
    char name[20];
    int age;
    float weight;
};
int main(){
    struct person *p=(struct person*)malloc(sizeof(struct person));
    printf("\nEnter Name: ");
    scanf("%s",p->name);
    printf("Enter Age: ");
    scanf("%d",&p->age);
    printf("Enter Weight: ");
    scanf("%f",&p->weight);
    printf("\n\n-----OUTPUT-----");
    printf("\nName is: %s",p->name);
    printf("\nAge is: %d",p->age);
    printf("\nWeight is: %.2f\n\n",p->weight);
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
typedef struct
{
  char name[50];
    int id;
    float gpa;
}student;
int main()
{
    int size = 0, capacity = 2;
    student *list=malloc(capacity * sizeof(student));
    if(list == NULL)
    {
        printf("memory allocation failed !");
        free(list);
        list = NULL;
        return 1;
    }     
    for(int i=0; i<capacity;i++)
    {
        printf("\ninput the name of the student %d: ",i+1);
        scanf("%49s",list[i].name);
        printf("\ninput the id of %s: ",list[i].name);
        scanf("%d",&list[i].id);
        printf("\ninput the GPA of %s: ",list[i].name);
        scanf("%f",&list[i].gpa);
        size++;
    }
    while(1)
    {
        char choice;
        printf("\ndo you want to add more students (y/n): ");
        scanf(" %c",&choice);
        if(choice != 'y' && choice != 'Y')
        {
            break;
        }
        if(size==capacity)
        {
            capacity*=2;
            student *temp=realloc(list, capacity * sizeof(student));
            if(temp==NULL)
            {
                printf("memory allocation failed !");
                free(temp);
                temp = NULL;
            }
        
            else
            {
                list = temp;
            }
        }
        printf("\ninput the name of student %d: ",size+1);
        scanf("%49s",list[size].name);
        printf("\ninput the id of %s: ",list[size].name);
        scanf("%d",&list[size].id);
        printf("\ninput the GPA of %s: ",list[size].name);
        scanf("%f",&list[size].gpa);
        size++;
    }
    printf("\n==========LIST OF STUDENTS==========\n");
    for(int i=0;i<size;i++)
    {
        printf("%d)\tNAME = %s\tID = %d\tGPA = %.2f\n",i+1,list[i].name,list[i].id,list[i].gpa);
    }
    free(list);
    list = NULL;
    return 0;
}
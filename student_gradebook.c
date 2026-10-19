#include<stdio.h>
#include<stdlib.h>
int active_alloc=0;
typedef struct
{
  char name[50];
    int id;
    float gpa;
}student;
void*my_malloc(size_t size)
{
    void *ptr=malloc(size);
    if(ptr!=NULL)
    {
        active_alloc++;
        printf("allocated memort = %p\tactive leaks = %d",ptr,active_alloc);
    }
    return ptr;
}
void my_free(void *ptr)
{
    if(ptr!=NULL)
    {
        free(ptr);
        active_alloc--;
        printf("freed memory at %p\ttotal leaks = %d",ptr,active_alloc);
    }
}
void*my_realloc(void*ptr,size_t size)
{
    void*new_ptr=realloc(ptr, size);
    if(ptr==NULL && new_ptr!= NULL)
    {
        active_alloc++;
        printf("realloc allocated at new memory %p. Active leaks = %d",new_ptr,active_alloc);
        return new_ptr;
    }
}
int main()
{
    int size = 0, capacity = 2;
    student *list=my_malloc(capacity * sizeof(student));
    if(list == NULL)
    {
        printf("memory allocation failed !");
        my_free(list);
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
            student *temp=my_realloc(list, capacity * sizeof(student));
            if(temp==NULL)
            {
                printf("memory allocation failed !");
                my_free(temp);
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
        printf("%d)\tNAME = %-20s\tID = %d\tGPA = %.2f\n",i+1,list[i].name,list[i].id,list[i].gpa);
    }
    my_free(list);
    list = NULL;
    return 0;
}
#include<stdio.h>
void input_todo()
{
    FILE *file = fopen("todo.txt", "a");
    if (file == NULL) 
    {
        printf("Error opening file!\n");
        return;
    }
    char task[100];
    printf("Enter your todo item: ");
    scanf(" %[^\n]", task);
    fprintf(file, "%s\n", task);
    fclose(file);
    printf("[saved to todo.txt]\n");
}
void display_todo()
{
    FILE *file = fopen("todo.txt","r");
    if(file == NULL)
    {
        printf("failed to find the file !");
        return;
    }
    char task[100];
    while(fgets(task, sizeof(task), file)!= NULL)
    {
        printf("-%s\n",task);
    }
    fclose(file);
}
int main()
{
    while(1)
    {
        int choice;
        printf("1)Input a task\n2)Show all the tasks\n3)exit\nInput ypur choice: ");
        scanf("%d",&choice);
        if(choice == 1)
        {
            input_todo();
        }
        else if(choice==2)
        {
            display_todo();
        }
        else
        {
            break;
        }
    }
    return 0;
}
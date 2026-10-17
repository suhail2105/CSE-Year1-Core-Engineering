#include<stdio.h>
#include<stdlib.h>
int main()
{
    int size = 0, capacity = 2;
    int *arr=malloc(capacity * sizeof(int));
    if(arr==NULL)
    {
        printf("Memory allocation failed!\n");
        free(arr);
        arr = NULL;
        return 1;
    }
    printf("input the values for the array(a non-number to stop): \n");
    while(1)
    {
        int value;
        if(scanf("%d",&value)!=1)
        {
            break;
        }
        if(size==capacity)
        {
            capacity*=2;
            int *temp=realloc(arr, capacity * sizeof(int));
            if(temp==NULL)
            {
                printf("memory allocation failed!\n");
                free(arr);
                arr = NULL;
            }
            else
            {
                arr = temp;
                printf("array successfully expanded !\nnew capacity of array = %d\n",capacity);
            }
        }
        arr[size]=value;
        size++;
    }
    printf("all the elements of this array are: \n");
    for(int i = 0; i<size; i++)
    {
        printf("%d\t",arr[i]);
    }
    free(arr);
    arr = NULL;
    return 0;
}
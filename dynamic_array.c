#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    printf("input the number of elements u want: ");
    scanf("%d",&n);
    int *arr=malloc(n * sizeof(int));
    if(arr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }
    printf("what would u like the array to be of: ");
    char word[50];
    scanf("%49s",word);
    printf("input the values for %s: \n",word);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int add;
    printf("would u like to add more elements(press 1 if yes, 0 if no) ?\n");
    scanf("%d",&add);
    if(add==1)
    {
        int n1;
        printf("input the number of elements u want: \n");
        scanf("%d",&n1);
        int *temp = realloc(arr,(n1+n) * sizeof(int));
        if (temp == NULL)
        {
            printf("Memory allocation failed!\n");
            free(arr);
            return 1;
        }
        arr = temp;
        printf("input the values for %s: \n",word);
        for(int i=n;i<(n1+n);i++)
        {
            scanf("%d",&arr[i]);
        }
        printf("the %s is as follows\n",word);
        for(int j=0;j<n+n1;j++)
        {
            printf("%d\t",arr[j]);
        }
    }
    else
    {
        printf("the %s is as follows\n",word);
        for(int j=0;j<n;j++)
        {
            printf("%d\t",arr[j]);
        }        
    }
    free(arr);
    arr = NULL;
    return 0;
}
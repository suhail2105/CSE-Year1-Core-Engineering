#include<stdio.h>
int main()
{
    int max,sum=0,marks[5],temp;
    float average;
    for(int i=0;i<5;i++)
    {
        printf("input the marks of student %d: ",i);
        scanf("%d",&marks[i]);
    }
    max=marks[0];
    int min=marks[0];
    for(int j=0;j<5;j++)
    {
        sum += marks[j];
        if (marks[j]>max)
        max=marks[j];
        if(marks[j]<min)
        min=marks[j];
    }
    average = (float)sum/5;
    printf("the average of all the students = %.2f\n",average);
    printf("the max of all the marks = %d\n",max);
    printf("the min of all the marks = %d\n",min);
    for(int k=0;k<5;k++)
    {
        for(int l=0;l<5-k-1;l++)
        {
            if(marks[l]>marks[l+1])
            {
                temp=marks[l];
                marks[l]=marks[l+1];
                marks[l+1]=temp;
            }    
        }
    }
    printf("the leaderboard is as follows: ");
    for(int m=0;m<5;m++)
    {
        printf("%d ",marks[m]);
    }
    printf("\n");
    printf("input the marks of student to be searched: ");
    int search_mark;
    scanf("%d",&search_mark);
    int found = 0,low = 0, high = 5-1;
    while(low<=high)
    {
        int mid = (low + high)/2;
        if(marks[mid]==search_mark)
        {
            found=search_mark;
            break;
        }
        else if(marks[mid]<search_mark)
        {
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    if(found!=0)
    printf("the mark have been found: %d",found);
    else
    printf("the mark was not found !");
    return 0;
}
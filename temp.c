#include<stdio.h>
int main(){
    float temp[7];
    printf("\nInput the temperatures for the last 7 days: ");
    for(int i=0; i<7; i++){
        printf("\nDay %d: ",i+1);
        scanf("%f",&temp[i]);
        if(temp[i]>100 || temp[i]<-100){
            printf("\ninvalid temp !");
            return 0;
        }
    }
    float max = temp[0];
    float min = temp[0];
    for(int i=0; i<7; i++){
        if(temp[i]>max){
            max = temp[i];
        }
        if(temp[i]<min){
            min = temp[i];
        }
    }
    printf("\nMax = %.2f\nMin = %.2f",max,min);
    float avg=0;
    for(int i=0; i<7; i++){
        avg+=temp[i];
    }
    printf("\nApprox average temperature this week was %d",(int)(avg/7));
    printf("\nTemperature chart:\n");
    for (int day=0; day<7; day++){
        printf("Day %d: ", day+1);
        for (int j=0; j<(int)temp[day]; j++){
            printf("*");
        }
        printf(" %.1f\n", temp[day]);
    }
    return 0;
}
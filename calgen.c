#include<stdio.h>
int main(){
    int years, months;
    printf("input year and months: ");
    scanf("%d %d", &years, &months);
    long total_days = 0;
    for (int y = 1900; y < years; y++){
        if ((y%4==0 && y%100!=0)||(y%400==0)){
            total_days += 366;
        }
        else{
            total_days += 365;
        }
    }
    int days[]={31,28,31,30,31,30,31,31,30,31,30,31};
    int leap=((years%4==0 && years%100!=0)||(years%400==0));
    if(leap){
        days[1]=29;
    }
    for(int m=1; m<months; m++){
        total_days+=days[m-1];
    }
    int start = (total_days + 1)%7;
    char *month_names[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    printf("\n      %s %d\n", month_names[months - 1], years);
    printf("-----------------------------\n");
    printf("  Sun Mon Tue Wed Thu Fri Sat\n");
    for (int i = 0; i < start; i++) {
        printf("    ");
    }
    for (int day=1; day<=days[months-1]; day++){
        printf("%4d",day);
        if ((day + start)%7 == 0){
            printf("\n");
        }
    }
    printf("\n-----------------------------\n");
    return 0;
}
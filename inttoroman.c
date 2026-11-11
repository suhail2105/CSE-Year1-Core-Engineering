#include<stdio.h>
#include<stdlib.h>
int main(){
    int   values[13]  = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    char *symbols[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
    printf("\n========INTEGER TO ROMAN========\n");
    printf("Input a number to convert it to roman number: ");
    int n;
    if(scanf("%d",&n)!=1){
        printf("This is not an integer !");
        exit(1);
    }
    if(n<1 || n>3999){
        printf("ERROR ! please enter a number between 1-3999");
        exit(1);
    }
    for(int i=0; i<13; i++){
        while(n>=values[i]){
        printf("%s",symbols[i]);
        n-=values[i];
        }
    }
    printf("\n");
    return 0;
}
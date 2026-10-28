#include<stdio.h>
typedef struct {
    char description[100];
    float amount;
    char category[50];
} transaction;
int main()
{
    int choice;
    do{
        printf("1)add expence\n2)view expences\n3)sum of all the expences\n4)exit\nchoice: ");
        scanf("%d",&choice);
        switch (choice){
            case 1:{
                transaction t;
                printf("input category of expence: ");
                scanf(" %[^\n]",t.category);
                printf("input expence: ");
                scanf("%f",&t.amount);
                printf("Description: ");
                scanf(" %[^\n]",t.description);
                FILE *f = fopen("expence.txt","a");
                if(f==NULL){printf("error opening the file"); break;}
                fprintf(f,"%s|%.2f|%s\n",t.category,t.amount,t.description);
                printf("[successfully added]\n");
                fclose(f);
            }
            break;
            case 2:{
                FILE *f= fopen("expence.txt","r");
                if(f==NULL){printf("error opening the file"); break;}
                char list[100];
                while(fgets(list,sizeof(list),f)!=NULL){
                    transaction t;
                    if(sscanf(list, "%49[^|]|%f|%99[^\n]",t.category,&t.amount,t.description)==3){
                        printf("%-15s|%8.2f|%s\n",t.category,t.amount,t.description);
                    }
                }
                fclose(f);
            }
            break;
            case 3:{
                FILE *f= fopen("expence.txt","r");
                if(f==NULL){printf("error opening the file\n"); break;}
                char list[50];
                float total = 0;
                while(fgets(list, sizeof(list), f)!=NULL){
                    transaction t;
                    if(sscanf(list, "%49[^|]|%f|%99[^\n]",t.category,&t.amount,t.description)==3){
                        total+=t.amount;
                    }
                }
                printf("the sum of all the expence = %.2f\n",total);
                fclose(f);
            }
            break;
            case 4:{
                printf("exiting the programe.....");
            }
            break;
            default:
                printf("incorrect choice\n");
            
        }
    }while(choice!=4);
    return 0;
}
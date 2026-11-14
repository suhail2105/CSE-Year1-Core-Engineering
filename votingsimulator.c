#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *voters[10] = {"suhail", "kabir", "numair", "majid", "hitler", "doraemon", "dekisugi", "shinchan", "kazama", "boo"};
char *candidate[3] = {"farhan", "maaz", "rubeena"};
void vote(){
    int voted[10] = {0};
    int count[3] = {0};
    int total_votes = 0;
    start_again:
    printf("\n================ VOTING MENU ================\n");
    for(int i=0; i<3; i++){
        printf("%d) %s\n", i+1, candidate[i]);
    }
    printf("0) Stop voting and show results\n");
    printf("=============================================\n");
    int choice;
    printf("Input your choice (0-3): ");
    if(scanf("%d", &choice) != 1){
        while (getchar() != '\n'); 
        printf("Invalid input! Please enter a number.\n");
        goto start_again;
    }
    if(choice == 0){
        goto show_results;
    }
    if(choice>=1 && choice<=3){
        printf("Are you sure you want to vote for %s? (yes/no): ", candidate[choice - 1]);
        char sure[5];
        scanf(" %4s", sure);
        if(strcmp(sure, "yes") == 0){
            printf("Input your name: ");
            char name[30];
            scanf(" %29s", name);
            int found = 0;
            for(int i=0; i<10; i++){
                if(strcmp(name, voters[i]) == 0){
                    found = 1;
                    if(voted[i] == 1){
                        printf("Error: %s has already voted!\n", name);
                    }else{
                        voted[i] = 1;
                        count[choice - 1] += 1;
                        total_votes++;
                        printf("Success: Vote added for %s!\n", candidate[choice - 1]);
                    }
                    break;
                }
            }
            if(!found){
                printf("Error: Name not found in voter list!\n");
            }
        }else{
            printf("Vote cancelled.\n");
        }
        if(total_votes == 10){
            printf("\nAll 10 registered voters have cast their votes!\n");
            goto show_results;
        }
        goto start_again;
    }else{
        printf("Wrong input, try again.\n");
        goto start_again;
    }
    show_results:
    printf("\n================ FINAL RESULTS ================\n");
    for(int i=0; i<3; i++){
        printf("%s: %d vote(s)\n", candidate[i], count[i]);
    }
    int max_votes = count[0];
    for(int i=1; i<3; i++){
        if(count[i] > max_votes){
            max_votes = count[i];
        }
    }
    if(max_votes == 0){
        printf("\nNo votes were cast.\n");
    }else{
        printf("\nWinner(s): ");
        for(int i=0; i<3; i++){
            if(count[i] == max_votes){
                printf("%s ", candidate[i]);
            }
        }
        printf("with %d vote(s)!\n", max_votes);
    }
    printf("\n--- Voters Who Did Not Vote ---\n");
    int missed = 0;
    for(int i=0; i<10; i++){
        if(voted[i] == 0){
            printf("- %s\n", voters[i]);
            missed++;
        }
    }
    if(missed == 0){
        printf("Everyone voted!\n");
    }
}
int main(){
    vote();
    return 0;
}
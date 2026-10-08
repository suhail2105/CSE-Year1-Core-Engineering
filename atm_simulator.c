#include <stdio.h>
#include <stdlib.h>
int main()
{
    int choice, epin, pin = 1106;
    float balance = 10000;
    int deb, dep;
    int attempts = 0;
    int authenticated = 0;
    // PIN Verification Block (Max 3 attempts)
    while (attempts < 3) {
        printf("Enter your PIN: ");
        scanf("%d", &epin);
        if (epin == pin) {
            authenticated = 1;
            break; // PIN correct, exit authentication loop
        } else {
            attempts++;
            printf("Invalid PIN! Attempts left: %d\n", 3 - attempts);
        }
    }
    // If failed 3 times, terminate immediately
    if (!authenticated) {
        printf("\nToo many incorrect attempts. Account locked. Exiting...\n");
        exit(0);
    }
    // Main ATM Menu Loop
    do {
        printf("\n||||||||||| CHOOSE ANY OF THE OPTIONS ||||||||||||\n");
        printf("\n1) BALANCE\t2) WITHDRAW\n3) DEPOSIT\t4) EXIT SYSTEM\nENTER YOUR CHOICE: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("\nYour balance = %.2f\n", balance);
                break;

            case 2:
                printf("\nInput amount to withdraw: ");
                scanf("%d", &deb);
                if (deb > balance) {
                    printf("\nInsufficient balance!\n");
                } else if (deb <= 0) {
                    printf("\nInvalid amount!\n");
                } else {
                    balance -= deb;
                    printf("%d has been debited from your account.\nBalance = %.2f\n", deb, balance);
                }
                break;

            case 3:
                printf("\nInput amount to deposit: ");
                scanf("%d", &dep);
                if (dep <= 0) {
                    printf("\nInvalid amount!\n");
                } else {
                    balance += dep;
                    printf("\n%d has been deposited to your account.\nBalance = %.2f\n", dep, balance);
                }
                break;

            case 4:
                printf("Thank you. Exiting from the program...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
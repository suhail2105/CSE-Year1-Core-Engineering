#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 250
void encrypt(){
    char let[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char word[max];
    printf("Input your message you want to encrypt: ");
    getchar();
    fgets(word, sizeof(word),stdin);
    word[strcspn(word, "\n")] = '\0';
    for(int i=0; word[i]!='\0'; i++){
        if(word[i]>='A' && word[i]<='Z'){
            word[i]+=32;
        }
    }
    int shift;
    char new[max];
    printf("\n--------ENCRYPTING THE MESSAGE--------\n");
    printf("\nInput how many places you want to shift: ");
    scanf("%d",&shift);
    if(shift<0 || shift>26){
    printf("invalid shift");
    return;
    }
    int len = strlen(word);
    for(int i=0; i<len; i++){
        new[i]=word[i];
        if(word[i]>='a' && word[i]<='z'){
            for(int j=0; j<26; j++){
                if(word[i]==let[j]){
                    new[i]=let[(j+shift)%26];
                    break;
                }
            }
        }
    }
    new[len]='\0';
    printf("The encrypted msg is: %s\n",new);
}
void decrypt(){
    char let[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char word[max];
    printf("Input your message you want to encrypt: ");
    getchar();
    fgets(word, sizeof(word),stdin);
    word[strcspn(word, "\n")] = '\0';
    for(int i=0; word[i]!='\0'; i++){
        if(word[i]>='A' && word[i]<='Z'){
            word[i]+=32;
        }
    }
    int shift;
    char new[max];
    printf("\n--------DECRYPTING THE MESSAGE--------\n");
    printf("\nInput how many places was the msg shifted: ");
    scanf("%d",&shift);
    if(shift<0 || shift>26){
    printf("invalid shift");
    return;
    }
    int len = strlen(word);
    for(int i=0; i<len; i++){
        new[i]=word[i];
        if(word[i]>='a' && word[i]<='z'){
            for(int j=0; j<26; j++){
                if(new[i]==let[j]){
                    new[i]=let[(j-shift+26)%26];
                    break;
                }
            }
        }
    }
    new[len]='\0';
    printf("The decrypted msg is: %s", new);
}
int main(){
    int choice;
    do{
        printf("\n--------------------\n");
        printf("1)Encrypt a message\n2)Decrypt a message\n3)Exit\nEnter ypur choice: ");
        scanf("%d",&choice);
        printf("\n--------------------\n");
        switch(choice){
            case 1:{encrypt();}break;
            case 2:{decrypt();}break;
            case 3:{
                printf("Exiting the program.....");
                exit(1);
            }
            break;
            default:{printf("Invalid choice !");}
        }
    }while(choice!=3);
    return 0;
}
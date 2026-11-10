#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void search(char words[][50], char meaning[][100]){
    int search=0; char key[50];
    printf("input the word you want to search: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")]='\0';
    for(int i=0; key[i]!='\0'; i++){
        if(key[i]>='A' && key[i]<='Z'){
            key[i]+=32;
        }
    }
    int len = strlen(key);
    while(len>0 && key[len-1]== ' '){
        key[len-1]='\0';
        len--;
    }
    char *p=key;
    while(*p==' '){
        p++;
    }
    for(int i = 0; i<10; i++){
        if(strcmp(p,words[i])==0){
            printf("word found\nword: %s\nmeaning: %s",words[i],meaning[i]);
            search = 1;
            break;
        }
    }
    if(search==0)
    printf("word not found !");
}
void display(char words[][50]){
    for(int i = 0; i<10; i++){
        printf("word %d : %s\n",i+1,words[i]);
    }
}
int main(){
    char words[10][50]={
        "love","pneumonoultramicroscopicsilicovolcanoconiosis","community","entrepreneur","utopia","asset","propaganda","leverage","collaborate","sustainability"};
    char meaning[10][100]={
        "a strong feeling of deep affection or care for someone or something",
"a lung disease caused by breathing in very fine silica dust from a volcano",
"a group of people living in the same area or sharing common interests",
"a person who starts a business and takes on the financial risk",
"an imaginary perfect society where everything is ideal",
"a useful or valuable thing that a person or company owns",
"biased information spread to promote a cause or influence people's opinions",
"to use something you already have to get a better result or advantage",
"to work together with others to achieve a shared goal",
"using resources in a way that does not harm the environment or run out"};
    int choice;
    do{
        printf("\n========WELCOME TO DICTIONARY========\n");
        printf("1) search\n2) display\n3) exit\nchoose your option: ");
        scanf("%d", &choice);
        getchar();        
        switch(choice){
            case 1:{
                search(words, meaning);
            }
            break;
            case 2:{
                display(words);
            }
            break;
            case 3:{
                printf("\nexiting the program....");
                exit(1);
            }
            break;
            default:{
                printf("Incorrect option chosen, try again");
            }
        }
    }while(choice!=3);
}
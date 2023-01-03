#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void playSolo(){
    int theme, index = rand() % 5;
    

    printf("\n\nChose theme:");
    printf("\n1- Food");
    printf("\n2- Names");
    printf("\n3- Animals");
    printf("\n4- Colors");
    printf("\nType your choice: ");

    scanf("%d", &theme);

    switch(theme){
        case 1:
        { // here the brackets define a scope where the label "case 1" points to, so that the variable can be declared before anything alse
            char foods[5][15] = {"Avocado", "Hamburger", "Salad", "Cheescake", "Peanut butter"};
            printf("%s\n\n", foods[index]);
            break;
        }
             
        case 2:
        {
            char names[5][15] = {"Yasmin", "Katherine", "Annelise", "Alexander", "Hamilton"};
            printf("%s", names[index]);
            break;
        }

        case 3:
        {
            char animals[5][15] = {"Crocodile", "Wolf", "Dolphin", "Hipoppotamus", "Rhino"};
            printf("%s", animals[index]);
            break;
        }

        case 4:
        {
            char colors[5][15] = {"Yellow", "Green", "White", "Black", "Blue"};
            printf("%s", colors[index]);
            break;
        }

        default:
            break;
    }

}

void chosePlayers(){
    int players;
    printf("\n1- Play solo");
    printf("\n2- Multiplayer");
    printf("\nType your choice: ");

    scanf("%d", &players);

    switch(players){
        case 1:
            playSolo();
            break;
        case 2:
            // multiplayer();
            break;
        default:
            break;
    }
}

void startMenu(){
    int option = 0;

    while (option < 3) {
        
        printf("Welcome to Hangman Game!");
        printf("\n1- Play");
        printf("\n2- About");
        printf("\n3- Quit");
        printf("\nType your choice: ");

        scanf("%d", &option);

        switch(option){
            case 1:
                chosePlayers();
                break;
            case 2:
                break;
            case 3:
                break;
            default:
                break;
        }

     //   printf("\e[1;1H\e[2J");
    }
}



void main(){

    srand((unsigned) time(NULL));

    startMenu();

    
    

}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void startMenu(){
    int opcao = 0;

    while (opcao < 2) {
        printf("Welcome to Hangman Game!");
        printf("\n1- Play");
        printf("\n2- About");
        printf("\n3- Quit");
        printf("\nType your choice: ");

        scanf("%d", opcao);

        switch(opcao){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            default:
                break;
        }

        //printf("\e[1;1H\e[2J");
    }
}


void main(){
    startMenu();

    
    

}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>     // strcpy(), strlen() and others
#include <stdbool.h>    // booleans
#include <time.h>       // generate seed for rand()

/*
    TO DO:
    - change scanf to fget

*/

void showMask(char mask[10][10]) {
    int column, row;

    for (row=0; row<10; row++) {
        for (column=0; column<10; column++) {
            printf("%c ", mask[row][column]);
        }
        printf("\n");
    }
}


void play() {
    int column, row;
    char board[10][10], mask[10][10];
    bool gameOver = 0;

    // generate the board and the mask
    for (row=0; row<10; row++) {
        for (column=0; column<10; column++) {
            board[row][column] ='~';
            mask[row][column] = '*';
        }
    }

    showMask(mask);
    // play
    int rowInput, columnInput;
    while(!gameOver) {
        // ask for player interaction
        printf("\nChoose row: ");
        scanf("%d", &rowInput);
        printf("\nChoose column: ");
        scanf("%d", &columnInput);

        mask[rowInput-1][columnInput-1] = board[rowInput-1][columnInput-1];

        showMask(mask);

    }


}

/// @brief Shows the first options that the user can choose: play, see info about the game or quit. This loops until the user quits.
void startMenu() {
    int option = 0;

    while (option < 3) {
        
        // selection menu
        printf("\nWelcome to Battleship Game!");
        printf("\n1- Play");
        printf("\n2- About");
        printf("\n3- Quit");
        printf("\nType your choice: ");

        setbuf(stdin, 0); // clear buffer
        scanf("%d", &option);

        // action corresponding to option chosen by use
        switch(option){
            case 1: // play
                play();
                break;

            case 2: // about
                printf("\e[1;1H\e[2J"); // clear screen
                setbuf(stdin, 0); // clear buffer
                printf("Game developed for study in 2023\nBy Heloisa Tambara");
                getchar();
                break;

            default: // ignore
                break;
        }

     //   printf("\e[1;1H\e[2J");
    }
}


/// @brief Main function: creates seed for random generations if needed and calls the startMenu().
void main() {
    startMenu(); // calls for the main menu
}

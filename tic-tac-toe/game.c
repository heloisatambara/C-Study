#include <stdio.h>
#include <stdlib.h>
#include <string.h>     // strcpy(), strlen() and others
#include <stdbool.h>    // booleans



void showBoard(char board[9]) {
    int i;

    printf("\n");

    for (i=0; i<9; i++) {

        // sets color to gray if the space wasn't used yet
        if (board[i]!='O'&&board[i]!='X') {
            printf("\033[90m");
        } else {
            printf("\033[1m");
        }

        // underlines first and second rows the make the board prettier
        if (i<6) {
            printf("\033[4m");
        }

        printf(" %c ", board[i]);
        printf("\033[0m");

        if ((i+1) % 3 == 0) {
            printf("\n");
        } else {
            printf("|");
        }
    }
}


/// @brief generates the board and starts the loop of the game.
void play() {
    char board[] = "123456789";
    int position, count=0;
    bool player1 = true;

    // play
    while (count<9) {
        printf("\e[1;1H\e[2J"); // clear screen
        if (player1) {
            printf("Player 1:\n");
        } else {
            printf("Player 2:\n");
        }
        
        showBoard(board);
        printf("\n\nEnter position:");
        setbuf(stdin, 0); // clear buffer
        scanf("%d", &position); 

        // checks if position was already used
        if (board[position-1]!='X'&&board[position-1]!='O'){
            if (player1) {
                board[position-1] = 'X';
            } else {
                board[position-1] = 'O';
            }

            player1 = !player1;

            count++;   
        }
        
    }

    // game over
    printf("\e[1;1H\e[2J"); // clear screen
    setbuf(stdin, 0); // clear buffer
    showBoard(board);
    printf("\n\nGame over!");
    
    getchar();


}

/// @brief Shows the first options that the user can choose: play, see info about the game or quit. This loops until the user quits.
void startMenu() {
    int option = 0;

    while (option < 3) {
        printf("\e[1;1H\e[2J"); // clear screen
        
        // selection menu
        printf("\nWelcome to Tic Tac Toe!");
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

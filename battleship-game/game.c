#include <stdio.h>
#include <stdlib.h>
#include <string.h>     // strcpy(), strlen() and others
#include <stdbool.h>    // booleans
#include <time.h>       // generate seed for rand()
#include <wchar.h>      // to use 4060 char

/*
    TO DO:
    - change scanf to fget;
    - configurations to change attempts and ships.
    - version with points per kind of ship, ship length etc..
    
*/

/// @brief walks through the mask printing it as a hidden board.
void showMask(wchar_t mask[10][10]) {
    int column, row;

    printf("   1 2 3 4 5 6 7 8 9 10\n");
    for (row=0; row<10; row++) {
        printf("%-2d ", row+1);
        for (column=0; column<10; column++) {
            switch (mask[row][column]) {
                case '~':
                    printf("\033[1;97;44m"); // \033 changes font to parameters [effect;font-color;background-color;+m
                    break;
                case 4060:
                    printf("\033[95;44m");
                    break;
                case '*':
                    printf("\033[0m"); // [0m sets everything back to default
                    break;
                default:
                    break;
            }

            printf("%c ", mask[row][column]);
            printf("\033[0m");
        }
        printf("\n");
    }
}


/// @brief generates random positions to put ships.
void positionShips(wchar_t board[10][10], int ships){
    int randRow, randColumn, points=0;
    
    while (points<ships){
        randRow = rand() % 10;
        randColumn = rand() % 10;

        if (board[randRow][randColumn]=='~'){
            board[randRow][randColumn] = 4060;
            points++;
        }
    }
    

}


/// @brief generates the board and the mask, the ships and starts the loop of the game.
void play() {
    int column, row, ships=20, attempts=50;
    wchar_t board[10][10], mask[10][10];

    // generate the board and the mask
    for (row=0; row<10; row++) {
        for (column=0; column<10; column++) {
            board[row][column] ='~';
            mask[row][column] = '*';
        }
    }


    // create random positioned ships
    positionShips(board, ships);


    // play
    int rowInput, columnInput, points=0, shots=0;
    char message[50] = "Welcome to Battleship!";
    while (shots<attempts && points<ships) {
        // initialization
        printf("\e[1;1H\e[2J"); // clear screen
        setbuf(stdin, 0); // clear buffer
        printf("\n%s", message);
        printf("\nYou have %d shots left.\n\n", attempts-shots);
        showMask(mask);

        // ask for player interaction - only accpets valid inputs
        rowInput = -1;
        columnInput = -1;
        while (rowInput<1||rowInput>10||columnInput<1||columnInput>10){
            printf("\nChoose row: ");
            scanf("%d", &rowInput);
            printf("\nChoose column: ");
            scanf("%d", &columnInput);
        }
        
        // unmasks the position
        mask[rowInput-1][columnInput-1] = board[rowInput-1][columnInput-1];

        // increments pointsers 
        if (board[rowInput-1][columnInput-1]==4060){
            strcpy(message,"Nice shot!");
            points++;
        } else {
            strcpy(message,"Unlucky shot...");
        }

        shots++;
    }

    // game over
    printf("\e[1;1H\e[2J"); // clear screen
    if (points==ships) {
        printf("\nCongratulations! You won!");
    } else {
        printf("\nOh no! You ran out of shots. You hit %d ships!n", points);
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

    srand((unsigned) time(NULL)); // generates random seed for ships 

    startMenu(); // calls for the main menu
}

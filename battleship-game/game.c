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

    
*/

/// @brief walks through the mask printing it as a hidden board.
void showMask(wchar_t mask[10][10]) {
    int column, row;

    for (row=0; row<10; row++) {
        for (column=0; column<10; column++) {
            printf("%c ", mask[row][column]);
        }
        printf("\n");
    }
}


/// @brief generates random positions to put ships.
void positionShips(wchar_t board[10][10], int ships){
    int randRow, randColumn, count=0;
    
    while (count<ships){
        randRow = rand() % 10;
        randColumn = rand() % 10;

        if (board[randRow][randColumn]=='~'){
            board[randRow][randColumn] = 4060;
            count++;
        }
    }
    

}


/// @brief generates the board and the mask, the ships and starts the loop of the game.
void play() {
    int column, row, ships=20, attempts=40;
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
    int rowInput, columnInput, count=0, shots=0;
    char message[50] = "Welcome to Battleship!";
    while (shots<attempts && count<ships) {
        // initialization
        printf("\e[1;1H\e[2J"); // clear screen
        setbuf(stdin, 0); // clear buffer
        printf("\n%s", message);
        printf("\nYou have %d shots left.\n\n", attempts-shots);
        showMask(mask);

        // ask for player interaction
        printf("\nChoose row: ");
        scanf("%d", &rowInput);
        printf("\nChoose column: ");
        scanf("%d", &columnInput);

        // unmasks the position
        mask[rowInput-1][columnInput-1] = board[rowInput-1][columnInput-1];

        // increments counters 
        if (board[rowInput-1][columnInput-1]==4060){
            strcpy(message,"Nice shot!");
            count++;
        } else {
            strcpy(message,"Unlucky shot...");
        }

        shots++;
    }

    // game over
    printf("\e[1;1H\e[2J"); // clear screen
    if (count==ships) {
        printf("\nCongratulation! You won!");
    } else {
        printf("\nOh no! You ran out of shots. The enemy won!");
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

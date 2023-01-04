#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/*
    TO DO:
    - remove undesirable prints on choosing words parts;
    - treatment for composed words (with space key);
    - Add a configuration part to the menu: add words to the solo bank of words, number of attempts;
    - Draw hangman.
*/
/*
  ---------
 |        _|_
 |       |o_o|
 |         |
 |        /|\
 |         |
 |        / \
 |
 |
*/

/// @brief Creates the mask and shows the word chosen by the singlePlayer() function or typed in by the multiplayer user.
char* showWord(char *word) {
    int i = 0, wordLength = strlen(word);
    char *mask;
    mask = malloc(15*sizeof(char));

    for (i=0; i<wordLength; i++) {
        mask[i] = '_';
    }
    mask[i]='\0';

    return mask;

}


/// @brief For single player, shows options of themes that the word will belong to, and the function randomly chooses one from the bank of the chosen theme.
void singlePlayer() {
    int theme, index = rand() % 5;
    char *word;

    // selection menu
    printf("\n\nChose theme:");
    printf("\n1- Food");
    printf("\n2- Names");
    printf("\n3- Animals");
    printf("\n4- Colors");
    printf("\nType your choice: ");

    scanf("%d", &theme);

    // action corresponding to option chosen by use
    switch(theme) {
        case 1:
        { // here the brackets define a scope where the label "case 1" points to, so that the variable can be declared before anything else
            // because variables can't be defined right after labels, but in scopes there's no problem.
            char foods[5][15] = {"Avocado", "Hamburger", "Salad", "Cheescake", "Peanut butter"};
            printf("%s\n\n", foods[index]);
            word = foods[index];
            break;
        }
             
        case 2:
        {
            char names[5][15] = {"Yasmin", "Katherine", "Annelise", "Alexander", "Hamilton"};
            printf("%s", names[index]);
            word = names[index];
            break;
        }

        case 3:
        {
            char animals[5][15] = {"Crocodile", "Wolf", "Dolphin", "Hipoppotamus", "Rhino"};
            printf("%s", animals[index]);
            word = animals[index];
            break;
        }

        case 4:
        {
            char colors[5][15] = {"Yellow", "Green", "White", "Black", "Blue"};
            printf("%s", colors[index]);
            word = colors[index];
            break;
        }

        default:
            break;
    }

    // display game
    int attempts = 10, count = 0, i=0;
    char letters[26], guess[2], *maskedWord = showWord(word);
    letters[0] = '\0';

    while (strcmp(word, maskedWord) && count<=attempts) {
        printf("\n\nNumber of attempts left: %d", attempts-count);
        printf("\nWord: ");
        for (i=0; i<=strlen(maskedWord);i++) {
            printf("%c ", maskedWord[i]);
        }
        printf("\n\nLetters tried: ");
        for (i=0; i<=strlen(letters);i++) {
            printf("%c ", letters[i]);
        }
        printf("\n\nGuess a letter: ");
        
        setbuf(stdin, 0); // limpar buffer
        fgets(guess, 2, stdin);

        letters[count] = guess[0];
        count++;
        letters[count] = '\0';

        for (i=0; i<=strlen(word); i++) {
            if (guess[0] == word[i]) {
                maskedWord[i] = guess[0];
            }
        }
        
    }
    
}

/// @brief If the user chose to play, here they choose if it's a single or multi player.
void chosePlayers() {
    int players;

    // selection menu
    printf("\n1- Single player");
    printf("\n2- Multiplayer");
    printf("\nType your choice: ");

    scanf("%d", &players);

    // action corresponding to option chosen by use
    switch(players){
        case 1:
            singlePlayer();
            break;
        case 2:
            // multiplayer();
            break;
        default:
            break;
    }
}

/// @brief Shows first options that the user can choose: play, see info about the game or quit. This loops until the user quits.
void startMenu() {
    int option = 0;

    while (option < 3) {
        
        // selection menu
        printf("Welcome to Hangman Game!");
        printf("\n1- Play");
        printf("\n2- About");
        printf("\n3- Quit");
        printf("\nType your choice: ");

        setbuf(stdin, 0); // limpar buffer
        scanf("%d", &option);

        // action corresponding to option chosen by use
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


/// @brief Main function.
void main() {
    srand((unsigned) time(NULL)); // if user choses play solo, a random word will be chosen

    startMenu(); // calls for the main menu
}
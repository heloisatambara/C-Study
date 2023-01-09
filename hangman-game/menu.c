#include <stdio.h>
#include <stdlib.h>
#include <string.h>     // for strcpy(), strlen() and others
#include <time.h>       // for generation of seed to use random
#include <stdbool.h>    // for booleans
#include <ctype.h>      // for toupper()
#include <locale.h>     // for setlocale()

/*
    TO DO:
    - Add a configuration part to the menu: add words to the solo bank of words, number of attempts;
    - Draw hangman.
*/
/*
  ----------¬
 |       __ |
 |      |:P|/
 |      ̅ ̅/|\
 |        / | \
 |         / \
 |        /   \
 |
 |
*/

/// @brief Draws the hangman 
void drawHangman(int i){
    char hangman[8][120];
    strcpy(hangman[7],"  ----------¬\n |       __ |\n |      |:P|/\n |       ̅ ̅ /|\\ \n |        / | \\ \n |         / \\ \n |        /   \\ \n |\n |");
    strcpy(hangman[6], "  ----------¬\n |       __ |\n |      |  |/\n |       ̅ ̅ /|\\ \n |        / | \\ \n |         / \\ \n |        /   \\ \n |\n |");
    strcpy(hangman[5], "  ----------¬\n |       __ |\n |      |  |/\n |       ̅ ̅ /|\\ \n |        / | \\ \n |         /   \n |        /     \n |\n |");
    strcpy(hangman[4], "  ----------¬\n |       __ |\n |      |  |/\n |       ̅ ̅ /|\\ \n |        / | \\ \n |           \n |              \n |\n |");
    strcpy(hangman[3], "  ----------¬\n |       __ |\n |      |  |/\n |       ̅ ̅ /|  \n |        / |   \n |             \n |              \n |\n |");
    strcpy(hangman[2], "  ----------¬\n |       __ |\n |      |  |/\n |       ̅ ̅  |  \n |          |   \n |             \n |              \n |\n |");
    strcpy(hangman[1], "  ----------¬\n |       __ |\n |      |  |/\n |       \u0305 \u0305     \n |              \n |             \n |              \n |\n |");
    strcpy(hangman[0], "  ----------¬\n |           \n |           \n |               \n |              \n |             \n |              \n |\n |");

    printf("%s", hangman[i]);
}


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

/// @brief For single player, prompts the user for theme options and returns a random word from the bank.
char* getRandomWord() {
    int theme, index = rand() % 5, i=0;
    char *word;
    word = malloc(15*sizeof(char));

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
            char foods[5][15] = {"AVOCADO", "HAMBURGER", "SALAD", "CHEESCAKE", "PEANUT BUTTER"};
            for (i=0;i < strlen(foods[index]);i++) {
                word[i] = foods[index][i];
            }
            word[i] ='\0';

            break;
        }
             
        case 2:
        {
            char names[5][15] = {"YASMIN", "HERMIONE", "ANNELISE", "ALEXANDER", "HARRY"};
            word = names[index];
            break;
        }

        case 3:
        {
            char animals[5][15] = {"CROCODILE", "WOLF", "DOLPHIN", "HIPOPPOTAMUS", "RHINO"};
            word = animals[index];
            break;
        }

        case 4:
        {
            char colors[5][15] = {"YELLOW", "GREEN", "WHITE", "BLACK", "BLUE"};
            word = colors[index];
            break;
        }

        default:
            break;
    }



    return word;
}


/// @brief Gets word from getRandomWord() or prompts the user for a word, that word will be masked with showWord() and the game begins.
void play(int players) {
    printf("\e[1;1H\e[2J"); // clear screen
    
    char word[50];
    int i;

    if (players==1) {
        strcpy(word, getRandomWord());
    } else {
        printf("\nPLAYER 1");
        printf("\nType a word for PLAYER 2 to guess");
        printf("\n>>> ");

        scanf("%s", word);

        for (i=0; i<strlen(word); i++) {
            word[i] = toupper(word[i]);
        }
        
    }
    
    printf("\e[1;1H\e[2J"); // clear screen

    // play game
    int attempts = 8, count = 0;
    char letters[26], guess[15], *maskedWord = showWord(word), message[35] =  "Welcome to Hangman Game!\0";
    bool alreadyGuessed = false, guessedRight = false;
    letters[0] = '\0';

    while (strcmp(word, maskedWord) && count<=attempts) {

        // display of attempts and current mask
        drawHangman(attempts-count);
        if (players==2){printf("\nPLAYER 2");}
        printf("\n%s", message);
        strcpy(message, "Welcome to Hangman Game!\0");
        printf("\n\nNumber of attempts left: %d", attempts-count);

        printf("\nWord: ");
        for (i=0; i<=strlen(maskedWord);i++) {
            printf("%c ", maskedWord[i]);
        }

        printf("\n\nLetters guessed: ");
        for (i=0; i<=strlen(letters);i++) {
            printf("%c ", letters[i]);
        }

        printf("\n\nGuess a letter or type 1 to guess a word: ");
        
        setbuf(stdin, 0); // clear buffer
        fgets(guess, 2, stdin);


        // if player tries to guess word 
        if (guess[0]=='1') {
            printf("Type your word, choose wisely!\n>>> ");
            setbuf(stdin, 0); // clear buffer
            fgets(guess, 15, stdin);

            for (i=0; i<=strlen(word); i++) {
                maskedWord[i] = toupper(guess[i]);
            }
            maskedWord[i-1] = '\0';

            break;
        } else {
            guess[0] = toupper(guess[0]);
        }

        printf("\e[1;1H\e[2J"); // clear screen

        // if player guesses letter
        alreadyGuessed = false;
        guessedRight = false;
        for (i=0; i<=strlen(letters); i++) {
            if (letters[i]==guess[0]) {
                alreadyGuessed = true;
            }
        }

        if (!alreadyGuessed) {
            // add letter to attempted letters and increment counter
            letters[count] = guess[0];
            count++;
            letters[count] = '\0';

            // change correct letters to the appropriate spaces in the mask
            for (i=0; i<=strlen(word); i++) {
                if (guess[0] == word[i]) {
                    strcpy(message, "Nice guess!\0");
                    guessedRight = true;
                    maskedWord[i] = guess[0];
                }
            }    
            if (!guessedRight) {
                strcpy(message, "Bad choice!");
            }
        } else {
            strcpy(message, "You've tried this letter before!\0");
        }
       
       

    }

    // game over:
    setbuf(stdin, 0); // clear buffer
    if (!strcmp(word, maskedWord)) {
        printf("\e[1;1H\e[2J"); // clear screen

        printf("\n\nNumber of attempts left: %d", attempts-count);
        printf("\nWord: ");

        for (i=0; i<=strlen(maskedWord);i++) {

            printf("%c ", maskedWord[i]);
        }

        printf("\n\n*************************\n*                       *\n*  Yaaaay! You got it!  *\n*                       *\n*************************");
        getchar();
        printf("\e[1;1H\e[2J"); // clear screen
    } else {
        printf("\e[1;1H\e[2J"); // clear screen
        printf("\n\nYou ran out of attempts! Better luck next time.");
        getchar();
        printf("\e[1;1H\e[2J"); // clear screen
    }
 
 free(maskedWord);
 free(word);

}

/// @brief If the user chose to play, here they choose if it's a single or multi player.
void chosePlayers() {
    int players;

    // selection menu
    printf("\n1- Single player");
    printf("\n2- Multiplayer");
    printf("\nType your choice: ");

    scanf("%d", &players);

    if (players==1 || players==2) {
        play(players);
    }
    
}

/// @brief Shows the first options that the user can choose: play, see info about the game or quit. This loops until the user quits.
void startMenu() {
    int option = 0;

    while (option < 3) {
        
        // selection menu
        printf("\nWelcome to Hangman Game!");
        printf("\n1- Play");
        printf("\n2- About");
        printf("\n3- Quit");
        printf("\nType your choice: ");

        setbuf(stdin, 0); // clear buffer
        scanf("%d", &option);

        // action corresponding to option chosen by use
        switch(option){
            case 1: // play
                chosePlayers();
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
    setlocale(LC_ALL, ".UTF8");

    srand((unsigned) time(NULL)); // if user choses play solo, a random word will be chosen

    startMenu(); // calls for the main menu
}
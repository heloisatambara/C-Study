#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <wchar.h>


void main() {
    char hangman7[] = "  ----------¬\n |       __ |\n |      |:P|/\n |       ̅ ̅ /|\\ \n |        / | \\ \n |         / \\ \n |        /   \\ \n |\n |";
    char hangman6[] = "  ----------¬\n |       __ |\n |      |  |/\n |       ̅ ̅ /|\\ \n |        / | \\ \n |         / \\ \n |        /   \\ \n |\n |";
    char hangman5[] = "  ----------¬\n |       __ |\n |      |  |/\n |       ̅ ̅ /|\\ \n |        / | \\ \n |         /   \n |        /     \n |\n |";
    char hangman4[] = "  ----------¬\n |       __ |\n |      |  |/\n |       ̅ ̅ /|\\ \n |        / | \\ \n |           \n |              \n |\n |";
    char hangman3[] = "  ----------¬\n |       __ |\n |      |  |/\n |       ̅ ̅ /|  \n |        / |   \n |             \n |              \n |\n |";
    char hangman2[] = "  ----------¬\n |       __ |\n |      |  |/\n |       ̅ ̅  |  \n |          |   \n |             \n |              \n |\n |";
    char hangman1[] = "  ----------¬\n |       __ |\n |      |  |/\n |       \u0305     \n |              \n |             \n |              \n |\n |";
    char hangman0[] = "  ----------¬\n |           \n |           \n |               \n |              \n |             \n |              \n |\n |";

    printf("\n\n%s", hangman7);
    printf("\n\n%s", hangman6);
    printf("\n\n%s", hangman5);
    printf("\n\n%s", hangman4);
    printf("\n\n%s", hangman3);
    printf("\n\n%s", hangman2);
    printf("\n\n%s", hangman1);
    printf("\n\n%s", hangman0);
}

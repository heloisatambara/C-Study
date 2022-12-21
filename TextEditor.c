#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int imprimeLinha(char *texto, int linha, bool imprimir) {
    int i = 0, j = 0, tamanhoDaLinha = -1;
    while (texto[i] != EOF && j <= linha) {
        if (texto[i] == '\n') {
            j++;
        }
        if (j == linha) {
            if (imprimir) {
                putchar(texto[i]);
            }
            tamanhoDaLinha++;
        }
        i++;
    }
    putchar('\n');

    return tamanhoDaLinha;
}

void insereString(char * string, int linha, int coluna, char * texto) {
    char aux[200];
    int i = 0, tamLinhas = coluna, tamString;

    // retira \n da string
    string[strlen(string)-1] = '\0';
    
    // calcula tamanho do texto até onde a string será inserida
    while (i<linha) {
        tamLinhas = tamLinhas + imprimeLinha(texto, linha, false);
        i++;
    }

    aux[tamLinhas] = '\0';
    strncpy(aux, texto, tamLinhas);
    strcat(aux, string);
    strcat(aux, texto + tamLinhas);
    strcpy(texto, aux);
}


char * carregaArquivo(char * n) {
    int cont = 0;
    char c;
    static char texto[200];

    // abre arquivo
     FILE *file = fopen("C:/USP/texto.txt", "r");

    // guarda o conteudo do texto no arquivo na string
     if (NULL == file) {
        printf("file can't be opened \n");
    }
    do {
        c = fgetc(file);
        texto[cont] = c;
        cont++;
    } while (c != EOF);
        
    fclose(file);

    return texto;
}
// void escreveNoArquivo(char nome) {

// }

// void cursorProximaPalavra() {

// }
// void cursorAtualPalavra() {

// }
void cursorFim() {

}
// void cursorLinha(int x) {

// }
// void apaga() {

// }
// void marcarCursor() {

// }
// void inserePilha() {

// }
// void empilha() {

// }
// void empilhaApaga() {

// }
// void busca(char string) {

// }
// //void substitui(char string1, char string2) {

// //}
// void juntaLinha() {

// }
// void exibePilha() {

// }



void imprimeCursor(int coluna) {
    int i=0;
    while (i < coluna) {
        putchar(' ');
        i++;
    }
    putchar('^');

}


void main() {

    // criar variaveis
    int linha = 0, coluna = 0, i = 0, j = 0, tamanhoDaLinha, stringLen;
    char input[50], s[50], r[50];
    char* texto, * token;

    // recebe os comandos e chama as funcoes correspondentes
    while (input[0] != '!') {
        printf("\n%d,%d> ", linha, coluna);
        setbuf(stdin, 0); // limpar buffer
        fgets(input, 50, stdin); // le o maximo que couber no input
        // printf(" <ENTER>");
        
        // percorre o input para executar os comandos
        i = 0;
        while (input[i]!='\0') {
            switch(input[i]){
                case 'I':
                    j = i + 1;
                    insereString(input + j, linha, coluna, texto);
                    stringLen = strlen(input+j);
                    coluna = coluna + stringLen;
                    break;
                case 'A':
                    j = i + 1;
                    texto = carregaArquivo(input + j);
                    break;
                // case 'E':
                //    j = i + 1
                //     escreveNoArquivo(input + j, texto);
                //     break;
                case 'F':
                    coluna++;
                    break;
                case 'T':
                    coluna--;
                    break;
                case 'O':
                    coluna = 0;
                    break;
                // case 'P':
                //     cursorProximaPalavra();
                //     break;
                // case 'Q':
                //     cursorAtualPalavra();
                //     break;
                case '$':
                    coluna = tamanhoDaLinha;
                    break;
                case ':':
                    if (input[i+1]=='F') {
                        cursorFim();
                    } else {
                        char aux[50];
                        strcpy(aux, input+j);
                        aux[strlen(aux)-1] = '\0';
                        linha = atoi(aux);
                    }
                    break;
                // case 'D':
                //     apaga();
                //     break;
                // case 'M':
                //     marcarCursor();
                //     break;
                // case 'V':
                //     inserePilha();
                //     break;
                // case 'C':
                //     empilha();
                //     break;
                // case 'X':
                //     empilhaApaga();
                //     break;
                // case 'B':
                //     strcpy(n, input+(i+1));
                //     busca(s);
                //     break;
                // case 'S':
                //       strcpy(n, input+(i+1));
                //       strtok(s, '/')
                //       substitui(s, r);
                //     break;
                // case 'N':
                //     insereString('\n');
                //     break;
                // case 'U':
                //     juntaLinha();
                //     break;
                case '!':
                    break;
                case 'J':
                    linha++;
                    tamanhoDaLinha = imprimeLinha(texto, linha, false);
                    if (coluna > tamanhoDaLinha) {
                        coluna = tamanhoDaLinha;
                    };
                    break;
                case 'H':
                    linha--;
                    tamanhoDaLinha = imprimeLinha(texto, linha, false);
                    if (coluna > tamanhoDaLinha) {
                        coluna = tamanhoDaLinha;
                    };
                    break;
                // case 'Z':
                //     exibePilha();
                //     break;
                default:
                    break;
            }

            if ((input[i]=='I')||(input[i]=='A')||(input[i]=='E')||(input[i]==':')||(input[i]=='B')||(input[i]=='S')||(input[i]=='!')){
                break;
            }

            i++;
        }

        tamanhoDaLinha = imprimeLinha(texto, linha, true);
        imprimeCursor(coluna);
    }

    free(texto);
}
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

void insereString(char string[50], int linha, int coluna, char * texto) {
    char aux[200];
    int i = 0, tamLinhas = 1;

    // retira \n da string
    string[strlen(string)-1] = '\0';
    
    // calcula tamanho do texto até onde a string será inserida
    while (i<linha) {
        tamLinhas = tamLinhas + imprimeLinha(texto, i, false);
        tamLinhas++; // caractere '\n' deve ser contado
        i++;
    }
    tamLinhas = tamLinhas + coluna;

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


void escreveNoArquivo(char * n, char * texto) {
    fclose(fopen(n, "w")); ;// esvaziar o arquivo

    FILE * file = fopen("C:/USP/texto.txt", "w");
    fprintf(file, "%s", texto);
    fclose(file);

}

int cursorProximaPalavra(char * texto, int linha, int coluna) {
    int i, tamLinhas = 1;

    while (i<linha) {
        tamLinhas = tamLinhas + imprimeLinha(texto, i, false);
        tamLinhas++; // caractere '\n' deve ser contado
        i++;
    }
    tamLinhas = tamLinhas + coluna;

    i = tamLinhas;
    while (texto[i] != ' ') {
        i++;
    }
    i++;

    return i;
}

int cursorAtualPalavra(char * texto, int linha, int coluna) {
    int i, tamLinhas = 1;

    while (i<linha) {
        tamLinhas = tamLinhas + imprimeLinha(texto, i, false);
        tamLinhas++; // caractere '\n' deve ser contado
        i++;
    }
    tamLinhas = tamLinhas + coluna;

    i = tamLinhas;
    while (texto[i] != ' ') {
        i--;
    }

    i++;
    return i;
}


void apaga(int linha, int coluna, char * texto) {
    int i = 0, tamLinhas = 1, size;
    char aux[200];

    // calcula tamanho do texto até onde o caractere será apagado
    while (i<linha) {
        tamLinhas = tamLinhas + imprimeLinha(texto, i, false);
        tamLinhas++; // caractere '\n' deve ser contado
        i++;
    }
    tamLinhas = tamLinhas + coluna;

    aux[tamLinhas] = '\0';
    strncpy(aux, texto, tamLinhas);
    strcat(aux, texto + (tamLinhas+1));
    strcpy(texto, aux);
}

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



void imprimeCursor(int coluna, int M) {
    int i=0;
    while (i < coluna) {
        if (i == M) {
            putchar('M');
        } else {
            putchar(' ');
        }
       
        i++;
    }
    putchar('^');

}

int quantasLinhas(char * texto) {
    int i = 0, j = 0;
    while (texto[i] != EOF) {
        if (texto[i] == '\n') {
            j++;
        }
        i++;
    }

    return j;
}


void main() {

    // criar variaveis
    int linha = 0, coluna = 0, i = 0, j = 0, tamanhoDaLinha, stringLen, M = -1;
    char input[50], s[50], r[50], pulaLinha[] = "\n ";
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
                case 'E':
                    j = i + 1;
                    escreveNoArquivo(input + j, texto);
                    break;
                case 'F':
                    coluna++;
                    break;
                case 'T':
                    coluna--;
                    break;
                case 'O':
                    coluna = 0;
                    break;
                case 'P':
                    coluna = cursorProximaPalavra(texto, linha, coluna);
                    break;
                case 'Q':
                    coluna = cursorAtualPalavra(texto, linha, coluna);
                    break;
                case '$':
                    coluna = tamanhoDaLinha;
                    break;
                case ':':
                    if (input[i+1]=='F') {
                        int maxLinhas = quantasLinhas(texto);
                        linha = maxLinhas;
                        tamanhoDaLinha = imprimeLinha(texto, linha, false);
                        coluna = tamanhoDaLinha;
                    } else {
                        char aux[50];
                        strcpy(aux, input+j);
                        aux[strlen(aux)-1] = '\0';
                        linha = atoi(aux);
                        if (coluna > tamanhoDaLinha) {
                            coluna = tamanhoDaLinha;
                        };
                    }
                    break;
                case 'D':
                    apaga(linha, coluna, texto);
                    if (coluna > tamanhoDaLinha) {
                            coluna = tamanhoDaLinha;
                    };
                    break;
                case 'M':
                    M = coluna;
                    break;
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
                case 'N':
                    insereString(pulaLinha, linha, coluna, texto);
                    break;
                case 'U':
                    coluna = 0;
                    apaga(linha, coluna-1, texto);
                    break;
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
        imprimeCursor(coluna, M);
    }

    free(texto);
}
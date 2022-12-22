#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define tamanhoPilha 10
char pilha[tamanhoPilha][200];

char texto[200];
int coluna = 0, linha = 0;

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

int posicaoNaString(int coluna, int linha, char * texto) {
    int i = 0, tamLinhas = 0;

    while (i<linha) {
        tamLinhas = tamLinhas + imprimeLinha(texto, i, false);
        tamLinhas++; // caractere '\n' deve ser contado
        i++;
    }
    tamLinhas = tamLinhas + coluna;

    return tamLinhas;
}


void insereString(char string[50], int linha, int coluna, char * texto) {
    char aux[200];
    int i = 0, posString;

    // retira \n da string
     if (string[strlen(string)-1] == '\n') {

        string[strlen(string)-1] = '\0';
    }
    
    // calcula tamanho do texto até onde a string será inserida
    posString = posicaoNaString(coluna, linha, texto);
    posString++;

    aux[posString] = '\0';
    strncpy(aux, texto, posString);
    strcat(aux, string);
    strcat(aux, texto + posString);
    strcpy(texto, aux);
}


char * carregaArquivo(char n[50]) {
    int cont = 0;
    char c;
     // retira \n da string
     if (n[strlen(n)-1] == '\n') {

        n[strlen(n)-1] = '\0';
    }

     FILE *file = fopen(n, "r");

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


void escreveNoArquivo(char n[50], char * texto) {
      if (n[strlen(n)-1] == '\n') {

        n[strlen(n)-1] = '\0';
    }

    fclose(fopen(n, "w")); ;// esvaziar o arquivo

    FILE * file = fopen(n, "w");
    fprintf(file, "%s", texto);
    fclose(file);

}

int cursorProximaPalavra(char * texto, int linha, int coluna) {
    int i, posString;

    posString = posicaoNaString(coluna, linha, texto);

    i = posString + 1;
    while (texto[i] != ' ') {
        i++;
    }
    i++;

    return i;
}

int cursorAtualPalavra(char * texto, int linha, int coluna) {
    int i, posString;

    posString = posicaoNaString(coluna, linha, texto);

    i = posString + 1;
    while (texto[i] != ' ') {
        i--;
    }

    i++;
    return i;
}


void apaga(int linha, int coluna, char * texto) {
    int i = 0, posString, size;
    char aux[200];

    posString = posicaoNaString(coluna, linha, texto);

    posString++;

    aux[posString] = '\0';
    strncpy(aux, texto, posString);
    strcat(aux, texto + (posString+1));
    strcpy(texto, aux);
}

// void inserePilha() {

// }

void empilha(int M, int coluna, int linha, char * texto, int topo) {
    int i = 0;
    char stringMarcada[200];
    bool empilhado;

    strcpy(stringMarcada, texto + (posicaoNaString(M, linha, texto)));
    stringMarcada[coluna-M] = '\0';
    
    if (topo < tamanhoPilha) {
        strcpy(pilha[topo], stringMarcada);
    } else {
        printf("Pilha cheia");
    }

}
// void empilhaApaga() {

// }
int busca(char * string, char * texto) {
    if (string[strlen(string)-1] == '\n') {

        string[strlen(string)-1] = '\0';
    }
    
    char * findString = strstr(texto, string);
    int pos = findString - texto;
    return pos;
}


bool substitui(char * string1, char * string2) {
     if (string2[strlen(string2)-1] == '\n') {
        string2[strlen(string2)-1] = '\0';
    }
    
    int pos = busca(string1, texto);

    if (pos<0) {
        return false;
    }

        int coluna = -1, linha = 0, k=0;

        while (k<=pos) {
            if (texto[k] == '\n') {
                coluna = -1;
                linha++;
            }
            coluna++;
            k++;
        }
        coluna--;

        k = 0;
        while (k<strlen(string1)) {
            apaga(linha, coluna, texto);
            k++;
        }

        
        insereString(string2, linha, coluna, texto);
    return true;
}

void exibePilha(int topo) {
    int i = topo;
    
    while (i>=0) {
        printf("%s\n", pilha[i]);
        i--;
    }
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
    int i = 0, j = 0, tamanhoDaLinha, stringLen, M = -1, topo = 0;
    char input[50], r[50], pulaLinha[] = "\n ";
    char *token, *n;

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
                    j = i +1;
                    carregaArquivo(input+j);
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
                case 'V':
                    insereString(pilha[topo], linha, coluna, texto);
                    topo--;
                    break;
                case 'C':
                    empilha(M, coluna, linha, texto, topo);
                    topo++;
                    M = -1;
                    break;
                case 'X':
                    empilha(M, coluna, linha, texto, topo);
                    topo++;
                    int count = coluna-M;
                    coluna = M;

                    while (count!=0) {
                        apaga(linha, coluna, texto);
                        count--;
                    }
                    
                    break;
                case 'B':
                    j = i + 1;

                    int pos = busca(input+j, texto), k=0;

                    coluna = -1;
                    linha = 0;
                    while (k<=pos) {
                        if (texto[k] == '\n') {
                            coluna = -2;
                            linha++;
                        }
                        coluna++;
                        k++;
                    }
                    break;
                case 'S':
                    j = i + 1;
                    char delimiter[2] = "/";
                    char *token1 =strtok(input+j, delimiter);
                    char *token2 = strtok(NULL, delimiter);
                    bool b=true;

                    do {
                        b = substitui(token1, token2);
                    } while (b);
                    break;
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
                case 'Z':
                    exibePilha(topo);
                    break;
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
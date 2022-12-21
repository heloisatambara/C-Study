#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insereString(char string[50]) {

}
char * carregaArquivo(char * n) {
    int cont = 0;
    char c;
    static char texto[200];

    // abre arquivo
    printf("%s", n);
     FILE *file = fopen("C:/USP/texto.txt", "r");

    // guarda o conteudo do texto no arquivo na string
     if (NULL == file) {
        printf("file can't be opened \n");
    }
    do {
        c = fgetc(file);
        printf("%c", c);
//         texto[cont] = c;
    //       cont++;
    } while (c != EOF);
        
    fclose(file);

    return texto;
}
// void escreveNoArquivo(char nome) {

// }
// void cursorFrente() {

// }
// void cursorTras() {

// }
// void cursorInicio() {

// }
// void cursorProximaPalavra() {

// }
// void cursorAtualPalavra() {

// }
// void cursorFimLinha() {

// }
// void cursorFim() {

// }
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
// void proximaLinha() {

// }
// void anteriorLinha() {

// }
// void exibePilha() {

// }


void main() {

    // criar variaveis
    int linha = 0, coluna = 0, i = 0, x = 0, j = 0;
    char input[50], n[50], s[50], r[50];
    char* texto;

    // recebe os comandos e chama as funcoes correspondentes
    while (input[0] != '!') {
        printf("\n%d,%d> ", linha, coluna);
        setbuf(stdin, 0); // limpar buffer
        fgets(input, 50, stdin); // le o maximo que couber no input
        // printf(" <ENTER>");
        
        // percorre o input para executar os comandos
        while (input[i]!='\0') {
            switch(input[i]){
                // case 'I':
                //     insereString(s);
                //     break;
                case 'A':
                    j = i + 1;
                    
                    char* texto = carregaArquivo(input + 1);
                    
                    printf("%s",texto);
                    break;
                // case 'E':
                //     strcpy(n, input+(i+1));
                //     escreveNoArquivo(n, texto);
                //     break;
                // case 'F':
                //     cursorFrente();
                //     break;
                // case 'T':
                //     cursorTras();
                //     break;
                // case 'O':
                //     cursorInicio();
                //     break;
                // case 'P':
                //     cursorProximaPalavra();
                //     break;
                // case 'Q':
                //     cursorAtualPalavra();
                //     break;
                // case '$':
                //     cursorFimLinha();
                //     break;
                // case ':':
                //     if (input[i+1]=='F') {
                //         cursorFim();
                //     } else {
                //        strcpy(x, input+(i+1));
                //         cursorLinha(x);
                //     }
                //     break;
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
                // dividir a string em /
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
                // case 'J':
                //     proximaLinha();
                //     break;
                // case 'H':
                //     anteriorLinha();
                //     break;
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
    }

    free(texto);
}
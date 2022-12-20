#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <fstream>
#include <string>
#include <iostream>

void insereString(char string) {

}
void carregaArquivo(char nome, char texto) {
    int c, i = 0;

    // abre arquivo
    FILE *file
    file = fopen(nome, "r+")

    // guarda o conteudo do texto no arquivo na string
    if (file) {
        do {
            c = getc(file);
            texto[i] = c;
            i++;
        } while (c != EOF)

        fclose(file);
    }
}
void escreveNoArquivo(char nome) {

}
void cursorFrente() {

}
void cursorTras() {

}
void cursorInicio() {

}
void cursorProximaPalavra() {

}
void cursorAtualPalavra() {

}
void cursorFimLinha() {

}
void cursorFim() {

}
void cursorLinha(int x) {

}
void apaga() {

}
void marcarCursor() {

}
void inserePilha() {

}
void empilha() {

}
void empilhaApaga() {

}
void busca(char string) {

}
void substitui(char string1, char string2) {

}
void quebraLinha() {

}
void juntaLinha() {

}
void proximaLinha() {

}
void anteriorLinha() {

}
void exibePilha() {

}


void main() {
    // para possibilitar o uso de acentos
    setlocale(LC_ALL, "");

    // criar variaveis
    int linha = 0, coluna = 0, i = 0, x = 0, j = 0;
    char input[50], texto[200], n[49], s[49], r[49];

    // recebe os comandos e chama as funcoes correspondentes
    while (input[0] != '!') {
        printf("\n%d,%d> ", linha, coluna);
        setbuf(stdin, 0); // limpar buffer
        fgets(input, 50, stdin); // le o maximo que couber no input
        // printf(" <ENTER>");
        
        // percorre o input para executar os comandos
        while (input[i]!='\0') {
            switch(input[i]){
                case 'I':
                    cpst
                    insereString(s);
                    break;
                case 'A':
                    carregaArquivo(n, texto);
                    break;
                case 'E':
                    escreveNoArquivo(n);
                    break;
                case 'F':
                    cursorFrente();
                    break;
                case 'T':
                    cursorTras();
                    break;
                case 'O':
                    cursorInicio();
                    break;
                case 'P':
                    cursorProximaPalavra();
                    break;
                case 'Q':
                    cursorAtualPalavra();
                    break;
                case '$':
                    cursorFimLinha();
                    break;
                case ':':
                    if (input[i+1]=='F') {
                        cursorFim();
                    } else {
                        cursorLinha(x);
                    }
                    break;
                case 'D':
                    apaga();
                    break;
                case 'M':
                    marcarCursor();
                    break;
                case 'V':
                    inserePilha();
                    break;
                case 'C':
                    empilha();
                    break;
                case 'X':
                    empilhaApaga();
                    break;
                case 'B':
                    busca(s);
                    break;
                case 'S':
                    substitui(s, r);
                    break;
                case 'N':
                    quebraLinha();
                    break;
                case 'U':
                    juntaLinha();
                    break;
                case '!':
                    break;
                case 'J':
                    proximaLinha();
                    break;
                case 'H':
                    anteriorLinha();
                    break;
                case 'Z':
                    exibePilha();
                    break;
                default:
                    break;
            }

            if ((input[i]=='I')||(input[i]=='A')||(input[i]=='E')||(input[i]==':')||(input[i]=='B')||(input[i]=='S')||(input[i]=='!')){
                break;
            }

            i++;
        }
    }
}
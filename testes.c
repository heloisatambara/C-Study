#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int abre(char n[20]) {
    int cont = 0, i;
    char c, texto[200];
   // char texto[100];
    // abre arquivo
    FILE *file = fopen(n, "r");

    // guarda o conteudo do texto no arquivo na string
     if (NULL == file) {
        printf("file can't be opened \n");
    }
    do {
        c = fgetc(file);
        printf("%c", c);
        texto[cont] = c;
        cont++;
    } while (c != EOF);
        
    fclose(file);

    for (i = 0; i<=200; i++) {
        printf("%c", texto[i]);
    }
    return 0;
}

void main() {
    int i;
    char d[20], n[20] = "AC:/USP/texto.txt";
    strcpy(d, n+1);
    
    abre(n+1);
}
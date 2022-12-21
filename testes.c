#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int abre(char n[20]) {
    int cont = 0, i;
    char c, texto[200];
    char t[] = "ooooi moooço";
   // char texto[100];
    // abre arquivo
    FILE *file = fopen(n, "r+");

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

    for (i = 0; i<=strlen(t); i++) {
        fprintf(file, "%c", t[i]);
    }   

    
    fclose(file);

    
    return 0;
}



void main() {
    // int i;
    // char d[20], n[20] = "AC:/USP/texto.txt";
    // strcpy(d, n+1);
    
    // abre(n+1);

    // char * pilha[10] = {0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0};
    // bool teste;
    // char string[] = "oooi moco";
    // teste = !pilha[1];

    // pilha[0] = string;

    // printf("%s", pilha[0]);

    // char *string = "testar busca de palavras";
    // char *pesq = "ata";
    // char * result = strstr(string, pesq);
    // int pos = result - string;

    // printf("%d", pos);

//       char str[80] = "This is - www.tutorialspoint.com - website";
//    const char s[2] = "-";
//    char *token;
   
//    /* get the first token */
//    token = strtok(str, s);
   
//    /* walk through other tokens */
//    while( token != NULL ) {
//       printf( " %s\n", token );
    
//       token = strtok(NULL, s);
   }
   


}
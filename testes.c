#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int cont = 0;
    char c;
   // char texto[100];

    // abre arquivo
    FILE *file = fopen("C:/USP/C++Studies/C-Study/C-Study/texto.txt.txt", "r");

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


    return 0;
}

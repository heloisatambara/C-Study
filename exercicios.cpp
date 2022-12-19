#include <stdio.h>

int ex1(){
    int numero,
    quadrado;
    printf("Entre com uma sequência de inteiros não-nulos, seguida por 0:\n");
    scanf("%d", &numero);

    while (numero != 0) {
        quadrado = numero * numero;
        printf("O quadrado de %d é %d", numero, quadrado);
        scanf("%d", &numero);
    }

    return 0;
}

int ex2(){
    int input,
    i,
    soma;
    printf("Entre com n para calcular a soma dos n primeiros inteiros positivos\n");

    scanf("%d", &input);
    i = 1;
    soma = 0;
    while (i <= input) {
        soma = soma + i;
        i = i + 1;
    }
    printf("A soma dos inteiros ate %d eh %d", input, soma);

    return 0;
}

int main() {
    int n, i, output;
    printf("Insira n:\n");
    scanf("%d", &n); // Nao esquecer do &!!!
    i = 0;
    output = 1;
    printf("%d primeiros numeros impares: ", n);
    while (i < n) {
        printf("%d, ", output);
        output = output + 2;
        i = i + 1;
    }

    return 0;
}
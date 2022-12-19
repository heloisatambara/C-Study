// exercicios da lista https://www.ime.usp.br/~macmulti/exercicios/inteiros/index.html

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

int ex3() {
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

int ex4() {
    int x, n, i, potencia;
    printf("Input x:\n");
    scanf("%d", &x);
    printf("Input n:\n");
    scanf("%d", &n);

    i = 0;
    potencia = 1;
    while (i != n){
        potencia = potencia * x;
        i = i + 1;
    }

    printf("x^n: %d", potencia);
    return 0;
}

int main(){
    int ex;
    printf("Escolha qual exercicio testar: ");
    scanf("%d", &ex);
    while ( ex != 0) {
        if (ex == 1) {
            ex1();
        }
        else if (ex == 2) {
            ex2();
        }
        else if (ex == 3) {
            ex3();
        }
        else if (ex == 4) {
            ex4();
        }
    }
}
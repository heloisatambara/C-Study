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

int ex25()
{
  int a, b, total, soma, termo, i;

  printf("Digite um par de numeros: ");
  scanf("%d %d", &a, &b);
  printf("(%d, %d)\n", a, b);
  total = 0; 
  soma  = 0;
  while (a != 0) { 
    total = total + 1; 
    termo = 1;
    for (i = 1; i <= b; i++)
      termo = termo * a;
    printf("Resp = %d\n", termo);
    soma = soma + termo;
    printf("Soma = %d\n", soma);
    printf("Digite um par de numeros: ");
    scanf("%d %d", &a, &b);
    printf("(%d, %d)\n", a, b);
  }
  printf("Total de pares: %d\n", total);
  return 0;
}

int main(){
    int ex;
    printf("Escolha qual exercicio testar: ");
    scanf("%d", &ex);
    while ( ex != 0) {
        switch (ex)
        {
        case 1:
            ex1();
            break;
        case 2:
            ex2();
            break;
        case 3:
            ex3();
            break;
        case 4:
            ex4();
            break;
        case 25:
            ex25();
            break;
        
        default:0;
            break;
        }
    }
}
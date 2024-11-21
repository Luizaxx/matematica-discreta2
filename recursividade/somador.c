#include <stdio.h>

int soma_recursiva(int n) {
    if (n == 1) {
        return 1;
    } else {
        
        return n + soma_recursiva(n - 1);
    }
}

int main() {
    int n;
    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &n);

    int resultado = soma_recursiva(n);
    printf("A soma de 1 ate %d e: %d\n", n, resultado);

    return 0;
}


#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

int main() {
    int n, i;

    printf("Digite o numero de termos da sequencia de Fibonacci: ");
    scanf("%d", &n);
    printf("Sequencia de Fibonacci:\n"); 

    for (i = 0; i < n; i++) {
        printf("%d", fibonacci(i));
    }

    printf("\n");
    return 0;
}
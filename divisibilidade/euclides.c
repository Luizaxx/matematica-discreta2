#include <stdio.h>

int mdc_recursivo(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return mdc_recursivo(b, a % b);
    }
}

int main() {
    int num1, num2;

    printf("Digite dois numeros inteiros positivos: ");
    scanf("%d %d", &num1, &num2);

    int resultado = mdc_recursivo(num1, num2);
    printf("O MDC de %d e %d e: %d\n", num1, num2, resultado);

    return 0;
}

#include <stdio.h>

int mdc_recursivo(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return mdc_recursivo(b, a % b);
    }
}

int mmc(int a, int b) {
    int mdc = mdc_recursivo(a, b);
    return (a * b) / mdc;
}

int main() {
    int num1, num2;

    printf("Digite dois numeros inteiros positivos: ");
    scanf("%d %d", &num1, &num2);

    int resultado_mmc = mmc(num1, num2);
    printf("O MMC de %d e %d e: %d\n", num1, num2, resultado_mmc);

    return 0;
}
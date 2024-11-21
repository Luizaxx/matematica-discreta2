#include <stdio.h>


void imprimir_numeros(int n) {
   
    if (n == 1) {
        printf("%d ", n);
    } else {
        
        imprimir_numeros(n - 1);
       
        printf("%d ", n);
    }
}

int main() {
    int n;

    printf("Digite um numero inteiro: ");
    scanf("%d", &n);

    printf("Numeros de 1 ate %d: ", n);
    imprimir_numeros(n);
    printf("\n");

    return 0;
}
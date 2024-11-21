#include <stdio.h>

void imprimir_tabela_zn(int n) {
    int tabela[n][n];

    // Preenche a tabela com as somas modulares
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tabela[i][j] = (i + j) % n;
        }
    }

    // Imprime a tabela
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", tabela[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("Digite o valor de n para a tabela Z_n: ");
    scanf("%d", &n);

    imprimir_tabela_zn(n);

    return 0;
}
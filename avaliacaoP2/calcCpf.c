#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para calcular o dígito verificador de um CPF
int calcular_digito_cpf(int *cpf, int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += cpf[i] * (tamanho + 1 - i);
    }
    int resto = soma % 11;
    return (resto < 2) ? 0 : 11 - resto;
}

// Função para validar um CPF
int validar_cpf(int *cpf) {
    int digito1 = calcular_digito_cpf(cpf, 9);
    int digito2 = calcular_digito_cpf(cpf, 10);
    return (digito1 == cpf[9] && digito2 == cpf[10]);
}

// Função para calcular o dígito verificador de um ISBN-10
char calcular_digito_isbn(int *isbn) {
    int soma = 0;
    for (int i = 0; i < 9; i++) {
        soma += isbn[i] * (10 - i);
    }
    int resto = soma % 11;
    return (resto == 10) ? 'X' : (char)('0' + resto);
}

// Função para validar um ISBN-10
int validar_isbn(int *isbn) {
    char digito = calcular_digito_isbn(isbn);
    return (digito == (isbn[9] == 10 ? 'X' : '0' + isbn[9]));
}

int main() {
    // Cálculo e validação de CPF
    int cpf[11];
    printf("Digite os 9 primeiros dígitos do CPF (sem pontos ou traços): ");
    for (int i = 0; i < 9; i++) {
        scanf("%1d", &cpf[i]);
    }

    cpf[9] = calcular_digito_cpf(cpf, 9);
    cpf[10] = calcular_digito_cpf(cpf, 10);

    printf("CPF completo: ");
    for (int i = 0; i < 11; i++) {
        printf("%d", cpf[i]);
    }
    printf("\n");

    if (validar_cpf(cpf)) {
        printf("CPF válido!\n");
    } else {
        printf("CPF inválido!\n");
    }

    // Cálculo e validação de ISBN-10
    int isbn[10];
    printf("\nDigite os 9 primeiros dígitos do ISBN-10: ");
    for (int i = 0; i < 9; i++) {
        scanf("%1d", &isbn[i]);
    }

    char digito_isbn = calcular_digito_isbn(isbn);
    printf("ISBN completo: ");
    for (int i = 0; i < 9; i++) {
        printf("%d", isbn[i]);
    }
    printf("%c\n", digito_isbn);

    isbn[9] = (digito_isbn == 'X') ? 10 : digito_isbn - '0';
    if (validar_isbn(isbn)) {
        printf("ISBN válido!\n");
    } else {
        printf("ISBN inválido!\n");
    }

    return 0;
}
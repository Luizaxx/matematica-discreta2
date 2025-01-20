#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Função para calcular o máximo divisor comum (MDC)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Função para calcular o inverso modular
int mod_inverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1) return 0;

    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0) x1 += m0;

    return x1;
}

// Função para calcular potência modular
long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;

    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;

        exp = exp >> 1;
        base = (base * base) % mod;
    }

    return result;
}

// Função para codificar uma mensagem usando a tabela A=11, B=12, ..., Z=36
void encode_message(const char *message, int *encoded, int *length) {
    *length = 0;
    for (int i = 0; message[i] != '\0'; i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            encoded[(*length)++] = message[i] - 'A' + 11;
        } else if (message[i] == ' ') {
            encoded[(*length)++] = 37; // Espaço codificado como 37
        } else {
            printf("Caracter inválido na mensagem: %c\n", message[i]);
            exit(1);
        }
    }
}

// Função para decodificar uma mensagem
void decode_message(const int *encoded, int length, char *decoded) {
    for (int i = 0; i < length; i++) {
        if (encoded[i] >= 11 && encoded[i] <= 36) {
            decoded[i] = (char)(encoded[i] - 11 + 'A');
        } else if (encoded[i] == 37) {
            decoded[i] = ' '; // Espaço
        } else {
            printf("Código inválido na mensagem codificada: %d\n", encoded[i]);
            exit(1);
        }
    }
    decoded[length] = '\0';
}

int main() {
    int p, q, e;

    // Entrada dos números primos p e q
    printf("Digite o valor de p (primo): ");
    scanf("%d", &p);
    printf("Digite o valor de q (primo): ");
    scanf("%d", &q);

    // Cálculo de n e phi(n)
    int n = p * q;
    int phi = (p - 1) * (q - 1);

    // Entrada do expoente público e
    printf("Digite o valor de e (1 < e < phi e coprimo com phi): ");
    scanf("%d", &e);
    if (gcd(e, phi) != 1) {
        printf("Erro: e não é coprimo com phi.\n");
        return 1;
    }

    // Cálculo da chave privada d
    int d = mod_inverse(e, phi);
    printf("Chave pública: (e=%d, n=%d)\n", e, n);
    printf("Chave privada: (d=%d, n=%d)\n", d, n);

    // Entrada da mensagem
    char message[256];
    printf("Digite a mensagem (somente letras maiúsculas e espaços): ");
    getchar(); // Limpar buffer do scanf anterior
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0'; // Remover newline

    // Codificação da mensagem
    int encoded[256];
    int length;
    encode_message(message, encoded, &length);

    // Criptografia da mensagem
    long long encrypted[256];
    printf("Mensagem criptografada: ");
    for (int i = 0; i < length; i++) {
        encrypted[i] = mod_exp(encoded[i], e, n);
        printf("%lld ", encrypted[i]);
    }
    printf("\n");

    // Decodificação da mensagem (descriptografia)
    printf("Mensagem descriptografada: ");
    for (int i = 0; i < length; i++) {
        long long plain = mod_exp(encrypted[i], d, n);
        if (plain >= 11 && plain <= 36) {
            printf("%c", (char)(plain - 11 + 'A'));
        } else if (plain == 37) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}

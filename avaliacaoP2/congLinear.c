#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Função para calcular o máximo divisor comum (MDC) usando o algoritmo de Euclides
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Função para calcular o inverso modular de "a" módulo "m" (usado para d)
int mod_inverse(int a, int m)
{
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    while (a > 1)
    {
        q = a / m;
        t = m;
        m = a % m;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0)
        x1 += m0;

    return x1;
}

// Função para calcular a potência modular recursivamente
long long mod_exp(long long base, long long exp, long long mod)
{
    if (exp == 0)
        return 1;
    if (exp % 2 == 0)
    {
        long long half = mod_exp(base, exp / 2, mod);
        return (half * half) % mod;
    }
    else
    {
        return (base * mod_exp(base, exp - 1, mod)) % mod;
    }
}

// Função para criptografar uma mensagem recursivamente
void encrypt_message(const char *message, int e, int n, int block_size, int index, long long *encrypted)
{
    if (message[index] == '\0')
        return;

    // Converter o caractere em número baseado no pré-código (A=11, B=12,... Z=36, espaço=10)
    int code;
    if (message[index] == ' ')
        code = 10;
    else
        code = message[index] - 'A' + 11;

    // Criptografar o bloco
    encrypted[index] = mod_exp(code, e, n);

    // Chamada recursiva para o próximo bloco
    encrypt_message(message, e, n, block_size, index + 1, encrypted);
}

// Função principal
int main()
{
    int p, q, e, block_size;
    long long n, phi, d;

    // Entrada dos valores
    printf("Digite os números primos p e q: ");
    scanf("%d %d", &p, &q);

    printf("Digite o número E (chave pública): ");
    scanf("%d", &e);

    printf("Digite o tamanho do bloco: ");
    scanf("%d", &block_size);

    // Calcular n e phi(n)
    n = (long long)p * q;
    phi = (p - 1) * (q - 1);

    // Validar E
    if (gcd(e, phi) != 1)
    {
        printf("E deve ser coprimo a phi(n).\n");
        return 1;
    }

    // Calcular d (inverso modular de e mod phi)
    d = mod_inverse(e, phi);

    printf("Chave privada d: %lld\n", d);

    // Entrada da mensagem a ser criptografada
    char message[256];
    printf("Digite a mensagem (letras maiúsculas e espaços): ");
    scanf(" %[^\n]", message);

    // Criptografar a mensagem
    long long encrypted[256] = {0};
    encrypt_message(message, e, n, block_size, 0, encrypted);

    // Exibir a mensagem criptografada
    printf("Mensagem criptografada: ");
    for (int i = 0; message[i] != '\0'; i++) {
        printf("%lld ", encrypted[i]);
    }
    printf("\n");

    return 0;
}


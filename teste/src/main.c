#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bankdll.h"


int main ()
{

    char* cliente[20];
    char* senha[8];
    float saldoInicial;

    int qtdContas = contarContas();
    printf("QTDE contas: %i", qtdContas);

    puts("Nome do cliente: ");
    gets(*cliente);

    puts("Senha: ");
    gets(*senha);

    puts("Saldo inicial: ");
    scanf("%f", &saldoInicial);

    bool sacar = sacar();
    Conta nova = criarConta(cliente, senha, saldoInicial);

    return nova.numConta;
}

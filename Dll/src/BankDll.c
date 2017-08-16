/*
 ============================================================================
 Name        : BankDll.c
 Author      : Emerson Santos
 Version     :
 Copyright   : God is unique way!
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>
#include "dll.h"


int main(int argc,char **argv)
{

    char cliente[20];
    char senha[8];
    float saldoInicial;

    int qtdContas = contarContas();
    printf("QTDE contas: %i\n\n\n\n", qtdContas);

    puts("Nome do cliente: ");
    fflush(stdin);
    gets(cliente);

    puts("Senha: ");
    fflush(stdin);
    gets(senha);

    puts("Saldo inicial: ");
    fflush(stdin);
    scanf("%f", &saldoInicial);

    printf("Cliente: %s - Senha: %s - Saldo: %.2f!\n\n", cliente, senha, saldoInicial);

    Conta nova = criarConta(cliente, senha, saldoInicial);

    printf("Cliente: %s\nSenha: %s\nSaldo: %.2f\nAtiva? %s\n\n", nova.cliente, nova.senha, nova.saldo, nova.ativa ? "Sim!" : "Não!");

    puts("Informe o valor que deseja sacar: ");
    fflush(stdin);
    scanf("%f", &saldoInicial);

    printf("Conta: %s\nSaldo: %.2f!\n\n", 3, consultarSaldo(3));

    if(sacar(nova.numConta, saldoInicial))
    	printf("Saque da conta %d, no valor de R$ %.2f foi realizado com sucesso!", nova.numConta, saldoInicial);
    else
    	printf("Falha ao tentar fazer saque na conta %d!", nova.numConta);


    return nova.numConta;
}

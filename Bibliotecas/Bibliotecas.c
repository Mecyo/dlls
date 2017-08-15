#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bankdll.h"


static char NOME_ARQ_CONTAS[] = "contas.db";
static char NOME_ARQ_NUM_CONTAS[] = "num_contas.db";


FILE *pont_arq_contas;
int qtdContas;

int contarContas() {

    char numConta[6];

    qtdContas = 0;

    abrirArquivo(NOME_ARQ_NUM_CONTAS, "r" );

    if(pont_arq_contas != NULL) {

        while(fgets(numConta, 6, pont_arq_contas) != NULL) {
            qtdContas++;
        }
    }
    else {
        printf("N�o foi poss�vel abrir o arquivo!");
    }

    fecharArquivo();

    return atoi(numConta);

}

BANKDLL Conta criarConta(char* cliente, char* senha, float saldoInicial)
{
    Conta nova;

    nova.numConta = contarContas() + 1;
    nova.ativa = true;
    nova.saldo = saldoInicial;
    strcpy(nova.cliente, cliente);
    strcpy(nova.senha, senha);

    abrirArquivo(NOME_ARQ_NUM_CONTAS, "a");

    if(pont_arq_contas != NULL) {
    	char str[6];
		sprintf(str, "%ld", nova.numConta);
        fputs(str, pont_arq_contas);
    }
    else {
        printf("N�o foi poss�vel abrir o arquivo!");
    }

fecharArquivo();

abrirArquivo(NOME_ARQ_CONTAS, "a");

if(pont_arq_contas != NULL) {
		char str[6];
		sprintf(str, "%ld", nova.numConta);
        fprintf(pont_arq_contas, str, ';', nova.ativa, ';', nova.saldo, ';', nova.cliente, ';', nova.senha, ";\n");
    }
    else {
        printf("N�o foi poss�vel abrir o arquivo!");
    }

fecharArquivo();

    return nova;
}

Conta buscarConta(Conta numConta) {
Conta busca;

busca.numConta = 12345;
busca.ativa =  true;
strcpy(busca.cliente, "Emerson");
busca.saldo = 234.56;
strcpy(busca.senha, "1234567");

return busca;
}

void abrirArquivo(const char* nomeArquivo, char* parametro) {

pont_arq_contas = fopen(nomeArquivo, parametro);

if (pont_arq_contas == NULL)
pont_arq_contas = fopen(nomeArquivo, "w");

}

void fecharArquivo() {
    fclose(pont_arq_contas);
}

BANKDLL bool depositar(int numConta, float valor)
{
    char linha[100];
    char ch;
    char num[6];
    int i = 0;
    bool depositado;

    abrirArquivo(NOME_ARQ_CONTAS, "r+b");

    if(pont_arq_contas != NULL) {

        //nova.numConta, ";", nova.ativa, ";", nova.saldo, ";", nova.cliente, ";", nova.senha, ";\n"

            while ((fgets(linha, 100, pont_arq_contas)) != NULL)
            {
            	for (int var = 0; ch != ';'; ++var) {
            		ch = linha[var];
            		num[i] = ch;

            	}
				if((atoi(num)) == numConta){
					//substituir linha atual alterando o saldo

					}

            }

        depositado = true;
    }
    else {
        printf("N�o foi poss�vel abrir o arquivo!");
        depositado = false;
    }

    fecharArquivo();

    return depositado;
}

BANKDLL bool sacar(int numConta,float valor)
{
    //char linha[100];
    char ch;
    char num[5];
    int i = 0;
    bool saque;

    abrirArquivo(NOME_ARQ_CONTAS, "r");

    if(pont_arq_contas != NULL) {

        while (ch != ';')
        {
            ch=fgetc(pont_arq_contas);
            num[i++] = ch;

        }

        saque = true;
    }
    else {
        printf("N�o foi poss�vel abrir o arquivo!");
        saque = false;
    }

    fecharArquivo();

    i = atoi(num);

    return saque;
}

BANKDLL float consultarSaldo(int numConta)
{
 float res = 2.9;
 return res;
}

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

    Conta nova = criarConta(*cliente, *senha, saldoInicial);

    return nova.numConta;
}


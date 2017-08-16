/*
 ============================================================================
 Name        : Dll.c
 Author      : Emerson
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dll.h"


bool verificaNumero(int numConta, char* linha);

static char NOME_ARQ_CONTAS[] = "contas.db";
static char NOME_ARQ_NUM_CONTAS[] = "num_contas.db";
FILE *pont_arq_contas;

BANKDLL int contarContas() {

    char linha[6];
    char numConta[6];

    pont_arq_contas = fopen(NOME_ARQ_NUM_CONTAS, "r");

    if(pont_arq_contas != NULL) {
        while(fgets(linha, 6, pont_arq_contas) != NULL) {
        	strcpy(numConta, linha);
        }
    }
    else {
        printf("Não foi possível abrir o arquivo!");
    }

    fclose(pont_arq_contas);

    return atoi(numConta);
}

BANKDLL Conta criarConta(char* cliente, char* senha, float saldoInicial) {
	Conta nova;

	nova.numConta = contarContas() + 1;
	nova.ativa = TRUE;
	nova.saldo = saldoInicial;
	strcpy(nova.cliente, cliente);
	strcpy(nova.senha, senha);

	pont_arq_contas = fopen(NOME_ARQ_NUM_CONTAS, "a");

	if (pont_arq_contas != NULL) {
		char str[6];
		sprintf(str, "\n%ld", nova.numConta);
		fputs(str, pont_arq_contas);
	} else {
		printf("Não foi possível abrir o arquivo!");
	}

	fclose(pont_arq_contas);

	pont_arq_contas = fopen(NOME_ARQ_CONTAS, "a");

	if (pont_arq_contas != NULL) {
		char str[6];
		sprintf(str, "%ld", nova.numConta);
		printf("\n%s;%d;%.2f;%s;%s", str, nova.ativa, nova.saldo, nova.cliente, nova.senha);
		fprintf(pont_arq_contas, str, ';', nova.ativa, ';', nova.saldo, ';',
				nova.cliente, ';', nova.senha, "\n");
	} else {
		printf("Não foi possível abrir o arquivo!");
	}

	fclose(pont_arq_contas);

	return nova;
}

BANKDLL Conta buscarConta(int numConta) {
	Conta busca;

	busca.numConta = 12345;
	busca.ativa = TRUE;
	strcpy(busca.cliente, "Emerson");
	busca.saldo = 234.56;
	strcpy(busca.senha, "1234567");

	return busca;
}

BANKDLL bool depositar(int numConta, float valor) {
	char linha[100];
	char ch;
	char num[6];
	int i = 0;
	bool depositado;

	pont_arq_contas = fopen(NOME_ARQ_CONTAS, "r+b");

	if (pont_arq_contas != NULL) {

		while ((fgets(linha, 100, pont_arq_contas)) != NULL) {
			for (; ch != ';'; ++i) {
				ch = linha[i];
				num[i] = i;

			}
			if ((atoi(num)) == numConta) {
				//substituir linha atual alterando o saldo

			}

		}

		depositado = TRUE;
	} else {
		printf("Não foi possível abrir o arquivo!");
		depositado = FALSE;
	}

	fclose(pont_arq_contas);

	return depositado;
}

BANKDLL bool sacar(int numConta, float valor) {

	char linha[100];
	char ch;
	char num[6];
	int i = 0, numLinha;
	bool saque;

	pont_arq_contas = fopen(NOME_ARQ_CONTAS, "r");

	if (pont_arq_contas != NULL) {
		FILE *pont_arq_backup = fopen("contas.db.bak", "w");
		while(!feof(pont_arq_contas)) {

			fgets(linha, 100, pont_arq_contas);

			if(verificaNumero(numConta, linha)) {
				printf("Arquivo Aberto %s!", num);
			} else {
				fputs(linha, pont_arq_backup);
			}
		}

		saque = TRUE;
	} else {
		printf("Não foi possível abrir o arquivo!");
		saque = FALSE;
	}

	fclose(pont_arq_contas);

	i = atoi(num);

	return saque;
}

bool verificaNumero(int numConta, char* linha) {

	int i = 0;
	char ch;
	char num[6];

	while(ch != ';') {

		ch = linha[i];
		num[i++] = ch;
	}

	if(atoi(num) == numConta)
		return TRUE;

	return FALSE;

}

BANKDLL float consultarSaldo(int numConta) {

	char linha[100];
	char ch;
	char saldo[6];
	int i = 0, numLinha = 0, verificador = 0;

	pont_arq_contas = fopen(NOME_ARQ_CONTAS, "r");

	if (pont_arq_contas != NULL) {
			while(!feof(pont_arq_contas)) {

				fgets(linha, 100, pont_arq_contas);

				if(verificaNumero(numConta, linha)) {
					while(verificador < 2) {
						ch = linha[i++];
						if(ch == ';')
							verificador++;
					}
					ch = linha[i++];
					int j = 0;
					while(ch != ';') {
						saldo[j] = ch;
						ch = linha[i++];

					}
					return atof(saldo);
					printf("Arquivo Aberto %.2f!", saldo);
				}
			}

		} else {
			printf("Não foi possível abrir o arquivo!");
		}

	return 0.0;
}

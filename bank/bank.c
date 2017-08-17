/*
 * dll.c
 *
 *  Created on: 17 de ago de 2017
 *      Author: Emerson Santos
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bank.h"


bool verificaNumero(int numConta, char* linha);
char* alterarLinha(char* linha, int posicao, char* replacement);

static char NOME_ARQ_CONTAS[] = "contas.db";
static char NOME_ARQ_NUM_CONTAS[] = "num_contas.db";
FILE *pont_arq_contas;

int contarContas() {

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

Conta criarConta(char* cliente, char* senha, float saldoInicial) {
	Conta nova;

	nova.numConta = contarContas() + 1;
	nova.ativa = TRUE;
	nova.saldo = saldoInicial;
	strcpy(nova.cliente, cliente);
	strcpy(nova.senha, senha);

	pont_arq_contas = fopen(NOME_ARQ_NUM_CONTAS, "a");

	if (pont_arq_contas != NULL) {
		char str[6];
		sprintf(str, "\n%d", nova.numConta);
		fputs(str, pont_arq_contas);
	} else {
		printf("Não foi possível abrir o arquivo!");
	}

	fclose(pont_arq_contas);

	pont_arq_contas = fopen(NOME_ARQ_CONTAS, "a");

	if (pont_arq_contas != NULL) {
		printf("\n%d;%d;%f;%s;%s", nova.numConta, nova.ativa, nova.saldo, nova.cliente, nova.senha);
		fprintf(pont_arq_contas, "\n%d;%d;%f;%s;%s", nova.numConta, nova.ativa, nova.saldo, nova.cliente, nova.senha);
	} else {
		printf("Não foi possível abrir o arquivo!");
	}

	fclose(pont_arq_contas);

	return nova;
}

Conta buscarConta(int numConta) {
	Conta busca;

	busca.numConta = 12345;
	busca.ativa = TRUE;
	strcpy(busca.cliente, "Emerson");
	busca.saldo = 234.56;
	strcpy(busca.senha, "1234567");

	return busca;
}

bool depositar(int numConta, float valor) {
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

bool sacar(int numConta, float valor) {

	float saldoAtual = consultarSaldo(numConta);
	if(saldoAtual < valor) {
		printf("A conta informada não possui saldo suficiente!");
		return FALSE;
	} else {
		char linha[100];

		pont_arq_contas = fopen(NOME_ARQ_CONTAS, "r");

		FILE *pont_arq_backup;

		if (pont_arq_contas != NULL) {
			pont_arq_backup = fopen("contas.db.bak", "w");
			while(!feof(pont_arq_contas)) {

				fgets(linha, 100, pont_arq_contas);

				if(verificaNumero(numConta, linha)) {
					char replacement[20];
					sprintf(replacement, "%f", saldoAtual - valor);
					fputs(alterarLinha(linha, 2, replacement), pont_arq_backup);

				} else {
					fputs(linha, pont_arq_backup);
				}
			}

		} else {
			printf("Não foi possível abrir o arquivo!");
			return FALSE;
		}

		fclose(pont_arq_contas);
		fclose(pont_arq_backup);
		unlink(NOME_ARQ_CONTAS);
		rename("contas.db.bak", NOME_ARQ_CONTAS);

		return TRUE;
	}

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

float consultarSaldo(int numConta) {

	char linha[100];
	char ch;
	char saldo[20];
	int i = 0, numLinha = 0, verificador = 0;

	pont_arq_contas = fopen(NOME_ARQ_CONTAS, "r");

	if (pont_arq_contas != NULL) {
			while(!feof(pont_arq_contas)) {

				fgets(linha, 100, pont_arq_contas);
				numLinha++;

				if(verificaNumero(numConta, linha)) {
					while(verificador < 2) {
						ch = linha[i++];
						if(ch == ';')
							verificador++;
					}

					ch = linha[i++];

					int j = 0;
					while(ch != ';') {
						if(ch == '.')
							ch = ',';
						saldo[j++] = ch;
						ch = linha[i++];
					}
					printf("%s ==> %f", saldo, atof(saldo));
					return atof(saldo);
				}
			}

		} else {
			printf("Não foi possível abrir o arquivo!");
		}

	return 0.0;
}

char* alterarLinha(char* linha, int posicao, char* replacement) {

	char linhaNova[200];
		char ch;
		int i = 0, j = 0, k = 0, verificador = 0;

		while(verificador < posicao) {
			ch = linha[i++];
			linhaNova[k++] = ch;
			if(ch == ';')
				verificador++;
		}
		printf("Linha: %s\n\n", linha);
		printf("1 - Linha Nova: %s\n", linhaNova);
		printf("i: %d - j: %d - k: %d\n", i, j, k);

		for(j = 0; j < strlen(replacement); j++)
			linhaNova[i++] = replacement[j];

		printf("2 - Linha Nova: %s\n", linhaNova);
		printf("i: %d - j: %d - k: %d\n", i, j, k);
		printf("ch: %c\n", ch);

		do{
			ch = linha[k++];
		}while(ch != ';');

		printf("ch: %c\n", ch);
		printf("3 - Linha Nova: %s\n", linhaNova);
		printf("i: %d - j: %d - k: %d\n", i, j, k);

		linhaNova[i++] = ch;
		while(k < strlen(linha))
			linhaNova[i++] = linha[k++];

		linhaNova[i] = '\0';

		return linhaNova;
}

bool validarlogin(int numConta, char* senha) {

	char linha[100];
	char password[9];
	bool validaNumero = FALSE, validaSenha = FALSE;

	pont_arq_contas = fopen(NOME_ARQ_NUM_CONTAS, "r");

	if(pont_arq_contas != NULL) {
		while(fgets(linha, 6, pont_arq_contas) != NULL) {
			if(numConta == atoi(linha))
				validaNumero = TRUE;
		}
	} else {
		printf("Não foi possível abrir o arquivo!");
		system("PAUSE");
	}

	fclose(pont_arq_contas);

	if(validaNumero) {
		pont_arq_contas = fopen(NOME_ARQ_CONTAS, "r");

			if(pont_arq_contas != NULL) {
				while(fgets(linha, 100, pont_arq_contas) != NULL) {
					if(verificaNumero(numConta, linha)) {
						int verificador = 0, i = 0;
						char ch;
						while(verificador < 4) {
							ch = linha[i++];
							if(ch == ';')
								verificador++;
						}

						int j = 0;
						while(i < strlen(linha))
							if(linha[i] != '\n')
								password[j++] = linha[i++];
							else
								i++;

					}
				}
				if(strcmp (password, senha) == 0)
					validaSenha = TRUE;
				else {
					printf("\nSenha inválida para a conta informada!\n\n");
					system("PAUSE");
				}

			} else {
				printf("Não foi possível abrir o arquivo!");
				system("PAUSE");
			}
	} else {
		printf("\nO número da conta informado é inválido!\n\n");
		system("PAUSE");
	}

	return validaNumero && validaSenha;

}

/*
 ============================================================================
 Name        : BankSystemDll.c
 Author      : Emerson Santos
 Version     :
 Copyright   : Fabricando dlls em C
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <locale.h>
#include <bank.h>
#include <menu.h>

#define acima 80
#define abaixo 72
#define enter 13

/**
 * Function Prototypes
 */
bool login();

int main(int argc, char **argv) {
	//setlocale(LC_ALL,"Portuguese");

	int ch, x, y, X, Y;
	x = 5;
	y = 7;
	X = 5;
	Y = 5;

	while(1) {

		while (!login()) {

			menu(X, Y); //variaveis em maiusculas
			gotoxy(x, y); //variaveis em minusculas
			printf(">");

			while (1) {
				ch = getch();
				if (ch == 224) {

					switch (getch()) {

					case acima:
						if (y < 11) {
							gotoxy(x, y);
							printf(" ");
							gotoxy(x, ++y);
							printf(">");
						} else {
							gotoxy(x, y);
							printf(" ");
							y = 8;
							gotoxy(x, --y);
							printf(">");
						}
						break;

					case abaixo:
						if (y > 7) {
							gotoxy(x, y);
							printf(" ");
							gotoxy(x, --y);
							printf(">");
						} else {
							gotoxy(x, y);
							printf(" ");
							y = 10;
							gotoxy(x, ++y);
							printf(">");
						}
						break;

						default: break;

					}

				} else if (ch == enter) {
					if (escolha(y) == 1) {
						goto fim;
					}
					break;
				}

			}
			system("cls");
		}
	}

	fim: system("PAUSE");

	return EXIT_SUCCESS;

	/*char cliente[20];
	 char senha[8];
	 float saldoInicial;
	 bool validaLogin = login();

	 while(!validaLogin)
	 validaLogin = login();

	 menuPrincipal();

	 int qtdContas = contarContas();
	 printf("QTDE contas: %i\n\n\n\n", qtdContas);

	 puts("Nome do cliente: ");
	 gets(cliente);
	 fflush(stdin);

	 puts("Senha: ");
	 gets(senha);
	 fflush(stdin);

	 puts("Saldo inicial: ");
	 scanf("%f", &saldoInicial);
	 fflush(stdin);

	 Conta nova = criarConta(cliente, senha, saldoInicial);

	 int numConta;
	 float valor;
	 printf("\nInforme o n�mero da conta de onde deseja sacar: ");
	 scanf("%d", &numConta);
	 fflush(stdin);

	 puts("\nInforme o valor que deseja sacar: ");
	 scanf("%f", &valor);
	 fflush(stdin);


	 if(sacar(numConta, valor))
	 printf("\nSaque da conta %d, no valor de R$ %.2f foi realizado com sucesso!", numConta, valor);

	 return 0;*/
}

bool login() {

	int numConta;
	char senha[9];
	system("cls");
	printf("\nPara realizar o login informe o n�mero da conta e a senha:\n");
	printf("N�mero da conta=> ");
	scanf("%d", &numConta);
	fflush(stdin);
	printf("Senha=> ");
	gets(senha);
	fflush(stdin);

	return validarlogin(numConta, senha);
}

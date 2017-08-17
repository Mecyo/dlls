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
#include <locale.h>
#include <dll.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ESC 27
#define KEY_ENTER 13

/**
* Function Prototypes
*/
void menuPrincipal();
int func();
bool login();

int main(int argc,char **argv)
{
	setlocale(LC_ALL,"Portuguese");

    char cliente[20];
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
	printf("\nInforme o número da conta de onde deseja sacar: ");
	scanf("%d", &numConta);
	fflush(stdin);

	puts("\nInforme o valor que deseja sacar: ");
	scanf("%f", &valor);
	fflush(stdin);


	if(sacar(numConta, valor))
		printf("\nSaque da conta %d, no valor de R$ %.2f foi realizado com sucesso!", numConta, valor);

    return 0;
}

void menuPrincipal() {

    int key = 0;
    while(1) {
        system("cls");
        printf("\n   ÚÄÄÄÄÄÄÄ Menu Principal ÄÄÄÄÄÄÄ¿\n");
        printf("   ³                              ³\n");
        printf("   ³ %s Retornar em main           ³\n", (key == KEY_UP)? "=>": " ");
        printf("   ³ %s Chamar outra funcao        ³\n", (key == KEY_DOWN)? "=>": " ");
        printf("   ³                              ³\n");
        printf("   ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");
        key = getch(); // get key pressed

        if (key == KEY_ESC)
            return;
    }
}

bool login() {

    int numConta;
    char senha[9];
        system("cls");
        printf("\nPara realizar o login informe o número da conta e a senha:\n");
        printf("Número da conta=> ");
        scanf("%d", &numConta);
        fflush(stdin);
        printf("Senha=> ");
        gets(senha);
        fflush(stdin);

        return validarlogin(numConta, senha);
}

int func() {
    int opcao;
    printf("\n tecle 1 para imposto");
    printf("\n tecle 2 para novo salario");
    printf("\n tecle 3 para classificação");
    printf("\n tecle 4 para finalizar o programa");
    scanf("%d",&opcao);
    return(opcao);
}

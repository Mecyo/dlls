/*
 ============================================================================
 Name        : BankDll.c
 Author      : Emerson Santos
 Version     :
 Copyright   : God is unique way!
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include<stdio.h>
#include<windows.h>//essa biblioteca e necessaria pra o uso da funcao tempo
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<conio.h>

#include"menu.h"
#include"dll.h"

#define acima 80
#define abaixo 72
#define enter 13

/**
* Function Prototypes
*/
void menuPrincipal();
int func();
bool login();


int main(int argc,char **argv)
{
	setlocale(LC_ALL,"Portuguese");


	int ch,x,y,X,Y;
	x=5; y=7; X=5; Y=5;

while(1){

menu(X,Y);//variaveis em maiusculas
gotoxy(x,y); //variaveis em minusculas
printf(">\n");

while(1){
		ch=getch();
		if(ch==224){

				     switch ( getch() ){

						case acima :
					        	if(y<12){
													gotoxy(x,y);
													printf(" ");
													gotoxy(x,++y);  printf(">");
										} break;


						case abaixo :
								if(y>7){
													gotoxy(x,y);
													printf(" ");
													gotoxy(x,--y); printf(">");
										}  break ;


					defalte : break;

					}

		}else if(ch==enter){
								if(escolha(y)==1){ goto fim;} break;
							}

		}
	system ("cls");
	}

	fim:
		system("PAUSE");

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
	printf("\nInforme o número da conta de onde deseja sacar: ");
	scanf("%d", &numConta);
	fflush(stdin);

	puts("\nInforme o valor que deseja sacar: ");
	scanf("%f", &valor);
	fflush(stdin);


	if(sacar(numConta, valor))
		printf("\nSaque da conta %d, no valor de R$ %.2f foi realizado com sucesso!", numConta, valor);*/

}

void menuPrincipal() {

    int key = 0;
    while(1) {
        system("cls");
        printf("\n   ÚÄÄÄÄÄÄÄ Menu Principal ÄÄÄÄÄÄÄ¿\n");
        printf("   ³                              ³\n");
        //printf("   ³ %s Retornar em main           ³\n", (key == KEY_UP)? "=>": " ");
        //printf("   ³ %s Chamar outra funcao        ³\n", (key == KEY_DOWN)? "=>": " ");
        printf("   ³                              ³\n");
        printf("   ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\n");
        //key = getch(); // get key pressed

        //if (key == KEY_ESC)
            //return;
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

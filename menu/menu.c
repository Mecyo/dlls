/*
 * menu.c
 *
 *  Created on: 17 de ago de 2017
 *      Author: Emerson Santos
 */

#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <dos.h>
#include "menu.h"

// -------------------------------------------------------------------------

void gotoxy(int coluna, int linha) {
     COORD point;
     point.X = coluna;
     point.Y = linha;
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

// -------------------------------------------------------------------------

void textcolor (DOS_COLORS iColor) {
     HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
     //BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
     bufferInfo.wAttributes &= 0x00F0;
     SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= iColor);
}

// -------------------------------------------------------------------------

void textbackground (DOS_COLORS iColor) {
     HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
     //BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
     bufferInfo.wAttributes &= 0x000F;
     SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= (iColor << 4));
}

// -------------------------------------------------------------------------

void wait ( float seconds ) {
     clock_t endwait;
     endwait = clock () + seconds * CLOCKS_PER_SEC ;
     while (clock() < endwait) {}
}

// -------------------------------------------------------------------------

void printxy(int coluna, int linha, char texto[]) {

     gotoxy(coluna, linha);
     printf(texto);

}

void tempo6(){
	int i;
	char charging[120]=""; //limpa o espaco reservado na memoria
	for(i=0; i<=100; i++)//laco de repeticao de zero a 100.
    {
	if(i%2){strcat(charging,"�"); }//variavel olavo recebe caractere �.
    system("CLS");//limpa a tela

    printf("               ����������������������������������������������������Ŀ");
    printf("\n  Load Programa�");

	textcolor(YELLOW);
	printf("  %s ",charging);//exibe na tela a contagem de "i" e acumula os caracteres "�" na tela

	textcolor(WHITE);
	printf("\n               ������������������������������������������������������");
    gotoxy(64,1);
	printf("    � %d%% ",i);
	Sleep(25); //tempo de 25 milisegundo
    textcolor(WHITE);
    }
    system("cls");	//limpa a tela
	printf("Carregado %d%%",i-1);//exibe na tela a ultima contagem de "�"na tela tipo: 100%
    Sleep(1000);//espera de um segundo
}




void menu(int X,int Y){
	    textbackground(GREEN);

	printxy(X, Y++," �������� Menu Principal �����Ŀ");
    printxy(X, Y++," �                             �");
	textcolor(YELLOW); printxy(X, Y++," �NOVA CONTA                   �");
	textcolor(WHITE);  printxy(X, Y++," �DEPOSITAR                    �");
	textcolor(YELLOW); printxy(X, Y++," �SACAR                        �");
	textcolor(WHITE);  printxy(X, Y++," �CONSULTAR SALDO              �");
	textcolor(YELLOW); printxy(X, Y++," �SAIR                         �");
    printxy(X, Y++," �������������������������������");

}


int escolha(int y){
	system("cls");
	system("COLOR 17");

	int X=5,Y=5;
	switch(y){

		case 7: textbackground(GREEN); printxy(X, Y++," \t\t \t\t\t");
				textbackground(GREEN); printxy(X, Y++," \t\t NOVA CONTA \t\t");
		        textbackground(GREEN); printxy(X, Y++," \t\t \t\t\t\n"); break;

		case 8: textbackground(GREEN); printxy(X, Y++," \t\t \t\t\t");
				textbackground(GREEN); printxy(X, Y++," \t\tDEPOSITAR \t\t");
		        textbackground(GREEN); printxy(X, Y++," \t\t \t\t\t\n"); break;

		case 9: textbackground(GREEN); printxy(X, Y++," \t\t \t\t\t");
				textbackground(GREEN); printxy(X, Y++," \t\tSACAR \t\t");
		        textbackground(GREEN); printxy(X, Y++," \t\t \t\t\t\n"); break;

		case 10: textbackground(GREEN); printxy(X, Y++," \t\t \t\t\t");
				 textbackground(GREEN); printxy(X, Y++," \t\tCONSULTAR SALDO\t\t");
		         textbackground(GREEN); printxy(X, Y++," \t\t \t\t\t\n");break;

		case 11: textbackground(BLUE); textcolor(YELLOW);tempo6();system ("cls");
				 textbackground(GREEN); printxy(X, Y++," \t\t \t\t\t");
				 textbackground(GREEN); printxy(X, Y++," \t\t ALUNO OLAVO!!\t\t");
		         textbackground(GREEN); printxy(X, Y++," \t\t \t\t\t\n"); break;

		case 12:
				 textbackground(RED); printxy(X, Y++," \t\t                \t\t");
				 textbackground(RED); textcolor(WHITE);printxy(X, Y++," \t\tFIM DO PROGRAMA.\t\t");
		         textbackground(RED); printxy(X, Y++," \t\t                \t\t\n");
				 textbackground(BLUE); return 1;  break;
	}
    textbackground(BLUE);
	system("pause");
	return 0;
}



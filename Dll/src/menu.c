/*
 * menu.c
 *
 *  Created on: 17 de ago de 2017
 *      Author: emersant
 */

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
     BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
     bufferInfo.wAttributes &= 0x00F0;
     SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= iColor);
}

// -------------------------------------------------------------------------

void textbackground (DOS_COLORS iColor) {
     HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
     BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
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
	char olavo[120]=""; //limpa o espaco reservado na memoria
	for(i=0; i<=100; i++)//laco de repeticao de zero a 100.
    {
	if(i%2){strcat(olavo,"�"); }//variavel olavo recebe caractere �.
    system("CLS");//limpa a tela

    printf("               ����������������������������������������������������Ŀ");
    printf("\n  Load Programa�");

	textcolor(YELLOW);
	printf("  %s ",olavo);//exibe na tela a contagem de "i" e acumula os caracteres "�" na tela

	textcolor(WHITE);
	printf("\n               ������������������������������������������������������");
    gotoxy(64,1);
	printf("    � %d%% ",i);
	Sleep(25); //tempo de 25 milisegundo
    textcolor(WHITE);
    }
    system("cls");	//limpa a tela
	printf("Carregado %d%%",i-1);//exibe na tela a ultima conatagem de "�"na tela tipo: 100%
    Sleep(1000);//espera de um segundo
}




void menu(int X,int Y){
	    textbackground(GREEN);

	printxy(X, Y++," �������� Menu Principal �����Ŀ");
    printxy(X, Y++," �                             �");
	textcolor(YELLOW); printxy(X, Y++," �IGOR                         �");
	textcolor(WHITE);  printxy(X, Y++," �Sr MOCO                      �");
	textcolor(YELLOW); printxy(X, Y++," �KELVIN                       �");
	textcolor(WHITE);  printxy(X, Y++," �BRUNO                        �");
	textcolor(YELLOW); printxy(X, Y++," �OLAVO                        �");
	textcolor(WHITE); printxy(X, Y++," �EXIT                         �");
    printxy(X, Y++," �������������������������������");

}


int escolha(int y){
	system("cls");
	system("COLOR 17");

	int X=5,Y=5;
	switch(y){

		case 7: textbackground(GREEN); printxy(X, Y++," \t\t \t\t\t");
				textbackground(GREEN); printxy(X, Y++," \t\t ALUNO IGOR \t\t");
		        textbackground(GREEN); printxy(X, Y++," \t\t \t\t\t\n"); break;

		case 8: textbackground(GREEN); printxy(X, Y++," \t\t \t\t\t");
				textbackground(GREEN); printxy(X, Y++," \t\tALUNO Sr MOCO \t\t");
		        textbackground(GREEN); printxy(X, Y++," \t\t \t\t\t\n"); break;

		case 9: textbackground(GREEN); printxy(X, Y++," \t\t \t\t\t");
				textbackground(GREEN); printxy(X, Y++," \t\tALUNO KELVIN \t\t");
		        textbackground(GREEN); printxy(X, Y++," \t\t \t\t\t\n"); break;

		case 10: textbackground(GREEN); printxy(X, Y++," \t\t \t\t\t");
				 textbackground(GREEN); printxy(X, Y++," \t\tALUNO BRUNO\t\t");
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
}



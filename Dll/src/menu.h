/*
 * menu.h
 *
 *  Created on: 17 de ago de 2017
 *      Author: emersant
 */

#ifndef MENU_H_
#define MENU_H_



#endif /* MENU_H_ */

typedef enum {
     BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN,
     LIGHT_GRAY, DARK_GRAY, LIGHT_BLUE, LIGHT_GREEN, LIGHT_CYAN,
     LIGHT_RED, LIGHT_MAGENTA, YELLOW, WHITE
} DOS_COLORS;


void gotoxy(int coluna, int linha);

void textcolor (DOS_COLORS iColor);

void textbackground (DOS_COLORS iColor);

void wait ( float seconds );

void printxy(int coluna, int linha, char texto[]);

void tempo6();

void menu(int X,int Y);

int escolha(int y);

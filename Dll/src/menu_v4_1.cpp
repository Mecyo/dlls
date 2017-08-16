#include<stdio.h>
#include<conio.h>
#include<conio2.c>//voce vai precisar dessa biblioteca
#include<windows.h>//essa biblioteca e necessaria pra o uso da funcao tempo
#include<stdlib.h>




#define acima 80
#define abaixo 72
#define enter 13

void tempo6(){
	int i;
	char olavo[120]=""; //limpa o espaco reservado na memoria
	for(i=0; i<=100; i++)//laco de repeticao de zero a 100.
    {
	if(i%2){strcat(olavo,"Û"); }//variavel olavo recebe caractere Û.
    system("CLS");//limpa a tela
    
    printf("               ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿");
    printf("\n  Load Programa³");
    
	textcolor(YELLOW);
	printf("  %s ",olavo);//exibe na tela a contagem de "i" e acumula os caracteres "Û" na tela
    
	textcolor(WHITE);
	printf("\n               ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
    gotoxy(64,1);
	printf("    ³ %d%% ",i);
	Sleep(25); //tempo de 25 milisegundo
    textcolor(WHITE);
    }
    system("cls");	//limpa a tela
	printf("Carregado %d%%",i-1);//exibe na tela a ultima conatagem de "ï"na tela tipo: 100%
    Sleep(1000);//espera de um segundo
} 




void menu(int X,int Y){
	    textbackground(GREEN);
	
	printxy(X, Y++," ÚÄÄÄÄÄÄÄ Menu Principal ÄÄÄÄÄÄ¿");
    printxy(X, Y++," ³                             ³");
	textcolor(YELLOW); printxy(X, Y++," ³IGOR                         ³");
	textcolor(WHITE);  printxy(X, Y++," ³Sr MOCO                      ³");
	textcolor(YELLOW); printxy(X, Y++," ³KELVIN                       ³");
	textcolor(WHITE);  printxy(X, Y++," ³BRUNO                        ³");
	textcolor(YELLOW); printxy(X, Y++," ³OLAVO                        ³");
	textcolor(WHITE); printxy(X, Y++," ³EXIT                         ³");
    printxy(X, Y++," ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
	
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

 main(){
 	
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
		system("pause"); 
	return 0;
}

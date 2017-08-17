/*
 * dll.h
 *
 *  Created on: 17 de ago de 2017
 *      Author: Emerson Santos
 */

#ifndef BANKDLL
#define BANKDLL

typedef enum {TRUE=1, FALSE=0} bool;

struct
{
	int numConta;
	bool ativa;
	float saldo;
	char cliente[20];
	char senha[8];
} typedef  Conta;

Conta criarConta(char* cliente, char* senha, float saldoInicial);
bool depositar(int numConta,float valor);
bool sacar(int numConta,float valor);
float consultarSaldo(int numConta);
int contarContas();
Conta buscarConta(int numConta);
bool validarlogin(int numConta, char* senha);

#endif // BANKDLL


#ifdef BUILD_DLL
 #define BANKDLL __declspec(dllexport)
#else
 #define BANKDLL __declspec(dllimport)
#endif

typedef enum {FALSES, TRUES} bool;

struct
{
	long int numConta;
	bool ativa;
	float saldo;
	char cliente[20];
	char senha[8];
} typedef  Conta;


BANKDLL Conta criarConta(char* cliente, char* senha, float saldoInicial);
BANKDLL bool depositar(int numConta,float valor);
BANKDLL bool sacar(int numConta,float valor);
BANKDLL float consultarSaldo(int numConta);
BANKDLL int contarContas();
BANKDLL Conta buscarConta(int numConta);
BANKDLL bool validarlogin(int numConta, char* senha);

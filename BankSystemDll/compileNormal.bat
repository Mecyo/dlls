cls

@echo off
echo Criando as libs.
gcc -c lib/bank.c -o build/bank.o
gcc -c lib/menu.c -o build/menu.o

ar rcs build/libbank.a build/bank.o
ar rcs build/libmenu.a build/menu.o

echo libs criadas com sucesso! 
pause

echo Removendo arquivos desnecessários: 
copy lib/bank.h build/bank.h
copy lib/menu.h build/menu.h
cd build
del /q *.c
del /q *.o
cd ../

echo Construindo o Programa Executável:
gcc -static src/BankSystemDll.c -L./build -I./build -lbank -lmenu -o build/BankSystemDll.exe
pause
start build/BankSystemDll.exe


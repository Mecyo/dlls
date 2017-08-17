cls

@echo off
echo Criando as libs.
gcc -c lib/dll.c -o build/dll.o
gcc -c lib/menu.c -o build/menu.o

ar rcs build/libdll.a build/dll.o
ar rcs build/libmenu.a build/menu.o

echo libs criadas com sucesso! 
pause

echo Removendo arquivos desnecess�rios: 
copy lib/dll.h build/dll.h
cd build
del /q *.c
del /q *.o
cd ../

echo Construindo o Programa Execut�vel:
gcc -static src/BankSystem.c -L./build -I./build -ldll -lmenu -o build/BankSystem.exe
pause
start build/BankSystem.exe

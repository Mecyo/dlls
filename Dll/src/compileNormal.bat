cls
C:\MinGW\bin\gcc -c -DBUILD_DLL C:\Users\Aluno\git\dlls\Dll\src\bank.c -o C:\Users\Aluno\git\dlls\Dll\src\out.o
C:\MinGW\bin\gcc -shared -o C:\Users\Aluno\git\dlls\Dll\src\bank.dll C:\Users\Aluno\git\dlls\Dll\src\out.o -Wl,--out-implib,C:\Users\Aluno\git\dlls\Dll\src\bank.a
del C:\Users\Aluno\git\dlls\Dll\src\out.o
C:\MinGW\bin\gcc C:\Users\Aluno\git\dlls\Dll\src\BankDll.c -o C:\Users\Aluno\git\dlls\Dll\src\BankDll.exe C:\Users\Aluno\git\dlls\Dll\src\bank.a
pause
start C:\Users\Aluno\git\dlls\Dll\src\BankDll.exe
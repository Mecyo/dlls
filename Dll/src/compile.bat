cls
C:\MinGW\bin\gcc -c -DBUILD_DLL bank.c -o out.o
C:\MinGW\bin\gcc -shared -o bank.dll out.o -Wl,--out-implib,bank.a
del out.o
C:\MinGW\bin\gcc BankDll.c -o BankDll.exe bank.a
pause
start BankDll.exe
cls
gcc -c -DBUILD_DLL bank.c -o out.o
gcc -shared -o bank.dll out.o -Wl,--out-implib,bank.a
del out.o
gcc BankDll.c -o BankDll.exe bank.a
pause
start BankDll.exe
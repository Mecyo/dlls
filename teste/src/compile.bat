cls
gcc -c -DBUILD_DLL bankdll.c -o out.o
gcc -shared -o minha.dll out.o -Wl,--out-implib,minha.a
del out.o
gcc main.c -o minha.exe minha.a
 @echo off
 chcp 65001
 color f8
 title BankSystemDll By Mecyo
 cls
 time /t
 date/t
 
 echo **************************************
 echo *        Sistema bancário            *
 echo *        Utilizando Dll's            *
 echo ++++++++++++++++++++++++++++++++++++++
 echo   
 echo Digite 1 para abrir o sistema bancário
 echo Digite 2 para abrir a calculadora
 echo Digite 0 para SAIR
 
 :menu
 set /p opcao=Digite a opção desejada: 
 if %opcao% equ 1 goto 1
 if %opcao% equ 2 goto 2
 if %opcao% equ 0 goto 0
 :1
 start BankSystemDll/Debug/BankSystemDll.exe
 :2
 start calc.exe
 :0
 exit
 cls
 goto menu
 
 
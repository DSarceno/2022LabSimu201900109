//	vie 22 abr 2022 17:12:18 CST
//	pruebas.c
//	Diego Sarceno (dsarceno68@gmail.com)

//	Resumen

//	Codificado del texto: UTF8
//	Compiladores probados: GNU gcc (Ubuntu 20.04 Linux) 9.3.0
//	Instruciones de Compilacion: no requiere nada mas
//	gcc -Wall -pedantic -std=c11 -c -o pruebas.o pruebas.c
//	gcc -o pruebas.x pruebas.o

//	Librerias
#include <stdio.h>

int main(){
  int n = 10;
  printf("%ld", isdigit(n));
  return 0;
}

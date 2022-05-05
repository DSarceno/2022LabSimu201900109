//	jue 21 abr 2022 18:28:36 CST
//	problema5.c
//	Diego Sarceno (dsarceno68@gmail.com)

//	Resumen

//	Codificado del texto: UTF8
//	Compiladores probados: GNU gcc (Ubuntu 20.04 Linux) 9.3.0
//	Instruciones de Compilacion: no requiere nada mas
//	gcc -Wall -pedantic -std=c11 -c -o problema5.o problema5.c
//	gcc -o problema5.x problema5.o

//	Librerias
#include <stdio.h>

// 0. prototipado de funciones y definicion de variables
unsigned long long int factorial(int n);

// 1. funcion main
int main(){
  // 2. definicion de variables
  int n;

  // 3. ingreso y validacion del dato ingresado por el usuario
  puts("Ingrese un número entero positivo.");
  scanf("%d", &n);

  //4. utilizacion de la funcion recursiva
  printf("El factorial del número ingresado es: %lld\n", factorial(n));

  return 0;
} // END MAIN


/*
                          FUNCIONES
*/


unsigned long long int factorial(int n){
  if (n == 1 || n == 0){
    return 1;
  } else {
    return n*factorial(n-1);
  } // END IF
} // FUNCION FACTORIAL


















// END PROGRAM

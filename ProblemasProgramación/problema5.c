//	mar 22 mar 2022 22:02:54 CST
//	problema5.c
//	Diego Sarceno (dsarceno68@gmail.com)

//	Este programa recibe dos números para generar un intervalo cerrado y
//  encontrar todos los números primos en el intervalo.

//	Codificado del texto: UTF8
//	Compiladores probados: GNU gcc (Ubuntu 20.04 Linux) 9.3.0
//	Instruciones de Compilacion: no requiere nada mas
//	gcc -Wall -pedantic -std=c11 -c -o problema5.o problema5.c
//	gcc -o problema5.x problema5.o

//	Librerias
#include <stdio.h>

// 1. Definimos la función "es_primo"
int es_primo(int n);

// 2. funcion main
int main(){
  // 3. definir variables
  int n1, n2;

  // 4. Leer los valores del intervalo
  puts("Ingrese dos valores para el intervalo (el segundo más grande que el primero).");
  scanf("%d", &n1);
  scanf("%d", &n2);

  // 5. Iniciar el ciclo for
  for (int j = n1; j <= n2; j++){
    // 6. validación primos
    if (es_primo(j) == 1){
      printf("El número %d es primo. \n", j);
    } // END IF
  } // END FOR5

  return 0;
} // END MAIN

int es_primo(int n){
  // E.1. declaración de variables locales
  int i = 2;
  int primo = 1;

  // E.2. ciclo while
  while ((i < n) && (primo == 1)){
    /* E.3. validamos si el contador 'i' es divisor de N
    en caso de que sea así, cambiamos la variable primo a 0 (FALSE)
    y salimos del ciclo. */
    if (n%i == 0){
      primo = 0;
    } else {
      i++;
    } // END IF
  } // END WHILE
  return primo;
} // END ES_PRIMO

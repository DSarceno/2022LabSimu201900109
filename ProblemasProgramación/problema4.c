//	vie 18 mar 2022 21:42:36 CST
//	problema4.c
//	Diego Sarceno (dsarceno68@gmail.com)

//	Este programa lee un número mayor que 1 y determina si es primo.

//	Codificado del texto: UTF8
//	Compiladores probados: GNU gcc (Ubuntu 20.04 Linux) 9.3.0
//	Instruciones de Compilacion: no requiere nada mas
//	gcc -Wall -pedantic -std=c11 -c -o problema4.o problema4.c
//	gcc -o problema4.x problema4.o

//	Librerias
#include <stdio.h>

// 1. funcion main
int main(){
  // 2. definir variables
  int i = 2;
  int primo = 1;
  int n;

  // 3. leemos el valor de N
  printf("Ingrese un número entero positivo. \n");
  scanf("%d", &n);

  // 4. Ingresamos al while
  while ((i < n) && (primo == 1)){
    /* 5. validamos si el contador 'i' es divisor de N
    en caso de que sea así, cambiamos la variable primo a 0 (FALSE)
    y salimos del ciclo. */
    if (n%i == 0){
      primo = 0;
    } else {
      i++;
    } // END IF
  } // END WHILE

  // 6. validamos la variable primo (1 = TRUE, 0 = FALSE)
  if (primo == 0){
    puts("El número no es primo.");
  } else {
    puts("El número es primo.");
  } // END IF
  return 0;
} // END MAIN FUNCTION

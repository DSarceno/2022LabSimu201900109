//	vie 18 mar 2022 21:27:28 CST
//	problema3.c
//	Diego Sarceno (dsarceno68@gmail.com)

//	Este programa calcula la raíz cuadrada entera de un número N,
//  tal que r^2 <= N.

//	Codificado del texto: UTF8
//	Compiladores probados: GNU gcc (Ubuntu 20.04 Linux) 9.3.0
//	Instruciones de Compilacion: no requiere nada mas
//	gcc -Wall -pedantic -std=c11 -c -o problema3.o problema3.c
//	gcc -o problema3.x problema3.o

//	Librerias
#include <stdio.h>

// 1. Funcion main
int main(){
  // 2. declaramos variables
  int i = 1;
  float N;

  // 3. Leemos el número N, por parte del usuario
  puts("Ingrese un número positivo. \n");
  scanf("%f", &N);

  // 4. validación, si el número es no entero o negativo, se cierra.
  if (N >= 0){
    // 5. Realizano el ciclo while
    while (i*i <= N){
      // 6. Incrementamos el valor de 'i'
      i++;
    } // END WHILE

    // 7. imprimiendo el valor válido de i (i - 1)
    printf("Raíz cuadrada entera de %.2f es: %d \n", N, i - 1);
  } else {
    puts("El número ingresado no es un entero positivo");
  } // END IF
  return 0;
} // END MAIN FUNCTION

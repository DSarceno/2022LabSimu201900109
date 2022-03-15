//	mar 15 mar 2022 14:49:48 CST
//	problema1For.c
//	Diego Sarceno (dsarceno68@gmail.com)

//	Este programa encuentra la media aritmetica entre los numeros positivos
//  ingresados por el usuario.

//	Codificado del texto: UTF8
//	Compiladores probados: GNU gcc (Ubuntu 20.04 Linux) 9.3.0
//	Instruciones de Compilacion: no requiere nada mas
//	gcc -Wall -pedantic -std=c11 -c -o problema1For.o problema1For.c
//	gcc -o problema1For.x problema1For.o

//	Librerias
#include <stdio.h>

// 1. Creación de la función main.
int main(){
  // 2. Declaración de variables
  float x = 0, media = 0;
  int i = 0, n = 0;

  printf("Calculadora para media aritmetica de 3 números. \n");
  // 3. Declaración del ciclo For
  for (i = 0; i < 3; i++){ // BEGIN FOR
    // 4. Lectura del valor
    printf("Ingrese un número real: \n");
    scanf("%f", &x);

    // 5. Validación del input
    if (x >= 0){
      n++;
      media += x;
    } // END IF
  } // END FOR

  // 6. Validación de la variable 'n'
  if (n == 0){
    // 7. En caso de que todos los números sean negativos
    printf("No positivos \n");
  } else {
    // 8. Muestra de la media aritmetica
    printf("La media es: %f \n", media/n);
  } // END IF
  return 0;
} // END MAIN FUNCTION

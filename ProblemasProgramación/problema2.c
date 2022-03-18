//	vie 18 mar 2022 12:16:54 CST
//	problema2.c
//	Diego Sarceno (dsarceno68@gmail.com)

//	El programa recibe un número indefinidio de alturas, y termina de obtener
//  datos al ingresar una negativa. Retorna la media, el máximo y mínimo.

//	Codificado del texto: UTF8
//	Compiladores probados: GNU gcc (Ubuntu 20.04 Linux) 9.3.0
//	Instruciones de Compilacion: no requiere nada mas
//	gcc -Wall -pedantic -std=c11 -c -o problema2.o problema2.c
//	gcc -o problema2.x problema2.o

//	Librerias
#include <stdio.h>

// 1. funcion main
int main(){
  // 2. declaración de variables
  int n = 0;
  float media = 0, x = 0;

  // 3. lectura del valor de 'x'
  printf("Ingrese un número real: \n");
  scanf("%f", &x);

  // 4. definimos el máximo y el mínimo como x para poder comparar luego
  float max = x, min = x;

  // 5. inicio del while
  while (x >= 0){
    // 6. Incremento de media y del contador 'n'
    n += 1;
    media += x;

    // 7. comparamos con los valores min y máx anteriores
    // 7.1. comparación con el máximo
    if (x > max){
      max = x;
    } // END IF
    // 7.2. comparación con el mínimo
    if (x < min){
      min = x;
    } // END IF

    // 8. ingreso de un nuevo número real para la repetición del bucle
    printf("Ingrese un número real: \n");
    scanf("%f", &x);
  } // END WHILE

  /* 9. validación del contador, en caso de ser cero, no se ingresaron números
  positivos o cero */
  if (n != 0){
    printf("La media aritmética es: %.2f \n", media/n);
    printf("El máximo es: %.2f \n", max);
    printf("El mínimo es: %.2f \n", min);
  } else {
    printf("No positivos. \n");
  } // END IF
  return 0;
} // END MAIN

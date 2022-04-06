//	mar 05 abr 2022 20:08:50 CST
//	problema6.c
//	Diego Sarceno (dsarceno68@gmail.com)

//	Este programa recibe un número de vértices y una cantidad igual de
//  coordenadas asociadas a cada uno de los vértices. Devuelve el área del
//  poligono.

//	Codificado del texto: UTF8
//	Compiladores probados: GNU gcc (Ubuntu 20.04 Linux) 9.3.0
//	Instruciones de Compilacion: no requiere nada mas
//	gcc -Wall -pedantic -std=c11 -c -o problema6.o problema6.c
//	gcc -o problema6.x problema6.o -lm

//	Librerias
#include <stdio.h>
#include <math.h>

// 1. Declaración de la función main
int main(){
  // 2. Declaración de variables 1
  int n;
  float sum = 0;
  float A;

  // 3. Lectura del número de vértices
  puts("Ingrese el número de vértices de su poligono.");
  scanf("%d",&n);

  // 4. Declaración de los arrays para el almacenaje de los datos.
  float x[n];
  float y[n];

  // 5. Bucle para el ingreso de las coordenadas (x,y)
  puts("Ingrese las coordenadas de los vértices en el siguiente formato (x,y)");
  for (int i = 0; i < n; i++){
    scanf("%f,%f", &x[i], &y[i]);
  } // END FOR

  // 6. Encontrando el área
  for (int j = 0; j < n - 1; j++){
    sum += (x[j]*y[j + 1]) - (x[j + 1]*y[j]);
  } // END FOR
  A = fabs(0.5*((x[n - 1]*y[0]) - (x[0]*y[n - 1])) + 0.5*sum);

  // 7. Se muestra el valor del área
  printf("El valor del área del poligono ingresado es: %f \n", A);
} // END MAIN

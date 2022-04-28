//	mié 27 abr 2022 22:31:19 CST
//	problema2.c
//	Diego Sarceno (dsarceno68@gmail.com)

//	Encuentra la raíz de la función propuesta en el examen por medio del método
//  Newton-Raphson

//	Codificado del texto: UTF8
//	Compiladores probados: GNU gcc (Ubuntu 20.04 Linux) 9.3.0
//	Instruciones de Compilacion: no requiere nada mas
//	gcc -Wall -pedantic -std=c11 -c -o problema2.o problema2.c
//	gcc -o problema2.x problema2.o -lm

//	Librerias
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 0. Prototipado de funciones y definicion de Variables
float f(float x);
float df(float x);
void newtonRaphson(float x_inicial, float tolerancia, int max, int *actiter, float *sol);

int main(){
  // 1. variables
  float x_inicial, tolerancia, raiz;
  int iteraciones, aiteracion;

  // 2. ingreso de datos
  puts("Ingrese un valor aproximado de la raíz");
  scanf("%f", &x_inicial);
  puts("Ingrese la tolerancia aceptada para el resultado.");
  scanf("%f", &tolerancia);
  puts("Ingrese un número de iteraciones máximo");
  scanf("%d", &iteraciones);

  // aplicamos la funcion
  newtonRaphson(x_inicial, tolerancia, iteraciones, &aiteracion, &raiz);

  // comprobamos si hay o no solución con la tolerancia y cantidad de iteracioens dadas.
  if (aiteracion == iteraciones){
    printf("No hay solución luego de %d iteraciones.", aiteracion);
  } else {
    printf("Solución: (%f,0)", raiz);
  }

  return 0;
} // END main



/*
                            FUNCIONES
*/

float f(float x){
  return (2 - exp(x) + cos(exp(x) - 2));
  //return (tan(x));
} // END f
/*
float df(float x){
  //return (-exp(x) - sin(exp(x) - 2)*exp(x));
  return(-1/(sin(x)*sin(x)));
} // END df
*/

void newtonRaphson(float x_inicial, float tolerancia, int max, int *actiter, float *sol){
  // variables de paso y diferencia
  float h = 0.0001; // valor para la aproximacion de la derivada
  float df;
  float x = x_inicial;
  int i = 0;

  // calculo aproximado de la derivada
  df = (f(x + h) - f(x - h))/(2*h);

  // bucle para aproximar el valor de la raiz
  for (i = 0; i < max; i++){
    x += f(x)/df;
    printf("x[%d] = %f \t f(x[%d]) = %f \n", i, x, i, f(x));
    if (fabs(f(x)) < tolerancia){ break; }
  } // END FOR

  // Resultados
  *sol = x;
  *actiter = i;

} // END newtonRaphson
















//

//	mié 27 abr 2022 22:31:14 CST
//	problema1.c
//	Diego Sarceno (dsarceno68@gmail.com)

//	Fit de la recta que mejor se aproxime a un conjunto de datos.

//	Codificado del texto: UTF8
//	Compiladores probados: GNU gcc (Ubuntu 20.04 Linux) 9.3.0
//	Instruciones de Compilacion: no requiere nada mas
//	gcc -Wall -pedantic -std=c11 -c -o problema1.o problema1.c
//	gcc -o problema1.x problema1.o -lm

//	Librerias
#include <stdio.h>
#include <math.h>


// 0. Prototipado de funciones y declaracion de variables
#define n 10
float suma_prod(float x[], float y[]);
float suma(float x[]);

// 1. funcion main
int main(){
  // 5. vectores de datos y variables importantes
  float x[n] = {1,2,3,4,5,6,7,8,9,10};
  float y[n] = {20.20,20.90,20.60,21.30,21.75,22.05,23.62,22.95,23.80,24.00};
  float m, b; // pendiente e intercepto
  float r; // coeficiente de correlacion

  // 6. Calculo de la pendiente y el intercepto con las funciones ya dadas.
  m = ((n*suma_prod(x,y)) - (suma(x)*suma(y)))/((n*suma_prod(x,x)) - (suma(x)*suma(x)));
  b = (suma(y) - (m*suma(x)))/(n);

  printf("%f x + %f \n",m,b);


  // 7. Cálculo del coeficiente de correlación r, e impresión de r**2
  r = ((n*suma_prod(x,y)) - (suma(x)*suma(y)))/sqrt(((n*suma_prod(x,x))-(suma(x)*suma(x)))*((n*suma_prod(y,y))-(suma(y)*suma(y))));
  printf("r = %f \n", r);
  printf("r^2 = %f \n", r*r);

  // 8. Encontrando el tiempo que se toma en llegar al tope de precio, 30

  /*
    Para ello despejamos la funcion f(x) = mx + b para x que es el tiempo y
    reemplazamos los 30 de precio tope
  */

  puts("El tiempo que le toma al combustible alcanzar su precio límite es de: ");
  printf("%f semanas.\n", (30 - b)/m);
  return 0;
}




/*
                          FUNCIONES
*/

float suma(float x[]){
  float result = 0;

  for (int i = 0; i < n; i++){
    result += x[i];
  } // END FOR

  return result;
} // END suma


float suma_prod(float x[], float y[]){
  float result = 0;

  for (int i = 0; i < n; i++){
    result += x[i]*y[i];
  } // END FOR

  return result;
} // END suma_prod



















//

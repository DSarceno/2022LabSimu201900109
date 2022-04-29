//	jue 28 abr 2022 23:17:08 CST
//	problema2.c
//	Diego Sarceno (dsarceno68@gmail.com)

//	Resumen

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
float biseccion(float inflim, float suplim, int iteraciones, float tolerancia);

// 1. funcion main
int main(){
  // 2. variables utiles
  float x_inicial, x_final, tolerancia;
  int iteraciones;

  // 3. ingreso de variables por parte del usuario
  puts("Límite inferior de la raíz.");
  scanf("%f",&x_inicial);
  puts("Límite superior de la raíz.");
  scanf("%f",&x_final);
  puts("Número máximo de iteraciones.");
  scanf("%d",&iteraciones);
  puts("Tolerancia aceptada.");
  scanf("%f",&tolerancia);


  // 4. Llamada a las funciones
  puts("inflim \t\t f(inflim) \t\t suplim \t\t f(suplim) \t\t p \t\t f(p)");
  biseccion(x_inicial, x_final, iteraciones, tolerancia);
  return 0;
} // END Main

float f(float x){
  return (2 - exp(x) + cos(exp(x) - 2));
} // END f

float biseccion(float inflim, float suplim, int iteraciones, float tolerancia){
  // punto medio del intervalo
  float p;

  p = (inflim + suplim)/2; // definicion del punto medio
  printf("%f \t %f \t %f \t %f \t %f \t %f\n", inflim, f(inflim), suplim, f(suplim), p, f(p));
  for (int i = 0; i < iteraciones; i++){
    p = (inflim + suplim)/2; // se vuelve a definir para que este dentreo del ciclo
    if (f(inflim)*f(p) > 0){ // deteccion de la variación de signo
      inflim = p;
    } else {
      suplim = p;
    } // END IF
    printf("%f \t %f \t %f \t %f \t %f \t %f\n", inflim, f(inflim), suplim, f(suplim), p, f(p));
    if (fabs(inflim - suplim) < tolerancia){ break; } // se llego a la tolerancia
  } // END FOR
  return 0;
} // END biseccion






















//

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
void biseccion(float inflim, float suplim, int iteraciones, int *fail, float *raiz, float tolerancia);

// 1. funcion main
int main(){
  // 2. variables utiles
  float x_inicial, x_final, tolerancia, raiz;
  int iteraciones, fail;

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
  // puts("inflim \t\t f(inflim) \t\t suplim \t\t f(suplim) \t\t p \t\t f(p)");

  biseccion(x_inicial, x_final, iteraciones, &fail, &raiz, tolerancia);

  // 5. Vemos si el método dio resultado en el número de iteraciones Dado
  if (fail == iteraciones){
    printf("No se pudo encontrar la raíz en %d iteraciones.\n", fail);
  } else {
    printf("El valor de la raíz es: %f\n", raiz);
  } // END IF


  //6. se crea un archivo con el punto dado y se genera el plot
  FILE* f;
  if ((f= fopen("point.dat","wt"))==NULL){
        puts("Error de escritura");
        return 1;
  } // END IF
  fprintf(f,"%f\t%f\n",raiz,0.0);
  fclose(f);

  // 6.1. plot
  system("gnuplot raiz.gp");

  return 0;
} // END Main

float f(float x){
  return (2 - exp(x) + cos(exp(x) - 2));
} // END f

void biseccion(float inflim, float suplim, int iteraciones, int *fail, float *raiz, float tolerancia){
  // punto medio del intervalo
  float p;
  int i;

  p = (inflim + suplim)/2; // definicion del punto medio
  // printf("%f \t %f \t %f \t %f \t %f \t %f\n", inflim, f(inflim), suplim, f(suplim), p, f(p));
  for (i = 0; i < iteraciones; i++){
    p = (inflim + suplim)/2; // se vuelve a definir para que este dentreo del ciclo
    if (f(inflim)*f(p) > 0){ // deteccion de la variación de signo
      inflim = p;
    } else {
      suplim = p;
    } // END IF
    // printf("%f \t %f \t %f \t %f \t %f \t %f\n", inflim, f(inflim), suplim, f(suplim), p, f(p));
    if (fabs(inflim - suplim) < tolerancia){ break; } // se llego a la tolerancia
  } // END FOR
  *raiz = p;
  *fail = i;
} // END biseccion






















//

//	jue 21 abr 2022 18:10:47 CST
//	problema6.c
//	Diego Sarceno (dsarceno68@gmail.com)

//	Calculo de diversas sumatorias con limite superior ingresado por el usuario.

//	Codificado del texto: UTF8
//	Compiladores probados: GNU gcc (Ubuntu 20.04 Linux) 9.3.0
//	Instruciones de Compilacion: no requiere nada mas
//	gcc -Wall -pedantic -std=c11 -c -o problema6.o problema6.c
//	gcc -o problema6.x problema6.o -lm

//	Librerias
#include <stdio.h>
#include <math.h>

// 0. Prototipado de funciones
float a(int n);
float b(int n);
float c(int n);
float d(int n);


// 1. funcion main
int main(){
  // 2. ingreso del limite superior
  int n;
  puts("Ingrese un número entero positivo.");
  scanf("%d", &n);

  printf("Inciso a) %.2f \n", a(n));
  printf("Inciso b) %.2f \n", b(n));
  printf("Inciso c) %.2f \n", c(n));
  printf("Inciso d) %.2f \n", d(n));
}


/*
                            FUNCIONES
*/

float a(int n){
  float sum1 = 0;
  for (int i = 1; i <= n; i++){
    sum1 += pow(i,2)*(i - 3);
  }
  return sum1;
} //END a

float b(int n){
  float sum2 = 0;
  for (int i = 2; i <= n; i++){
    sum2 += 3/(i - 1);
  }
  return sum2;
} // END b

float c(int n){
  float sum3 = 0;
  for (int i = 1; i <= n; i++){
    sum3 += (1/sqrt(5))*pow(((1 + sqrt(5))/2),i) - (1/sqrt(5))*pow(((1 - sqrt(5))/2),i);
  }
  return sum3;
} // END c

float d(int n){
  float sum4 = 0;
  for (int i = 2; i <= n; i++){
    sum4 += 0.1*(3*pow(2,i - 2) + 4);
  }
  return sum4;
} // END d







//END PROGRAM lab4Problema6

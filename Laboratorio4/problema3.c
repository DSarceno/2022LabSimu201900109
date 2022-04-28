//	jue 21 abr 2022 17:01:06 CST
//	problema3.c
//	Diego Sarceno (dsarceno68@gmail.com)

//	Este problema recibe dos vectores en R3 al usuario y calcula
//  algunas operaciones con dichos vectores.

//	Codificado del texto: UTF8
//	Compiladores probados: GNU gcc (Ubuntu 20.04 Linux) 9.3.0
//	Instruciones de Compilacion: no requiere nada mas
//	gcc -Wall -pedantic -std=c11 -c -o problema3.o problema3.c
//	gcc -o problema3.x problema3.o -lm

//	Librerias
#include <stdio.h>
#include <math.h>

// 0. Prototipado de funciones y declaracion de variables
//double sqrt(double x);
void printArrays(float array[], int length);
void suma_vectorial(float array1[], float array2[], float result[]);
float magnitud(float array[]);
float producto_interno(float array1[], float array2[]);
void producto_vectorial(float array1[], float array2[], float result[]);

// 1. Main function
int main(){
  // 2. declaracion de variables generales
  float vec1[3], vec2[3];
  float resvec[3];

  // 3. Ingreso de los vectores por parte del usuario
  puts("Ingrese dos vectores en R3 en la forma x1,x2,x3.");
  scanf("%f,%f,%f",&vec1[0],&vec1[1],&vec1[2]);
  scanf("%f,%f,%f",&vec2[0],&vec2[1],&vec2[2]);

  // 4. Realizando las diferente operaciones
  // 4.1. Suma de vectores
  suma_vectorial(vec1,vec2,resvec);
  puts("Suma de vectores.");
  printArrays(resvec, 3);
  // 4.2. magnitud de cada vector
  printf("Magnitud de cada vector. V1 = %f, V2 = %f\n", magnitud(vec1), magnitud(vec2));
  // 4.3. vector product
  producto_vectorial(vec1,vec2,resvec);
  puts("Producto vectorial entre ambos vectores.");
  printArrays(resvec, 3);
  // 4.4. inner product
  printf("Producto interno entre ambos vectores: %f\n",producto_interno(vec1,vec2));

  return 0;
} // END MAIN


/*
                          FUNCIONES
*/

float producto_interno(float array1[], float array2[]){
  float result = 0;

  for (int i = 0; i < 3; i++){
    result += array1[i]*array2[i];
  } // END FOR

  return result;
} // END PRODUCTO_INTERNO


void producto_vectorial(float array1[], float array2[], float result[]){
  // componentes del vector resultante
  result[0] = (array1[1]*array2[2] - array1[2]*array2[1]);
  result[1] = -(array1[0]*array2[2] - array1[2]*array2[0]);
  result[2] = (array1[0]*array2[1] - array1[1]*array2[0]);
} // END PRODUCTO_VECTORIAL


void printArrays(float array[], int length){
  // impresion
  printf("(");
  for (int i = 0; i < length; i++){
    if (i != length - 1){
      printf("%f, ",array[i]);
    } else {
      printf("%f)\n", array[i]);
    } // END IF
  } // END FOR
} // END printArrays


void suma_vectorial(float array1[], float array2[], float result[]){
  for (int i = 0; i < 3; i++){
    result[i] = array1[i]+array2[i];
  } // END FOR
} // END SUMA_VECTORIAL


float magnitud(float array[]){
  //double sqrt(double x);
  float norm = 0;

  for (int i = 0; i < 3; i++){
    norm += pow(array[i],2);
  } // END FOR
  return sqrt(norm);
} // END SUMA_VECTORIAL








// adñlfja

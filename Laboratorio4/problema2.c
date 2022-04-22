//	jue 21 abr 2022 18:28:27 CST
//	problema2.c
//	Diego Sarceno (dsarceno68@gmail.com)

//	Ordenamiento de números dados por un usuario.

//	Codificado del texto: UTF8
//	Compiladores probados: GNU gcc (Ubuntu 20.04 Linux) 9.3.0
//	Instruciones de Compilacion: no requiere nada mas
//	gcc -Wall -pedantic -std=c11 -c -o problema2.o problema2.c
//	gcc -o problema2.x problema2.o

//	Librerias
#include <stdio.h>


// 0. Prototipado de funcion y definicion de variables
#define l 5
void mergeSort(int main_array[], int start, int final);
void merge(int array[], int start, int half, int final);
void printArrays(int array[], int length);

// 1. funcion main
int main(){
  // 3. declaracion de variables
  int vector[5];

  // 4. ingreso de datos
  puts("Ingrese 5 numeros enteros.");
  for (int i = 0; i < l; i++){ scanf("%d", &vector[i]); }

  // 5. Ordenamiento del array
  puts("Array ordenado.");
  mergeSort(vector, 0, l);
  printArrays(vector, l);

  return 0;
} // END MAIN


/*
                            FUNCITON
*/


void mergeSort(int main_array[], int start, int final){
  int half;
  half = (start + final)/2;
  if (start < final){
    mergeSort(main_array, start, half);
    mergeSort(main_array, half + 1, final);
    merge(main_array, start, half, final);
  } // END IF
} // END MERGESORT

void merge(int array[], int start, int half, int final){
  int aux[final + 1],i,j,k,t;

  k = 0; // movimiento por la lista auxiliar
  i = start; // movimiento por la sublista izquierda
  j = half + 1; // movimiento por la sublista derecha

  // ciclo para empezar a unir los arrays
  while(i <= half && j <= final){
    k++;
    if (array[i] < array[j]){
      aux[k] = array[i];
      i++;
    } else {
      aux[k] = array[j];
      j++;
    } // END IF
  } // END WHILE

  // para los elementos sobrantes de alguna de las sublistas
  for (t = i; t <= half; t++){
    k++;
    aux[k] = array[t];
  } // END FOR

  for (t = j; t <= final; t++){
    k++;
    aux[k] = array[t];
  } // END FOR

  // regresar todo al vector original
  for (t = 1; t <= k; t++){
    array[start + t - 1] = aux[t];
  } // END FOR
} // END MERGE

void printArrays(int array[], int length){
  // impresion
  printf("(");
  for (int i = 0; i < length; i++){
    if (i != length - 1){
      printf("%d, ",array[i]);
    } else {
      printf("%d)\n", array[i]);
    } // END IF
  } // END FOR
} // END printArrays











// END PROGRAM

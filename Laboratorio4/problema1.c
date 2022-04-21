//	mié 20 abr 2022 15:52:22 CST
//	problema1.c
//	Diego Sarceno (dsarceno68@gmail.com)

//	Este programa crea y muestra una lista de 10 elementos de números pares
//  y solicita al usuario en que orden desea que se ordene
//  (ascendente/descendente). Para el ordenamiento se utiliza el algoritmo
//  merge-sort.

//	Codificado del texto: UTF8
//	Compiladores probados: GNU gcc (Ubuntu 20.04 Linux) 9.3.0
//	Instruciones de Compilacion: no requiere nada mas
//	gcc -Wall -pedantic -std=c11 -c -o problema1.o problema1.c
//	gcc -o problema1.x problema1.o

//	Librerias
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 0. Prototipado de funciones
void mergeSort(int main_array[], int start, int final);
void merge(int array[], int start, int half, int final);
void reverse(int array[], int length);
void printArrays(int array[], int length);
void shuffle(int array[], int length);
#define l 10

// 1. Función main

int main(){
  // 1.1. Definimos la "seed" como el tiempo, para el generador de numeros
  srand(time(0));

  // 2. Se crea un arreglo de números pares del 2 al 20
  int numeros[l];
  // 2.1. se ingresan los datos en la lista
  for (int i = 0; i < l; i++){ numeros[i] = 2*i + 2; }

  // 3. Se aleatoriza el arreglo
  printArrays(numeros, l);
  shuffle(numeros, l);
  printArrays(numeros, l);

  // 4. Interaccion con el usuario y ordenamiento del arreglo
  char input;
  int control = 0;
  while(control == 0){
    puts("Ingrese como desea ver los números.");
    puts("'A' para verlos de forma ascendente.");
    puts("'D' para verlos de forma descendente.");
    scanf("%s",&input);
    if (input == 65){
      control = 1;
      puts("WUUU FORMA ASCENDENTE");
      //printArrays(numeros, l);
      mergeSort(numeros, 0, l);
      printArrays(numeros, l);
    } else if (input == 68){
      control = 1;
      puts("WUUU FORMA DESCENDENTE");
      //printArrays(numeros, l);
      mergeSort(numeros, 0, l);
      reverse(numeros, l);
      printArrays(numeros, l);
    } else {
      puts("Ingrese un valor válido.");
    } // END IF
  } // END WHILE


  return 0;
} // END MAIN


/*
                              FUNCIONES UTILIZADAS
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

void reverse(int array[], int length){
  int aux[length];

  // Navegando el array del final hacia el inicio, y aux en forma contraria
  for (int i = length - 1; i >= 0; i--){
    aux[length - i - 1] = array[i];
  } // END FOR

  // regresando todo al vector original
  for (int j = 0; j < length; j++){
    array[j] = aux[j];
  } // END FOR
} // END INVERSE

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

void shuffle(int array[], int length){
  int random_position, step;
  for (int k = 0; k < length; k++){
    // Generamos una posicion random
    random_position = rand() % length;
    // intercambiar el actual elemento con el de la poiscion aleatoria
    step = array[k];
    array[k] = array[random_position];
    array[random_position] = step;
  } // END FOR
} // END SHUFFLE























//adf
